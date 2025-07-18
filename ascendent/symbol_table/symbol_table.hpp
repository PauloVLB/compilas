#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

// Include necessary headers
#include <string>
#include <unordered_map>
#include <stack>
#include <vector>
#include <optional>
#include <iostream>

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
    std::vector<std::string> paramList; 
    std::string type;
    Tag tag;
    std::unordered_map<std::string, std::string> members;
    std::string label;

    TokenInfo(std::vector<std::string> pl, std::string t, Tag tg, std::unordered_map<std::string, std::string> mp = {})
        : paramList(std::move(pl)), type(t), tag(tg), members(std::move(mp)), label("t") {}

    TokenInfo() : paramList({}), type(), tag() {}
};

inline std::ostream& operator<<(std::ostream& os, const TokenInfo& info) {
    os << "TokenInfo(";
    os << "paramList: [";
    for (const auto& type : info.paramList) {
        os << type << ", ";
    }
    os << "], type: " << info.type << ", tag: " << info.tag;
    os << ", members: {";
    for (const auto& [name, type] : info.members) {
        os << name << ": " << type << ", ";
    }
    os << "})";

    return os;
}

class SymbolTable {
    private:
        static std::vector<std::unordered_map<std::string, TokenInfo>> scopes;
        static std::stack<std::string> current_proc;

    public:
        static void enter_scope(std::string name) {
            scopes.emplace_back();
            current_proc.push(name);
        }
    
        static void exit_scope() {
            if (!scopes.empty())
                scopes.pop_back();
            if(!current_proc.empty()){

                current_proc.pop();
            }
        }

        static std::string get_scope_name() {
            if(!current_proc.empty()) {
                return current_proc.top();
            }

            return "none";
        }


    static bool insert(const std::string& name, const TokenInfo& info) {
        auto& current = scopes.back();
        if (current.count(name) > 0) return false; // redeclaração no mesmo escopo
        current[name] = info;
        return true;
    }

    static void set_label(const std::string& name, const std::string& label) {
        if (scopes.empty()) return; // não há escopo
        auto& current = scopes.back();
        auto it = current.find(name);
        if (it != current.end()) {
            it->second.label = label; // atualiza o label
        } else {
            std::cerr << "Warning: Attempted to insert label for undeclared variable '" << name << "'\n";
        }
    }

    static std::string get_label(const std::string& name) {
        if (scopes.empty()) return ""; // não há escopo
        auto& current = scopes.back();
        auto it = current.find(name);
        if (it != current.end()) {
            return it->second.label; // retorna o label
        }
        return ""; // não encontrado
    }

    static bool insert_into_parent_scope(const std::string& name, const TokenInfo& info) {
        if (scopes.size() < 2) return false; // não há escopo pai
        auto& parent = scopes[scopes.size() - 2];
        if (parent.count(name) > 0) return false; // redeclaração no escopo pai
        parent[name] = info;
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