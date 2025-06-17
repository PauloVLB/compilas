#include <bits/stdc++.h>

#include "symbol_table.hpp"

using namespace std;

int main() {

    SymbolTable ts;

    // escopo global
    ts.insert("x", TokenInfo({}, Tipo::make_base(BaseTipo::INT), Tag::VAR));

    ts.enter_scope(); // escopo interno (ex: procedimento)
    ts.insert("y", TokenInfo({}, Tipo::make_base(BaseTipo::FLOAT), Tag::VAR));

    auto info = ts.lookup("x"); // encontra no escopo global
    auto info2 = ts.lookup("y"); // encontra no escopo atual

    ts.print_all();

    ts.exit_scope();
    auto info3 = ts.lookup("y"); // agora retorna nullopt
}