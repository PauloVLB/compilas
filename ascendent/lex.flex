%option noyywrap

%{
#include "../symbol_table.hpp"
#include <string>
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
program {update_token(yytext);return 1;}
begin {update_token(yytext);return 1;}
end {update_token(yytext);return 1;}
var {update_token(yytext);return 1;}
procedure {update_token(yytext);return 1;}
in {update_token(yytext);return 1;}
struct {update_token(yytext);return 1;}
not {update_token(yytext);return 1;}
new {update_token(yytext);return 1;}
ref {update_token(yytext);return 1;}
deref {update_token(yytext);return 1;}
if {update_token(yytext);return 1;}
then {update_token(yytext);return 1;}
else {update_token(yytext);return 1;}
fi {update_token(yytext);return 1;}
while {update_token(yytext);return 1;}
do {update_token(yytext);return 1;}
od {update_token(yytext);return 1;}
return {update_token(yytext);return 1;}
float {update_token(yytext);return 1;}
int {update_token(yytext);return 1;}
string {update_token(yytext);return 1;}
bool {update_token(yytext);return 1;}
array {update_token(yytext);return 1;}
of {update_token(yytext);return 1;}
true {update_token(yytext);return 1;}
false {update_token(yytext);return 1;}
print {update_token(yytext);return 1;}
\( {update_token(yytext);return 1;}
\) {update_token(yytext);return 1;}

{STRING_LITERAL} {update_token("STRING_LITERAL", yytext);return 1;}
({ALPHA}({ALPHA}|{DIGIT}|\_)*({ALPHA}|{DIGIT}))|{ALPHA} {update_token("NAME", yytext); symbol_table::insert(yytext, yytext);return 1;}
{DIGIT}+ {update_token("INT_LITERAL", yytext);return 1;}
{DIGIT}+\.{DIGIT}+ {update_token("FLOAT_LITERAL", yytext);return 1;}
\n {update_token("\n");}

\&\& {update_token(yytext);return AND;}
\|\| {update_token(yytext);return OR;}

"+" {update_token(yytext);return PLUS;}
"-" {update_token(yytext);return MINUS;}
"*" {update_token(yytext);return MULT;}
"/" {update_token(yytext);return DIV;}
":=" {update_token(yytext);return ASSIGN;}
";" {update_token(yytext);return ';';}

"^" {update_token(yytext);return EXP_OP;}
"." {update_token(yytext);return '.';}
"," {update_token(yytext);return ',';}
"[" {update_token(yytext);return '[';}
"]" {update_token(yytext);return ']';}
"{" {update_token(yytext);return '{';}
"}" {update_token(yytext);return '}';}
":" {update_token(yytext);return ':';}

"<>" {update_token(yytext);return NE;}
"=" {update_token(yytext);return EQ;}
"<" {update_token(yytext);return LT;}
">" {update_token(yytext);return GT;}
"<=" {update_token(yytext);return LE;}
">=" {update_token(yytext);return GE;}


<<EOF>> {update_token("$"); return 1;}
" " {update_token("ignore");}

. {printf("\nERRO %d %d\n", nLinhas, nColunas); return 0;}

%%
