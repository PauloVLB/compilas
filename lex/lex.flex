%option noyywrap

%{
#include "../symbol_table.hpp"
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
program {update_token(yytext);}
begin {update_token(yytext);}
end {update_token(yytext);}
var {update_token(yytext);}
procedure {update_token(yytext);}
in {update_token(yytext);}
struct {update_token(yytext);}
not {update_token(yytext);}
new {update_token(yytext);}
ref {update_token(yytext);}
deref {update_token(yytext);}
if {update_token(yytext);}
then {update_token(yytext);}
else {update_token(yytext);}
fi {update_token(yytext);}
while {update_token(yytext);}
do {update_token(yytext);}
od {update_token(yytext);}
return {update_token(yytext);}
float {update_token(yytext);}
int {update_token(yytext);}
string {update_token(yytext);}
bool {update_token(yytext);}
array {update_token(yytext);}
of {update_token(yytext);}
true {update_token(yytext);}
false {update_token(yytext);}
print {update_token(yytext);}
\( {update_token(yytext);}
\) {update_token(yytext);}

{STRING_LITERAL} {update_token("STRING_LITERAL", yytext);}
({ALPHA}({ALPHA}|{DIGIT}|\_)*({ALPHA}|{DIGIT}))|{ALPHA} {update_token("NAME", yytext); symbol_table::insert(yytext, yytext);}
{DIGIT}+ {update_token("INT_LITERAL", yytext);}
{DIGIT}+\.{DIGIT}+ {update_token("FLOAT_LITERAL", yytext);}
\n {update_token("\n");}

\&\& {update_token(yytext);}
\|\| {update_token(yytext);}

"+" {update_token(yytext);}
"-" {update_token(yytext);}
"*" {update_token(yytext);}
"/" {update_token(yytext);}
":=" {update_token(yytext);}
";" {update_token(yytext);}

"^" {update_token(yytext);}
"." {update_token(yytext);}
"," {update_token(yytext);}
"[" {update_token(yytext);}
"]" {update_token(yytext);}
"{" {update_token(yytext);}
"}" {update_token(yytext);}
":" {update_token(yytext);}
"<>" {update_token(yytext);}

"=" {update_token(yytext);}
"<" {update_token(yytext);}
">" {update_token(yytext);}
"<=" {update_token(yytext);}
">=" {update_token(yytext);}

" " {update_token("ignore");}

. {printf("\nERRO %d %d\n", nLinhas, nColunas); return 0;}

%%


int main() {
    yylex();
    
}