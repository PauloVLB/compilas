flex -o lexer.cpp lex.flex
bison -o parser.cpp -d --language=c++ parser.y
g++ lexer.cpp parser.cpp -o syntax_asc