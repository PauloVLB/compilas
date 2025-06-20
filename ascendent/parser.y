

%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <iostream>

#include "types/attrs.hpp"
#include "symbol_table/symbol_table.hpp"

extern int yylex();
void yyerror(const char *s);
std::vector<std::unordered_map<std::string, TokenInfo>> SymbolTable::scopes;

%}

%union {
    std::string* sval;
    BoolAttr* b_attr;
    TypedAttr* t_attr;
}


%token <sval> NAME
%token <sval> FLOAT_LITERAL INT_LITERAL STRING_LITERAL
%token TRUE FALSE NULL_LIT

%token LPAREN RPAREN SEMICOLON LBRACKET RBRACKET LBRACE RBRACE COLON DOT COMMA CARET

%token PROGRAM BEGIN_TOK END VAR PROCEDURE STRUCT IN IF THEN ELSE FI WHILE DO OD RETURN NEW DEREF REF NOT ARRAY OF

%token ASSIGN
%token AND OR
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

// ATRIBUTOS

%type <b_attr> program opt_decls decl_tail decl var_decl proc_decl rec_decl

%type <t_attr> var_init_opt type expression

%%

program:
    PROGRAM NAME BEGIN_TOK opt_decls END
    {   
        // std::cout << "quawuda" << std::endl;
        $$ = new BoolAttr();
        $$->ok = $4->ok;
        if($$->ok) {
            printf("Análise sintática concluída com sucesso!\n");
        }
        if (!$$->ok) {
            printf("Erro de tipo encontrado no programa.\n");
		}
        delete $2;
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
        $$->ok = $2->ok && $3->ok;
        delete $2;
        delete $3;
    }
    ;

decl:
      var_decl
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok;
        delete $1;
    }
    | proc_decl
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok;
        delete $1;
    }
    | rec_decl
    {
        $$ = new BoolAttr();
        $$->ok = $1->ok;
        delete $1;
    }
    ;

var_decl:
      VAR NAME ':' type var_init_opt
    {
        $$ = new BoolAttr();
        $5->type = $4->type;
        bool insert_ok = SymbolTable::insert(*$2, TokenInfo({}, $4->type, Tag::VAR));
        if (!insert_ok) {
            std::cout << "Erro: Variável '" << *$2 << "' já declarada." << std::endl;
            YYABORT;
            $$->ok = false;
        } else {
            $$->ok = $5->ok;
        }
        delete $2;
        delete $4;
        delete $5;
        SymbolTable::print_all();
    }
    | VAR NAME ASSIGN expression
    {
        $$ = new BoolAttr();
        $$->ok = $4->ok;
        SymbolTable::print_all();
        SymbolTable::insert(*$2, TokenInfo({}, $4->type, Tag::VAR));
        delete $2;
        delete $4;
        SymbolTable::print_all();
    }
    ;

var_init_opt:
      /* vazio */
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "bool";
    }
    | ASSIGN expression
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "bool";
    }
    ;

proc_decl:
    PROCEDURE NAME '(' opt_param_list ')' opt_type block
    {
        $$ = new BoolAttr();
        $$->ok = true;
    }
    ;

opt_param_list:
      /* vazio */
    | paramfield_decl paramfield_tail
    ;

paramfield_tail:
      /* vazio */
    | ',' paramfield_decl paramfield_tail
    ;

opt_type:
      /* vazio */
    | ':' type
    ;

block:
    BEGIN_TOK proc_body_opt stmt_list END
    ;

proc_body_opt:
      /* vazio */
    | decl decl_tail IN
    ;

rec_decl:
    STRUCT NAME '{' opt_paramfield_decls '}'
    {
        $$ = new BoolAttr();
        $$->ok = true;
    }
    ;

opt_paramfield_decls:
      /* vazio */
    | paramfield_decl paramfield_decl_tail
    ;

paramfield_decl_tail:
      /* vazio */
    | ';' paramfield_decl paramfield_decl_tail
    ;

paramfield_decl:
    NAME ':' type
    ;

stmt_list:
      /* vazio */
    | stmt stmt_tail
    ;

stmt_tail:
      /* vazio */
    | ';' stmt stmt_tail
    ;

stmt:
      assign_stmt
    | if_stmt
    | while_stmt
    | return_stmt
    | call_stmt
    ;

assign_stmt:
      var ASSIGN expression
    | deref_var ASSIGN expression
    ;

if_stmt:
    IF expression THEN stmt_list else_opt FI
    ;

else_opt:
      /* vazio */
    | ELSE stmt_list
    ;

while_stmt:
    WHILE expression DO stmt_list OD
    ;

return_stmt:
    RETURN return_exp_opt
    ;

return_exp_opt:
      /* vazio */
    | expression
    ;

call_stmt:
    NAME '(' call_args_opt ')'
    ;

call_args_opt:
      /* vazio */
    | expression call_args_tail
    ;

call_args_tail:
      /* vazio */
    | ',' expression call_args_tail
    ;

//////////////////////////
// EXPRESSIONS COM NÍVEIS
//////////////////////////

expression:
      or_exp
      {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "ERR";
      }
    ;

or_exp:
      or_exp OR and_exp
    | and_exp
    ;

and_exp:
      and_exp AND not_exp
    | not_exp
    ;

not_exp:
      NOT not_exp
    | rel_exp
    ;

rel_exp:
      rel_exp LT add_exp
    | rel_exp LE add_exp
    | rel_exp GT add_exp
    | rel_exp GE add_exp
    | rel_exp EQ add_exp
    | rel_exp NE add_exp
    | add_exp
    ;

add_exp:
      add_exp PLUS mult_exp
    | add_exp MINUS mult_exp
    | mult_exp
    ;

mult_exp:
      mult_exp MULT exp_exp
    | mult_exp DIV exp_exp
    | exp_exp
    ;

exp_exp:
      unary_exp EXP_OP exp_exp
    | unary_exp
    ;

unary_exp:
      MINUS unary_exp
    | primary_exp
    ;

primary_exp:
      literal
    | call_stmt
    | NEW NAME
    | var
    | ref_var
    | deref_var
    | '(' expression ')'
    ;

//////////////////////////
// VARIÁVEIS
//////////////////////////

var:
      NAME var_suffix
    ;

var_suffix:
      /* vazio */
    | '.' NAME var_suffix
    | '[' expression ']' var_suffix
    ;

ref_var:
    REF '(' var ')'
    ;

deref_var:
      DEREF '(' var ')'
    | DEREF '(' deref_var ')'
    ;

//////////////////////////
// LITERAIS
//////////////////////////

literal:
      FLOAT_LITERAL
    | INT_LITERAL
    | STRING_LITERAL
    | bool_literal
    | NULL_LIT
    ;

bool_literal:
      TRUE
    | FALSE
    ;

//////////////////////////
// TIPOS
//////////////////////////

type:
      FLOAT_T
      {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "FLOAT";
      }
    | INT_T
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "INT";
    }
    | STRING_T
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "STRING";
    }
    | BOOL_T
    {
        $$ = new TypedAttr();
        $$->ok = true;
        $$->type = "BOOL";
    }
    | NAME
    {
        $$ = new TypedAttr();
        auto lookup_result = SymbolTable::lookup("name");
        if (lookup_result) {
            if (lookup_result->tag != Tag::STRUCT) {
                std::cout << "Erro: '" << *$1 << "' não é um tipo." << std::endl;
                YYABORT;
                $$->ok = false;
                $$->type = "ERR";
            }
            else {
                $$->ok = true;
                $$->type = lookup_result->type;
            }
        } else {
            std::cout << "Erro: Tipo '" << *$1 << "' não declarado." << std::endl;
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
        $$->type = $3->type;
        delete $3;
    }
    | ARRAY '[' INT_LITERAL ']' OF type
    {
        $$ = new TypedAttr();
        $$->ok = $6->ok;
        // Aqui você deve construir o tipo do array.
        // Por exemplo, você pode criar uma string como "ARRAY OF " + tipo_base.
        if($$->ok) {
            $$->type = "ARRAY OF " + $6->type; 
        } else {
            $$->type = "ERR";
        }
        delete $6;
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}

int main(void) {
    SymbolTable::enter_scope();
    // yydebug = 1;
    return yyparse();
}
