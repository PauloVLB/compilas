std::map<std::pair<std::string, std::string>, std::vector<std::string>> t;
t[{"S", "program"}] = {"PROGRAM", "$"};
t[{"PROGRAM", "program"}] = {"program", "NAME", "begin", "DECL_SECTION", "end"};
t[{"DECL_SECTION", "end"}] = {"ε"};
t[{"DECL_SECTION", "var"}] = {"DECL", "DECL_LIST"};
t[{"DECL_SECTION", "procedure"}] = {"DECL", "DECL_LIST"};
t[{"DECL_SECTION", "struct"}] = {"DECL", "DECL_LIST"};
t[{"DECL_LIST", "end"}] = {"ε"};
t[{"DECL_LIST", ";"}] = {";", "DECL", "DECL_LIST"};
t[{"DECL_LIST", "in"}] = {"ε"};
t[{"DECL", "var"}] = {"VAR_DECL"};
t[{"DECL", "procedure"}] = {"PROC_DECL"};
t[{"DECL", "struct"}] = {"REC_DECL"};
t[{"VAR_DECL", "var"}] = {"var", "NAME", "VAR_DECL_TYPE"};
t[{"VAR_DECL_TYPE", ":"}] = {":", "TYPE", "VAR_INIT"};
t[{"VAR_DECL_TYPE", ":="}] = {":=", "EXP"};
t[{"VAR_INIT", "end"}] = {"ε"};
t[{"VAR_INIT", ";"}] = {"ε"};
t[{"VAR_INIT", ":="}] = {":=", "EXP"};
t[{"VAR_INIT", "in"}] = {"ε"};
t[{"PROC_DECL", "procedure"}] = {"procedure", "NAME", "(", "PARAMFIELD_LIST", ")", "TYPE_ANNOTATION", "BLOCK"};
t[{"PARAMFIELD_LIST", "NAME"}] = {"PARAMFIELD_DECL", "PARAMFIELD_LIST_TAIL"};
t[{"PARAMFIELD_LIST", ")"}] = {"ε"};
t[{"PARAMFIELD_LIST_TAIL", ")"}] = {"ε"};
t[{"PARAMFIELD_LIST_TAIL", ","}] = {",", "PARAMFIELD_DECL", "PARAMFIELD_LIST_TAIL"};
t[{"TYPE_ANNOTATION", "begin"}] = {"ε"};
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
t[{"PARAMFIELD_DECLS", "}"}] = {"ε"};
t[{"STMT_LIST", "NAME"}] = {"STMT", "STMT_LIST_TAIL"};
t[{"STMT_LIST", "end"}] = {"ε"};
t[{"STMT_LIST", "deref"}] = {"STMT", "STMT_LIST_TAIL"};
t[{"STMT_LIST", "if"}] = {"STMT", "STMT_LIST_TAIL"};
t[{"STMT_LIST", "fi"}] = {"ε"};
t[{"STMT_LIST", "else"}] = {"ε"};
t[{"STMT_LIST", "while"}] = {"STMT", "STMT_LIST_TAIL"};
t[{"STMT_LIST", "od"}] = {"ε"};
t[{"STMT_LIST", "return"}] = {"STMT", "STMT_LIST_TAIL"};
t[{"STMT_LIST_TAIL", "end"}] = {"ε"};
t[{"STMT_LIST_TAIL", ";"}] = {";", "STMT", "STMT_LIST_TAIL"};
t[{"STMT_LIST_TAIL", "fi"}] = {"ε"};
t[{"STMT_LIST_TAIL", "else"}] = {"ε"};
t[{"STMT_LIST_TAIL", "od"}] = {"ε"};
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
t[{"OR_EXP_PRIME", "end"}] = {"ε"};
t[{"OR_EXP_PRIME", ";"}] = {"ε"};
t[{"OR_EXP_PRIME", ")"}] = {"ε"};
t[{"OR_EXP_PRIME", ","}] = {"ε"};
t[{"OR_EXP_PRIME", "in"}] = {"ε"};
t[{"OR_EXP_PRIME", "||"}] = {"||", "AND_EXP", "OR_EXP_PRIME"};
t[{"OR_EXP_PRIME", "]"}] = {"ε"};
t[{"OR_EXP_PRIME", "then"}] = {"ε"};
t[{"OR_EXP_PRIME", "fi"}] = {"ε"};
t[{"OR_EXP_PRIME", "else"}] = {"ε"};
t[{"OR_EXP_PRIME", "do"}] = {"ε"};
t[{"OR_EXP_PRIME", "od"}] = {"ε"};
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
t[{"AND_EXP_PRIME", "end"}] = {"ε"};
t[{"AND_EXP_PRIME", ";"}] = {"ε"};
t[{"AND_EXP_PRIME", ")"}] = {"ε"};
t[{"AND_EXP_PRIME", ","}] = {"ε"};
t[{"AND_EXP_PRIME", "in"}] = {"ε"};
t[{"AND_EXP_PRIME", "||"}] = {"ε"};
t[{"AND_EXP_PRIME", "&&"}] = {"&&", "NOT_EXP", "AND_EXP_PRIME"};
t[{"AND_EXP_PRIME", "]"}] = {"ε"};
t[{"AND_EXP_PRIME", "then"}] = {"ε"};
t[{"AND_EXP_PRIME", "fi"}] = {"ε"};
t[{"AND_EXP_PRIME", "else"}] = {"ε"};
t[{"AND_EXP_PRIME", "do"}] = {"ε"};
t[{"AND_EXP_PRIME", "od"}] = {"ε"};
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
t[{"REL_EXP_PRIME", "end"}] = {"ε"};
t[{"REL_EXP_PRIME", ";"}] = {"ε"};
t[{"REL_EXP_PRIME", ")"}] = {"ε"};
t[{"REL_EXP_PRIME", ","}] = {"ε"};
t[{"REL_EXP_PRIME", "in"}] = {"ε"};
t[{"REL_EXP_PRIME", "||"}] = {"ε"};
t[{"REL_EXP_PRIME", "&&"}] = {"ε"};
t[{"REL_EXP_PRIME", "]"}] = {"ε"};
t[{"REL_EXP_PRIME", "<"}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
t[{"REL_EXP_PRIME", "<="}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
t[{"REL_EXP_PRIME", ">"}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
t[{"REL_EXP_PRIME", ">="}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
t[{"REL_EXP_PRIME", "="}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
t[{"REL_EXP_PRIME", "<>"}] = {"REL_OP", "ADD_EXP", "REL_EXP_PRIME"};
t[{"REL_EXP_PRIME", "then"}] = {"ε"};
t[{"REL_EXP_PRIME", "fi"}] = {"ε"};
t[{"REL_EXP_PRIME", "else"}] = {"ε"};
t[{"REL_EXP_PRIME", "do"}] = {"ε"};
t[{"REL_EXP_PRIME", "od"}] = {"ε"};
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
t[{"ADD_EXP_PRIME", "end"}] = {"ε"};
t[{"ADD_EXP_PRIME", ";"}] = {"ε"};
t[{"ADD_EXP_PRIME", ")"}] = {"ε"};
t[{"ADD_EXP_PRIME", ","}] = {"ε"};
t[{"ADD_EXP_PRIME", "in"}] = {"ε"};
t[{"ADD_EXP_PRIME", "||"}] = {"ε"};
t[{"ADD_EXP_PRIME", "&&"}] = {"ε"};
t[{"ADD_EXP_PRIME", "+"}] = {"+", "MUL_EXP", "ADD_EXP_PRIME"};
t[{"ADD_EXP_PRIME", "-"}] = {"-", "MUL_EXP", "ADD_EXP_PRIME"};
t[{"ADD_EXP_PRIME", "]"}] = {"ε"};
t[{"ADD_EXP_PRIME", "<"}] = {"ε"};
t[{"ADD_EXP_PRIME", "<="}] = {"ε"};
t[{"ADD_EXP_PRIME", ">"}] = {"ε"};
t[{"ADD_EXP_PRIME", ">="}] = {"ε"};
t[{"ADD_EXP_PRIME", "="}] = {"ε"};
t[{"ADD_EXP_PRIME", "<>"}] = {"ε"};
t[{"ADD_EXP_PRIME", "then"}] = {"ε"};
t[{"ADD_EXP_PRIME", "fi"}] = {"ε"};
t[{"ADD_EXP_PRIME", "else"}] = {"ε"};
t[{"ADD_EXP_PRIME", "do"}] = {"ε"};
t[{"ADD_EXP_PRIME", "od"}] = {"ε"};
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
t[{"MUL_EXP_PRIME", "end"}] = {"ε"};
t[{"MUL_EXP_PRIME", ";"}] = {"ε"};
t[{"MUL_EXP_PRIME", ")"}] = {"ε"};
t[{"MUL_EXP_PRIME", ","}] = {"ε"};
t[{"MUL_EXP_PRIME", "in"}] = {"ε"};
t[{"MUL_EXP_PRIME", "||"}] = {"ε"};
t[{"MUL_EXP_PRIME", "&&"}] = {"ε"};
t[{"MUL_EXP_PRIME", "+"}] = {"ε"};
t[{"MUL_EXP_PRIME", "-"}] = {"ε"};
t[{"MUL_EXP_PRIME", "*"}] = {"*", "EXP_EXP", "MUL_EXP_PRIME"};
t[{"MUL_EXP_PRIME", "/"}] = {"/", "EXP_EXP", "MUL_EXP_PRIME"};
t[{"MUL_EXP_PRIME", "]"}] = {"ε"};
t[{"MUL_EXP_PRIME", "<"}] = {"ε"};
t[{"MUL_EXP_PRIME", "<="}] = {"ε"};
t[{"MUL_EXP_PRIME", ">"}] = {"ε"};
t[{"MUL_EXP_PRIME", ">="}] = {"ε"};
t[{"MUL_EXP_PRIME", "="}] = {"ε"};
t[{"MUL_EXP_PRIME", "<>"}] = {"ε"};
t[{"MUL_EXP_PRIME", "then"}] = {"ε"};
t[{"MUL_EXP_PRIME", "fi"}] = {"ε"};
t[{"MUL_EXP_PRIME", "else"}] = {"ε"};
t[{"MUL_EXP_PRIME", "do"}] = {"ε"};
t[{"MUL_EXP_PRIME", "od"}] = {"ε"};
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
t[{"EXP_EXP_PRIME", "end"}] = {"ε"};
t[{"EXP_EXP_PRIME", ";"}] = {"ε"};
t[{"EXP_EXP_PRIME", ")"}] = {"ε"};
t[{"EXP_EXP_PRIME", ","}] = {"ε"};
t[{"EXP_EXP_PRIME", "in"}] = {"ε"};
t[{"EXP_EXP_PRIME", "||"}] = {"ε"};
t[{"EXP_EXP_PRIME", "&&"}] = {"ε"};
t[{"EXP_EXP_PRIME", "+"}] = {"ε"};
t[{"EXP_EXP_PRIME", "-"}] = {"ε"};
t[{"EXP_EXP_PRIME", "*"}] = {"ε"};
t[{"EXP_EXP_PRIME", "/"}] = {"ε"};
t[{"EXP_EXP_PRIME", "^"}] = {"^", "PRIMARY", "EXP_EXP_PRIME"};
t[{"EXP_EXP_PRIME", "]"}] = {"ε"};
t[{"EXP_EXP_PRIME", "<"}] = {"ε"};
t[{"EXP_EXP_PRIME", "<="}] = {"ε"};
t[{"EXP_EXP_PRIME", ">"}] = {"ε"};
t[{"EXP_EXP_PRIME", ">="}] = {"ε"};
t[{"EXP_EXP_PRIME", "="}] = {"ε"};
t[{"EXP_EXP_PRIME", "<>"}] = {"ε"};
t[{"EXP_EXP_PRIME", "then"}] = {"ε"};
t[{"EXP_EXP_PRIME", "fi"}] = {"ε"};
t[{"EXP_EXP_PRIME", "else"}] = {"ε"};
t[{"EXP_EXP_PRIME", "do"}] = {"ε"};
t[{"EXP_EXP_PRIME", "od"}] = {"ε"};
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
t[{"NAME_TAIL", "end"}] = {"ε"};
t[{"NAME_TAIL", ";"}] = {"ε"};
t[{"NAME_TAIL", ":="}] = {"ε"};
t[{"NAME_TAIL", "("}] = {"(", "E", ")", "NAME_TAIL"};
t[{"NAME_TAIL", ")"}] = {"ε"};
t[{"NAME_TAIL", ","}] = {"ε"};
t[{"NAME_TAIL", "in"}] = {"ε"};
t[{"NAME_TAIL", "||"}] = {"ε"};
t[{"NAME_TAIL", "&&"}] = {"ε"};
t[{"NAME_TAIL", "+"}] = {"ε"};
t[{"NAME_TAIL", "-"}] = {"ε"};
t[{"NAME_TAIL", "*"}] = {"ε"};
t[{"NAME_TAIL", "/"}] = {"ε"};
t[{"NAME_TAIL", "^"}] = {"ε"};
t[{"NAME_TAIL", "."}] = {".", "NAME", "NAME_TAIL"};
t[{"NAME_TAIL", "["}] = {"[", "EXP", "]", "NAME_TAIL"};
t[{"NAME_TAIL", "]"}] = {"ε"};
t[{"NAME_TAIL", "<"}] = {"ε"};
t[{"NAME_TAIL", "<="}] = {"ε"};
t[{"NAME_TAIL", ">"}] = {"ε"};
t[{"NAME_TAIL", ">="}] = {"ε"};
t[{"NAME_TAIL", "="}] = {"ε"};
t[{"NAME_TAIL", "<>"}] = {"ε"};
t[{"NAME_TAIL", "then"}] = {"ε"};
t[{"NAME_TAIL", "fi"}] = {"ε"};
t[{"NAME_TAIL", "else"}] = {"ε"};
t[{"NAME_TAIL", "do"}] = {"ε"};
t[{"NAME_TAIL", "od"}] = {"ε"};
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
t[{"XX", "end"}] = {"ε"};
t[{"XX", ";"}] = {"ε"};
t[{"XX", ":="}] = {"NAME_TAIL", ":=", "EXP"};
t[{"XX", "("}] = {"NAME_TAIL", ":=", "EXP"};
t[{"XX", "."}] = {"NAME_TAIL", ":=", "EXP"};
t[{"XX", "["}] = {"NAME_TAIL", ":=", "EXP"};
t[{"XX", "fi"}] = {"ε"};
t[{"XX", "else"}] = {"ε"};
t[{"XX", "od"}] = {"ε"};
t[{"ASSIGN_STMT", "NAME"}] = {"VAR", ":=", "EXP"};
t[{"IF_STMT", "if"}] = {"if", "EXP", "then", "STMT_LIST", "D", "fi"};
t[{"D", "fi"}] = {"ε"};
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
t[{"E_TAIL", ")"}] = {"ε"};
t[{"E_TAIL", ","}] = {",", "EXP", "E_TAIL"};
t[{"TYPE", "NAME"}] = {"NAME"};
t[{"TYPE", "ref"}] = {"ref", "(", "TYPE", ")"};
t[{"TYPE", "float"}] = {"float"};
t[{"TYPE", "int"}] = {"int"};
t[{"TYPE", "string"}] = {"string"};
t[{"TYPE", "bool"}] = {"bool"};
t[{"TYPE", "array"}] = {"array", "F", "of", "TYPE"};
t[{"F", "INT_LITERAL"}] = {"INT_LITERAL"};
t[{"F", "of"}] = {"ε"};
