#include <unordered_map>
#include <stack>
#include <set>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>
#include <cstdio>  // Para FILE*
#include "syntax_rec.h"

extern FILE* yyin;
extern int yylex();
extern std::string current_token;
extern int nLinhas, nColunas;
std::string current;
const char* FILE_NAME = "teste3.nao";

std::string get_next_token() {
    yylex(); // avança no input e atualiza current_token
    return current_token;
}

void print_error_message() {
    std::cerr << FILE_NAME << ":" << nLinhas<< ":" << nColunas << ": unexpected token " << current_token << std::endl; 
    exit(1);
}

void match(std::string a) {
    if(a == current) {
        current = get_next_token();
    }
    else {
        print_error_message();
    }
}

void ADD_EXP() {
    if(current == "("){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "FLOAT_LITERAL"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "INT_LITERAL"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "NAME"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "STRING_LITERAL"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "deref"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "false"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "new"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "null"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "ref"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == "true"){
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else {
        print_error_message();
    }

}

void ADD_EXP_PRIME() {
    if(current == "&&"){
    }
    else if(current == ")"){
    }
    else if(current == "+"){
        match("+");
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == ","){
    }
    else if(current == "-"){
        match("-");
        MUL_EXP();
        ADD_EXP_PRIME();
    }
    else if(current == ";"){
    }
    else if(current == "<"){
    }
    else if(current == "<="){
    }
    else if(current == "<>"){
    }
    else if(current == "="){
    }
    else if(current == ">"){
    }
    else if(current == ">="){
    }
    else if(current == "]"){
    }
    else if(current == "do"){
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "in"){
    }
    else if(current == "od"){
    }
    else if(current == "then"){
    }
    else if(current == "||"){
    }
    else {
        print_error_message();
    }

}

void AND_EXP() {
    if(current == "("){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "FLOAT_LITERAL"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "INT_LITERAL"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "NAME"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "STRING_LITERAL"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "deref"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "false"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "new"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "not"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "null"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "ref"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == "true"){
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else {
        print_error_message();
    }

}

void AND_EXP_PRIME() {
    if(current == "&&"){
        match("&&");
        NOT_EXP();
        AND_EXP_PRIME();
    }
    else if(current == ")"){
    }
    else if(current == ","){
    }
    else if(current == ";"){
    }
    else if(current == "]"){
    }
    else if(current == "do"){
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "in"){
    }
    else if(current == "od"){
    }
    else if(current == "then"){
    }
    else if(current == "||"){
    }
    else {
        print_error_message();
    }

}

void ASSIGN_STMT() {
    if(current == "NAME"){
        VAR();
        match(":=");
        EXP();
    }
    else {
        print_error_message();
    }

}

void BLOCK() {
    if(current == "begin"){
        match("begin");
        Z();
        match("end");
    }
    else {
        print_error_message();
    }

}

void BOOL_LITERAL() {
    if(current == "false"){
        match("false");
    }
    else if(current == "true"){
        match("true");
    }
    else {
        print_error_message();
    }

}

void C() {
    if(current == "NAME"){
        VAR();
    }
    else if(current == "deref"){
        DEREF_VAR();
    }
    else {
        print_error_message();
    }

}

void CALL_STMT() {
    if(current == "NAME"){
        match("NAME");
        match("(");
        E();
        match(")");
    }
    else {
        print_error_message();
    }

}

void D() {
    if(current == "else"){
        match("else");
        STMT_LIST();
    }
    else if(current == "fi"){
    }
    else {
        print_error_message();
    }

}

void DECL() {
    if(current == "procedure"){
        PROC_DECL();
    }
    else if(current == "struct"){
        REC_DECL();
    }
    else if(current == "var"){
        VAR_DECL();
    }
    else {
        print_error_message();
    }

}

void DECL_LIST() {
    if(current == ";"){
        match(";");
        DECL();
        DECL_LIST();
    }
    else if(current == "end"){
    }
    else if(current == "in"){
    }
    else {
        print_error_message();
    }

}

void DECL_SECTION() {
    if(current == "end"){
    }
    else if(current == "procedure"){
        DECL();
        DECL_LIST();
    }
    else if(current == "struct"){
        DECL();
        DECL_LIST();
    }
    else if(current == "var"){
        DECL();
        DECL_LIST();
    }
    else {
        print_error_message();
    }

}

void DEREF_VAR() {
    if(current == "deref"){
        match("deref");
        match("(");
        C();
        match(")");
    }
    else {
        print_error_message();
    }

}

void E() {
    if(current == "("){
        EXP();
        E_TAIL();
    }
    else if(current == "FLOAT_LITERAL"){
        EXP();
        E_TAIL();
    }
    else if(current == "INT_LITERAL"){
        EXP();
        E_TAIL();
    }
    else if(current == "NAME"){
        EXP();
        E_TAIL();
    }
    else if(current == "STRING_LITERAL"){
        EXP();
        E_TAIL();
    }
    else if(current == "deref"){
        EXP();
        E_TAIL();
    }
    else if(current == "false"){
        EXP();
        E_TAIL();
    }
    else if(current == "new"){
        EXP();
        E_TAIL();
    }
    else if(current == "not"){
        EXP();
        E_TAIL();
    }
    else if(current == "null"){
        EXP();
        E_TAIL();
    }
    else if(current == "ref"){
        EXP();
        E_TAIL();
    }
    else if(current == "true"){
        EXP();
        E_TAIL();
    }
    else {
        print_error_message();
    }

}

void EXP() {
    if(current == "("){
        OR_EXP();
    }
    else if(current == "FLOAT_LITERAL"){
        OR_EXP();
    }
    else if(current == "INT_LITERAL"){
        OR_EXP();
    }
    else if(current == "NAME"){
        OR_EXP();
    }
    else if(current == "STRING_LITERAL"){
        OR_EXP();
    }
    else if(current == "deref"){
        OR_EXP();
    }
    else if(current == "false"){
        OR_EXP();
    }
    else if(current == "new"){
        OR_EXP();
    }
    else if(current == "not"){
        OR_EXP();
    }
    else if(current == "null"){
        OR_EXP();
    }
    else if(current == "ref"){
        OR_EXP();
    }
    else if(current == "true"){
        OR_EXP();
    }
    else {
        print_error_message();
    }

}

void EXP_EXP() {
    if(current == "("){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "FLOAT_LITERAL"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "INT_LITERAL"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "NAME"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "STRING_LITERAL"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "deref"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "false"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "new"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "null"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "ref"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "true"){
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else {
        print_error_message();
    }

}

void EXP_EXP_PRIME() {
    if(current == "&&"){
    }
    else if(current == ")"){
    }
    else if(current == "*"){
    }
    else if(current == "+"){
    }
    else if(current == ","){
    }
    else if(current == "-"){
    }
    else if(current == "/"){
    }
    else if(current == ";"){
    }
    else if(current == "<"){
    }
    else if(current == "<="){
    }
    else if(current == "<>"){
    }
    else if(current == "="){
    }
    else if(current == ">"){
    }
    else if(current == ">="){
    }
    else if(current == "]"){
    }
    else if(current == "^"){
        match("^");
        PRIMARY();
        EXP_EXP_PRIME();
    }
    else if(current == "do"){
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "in"){
    }
    else if(current == "od"){
    }
    else if(current == "then"){
    }
    else if(current == "||"){
    }
    else {
        print_error_message();
    }

}

void E_TAIL() {
    if(current == ")"){
    }
    else if(current == ","){
        match(",");
        EXP();
        E_TAIL();
    }
    else {
        print_error_message();
    }

}

void F() {
    if(current == "INT_LITERAL"){
        match("INT_LITERAL");
    }
    else if(current == "of"){
    }
    else {
        print_error_message();
    }

}

void IF_STMT() {
    if(current == "if"){
        match("if");
        EXP();
        match("then");
        STMT_LIST();
        D();
        match("fi");
    }
    else {
        print_error_message();
    }

}

void LITERAL() {
    if(current == "FLOAT_LITERAL"){
        match("FLOAT_LITERAL");
    }
    else if(current == "INT_LITERAL"){
        match("INT_LITERAL");
    }
    else if(current == "STRING_LITERAL"){
        match("STRING_LITERAL");
    }
    else if(current == "false"){
        BOOL_LITERAL();
    }
    else if(current == "null"){
        match("null");
    }
    else if(current == "true"){
        BOOL_LITERAL();
    }
    else {
        print_error_message();
    }

}

void MUL_EXP() {
    if(current == "("){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "FLOAT_LITERAL"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "INT_LITERAL"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "NAME"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "STRING_LITERAL"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "deref"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "false"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "new"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "null"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "ref"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "true"){
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else {
        print_error_message();
    }

}

void MUL_EXP_PRIME() {
    if(current == "&&"){
    }
    else if(current == ")"){
    }
    else if(current == "*"){
        match("*");
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == "+"){
    }
    else if(current == ","){
    }
    else if(current == "-"){
    }
    else if(current == "/"){
        match("/");
        EXP_EXP();
        MUL_EXP_PRIME();
    }
    else if(current == ";"){
    }
    else if(current == "<"){
    }
    else if(current == "<="){
    }
    else if(current == "<>"){
    }
    else if(current == "="){
    }
    else if(current == ">"){
    }
    else if(current == ">="){
    }
    else if(current == "]"){
    }
    else if(current == "do"){
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "in"){
    }
    else if(current == "od"){
    }
    else if(current == "then"){
    }
    else if(current == "||"){
    }
    else {
        print_error_message();
    }

}

void NAME_TAIL() {
    if(current == "&&"){
    }
    else if(current == "("){
        match("(");
        E();
        match(")");
        NAME_TAIL();
    }
    else if(current == ")"){
    }
    else if(current == "*"){
    }
    else if(current == "+"){
    }
    else if(current == ","){
    }
    else if(current == "-"){
    }
    else if(current == "."){
        match(".");
        match("NAME");
        NAME_TAIL();
    }
    else if(current == "/"){
    }
    else if(current == ":="){
    }
    else if(current == ";"){
    }
    else if(current == "<"){
    }
    else if(current == "<="){
    }
    else if(current == "<>"){
    }
    else if(current == "="){
    }
    else if(current == ">"){
    }
    else if(current == ">="){
    }
    else if(current == "["){
        match("[");
        EXP();
        match("]");
        NAME_TAIL();
    }
    else if(current == "]"){
    }
    else if(current == "^"){
    }
    else if(current == "do"){
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "in"){
    }
    else if(current == "od"){
    }
    else if(current == "then"){
    }
    else if(current == "||"){
    }
    else {
        print_error_message();
    }

}

void NOT_EXP() {
    if(current == "("){
        REL_EXP();
    }
    else if(current == "FLOAT_LITERAL"){
        REL_EXP();
    }
    else if(current == "INT_LITERAL"){
        REL_EXP();
    }
    else if(current == "NAME"){
        REL_EXP();
    }
    else if(current == "STRING_LITERAL"){
        REL_EXP();
    }
    else if(current == "deref"){
        REL_EXP();
    }
    else if(current == "false"){
        REL_EXP();
    }
    else if(current == "new"){
        REL_EXP();
    }
    else if(current == "not"){
        match("not");
        NOT_EXP();
    }
    else if(current == "null"){
        REL_EXP();
    }
    else if(current == "ref"){
        REL_EXP();
    }
    else if(current == "true"){
        REL_EXP();
    }
    else {
        print_error_message();
    }

}

void OR_EXP() {
    if(current == "("){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "FLOAT_LITERAL"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "INT_LITERAL"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "NAME"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "STRING_LITERAL"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "deref"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "false"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "new"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "not"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "null"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "ref"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else if(current == "true"){
        AND_EXP();
        OR_EXP_PRIME();
    }
    else {
        print_error_message();
    }

}

void OR_EXP_PRIME() {
    if(current == ")"){
    }
    else if(current == ","){
    }
    else if(current == ";"){
    }
    else if(current == "]"){
    }
    else if(current == "do"){
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "in"){
    }
    else if(current == "od"){
    }
    else if(current == "then"){
    }
    else if(current == "||"){
        match("||");
        AND_EXP();
        OR_EXP_PRIME();
    }
    else {
        print_error_message();
    }

}

void PARAMFIELD_DECL() {
    if(current == "NAME"){
        match("NAME");
        match(":");
        TYPE();
    }
    else {
        print_error_message();
    }

}

void PARAMFIELD_DECLS() {
    if(current == "NAME"){
        PARAMFIELD_DECL();
        match(";");
        PARAMFIELD_DECLS();
    }
    else if(current == "}"){
    }
    else {
        print_error_message();
    }

}

void PARAMFIELD_LIST() {
    if(current == ")"){
    }
    else if(current == "NAME"){
        PARAMFIELD_DECL();
        PARAMFIELD_LIST_TAIL();
    }
    else {
        print_error_message();
    }

}

void PARAMFIELD_LIST_TAIL() {
    if(current == ")"){
    }
    else if(current == ","){
        match(",");
        PARAMFIELD_DECL();
        PARAMFIELD_LIST_TAIL();
    }
    else {
        print_error_message();
    }

}

void PRIMARY() {
    if(current == "("){
        match("(");
        EXP();
        match(")");
    }
    else if(current == "FLOAT_LITERAL"){
        LITERAL();
    }
    else if(current == "INT_LITERAL"){
        LITERAL();
    }
    else if(current == "NAME"){
        VAR();
    }
    else if(current == "STRING_LITERAL"){
        LITERAL();
    }
    else if(current == "deref"){
        DEREF_VAR();
    }
    else if(current == "false"){
        LITERAL();
    }
    else if(current == "new"){
        match("new");
        match("NAME");
    }
    else if(current == "null"){
        LITERAL();
    }
    else if(current == "ref"){
        REF_VAR();
    }
    else if(current == "true"){
        LITERAL();
    }
    else {
        print_error_message();
    }

}

void PROC_DECL() {
    if(current == "procedure"){
        match("procedure");
        match("NAME");
        match("(");
        PARAMFIELD_LIST();
        match(")");
        TYPE_ANNOTATION();
        BLOCK();
    }
    else {
        print_error_message();
    }

}

void PROGRAM() {
    if(current == "program"){
        match("program");
        match("NAME");
        match("begin");
        DECL_SECTION();
        match("end");
    }
    else {
        print_error_message();
    }

}

void REC_DECL() {
    if(current == "struct"){
        match("struct");
        match("NAME");
        match("{");
        PARAMFIELD_DECLS();
        match("}");
    }
    else {
        print_error_message();
    }

}

void REF_VAR() {
    if(current == "ref"){
        match("ref");
        match("(");
        VAR();
        match(")");
    }
    else {
        print_error_message();
    }

}

void REL_EXP() {
    if(current == "("){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "FLOAT_LITERAL"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "INT_LITERAL"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "NAME"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "STRING_LITERAL"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "deref"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "false"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "new"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "null"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "ref"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "true"){
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else {
        print_error_message();
    }

}

void REL_EXP_PRIME() {
    if(current == "&&"){
    }
    else if(current == ")"){
    }
    else if(current == ","){
    }
    else if(current == ";"){
    }
    else if(current == "<"){
        REL_OP();
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "<="){
        REL_OP();
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "<>"){
        REL_OP();
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "="){
        REL_OP();
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == ">"){
        REL_OP();
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == ">="){
        REL_OP();
        ADD_EXP();
        REL_EXP_PRIME();
    }
    else if(current == "]"){
    }
    else if(current == "do"){
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "in"){
    }
    else if(current == "od"){
    }
    else if(current == "then"){
    }
    else if(current == "||"){
    }
    else {
        print_error_message();
    }

}

void REL_OP() {
    if(current == "<"){
        match("<");
    }
    else if(current == "<="){
        match("<=");
    }
    else if(current == "<>"){
        match("<>");
    }
    else if(current == "="){
        match("=");
    }
    else if(current == ">"){
        match(">");
    }
    else if(current == ">="){
        match(">=");
    }
    else {
        print_error_message();
    }

}

void RETURN_STMT() {
    if(current == "return"){
        match("return");
        match("(");
        EXP();
        match(")");
    }
    else {
        print_error_message();
    }

}

void S() {
    if(current == "program"){
        PROGRAM();
        match("$");
    }
    else {
        print_error_message();
    }

}

void STMT() {
    if(current == "NAME"){
        STMT_NAME_BEGIN();
    }
    else if(current == "deref"){
        DEREF_VAR();
        match(":=");
        EXP();
    }
    else if(current == "if"){
        IF_STMT();
    }
    else if(current == "return"){
        RETURN_STMT();
    }
    else if(current == "while"){
        WHILE_STMT();
    }
    else {
        print_error_message();
    }

}

void STMT_LIST() {
    if(current == "NAME"){
        STMT();
        STMT_LIST_TAIL();
    }
    else if(current == "deref"){
        STMT();
        STMT_LIST_TAIL();
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "if"){
        STMT();
        STMT_LIST_TAIL();
    }
    else if(current == "od"){
    }
    else if(current == "return"){
        STMT();
        STMT_LIST_TAIL();
    }
    else if(current == "while"){
        STMT();
        STMT_LIST_TAIL();
    }
    else {
        print_error_message();
    }

}

void STMT_LIST_TAIL() {
    if(current == ";"){
        match(";");
        STMT();
        STMT_LIST_TAIL();
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "od"){
    }
    else {
        print_error_message();
    }

}

void STMT_NAME_BEGIN() {
    if(current == "NAME"){
        match("NAME");
        X();
    }
    else {
        print_error_message();
    }

}

void TYPE() {
    if(current == "NAME"){
        match("NAME");
    }
    else if(current == "array"){
        match("array");
        F();
        match("of");
        TYPE();
    }
    else if(current == "bool"){
        match("bool");
    }
    else if(current == "float"){
        match("float");
    }
    else if(current == "int"){
        match("int");
    }
    else if(current == "ref"){
        match("ref");
        match("(");
        TYPE();
        match(")");
    }
    else if(current == "string"){
        match("string");
    }
    else {
        print_error_message();
    }

}

void TYPE_ANNOTATION() {
    if(current == ":"){
        match(":");
        TYPE();
    }
    else if(current == "begin"){
    }
    else {
        print_error_message();
    }

}

void VAR() {
    if(current == "NAME"){
        match("NAME");
        NAME_TAIL();
    }
    else {
        print_error_message();
    }

}

void VAR_ACCESS() {
    if(current == "["){
        match("[");
        EXP();
        match("]");
        VAR_ACCESS();
    }
    else {
        print_error_message();
    }

}

void VAR_DECL() {
    if(current == "var"){
        match("var");
        match("NAME");
        VAR_DECL_TYPE();
    }
    else {
        print_error_message();
    }

}

void VAR_DECL_TYPE() {
    if(current == ":"){
        match(":");
        TYPE();
        VAR_INIT();
    }
    else if(current == ":="){
        match(":=");
        EXP();
    }
    else {
        print_error_message();
    }

}

void VAR_INIT() {
    if(current == ":="){
        match(":=");
        EXP();
    }
    else if(current == ";"){
    }
    else if(current == "end"){
    }
    else if(current == "in"){
    }
    else {
        print_error_message();
    }

}

void WHILE_STMT() {
    if(current == "while"){
        match("while");
        EXP();
        match("do");
        STMT_LIST();
        match("od");
    }
    else {
        print_error_message();
    }

}

void X() {
    if(current == "("){
        match("(");
        E();
        match(")");
        XX();
    }
    else if(current == "."){
        match(".");
        match("NAME");
        NAME_TAIL();
        match(":=");
        EXP();
    }
    else if(current == ":="){
        match(":=");
        EXP();
    }
    else if(current == "["){
        match("[");
        EXP();
        match("]");
        NAME_TAIL();
        match(":=");
        EXP();
    }
    else {
        print_error_message();
    }

}

void XX() {
    if(current == "("){
        NAME_TAIL();
        match(":=");
        EXP();
    }
    else if(current == "."){
        NAME_TAIL();
        match(":=");
        EXP();
    }
    else if(current == ":="){
        NAME_TAIL();
        match(":=");
        EXP();
    }
    else if(current == ";"){
    }
    else if(current == "["){
        NAME_TAIL();
        match(":=");
        EXP();
    }
    else if(current == "else"){
    }
    else if(current == "end"){
    }
    else if(current == "fi"){
    }
    else if(current == "od"){
    }
    else {
        print_error_message();
    }

}

void Z() {
    if(current == "NAME"){
        STMT_LIST();
    }
    else if(current == "deref"){
        STMT_LIST();
    }
    else if(current == "end"){
        STMT_LIST();
    }
    else if(current == "if"){
        STMT_LIST();
    }
    else if(current == "in"){
        match("in");
        STMT_LIST();
    }
    else if(current == "procedure"){
        DECL();
        DECL_LIST();
        match("in");
        STMT_LIST();
    }
    else if(current == "return"){
        STMT_LIST();
    }
    else if(current == "struct"){
        DECL();
        DECL_LIST();
        match("in");
        STMT_LIST();
    }
    else if(current == "var"){
        DECL();
        DECL_LIST();
        match("in");
        STMT_LIST();
    }
    else if(current == "while"){
        STMT_LIST();
    }
    else {
        print_error_message();
    }

}



void syntax() {

    current = get_next_token();
    S();
    std::cout << "Análise sintática concluída com sucesso!" << std::endl;

}

int main() {
    yyin = fopen(FILE_NAME, "r");  // Abre o arquivo a ser compilado
    if (!yyin) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Chamada da função principal da análise sintática
    syntax();

    fclose(yyin);  // Fecha o arquivo no final
    return 0;
}