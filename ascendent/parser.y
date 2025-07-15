%locations
%code requires {
    #include <unordered_map>
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <iostream>
#include <vector>
#include <optional>
#include <functional>
#include "types/attrs.hpp"
#include "symbol_table/symbol_table.hpp"

extern int yylex();
void yyerror(const char *s);

bool is_numeric(const std::string& type) {
    return type == "int" || type == "float";
}

std::string resolve_arithmetic_type(const std::string& t1, const std::string& t2) {
    if (t1 == "float" || t2 == "float") {
        return "float";
    }
    return "int";
}

bool check_compatible(const std::string& tvar, const std::string& texp) {
    return (tvar == texp) || 
                        (texp == "NULL" && tvar.rfind("REF(", 0) == 0) || 
                        (tvar == "float" && texp == "int");
}

void print_token_location(const int& first_line, const int& first_column) {
    std::cout << "Linha " << first_line << ", Coluna " << first_column << ": \n";
}

std::unordered_map<std::string, std::string> op_name_to_c_symbol = {
    {"OR", "||"},
    {"AND", "&&"},
    {"NOT", "!"},
    {"+", "+"},
    {"-", "-"},
    {"*", "*"},
    {"/", "/"},
    {"^", "pow"},
    {"<", "<"},
    {"<=", "<="},
    {">", ">"},
    {">=", ">="},
    {"=", "=="},
    {"<>", "!="}
};

int curr_var = 0;
int curr_label = 0;
std::string variable_declarations = "";
std::string header_declarations = "#include <stdio.h>\n#include <math.h>\n\n";

std::string resolve_type(const std::string& type) {
    if (type == "int" || type == "float") {
        return type;
    }else if (type == "bool"){
        return "int";
    }
    else if (type == "string") {
        return "char *";
    }
    else if (type.rfind("REF(", 0) == 0 && type.back() == ')') {
        // Extract the inner type recursively
        std::string inner_type = type.substr(4, type.length() - 5);
        return resolve_type(inner_type) + "*";
    }
    // else if (type.rfind("ARRAY(", 0) == 0 && type.back() == ')') {
    //     size_t comma_pos = type.find(',');
    //     size_t start_pos = 6; 
    //     std::string size_str = type.substr(start_pos, comma_pos - start_pos);
    //     std::string inner_type_str = type.substr(comma_pos + 1, type.length() - comma_pos - 2);
    //     return resolve_type(inner_type_str) + "[" + size_str + "];\n";
    // }
    else {
        // Check if type is a struct name
        auto lookup_result = SymbolTable::lookup(type);
        if (lookup_result && lookup_result->tag == Tag::STRUCT) {
            std::string label = lookup_result->label;
            return "struct " + label;
        }
    }
    return "ERR";
}

void resolve_array_type(std::string& type, std::string& inner_type, std::string& cols) {
    if (type.rfind("ARRAY(", 0) == 0 && type.back() == ')') {
        size_t comma_pos = type.find(',');
        size_t start_pos = 6; 
        std::string size_str = type.substr(start_pos, comma_pos - start_pos);
        std::string inner_type_str = type.substr(comma_pos + 1, type.length() - comma_pos - 2);
        cols += "[" + size_str + "]";
        resolve_array_type(inner_type_str, inner_type, cols);
    }
    else {
        inner_type = resolve_type(type);
    }
}

std::string new_var(std::string type = "int", std::string var_original_name = "") {
    std::string var_name =  var_original_name + "t" + std::to_string(curr_var++);
    if (type.rfind("ARRAY(", 0) == 0 && type.back() == ')') {
        std::string inner_type_str;
        std::string cols = "";
        resolve_array_type(type, inner_type_str, cols);
        variable_declarations += inner_type_str + " " + var_name + cols + ";\n";
    } else {
        variable_declarations += resolve_type(type) + " " + var_name + ";\n";
    }
    return var_name;
}

std::string new_label() {
    return "l" + std::to_string(curr_label++);
}

bool handle_binary_op(
    TypedAttr*& $$ /* Atributo de resultado */,
    const int& first_line, const int& first_column,
    TypedAttr* left /* Operando esquerdo */,
    TypedAttr* right /* Operando direito */,
    const std::string& op_name /* Nome do operador para erros */,
    // Função que define se os tipos são válidos para a operação
    std::function<bool(const std::string&, const std::string&)> are_types_valid,
    // Função que calcula o tipo do resultado
    std::function<std::string(const std::string&, const std::string&)> resolve_result_type)
{
    $$ = new TypedAttr();
    bool ok = (left->type != "ERR" && right->type != "ERR");
    $$->type = "ERR";
    $$->code = "";
    
    if (ok) {
        if (are_types_valid(left->type, right->type)) {
            $$->type = resolve_result_type(left->type, right->type);
        } else {
            print_token_location(first_line, first_column);
            std::cout << "Erro de tipo: Operandos inválidos para o operador '" << op_name << "'. "
                      << "Recebeu '" << left->type << "' e '" << right->type << "'." << std::endl;
            return false;
        }
    }

    std::string left_var = left->val.empty() ? new_var(left->type) : left->val;
    std::string right_var = right->val.empty() ? new_var(right->type) : right->val;
    $$->val = new_var($$->type);
    std::string op_symbol = op_name_to_c_symbol[op_name];
    $$->code = left->code + right->code;
    if(op_symbol == "pow") {
        $$->code += $$->val + " = " + op_symbol + "(" + left_var + ", " + right_var + ");\n";
    }
    else {
        $$->code += $$->val + " = " + left_var + " " + op_symbol + " " + right_var + ";\n";
    }

    delete left;
    delete right;
    return true;
}

%}

%union {
    std::string* sval;
    BoolAttr* b_attr;
    TypedAttr* t_attr;
    ListAttr* plist_attr;
    MapAttr* map_attr;
}

%token <sval> NAME FLOAT_LITERAL INT_LITERAL STRING_LITERAL
%token TRUE FALSE NULL_LIT
%token LPAREN RPAREN SEMICOLON LBRACKET RBRACKET LBRACE RBRACE COLON DOT COMMA CARET
%token PROGRAM BEGIN_TOK END VAR PROCEDURE STRUCT IN IF THEN ELSE FI WHILE DO OD RETURN NEW DEREF REF NOT ARRAY OF
%token ASSIGN AND OR
%token LT LE GT GE EQ NE
%token PLUS MINUS MULT DIV EXP_OP
%token FLOAT_T INT_T STRING_T BOOL_T

%start program

%left OR
%left AND
%right NOT
%nonassoc LT LE GT GE EQ NE
%left PLUS MINUS
%left MULT DIV
%right EXP_OP

%type <sval> M_enter_proc_scope
%type <b_attr> program opt_decls decl_tail decl var_decl proc_decl proc_header rec_decl block proc_body_opt
%type <b_attr> stmt_list stmt_tail stmt assign_stmt if_stmt else_opt while_stmt call_stmt return_stmt
%type <map_attr> opt_struct_members struct_member_tail struct_member_decl

%type <t_attr> var_init_opt opt_type return_exp_opt call_exp
%type <t_attr> expression or_exp and_exp not_exp rel_exp add_exp mult_exp exp_exp unary_exp primary_exp
%type <t_attr> var ref_var deref_var literal bool_literal type
%type <t_attr> paramfield_decl

%type <plist_attr> opt_param_list paramfield_tail
%type <plist_attr> call_args_opt call_args_tail


%%

program:
    PROGRAM NAME BEGIN_TOK opt_decls END
    {
        std::string program_name = *$2;
        delete $2;
        
        $$ = new BoolAttr();
        $$->ok = $4->ok;
        
        if ($$->ok) {
            $$->code = header_declarations + "int main() {\n" + variable_declarations + "\n" + $4->code + "}\n";
            printf("Análise sintática concluída com sucesso para o programa '%s'!\n", program_name.c_str());
            printf("Código gerado:\n%s\n", $$->code.c_str());
            FILE* out = fopen(("../out/" + program_name + ".c").c_str(), "w");
            if (out) {
                fputs($$->code.c_str(), out);
                fclose(out);
                printf("Código salvo em '../out/%s.c'\n", program_name.c_str());
            } else {
                printf("Erro ao abrir arquivo para escrita.\n");
            }
        } else {
            printf("Análise sintática encontrou erros no programa '%s'.\n", program_name.c_str());
        }
        delete $4;
    }
    ;

opt_decls:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
        $$->code = "";
    }
    | decl decl_tail
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok && $2->ok;
        if ($$->ok) {
            $$->code = $1->code + $2->code;
        } else {
            $$->code = "";
        }
        delete $1;
        delete $2;
    }
    ;

decl_tail:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
        $$->code = "";
    }
    | ';' decl decl_tail
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok && $3->ok;
        if ($$->ok) {
            $$->code = $2->code + $3->code;
        } else {
            $$->code = "";
        }
        delete $2;
        delete $3;
    }
    ;

decl:
      var_decl  { $$ = $1; }
    | proc_decl { $$ = $1; }
    | rec_decl  { $$ = $1; }
    ;

var_decl:
    VAR NAME ':' type var_init_opt
    {
        $$ = new BoolAttr();
        $$->ok = false; 
        if ($4->type != "ERR" && $5->type != "ERR") {
            std::string var_name = *$2;
            std::string declared_type = $4->type;
            std::string init_type = $5->type;

            bool has_initializer = (init_type != "void");

            if (has_initializer) {

                if(!check_compatible(declared_type, init_type)) {
                    print_token_location(@2.first_line, @2.first_column);
                    std::cout << "Erro de Tipo: Incompatibilidade na inicialização da variável '" << var_name
                            << "'. O tipo declarado é '" << declared_type
                            << "', mas a expressão de inicialização é do tipo '" << init_type << "'." << std::endl;
                } 
                else {
                    bool insert_ok = SymbolTable::insert(var_name, TokenInfo({}, declared_type, Tag::VAR));
                    if (!insert_ok) {
                        print_token_location(@2.first_line, @2.first_column);
                        std::cout << "Erro: Variável '" << var_name << "' já declarada." << std::endl;
                    } else {
                        std::string var_var = new_var($4->type, var_name );
                        SymbolTable::set_label(var_name, var_var);
                        $$->code = $5->code + var_var + " = " + $5->val + ";\n";
                        $$->ok = true;
                    }
                }
            } else { 
                bool insert_ok = SymbolTable::insert(var_name, TokenInfo({}, declared_type, Tag::VAR));
                if (!insert_ok) {
                    print_token_location(@2.first_line, @2.first_column);
                    std::cout << "Erro: Variável '" << var_name << "' já declarada." << std::endl;
                } else {
                    std::string var_var = new_var($4->type, var_name );
                    SymbolTable::set_label(var_name, var_var);
                    $$->ok = true;
                }
            }


        }
        
        delete $2;
        delete $4;
        delete $5;
    }
    | VAR NAME ASSIGN expression
    {
        $$ = new BoolAttr();
        $$->ok = false; 

        std::string var_name = *$2;

        if ($4->type != "ERR") {
            std::string init_type = $4->type;

            bool insert_ok = SymbolTable::insert(var_name, TokenInfo({}, init_type, Tag::VAR));
            if (!insert_ok) {
                print_token_location(@2.first_line, @2.first_column);
                std::cout << "Erro: Variável '" << var_name << "' já declarada." << std::endl;
            } else {
                $$->ok = true; // Sucesso
            }
        }

        if($$->ok) {
            std::string var_var = new_var($4->type, var_name );
            SymbolTable::set_label(var_name, var_var);
            $$->code = $4->code + var_var + " = " + $4->val + ";\n";
        }

        delete $2;
        delete $4;
    }
    ;

var_init_opt:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->type = "void";
    }
    | ASSIGN expression { $$ = $2; }
    ;

proc_decl:
    proc_header block
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok && $2->ok;
        if ($$->ok) {
            // TODO : Criar label aqui e associar ao nome do metodo
            $$->code = $2->code;
        } else {
            $$->code = "";
        }
        
        delete $1;
        delete $2;
    }
    ;

M_enter_proc_scope : NAME {
    $$ = $1;
    std::string proc_name = *$1;
    SymbolTable::enter_scope(proc_name);
}

proc_header:
    PROCEDURE M_enter_proc_scope '(' opt_param_list ')' opt_type
    {
        $$ = new BoolAttr();
        std::string proc_name = *$2;
        $$->ok = false;

        bool insert_ok = SymbolTable::insert_into_parent_scope(proc_name, TokenInfo($4->param_types_list, $6->type, Tag::PROC));

        if (!insert_ok) {
            print_token_location(@2.first_line, @2.first_column);
            std::cout << "Erro: Redefinição do procedimento '" << proc_name << "'." << std::endl;
        } else {
            $$->ok = true;
        }
        
        delete $2;
        delete $4;
        delete $6;
    }
    ;

opt_param_list:
      /* vazio */
    {
        $$ = new ListAttr();
        $$->ok = true;
        $$->param_types_list = std::vector<std::string>();
    }
    | paramfield_decl paramfield_tail
    {
        $$ = $2;
        if ($1->type != "ERR") {
            $$->param_types_list.insert($$->param_types_list.begin(), $1->type);
        } else {
            $$->ok = false;
        }
        delete $1;
    }
    ;

paramfield_tail:
      /* vazio */
    {
        $$ = new ListAttr();
        $$->ok = true;
        $$->param_types_list = std::vector<std::string>();
    }
    | ',' paramfield_decl paramfield_tail
    {
        $$ = $3;
        if ($2->type != "ERR") {
            $$->param_types_list.insert($$->param_types_list.begin(), $2->type);
        } else {
            $$->ok = false;
        }
        delete $2;
    }
    ;

opt_type:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->type = "void";
    }
    | ':' type { $$ = $2; }
    ;

block:
    BEGIN_TOK proc_body_opt stmt_list END
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok && $3->ok;
        if ($$->ok) {
            $$->code = $2->code + $3->code;
        } else {
            $$->code = "";
        }
        delete $2;
        delete $3;
        SymbolTable::exit_scope();
    }
    ;

proc_body_opt:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
        $$->code = "";
    }
    | decl decl_tail IN
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok && $2->ok;
        if ($$->ok) {
            $$->code = $1->code + $2->code;
        } else {
            $$->code = "";
        }
        delete $1;
        delete $2;
    }
    ;

rec_decl:
    STRUCT NAME '{' opt_struct_members '}'
    {
        $$ = new BoolAttr();
        $$->ok = false;
        std::string struct_name = *$2;
        std::string label = struct_name + "t" + std::to_string(curr_var++);

        bool insert_ok = SymbolTable::insert(struct_name, TokenInfo({}, struct_name, Tag::STRUCT, $4->member_map));
        
        if (!insert_ok) {
            print_token_location(@2.first_line, @2.first_column);
            std::cout << "Erro: Redefinição do tipo '" << struct_name << "'." << std::endl;
        }
        else {
            $$->ok = $4->ok;
            header_declarations += "struct " + label + " {\n"
                                + $4->code + "};\n\n";
            SymbolTable::set_label(struct_name, label);
        }


        

        delete $2;
        delete $4;
    }
    ;

opt_struct_members:
    /* vazio */
    {

        $$ = new MapAttr();
        $$->ok = true;
        $$->member_map = std::unordered_map<std::string, std::string>();
        $$->code = "";
    }
    | struct_member_decl struct_member_tail
    {
        $$ = $2;
        $$->ok = false;
        auto& first_member_map = $1->member_map;
        if($1->ok) {
            const auto [name, type] = *first_member_map.begin();

            if ($$->member_map.count(name) > 0) {
                print_token_location(@1.first_line, @1.first_column);
                std::cout << "Erro: Membro da struct '" << name << "' já foi declarado." << std::endl;
            }
            else {
                ($$->member_map)[name] = type;
                $$->ok = true;
                $$->code = "    " + resolve_type(type) + " " + name + ";\n"
                        + $2->code;

            }
        }
        delete $1;
    }
    ;

struct_member_tail:
    /* vazio */
    {
        $$ = new MapAttr();
        $$->ok = true;
        $$->member_map = std::unordered_map<std::string, std::string>();
        $$->code = "";
    }
    | ';' struct_member_decl struct_member_tail
    {
        $$ = $3;
        $$->ok = false;
        auto& new_member_map = $2->member_map;
        if ($2->ok) {
            const auto& [name, type] = *new_member_map.begin();

            if ($$->member_map.count(name) > 0) {
                print_token_location(@2.first_line, @2.first_column);
                std::cout << "Erro: Membro da struct '" << name << "' já foi declarado." << std::endl;
            } else {
                ($$->member_map)[name] = type;
                $$->ok = true;
                $$->code = "    " + resolve_type(type) + " " + name + ";\n"
                        + $3->code;
            }
        }
        delete $2;
    }
    ;

struct_member_decl:
    NAME ':' type
    {
        $$ = new MapAttr();
        $$->member_map = std::unordered_map<std::string, std::string>();
        $$->ok = false;
        
        if ($3->type != "ERR") {
            std::string member_name = *$1;
            std::string member_type = $3->type;
            ($$->member_map)[member_name] = member_type;
            $$->ok = true;
            $$->code = "    " + resolve_type(member_type) + " " + member_name + ";\n";
        }


        delete $1;
        delete $3;
    }
    ;

paramfield_decl:
    NAME ':' type
    {
        $$ = new TypedAttr();
        $$->type = $3->type;
        std::string field_name = *$1;
        if($$->type != "ERR") {
            bool insert_ok = SymbolTable::insert(field_name, TokenInfo({}, $3->type, Tag::PROC_PARAM));
            
            if (!insert_ok) {
                print_token_location(@1.first_line, @1.first_column);
                std::cout << "Erro: Parâmetro '" << field_name << "' já foi declarado." << std::endl;
                $$->type = "ERR";
            }
            
        }
        delete $1;
        delete $3;
    }
    ;

stmt_list:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
        $$->code = "";
    }
    | stmt stmt_tail
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok && $2->ok;
        if ($$->ok) {
            $$->code = $1->code + $2->code;
        } else {
            $$->code = "";
        }
        delete $1;
        delete $2;
    }
    ;

stmt_tail:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
        $$->code = "";
    }
    | ';' stmt stmt_tail
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok && $3->ok;
        if ($$->ok) {
            $$->code = $2->code + $3->code;
        } else {
            $$->code = "";
        }
        delete $2;
        delete $3;
    }
    ;

stmt:
      assign_stmt { $$ = $1; }
    | if_stmt     { $$ = $1; }
    | while_stmt  { $$ = $1; }
    | return_stmt { $$ = $1; }
    | call_stmt   { $$ = $1; }
    ;

assign_stmt:
      var ASSIGN expression
    {
        $$ = new BoolAttr();
        $$->ok = ($1->type != "ERR" && $3->type != "ERR");
        
        if ($$->ok) {
            if (!check_compatible($1->type, $3->type)) {
                print_token_location(@2.first_line, @2.first_column);
                std::cout << "Erro de Tipo: Incompatibilidade na atribuição. "
                          << "Não é possível atribuir uma expressão do tipo '" << $3->type
                          << "' a uma variável do tipo '" << $1->type << "'." << std::endl;
                $$->ok = false;
            }
            else {
                std::string var_name = $1->val;
                $$->code = $3->code + var_name + " = " + $3->val + ";\n";
            }
        }

        delete $1;
        delete $3;
    }
    | deref_var ASSIGN expression
    {
        $$ = new BoolAttr();
        $$->ok = ($1->type != "ERR" && $3->type != "ERR");
        
        if ($$->ok) {
            if ($1->type != $3->type) {
                print_token_location(@2.first_line, @2.first_column);
                std::cout << "Erro de Tipo: Incompatibilidade na atribuição. "
                          << "Não é possível atribuir uma expressão do tipo '" << $3->type
                          << "' a uma variável do tipo '" << $1->type << "'." << std::endl;
                $$->ok = false;
            }
            else {
                // TODO: Não criar a variavel de deref_var, e colocar em *$1->val, algo assim
                std::string var_name = $1->val;
                $$->code = $3->code + var_name + " = " + $3->val + ";\n";
            }
        }

        delete $1;
        delete $3;
    }
    ;

if_stmt:
    IF expression THEN stmt_list else_opt FI
    {
        $$ = new BoolAttr();
        $$->ok = ($2->type != "ERR") && $4->ok && $5->ok;
        if ($2->type != "ERR" && $2->type != "bool") {
            print_token_location(@2.first_line, @2.first_column);
            std::cout << "Erro de tipo: Condição do IF deve ser BOOL, mas foi '" << $2->type << "'." << std::endl;
            $$->ok = false;
        }
        if($$->ok) {
            std::string if_label = new_label();
            std::string end_label = new_label();
            $$->code =  $2->code 
                        + "if (" + $2->val + ") goto " + if_label + ";\n"
                        + $5->code + "goto " + end_label + ";\n"
                        + if_label + ":{\n"
                        + $4->code +"}"
                        + end_label + ":{\n}";
        }
        delete $2;
        delete $4;
        delete $5;
    }
    ;

else_opt:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
        $$->code = "";
    }
    | ELSE stmt_list
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok;
        if ($$->ok) {
            $$->code = $2->code;
        } else {
            $$->code = "";
        }
        delete $2;
    }
    ;

while_stmt:
    WHILE expression DO stmt_list OD
    {
        $$ = new BoolAttr();
        $$->ok =($2->type != "ERR") && $4->ok;
        if ($2->type != "ERR" && $2->type != "bool") {
            print_token_location(@2.first_line, @2.first_column);
            std::cout << "Erro de tipo: Condição do WHILE deve ser BOOL, mas foi '" << $2->type << "'." << std::endl;
            $$->ok = false;
        }
        if($$->ok) {
            std::string start_label = new_label();
            std::string end_label = new_label();
            std::string while_var = new_var("bool");

            $$->code =  start_label + ":{\n"
                        + $2->code
                        + while_var + " = !" + $2->val + ";\n"
                        + "if (" + while_var + ") goto " + end_label + ";\n"
                        + $4->code
                        + "goto " + start_label + ";\n}"
                        + end_label + ":{\n}";
        }
        delete $2;
        delete $4;
    }
    ;

return_stmt:
    RETURN return_exp_opt
    {
        $$ = new BoolAttr();
        $$->ok = $2->type != "ERR";

        if($$->ok) {
            std::string scope_name = SymbolTable::get_scope_name();
            auto lookup_result = SymbolTable::lookup(scope_name);
            if (!lookup_result || lookup_result->tag != Tag::PROC) {
                print_token_location(@1.first_line, @1.first_column);
                std::cout << "Erro: 'RETURN' usado fora de um procedimento/função." << std::endl;
                $$->ok = false;
            } else {
                
                if($2->type == lookup_result->type || 
                ($2->type == "void" && lookup_result->type == "void")) {
                    $$->ok = true;
                } else {
                    print_token_location(@1.first_line, @1.first_column);
                    std::cout << "Erro de tipo: 'RETURN' espera tipo '" << lookup_result->type 
                            << "', mas recebeu '" << $2->type << "'." << std::endl;
                    $$->ok = false;
                }
            }
        }

        delete $2;
    }
    ;

return_exp_opt:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->type = "void";
    }
    | expression { $$ = $1; }
    ;

call_stmt:
    call_exp
    {
        $$ = new BoolAttr();
        $$->ok = ($1->type != "ERR");
        if ($$->ok) {
            $$->code = $1->code;
        }
        delete $1;
    }
    ;

call_exp:
    NAME '(' call_args_opt ')'
    {
        $$ = new TypedAttr();
        $$->type = "ERR";
        $$->code = "";
        $$->val = "";
        std::string func_name = *$1;

        auto lookup_result = SymbolTable::lookup(func_name);
        if (!lookup_result || lookup_result->tag != Tag::PROC) {
            print_token_location(@1.first_line, @1.first_column);
            std::cout << "Erro: Função ou procedimento '" << func_name << "' não declarado." << std::endl;
        } else if($3->ok) {
            const auto& declared_params = lookup_result->paramList;
            const auto& provided_args = $3->param_types_list;

            if (declared_params.size() != provided_args.size()) {
                print_token_location(@1.first_line, @1.first_column);
                std::cout << "Erro: Função '" << func_name << "' espera " << declared_params.size() 
                          << " argumentos, mas recebeu " << provided_args.size() << "." << std::endl;
            } else {
                bool types_match = true;
                for (size_t i = 0; i < declared_params.size(); ++i) {
                    if (!check_compatible(declared_params[i], provided_args[i])) {
                        print_token_location(@1.first_line, @1.first_column);
                        std::cout << "Erro: Incompatibilidade de tipo no argumento " << i + 1 
                                  << " da chamada para '" << func_name << "'. Esperado '" 
                                  << declared_params[i] << "', mas recebeu '" << provided_args[i] << "'." << std::endl;
                        types_match = false;
                        break;
                    }
                }

                if (types_match) {
                    $$->type = lookup_result->type;
                    $$->code = $3->code;

                    if (func_name == "readint") {
                        $$->val = new_var("int");
                        $$->code += "scanf(\"%d\", &" + $$->val + ");\n";
                    } else if (func_name == "readfloat") {
                        $$->val = new_var("float");
                        $$->code += "scanf(\"%f\", &" + $$->val + ");\n";
                    } else if (func_name == "readchar") {
                        $$->val = new_var("int");
                        $$->code += $$->val + " = getchar();\n";
                    } else if (func_name == "readstring") {
                        $$->val = new_var("string"); 
                        $$->code += "scanf(\"%s\", " + $$->val + ");\n"; 
                    } else if (func_name == "readline") {
                        $$->val = new_var("string"); 
                        $$->code += "scanf(\"%[^\n]%*c\", " + $$->val + ");\n"; 
                    } else if (func_name == "printint") {
                        $$->code += "printf(\"%d\", " + $3->param_vals_list[0] + ");\n";
                    } else if (func_name == "printfloat") {
                        $$->code += "printf(\"%f\", " + $3->param_vals_list[0] + ");\n";
                    } else if (func_name == "printstr") {
                        $$->code += "printf(\"%s\", " + $3->param_vals_list[0] + ");\n";
                    } else if (func_name == "printline") {
                        $$->code += "printf(\"%s\\n\", " + $3->param_vals_list[0] + ");\n";
                    } else {
                        // Tratamento para funções definidas pelo usuário vem aqui
                       $$->code =+ "";
                    }
                } 
            }
        }
        delete $1;
        delete $3;
    }
    ;

call_args_opt:
      /* vazio */
    {
        $$ = new ListAttr();
        $$->ok = true;
        $$->param_types_list = std::vector<std::string>();
        $$->param_vals_list = std::vector<std::string>();
        $$->code = "";                                   
    }
    | expression call_args_tail
    {
        $$ = $2;
        if ($1->type != "ERR") {
            $$->param_types_list.insert($$->param_types_list.begin(), $1->type);
            $$->param_vals_list.insert($$->param_vals_list.begin(), $1->val); 
            $$->code = $1->code + $$->code;
        }
        else {
            $$->ok = false;
        }
        delete $1;
    }
    ;

call_args_tail:
      /* vazio */
    {
        $$ = new ListAttr();
        $$->ok = true;
        $$->param_types_list = std::vector<std::string>();
        $$->param_vals_list = std::vector<std::string>();
        $$->code = "";
    }
    | ',' expression call_args_tail
    {
        $$ = $3;
        if ($2->type != "ERR") {
            $$->param_types_list.insert($$->param_types_list.begin(), $2->type);
            $$->param_vals_list = std::vector<std::string>();
            $$->code = "";
        }
        else {
            $$->ok = false;
        }
        delete $2;
    }
    ;

expression:
    or_exp { $$ = $1; }
    ;

or_exp:
      or_exp OR and_exp
    {
        handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "OR", 
            [](const auto& t1, const auto& t2) { return t1 == "bool" && t2 == "bool"; },
            [](const auto& t1, const auto& t2) { return "bool"; });
    }
    | and_exp { $$ = $1; }
    ;

and_exp:
      and_exp AND not_exp
    {
        handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "AND",
            [](const auto& t1, const auto& t2) { return t1 == "bool" && t2 == "bool"; },
            [](const auto& t1, const auto& t2) { return "bool"; });
    }
    | not_exp { $$ = $1; }
    ;

not_exp:
      NOT not_exp
    {
        $$ = new TypedAttr();
        if ($2->type == "bool") {
            $$->type = "bool";
            $$->val = new_var("bool");
            $$->code = $2->code + $$->val + " = !" + $2->val + ";\n";
        } else {
            print_token_location(@1.first_line, @1.first_column);
            std::cout << "Erro de tipo: Operando de NOT deve ser BOOLEAN." << std::endl;
            $$->type = "ERR";
        }
        delete $2;
    }
    | rel_exp { $$ = $1; }
    ;

rel_exp: rel_exp LT add_exp {
    handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "<",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "bool"; });
}
| rel_exp LE add_exp {
    handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "<=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "bool"; });
}
| rel_exp GT add_exp{
    handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, ">",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "bool"; });
}
| rel_exp GE add_exp {
    handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, ">=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "bool"; });
}
| rel_exp EQ add_exp {
    handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "bool"; });
}
| rel_exp NE add_exp {
    handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "<>",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "bool"; });
}
| add_exp { $$ = $1; }
;


add_exp:
      add_exp PLUS mult_exp
    {
        handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "+",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            resolve_arithmetic_type);
    }
    | add_exp MINUS mult_exp
    {
        handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "-",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            resolve_arithmetic_type);
    }
    | mult_exp { $$ = $1; }
    ;

mult_exp:
      mult_exp MULT exp_exp
    {
        handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "*", 
        [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); }, 
        resolve_arithmetic_type);
    }
    | mult_exp DIV exp_exp
    {
        handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "/", 
        [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); }, 
        resolve_arithmetic_type);
    }
    | exp_exp { $$ = $1; }
    ;

exp_exp:
      unary_exp EXP_OP exp_exp
    {
        handle_binary_op($$, @2.first_line, @2.first_column, $1, $3, "^",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            [](const auto& t1, const auto& t2) { return "float"; });
    }
    | unary_exp { $$ = $1; }
    ;

unary_exp:
      MINUS unary_exp
    {
        $$ = new TypedAttr();
        $$->type = "ERR";
        if ($2->type != "ERR" && ($2->type == "int" || $2->type == "float")) {
            $$->type = $2->type;
            $$->val = new_var($2->type);
            $$->code = $2->code + $$->val + " = -" + $2->val + ";\n";
        } else {
            print_token_location(@1.first_line, @1.first_column);
            std::cout << "Erro de tipo: Operando unário '-' deve ser numérico." << std::endl;
        }
        delete $2;
    }
    | primary_exp { $$ = $1; }
    ;

primary_exp:
      literal           { $$ = $1; }
    | call_exp          { $$ = $1; }
    | NEW NAME
    {
        $$ = new TypedAttr();
        std::string type_name = *$2;
        auto lookup_result = SymbolTable::lookup(type_name);
        if (!lookup_result || lookup_result->tag != Tag::STRUCT) {
            print_token_location(@2.first_line, @2.first_column);
            std::cout << "Erro: Tipo '" << type_name << "' não é um struct para 'NEW'." << std::endl;
            $$->type = "ERR";
        } else {
            $$->type =  type_name ;
        }
        delete $2;
    }
    | var               { $$ = $1; } // x := 2 + deref(y)
    | ref_var           { $$ = $1; } // x : ref(int)
    | deref_var         { $$ = $1; } // y1 : int        y2 : ref(ref(int))
    | '(' expression ')'{ $$ = $2; } // x := deref(y2)       x := ref(y1)
                                     // int* x; int y1; int* y2; x = &y1; x = *y2;
    ;

var:
    NAME
    {
        $$ = new TypedAttr();
        $$->code = "";
        $$->val = *$1;
        std::string var_base_name = *$1;
        delete $1;

        auto lookup_result = SymbolTable::lookup(var_base_name);
        if (!lookup_result || (lookup_result->tag != Tag::VAR && lookup_result->tag != Tag::PROC_PARAM)) {
            print_token_location(@1.first_line, @1.first_column);
            std::cout << "Erro: Variável '" << var_base_name << "' não declarada." << std::endl;
            $$->type = "ERR";
        } else {
            $$->type = lookup_result->type;
            $$->val = lookup_result->label;
        }
    }
|   var '.' NAME
    {
        $$ = new TypedAttr();
        $$->type = "ERR";

        if ($1->type != "ERR") {
            std::string base_type_name = $1->type;
            std::string field_name = *$3;

            auto base_type_info_opt = SymbolTable::lookup(base_type_name);

            if (!base_type_info_opt || base_type_info_opt->tag != Tag::STRUCT) {
                print_token_location(@2.first_line, @2.first_column);
                std::cout << "Erro de tipo: Tentativa de acessar o campo '" << field_name 
                        << "' em um tipo não-struct ('" << base_type_name << "')." << std::endl;
            } else {
                auto& base_type_info = *base_type_info_opt;

                const auto& members_map = base_type_info.members;
                auto member_iterator = members_map.find(field_name);

                if (member_iterator == members_map.end()) {
                    print_token_location(@2.first_line, @2.first_column);
                    std::cout << "Erro de tipo: O tipo '" << base_type_name 
                            << "' não possui um membro chamado '" << field_name << "'." << std::endl;
                } else {
                    $$->type = member_iterator->second;
                    $$->val = $1->val + "." + field_name;
                }
            }
        }
        
        delete $1;
        delete $3;
    }
|   var '[' expression ']'
    {
        $$ = new TypedAttr();
        $$->type = "ERR";
        $$->code = "";

        bool ok = ($1->type != "ERR" && $3->type != "ERR");
        if (ok) {
            std::string base_type = $1->type;
            std::string index_type = $3->type;

            if (index_type != "int") {
                print_token_location(@3.first_line, @3.first_column);
                std::cout << "Erro de tipo: O índice de um array deve ser um inteiro, mas foi '" << index_type << "'." << std::endl;
            }
            else if (base_type.rfind("ARRAY(", 0) == 0 && base_type.back() == ')') {
                size_t comma_pos = base_type.find(',');
                $$->type = base_type.substr(comma_pos + 1, base_type.length() - comma_pos - 2);
                $$->code = $1->code + $3->code;
                $$->val = $1->val + "[" + $3->val + "]";

            } else {
                print_token_location(@1.first_line, @1.first_column);
                std::cout << "Erro de tipo: Tentativa de indexar um tipo não-array ('" << base_type << "')." << std::endl;
            }
        }
        delete $1;
        delete $3;
    }
    ;

ref_var:
    REF '(' var ')'
    {
        $$ = new TypedAttr();
        $$->type = "ERR";
        if ($3->type != "ERR") {
            $$->type = "REF(" + $3->type + ")";
            $$->code = $3->code; 
            $$->val = "&(" + $3->val + ")"; 
        }
        delete $3;
    }
    ;

deref_var:
      DEREF '(' var ')'
    {
        $$ = new TypedAttr();
        $$->type = "ERR";
        if($3->type != "ERR") {
            if ($3->type.rfind("REF(", 0) == 0) {
                $$->type = $3->type.substr(4, $3->type.length() - 5);
                $$->code = $3->code;
                $$->val = "*(" + $3->val + ")";
            } else {
                print_token_location(@1.first_line, @1.first_column);
                std::cout << "Erro de tipo: DEREF exige um tipo de referência." << std::endl;
            }
        }
        delete $3;
    }
    | DEREF '(' deref_var ')'
    {
        $$ = new TypedAttr();
        $$->type = "ERR";
        if($3->type != "ERR") {
            if ($3->type.rfind("REF(", 0) == 0) {
                $$->type = $3->type.substr(4, $3->type.length() - 5);
                $$->code = $3->code;
                $$->val = "*(" + $3->val + ")";
            } else {
                print_token_location(@1.first_line, @1.first_column);
                std::cout << "Erro de tipo: DEREF exige um tipo de referência (cascata)." << std::endl;
            }
        }
        delete $3;
    }
    ;

literal:
      FLOAT_LITERAL   { 
        $$ = new TypedAttr(); $$->type = "float"; $$->val = (*$1); $$->code = ""; delete $1; 
        }
    | INT_LITERAL     { 
        $$ = new TypedAttr(); $$->type = "int"; $$->val = (*$1); $$->code = ""; delete $1; 
        }
    | STRING_LITERAL  { 
        $$ = new TypedAttr(); $$->type = "string"; $$->val = (*$1); $$->code = ""; delete $1; 
        }
    | bool_literal    { $$ = $1; }
    | NULL_LIT        { $$ = new TypedAttr(); $$->type = "NULL"; }
    ;

bool_literal:
      TRUE  { $$ = new TypedAttr(); $$->type = "bool"; $$->val = "1"; $$->code = ""; }
    | FALSE { $$ = new TypedAttr(); $$->type = "bool"; $$->val = "0"; $$->code = ""; }
    ;

type:
      FLOAT_T   { $$ = new TypedAttr(); $$->type = "float"; }
    | INT_T     { $$ = new TypedAttr(); $$->type = "int"; }
    | STRING_T  { $$ = new TypedAttr(); $$->type = "string"; }
    | BOOL_T    { $$ = new TypedAttr(); $$->type = "bool"; }
    | NAME
    {
        $$ = new TypedAttr();
        std::string type_name = *$1;
        auto lookup_result = SymbolTable::lookup(type_name);
        
        if (lookup_result && lookup_result->tag == Tag::STRUCT) {
            $$->type = lookup_result->type;
        } else {
            print_token_location(@1.first_line, @1.first_column);
            std::cout << "Erro: '" << type_name << "' não é um tipo válido ou struct declarado." << std::endl;
            $$->type = "ERR";
        }
        delete $1;
    }
    | REF '(' type ')'
    {
        $$ = new TypedAttr();
        $$->type = "ERR";
        if ($3->type != "ERR") {
            $$->type = "REF(" + $3->type + ")";
        }
        delete $3;
    }
    | ARRAY '[' INT_LITERAL ']' OF type
    {
    $$ = new TypedAttr();
    $$->type = "ERR";
    if ($6->type != "ERR") {
        std::string size_str = *$3;
        $$->type = "ARRAY(" + size_str + "," + $6->type + ")";
    }
    delete $3;
    delete $6;
    }
    ;

%%

void yyerror(const char *s) {
    extern int yylineno;
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}

int main(void) {
    SymbolTable::enter_scope("global");

    SymbolTable::insert("readint", TokenInfo({}, "int", Tag::PROC));
    SymbolTable::insert("readfloat", TokenInfo({}, "float", Tag::PROC));
    SymbolTable::insert("readchar", TokenInfo({}, "int", Tag::PROC));
    SymbolTable::insert("readstring", TokenInfo({}, "string", Tag::PROC));
    SymbolTable::insert("readline", TokenInfo({}, "string", Tag::PROC));
    SymbolTable::insert("printint", TokenInfo({ "int" }, "void", Tag::PROC));
    SymbolTable::insert("printfloat", TokenInfo({ "float" }, "void", Tag::PROC));
    SymbolTable::insert("printstr", TokenInfo({ "string" }, "void", Tag::PROC));
    SymbolTable::insert("printline", TokenInfo({ "string" }, "void", Tag::PROC));

    yyparse();
    
    SymbolTable::exit_scope();
    
    return 0;
}