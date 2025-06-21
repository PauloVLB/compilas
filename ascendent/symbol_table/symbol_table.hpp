#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

// Include necessary headers
#include <string>
#include <unordered_map>
#include <stack>
#include <vector>
#include <optional>

#include "../types/types.hpp"

enum class Tag {
    VAR,
    PROC,
    STRUCT,
    PROC_PARAM
};

inline std::ostream& operator<<(std::ostream& os, const Tag& tag) {
    switch (tag) {
        case Tag::VAR: os << "VAR"; break;
        case Tag::PROC: os << "PROC"; break;
        case Tag::STRUCT: os << "STRUCT"; break;
        case Tag::PROC_PARAM: os << "PROC_PARAM"; break;
    }
    return os;
}

struct TokenInfo {
    std::vector<std::string> paramList; // se for PROC
    std::string type;
    Tag tag;
    // Para STRUCT
    // Mapeia nome do membro para seu tipo
    std::unordered_map<std::string, std::string> members;

    TokenInfo(std::vector<std::string> pl, std::string t, Tag tg, std::unordered_map<std::string, std::string> mp = {})
        : paramList(std::move(pl)), type(t), tag(tg), members(std::move(mp)) {}

    TokenInfo() : paramList({}), type(), tag() {}
};

inline std::ostream& operator<<(std::ostream& os, const TokenInfo& info) {
    os << "TokenInfo(";
    os << "paramList: [";
    for (const auto& type : info.paramList) {
        os << type << ", ";
    }
    os << "], type: " << info.type << ", tag: " << info.tag << ")";
    return os;
}

// Class or structure declaration
class SymbolTable {
    private:
        static std::vector<std::unordered_map<std::string, TokenInfo>> scopes;
    
        // SymbolTable() {
        //     enter_scope(); // escopo global
        // }
    
    public:
        static void enter_scope() {
            scopes.emplace_back();
        }
    
        static void exit_scope() {
            if (!scopes.empty())
                scopes.pop_back();
        }


    static bool insert(const std::string& name, const TokenInfo& info) {
        auto& current = scopes.back();
        if (current.count(name) > 0) return false; // redeclaração no mesmo escopo
        current[name] = info;
        return true;
    }

    static std::optional<TokenInfo> lookup(const std::string& name)  {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            auto found = it->find(name);
            if (found != it->end()) return found->second;
        }
        return std::nullopt; // não encontrado
    }

    static bool exists_in_current_scope(const std::string& name) {
        const auto& current = scopes.back();
        return current.count(name) > 0;
    }

    static void print_all()  {
        std::cout << "Symbol Table Contents:\n";
        int scope_level = 0;
        for (const auto& scope : scopes) {
            std::cout << "Scope " << scope_level++ << ":\n";
            for (const auto& [name, info] : scope) {
                std::cout << "  " << name << " -> " << info << "\n";
            }
        }
    }

};

#endif // SYMBOL_TABLE_HPP