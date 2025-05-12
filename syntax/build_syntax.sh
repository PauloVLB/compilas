flex -o ../lex/lex.cpp ../lex/lex.flex
g++ syntax.cpp ../lex/lex.cpp -o syntax