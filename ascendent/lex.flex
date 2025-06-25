%option noyywrap
%option yylineno

%{
#include <vector> 
#include <string>
#include "types/attrs.hpp"
#include "parser.tab.h"
#include <iostream>

extern YYSTYPE yylval;

std::string current_token;
int nColunas = 1;


void update_token(std::string token_name, std::string yytxt="") {
    if(token_name == "ignore") {
        // std::cout << "Ignore" << std::endl;
        nColunas += yyleng;
        return;
    }

    // SymbolTable::print_all();

    if(token_name == "\n" || token_name == "\r\n") {
        nColunas = 1;
        return;
    }
    current_token = token_name;
    //printf("Updated current token: %s\n", current_token.c_str());
    //printf("%s %s \n", token_name.c_str(), yytxt.c_str());
    yylloc.first_line = yylineno;
    yylloc.first_column = nColunas;
    nColunas += yyleng;
    yylloc.last_line = yylineno;
    yylloc.last_column = nColunas;

}

void comment(std::string yytxt) {
    nColunas += yyleng;
    for(char c : yytxt) {
        if(c == '\n') {
            yylineno++;
            nColunas = 0;
        }
    }
}

%}

DIGIT [0-9]
LOW_ALPHA [a-z]
UPPER_ALPHA [A-Z]
ALPHA [a-zA-Z]
NOT_PRINTABLE (\n|\r)
TUDO (\n|.)

INT_LITERAL {DIGIT}+
FLOAT_LITERAL {DIGIT}+.{DIGIT}+
STRING_LITERAL \"[^\n\"]*\"

END_OF_FILE <<EOF>>

%%

\(\*{TUDO}*\*\) {comment(yytext);}
\/\/.* {comment(yytext);}
program {update_token(yytext); return PROGRAM;}
begin {update_token(yytext); return BEGIN_TOK;}
end {update_token(yytext); return END;}
var {update_token(yytext); return VAR;}
procedure {update_token(yytext); return PROCEDURE;}
in {update_token(yytext); return IN;}
struct {update_token(yytext); return STRUCT;}
not {update_token(yytext); return NOT;}
new {update_token(yytext); return NEW;}
ref {update_token(yytext); return REF;}
deref {update_token(yytext); return DEREF;}
if {update_token(yytext); return IF;}
then {update_token(yytext); return THEN;}
else {update_token(yytext); return ELSE;}
fi {update_token(yytext); return FI;}
while {update_token(yytext); return WHILE;}
do {update_token(yytext); return DO;}
od {update_token(yytext); return OD;}
return {update_token(yytext); return RETURN;}
float {update_token(yytext); return FLOAT_T;}
int {update_token(yytext); return INT_T;}
string {update_token(yytext); return STRING_T;}
bool {update_token(yytext); return BOOL_T;}
array {update_token(yytext); return ARRAY;}
of {update_token(yytext); return OF;}
true {update_token(yytext); return TRUE;}
false {update_token(yytext); return FALSE;}
\( {update_token(yytext); return '(';}
\) {update_token(yytext); return ')';}

{STRING_LITERAL} {
    update_token("STRING_LITERAL", yytext);
    yylval.sval = new std::string(yytext);
    return STRING_LITERAL;
}
({ALPHA}({ALPHA}|{DIGIT}|\_)*({ALPHA}|{DIGIT}))|{ALPHA} {
    update_token("NAME", yytext);
    yylval.sval = new std::string(yytext);
    return NAME;
}
{DIGIT}+ {
    update_token("INT_LITERAL", yytext);
    yylval.sval = new std::string(yytext);
    return INT_LITERAL;
}
{DIGIT}+\.{DIGIT}+ {
    update_token("FLOAT_LITERAL", yytext);
    yylval.sval = new std::string(yytext);
    return FLOAT_LITERAL;
}
\n {update_token("\n");}

\&\& {update_token(yytext);return AND;}
\|\| {update_token(yytext);return OR;}

"+" {update_token(yytext);return PLUS;}
"-" {update_token(yytext);return MINUS;}
"*" {update_token(yytext);return MULT;}
"/" {update_token(yytext);return DIV;}
":=" {update_token(yytext);return ASSIGN;}
";" {update_token(yytext);return ';';}

"[" {update_token(yytext); return '[';}
"]" {update_token(yytext); return ']';}
"{" {update_token(yytext); return '{';}
"}" {update_token(yytext); return '}';}
":" {update_token(yytext); return ':';}
"." {update_token(yytext); return '.';}
"," {update_token(yytext); return ',';}
"^" {update_token(yytext); return EXP_OP;}
"<>" {update_token(yytext);return NE;}

"=" {update_token(yytext);return EQ;}
"<" {update_token(yytext);return LT;}
">" {update_token(yytext);return GT;}
"<=" {update_token(yytext);return LE;}
">=" {update_token(yytext);return GE;}

<<EOF>> {update_token("$"); return 0;}
" " {update_token("ignore");}

. {printf("\nERRO %d %d\n", yylineno, nColunas); return 0;}

%%
