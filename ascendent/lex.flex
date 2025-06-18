%option noyywrap

%{
//#include "symbol_table/symbol_table.hpp"
#include <string>
#include "types/attrs.hpp"
#include "parser.hpp"
#include <iostream>
std::string current_token;
//std::vector<std::unordered_map<std::string, TokenInfo>> SymbolTable::scopes;
int nLinhas = 1;
int nColunas = 0;


void update_token(std::string token_name, std::string yytxt="") {
    if(token_name == "ignore") {
        // std::cout << "Ignore" << std::endl;
        nColunas += yyleng;
        return;
    }

    // SymbolTable::print_all();

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
program {update_token(yytext); return yy::parser::token::yytokentype::PROGRAM;}
begin {update_token(yytext); return yy::parser::token::yytokentype::BEGIN_TOK;}
end {update_token(yytext); return yy::parser::token::yytokentype::END;}
var {update_token(yytext); return yy::parser::token::yytokentype::VAR;}
procedure {update_token(yytext); return yy::parser::token::yytokentype::PROCEDURE;}
in {update_token(yytext); return yy::parser::token::yytokentype::IN;}
struct {update_token(yytext); return yy::parser::token::yytokentype::STRUCT;}
not {update_token(yytext); return yy::parser::token::yytokentype::NOT;}
new {update_token(yytext); return yy::parser::token::yytokentype::NEW;}
ref {update_token(yytext); return yy::parser::token::yytokentype::REF;}
deref {update_token(yytext); return yy::parser::token::yytokentype::DEREF;}
if {update_token(yytext); return yy::parser::token::yytokentype::IF;}
then {update_token(yytext); return yy::parser::token::yytokentype::THEN;}
else {update_token(yytext); return yy::parser::token::yytokentype::ELSE;}
fi {update_token(yytext); return yy::parser::token::yytokentype::FI;}
while {update_token(yytext); return yy::parser::token::yytokentype::WHILE;}
do {update_token(yytext); return yy::parser::token::yytokentype::DO;}
od {update_token(yytext); return yy::parser::token::yytokentype::OD;}
return {update_token(yytext); return yy::parser::token::yytokentype::RETURN;}
float {update_token(yytext); return yy::parser::token::yytokentype::FLOAT_T;}
int {update_token(yytext); return yy::parser::token::yytokentype::INT_T;}
string {update_token(yytext); return yy::parser::token::yytokentype::STRING_T;}
bool {update_token(yytext); return yy::parser::token::yytokentype::BOOL_T;}
array {update_token(yytext); return yy::parser::token::yytokentype::ARRAY;}
of {update_token(yytext); return yy::parser::token::yytokentype::OF;}
true {update_token(yytext); return yy::parser::token::yytokentype::TRUE;}
false {update_token(yytext); return yy::parser::token::yytokentype::FALSE;}
\( {update_token(yytext); return '(';}
\) {update_token(yytext); return ')';}

{STRING_LITERAL} {update_token("STRING_LITERAL", yytext);return yy::parser::token::yytokentype::STRING_LITERAL;}
({ALPHA}({ALPHA}|{DIGIT}|\_)*({ALPHA}|{DIGIT}))|{ALPHA} {update_token("NAME", yytext); return yy::parser::token::yytokentype::NAME;}
{DIGIT}+ {update_token("INT_LITERAL", yytext);return yy::parser::token::yytokentype::INT_LITERAL;}
{DIGIT}+\.{DIGIT}+ {update_token("FLOAT_LITERAL", yytext);return yy::parser::token::yytokentype::FLOAT_LITERAL;}
\n {update_token("\n");}

\&\& {update_token(yytext);return yy::parser::token::yytokentype::AND;}
\|\| {update_token(yytext);return yy::parser::token::yytokentype::OR;}

"+" {update_token(yytext);return yy::parser::token::yytokentype::PLUS;}
"-" {update_token(yytext);return yy::parser::token::yytokentype::MINUS;}
"*" {update_token(yytext);return yy::parser::token::yytokentype::MULT;}
"/" {update_token(yytext);return yy::parser::token::yytokentype::DIV;}
":=" {update_token(yytext);return yy::parser::token::yytokentype::ASSIGN;}
";" {update_token(yytext);return ';';}

"[" {update_token(yytext); return '[';}
"]" {update_token(yytext); return ']';}
"{" {update_token(yytext); return '{';}
"}" {update_token(yytext); return '}';}
":" {update_token(yytext); return ':';}
"." {update_token(yytext); return '.';}
"," {update_token(yytext); return ',';}
"^" {update_token(yytext); return '^';}
"<>" {update_token(yytext);return yy::parser::token::yytokentype::NE;}

"=" {update_token(yytext);return yy::parser::token::yytokentype::EQ;}
"<" {update_token(yytext);return yy::parser::token::yytokentype::LT;}
">" {update_token(yytext);return yy::parser::token::yytokentype::GT;}
"<=" {update_token(yytext);return yy::parser::token::yytokentype::LE;}
">=" {update_token(yytext);return yy::parser::token::yytokentype::GE;}

<<EOF>> {update_token("$"); return 0;}
" " {update_token("ignore");}

. {printf("\nERRO %d %d\n", nLinhas, nColunas); return 0;}

%%
