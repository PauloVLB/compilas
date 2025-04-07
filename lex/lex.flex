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

    if(token_name == "\n") {
        nLinhas++;
        nColunas = 0;
    }
    printf("%s %s ", token_name.c_str(), yytxt.c_str());
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
program {update_token("PROGRAM");}
begin {update_token("BEGIN");}
end {update_token("END");}
var {update_token("VAR");}
procedure {update_token("PROCEDURE");}
in {update_token("IN");}
struct {update_token("STRUCT");}
not {update_token("NOT");}
new {update_token("NEW");}
ref {update_token("REF");}
deref {update_token("DEREF");}
if {update_token("IF");}
then {update_token("THEN");}
else {update_token("ELSE");}
fi {update_token("FI");}
while {update_token("WHILE");}
do {update_token("DO");}
od {update_token("OD");}
return {update_token("RETURN");}
float {update_token("FLOAT");}
int {update_token("INT");}
string {update_token("STRING");}
bool {update_token("BOOL");}
array {update_token("ARRAY");}
of {update_token("OF");}
true {update_token("TRUE");}
false {update_token("FALSE");}
print {update_token("PRINT");}
\( {update_token("OPEN_PAR");}
\) {update_token("CLOSE_PAR");}

{STRING_LITERAL} {update_token("STRING_LITERAL ", yytext);}
({ALPHA}({ALPHA}|{DIGIT}|\_)*({ALPHA}|{DIGIT}))|{ALPHA} {update_token("IDENTIFICADOR ", yytext); symbol_table::insert(yytext, yytext);}
{DIGIT}+ {update_token("LITERAL_INT ", yytext);}
{DIGIT}+\.{DIGIT}+ {update_token("LITERAL_FLOAT ", yytext);}
\n {update_token("\n");}

\&\& {update_token("AND");}
\|\| {update_token("OR");}

"+" {update_token("PLUS");}
"-" {update_token("MINUS");}
"*" {update_token("MULT");}
"/" {update_token("DIV");}
":=" {update_token("ASSIGN");}
";" {update_token("SEMICOLON");}

"^" {update_token("POWER");}
"." {update_token("DOT");}
"," {update_token("COMMA");}
"[" {update_token("OPEN_BRACKET");}
"]" {update_token("CLOSE_BRACKET");}
"{" {update_token("OPEN_BRACE");}
"}" {update_token("CLOSE_BRACE");}
":" {update_token("COLON");}
"<>" {update_token("NOT_EQUAL");}

"=" {update_token("EQUALS");}
"<" {update_token("LESS_THAN");}
">" {update_token("GREATER_THAN");}
"<=" {update_token("LESS_EQUAL");}
">=" {update_token("GREATER_EQUAL");}

" " {update_token("ignore");}

. {printf("\nERRO %d %d\n", nLinhas, nColunas); return 0;}

%%


int main() {
    yylex();
    
}