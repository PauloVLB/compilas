%{
    int blau = 2;
%}

DIGIT [0-9]
LOW_ALPHA [a-z]
UPPER_ALPHA [A-Z]
ALPHA [a-zA-Z]
NOT_PRINTABLE [\n \r]

INT_LITERAL {DIGIT}+
FLOAT_LITERAL {DIGIT}+.{DIGIT}+
STRING_LITERAL "[^{NOT_PRINTABLE}]"

%%

program {printf("PROGRAM");}
begin {printf("BEGIN");}
end {printf("END");}
var {printf("VAR");}
procedure {printf("PROCEDURE");}
in {printf("IN");}
struct {printf("STRUCT");}
not {printf("NOT");}
new {printf("NEW");}
ref {printf("REF");}
deref {printf("DEREF");}
if {printf("IF");}
then {printf("THEN");}
else {printf("ELSE");}
fi {printf("FI");}
while {printf("WHILE");}
do {printf("DO");}
od {printf("OD");}
return {printf("RETURN");}
float {printf("FLOAT");}
int {printf("INT");}
string {printf("STRING");}
bool {printf("BOOL");}
array {printf("ARRAY");}
of {printf("OF");}
true {printf("TRUE");}
false {printf("FALSE");}
\&\& {printf("AND");}
\|\| {printf("OR");}
[{ALPHA} [{ALPHA} {DIGIT}] [{ALPHA} {DIGIT} _]*] | {ALPHA} {printf("%s", yytext);}
{DIGIT}+ {printf("%s", yytext);}
{DIGIT}+.{DIGIT}+ {printf("%s", yytext);}
"[^{NOT_PRINTABLE}]" {printf("%s", yytext);}
\n {printf("\n");}

%%
int main() {
    yylex();
}