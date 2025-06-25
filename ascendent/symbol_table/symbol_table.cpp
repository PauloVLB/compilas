#include "symbol_table.hpp"

std::vector<std::unordered_map<std::string, TokenInfo>> SymbolTable::scopes;
std::stack<std::string> SymbolTable::current_proc;