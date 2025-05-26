%option noyywrap

%{
#include "../symbol_table.hpp"
#include <string>
#include "parser.hpp"
#include <iostream>
std::string current_token;
std::unordered_map<std::string, std::stack<std::string>> symbol_table::table;
int nLinhas = 1;
int nColunas = 0;


void update_token(std::string token_name, std::string yytxt="") {
    if(token_name == "ignore") {
        nColunas += yyleng;
        return;
    }

    if(token_name == "\n" || token_name == "\r\n") {
        nLinhas++;
        nColunas = 0;
        return;
    }
    current_token = token_name;
    //printf("Updated current token: %s\n", current_token.c_str());
    printf("%s %s \n", token_name.c_str(), yytxt.c_str());
    nColunas += yyleng;
}

void comment(std::string yytxt) {
    nColunas += yyleng;
    for(char c : yytxt) {
        if(c == '\n') {
            nLinhas++;
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
STRING_LITERAL \"[^{NOT_PRINTABLE}]*\"

END_OF_FILE <<EOF>>

%%

\(\*{TUDO}*\*\) {comment(yytext);}
\/\/.* {comment(yytext);}
program {update_token(yytext); return yytokentype::PROGRAM;}
begin {update_token(yytext); return yytokentype::BEGIN_TOK;}
end {update_token(yytext); return yytokentype::END;}
var {update_token(yytext); return yytokentype::VAR;}
procedure {update_token(yytext); return yytokentype::PROCEDURE;}
in {update_token(yytext); return yytokentype::IN;}
struct {update_token(yytext); return yytokentype::STRUCT;}
not {update_token(yytext); return yytokentype::NOT;}
new {update_token(yytext); return yytokentype::NEW;}
ref {update_token(yytext); return yytokentype::REF;}
deref {update_token(yytext); return yytokentype::DEREF;}
if {update_token(yytext); return yytokentype::IF;}
then {update_token(yytext); return yytokentype::THEN;}
else {update_token(yytext); return yytokentype::ELSE;}
fi {update_token(yytext); return yytokentype::FI;}
while {update_token(yytext); return yytokentype::WHILE;}
do {update_token(yytext); return yytokentype::DO;}
od {update_token(yytext); return yytokentype::OD;}
return {update_token(yytext); return yytokentype::RETURN;}
float {update_token(yytext); return yytokentype::FLOAT_T;}
int {update_token(yytext); return yytokentype::INT_T;}
string {update_token(yytext); return yytokentype::STRING_T;}
bool {update_token(yytext); return yytokentype::BOOL_T;}
array {update_token(yytext); return 1;}
of {update_token(yytext); return 1;}
true {update_token(yytext); return yytokentype::TRUE;}
false {update_token(yytext); return yytokentype::FALSE;}
print {update_token(yytext); return 1;}
\( {update_token(yytext); return '(';}
\) {update_token(yytext); return ')';}

{STRING_LITERAL} {update_token("STRING_LITERAL", yytext);return yytokentype::STRING_LITERAL;}
({ALPHA}({ALPHA}|{DIGIT}|\_)*({ALPHA}|{DIGIT}))|{ALPHA} {update_token("NAME", yytext); symbol_table::insert(yytext, yytext);return yytokentype::NAME;}
{DIGIT}+ {update_token("INT_LITERAL", yytext);return yytokentype::INT_LITERAL;}
{DIGIT}+\.{DIGIT}+ {update_token("FLOAT_LITERAL", yytext);return yytokentype::FLOAT_LITERAL;}
\n {update_token("\n");}

\&\& {update_token(yytext);return yytokentype::AND;}
\|\| {update_token(yytext);return yytokentype::OR;}

"+" {update_token(yytext);return yytokentype::PLUS;}
"-" {update_token(yytext);return yytokentype::MINUS;}
"*" {update_token(yytext);return yytokentype::MULT;}
"/" {update_token(yytext);return yytokentype::DIV;}
":=" {update_token(yytext);return yytokentype::ASSIGN;}
";" {update_token(yytext);return ';';}

"[" {update_token(yytext); return '[';}
"]" {update_token(yytext); return ']';}
"{" {update_token(yytext); return '{';}
"}" {update_token(yytext); return '}';}
":" {update_token(yytext); return ':';}
"." {update_token(yytext); return '.';}
"," {update_token(yytext); return ',';}
"^" {update_token(yytext); return '^';}
"<>" {update_token(yytext);return yytokentype::NE;}

"=" {update_token(yytext);return yytokentype::EQ;}
"<" {update_token(yytext);return yytokentype::LT;}
">" {update_token(yytext);return yytokentype::GT;}
"<=" {update_token(yytext);return yytokentype::LE;}
">=" {update_token(yytext);return yytokentype::GE;}

<<EOF>> {update_token("$"); return 0;}
" " {update_token("ignore");}

. {printf("\nERRO %d %d\n", nLinhas, nColunas); return 0;}

%%
