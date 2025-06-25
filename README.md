# Comp2025.3

Este repositório contém um compilador para a linguagem NAO, um projeto acadêmico de implementação de compilador usando análise sintática ascendente (bottom-up).

## Autores

- Debora Tayna da Silva Chacon
- Dante Augusto Bezerra Pinto
- Esther Maria da Silveira Wanderley
- Henrique Lopes Fouquet
- Paulo Vitor Lima Borges

## Estrutura do Projeto

O compilador está organizado da seguinte forma:

- `/ascendent`: Implementação do compilador usando análise sintática ascendente com Flex e Bison
- `/tests`: Arquivos de teste para o compilador

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

Para compilar o compilador, navegue até o diretório `/ascendent` e execute o comando make:

```bash
cd ascendent
make
```

Isso gerará o executável `syntax_asc` no mesmo diretório.

## Uso do Compilador

Para analisar um arquivo, use:

```bash
./syntax_asc < caminho/para/arquivo.nao
```

### Exemplos

Há diversos arquivos de teste disponíveis no diretório `/tests`. Por exemplo:

```bash
./syntax_asc < ../tests/teste2.nao
```

## Arquivos de Teste

O diretório `/tests` contém diversos arquivos de teste que demonstram diferentes funcionalidades da linguagem NAO:

- **`correct.nao`**: Programa básico correto que demonstra a estrutura mínima de um programa NAO com declaração de variável e atribuição
- **`swapexample.nao`**: Exemplo completo demonstrando o uso de referências e desreferenciamento, incluindo uma função de troca de valores
- **`testestruct.nao`**: Teste de declaração e uso de estruturas (structs) com acesso a campos
- **`testeref.nao`**: Teste avançado de referências, incluindo referências de referências e operações com ponteiros
- **`testeerros.nao`**: Arquivo de teste com erros intencionais para validar a detecção de erros pelo compilador
- **`nested.nao`**: Teste de estruturas aninhadas e escopo
- **`test_suite.nao`**: Suite completa de testes com múltiplas funcionalidades

Para executar qualquer um desses testes:

```bash
cd ascendent
./syntax_asc < ../tests/nome_do_arquivo.nao
```

## Limpeza

Para limpar os arquivos gerados durante a compilação:

```bash
cd ascendent
make clean
```

## Desenvolvimento

Este compilador foi desenvolvido como um projeto acadêmico para demonstrar os conceitos de análise léxica e sintática. A implementação ascendente (bottom-up) utiliza Flex para análise léxica e Bison para análise sintática.

Para estender ou modificar o compilador, você pode editar os seguintes arquivos principais:

- `ascendent/lex.flex`: Definições de tokens para o analisador léxico
- `ascendent/parser.y`: Gramática da linguagem e regras de produção
- `ascendent/main.cpp`: Ponto de entrada do compilador
- `ascendent/symbol_table/`: Implementação da tabela de símbolos

