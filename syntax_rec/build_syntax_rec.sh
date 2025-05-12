flex -o ../lex/lex.cpp ../lex/lex.flex
g++ syntax_rec.cpp ../lex/lex.cpp -o syntax_rec