%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%union {
    char* str;
}

%token <str> NAME
%token <str> FLOAT_LITERAL INT_LITERAL STRING_LITERAL
%token TRUE FALSE NULL_LIT

%token PROGRAM BEGIN END VAR PROCEDURE STRUCT IN IF THEN ELSE FI WHILE DO OD RETURN NEW DEREF REF NOT

%token ASSIGN  // :=
%token AND OR
%token LT LE GT GE EQ NE
%token PLUS MINUS MULT DIV EXP_OP

%token FLOAT_T INT_T STRING_T BOOL_T

%start program

%%

program:
    PROGRAM NAME BEGIN opt_decls END
    ;

opt_decls:
      /* vazio */
    | decl decl_tail
    ;

decl_tail:
      /* vazio */
    | ';' decl decl_tail
    ;

decl:
      var_decl
    | proc_decl
    | rec_decl
    ;

var_decl:
      VAR NAME ':' type var_init_opt
    | VAR NAME ASSIGN exp
    ;

var_init_opt:
      /* vazio */
    | ASSIGN exp
    ;

proc_decl:
    PROCEDURE NAME '(' opt_param_list ')' opt_type block
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
    BEGIN proc_body_opt STMT_LIST END
    ;

proc_body_opt:
      /* vazio */
    | decl decl_tail IN
    ;

rec_decl:
    STRUCT NAME '{' opt_paramfield_decls '}'
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
      var ASSIGN exp
    | deref_var ASSIGN exp
    ;

if_stmt:
    IF exp THEN stmt_list else_opt FI
    ;

else_opt:
      /* vazio */
    | ELSE stmt_list
    ;

while_stmt:
    WHILE exp DO stmt_list OD
    ;

return_stmt:
    RETURN return_exp_opt
    ;

return_exp_opt:
      /* vazio */
    | exp
    ;

call_stmt:
    NAME '(' call_args_opt ')'
    ;

call_args_opt:
      /* vazio */
    | exp call_args_tail
    ;

call_args_tail:
      /* vazio */
    | ',' exp call_args_tail
    ;

exp:
      exp LOG_OP exp
    | NOT exp
    | exp REL_OP exp
    | exp ARITH_OP exp
    | literal
    | call_stmt
    | NEW NAME
    | var
    | ref_var
    | deref_var
    | '(' exp ')'
    ;

ref_var:
    REF '(' var ')'
    ;

deref_var:
      DEREF '(' var ')'
    | DEREF '(' deref_var ')'
    ;

var:
      NAME
    | exp '.' NAME
    ;

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

type:
      FLOAT_T
    | INT_T
    | STRING_T
    | BOOL_T
    | NAME
    | REF '(' type ')'
    ;

LOG_OP: AND | OR
REL_OP: LT | LE | GT | GE | EQ | NE
ARITH_OP: PLUS | MINUS | MULT | DIV | EXP_OP

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}

int main(void) {
    return yyparse();
}
