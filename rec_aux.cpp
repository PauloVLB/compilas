#include <unordered_map>
#include <stack>
#include <set>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>

const std::vector<std::string> non_terminals_list = {
    "PROGRAM",
    "DECL_SECTION",
    "DECL_SECTION",
    "DECL_LIST",
    "DECL_LIST",
    "DECL",
    "DECL",
    "DECL",
    "VAR_DECL",
    "VAR_DECL_TYPE",
    "VAR_DECL_TYPE",
    "VAR_INIT",
    "VAR_INIT",
    "PROC_DECL",
    "PARAMFIELD_LIST",
    "PARAMFIELD_LIST",
    "PARAMFIELD_LIST_TAIL",
    "PARAMFIELD_LIST_TAIL",
    "TYPE_ANNOTATION",
    "TYPE_ANNOTATION",
    "BLOCK",
    "Z",
    "Z",
    "Z",
    "REC_DECL",
    "PARAMFIELD_DECLS",
    "PARAMFIELD_DECLS",
    "STMT_LIST",
    "STMT_LIST",
    "STMT_LIST_TAIL",
    "STMT_LIST_TAIL",
    "EXP",
    "OR_EXP",
    "OR_EXP_PRIME",
    "OR_EXP_PRIME",
    "AND_EXP",
    "AND_EXP_PRIME",
    "AND_EXP_PRIME",
    "NOT_EXP",
    "NOT_EXP",
    "REL_EXP",
    "REL_EXP_PRIME",
    "REL_EXP_PRIME",
    "ADD_EXP",
    "ADD_EXP_PRIME",
    "ADD_EXP_PRIME",
    "ADD_EXP_PRIME",
    "MUL_EXP",
    "MUL_EXP_PRIME",
    "MUL_EXP_PRIME",
    "MUL_EXP_PRIME",
    "EXP_EXP",
    "EXP_EXP_PRIME",
    "EXP_EXP_PRIME",
    "PRIMARY",
    "PRIMARY",
    "PRIMARY",
    "PRIMARY",
    "PRIMARY",
    "PRIMARY",
    "REF_VAR",
    "DEREF_VAR",
    "C",
    "C",
    "PARAMFIELD_DECL",
    "NAME_TAIL",
    "NAME_TAIL",
    "NAME_TAIL",
    "NAME_TAIL",
    "VAR",
    "CALL_STMT",
    "VAR_ACCESS",
    "VAR_ACCESS",
    "REL_OP",
    "REL_OP",
    "REL_OP",
    "REL_OP",
    "REL_OP",
    "REL_OP",
    "LITERAL",
    "LITERAL",
    "LITERAL",
    "LITERAL",
    "LITERAL",
    "BOOL_LITERAL",
    "BOOL_LITERAL",
    "STMT",
    "STMT",
    "STMT",
    "STMT",
    "STMT",
    "STMT_NAME_BEGIN",
    "X",
    "X",
    "X",
    "X",
    "XX",
    "XX",
    "ASSIGN_STMT",
    "IF_STMT",
    "D",
    "D",
    "WHILE_STMT",
    "RETURN_STMT",
    "E",
    "E_TAIL",
    "E_TAIL",
    "TYPE",
    "TYPE",
    "TYPE",
    "TYPE",
    "TYPE",
    "TYPE",
    "TYPE",
    "F",
    "F",
    "S"

};

void init_non_terminals(std::set<std::string> & s) {

    for(std::string non_terminal : non_terminals_list) {
        s.insert(non_terminal);
    }
}

void init_transition_table(std::map<std::pair<std::string, std::string>, std::vector<std::string>> & t) {
    
    t[{"S", "program"}] = {"PROGRAM", "$"};
    t[{"PROGRAM", "program"}] = {"program", "NAME", "begin", "DECL_SECTION", "end"};
    t[{"DECL_SECTION", "end"}] = {};
    t[{"DECL_SECTION", "var"}] = {"DECL", "DECL_LIST"};
    t[{"DECL_SECTION", "procedure"}] = {"DECL", "DECL_LIST"};
    t[{"DECL_SECTION", "struct"}] = {"DECL", "DECL_LIST"};
    t[{"DECL_LIST", "end"}] = {};
    t[{"DECL_LIST", ";"}] = {";", "DECL", "DECL_LIST"};
    t[{"DECL_LIST", "in"}] = {};
    t[{"DECL", "var"}] = {"VAR_DECL"};
    t[{"DECL", "procedure"}] = {"PROC_DECL"};
    t[{"DECL", "struct"}] = {"REC_DECL"};
    t[{"VAR_DECL", "var"}] = {"var", "NAME", "VAR_DECL_TYPE"};
    t[{"VAR_DECL_TYPE", ":"}] = {":", "TYPE", "VAR_INIT"};
    t[{"VAR_DECL_TYPE", ":="}] = {":=", "EXP"};
    t[{"VAR_INIT", "end"}] = {};
    t[{"VAR_INIT", ";"}] = {};
    t[{"VAR_INIT", ":="}] = {":=", "EXP"};
    t[{"VAR_INIT", "in"}] = {};
    t[{"PROC_DECL", "procedure"}] = {"procedure", "NAME", "(", "PARAMFIELD_LIST", ")", "TYPE_ANNOTATION", "BLOCK"};
    t[{"PARAMFIELD_LIST", "NAME"}] = {"PARAMFIELD_DECL", "PARAMFIELD_LIST_TAIL"};
    t[{"PARAMFIELD_LIST", ")"}] = {};
    t[{"PARAMFIELD_LIST_TAIL", ")"}] = {};
    t[{"PARAMFIELD_LIST_TAIL", ","}] = {",", "PARAMFIELD_DECL", "PARAMFIELD_LIST_TAIL"};
    t[{"TYPE_ANNOTATION", "begin"}] = {};
    t[{"TYPE_ANNOTATION", ":"}] = {":", "TYPE"};
    t[{"BLOCK", "begin"}] = {"begin", "Z", "end"};
    t[{"Z", "NAME"}] = {"STMT_LIST"};
    t[{"Z", "end"}] = {"STMT_LIST"};
    t[{"Z", "var"}] = {"DECL", "DECL_LIST", "in", "STMT_LIST"};
    t[{"Z", "procedure"}] = {"DECL", "DECL_LIST", "in", "STMT_LIST"};
    t[{"Z", "in"}] = {"in", "STMT_LIST"};
    t[{"Z", "struct"}] = {"DECL", "DECL_LIST", "in", "STMT_LIST"};
    t[{"Z", "deref"}] = {"STMT_LIST"};
    t[{"Z", "if"}] = {"STMT_LIST"};
    t[{"Z", "while"}] = {"STMT_LIST"};
    t[{"Z", "return"}] = {"STMT_LIST"};
    t[{"REC_DECL", "struct"}] = {"struct", "NAME", "{", "PARAMFIELD_DECLS", "}"};
    t[{"PARAMFIELD_DECLS", "NAME"}] = {"PARAMFIELD_DECL", ";", "PARAMFIELD_DECLS"};
    t[{"PARAMFIELD_DECLS", "}"}] = {};
    t[{"STMT_LIST", "NAME"}] = {"STMT", "STMT_LIST_TAIL"};
    t[{"STMT_LIST", "end"}] = {};
    t[{"STMT_LIST", "deref"}] = {"STMT", "STMT_LIST_TAIL"};
    t[{"STMT_LIST", "if"}] = {"STMT", "STMT_LIST_TAIL"};
    t[{"STMT_LIST", "fi"}] = {};
    t[{"STMT_LIST", "else"}] = {};
    t[{"STMT_LIST", "while"}] = {"STMT", "STMT_LIST_TAIL"};
    t[{"STMT_LIST", "od"}] = {};
    t[{"STMT_LIST", "return"}] = {"STMT", "STMT_LIST_TAIL"};
    t[{"STMT_LIST_TAIL", "end"}] = {};
    t[{"STMT_LIST_TAIL", ";"}] = {";", "STMT", "STMT_LIST_TAIL"};
    t[{"STMT_LIST_TAIL", "fi"}] = {};
    t[{"STMT_LIST_TAIL", "else"}] = {};
    t[{"STMT_LIST_TAIL", "od"}] = {};
    t[{"EXP", "NAME"}] = {"OR_EXP"};
    t[{"EXP", "("}] = {"OR_EXP"};
    t[{"EXP", "not"}] = {"OR_EXP"};
    t[{"EXP", "new"}] = {"OR_EXP"};
    t[{"EXP", "ref"}] = {"OR_EXP"};
    t[{"EXP", "deref"}] = {"OR_EXP"};
    t[{"EXP", "FLOAT_LITERAL"}] = {"OR_EXP"};
    t[{"EXP", "INT_LITERAL"}] = {"OR_EXP"};
    t[{"EXP", "STRING_LITERAL"}] = {"OR_EXP"};
    t[{"EXP", "null"}] = {"OR_EXP"};
    t[{"EXP", "true"}] = {"OR_EXP"};
    t[{"EXP", "false"}] = {"OR_EXP"};
    t[{"OR_EXP", "NAME"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "("}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "not"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "new"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "ref"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "deref"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "FLOAT_LITERAL"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "INT_LITERAL"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "STRING_LITERAL"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "null"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "true"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP", "false"}] = {"AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP_PRIME", "end"}] = {};
    t[{"OR_EXP_PRIME", ";"}] = {};
    t[{"OR_EXP_PRIME", ")"}] = {};
    t[{"OR_EXP_PRIME", ","}] = {};
    t[{"OR_EXP_PRIME", "in"}] = {};
    t[{"OR_EXP_PRIME", "||"}] = {"||", "AND_EXP", "OR_EXP_PRIME"};
    t[{"OR_EXP_PRIME", "]"}] = {};
    t[{"OR_EXP_PRIME", "then"}] = {};
    t[{"OR_EXP_PRIME", "fi"}] = {};
    t[{"OR_EXP_PRIME", "else"}] = {};
    t[{"OR_EXP_PRIME", "do"}] = {};
    t[{"OR_EXP_PRIME", "od"}] = {};
    t[{"AND_EXP", "NAME"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "("}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "not"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "new"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "ref"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "deref"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "FLOAT_LITERAL"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "INT_LITERAL"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "STRING_LITERAL"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "null"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "true"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP", "false"}] = {"NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP_PRIME", "end"}] = {};
    t[{"AND_EXP_PRIME", ";"}] = {};
    t[{"AND_EXP_PRIME", ")"}] = {};
    t[{"AND_EXP_PRIME", ","}] = {};
    t[{"AND_EXP_PRIME", "in"}] = {};
    t[{"AND_EXP_PRIME", "||"}] = {};
    t[{"AND_EXP_PRIME", "&&"}] = {"&&", "NOT_EXP", "AND_EXP_PRIME"};
    t[{"AND_EXP_PRIME", "]"}] = {};
    t[{"AND_EXP_PRIME", "then"}] = {};
    t[{"AND_EXP_PRIME", "fi"}] = {};
    t[{"AND_EXP_PRIME", "else"}] = {};
    t[{"AND_EXP_PRIME", "do"}] = {};
    t[{"AND_EXP_PRIME", "od"}] = {};
    t[{"NOT_EXP", "NAME"}] = {"REL_EXP"};
    t[{"NOT_EXP", "("}] = {"REL_EXP"};
    t[{"NOT_EXP", "not"}] = {"not", "NOT_EXP"};
    t[{"NOT_EXP", "new"}] = {"REL_EXP"};
    t[{"NOT_EXP", "ref"}] = {"REL_EXP"};
    t[{"NOT_EXP", "deref"}] = {"REL_EXP"};
    t[{"NOT_EXP", "FLOAT_LITERAL"}] = {"REL_EXP"};
    t[{"NOT_EXP", "INT_LITERAL"}] = {"REL_EXP"};
    t[{"NOT_EXP", "STRING_LITERAL"}] = {"REL_EXP"};
    t[{"NOT_EXP", "null"}] = {"REL_EXP"};
    t[{"NOT_EXP", "true"}] = {"REL_EXP"};
    t[{"NOT_EXP", "false"}] = {"REL_EXP"};
    t[{"REL_EXP", "NAME"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "("}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "new"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "ref"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "deref"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "FLOAT_LITERAL"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "INT_LITERAL"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "STRING_LITERAL"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "null"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "true"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP", "false"}] = {"ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP_PRIME", "end"}] = {};
    t[{"REL_EXP_PRIME", ";"}] = {};
    t[{"REL_EXP_PRIME", ")"}] = {};
    t[{"REL_EXP_PRIME", ","}] = {};
    t[{"REL_EXP_PRIME", "in"}] = {};
    t[{"REL_EXP_PRIME", "||"}] = {};
    t[{"REL_EXP_PRIME", "&&"}] = {};
    t[{"REL_EXP_PRIME", "]"}] = {};
    t[{"REL_EXP_PRIME", "<"}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP_PRIME", "<="}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP_PRIME", ">"}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP_PRIME", ">="}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP_PRIME", "="}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP_PRIME", "<>"}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
    t[{"REL_EXP_PRIME", "then"}] = {};
    t[{"REL_EXP_PRIME", "fi"}] = {};
    t[{"REL_EXP_PRIME", "else"}] = {};
    t[{"REL_EXP_PRIME", "do"}] = {};
    t[{"REL_EXP_PRIME", "od"}] = {};
    t[{"ADD_EXP", "NAME"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "("}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "new"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "ref"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "deref"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "FLOAT_LITERAL"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "INT_LITERAL"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "STRING_LITERAL"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "null"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "true"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP", "false"}] = {"MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP_PRIME", "end"}] = {};
    t[{"ADD_EXP_PRIME", ";"}] = {};
    t[{"ADD_EXP_PRIME", ")"}] = {};
    t[{"ADD_EXP_PRIME", ","}] = {};
    t[{"ADD_EXP_PRIME", "in"}] = {};
    t[{"ADD_EXP_PRIME", "||"}] = {};
    t[{"ADD_EXP_PRIME", "&&"}] = {};
    t[{"ADD_EXP_PRIME", "+"}] = {"+", "MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP_PRIME", "-"}] = {"-", "MUL_EXP", "ADD_EXP_PRIME"};
    t[{"ADD_EXP_PRIME", "]"}] = {};
    t[{"ADD_EXP_PRIME", "<"}] = {};
    t[{"ADD_EXP_PRIME", "<="}] = {};
    t[{"ADD_EXP_PRIME", ">"}] = {};
    t[{"ADD_EXP_PRIME", ">="}] = {};
    t[{"ADD_EXP_PRIME", "="}] = {};
    t[{"ADD_EXP_PRIME", "<>"}] = {};
    t[{"ADD_EXP_PRIME", "then"}] = {};
    t[{"ADD_EXP_PRIME", "fi"}] = {};
    t[{"ADD_EXP_PRIME", "else"}] = {};
    t[{"ADD_EXP_PRIME", "do"}] = {};
    t[{"ADD_EXP_PRIME", "od"}] = {};
    t[{"MUL_EXP", "NAME"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "("}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "new"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "ref"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "deref"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "FLOAT_LITERAL"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "INT_LITERAL"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "STRING_LITERAL"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "null"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "true"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP", "false"}] = {"EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP_PRIME", "end"}] = {};
    t[{"MUL_EXP_PRIME", ";"}] = {};
    t[{"MUL_EXP_PRIME", ")"}] = {};
    t[{"MUL_EXP_PRIME", ","}] = {};
    t[{"MUL_EXP_PRIME", "in"}] = {};
    t[{"MUL_EXP_PRIME", "||"}] = {};
    t[{"MUL_EXP_PRIME", "&&"}] = {};
    t[{"MUL_EXP_PRIME", "+"}] = {};
    t[{"MUL_EXP_PRIME", "-"}] = {};
    t[{"MUL_EXP_PRIME", "*"}] = {"*", "EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP_PRIME", "/"}] = {"/", "EXP_EXP", "MUL_EXP_PRIME"};
    t[{"MUL_EXP_PRIME", "]"}] = {};
    t[{"MUL_EXP_PRIME", "<"}] = {};
    t[{"MUL_EXP_PRIME", "<="}] = {};
    t[{"MUL_EXP_PRIME", ">"}] = {};
    t[{"MUL_EXP_PRIME", ">="}] = {};
    t[{"MUL_EXP_PRIME", "="}] = {};
    t[{"MUL_EXP_PRIME", "<>"}] = {};
    t[{"MUL_EXP_PRIME", "then"}] = {};
    t[{"MUL_EXP_PRIME", "fi"}] = {};
    t[{"MUL_EXP_PRIME", "else"}] = {};
    t[{"MUL_EXP_PRIME", "do"}] = {};
    t[{"MUL_EXP_PRIME", "od"}] = {};
    t[{"EXP_EXP", "NAME"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "("}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "new"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "ref"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "deref"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "FLOAT_LITERAL"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "INT_LITERAL"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "STRING_LITERAL"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "null"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "true"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP", "false"}] = {"PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP_PRIME", "end"}] = {};
    t[{"EXP_EXP_PRIME", ";"}] = {};
    t[{"EXP_EXP_PRIME", ")"}] = {};
    t[{"EXP_EXP_PRIME", ","}] = {};
    t[{"EXP_EXP_PRIME", "in"}] = {};
    t[{"EXP_EXP_PRIME", "||"}] = {};
    t[{"EXP_EXP_PRIME", "&&"}] = {};
    t[{"EXP_EXP_PRIME", "+"}] = {};
    t[{"EXP_EXP_PRIME", "-"}] = {};
    t[{"EXP_EXP_PRIME", "*"}] = {};
    t[{"EXP_EXP_PRIME", "/"}] = {};
    t[{"EXP_EXP_PRIME", "^"}] = {"^", "PRIMARY", "EXP_EXP_PRIME"};
    t[{"EXP_EXP_PRIME", "]"}] = {};
    t[{"EXP_EXP_PRIME", "<"}] = {};
    t[{"EXP_EXP_PRIME", "<="}] = {};
    t[{"EXP_EXP_PRIME", ">"}] = {};
    t[{"EXP_EXP_PRIME", ">="}] = {};
    t[{"EXP_EXP_PRIME", "="}] = {};
    t[{"EXP_EXP_PRIME", "<>"}] = {};
    t[{"EXP_EXP_PRIME", "then"}] = {};
    t[{"EXP_EXP_PRIME", "fi"}] = {};
    t[{"EXP_EXP_PRIME", "else"}] = {};
    t[{"EXP_EXP_PRIME", "do"}] = {};
    t[{"EXP_EXP_PRIME", "od"}] = {};
    t[{"PRIMARY", "NAME"}] = {"VAR"};
    t[{"PRIMARY", "("}] = {"(", "EXP", ")"};
    t[{"PRIMARY", "new"}] = {"new", "NAME"};
    t[{"PRIMARY", "ref"}] = {"REF_VAR"};
    t[{"PRIMARY", "deref"}] = {"DEREF_VAR"};
    t[{"PRIMARY", "FLOAT_LITERAL"}] = {"LITERAL"};
    t[{"PRIMARY", "INT_LITERAL"}] = {"LITERAL"};
    t[{"PRIMARY", "STRING_LITERAL"}] = {"LITERAL"};
    t[{"PRIMARY", "null"}] = {"LITERAL"};
    t[{"PRIMARY", "true"}] = {"LITERAL"};
    t[{"PRIMARY", "false"}] = {"LITERAL"};
    t[{"REF_VAR", "ref"}] = {"ref", "(", "VAR", ")"};
    t[{"DEREF_VAR", "deref"}] = {"deref", "(", "C", ")"};
    t[{"C", "NAME"}] = {"VAR"};
    t[{"C", "deref"}] = {"DEREF_VAR"};
    t[{"PARAMFIELD_DECL", "NAME"}] = {"NAME", ":", "TYPE"};
    t[{"NAME_TAIL", "end"}] = {};
    t[{"NAME_TAIL", ";"}] = {};
    t[{"NAME_TAIL", ":="}] = {};
    t[{"NAME_TAIL", "("}] = {"(", "E", ")", "NAME_TAIL"};
    t[{"NAME_TAIL", ")"}] = {};
    t[{"NAME_TAIL", ","}] = {};
    t[{"NAME_TAIL", "in"}] = {};
    t[{"NAME_TAIL", "||"}] = {};
    t[{"NAME_TAIL", "&&"}] = {};
    t[{"NAME_TAIL", "+"}] = {};
    t[{"NAME_TAIL", "-"}] = {};
    t[{"NAME_TAIL", "*"}] = {};
    t[{"NAME_TAIL", "/"}] = {};
    t[{"NAME_TAIL", "^"}] = {};
    t[{"NAME_TAIL", "."}] = {".", "NAME", "NAME_TAIL"};
    t[{"NAME_TAIL", "["}] = {"[", "EXP", "]", "NAME_TAIL"};
    t[{"NAME_TAIL", "]"}] = {};
    t[{"NAME_TAIL", "<"}] = {};
    t[{"NAME_TAIL", "<="}] = {};
    t[{"NAME_TAIL", ">"}] = {};
    t[{"NAME_TAIL", ">="}] = {};
    t[{"NAME_TAIL", "="}] = {};
    t[{"NAME_TAIL", "<>"}] = {};
    t[{"NAME_TAIL", "then"}] = {};
    t[{"NAME_TAIL", "fi"}] = {};
    t[{"NAME_TAIL", "else"}] = {};
    t[{"NAME_TAIL", "do"}] = {};
    t[{"NAME_TAIL", "od"}] = {};
    t[{"VAR", "NAME"}] = {"NAME", "NAME_TAIL"};
    t[{"CALL_STMT", "NAME"}] = {"NAME", "(", "E", ")"};
    t[{"VAR_ACCESS", "["}] = {"[", "EXP", "]", "VAR_ACCESS"};
    t[{"REL_OP", "<"}] = {"<"};
    t[{"REL_OP", "<="}] = {"<="};
    t[{"REL_OP", ">"}] = {">"};
    t[{"REL_OP", ">="}] = {">="};
    t[{"REL_OP", "="}] = {"="};
    t[{"REL_OP", "<>"}] = {"<>"};
    t[{"LITERAL", "FLOAT_LITERAL"}] = {"FLOAT_LITERAL"};
    t[{"LITERAL", "INT_LITERAL"}] = {"INT_LITERAL"};
    t[{"LITERAL", "STRING_LITERAL"}] = {"STRING_LITERAL"};
    t[{"LITERAL", "null"}] = {"null"};
    t[{"LITERAL", "true"}] = {"BOOL_LITERAL"};
    t[{"LITERAL", "false"}] = {"BOOL_LITERAL"};
    t[{"BOOL_LITERAL", "true"}] = {"true"};
    t[{"BOOL_LITERAL", "false"}] = {"false"};
    t[{"STMT", "NAME"}] = {"STMT_NAME_BEGIN"};
    t[{"STMT", "deref"}] = {"DEREF_VAR", ":=", "EXP"};
    t[{"STMT", "if"}] = {"IF_STMT"};
    t[{"STMT", "while"}] = {"WHILE_STMT"};
    t[{"STMT", "return"}] = {"RETURN_STMT"};
    t[{"STMT_NAME_BEGIN", "NAME"}] = {"NAME", "X"};
    t[{"X", ":="}] = {":=", "EXP"};
    t[{"X", "("}] = {"(", "E", ")", "XX"};
    t[{"X", "."}] = {".", "NAME", "NAME_TAIL", ":=", "EXP"};
    t[{"X", "["}] = {"[", "EXP", "]", "NAME_TAIL", ":=", "EXP"};
    t[{"XX", "end"}] = {};
    t[{"XX", ";"}] = {};
    t[{"XX", ":="}] = {"NAME_TAIL", ":=", "EXP"};
    t[{"XX", "("}] = {"NAME_TAIL", ":=", "EXP"};
    t[{"XX", "."}] = {"NAME_TAIL", ":=", "EXP"};
    t[{"XX", "["}] = {"NAME_TAIL", ":=", "EXP"};
    t[{"XX", "fi"}] = {};
    t[{"XX", "else"}] = {};
    t[{"XX", "od"}] = {};
    t[{"ASSIGN_STMT", "NAME"}] = {"VAR", ":=", "EXP"};
    t[{"IF_STMT", "if"}] = {"if", "EXP", "then", "STMT_LIST", "D", "fi"};
    t[{"D", "fi"}] = {};
    t[{"D", "else"}] = {"else", "STMT_LIST"};
    t[{"WHILE_STMT", "while"}] = {"while", "EXP", "do", "STMT_LIST", "od"};
    t[{"RETURN_STMT", "return"}] = {"return", "(", "EXP", ")"};
    t[{"E", "NAME"}] = {"EXP", "E_TAIL"};
    t[{"E", "("}] = {"EXP", "E_TAIL"};
    t[{"E", "not"}] = {"EXP", "E_TAIL"};
    t[{"E", "new"}] = {"EXP", "E_TAIL"};
    t[{"E", "ref"}] = {"EXP", "E_TAIL"};
    t[{"E", "deref"}] = {"EXP", "E_TAIL"};
    t[{"E", "FLOAT_LITERAL"}] = {"EXP", "E_TAIL"};
    t[{"E", "INT_LITERAL"}] = {"EXP", "E_TAIL"};
    t[{"E", "STRING_LITERAL"}] = {"EXP", "E_TAIL"};
    t[{"E", "null"}] = {"EXP", "E_TAIL"};
    t[{"E", "true"}] = {"EXP", "E_TAIL"};
    t[{"E", "false"}] = {"EXP", "E_TAIL"};
    t[{"E_TAIL", ")"}] = {};
    t[{"E_TAIL", ","}] = {",", "EXP", "E_TAIL"};
    t[{"TYPE", "NAME"}] = {"NAME"};
    t[{"TYPE", "ref"}] = {"ref", "(", "TYPE", ")"};
    t[{"TYPE", "float"}] = {"float"};
    t[{"TYPE", "int"}] = {"int"};
    t[{"TYPE", "string"}] = {"string"};
    t[{"TYPE", "bool"}] = {"bool"};
    t[{"TYPE", "array"}] = {"array", "F", "of", "TYPE"};
    t[{"F", "INT_LITERAL"}] = {"INT_LITERAL"};
    t[{"F", "of"}] = {};

}


int main() {
    std::set<std::string> non_terminals;
    init_non_terminals(non_terminals);

    std::map<std::pair<std::string, std::string>, std::vector<std::string>> transition_table;
    init_transition_table(transition_table);

    // map<string, map<string, vector<string>>>;

    std::map<std::string, std::map<std::string, std::vector<std::string>>> mapa2;

    for(auto nt : non_terminals) {

        for(auto [ntt, t] : transition_table) {

            if(nt == ntt.first) {
                mapa2[nt][ntt.second] = t;
            }
        }
    }

    for(auto [nomefuncao, m] : mapa2) {
        std:: cout << "void " << nomefuncao << "() {\n";
        int i = 0;
        for(auto [caset, vt] : m) {
            std::cout << "\t\t" << (i++ == 0 ? "" : "else ") << "if(current == \"" << caset << "\"){\n";
            for(auto t : vt) {
                if(non_terminals.count(t)) {
                    std::cout << "\t\t\t" << t <<  "();\n";
                }
                else {
                    std::cout << "\t\t\t" << "match(\"" << t << "\");\n";
                }
            }
            std::cout << "\t\t}\n";
            
        }
        std::cout << "\t\telse {\n";
        std::cout << "\t\t\tprint_error_message();\n";
        std::cout << "\t\t}\n\n";
        std::cout << "}\n\n";
    }
    return 0;
}