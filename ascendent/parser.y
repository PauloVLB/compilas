%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <optional>

#include "types/attrs.hpp"
#include "symbol_table/symbol_table.hpp"

extern int yylex();
void yyerror(const char *s);
%}

%union {
    std::string* sval;
    BoolAttr* b_attr;
    TypedAttr* t_attr;
    std::vector<std::string>* param_types_list;
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

%type <b_attr> program opt_decls decl_tail decl var_decl proc_decl rec_decl block proc_body_opt
%type <b_attr> opt_paramfield_decls paramfield_decl_tail
%type <b_attr> stmt_list stmt_tail stmt assign_stmt if_stmt else_opt while_stmt call_stmt
%type <b_attr> M_proc_scope_enter

%type <t_attr> var_init_opt opt_type return_stmt return_exp_opt call_args_opt call_args_tail call_exp
%type <t_attr> expression or_exp and_exp not_exp rel_exp add_exp mult_exp exp_exp unary_exp primary_exp
%type <t_attr> var ref_var deref_var literal bool_literal type
%type <t_attr> paramfield_decl

%type <param_types_list> opt_param_list paramfield_tail


%%

program:
    PROGRAM NAME BEGIN_TOK opt_decls END
    {
        std::string program_name = *$2;
        delete $2;
        
        $$ = new BoolAttr();
        $$->ok = $4->ok;
        
        if ($$->ok) {
            printf("Análise sintática concluída com sucesso para o programa '%s'!\n", program_name.c_str());
        } else {
            printf("Análise sintática encerrada devido a erro no programa '%s'.\n", program_name.c_str());
        }
        delete $4;
    }
    ;

opt_decls:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
    }
    | decl decl_tail
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok && $2->ok;
        delete $1;
        delete $2;
    }
    ;

decl_tail:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
    }
    | ';' decl decl_tail
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok && $3->ok;
        delete $2;
        delete $3;
    }
    ;

decl:
      var_decl  { $$ = new BoolAttr(); $$->ok = $1->ok; delete $1; }
    | proc_decl { $$ = new BoolAttr(); $$->ok = $1->ok; delete $1; }
    | rec_decl  { $$ = new BoolAttr(); $$->ok = $1->ok; delete $1; }
    ;

var_decl:
    VAR NAME ':' type var_init_opt
    {
        $$ = new BoolAttr();
        std::string var_name = *$2;
        bool insert_ok = SymbolTable::insert(var_name, TokenInfo({}, $4->type, Tag::VAR));
        
        if (!insert_ok) {
            std::cout << "Erro: Variável '" << var_name << "' já declarada." << std::endl;
            YYABORT;
            $$->ok = false;
        } else {
            $$->ok = $4->ok && $5->ok;
        }
        delete $2;
        delete $4;
        delete $5;
        SymbolTable::print_all();
    }
    ;

var_init_opt:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "void";
    }
    | ASSIGN expression
    {
        $$ = new TypedAttr();
        $$->ok = $2->ok;
        $$->type = $2->type;
        delete $2;
    }
    ;

M_proc_scope_enter:
      /* vazio */
    {
        SymbolTable::enter_scope();
        $$ = new BoolAttr();
        $$->ok = true;
    }
    ;

proc_decl:
    PROCEDURE NAME M_proc_scope_enter '(' opt_param_list ')' opt_type block
    {
        $$ = new BoolAttr();
        std::string proc_name = *$2;
        bool insert_ok = SymbolTable::insert(proc_name, TokenInfo(*$5, $7->type, Tag::PROC));
        
        if (!insert_ok) {
            std::cout << "Erro: Redefinição do procedimento '" << proc_name << "'." << std::endl;
            YYABORT;
            $$->ok = false;
        } else {
            $$->ok = $3->ok && $7->ok && $8->ok;
        }
        
        delete $2;
        delete $3;
        delete $5;
        delete $7;
        delete $8;
        SymbolTable::print_all();
    }
    ;

opt_param_list:
      /* vazio */
    {
        $$ = new std::vector<std::string>();
    }
    | paramfield_decl paramfield_tail
    {
        $$ = $2;
        if ($1->ok) {
            $$->insert($$->begin(), $1->type);
        } else {
            $$->clear();
        }
        delete $1;
    }
    ;

paramfield_tail:
      /* vazio */
    {
        $$ = new std::vector<std::string>();
    }
    | ',' paramfield_decl paramfield_tail
    {
        $$ = $3;
        if ($2->ok) {
            $$->insert($$->begin(), $2->type);
        } else {
            $$->clear();
        }
        delete $2;
    }
    ;

opt_type:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "void";
    }
    | ':' type
    {
        $$ = new TypedAttr();
        $$->ok = $2->ok;
        $$->type = $2->type;
        delete $2;
    }
    ;

block:
    BEGIN_TOK proc_body_opt stmt_list END
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok && $3->ok;
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
    }
    | decl decl_tail IN
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok && $2->ok;
        delete $1;
        delete $2;
    }
    ;

rec_decl:
    STRUCT NAME '{' opt_paramfield_decls '}'
    {
        $$ = new BoolAttr();
        std::string struct_name = *$2;
        bool insert_ok = SymbolTable::insert(struct_name, TokenInfo({}, "STRUCT(" + struct_name + ")", Tag::STRUCT));
        
        if (!insert_ok) {
            std::cout << "Erro: Struct '" << struct_name << "' já declarado." << std::endl;
            YYABORT;
            $$->ok = false;
        } else {
            $$->ok = $4->ok;
        }
        delete $2;
        delete $4;
    }
    ;

opt_paramfield_decls:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
    }
    | paramfield_decl paramfield_decl_tail
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok && $2->ok;
        delete $1;
        delete $2;
    }
    ;

paramfield_decl_tail:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
    }
    | ';' paramfield_decl paramfield_decl_tail
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok && $3->ok;
        delete $2;
        delete $3;
    }
    ;

paramfield_decl:
    NAME ':' type
    {
        $$ = new TypedAttr();
        std::string field_name = *$1;
        bool insert_ok = SymbolTable::insert(field_name, TokenInfo({}, $3->type, Tag::PROC_PARAM));
        
        if (!insert_ok) {
            std::cout << "Erro: Parâmetro '" << field_name << "' já foi declarado." << std::endl;
            YYABORT;
            $$->ok = false;
        } else {
            $$->ok = $3->ok;
        }
        
        $$->type = $3->type;
        delete $1;
        delete $3;
    }
    ;

stmt_list:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
    }
    | stmt stmt_tail
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok && $2->ok;
        delete $1;
        delete $2;
    }
    ;

stmt_tail:
      /* vazio */
    {
        $$ = new BoolAttr();
        $$->ok = true;
    }
    | ';' stmt stmt_tail
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok && $3->ok;
        delete $2;
        delete $3;
    }
    ;

stmt:
      assign_stmt { $$ = new BoolAttr(); $$->ok = $1->ok; delete $1; }
    | if_stmt     { $$ = new BoolAttr(); $$->ok = $1->ok; delete $1; }
    | while_stmt  { $$ = new BoolAttr(); $$->ok = $1->ok; delete $1; }
    | return_stmt { $$ = new BoolAttr(); $$->ok = $1->ok; delete $1; }
    | call_stmt   { $$ = new BoolAttr(); $$->ok = $1->ok; delete $1; }
    ;

assign_stmt:
      var ASSIGN expression
    {
        $$ = new BoolAttr();
        
        if (!$1->ok || !$3->ok) {
            $$->ok = false;
        } else {
            bool is_compatible = ($1->type == $3->type) || 
                                 ($3->type == "NULL" && $1->type.rfind("REF(", 0) == 0);

            if (!is_compatible) {
                std::cout << "Erro de Tipo: Incompatibilidade na atribuição. "
                          << "Não é possível atribuir uma expressão do tipo '" << $3->type
                          << "' a uma variável do tipo '" << $1->type << "'." << std::endl;
                YYABORT;
                $$->ok = false;
            } else {
                $$->ok = true;
            }
        }

        delete $1;
        delete $3;
    }
    | deref_var ASSIGN expression
    {
        $$ = new BoolAttr();
        
        if (!$1->ok || !$3->ok) {
            $$->ok = false;
        } else {
            if ($1->type != $3->type) {
                std::cout << "Erro de Tipo: Incompatibilidade na atribuição. "
                          << "Não é possível atribuir uma expressão do tipo '" << $3->type
                          << "' a uma variável do tipo '" << $1->type << "'." << std::endl;
                YYABORT;
                $$->ok = false;
            } else {
                $$->ok = true;
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
        if ($2->type != "BOOL") {
            std::cout << "Erro de tipo: Condição do IF deve ser BOOL, mas foi '" << $2->type << "'." << std::endl;
            YYABORT;
            $$->ok = false;
        } else {
            $$->ok = $2->ok && $4->ok && $5->ok;
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
    }
    | ELSE stmt_list
    {
        $$ = new BoolAttr();
        $$->ok = $2->ok;
        delete $2;
    }
    ;

while_stmt:
    WHILE expression DO stmt_list OD
    {
        $$ = new BoolAttr();
        if ($2->type != "BOOL") {
            std::cout << "Erro de tipo: Condição do WHILE deve ser BOOL, mas foi '" << $2->type << "'." << std::endl;
            YYABORT;
            $$->ok = false;
        } else {
            $$->ok = $2->ok && $4->ok;
        }
        delete $2;
        delete $4;
    }
    ;

return_stmt:
    RETURN return_exp_opt
    {
        $$ = new TypedAttr();
        $$->ok = $2->ok;
        $$->type = $2->type;
        delete $2;
    }
    ;

return_exp_opt:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "void";
    }
    | expression
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
    ;

call_stmt:
    call_exp
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok;
        delete $1;
    }
    ;

call_exp:
    NAME '(' call_args_opt ')'
    {
        $$ = new TypedAttr();
        std::string func_name = *$1;
        delete $1;

        auto lookup_result = SymbolTable::lookup(func_name);
        if (!lookup_result || lookup_result->tag != Tag::PROC) {
            std::cout << "Erro: Função ou procedimento '" << func_name << "' não declarado." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        } else {
            $$->ok = $3->ok;
            $$->type = lookup_result->type;
        }
        delete $3;
    }
    ;

call_args_opt:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "void";
    }
    | expression call_args_tail
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $2->ok;
        $$->type = "void";
        delete $1;
        delete $2;
    }
    ;

call_args_tail:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "void";
    }
    | ',' expression call_args_tail
    {
        $$ = new TypedAttr();
        $$->ok = $2->ok && $3->ok;
        $$->type = "void";
        delete $2;
        delete $3;
    }
    ;

expression:
    or_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
    ;

or_exp:
      or_exp OR and_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $3->ok;
        if ($$->ok && $1->type == "BOOL" && $3->type == "BOOL") {
            $$->type = "BOOL";
        } else {
            std::cout << "Erro de tipo: Operandos de OR devem ser BOOLEAN." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $1;
        delete $3;
    }
    | and_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
    ;

and_exp:
      and_exp AND not_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $3->ok;
        if ($$->ok && $1->type == "BOOL" && $3->type == "BOOL") {
            $$->type = "BOOL";
        } else {
            std::cout << "Erro de tipo: Operandos de AND devem ser BOOLEAN." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $1;
        delete $3;
    }
    | not_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
    ;

not_exp:
      NOT not_exp
    {
        $$ = new TypedAttr();
        $$->ok = $2->ok;
        if ($$->ok && $2->type == "BOOL") {
            $$->type = "BOOL";
        } else {
            std::cout << "Erro de tipo: Operando de NOT deve ser BOOLEAN." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $2;
    }
    | rel_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
    ;

rel_exp: rel_exp LT add_exp {
  $$ = new TypedAttr();
  $$->ok = $1->ok && $3->ok;
  if ($$->ok && $1->type == $3->type) {
    $$->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    $$->ok = false;
    $$->type = "ERR";
  }
  delete $1;
  delete $3;
}
| rel_exp LE add_exp {
  $$ = new TypedAttr();
  $$->ok = $1->ok && $3->ok;
  if ($$->ok && $1->type == $3->type) {
    $$->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    $$->ok = false;
    $$->type = "ERR";
  }
  delete $1;
  delete $3;
}
| rel_exp GT add_exp{
  $$ = new TypedAttr();
  $$->ok = $1->ok && $3->ok;
  if ($$->ok && $1->type == $3->type) {
    $$->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    $$->ok = false;
    $$->type = "ERR";
  }
  delete $1;
  delete $3;
}
| rel_exp GE add_exp {
  $$ = new TypedAttr();
  $$->ok = $1->ok && $3->ok;
  if ($$->ok && $1->type == $3->type) {
    $$->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    $$->ok = false;
    $$->type = "ERR";
  }
  delete $1;
  delete $3;
}
| rel_exp EQ add_exp {
  $$ = new TypedAttr();
  $$->ok = $1->ok && $3->ok;
  if ($$->ok && $1->type == $3->type) {
    $$->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    $$->ok = false;
    $$->type = "ERR";
  }
  delete $1;
  delete $3;
}
| rel_exp NE add_exp {
  $$ = new TypedAttr();
  $$->ok = $1->ok && $3->ok;
  if ($$->ok && $1->type == $3->type) {
    $$->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    $$->ok = false;
    $$->type = "ERR";
  }
  delete $1;
  delete $3;
}
| add_exp {
  $$ = new TypedAttr();
 
  $$->ok = $1->ok;
  $$->type = $1->type;
  delete $1;
}
;


add_exp:
      add_exp PLUS mult_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $3->ok;
        if ($$->ok && ($1->type == "INT" || $1->type == "FLOAT") && ($3->type == "INT" || $3->type == "FLOAT")) {
            $$->type = ($1->type == "FLOAT" || $3->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de adição/subtração devem ser numéricos." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $1;
        delete $3;
    }
    | add_exp MINUS mult_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $3->ok;
        if ($$->ok && ($1->type == "INT" || $1->type == "FLOAT") && ($3->type == "INT" || $3->type == "FLOAT")) {
            $$->type = ($1->type == "FLOAT" || $3->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de adição/subtração devem ser numéricos." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $1;
        delete $3;
    }
    | mult_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
    ;

mult_exp:
      mult_exp MULT exp_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $3->ok;
        if ($$->ok && ($1->type == "INT" || $1->type == "FLOAT") && ($3->type == "INT" || $3->type == "FLOAT")) {
            $$->type = ($1->type == "FLOAT" || $3->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de multiplicação/divisão devem ser numéricos." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $1;
        delete $3;
    }
    | mult_exp DIV exp_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $3->ok;
        if ($$->ok && ($1->type == "INT" || $1->type == "FLOAT") && ($3->type == "INT" || $3->type == "FLOAT")) {
            $$->type = ($1->type == "FLOAT" || $3->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de multiplicação/divisão devem ser numéricos." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $1;
        delete $3;
    }
    | exp_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
    ;

exp_exp:
      unary_exp EXP_OP exp_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $3->ok;
        if ($$->ok && ($1->type == "INT" || $1->type == "FLOAT") && ($3->type == "INT" || $3->type == "FLOAT")) {
            $$->type = ($1->type == "FLOAT" || $3->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de exponenciação devem ser numéricos." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $1;
        delete $3;
    }
    | unary_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
    ;

unary_exp:
      MINUS unary_exp
    {
        $$ = new TypedAttr();
        $$->ok = $2->ok;
        if ($$->ok && ($2->type == "INT" || $2->type == "FLOAT")) {
            $$->type = $2->type;
        } else {
            std::cout << "Erro de tipo: Operando unário '-' deve ser numérico." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $2;
    }
    | primary_exp
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = $1->type;
        delete $1;
    }
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
            std::cout << "Erro: Tipo '" << type_name << "' não é um struct para 'NEW'." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        } else {
            $$->ok = true;
            $$->type = "REF(" + type_name + ")";
        }
        delete $2;
    }
    | var               { $$ = $1; }
    | ref_var           { $$ = $1; }
    | deref_var         { $$ = $1; }
    | '(' expression ')'{ $$ = $2; }
    ;

var:
    NAME
    {
        $$ = new TypedAttr();
        std::string var_base_name = *$1;
        delete $1;

        auto lookup_result = SymbolTable::lookup(var_base_name);
        if (!lookup_result || (lookup_result->tag != Tag::VAR && lookup_result->tag != Tag::PROC_PARAM)) {
            std::cout << "Erro: Variável '" << var_base_name << "' não declarada." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        } else {
            $$->ok = true;
            $$->type = lookup_result->type;
        }
    }
|   var '.' NAME
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok;
        $$->type = "ERR";

        if ($$->ok) {
            std::string base_type = $1->type;
            std::string field_name = *$3;
            delete $3;

            if (base_type == "INT" || base_type == "FLOAT" || base_type == "STRING" || base_type == "BOOL") {
                std::cout << "Erro de tipo: Tentativa de acessar o campo '" << field_name << "' em um tipo primitivo ('" << base_type << "')." << std::endl;
                YYABORT;
                $$->ok = false;
            } else {
                std::cout << "AVISO: Verificação semântica para o campo '" << field_name << "' não está totalmente implementada." << std::endl;
                $$->ok = true;
                $$->type = "any";
            }
        }
        delete $1;
    }
|   var '[' expression ']'
    {
        $$ = new TypedAttr();
        $$->ok = $1->ok && $3->ok;
        $$->type = "ERR";

        if ($$->ok) {
            std::string base_type = $1->type;
            std::string index_type = $3->type;

            if (index_type != "INT") {
                std::cout << "Erro de tipo: O índice de um array deve ser um inteiro, mas foi '" << index_type << "'." << std::endl;
                YYABORT;
                $$->ok = false;
            }

            if ($$->ok) {
                if (base_type.rfind("ARRAY(", 0) == 0) {
                    $$->type = base_type.substr(6, base_type.length() - 7);
                } else {
                    std::cout << "Erro de tipo: Tentativa de indexar um tipo não-array ('" << base_type << "')." << std::endl;
                    YYABORT;
                    $$->ok = false;
                }
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
        $$->ok = $3->ok;
        if ($$->ok) {
            $$->type = "REF(" + $3->type + ")";
        } else {
            $$->type = "ERR";
        }
        delete $3;
    }
    ;

deref_var:
      DEREF '(' var ')'
    {
        $$ = new TypedAttr();
        $$->ok = $3->ok;
        if ($$->ok && $3->type.rfind("REF(", 0) == 0) {
            $$->type = $3->type.substr(4, $3->type.length() - 5);
        } else {
            std::cout << "Erro de tipo: DEREF exige um tipo de referência." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $3;
    }
    | DEREF '(' deref_var ')'
    {
        $$ = new TypedAttr();
        $$->ok = $3->ok;
        if ($$->ok && $3->type.rfind("REF(", 0) == 0) {
            $$->type = $3->type.substr(4, $3->type.length() - 5);
        } else {
            std::cout << "Erro de tipo: DEREF exige um tipo de referência (cascata)." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $3;
    }
    ;

literal:
      FLOAT_LITERAL   { $$ = new TypedAttr(); $$->ok = true; $$->type = "FLOAT"; delete $1; }
    | INT_LITERAL     { $$ = new TypedAttr(); $$->ok = true; $$->type = "INT"; delete $1; }
    | STRING_LITERAL  { $$ = new TypedAttr(); $$->ok = true; $$->type = "STRING"; delete $1; }
    | bool_literal    { $$ = $1; }
    | NULL_LIT        { $$ = new TypedAttr(); $$->ok = true; $$->type = "NULL"; }
    ;

bool_literal:
      TRUE  { $$ = new TypedAttr(); $$->ok = true; $$->type = "BOOL"; }
    | FALSE { $$ = new TypedAttr(); $$->ok = true; $$->type = "BOOL"; }
    ;

type:
      FLOAT_T   { $$ = new TypedAttr(); $$->ok = true; $$->type = "FLOAT"; }
    | INT_T     { $$ = new TypedAttr(); $$->ok = true; $$->type = "INT"; }
    | STRING_T  { $$ = new TypedAttr(); $$->ok = true; $$->type = "STRING"; }
    | BOOL_T    { $$ = new TypedAttr(); $$->ok = true; $$->type = "BOOL"; }
    | NAME
    {
        $$ = new TypedAttr();
        std::string type_name = *$1;
        auto lookup_result = SymbolTable::lookup(type_name);
        
        if (lookup_result && lookup_result->tag == Tag::STRUCT) {
            $$->ok = true;
            $$->type = lookup_result->type;
        } else {
            std::cout << "Erro: '" << type_name << "' não é um tipo válido ou struct declarado." << std::endl;
            YYABORT;
            $$->ok = false;
            $$->type = "ERR";
        }
        delete $1;
    }
    | REF '(' type ')'
    {
        $$ = new TypedAttr();
        $$->ok = $3->ok;
        if ($$->ok) {
            $$->type = "REF(" + $3->type + ")";
        } else {
            $$->type = "ERR";
        }
        delete $3;
    }
    | ARRAY '[' INT_LITERAL ']' OF type
    {
        $$ = new TypedAttr();
        $$->ok = $6->ok;
        if ($$->ok) {
            $$->type = "ARRAY(" + $6->type + ")";
        } else {
            $$->type = "ERR";
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
    SymbolTable::enter_scope();
    yyparse();
    
    std::cout << "\n--- Conteúdo Final da Tabela de Símbolos ---" << std::endl;
    SymbolTable::print_all();
    SymbolTable::exit_scope();
    
    return 0;
}