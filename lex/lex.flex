%option noyywrap

%{
#include "../symbol_table.hpp"
std::unordered_map<std::string, std::stack<std::string>> symbol_table::table;
%}

DIGIT [0-9]
LOW_ALPHA [a-z]
UPPER_ALPHA [A-Z]
ALPHA [a-zA-Z]
NOT_PRINTABLE [\n \r]

INT_LITERAL {DIGIT}+
FLOAT_LITERAL {DIGIT}+.{DIGIT}+
STRING_LITERAL \"[^{NOT_PRINTABLE}]*\"

%%

program {printf("PROGRAM ");}
begin {printf("BEGIN ");}
end {printf("END ");}
var {printf("VAR ");}
procedure {printf("PROCEDURE ");}
in {printf("IN ");}
struct {printf("STRUCT ");}
not {printf("NOT ");}
new {printf("NEW ");}
ref {printf("REF ");}
deref {printf("DEREF ");}
if {printf("IF ");}
then {printf("THEN ");}
else {printf("ELSE ");}
fi {printf("FI ");}
while {printf("WHILE ");}
do {printf("DO ");}
od {printf("OD ");}
return {printf("RETURN ");}
float {printf("FLOAT ");}
int {printf("INT ");}
string {printf("STRING ");}
bool {printf("BOOL ");}
array {printf("ARRAY ");}
of {printf("OF ");}
true {printf("TRUE ");}
false {printf("FALSE ");}
print {printf("PRINT ");}
\( {printf("OPEN_PAR ");}
\) {printf("CLOSE_PAR ");}

{STRING_LITERAL} {printf("STRING_LITERAL %s ", yytext);}
({ALPHA}({ALPHA}|{DIGIT}|\_)*({ALPHA}|{DIGIT}))|{ALPHA} {printf("IDENTIFICADOR %s ", yytext); symbol_table::insert(yytext, yytext);}
{DIGIT}+ {printf("LITERAL_INT %s ", yytext);}
{DIGIT}+\.{DIGIT}+ {printf("LITERAL_FLOAT %s ", yytext);}
\n {printf("\n");}

\&\& {printf("AND ");}
\|\| {printf("OR ");}

"+" {printf("PLUS ");}
"-" {printf("MINUS ");}
"*" {printf("MULT ");}
"/" {printf("DIV ");}
":=" {printf("ASSIGN ");}
";" {printf("SEMICOLON ");}

"^" {printf("POWER ");}
"." {printf("DOT ");}
"," {printf("COMMA ");}
"[" {printf("OPEN_BRACKET ");}
"]" {printf("CLOSE_BRACKET ");}
"{" {printf("OPEN_BRACE ");}
"}" {printf("CLOSE_BRACE ");}
":" {printf("COLON ");}
"<>" {printf("NOT_EQUAL ");}

"=" {printf("EQUALS ");}
"<" {printf("LESS_THAN ");}
">" {printf("GREATER_THAN ");}
"<=" {printf("LESS_EQUAL ");}
">=" {printf("GREATER_EQUAL ");}

" "
\/\/[^{NOT_PRINTABLE}]*{NOT_PRINTABLE}

. {printf("UNDEFINED_TOKEN ");}

%%

int main() {
    yylex();
    printf("%s\n", symbol_table::get("macarrao_com_salsicha").c_str());
}