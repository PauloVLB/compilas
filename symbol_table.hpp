#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

// Include necessary headers
#include <string>
#include <unordered_map>
#include <stack>

// Class or structure declaration
class symbol_table {
    
public:
    // struct token_info {
    //     std::string name;

    //     token_info(std::string _name){
    //         name = _name;
    //     }
    // };

    static void insert(const std::string& key, std::string value) {
        table[key].push(value);
    }

    static bool find(const std::string& key) {
        return table.count(key);
    }

    static std::string get(std::string key) {
        return table[key].top();
    }
    
    static void remove(std::string key) {
        if(!table[key].empty()) {
            table[key].pop();
        }
    }

private:
    static std::unordered_map<std::string, std::stack<std::string>> table;
};

#endif // SYMBOL_TABLE_HPP