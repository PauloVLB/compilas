%{
int col = 0;

void printnum() {

    //printf("!!!%d", col);
    if(col == 0) {
        printf("%s", yytext);
        return;
    }

    char c = yytext[0];
    int num = c - '0';
    //printf ("BBB %d   <---------", num);
    if(num == 1) {
        printf("I");
    }
    else if(num == 2) {
        printf("II");
    }
    else if(num == 3) {
        printf("III");
    }
    else if(num == 4) {
        printf("IV");
    }
    else if(num == 5) {
        printf("V");
    }
    else if(num == 6) {
        printf("VI");
    }
    else if(num == 7) {
        printf("VII");
    }
    else if(num == 8) {
        printf("VIII");
    }
    else if(num == 9) {
        printf("IX");
    }
}


%}

ALG [1-9]

%% 

\n {col = 0; printf("\n");}
10 {
    if(col != 0) {
        printf("X");
    }
    else {
        printf("%s", yytext);
    }
}
{ALG} {printnum(); col++;}
. {
    printf("%s", yytext);
    col++;
}

%% 
main ()
{
    yylex();
}