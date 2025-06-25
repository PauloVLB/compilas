#ifndef ATTRS_HPP
#define ATTRS_HPP

#include <stdbool.h>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>


typedef struct {
    std::string type;
} TypedAttr;

typedef struct {
    bool ok;
} BoolAttr;

typedef struct {
    std::string name;
} NamedAttr;

typedef struct {
    bool ok;
    std::unordered_map<std::string, std::string> member_map;
} MapAttr;

typedef struct {
    bool ok;
    std::vector<std::string> param_types_list;
} ListAttr;

#endif
