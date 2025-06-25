/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <iostream>
#include <vector>
#include <optional>
#include <functional>
#include "types/attrs.hpp"
#include "symbol_table/symbol_table.hpp"

extern int yylex();
void yyerror(const char *s);

bool is_numeric(const std::string& type) {
    return type == "INT" || type == "FLOAT";
}

std::string resolve_arithmetic_type(const std::string& t1, const std::string& t2) {
    if (t1 == "FLOAT" || t2 == "FLOAT") {
        return "FLOAT";
    }
    return "INT";
}

bool check_compatible(const std::string& tvar, const std::string& texp) {
    return (tvar == texp) || 
                        (texp == "NULL" && tvar.rfind("REF(", 0) == 0) || 
                        (tvar == "FLOAT" && texp == "INT");
}

void print_token_location(const int& first_line, const int& first_column) {
    std::cout << "Linha " << first_line << ", Coluna " << first_column << ": \n";
}

bool handle_binary_op(
    TypedAttr*& $$ /* Atributo de resultado */,
    const int& first_line, const int& first_column,
    TypedAttr* left /* Operando esquerdo */,
    TypedAttr* right /* Operando direito */,
    const std::string& op_name /* Nome do operador para erros */,
    // Função que define se os tipos são válidos para a operação
    std::function<bool(const std::string&, const std::string&)> are_types_valid,
    // Função que calcula o tipo do resultado
    std::function<std::string(const std::string&, const std::string&)> resolve_result_type)
{
    $$ = new TypedAttr();
    bool ok = (left->type != "ERR" && right->type != "ERR");
    $$->type = "ERR";
    
    if (ok) {
        if (are_types_valid(left->type, right->type)) {
            $$->type = resolve_result_type(left->type, right->type);
        } else {
            print_token_location(first_line, first_column);
            std::cout << "Erro de tipo: Operandos inválidos para o operador '" << op_name << "'. "
                      << "Recebeu '" << left->type << "' e '" << right->type << "'." << std::endl;
            return false;
        }
    } 

    delete left;
    delete right;
    return true;
}


#line 140 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NAME = 3,                       /* NAME  */
  YYSYMBOL_FLOAT_LITERAL = 4,              /* FLOAT_LITERAL  */
  YYSYMBOL_INT_LITERAL = 5,                /* INT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_TRUE = 7,                       /* TRUE  */
  YYSYMBOL_FALSE = 8,                      /* FALSE  */
  YYSYMBOL_NULL_LIT = 9,                   /* NULL_LIT  */
  YYSYMBOL_LPAREN = 10,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 11,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 12,                 /* SEMICOLON  */
  YYSYMBOL_LBRACKET = 13,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 14,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 16,                    /* RBRACE  */
  YYSYMBOL_COLON = 17,                     /* COLON  */
  YYSYMBOL_DOT = 18,                       /* DOT  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_CARET = 20,                     /* CARET  */
  YYSYMBOL_PROGRAM = 21,                   /* PROGRAM  */
  YYSYMBOL_BEGIN_TOK = 22,                 /* BEGIN_TOK  */
  YYSYMBOL_END = 23,                       /* END  */
  YYSYMBOL_VAR = 24,                       /* VAR  */
  YYSYMBOL_PROCEDURE = 25,                 /* PROCEDURE  */
  YYSYMBOL_STRUCT = 26,                    /* STRUCT  */
  YYSYMBOL_IN = 27,                        /* IN  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_THEN = 29,                      /* THEN  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_FI = 31,                        /* FI  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_DO = 33,                        /* DO  */
  YYSYMBOL_OD = 34,                        /* OD  */
  YYSYMBOL_RETURN = 35,                    /* RETURN  */
  YYSYMBOL_NEW = 36,                       /* NEW  */
  YYSYMBOL_DEREF = 37,                     /* DEREF  */
  YYSYMBOL_REF = 38,                       /* REF  */
  YYSYMBOL_NOT = 39,                       /* NOT  */
  YYSYMBOL_ARRAY = 40,                     /* ARRAY  */
  YYSYMBOL_OF = 41,                        /* OF  */
  YYSYMBOL_ASSIGN = 42,                    /* ASSIGN  */
  YYSYMBOL_AND = 43,                       /* AND  */
  YYSYMBOL_OR = 44,                        /* OR  */
  YYSYMBOL_LT = 45,                        /* LT  */
  YYSYMBOL_LE = 46,                        /* LE  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_GE = 48,                        /* GE  */
  YYSYMBOL_EQ = 49,                        /* EQ  */
  YYSYMBOL_NE = 50,                        /* NE  */
  YYSYMBOL_PLUS = 51,                      /* PLUS  */
  YYSYMBOL_MINUS = 52,                     /* MINUS  */
  YYSYMBOL_MULT = 53,                      /* MULT  */
  YYSYMBOL_DIV = 54,                       /* DIV  */
  YYSYMBOL_EXP_OP = 55,                    /* EXP_OP  */
  YYSYMBOL_FLOAT_T = 56,                   /* FLOAT_T  */
  YYSYMBOL_INT_T = 57,                     /* INT_T  */
  YYSYMBOL_STRING_T = 58,                  /* STRING_T  */
  YYSYMBOL_BOOL_T = 59,                    /* BOOL_T  */
  YYSYMBOL_60_ = 60,                       /* ';'  */
  YYSYMBOL_61_ = 61,                       /* ':'  */
  YYSYMBOL_62_ = 62,                       /* '('  */
  YYSYMBOL_63_ = 63,                       /* ')'  */
  YYSYMBOL_64_ = 64,                       /* ','  */
  YYSYMBOL_65_ = 65,                       /* '{'  */
  YYSYMBOL_66_ = 66,                       /* '}'  */
  YYSYMBOL_67_ = 67,                       /* '.'  */
  YYSYMBOL_68_ = 68,                       /* '['  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_opt_decls = 72,                 /* opt_decls  */
  YYSYMBOL_decl_tail = 73,                 /* decl_tail  */
  YYSYMBOL_decl = 74,                      /* decl  */
  YYSYMBOL_var_decl = 75,                  /* var_decl  */
  YYSYMBOL_var_init_opt = 76,              /* var_init_opt  */
  YYSYMBOL_proc_decl = 77,                 /* proc_decl  */
  YYSYMBOL_M_enter_proc_scope = 78,        /* M_enter_proc_scope  */
  YYSYMBOL_proc_header = 79,               /* proc_header  */
  YYSYMBOL_opt_param_list = 80,            /* opt_param_list  */
  YYSYMBOL_paramfield_tail = 81,           /* paramfield_tail  */
  YYSYMBOL_opt_type = 82,                  /* opt_type  */
  YYSYMBOL_block = 83,                     /* block  */
  YYSYMBOL_proc_body_opt = 84,             /* proc_body_opt  */
  YYSYMBOL_rec_decl = 85,                  /* rec_decl  */
  YYSYMBOL_opt_struct_members = 86,        /* opt_struct_members  */
  YYSYMBOL_struct_member_tail = 87,        /* struct_member_tail  */
  YYSYMBOL_struct_member_decl = 88,        /* struct_member_decl  */
  YYSYMBOL_paramfield_decl = 89,           /* paramfield_decl  */
  YYSYMBOL_stmt_list = 90,                 /* stmt_list  */
  YYSYMBOL_stmt_tail = 91,                 /* stmt_tail  */
  YYSYMBOL_stmt = 92,                      /* stmt  */
  YYSYMBOL_assign_stmt = 93,               /* assign_stmt  */
  YYSYMBOL_if_stmt = 94,                   /* if_stmt  */
  YYSYMBOL_else_opt = 95,                  /* else_opt  */
  YYSYMBOL_while_stmt = 96,                /* while_stmt  */
  YYSYMBOL_return_stmt = 97,               /* return_stmt  */
  YYSYMBOL_return_exp_opt = 98,            /* return_exp_opt  */
  YYSYMBOL_call_stmt = 99,                 /* call_stmt  */
  YYSYMBOL_call_exp = 100,                 /* call_exp  */
  YYSYMBOL_call_args_opt = 101,            /* call_args_opt  */
  YYSYMBOL_call_args_tail = 102,           /* call_args_tail  */
  YYSYMBOL_expression = 103,               /* expression  */
  YYSYMBOL_or_exp = 104,                   /* or_exp  */
  YYSYMBOL_and_exp = 105,                  /* and_exp  */
  YYSYMBOL_not_exp = 106,                  /* not_exp  */
  YYSYMBOL_rel_exp = 107,                  /* rel_exp  */
  YYSYMBOL_add_exp = 108,                  /* add_exp  */
  YYSYMBOL_mult_exp = 109,                 /* mult_exp  */
  YYSYMBOL_exp_exp = 110,                  /* exp_exp  */
  YYSYMBOL_unary_exp = 111,                /* unary_exp  */
  YYSYMBOL_primary_exp = 112,              /* primary_exp  */
  YYSYMBOL_var = 113,                      /* var  */
  YYSYMBOL_ref_var = 114,                  /* ref_var  */
  YYSYMBOL_deref_var = 115,                /* deref_var  */
  YYSYMBOL_literal = 116,                  /* literal  */
  YYSYMBOL_bool_literal = 117,             /* bool_literal  */
  YYSYMBOL_type = 118                      /* type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      62,    63,     2,     2,    64,     2,    67,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    60,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,    66,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   138,   142,   153,   157,   167,   168,   169,
     173,   218,   245,   249,   253,   264,   271,   294,   299,   313,
     318,   332,   336,   340,   352,   356,   366,   390,   396,   419,
     424,   445,   465,   487,   491,   502,   506,   516,   517,   518,
     519,   520,   524,   542,   563,   580,   584,   593,   608,   640,
     644,   648,   657,   701,   706,   721,   726,   740,   744,   750,
     754,   760,   764,   776,   779,   786,   793,   800,   807,   814,
     821,   826,   832,   838,   842,   848,   854,   858,   864,   868,
     880,   884,   885,   886,   900,   901,   902,   903,   907,   922,
     957,   986,   998,  1012,  1029,  1030,  1031,  1032,  1033,  1037,
    1038,  1042,  1043,  1044,  1045,  1046,  1061,  1070
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NAME",
  "FLOAT_LITERAL", "INT_LITERAL", "STRING_LITERAL", "TRUE", "FALSE",
  "NULL_LIT", "LPAREN", "RPAREN", "SEMICOLON", "LBRACKET", "RBRACKET",
  "LBRACE", "RBRACE", "COLON", "DOT", "COMMA", "CARET", "PROGRAM",
  "BEGIN_TOK", "END", "VAR", "PROCEDURE", "STRUCT", "IN", "IF", "THEN",
  "ELSE", "FI", "WHILE", "DO", "OD", "RETURN", "NEW", "DEREF", "REF",
  "NOT", "ARRAY", "OF", "ASSIGN", "AND", "OR", "LT", "LE", "GT", "GE",
  "EQ", "NE", "PLUS", "MINUS", "MULT", "DIV", "EXP_OP", "FLOAT_T", "INT_T",
  "STRING_T", "BOOL_T", "';'", "':'", "'('", "')'", "','", "'{'", "'}'",
  "'.'", "'['", "']'", "$accept", "program", "opt_decls", "decl_tail",
  "decl", "var_decl", "var_init_opt", "proc_decl", "M_enter_proc_scope",
  "proc_header", "opt_param_list", "paramfield_tail", "opt_type", "block",
  "proc_body_opt", "rec_decl", "opt_struct_members", "struct_member_tail",
  "struct_member_decl", "paramfield_decl", "stmt_list", "stmt_tail",
  "stmt", "assign_stmt", "if_stmt", "else_opt", "while_stmt",
  "return_stmt", "return_exp_opt", "call_stmt", "call_exp",
  "call_args_opt", "call_args_tail", "expression", "or_exp", "and_exp",
  "not_exp", "rel_exp", "add_exp", "mult_exp", "exp_exp", "unary_exp",
  "primary_exp", "var", "ref_var", "deref_var", "literal", "bool_literal",
  "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,     7,    19,    -8,  -150,    24,    35,    49,    57,    44,
      10,  -150,  -150,    75,  -150,   -34,  -150,    40,    43,  -150,
      24,  -150,    24,  -150,    17,    26,   117,   118,    10,    10,
      72,    60,  -150,  -150,  -150,  -150,  -150,  -150,   120,    62,
      63,    17,    36,    17,  -150,  -150,    82,    84,  -150,    46,
      29,    33,  -150,    74,  -150,    38,  -150,  -150,  -150,  -150,
    -150,    68,    64,  -150,  -150,  -150,  -150,    89,    79,    70,
      77,    81,    78,    83,  -150,   119,    17,    17,    17,   122,
      87,  -150,  -150,  -150,  -150,  -150,  -150,   -37,   106,    17,
    -150,     9,   146,  -150,  -150,    90,    17,    17,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,   147,
      17,    26,   149,    17,  -150,    26,    91,   117,  -150,    26,
    -150,   118,  -150,  -150,   126,   124,  -150,  -150,  -150,    72,
    -150,    17,    17,    96,    97,  -150,   -50,    99,   -35,  -150,
      84,  -150,    29,    29,    29,    29,    29,    29,    33,    33,
    -150,  -150,  -150,  -150,    94,   101,    98,  -150,  -150,    26,
    -150,    77,  -150,    83,    72,    72,    87,  -150,  -150,  -150,
      17,  -150,  -150,  -150,  -150,  -150,  -150,   110,  -150,  -150,
    -150,   135,   132,  -150,    97,    26,    72,   137,  -150,  -150,
    -150,  -150,  -150
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     0,     0,
       5,     7,     8,     0,     9,     0,    15,     0,     0,     2,
       0,     4,    24,    14,     0,     0,    17,    27,     5,     5,
      33,    88,    94,    95,    96,    99,   100,    98,     0,     0,
       0,     0,     0,     0,    82,    11,    57,    59,    61,    63,
      70,    73,    76,    78,    80,    84,    85,    86,    81,    97,
     105,     0,     0,   101,   102,   103,   104,    12,     0,     0,
      19,     0,     0,    29,     6,     0,     0,     0,    49,     0,
      35,    37,    38,    39,    40,    41,    51,     0,     0,    53,
      83,     0,     0,    62,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,    21,     0,    18,     0,
      26,     0,    28,    25,     0,     0,    48,    50,    23,     0,
      34,     0,     0,     0,    55,    88,     0,     0,     0,    87,
      58,    60,    64,    65,    66,    67,    68,    69,    71,    72,
      74,    75,    77,    89,     0,     0,     0,    13,    32,     0,
      16,    19,    31,    29,    33,    33,    35,    42,    43,    52,
       0,    54,    92,    93,    91,    90,   106,     0,    22,    20,
      30,    45,     0,    36,    55,     0,    33,     0,    47,    56,
     107,    46,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,    88,    56,  -150,  -150,  -150,  -150,  -150,
    -150,     8,  -150,  -150,  -150,  -150,  -150,    11,    50,    53,
    -149,     6,    47,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
     -26,  -150,   -11,   -42,  -150,    85,   -32,  -150,    12,    14,
     -49,   133,  -150,   -30,  -150,   -28,  -150,  -150,  -108
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    21,    10,    11,   114,    12,    17,    13,
      69,   118,   160,    23,    30,    14,    72,   122,    73,    70,
      79,   130,    80,    81,    82,   187,    83,    84,   126,    85,
      44,   133,   171,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      87,    95,    88,   155,    86,   131,     1,   158,    24,    93,
       3,   162,   135,   172,     5,   181,   182,   109,   110,     4,
      31,    32,    33,    34,    35,    36,    37,    25,   174,    60,
     109,   110,   109,   110,   124,   125,   127,   191,    15,    31,
      32,    33,    34,    35,    36,    37,    39,   134,     6,     7,
       8,   178,    16,    38,    39,    40,    41,   150,   151,   152,
      18,   136,   138,   137,    61,   141,    62,    19,   154,    42,
      20,   157,    38,    39,    40,    31,    28,   190,    29,    43,
     104,   105,    63,    64,    65,    66,   106,   107,    42,   167,
     168,    98,    99,   100,   101,   102,   103,    22,    43,    87,
      76,    88,    26,    86,    77,   109,   110,    78,    27,    39,
     142,   143,   144,   145,   146,   147,    74,    75,   148,   149,
      68,    71,    89,    90,    91,    92,    96,    97,   184,   108,
     111,   113,   112,   116,    87,    87,    88,    88,    86,    86,
     115,   117,   119,   121,   120,   128,   123,   129,   132,   135,
     153,   185,   159,   139,   156,   164,    87,   165,    88,   169,
      86,   170,   173,   175,   176,   186,   188,   177,   192,   179,
     161,   163,   183,   189,   180,    94,   166,     0,     0,     0,
       0,   140
};

static const yytype_int16 yycheck[] =
{
      30,    43,    30,   111,    30,    42,    21,   115,    42,    41,
       3,   119,     3,    63,    22,   164,   165,    67,    68,     0,
       3,     4,     5,     6,     7,     8,     9,    61,    63,     3,
      67,    68,    67,    68,    76,    77,    78,   186,     3,     3,
       4,     5,     6,     7,     8,     9,    37,    89,    24,    25,
      26,   159,     3,    36,    37,    38,    39,   106,   107,   108,
       3,    91,    92,    91,    38,    97,    40,    23,   110,    52,
      60,   113,    36,    37,    38,     3,    20,   185,    22,    62,
      51,    52,    56,    57,    58,    59,    53,    54,    52,   131,
     132,    45,    46,    47,    48,    49,    50,    22,    62,   129,
      28,   129,    62,   129,    32,    67,    68,    35,    65,    37,
      98,    99,   100,   101,   102,   103,    28,    29,   104,   105,
       3,     3,    62,     3,    62,    62,    44,    43,   170,    55,
      62,    42,    68,    63,   164,   165,   164,   165,   164,   165,
      61,    64,    61,    60,    66,    23,    27,    60,    42,     3,
       3,    41,    61,    63,     5,    29,   186,    33,   186,    63,
     186,    64,    63,    69,    63,    30,    34,    69,    31,   161,
     117,   121,   166,   184,   163,    42,   129,    -1,    -1,    -1,
      -1,    96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    71,     3,     0,    22,    24,    25,    26,    72,
      74,    75,    77,    79,    85,     3,     3,    78,     3,    23,
      60,    73,    22,    83,    42,    61,    62,    65,    74,    74,
      84,     3,     4,     5,     6,     7,     8,     9,    36,    37,
      38,    39,    52,    62,   100,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       3,    38,    40,    56,    57,    58,    59,   118,     3,    80,
      89,     3,    86,    88,    73,    73,    28,    32,    35,    90,
      92,    93,    94,    96,    97,    99,   100,   113,   115,    62,
       3,    62,    62,   106,   111,   103,    44,    43,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    67,
      68,    62,    68,    42,    76,    61,    63,    64,    81,    61,
      66,    60,    87,    27,   103,   103,    98,   103,    23,    60,
      91,    42,    42,   101,   103,     3,   113,   115,   113,    63,
     105,   106,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,     3,   103,   118,     5,   103,   118,    61,
      82,    89,   118,    88,    29,    33,    92,   103,   103,    63,
      64,   102,    63,    63,    63,    69,    63,    69,   118,    81,
      87,    90,    90,    91,   103,    41,    30,    95,    34,   102,
     118,    90,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    75,    76,    76,    77,    78,    79,    80,    80,    81,
      81,    82,    82,    83,    84,    84,    85,    86,    86,    87,
      87,    88,    89,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    93,    93,    94,    95,    95,    96,    97,    98,
      98,    99,   100,   101,   101,   102,   102,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   108,   109,   109,   109,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     113,   114,   115,   115,   116,   116,   116,   116,   116,   117,
     117,   118,   118,   118,   118,   118,   118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     0,     3,     1,     1,     1,
       5,     4,     0,     2,     2,     1,     6,     0,     2,     0,
       3,     0,     2,     4,     0,     3,     5,     0,     2,     0,
       3,     3,     3,     0,     2,     0,     3,     1,     1,     1,
       1,     1,     3,     3,     6,     0,     2,     5,     2,     0,
       1,     1,     4,     0,     2,     0,     3,     1,     3,     1,
       3,     1,     2,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     1,     1,     3,     1,     3,
       4,     4,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PROGRAM NAME BEGIN_TOK opt_decls END  */
#line 120 "parser.y"
    {
        std::string program_name = *(yyvsp[-3].sval);
        delete (yyvsp[-3].sval);
        
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok;
        
        if ((yyval.b_attr)->ok) {
            printf("Análise sintática concluída com sucesso para o programa '%s'!\n", program_name.c_str());
        } else {
            printf("Análise sintática encontrou erros no programa '%s'.\n", program_name.c_str());
        }
        delete (yyvsp[-1].b_attr);
    }
#line 1515 "parser.tab.c"
    break;

  case 3: /* opt_decls: %empty  */
#line 138 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1524 "parser.tab.c"
    break;

  case 4: /* opt_decls: decl decl_tail  */
#line 143 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1535 "parser.tab.c"
    break;

  case 5: /* decl_tail: %empty  */
#line 153 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1544 "parser.tab.c"
    break;

  case 6: /* decl_tail: ';' decl decl_tail  */
#line 158 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1555 "parser.tab.c"
    break;

  case 7: /* decl: var_decl  */
#line 167 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1561 "parser.tab.c"
    break;

  case 8: /* decl: proc_decl  */
#line 168 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1567 "parser.tab.c"
    break;

  case 9: /* decl: rec_decl  */
#line 169 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1573 "parser.tab.c"
    break;

  case 10: /* var_decl: VAR NAME ':' type var_init_opt  */
#line 174 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = false; 
        if ((yyvsp[-1].t_attr)->type != "ERR" && (yyvsp[0].t_attr)->type != "ERR") {
            std::string var_name = *(yyvsp[-3].sval);
            std::string declared_type = (yyvsp[-1].t_attr)->type;
            std::string init_type = (yyvsp[0].t_attr)->type;

            bool has_initializer = (init_type != "void");

            if (has_initializer) {

                if(!check_compatible(declared_type, init_type)) {
                    print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                    std::cout << "Erro de Tipo: Incompatibilidade na inicialização da variável '" << var_name
                            << "'. O tipo declarado é '" << declared_type
                            << "', mas a expressão de inicialização é do tipo '" << init_type << "'." << std::endl;
                } 
                else {
                    bool insert_ok = SymbolTable::insert(var_name, TokenInfo({}, declared_type, Tag::VAR));
                    if (!insert_ok) {
                        print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        std::cout << "Erro: Variável '" << var_name << "' já declarada." << std::endl;
                    } else {
                        (yyval.b_attr)->ok = true; 
                    }
                }
            } else {
                bool insert_ok = SymbolTable::insert(var_name, TokenInfo({}, declared_type, Tag::VAR));
                if (!insert_ok) {
                    print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                    std::cout << "Erro: Variável '" << var_name << "' já declarada." << std::endl;
                } else {
                    (yyval.b_attr)->ok = true;
                }
            }

        }
        
        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].t_attr);
        delete (yyvsp[0].t_attr);
        //SymbolTable::print_all();
    }
#line 1622 "parser.tab.c"
    break;

  case 11: /* var_decl: VAR NAME ASSIGN expression  */
#line 219 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = false; 

        std::string var_name = *(yyvsp[-2].sval);

        if ((yyvsp[0].t_attr)->type != "ERR") {
            std::string init_type = (yyvsp[0].t_attr)->type;

            bool insert_ok = SymbolTable::insert(var_name, TokenInfo({}, init_type, Tag::VAR));
            if (!insert_ok) {
                print_token_location((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                std::cout << "Erro: Variável '" << var_name << "' já declarada." << std::endl;
            } else {
                (yyval.b_attr)->ok = true; // Sucesso
            }
        }

        delete (yyvsp[-2].sval);
        delete (yyvsp[0].t_attr);
        //SymbolTable::print_all();
    }
#line 1649 "parser.tab.c"
    break;

  case 12: /* var_init_opt: %empty  */
#line 245 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "void";
    }
#line 1658 "parser.tab.c"
    break;

  case 13: /* var_init_opt: ASSIGN expression  */
#line 249 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 1664 "parser.tab.c"
    break;

  case 14: /* proc_decl: proc_header block  */
#line 254 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
        //SymbolTable::print_all();
    }
#line 1677 "parser.tab.c"
    break;

  case 15: /* M_enter_proc_scope: NAME  */
#line 264 "parser.y"
                          {
    (yyval.sval) = (yyvsp[0].sval);
    std::string proc_name = *(yyvsp[0].sval);
    SymbolTable::enter_scope(proc_name);
}
#line 1687 "parser.tab.c"
    break;

  case 16: /* proc_header: PROCEDURE M_enter_proc_scope '(' opt_param_list ')' opt_type  */
#line 272 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        std::string proc_name = *(yyvsp[-4].sval);
        (yyval.b_attr)->ok = false;

        bool insert_ok = SymbolTable::insert_into_parent_scope(proc_name, TokenInfo((yyvsp[-2].plist_attr)->param_types_list, (yyvsp[0].t_attr)->type, Tag::PROC));

        if (!insert_ok) {
            print_token_location((yylsp[-4]).first_line, (yylsp[-4]).first_column);
            std::cout << "Erro: Redefinição do procedimento '" << proc_name << "'." << std::endl;
        } else {
            (yyval.b_attr)->ok = true;
        }
        
        delete (yyvsp[-4].sval);
        delete (yyvsp[-2].plist_attr);
        delete (yyvsp[0].t_attr);
    }
#line 1710 "parser.tab.c"
    break;

  case 17: /* opt_param_list: %empty  */
#line 294 "parser.y"
    {
        (yyval.plist_attr) = new ListAttr();
        (yyval.plist_attr)->ok = true;
        (yyval.plist_attr)->param_types_list = std::vector<std::string>();
    }
#line 1720 "parser.tab.c"
    break;

  case 18: /* opt_param_list: paramfield_decl paramfield_tail  */
#line 300 "parser.y"
    {
        (yyval.plist_attr) = (yyvsp[0].plist_attr);
        if ((yyvsp[-1].t_attr)->type != "ERR") {
            (yyval.plist_attr)->param_types_list.insert((yyval.plist_attr)->param_types_list.begin(), (yyvsp[-1].t_attr)->type);
        } else {
            (yyval.plist_attr)->ok = false;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 1734 "parser.tab.c"
    break;

  case 19: /* paramfield_tail: %empty  */
#line 313 "parser.y"
    {
        (yyval.plist_attr) = new ListAttr();
        (yyval.plist_attr)->ok = true;
        (yyval.plist_attr)->param_types_list = std::vector<std::string>();
    }
#line 1744 "parser.tab.c"
    break;

  case 20: /* paramfield_tail: ',' paramfield_decl paramfield_tail  */
#line 319 "parser.y"
    {
        (yyval.plist_attr) = (yyvsp[0].plist_attr);
        if ((yyvsp[-1].t_attr)->type != "ERR") {
            (yyval.plist_attr)->param_types_list.insert((yyval.plist_attr)->param_types_list.begin(), (yyvsp[-1].t_attr)->type);
        } else {
            (yyval.plist_attr)->ok = false;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 1758 "parser.tab.c"
    break;

  case 21: /* opt_type: %empty  */
#line 332 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "void";
    }
#line 1767 "parser.tab.c"
    break;

  case 22: /* opt_type: ':' type  */
#line 336 "parser.y"
               { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 1773 "parser.tab.c"
    break;

  case 23: /* block: BEGIN_TOK proc_body_opt stmt_list END  */
#line 341 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
        SymbolTable::exit_scope();
    }
#line 1785 "parser.tab.c"
    break;

  case 24: /* proc_body_opt: %empty  */
#line 352 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1794 "parser.tab.c"
    break;

  case 25: /* proc_body_opt: decl decl_tail IN  */
#line 357 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 1805 "parser.tab.c"
    break;

  case 26: /* rec_decl: STRUCT NAME '{' opt_struct_members '}'  */
#line 367 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = false;
        std::string struct_name = *(yyvsp[-3].sval);

        bool insert_ok = SymbolTable::insert(struct_name, TokenInfo({}, struct_name, Tag::STRUCT, (yyvsp[-1].map_attr)->member_map));
        
        if (!insert_ok) {
            print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
            std::cout << "Erro: Redefinição do tipo '" << struct_name << "'." << std::endl;
        }
        else {
            (yyval.b_attr)->ok = (yyvsp[-1].map_attr)->ok;
        }
        

        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].map_attr);
    }
#line 1829 "parser.tab.c"
    break;

  case 27: /* opt_struct_members: %empty  */
#line 390 "parser.y"
    {

        (yyval.map_attr) = new MapAttr();
        (yyval.map_attr)->ok = true;
        (yyval.map_attr)->member_map = std::unordered_map<std::string, std::string>();
    }
#line 1840 "parser.tab.c"
    break;

  case 28: /* opt_struct_members: struct_member_decl struct_member_tail  */
#line 397 "parser.y"
    {
        (yyval.map_attr) = (yyvsp[0].map_attr);
        (yyval.map_attr)->ok = false;
        auto& first_member_map = (yyvsp[-1].map_attr)->member_map;
        if((yyvsp[-1].map_attr)->ok) {
            const auto [name, type] = *first_member_map.begin();

            if ((yyval.map_attr)->member_map.count(name) > 0) {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro: Membro da struct '" << name << "' já foi declarado." << std::endl;
            }
            else {
                ((yyval.map_attr)->member_map)[name] = type;
                (yyval.map_attr)->ok = true;
            }
        }
        delete (yyvsp[-1].map_attr);
    }
#line 1863 "parser.tab.c"
    break;

  case 29: /* struct_member_tail: %empty  */
#line 419 "parser.y"
    {
        (yyval.map_attr) = new MapAttr();
        (yyval.map_attr)->ok = true;
        (yyval.map_attr)->member_map = std::unordered_map<std::string, std::string>();
    }
#line 1873 "parser.tab.c"
    break;

  case 30: /* struct_member_tail: ';' struct_member_decl struct_member_tail  */
#line 425 "parser.y"
    {
        (yyval.map_attr) = (yyvsp[0].map_attr);
        (yyval.map_attr)->ok = false;
        auto& new_member_map = (yyvsp[-1].map_attr)->member_map;
        if ((yyvsp[-1].map_attr)->ok) {
            const auto& [name, type] = *new_member_map.begin();

            if ((yyval.map_attr)->member_map.count(name) > 0) {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro: Membro da struct '" << name << "' já foi declarado." << std::endl;
            } else {
                ((yyval.map_attr)->member_map)[name] = type;
                (yyval.map_attr)->ok = true;
            }
        }
        delete (yyvsp[-1].map_attr);
    }
#line 1895 "parser.tab.c"
    break;

  case 31: /* struct_member_decl: NAME ':' type  */
#line 446 "parser.y"
    {
        (yyval.map_attr) = new MapAttr();
        (yyval.map_attr)->member_map = std::unordered_map<std::string, std::string>();
        (yyval.map_attr)->ok = false;
        
        if ((yyvsp[0].t_attr)->type != "ERR") {
            std::string member_name = *(yyvsp[-2].sval);
            std::string member_type = (yyvsp[0].t_attr)->type;
            ((yyval.map_attr)->member_map)[member_name] = member_type;
            (yyval.map_attr)->ok = true;
        }


        delete (yyvsp[-2].sval);
        delete (yyvsp[0].t_attr);
    }
#line 1916 "parser.tab.c"
    break;

  case 32: /* paramfield_decl: NAME ':' type  */
#line 466 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        std::string field_name = *(yyvsp[-2].sval);
        if((yyval.t_attr)->type != "ERR") {
            bool insert_ok = SymbolTable::insert(field_name, TokenInfo({}, (yyvsp[0].t_attr)->type, Tag::PROC_PARAM));
            
            if (!insert_ok) {
                print_token_location((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                std::cout << "Erro: Parâmetro '" << field_name << "' já foi declarado." << std::endl;
                (yyval.t_attr)->type = "ERR";
            }
            
        }
        delete (yyvsp[-2].sval);
        delete (yyvsp[0].t_attr);
    }
#line 1938 "parser.tab.c"
    break;

  case 33: /* stmt_list: %empty  */
#line 487 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1947 "parser.tab.c"
    break;

  case 34: /* stmt_list: stmt stmt_tail  */
#line 492 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1958 "parser.tab.c"
    break;

  case 35: /* stmt_tail: %empty  */
#line 502 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1967 "parser.tab.c"
    break;

  case 36: /* stmt_tail: ';' stmt stmt_tail  */
#line 507 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1978 "parser.tab.c"
    break;

  case 37: /* stmt: assign_stmt  */
#line 516 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1984 "parser.tab.c"
    break;

  case 38: /* stmt: if_stmt  */
#line 517 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1990 "parser.tab.c"
    break;

  case 39: /* stmt: while_stmt  */
#line 518 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1996 "parser.tab.c"
    break;

  case 40: /* stmt: return_stmt  */
#line 519 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 2002 "parser.tab.c"
    break;

  case 41: /* stmt: call_stmt  */
#line 520 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 2008 "parser.tab.c"
    break;

  case 42: /* assign_stmt: var ASSIGN expression  */
#line 525 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = ((yyvsp[-2].t_attr)->type != "ERR" && (yyvsp[0].t_attr)->type != "ERR");
        
        if ((yyval.b_attr)->ok) {
            if (!check_compatible((yyvsp[-2].t_attr)->type, (yyvsp[0].t_attr)->type)) {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro de Tipo: Incompatibilidade na atribuição. "
                          << "Não é possível atribuir uma expressão do tipo '" << (yyvsp[0].t_attr)->type
                          << "' a uma variável do tipo '" << (yyvsp[-2].t_attr)->type << "'." << std::endl;
                (yyval.b_attr)->ok = false;
            }
        }

        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2030 "parser.tab.c"
    break;

  case 43: /* assign_stmt: deref_var ASSIGN expression  */
#line 543 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = ((yyvsp[-2].t_attr)->type != "ERR" && (yyvsp[0].t_attr)->type != "ERR");
        
        if ((yyval.b_attr)->ok) {
            if ((yyvsp[-2].t_attr)->type != (yyvsp[0].t_attr)->type) {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro de Tipo: Incompatibilidade na atribuição. "
                          << "Não é possível atribuir uma expressão do tipo '" << (yyvsp[0].t_attr)->type
                          << "' a uma variável do tipo '" << (yyvsp[-2].t_attr)->type << "'." << std::endl;
                (yyval.b_attr)->ok = false;
            }
        }

        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2052 "parser.tab.c"
    break;

  case 44: /* if_stmt: IF expression THEN stmt_list else_opt FI  */
#line 564 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = ((yyvsp[-4].t_attr)->type != "ERR") && (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        if ((yyvsp[-4].t_attr)->type != "ERR" && (yyvsp[-4].t_attr)->type != "BOOL") {
            print_token_location((yylsp[-4]).first_line, (yylsp[-4]).first_column);
            std::cout << "Erro de tipo: Condição do IF deve ser BOOL, mas foi '" << (yyvsp[-4].t_attr)->type << "'." << std::endl;
            (yyval.b_attr)->ok = false;
        }
        delete (yyvsp[-4].t_attr);
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 2069 "parser.tab.c"
    break;

  case 45: /* else_opt: %empty  */
#line 580 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 2078 "parser.tab.c"
    break;

  case 46: /* else_opt: ELSE stmt_list  */
#line 585 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok;
        delete (yyvsp[0].b_attr);
    }
#line 2088 "parser.tab.c"
    break;

  case 47: /* while_stmt: WHILE expression DO stmt_list OD  */
#line 594 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok =((yyvsp[-3].t_attr)->type != "ERR") && (yyvsp[-1].b_attr)->ok;
        if ((yyvsp[-3].t_attr)->type != "ERR" && (yyvsp[-3].t_attr)->type != "BOOL") {
            print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
            std::cout << "Erro de tipo: Condição do WHILE deve ser BOOL, mas foi '" << (yyvsp[-3].t_attr)->type << "'." << std::endl;
            (yyval.b_attr)->ok = false;
        }
        delete (yyvsp[-3].t_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 2104 "parser.tab.c"
    break;

  case 48: /* return_stmt: RETURN return_exp_opt  */
#line 609 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[0].t_attr)->type != "ERR";

        if((yyval.b_attr)->ok) {
            std::string scope_name = SymbolTable::get_scope_name();
            auto lookup_result = SymbolTable::lookup(scope_name);
            if (!lookup_result || lookup_result->tag != Tag::PROC) {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro: 'RETURN' usado fora de um procedimento/função." << std::endl;
                (yyval.b_attr)->ok = false;
            } else {
                
                if((yyvsp[0].t_attr)->type == lookup_result->type || 
                ((yyvsp[0].t_attr)->type == "void" && lookup_result->type == "void")) {
                    (yyval.b_attr)->ok = true;
                } else {
                    print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                    std::cout << "Erro de tipo: 'RETURN' espera tipo '" << lookup_result->type 
                            << "', mas recebeu '" << (yyvsp[0].t_attr)->type << "'." << std::endl;
                    (yyval.b_attr)->ok = false;
                }
            }
        }

        delete (yyvsp[0].t_attr);
    }
#line 2136 "parser.tab.c"
    break;

  case 49: /* return_exp_opt: %empty  */
#line 640 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "void";
    }
#line 2145 "parser.tab.c"
    break;

  case 50: /* return_exp_opt: expression  */
#line 644 "parser.y"
                 { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2151 "parser.tab.c"
    break;

  case 51: /* call_stmt: call_exp  */
#line 649 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = ((yyvsp[0].t_attr)->type != "ERR");
        delete (yyvsp[0].t_attr);
    }
#line 2161 "parser.tab.c"
    break;

  case 52: /* call_exp: NAME '(' call_args_opt ')'  */
#line 658 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        bool ok = (yyvsp[-1].plist_attr)->ok;
        (yyval.t_attr)->type = "ERR";
        std::string func_name = *(yyvsp[-3].sval);

        auto lookup_result = SymbolTable::lookup(func_name);
        if (!lookup_result || lookup_result->tag != Tag::PROC) {
            print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
            std::cout << "Erro: Função ou procedimento '" << func_name << "' não declarado." << std::endl;
        } else if(ok) {
            const auto& declared_params = lookup_result->paramList;
            const auto& provided_args = (yyvsp[-1].plist_attr)->param_types_list;

            if (declared_params.size() != provided_args.size()) {
                print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                std::cout << "Erro: Função '" << func_name << "' espera " << declared_params.size() 
                          << " argumentos, mas recebeu " << provided_args.size() << "." << std::endl;
            } else {
                bool types_match = true;
                for (size_t i = 0; i < declared_params.size(); ++i) {
                    if (!check_compatible(declared_params[i], provided_args[i])) {
                        print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        std::cout << "Erro: Incompatibilidade de tipo no argumento " << i + 1 
                                  << " da chamada para '" << func_name << "'. Esperado '" 
                                  << declared_params[i] << "', mas recebeu '" << provided_args[i] << "'." << std::endl;
                        types_match = false;
                        break;
                    }
                }

                if (types_match) {
                    (yyval.t_attr)->type = lookup_result->type;
                } 
            }
        }
        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].plist_attr);
    }
#line 2205 "parser.tab.c"
    break;

  case 53: /* call_args_opt: %empty  */
#line 701 "parser.y"
    {
        (yyval.plist_attr) = new ListAttr();
        (yyval.plist_attr)->ok = true;
        (yyval.plist_attr)->param_types_list = std::vector<std::string>();
    }
#line 2215 "parser.tab.c"
    break;

  case 54: /* call_args_opt: expression call_args_tail  */
#line 707 "parser.y"
    {
        (yyval.plist_attr) = (yyvsp[0].plist_attr);
        if ((yyvsp[-1].t_attr)->type != "ERR") {
            (yyval.plist_attr)->param_types_list.insert((yyval.plist_attr)->param_types_list.begin(), (yyvsp[-1].t_attr)->type);
        }
        else {
            (yyval.plist_attr)->ok = false;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2230 "parser.tab.c"
    break;

  case 55: /* call_args_tail: %empty  */
#line 721 "parser.y"
    {
        (yyval.plist_attr) = new ListAttr();
        (yyval.plist_attr)->ok = true;
        (yyval.plist_attr)->param_types_list = std::vector<std::string>();
    }
#line 2240 "parser.tab.c"
    break;

  case 56: /* call_args_tail: ',' expression call_args_tail  */
#line 727 "parser.y"
    {
        (yyval.plist_attr) = (yyvsp[0].plist_attr);
        if ((yyvsp[-1].t_attr)->type != "ERR") {
            (yyval.plist_attr)->param_types_list.insert((yyval.plist_attr)->param_types_list.begin(), (yyvsp[-1].t_attr)->type);
        }
        else {
            (yyval.plist_attr)->ok = false;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2255 "parser.tab.c"
    break;

  case 57: /* expression: or_exp  */
#line 740 "parser.y"
           { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2261 "parser.tab.c"
    break;

  case 58: /* or_exp: or_exp OR and_exp  */
#line 745 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "OR", 
            [](const auto& t1, const auto& t2) { return t1 == "BOOL" && t2 == "BOOL"; },
            [](const auto& t1, const auto& t2) { return "BOOL"; });
    }
#line 2271 "parser.tab.c"
    break;

  case 59: /* or_exp: and_exp  */
#line 750 "parser.y"
              { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2277 "parser.tab.c"
    break;

  case 60: /* and_exp: and_exp AND not_exp  */
#line 755 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "AND",
            [](const auto& t1, const auto& t2) { return t1 == "BOOL" && t2 == "BOOL"; },
            [](const auto& t1, const auto& t2) { return "BOOL"; });
    }
#line 2287 "parser.tab.c"
    break;

  case 61: /* and_exp: not_exp  */
#line 760 "parser.y"
              { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2293 "parser.tab.c"
    break;

  case 62: /* not_exp: NOT not_exp  */
#line 765 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        if ((yyvsp[0].t_attr)->type == "BOOL") {
            (yyval.t_attr)->type = "BOOL";
        } else {
            print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
            std::cout << "Erro de tipo: Operando de NOT deve ser BOOLEAN." << std::endl;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[0].t_attr);
    }
#line 2309 "parser.tab.c"
    break;

  case 63: /* not_exp: rel_exp  */
#line 776 "parser.y"
              { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2315 "parser.tab.c"
    break;

  case 64: /* rel_exp: rel_exp LT add_exp  */
#line 779 "parser.y"
                            {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "<",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2327 "parser.tab.c"
    break;

  case 65: /* rel_exp: rel_exp LE add_exp  */
#line 786 "parser.y"
                     {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "<=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2339 "parser.tab.c"
    break;

  case 66: /* rel_exp: rel_exp GT add_exp  */
#line 793 "parser.y"
                    {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), ">",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2351 "parser.tab.c"
    break;

  case 67: /* rel_exp: rel_exp GE add_exp  */
#line 800 "parser.y"
                     {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), ">=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2363 "parser.tab.c"
    break;

  case 68: /* rel_exp: rel_exp EQ add_exp  */
#line 807 "parser.y"
                     {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2375 "parser.tab.c"
    break;

  case 69: /* rel_exp: rel_exp NE add_exp  */
#line 814 "parser.y"
                     {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "<>",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2387 "parser.tab.c"
    break;

  case 70: /* rel_exp: add_exp  */
#line 821 "parser.y"
          { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2393 "parser.tab.c"
    break;

  case 71: /* add_exp: add_exp PLUS mult_exp  */
#line 827 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "+",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            resolve_arithmetic_type);
    }
#line 2403 "parser.tab.c"
    break;

  case 72: /* add_exp: add_exp MINUS mult_exp  */
#line 833 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "-",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            resolve_arithmetic_type);
    }
#line 2413 "parser.tab.c"
    break;

  case 73: /* add_exp: mult_exp  */
#line 838 "parser.y"
               { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2419 "parser.tab.c"
    break;

  case 74: /* mult_exp: mult_exp MULT exp_exp  */
#line 843 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "*", 
        [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); }, 
        resolve_arithmetic_type);
    }
#line 2429 "parser.tab.c"
    break;

  case 75: /* mult_exp: mult_exp DIV exp_exp  */
#line 849 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "/", 
        [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); }, 
        resolve_arithmetic_type);
    }
#line 2439 "parser.tab.c"
    break;

  case 76: /* mult_exp: exp_exp  */
#line 854 "parser.y"
              { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2445 "parser.tab.c"
    break;

  case 77: /* exp_exp: unary_exp EXP_OP exp_exp  */
#line 859 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "^",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            [](const auto& t1, const auto& t2) { return "FLOAT"; });
    }
#line 2455 "parser.tab.c"
    break;

  case 78: /* exp_exp: unary_exp  */
#line 864 "parser.y"
                { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2461 "parser.tab.c"
    break;

  case 79: /* unary_exp: MINUS unary_exp  */
#line 869 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "ERR";
        if ((yyvsp[0].t_attr)->type != "ERR" && ((yyvsp[0].t_attr)->type == "INT" || (yyvsp[0].t_attr)->type == "FLOAT")) {
            (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        } else {
            print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
            std::cout << "Erro de tipo: Operando unário '-' deve ser numérico." << std::endl;
        }
        delete (yyvsp[0].t_attr);
    }
#line 2477 "parser.tab.c"
    break;

  case 80: /* unary_exp: primary_exp  */
#line 880 "parser.y"
                  { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2483 "parser.tab.c"
    break;

  case 81: /* primary_exp: literal  */
#line 884 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2489 "parser.tab.c"
    break;

  case 82: /* primary_exp: call_exp  */
#line 885 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2495 "parser.tab.c"
    break;

  case 83: /* primary_exp: NEW NAME  */
#line 887 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string type_name = *(yyvsp[0].sval);
        auto lookup_result = SymbolTable::lookup(type_name);
        if (!lookup_result || lookup_result->tag != Tag::STRUCT) {
            print_token_location((yylsp[0]).first_line, (yylsp[0]).first_column);
            std::cout << "Erro: Tipo '" << type_name << "' não é um struct para 'NEW'." << std::endl;
            (yyval.t_attr)->type = "ERR";
        } else {
            (yyval.t_attr)->type =  type_name ;
        }
        delete (yyvsp[0].sval);
    }
#line 2513 "parser.tab.c"
    break;

  case 84: /* primary_exp: var  */
#line 900 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2519 "parser.tab.c"
    break;

  case 85: /* primary_exp: ref_var  */
#line 901 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2525 "parser.tab.c"
    break;

  case 86: /* primary_exp: deref_var  */
#line 902 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2531 "parser.tab.c"
    break;

  case 87: /* primary_exp: '(' expression ')'  */
#line 903 "parser.y"
                        { (yyval.t_attr) = (yyvsp[-1].t_attr); }
#line 2537 "parser.tab.c"
    break;

  case 88: /* var: NAME  */
#line 908 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string var_base_name = *(yyvsp[0].sval);
        delete (yyvsp[0].sval);

        auto lookup_result = SymbolTable::lookup(var_base_name);
        if (!lookup_result || (lookup_result->tag != Tag::VAR && lookup_result->tag != Tag::PROC_PARAM)) {
            print_token_location((yylsp[0]).first_line, (yylsp[0]).first_column);
            std::cout << "Erro: Variável '" << var_base_name << "' não declarada." << std::endl;
            (yyval.t_attr)->type = "ERR";
        } else {
            (yyval.t_attr)->type = lookup_result->type;
        }
    }
#line 2556 "parser.tab.c"
    break;

  case 89: /* var: var '.' NAME  */
#line 923 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "ERR";

        if ((yyvsp[-2].t_attr)->type != "ERR") {
            std::string base_type_name = (yyvsp[-2].t_attr)->type;
            std::string field_name = *(yyvsp[0].sval);

            auto base_type_info_opt = SymbolTable::lookup(base_type_name);

            if (!base_type_info_opt || base_type_info_opt->tag != Tag::STRUCT) {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro de tipo: Tentativa de acessar o campo '" << field_name 
                        << "' em um tipo não-struct ('" << base_type_name << "')." << std::endl;
            } else {
                auto& base_type_info = *base_type_info_opt;

                const auto& members_map = base_type_info.members;
                auto member_iterator = members_map.find(field_name);

                if (member_iterator == members_map.end()) {
                    print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                    std::cout << "Erro de tipo: O tipo '" << base_type_name 
                            << "' não possui um membro chamado '" << field_name << "'." << std::endl;
                } else {
                    (yyval.t_attr)->type = member_iterator->second;
                }
            }
        }
        
        // Limpa a memória do atributo da variável.
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].sval);
    }
#line 2595 "parser.tab.c"
    break;

  case 90: /* var: var '[' expression ']'  */
#line 958 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        bool ok = ((yyvsp[-3].t_attr)->type != "ERR" && (yyvsp[-1].t_attr)->type != "ERR");
        (yyval.t_attr)->type = "ERR";

        if (ok) {
            std::string base_type = (yyvsp[-3].t_attr)->type;
            std::string index_type = (yyvsp[-1].t_attr)->type;

            if (index_type != "INT") {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro de tipo: O índice de um array deve ser um inteiro, mas foi '" << index_type << "'." << std::endl;
            }
            else {
                if (base_type.rfind("ARRAY(", 0) == 0) {
                    (yyval.t_attr)->type = base_type.substr(6, base_type.length() - 7);
                } else {
                    print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                    std::cout << "Erro de tipo: Tentativa de indexar um tipo não-array ('" << base_type << "')." << std::endl;
                }
            }
        }
        delete (yyvsp[-3].t_attr);
        delete (yyvsp[-1].t_attr);
    }
#line 2625 "parser.tab.c"
    break;

  case 91: /* ref_var: REF '(' var ')'  */
#line 987 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "ERR";
        if ((yyvsp[-1].t_attr)->type != "ERR") {
            (yyval.t_attr)->type = "REF(" + (yyvsp[-1].t_attr)->type + ")";
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2638 "parser.tab.c"
    break;

  case 92: /* deref_var: DEREF '(' var ')'  */
#line 999 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "ERR";
        if((yyvsp[-1].t_attr)->type != "ERR") {
            if ((yyvsp[-1].t_attr)->type.rfind("REF(", 0) == 0) {
                (yyval.t_attr)->type = (yyvsp[-1].t_attr)->type.substr(4, (yyvsp[-1].t_attr)->type.length() - 5);
            } else {
                print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                std::cout << "Erro de tipo: DEREF exige um tipo de referência." << std::endl;
            }
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2656 "parser.tab.c"
    break;

  case 93: /* deref_var: DEREF '(' deref_var ')'  */
#line 1013 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "ERR";
        if((yyvsp[-1].t_attr)->type != "ERR") {
            if ((yyvsp[-1].t_attr)->type.rfind("REF(", 0) == 0) {
                (yyval.t_attr)->type = (yyvsp[-1].t_attr)->type.substr(4, (yyvsp[-1].t_attr)->type.length() - 5);
            } else {
                print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                std::cout << "Erro de tipo: DEREF exige um tipo de referência (cascata)." << std::endl;
            }
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2674 "parser.tab.c"
    break;

  case 94: /* literal: FLOAT_LITERAL  */
#line 1029 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "FLOAT"; delete (yyvsp[0].sval); }
#line 2680 "parser.tab.c"
    break;

  case 95: /* literal: INT_LITERAL  */
#line 1030 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "INT"; delete (yyvsp[0].sval); }
#line 2686 "parser.tab.c"
    break;

  case 96: /* literal: STRING_LITERAL  */
#line 1031 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "STRING"; delete (yyvsp[0].sval); }
#line 2692 "parser.tab.c"
    break;

  case 97: /* literal: bool_literal  */
#line 1032 "parser.y"
                      { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2698 "parser.tab.c"
    break;

  case 98: /* literal: NULL_LIT  */
#line 1033 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "NULL"; }
#line 2704 "parser.tab.c"
    break;

  case 99: /* bool_literal: TRUE  */
#line 1037 "parser.y"
            { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "BOOL"; }
#line 2710 "parser.tab.c"
    break;

  case 100: /* bool_literal: FALSE  */
#line 1038 "parser.y"
            { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "BOOL"; }
#line 2716 "parser.tab.c"
    break;

  case 101: /* type: FLOAT_T  */
#line 1042 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "FLOAT"; }
#line 2722 "parser.tab.c"
    break;

  case 102: /* type: INT_T  */
#line 1043 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "INT"; }
#line 2728 "parser.tab.c"
    break;

  case 103: /* type: STRING_T  */
#line 1044 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "STRING"; }
#line 2734 "parser.tab.c"
    break;

  case 104: /* type: BOOL_T  */
#line 1045 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->type = "BOOL"; }
#line 2740 "parser.tab.c"
    break;

  case 105: /* type: NAME  */
#line 1047 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string type_name = *(yyvsp[0].sval);
        auto lookup_result = SymbolTable::lookup(type_name);
        
        if (lookup_result && lookup_result->tag == Tag::STRUCT) {
            (yyval.t_attr)->type = lookup_result->type;
        } else {
            print_token_location((yylsp[0]).first_line, (yylsp[0]).first_column);
            std::cout << "Erro: '" << type_name << "' não é um tipo válido ou struct declarado." << std::endl;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[0].sval);
    }
#line 2759 "parser.tab.c"
    break;

  case 106: /* type: REF '(' type ')'  */
#line 1062 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "ERR";
        if ((yyvsp[-1].t_attr)->type != "ERR") {
            (yyval.t_attr)->type = "REF(" + (yyvsp[-1].t_attr)->type + ")";
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2772 "parser.tab.c"
    break;

  case 107: /* type: ARRAY '[' INT_LITERAL ']' OF type  */
#line 1071 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = "ERR";
        if ((yyvsp[0].t_attr)->type != "ERR") {
            (yyval.t_attr)->type = "ARRAY(" + (yyvsp[0].t_attr)->type + ")";
        }
        delete (yyvsp[-3].sval);
        delete (yyvsp[0].t_attr);
    }
#line 2786 "parser.tab.c"
    break;


#line 2790 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1082 "parser.y"


void yyerror(const char *s) {
    extern int yylineno;
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}

int main(void) {
    SymbolTable::enter_scope("global");
    yyparse();
    
    //std::cout << "\n--- Conteúdo Final da Tabela de Símbolos ---" << std::endl;
    //SymbolTable::print_all();
    SymbolTable::exit_scope();
    
    return 0;
}
