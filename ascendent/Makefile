# Compilador
CXX = g++
# Flags de compilação (C++17, Warnings, Debug)
CXXFLAGS = -std=c++17 -Wall -g

# Arquivos fonte que você escreveu
SOURCES = main.cpp symbol_table/symbol_table.cpp # Uncomment and add your .cpp files here

# Alvo final
TARGET = syntax_asc

# Arquivos objeto
OBJECTS = $(SOURCES:.cpp=.o) lex.yy.o parser.tab.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regra genérica para compilar .cpp para .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para o Bison
# Gera parser.tab.c e parser.tab.h
parser.tab.c parser.tab.h: parser.y
	bison -d -o parser.tab.c parser.y

# Regra para o Flex
# Gera lex.yy.c, que depende do header do Bison
lex.yy.c: lex.flex parser.tab.h
	flex -o lex.yy.c lex.flex

# O Bison gera um arquivo .c, mas podemos compilá-lo com g++
parser.tab.o: parser.tab.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

lex.yy.o: lex.yy.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET) $(OBJECTS) lex.yy.c parser.tab.c parser.tab.h