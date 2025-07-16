#ifndef ATTRS_HPP
#define ATTRS_HPP

#include <stdbool.h>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>


typedef struct {
    std::string type;
    std::string val;
    std::string code;
} TypedAttr;

typedef struct {
    bool ok;
    std::string code;
} BoolAttr;

typedef struct {
    std::string name;
} NamedAttr;

typedef struct {
    bool ok;
    std::unordered_map<std::string, std::string> member_map;
    std::string code;
} MapAttr;

typedef struct {
    bool ok;
    std::vector<std::string> param_types_list;
    std::vector<std::string> param_vals_list;
    std::string code;
} ListAttr;

#endif
