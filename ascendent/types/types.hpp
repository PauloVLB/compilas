#ifndef TYPES_HPP
#define TYPES_HPP

#include <memory>
#include <string>
#include <iostream>

enum class BaseTipo {
    INT,
    FLOAT,
    STRING,
    BOOL,
    STRUCT,
    NULL_TYPE,
    ERR
};


enum class TipoTag {
    BASE,     // tipo simples como INT, FLOAT, etc.
    ARRAY,    // array de outro tipo
    REF       // referência para outro tipo
};

struct Tipo {
    TipoTag tag;

    // Para BASE
    BaseTipo base;

    // Para ARRAY ou REF
    std::shared_ptr<Tipo> inner;

    // Nome da struct, se BASE == STRUCT
    std::string struct_name;

    // Construtores estáticos para facilitar a criação
    static Tipo make_base(BaseTipo b, std::string struct_name = "") {
        return Tipo{TipoTag::BASE, b, nullptr, struct_name};
    }

    static Tipo make_array(Tipo inner) {
        return Tipo{TipoTag::ARRAY, BaseTipo::ERR, std::make_shared<Tipo>(inner)};
    }

    static Tipo make_ref(Tipo inner) {
        return Tipo{TipoTag::REF, BaseTipo::ERR, std::make_shared<Tipo>(inner)};
    }

    // Comparação de tipos
    bool operator==(const Tipo& other) const {
        if (tag != other.tag) return false;

        if (tag == TipoTag::BASE) {
            return base == other.base &&
                   (base != BaseTipo::STRUCT || struct_name == other.struct_name);
        }

        return *inner == *other.inner;
    }

    bool operator!=(const Tipo& other) const {
        return !(*this == other);
    }

// Define operator<< as a free function below the struct
};


inline std::string to_string(const Tipo& tipo) {
    switch (tipo.tag) {
        case TipoTag::BASE:
            switch (tipo.base) {
                case BaseTipo::INT: return "int";
                case BaseTipo::FLOAT: return "float";
                case BaseTipo::STRING: return "string";
                case BaseTipo::BOOL: return "bool";
                case BaseTipo::STRUCT: return "struct " + tipo.struct_name;
                case BaseTipo::NULL_TYPE: return "null";
                case BaseTipo::ERR: return "<erro>";
            }

        case TipoTag::ARRAY:
            return "array of " + to_string(*tipo.inner);

        case TipoTag::REF:
            return "ref to " + to_string(*tipo.inner);
    }

    return "??";  // fallback seguro
}

// Free function for operator<<
inline std::ostream& operator<<(std::ostream& os, const Tipo& tipo)
{
    os << to_string(tipo);
    return os;
}



#endif