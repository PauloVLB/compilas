# Comp2025.3 - Compilador NAO com Geração de Código C de 3 Endereços

Este repositório contém um compilador completo para a linguagem NAO, um projeto acadêmico que implementa todas as fases de compilação: análise léxica, sintática, semântica e **geração de código C de 3 endereços**. O compilador utiliza análise sintática ascendente (bottom-up) com Flex e Bison e produz código intermediário no formato de 3 endereços.

## Autores

- Debora Tayna da Silva Chacon
- Dante Augusto Bezerra Pinto
- Esther Maria da Silveira Wanderley
- Henrique Lopes Fouquet
- Paulo Vitor Lima Borges

## Estrutura do Projeto

O compilador está organizado da seguinte forma:

- `/ascendent`: Implementação completa do compilador usando análise sintática ascendente
  - `lex.flex`: Analisador léxico com definições de tokens
  - `parser.y`: Analisador sintático com gramática e **geração de código**
  - `main.cpp`: Ponto de entrada do compilador
  - `symbol_table/`: Sistema de tabela de símbolos com escopo
  - `types/`: Definições de tipos e atributos para análise semântica
- `/tests`: Arquivos de teste abrangentes para todas as funcionalidades
- `/old`: Versões anteriores e arquivos de desenvolvimento

## Funcionalidades Implementadas

O compilador NAO implementa um conjunto abrangente de funcionalidades:

### ✅ Análise Léxica
- Reconhecimento de tokens da linguagem NAO
- Tratamento de comentários (linha e bloco)
- Controle de posição (linha e coluna) para relatórios de erro
- Literais: inteiros, floats, strings e booleanos

### ✅ Análise Sintática
- Gramática completa da linguagem NAO usando Bison
- Tratamento de precedência de operadores
- Estruturas de controle: if-then-else, while-do
- Declarações de procedures, variáveis e structs

### ✅ Análise Semântica
- **Sistema de tabela de símbolos com múltiplos escopos**
- **Verificação de tipos** com relatórios detalhados de erro
- **Conversão implícita** (int → float)
- **Verificação de compatibilidade** de tipos em atribuições
- **Resolução de referências** e verificação de declaração

### ✅ Sistema de Tipos Avançado
- **Tipos primitivos**: int, float, string, bool
- **Tipos compostos**: struct com membros tipados
- **Arrays multidimensionais**: `array [size] of type`
- **Referências (ponteiros)**: `ref(type)` com operadores `ref()` e `deref()`
- **Verificação de indexação** de arrays

### ✅ Geração de Código C de 3 Endereços
- **Tradução completa para código C intermediário** no formato de 3 endereços
- **Código de 3 endereços**: Cada operação usa no máximo 3 operandos (resultado, operando1, operando2)
- **Variáveis temporárias automáticas** (`t0`, `t1`, `t2`...) para expressões complexas
- **Linearização de expressões** em instruções simples
- **Estruturas de controle** traduzidas com labels e gotos
- **Resolução de tipos** para equivalentes em C
- **Funções built-in**: printf, scanf para I/O
- **Salvamento automático** do código gerado em arquivos `.c`

### ✅ Funcionalidades da Linguagem NAO
- **Procedures** com parâmetros tipados
- **Structs** com acesso a membros (`.`)
- **Arrays** com indexação (`[]`) e verificação de tipos
- **Referências** com `ref()` e `deref()` para ponteiros
- **Operadores aritméticos**: `+`, `-`, `*`, `/`, `^` (exponenciação)
- **Operadores relacionais**: `<`, `<=`, `>`, `>=`, `=`, `<>`
- **Operadores lógicos**: `and`, `or`, `not`
- **Comando `new`** para alocação de structs

## Dependências

Para compilar e executar este projeto, você precisará das seguintes dependências:

- **GCC/G++** (versão 7.0 ou superior) com suporte a C++17
- **Flex** (Fast Lexical Analyzer Generator)
- **Bison** (GNU Parser Generator)
- **Make**

### Instalação das Dependências

#### No Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential flex bison
```

## Compilação

Para compilar o compilador, navegue até o diretório `/ascendent` e execute:

```bash
cd ascendent
make
```

Isso gerará o executável `syntax_asc` no mesmo diretório.

### Requisitos do Sistema
- **Make** para automação de build
- **Bison** para geração do parser
- **Flex** para geração do scanner léxico
- **GCC/G++** para compilação (C++17)

## Uso do Compilador

### Primeiro Uso

Antes de executar o compilador, crie o diretório de saída:

```bash
mkdir -p out
```

Em seguida, compile e execute:

```bash
./syntax_asc < ../tests/correct.nao
```

O compilador realizará:
1. **Análise léxica e sintática** completa
2. **Verificação semântica** com detecção de erros
3. **Geração de código C de 3 endereços** equivalente
4. **Salvamento automático** do código em `../out/programa.c`

### Saída do Compilador

Quando bem-sucedido, o compilador exibirá:
- Confirmação da análise sintática
- **Código C de 3 endereços** completo na saída padrão
- Arquivo `.c` salvo no diretório `out/`

### Exemplos

Há diversos arquivos de teste disponíveis no diretório `/tests`:

```bash
# Programa básico com declarações e atribuições
./syntax_asc < ../tests/correct.nao

# Exemplo completo com referências e structs
./syntax_asc < ../tests/swapexample.nao

# Suite de testes abrangente
./syntax_asc < ../tests/test_suite.nao

# Algoritmo de busca binária completo
./syntax_asc < ../tests/binary_search.nao
```

## Compilando o Código Gerado

O compilador gera **código C de 3 endereços** que pode ser compilado com GCC:

```bash
# Compilar e executar o código gerado
cd out
gcc -o programa programa.c -lm
./programa
```

### Exemplo de Geração de Código de 3 Endereços

Para o programa NAO:
```nao
program exemplo
begin
    procedure main()
    begin
        var x : int := 42;
        var y : float
    in
        y := x + 2.5;
        printfloat(y)
    end
end
```

O compilador gera **código de 3 endereços em C**:
```c
#include <stdio.h>
#include <math.h>

int main() {
    int xt0;      // Variável original x
    float yt1;    // Variável original y
    float t2;     // Variável temporária para x + 2.5
    
    xt0 = 42;           // Atribuição simples
    t2 = xt0 + 2.5;     // Operação de 3 endereços: t2 = xt0 + 2.5
    yt1 = t2;           // Atribuição simples: y = t2
    printf("%f", yt1);  // Chamada de função
}
```

**Características do código de 3 endereços gerado:**
- **Uma operação por linha** com no máximo 3 operandos
- **Variáveis temporárias** (`t0`, `t1`, `t2`...) para resultados intermediários
- **Linearização de expressões complexas** em instruções simples
- **Código intermediário** facilmente otimizável e executável

## 🎯 Código de 3 Endereços

Uma das principais características deste compilador é a **geração de código C no formato de 3 endereços**, um padrão fundamental em compiladores:

### O que é Código de 3 Endereços?
- **Formato padrão**: `resultado = operando1 operador operando2`
- **Máximo 3 operandos** por instrução (resultado + até 2 operandos)
- **Linearização** de expressões complexas em instruções simples
- **Código intermediário** facilmente otimizável

### Vantagens do Formato de 3 Endereços
- ✅ **Simplicidade**: Cada instrução realiza uma única operação
- ✅ **Otimização**: Fácil análise e transformação do código
- ✅ **Depuração**: Código intermediário legível e rastreável
- ✅ **Portabilidade**: Base sólida para diferentes arquiteturas

### Exemplo Prático de Transformação

**Código NAO original:**
```nao
y := (a + b) * (c - d);
```

**Código de 3 endereços gerado:**
```c
t1 = a + b;     // Primeira operação: t1 = a + b
t2 = c - d;     // Segunda operação: t2 = c - d  
y = t1 * t2;    // Terceira operação: y = t1 * t2
```

**Características observadas:**
- Expressão complexa dividida em **3 instruções simples**
- **Variáveis temporárias** (`t1`, `t2`) para resultados intermediários
- **Uma operação aritmética por linha**
- **Máximo 3 operandos** por instrução

## Arquivos de Teste

O diretório `/tests` contém uma suite abrangente de testes que demonstram todas as funcionalidades implementadas:

### Testes Básicos
- **`correct.nao`**: Programa mínimo correto com declaração de variável e atribuição
- **`if_example.nao`**: Estruturas condicionais if-then-else
- **`while_example.nao`**: Laços while-do

### Testes de Tipos e Estruturas
- **`struct_example.nao`**: Declaração e uso de structs com acesso a membros
- **`testestruct.nao`**: Testes avançados de estruturas
- **`nested.nao`**: Estruturas aninhadas e teste de escopo

### Testes de Referências e Arrays
- **`swapexample.nao`**: Exemplo completo de referências e desreferenciamento
- **`testeref.nao`**: Testes avançados de referências, incluindo referências de referências
- Arrays multidimensionais e indexação

### Testes Avançados
- **`test_suite.nao`**: Suite completa demonstrando todas as funcionalidades:
  - Tipos primitivos e compostos
  - Conversões implícitas de tipo
  - Operações aritméticas e lógicas
  - Arrays multidimensionais
  - Referências e ponteiros
  - Structs complexas
- **`binary_search.nao`**: Algoritmo completo de busca binária

### Testes de Erro
- **`testeerros.nao`**: Arquivo com erros intencionais para validar a detecção semântica

### Executando os Testes

```bash
cd ascendent

# Teste básico
./syntax_asc < ../tests/correct.nao

# Suite completa (demonstra todas as funcionalidades)
./syntax_asc < ../tests/test_suite.nao

# Algoritmo complexo
./syntax_asc < ../tests/binary_search.nao
```

## Limpeza

Para limpar os arquivos gerados durante a compilação:

```bash
cd ascendent
make clean
```

## Desenvolvimento e Arquitetura

Este compilador implementa todas as fases de um compilador completo:

### Arquitetura do Sistema

#### 1. **Análise Léxica** (`lex.flex`)
- Tokenização completa da linguagem NAO
- Controle preciso de posição para relatórios de erro
- Tratamento de comentários e literais

#### 2. **Análise Sintática** (`parser.y`)
- Gramática LR(1) completa usando Bison
- Precedência e associatividade de operadores
- Construção de árvore sintática com atributos semânticos

#### 3. **Análise Semântica** (integrada ao parser)
- **Sistema de tabela de símbolos** (`symbol_table/`)
  - Múltiplos escopos com pilha
  - Verificação de redeclaração
  - Resolução de nomes
- **Sistema de tipos** (`types/`)
  - Verificação de compatibilidade
  - Conversões implícitas
  - Tipos compostos e referências

#### 4. **Geração de Código de 3 Endereços** (integrada ao parser)
- **Tradução dirigida pela sintaxe** para código de 3 endereços
- **Geração de código C de 3 endereços** com linearização de expressões
- **Variáveis temporárias automáticas** (`t0`, `t1`, `t2`...) para expressões intermediárias
- **Labels únicos** para estruturas de controle
- **Uma operação por instrução** seguindo o padrão de 3 endereços

### Principais Componentes

- **`main.cpp`**: Ponto de entrada, inicialização do sistema
- **`symbol_table/symbol_table.hpp/cpp`**: Gerenciamento de símbolos e escopos
- **`types/attrs.hpp`**: Definições de atributos para análise semântica
- **`Makefile`**: Sistema de build automatizado

