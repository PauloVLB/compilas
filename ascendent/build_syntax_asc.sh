flex -o lexer.cpp lex.flex
bison -d -o parser.cpp parser.y
g++ lexer.cpp parser.cpp -o syntax_asc