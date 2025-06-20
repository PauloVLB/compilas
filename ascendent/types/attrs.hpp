#ifndef ATTRS_HPP
#define ATTRS_HPP

#include <stdbool.h>
#include <memory>
#include <string>


typedef struct {
    bool ok;
    std::string type;
} TypedAttr;

typedef struct {
    bool ok;
} BoolAttr;

typedef struct {
    std::string name;
} NamedAttr;

#endif
