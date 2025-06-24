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
    $$->ok = left->ok && right->ok;
    
    if ($$->ok) {
        if (are_types_valid(left->type, right->type)) {
            $$->type = resolve_result_type(left->type, right->type);
        } else {
            print_token_location(first_line, first_column);
            std::cout << "Erro de tipo: Operandos inválidos para o operador '" << op_name << "'. "
                      << "Recebeu '" << left->type << "' e '" << right->type << "'." << std::endl;
            $$->ok = false;
            $$->type = "ERR";
            return false;
        }
    } else {
        $$->type = "ERR";
    }

    delete left;
    delete right;
    return true;
}


#line 143 "parser.tab.c"

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
  YYSYMBOL_proc_header = 78,               /* proc_header  */
  YYSYMBOL_opt_param_list = 79,            /* opt_param_list  */
  YYSYMBOL_paramfield_tail = 80,           /* paramfield_tail  */
  YYSYMBOL_opt_type = 81,                  /* opt_type  */
  YYSYMBOL_block = 82,                     /* block  */
  YYSYMBOL_proc_body_opt = 83,             /* proc_body_opt  */
  YYSYMBOL_rec_decl = 84,                  /* rec_decl  */
  YYSYMBOL_opt_struct_members = 85,        /* opt_struct_members  */
  YYSYMBOL_struct_member_tail = 86,        /* struct_member_tail  */
  YYSYMBOL_struct_member_decl = 87,        /* struct_member_decl  */
  YYSYMBOL_paramfield_decl = 88,           /* paramfield_decl  */
  YYSYMBOL_stmt_list = 89,                 /* stmt_list  */
  YYSYMBOL_stmt_tail = 90,                 /* stmt_tail  */
  YYSYMBOL_stmt = 91,                      /* stmt  */
  YYSYMBOL_assign_stmt = 92,               /* assign_stmt  */
  YYSYMBOL_if_stmt = 93,                   /* if_stmt  */
  YYSYMBOL_else_opt = 94,                  /* else_opt  */
  YYSYMBOL_while_stmt = 95,                /* while_stmt  */
  YYSYMBOL_return_stmt = 96,               /* return_stmt  */
  YYSYMBOL_return_exp_opt = 97,            /* return_exp_opt  */
  YYSYMBOL_call_stmt = 98,                 /* call_stmt  */
  YYSYMBOL_call_exp = 99,                  /* call_exp  */
  YYSYMBOL_call_args_opt = 100,            /* call_args_opt  */
  YYSYMBOL_call_args_tail = 101,           /* call_args_tail  */
  YYSYMBOL_expression = 102,               /* expression  */
  YYSYMBOL_or_exp = 103,                   /* or_exp  */
  YYSYMBOL_and_exp = 104,                  /* and_exp  */
  YYSYMBOL_not_exp = 105,                  /* not_exp  */
  YYSYMBOL_rel_exp = 106,                  /* rel_exp  */
  YYSYMBOL_add_exp = 107,                  /* add_exp  */
  YYSYMBOL_mult_exp = 108,                 /* mult_exp  */
  YYSYMBOL_exp_exp = 109,                  /* exp_exp  */
  YYSYMBOL_unary_exp = 110,                /* unary_exp  */
  YYSYMBOL_primary_exp = 111,              /* primary_exp  */
  YYSYMBOL_var = 112,                      /* var  */
  YYSYMBOL_ref_var = 113,                  /* ref_var  */
  YYSYMBOL_deref_var = 114,                /* deref_var  */
  YYSYMBOL_literal = 115,                  /* literal  */
  YYSYMBOL_bool_literal = 116,             /* bool_literal  */
  YYSYMBOL_type = 117                      /* type  */
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
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

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
       0,   121,   121,   140,   144,   155,   159,   169,   170,   171,
     175,   220,   247,   252,   262,   274,   298,   303,   317,   322,
     336,   341,   351,   363,   367,   377,   401,   407,   430,   435,
     456,   476,   500,   504,   515,   519,   529,   530,   531,   532,
     533,   537,   555,   576,   593,   597,   606,   621,   654,   659,
     669,   678,   725,   730,   745,   750,   764,   774,   780,   784,
     790,   794,   809,   812,   819,   826,   833,   840,   847,   854,
     859,   865,   871,   875,   881,   887,   891,   897,   901,   915,
     919,   920,   921,   937,   938,   939,   940,   944,   961,  1000,
    1031,  1045,  1061,  1080,  1081,  1082,  1083,  1084,  1088,  1089,
    1093,  1094,  1095,  1096,  1097,  1114,  1125
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
  "decl", "var_decl", "var_init_opt", "proc_decl", "proc_header",
  "opt_param_list", "paramfield_tail", "opt_type", "block",
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

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,     7,    14,    -3,  -149,    24,    35,    49,    64,    37,
      10,  -149,  -149,    75,  -149,   -34,    40,    43,  -149,    24,
    -149,    24,  -149,    17,    26,   117,   118,    10,    10,    72,
      60,  -149,  -149,  -149,  -149,  -149,  -149,   120,    62,    63,
      17,    36,    17,  -149,  -149,    82,    84,  -149,    46,    29,
      33,  -149,    74,  -149,    38,  -149,  -149,  -149,  -149,  -149,
      68,    65,  -149,  -149,  -149,  -149,    90,    70,    77,    78,
      80,    79,    83,  -149,   119,    17,    17,    17,   121,    87,
    -149,  -149,  -149,  -149,  -149,  -149,   -37,   106,    17,  -149,
       9,   146,  -149,  -149,    88,    17,    17,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,   147,    17,
      26,   148,    17,  -149,    26,    91,   117,  -149,    26,  -149,
     118,  -149,  -149,   125,   122,  -149,  -149,  -149,    72,  -149,
      17,    17,    94,    95,  -149,   -50,    98,   -35,  -149,    84,
    -149,    29,    29,    29,    29,    29,    29,    33,    33,  -149,
    -149,  -149,  -149,    93,   100,    96,  -149,  -149,    26,  -149,
      78,  -149,    83,    72,    72,    87,  -149,  -149,  -149,    17,
    -149,  -149,  -149,  -149,  -149,  -149,   123,  -149,  -149,  -149,
     136,   133,  -149,    95,    26,    72,   137,  -149,  -149,  -149,
    -149,  -149
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     0,     0,
       5,     7,     8,     0,     9,     0,     0,     0,     2,     0,
       4,    23,    14,     0,     0,    16,    26,     5,     5,    32,
      87,    93,    94,    95,    98,    99,    97,     0,     0,     0,
       0,     0,     0,    81,    11,    56,    58,    60,    62,    69,
      72,    75,    77,    79,    83,    84,    85,    80,    96,   104,
       0,     0,   100,   101,   102,   103,    12,     0,     0,    18,
       0,     0,    28,     6,     0,     0,     0,    48,     0,    34,
      36,    37,    38,    39,    40,    50,     0,     0,    52,    82,
       0,     0,    61,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,    20,     0,    17,     0,    25,
       0,    27,    24,     0,     0,    47,    49,    22,     0,    33,
       0,     0,     0,    54,    87,     0,     0,     0,    86,    57,
      59,    63,    64,    65,    66,    67,    68,    70,    71,    73,
      74,    76,    88,     0,     0,     0,    13,    31,     0,    15,
      18,    30,    28,    32,    32,    34,    41,    42,    51,     0,
      53,    91,    92,    90,    89,   105,     0,    21,    19,    29,
      44,     0,    35,    54,     0,    32,     0,    46,    55,   106,
      45,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,    89,    57,  -149,  -149,  -149,  -149,  -149,
      11,  -149,  -149,  -149,  -149,  -149,     8,    52,    53,  -148,
      12,    45,  -149,  -149,  -149,  -149,  -149,  -149,  -149,   -25,
    -149,    -9,   -41,  -149,    81,   -31,  -149,    13,    15,   -48,
     134,  -149,   -29,  -149,   -27,  -149,  -149,  -107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    20,    10,    11,   113,    12,    13,    68,
     117,   159,    22,    29,    14,    71,   121,    72,    69,    78,
     129,    79,    80,    81,   186,    82,    83,   125,    84,    43,
     132,   170,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,    94,    87,   154,    85,   130,     1,   157,    23,    92,
       3,   161,   134,   171,     4,   180,   181,   108,   109,     5,
      30,    31,    32,    33,    34,    35,    36,    24,   173,    59,
     108,   109,   108,   109,   123,   124,   126,   190,    15,    30,
      31,    32,    33,    34,    35,    36,    38,   133,     6,     7,
       8,   177,    16,    37,    38,    39,    40,   149,   150,   151,
      18,   135,   137,   136,    60,   140,    61,    17,   153,    41,
      19,   156,    37,    38,    39,    30,    27,   189,    28,    42,
     103,   104,    62,    63,    64,    65,   105,   106,    41,   166,
     167,    97,    98,    99,   100,   101,   102,    21,    42,    86,
      75,    87,    25,    85,    76,   108,   109,    77,    26,    38,
     141,   142,   143,   144,   145,   146,    73,    74,   147,   148,
      67,    70,    88,    89,    90,    91,    95,    96,   183,   107,
     110,   114,   112,   111,    86,    86,    87,    87,    85,    85,
     115,   118,   116,   120,   127,   119,   122,   128,   131,   134,
     152,   138,   158,   155,   163,   164,    86,   168,    87,   169,
      85,   172,   174,   175,   184,   176,   185,   187,   191,   160,
     179,   178,   162,   165,   188,    93,   139,   182
};

static const yytype_uint8 yycheck[] =
{
      29,    42,    29,   110,    29,    42,    21,   114,    42,    40,
       3,   118,     3,    63,     0,   163,   164,    67,    68,    22,
       3,     4,     5,     6,     7,     8,     9,    61,    63,     3,
      67,    68,    67,    68,    75,    76,    77,   185,     3,     3,
       4,     5,     6,     7,     8,     9,    37,    88,    24,    25,
      26,   158,     3,    36,    37,    38,    39,   105,   106,   107,
      23,    90,    91,    90,    38,    96,    40,     3,   109,    52,
      60,   112,    36,    37,    38,     3,    19,   184,    21,    62,
      51,    52,    56,    57,    58,    59,    53,    54,    52,   130,
     131,    45,    46,    47,    48,    49,    50,    22,    62,   128,
      28,   128,    62,   128,    32,    67,    68,    35,    65,    37,
      97,    98,    99,   100,   101,   102,    27,    28,   103,   104,
       3,     3,    62,     3,    62,    62,    44,    43,   169,    55,
      62,    61,    42,    68,   163,   164,   163,   164,   163,   164,
      63,    61,    64,    60,    23,    66,    27,    60,    42,     3,
       3,    63,    61,     5,    29,    33,   185,    63,   185,    64,
     185,    63,    69,    63,    41,    69,    30,    34,    31,   116,
     162,   160,   120,   128,   183,    41,    95,   165
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    71,     3,     0,    22,    24,    25,    26,    72,
      74,    75,    77,    78,    84,     3,     3,     3,    23,    60,
      73,    22,    82,    42,    61,    62,    65,    74,    74,    83,
       3,     4,     5,     6,     7,     8,     9,    36,    37,    38,
      39,    52,    62,    99,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     3,
      38,    40,    56,    57,    58,    59,   117,     3,    79,    88,
       3,    85,    87,    73,    73,    28,    32,    35,    89,    91,
      92,    93,    95,    96,    98,    99,   112,   114,    62,     3,
      62,    62,   105,   110,   102,    44,    43,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    67,    68,
      62,    68,    42,    76,    61,    63,    64,    80,    61,    66,
      60,    86,    27,   102,   102,    97,   102,    23,    60,    90,
      42,    42,   100,   102,     3,   112,   114,   112,    63,   104,
     105,   107,   107,   107,   107,   107,   107,   108,   108,   109,
     109,   109,     3,   102,   117,     5,   102,   117,    61,    81,
      88,   117,    87,    29,    33,    91,   102,   102,    63,    64,
     101,    63,    63,    63,    69,    63,    69,   117,    80,    86,
      89,    89,    90,   102,    41,    30,    94,    34,   101,   117,
      89,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    75,    76,    76,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    83,    83,    84,    85,    85,    86,    86,
      87,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    92,    92,    93,    94,    94,    95,    96,    97,    97,
      98,    99,   100,   100,   101,   101,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   108,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   112,   112,   112,
     113,   114,   114,   115,   115,   115,   115,   115,   116,   116,
     117,   117,   117,   117,   117,   117,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     0,     3,     1,     1,     1,
       5,     4,     0,     2,     2,     6,     0,     2,     0,     3,
       0,     2,     4,     0,     3,     5,     0,     2,     0,     3,
       3,     3,     0,     2,     0,     3,     1,     1,     1,     1,
       1,     3,     3,     6,     0,     2,     5,     2,     0,     1,
       1,     4,     0,     2,     0,     3,     1,     3,     1,     3,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     1,     1,     3,     1,     3,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     6
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
#line 122 "parser.y"
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
#line 140 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1524 "parser.tab.c"
    break;

  case 4: /* opt_decls: decl decl_tail  */
#line 145 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1535 "parser.tab.c"
    break;

  case 5: /* decl_tail: %empty  */
#line 155 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1544 "parser.tab.c"
    break;

  case 6: /* decl_tail: ';' decl decl_tail  */
#line 160 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1555 "parser.tab.c"
    break;

  case 7: /* decl: var_decl  */
#line 169 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1561 "parser.tab.c"
    break;

  case 8: /* decl: proc_decl  */
#line 170 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1567 "parser.tab.c"
    break;

  case 9: /* decl: rec_decl  */
#line 171 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1573 "parser.tab.c"
    break;

  case 10: /* var_decl: VAR NAME ':' type var_init_opt  */
#line 176 "parser.y"
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
#line 221 "parser.y"
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
#line 247 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = true;
        (yyval.t_attr)->type = "void";
    }
#line 1659 "parser.tab.c"
    break;

  case 13: /* var_init_opt: ASSIGN expression  */
#line 253 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 1670 "parser.tab.c"
    break;

  case 14: /* proc_decl: proc_header block  */
#line 263 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
        //SymbolTable::print_all();
    }
#line 1683 "parser.tab.c"
    break;

  case 15: /* proc_header: PROCEDURE NAME '(' opt_param_list ')' opt_type  */
#line 275 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        std::string proc_name = *(yyvsp[-4].sval);
        (yyval.b_attr)->ok = false;

        bool insert_ok = SymbolTable::insert(proc_name, TokenInfo((yyvsp[-2].plist_attr)->param_types_list, (yyvsp[0].t_attr)->type, Tag::PROC));
        SymbolTable::enter_scope(proc_name);

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
#line 1707 "parser.tab.c"
    break;

  case 16: /* opt_param_list: %empty  */
#line 298 "parser.y"
    {
        (yyval.plist_attr) = new ListAttr();
        (yyval.plist_attr)->ok = true;
        (yyval.plist_attr)->param_types_list = std::vector<std::string>();
    }
#line 1717 "parser.tab.c"
    break;

  case 17: /* opt_param_list: paramfield_decl paramfield_tail  */
#line 304 "parser.y"
    {
        (yyval.plist_attr) = (yyvsp[0].plist_attr);
        if ((yyvsp[-1].t_attr)->ok) {
            (yyval.plist_attr)->param_types_list.insert((yyval.plist_attr)->param_types_list.begin(), (yyvsp[-1].t_attr)->type);
        } else {
            (yyval.plist_attr)->ok = false;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 1731 "parser.tab.c"
    break;

  case 18: /* paramfield_tail: %empty  */
#line 317 "parser.y"
    {
        (yyval.plist_attr) = new ListAttr();
        (yyval.plist_attr)->ok = true;
        (yyval.plist_attr)->param_types_list = std::vector<std::string>();
    }
#line 1741 "parser.tab.c"
    break;

  case 19: /* paramfield_tail: ',' paramfield_decl paramfield_tail  */
#line 323 "parser.y"
    {
        (yyval.plist_attr) = (yyvsp[0].plist_attr);
        if ((yyvsp[-1].t_attr)->ok) {
            (yyval.plist_attr)->param_types_list.insert((yyval.plist_attr)->param_types_list.begin(), (yyvsp[-1].t_attr)->type);
        } else {
            (yyval.plist_attr)->ok = false;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 1755 "parser.tab.c"
    break;

  case 20: /* opt_type: %empty  */
#line 336 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = true;
        (yyval.t_attr)->type = "void";
    }
#line 1765 "parser.tab.c"
    break;

  case 21: /* opt_type: ':' type  */
#line 342 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 1776 "parser.tab.c"
    break;

  case 22: /* block: BEGIN_TOK proc_body_opt stmt_list END  */
#line 352 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
        SymbolTable::exit_scope();
    }
#line 1788 "parser.tab.c"
    break;

  case 23: /* proc_body_opt: %empty  */
#line 363 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1797 "parser.tab.c"
    break;

  case 24: /* proc_body_opt: decl decl_tail IN  */
#line 368 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 1808 "parser.tab.c"
    break;

  case 25: /* rec_decl: STRUCT NAME '{' opt_struct_members '}'  */
#line 378 "parser.y"
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
#line 1832 "parser.tab.c"
    break;

  case 26: /* opt_struct_members: %empty  */
#line 401 "parser.y"
    {

        (yyval.map_attr) = new MapAttr();
        (yyval.map_attr)->ok = true;
        (yyval.map_attr)->member_map = std::unordered_map<std::string, std::string>();
    }
#line 1843 "parser.tab.c"
    break;

  case 27: /* opt_struct_members: struct_member_decl struct_member_tail  */
#line 408 "parser.y"
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
#line 1866 "parser.tab.c"
    break;

  case 28: /* struct_member_tail: %empty  */
#line 430 "parser.y"
    {
        (yyval.map_attr) = new MapAttr();
        (yyval.map_attr)->ok = true;
        (yyval.map_attr)->member_map = std::unordered_map<std::string, std::string>();
    }
#line 1876 "parser.tab.c"
    break;

  case 29: /* struct_member_tail: ';' struct_member_decl struct_member_tail  */
#line 436 "parser.y"
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
#line 1898 "parser.tab.c"
    break;

  case 30: /* struct_member_decl: NAME ':' type  */
#line 457 "parser.y"
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
#line 1919 "parser.tab.c"
    break;

  case 31: /* paramfield_decl: NAME ':' type  */
#line 477 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        std::string field_name = *(yyvsp[-2].sval);
        if((yyval.t_attr)->type != "ERR") {
            bool insert_ok = SymbolTable::insert(field_name, TokenInfo({}, (yyvsp[0].t_attr)->type, Tag::PROC_PARAM));
            
            if (!insert_ok) {
                print_token_location((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                std::cout << "Erro: Parâmetro '" << field_name << "' já foi declarado." << std::endl;
                (yyval.t_attr)->ok = false;
                (yyval.t_attr)->type = "ERR";
            }
            
        }
        delete (yyvsp[-2].sval);
        delete (yyvsp[0].t_attr);
    }
#line 1943 "parser.tab.c"
    break;

  case 32: /* stmt_list: %empty  */
#line 500 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1952 "parser.tab.c"
    break;

  case 33: /* stmt_list: stmt stmt_tail  */
#line 505 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1963 "parser.tab.c"
    break;

  case 34: /* stmt_tail: %empty  */
#line 515 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1972 "parser.tab.c"
    break;

  case 35: /* stmt_tail: ';' stmt stmt_tail  */
#line 520 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1983 "parser.tab.c"
    break;

  case 36: /* stmt: assign_stmt  */
#line 529 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1989 "parser.tab.c"
    break;

  case 37: /* stmt: if_stmt  */
#line 530 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1995 "parser.tab.c"
    break;

  case 38: /* stmt: while_stmt  */
#line 531 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 2001 "parser.tab.c"
    break;

  case 39: /* stmt: return_stmt  */
#line 532 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].t_attr)->ok; delete (yyvsp[0].t_attr); }
#line 2007 "parser.tab.c"
    break;

  case 40: /* stmt: call_stmt  */
#line 533 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 2013 "parser.tab.c"
    break;

  case 41: /* assign_stmt: var ASSIGN expression  */
#line 538 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        
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
#line 2035 "parser.tab.c"
    break;

  case 42: /* assign_stmt: deref_var ASSIGN expression  */
#line 556 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        
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
#line 2057 "parser.tab.c"
    break;

  case 43: /* if_stmt: IF expression THEN stmt_list else_opt FI  */
#line 577 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-4].t_attr)->ok && (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        if ((yyvsp[-4].t_attr)->type != "ERR" && (yyvsp[-4].t_attr)->type != "BOOL") {
            print_token_location((yylsp[-4]).first_line, (yylsp[-4]).first_column);
            std::cout << "Erro de tipo: Condição do IF deve ser BOOL, mas foi '" << (yyvsp[-4].t_attr)->type << "'." << std::endl;
            (yyval.b_attr)->ok = false;
        }
        delete (yyvsp[-4].t_attr);
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 2074 "parser.tab.c"
    break;

  case 44: /* else_opt: %empty  */
#line 593 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 2083 "parser.tab.c"
    break;

  case 45: /* else_opt: ELSE stmt_list  */
#line 598 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok;
        delete (yyvsp[0].b_attr);
    }
#line 2093 "parser.tab.c"
    break;

  case 46: /* while_stmt: WHILE expression DO stmt_list OD  */
#line 607 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-3].t_attr)->ok && (yyvsp[-1].b_attr)->ok;
        if ((yyvsp[-3].t_attr)->type != "ERR" && (yyvsp[-3].t_attr)->type != "BOOL") {
            print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
            std::cout << "Erro de tipo: Condição do WHILE deve ser BOOL, mas foi '" << (yyvsp[-3].t_attr)->type << "'." << std::endl;
            (yyval.b_attr)->ok = false;
        }
        delete (yyvsp[-3].t_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 2109 "parser.tab.c"
    break;

  case 47: /* return_stmt: RETURN return_exp_opt  */
#line 622 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = "ERR";

        if((yyval.t_attr)->ok) {
            std::string scope_name = SymbolTable::get_scope_name();
            auto lookup_result = SymbolTable::lookup(scope_name);
            if (!lookup_result || lookup_result->tag != Tag::PROC) {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro: 'RETURN' usado fora de um procedimento/função." << std::endl;
                (yyval.t_attr)->ok = false;
            } else {
                
                if((yyvsp[0].t_attr)->type == lookup_result->type || 
                ((yyvsp[0].t_attr)->type == "void" && lookup_result->type == "void")) {
                    (yyval.t_attr)->type = lookup_result->type;
                } else {
                    print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                    std::cout << "Erro de tipo: 'RETURN' espera tipo '" << lookup_result->type 
                            << "', mas recebeu '" << (yyvsp[0].t_attr)->type << "'." << std::endl;
                    (yyval.t_attr)->ok = false;
                }
            }
        }

        delete (yyvsp[0].t_attr);
    }
#line 2142 "parser.tab.c"
    break;

  case 48: /* return_exp_opt: %empty  */
#line 654 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = true;
        (yyval.t_attr)->type = "void";
    }
#line 2152 "parser.tab.c"
    break;

  case 49: /* return_exp_opt: expression  */
#line 660 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2163 "parser.tab.c"
    break;

  case 50: /* call_stmt: call_exp  */
#line 670 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[0].t_attr)->ok;
        delete (yyvsp[0].t_attr);
    }
#line 2173 "parser.tab.c"
    break;

  case 51: /* call_exp: NAME '(' call_args_opt ')'  */
#line 679 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].plist_attr)->ok;
        (yyval.t_attr)->type = "ERR";
        std::string func_name = *(yyvsp[-3].sval);

        auto lookup_result = SymbolTable::lookup(func_name);
        if (!lookup_result || lookup_result->tag != Tag::PROC) {
            print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
            std::cout << "Erro: Função ou procedimento '" << func_name << "' não declarado." << std::endl;
            (yyval.t_attr)->ok = false;
        } else if((yyval.t_attr)->ok) {
            const auto& declared_params = lookup_result->paramList;
            const auto& provided_args = (yyvsp[-1].plist_attr)->param_types_list;

            if (declared_params.size() != provided_args.size()) {
                print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                std::cout << "Erro: Função '" << func_name << "' espera " << declared_params.size() 
                          << " argumentos, mas recebeu " << provided_args.size() << "." << std::endl;
                (yyval.t_attr)->ok = false;
            } else {
                bool types_match = true;
                for (size_t i = 0; i < declared_params.size(); ++i) {
                    if (!check_compatible(declared_params[i], provided_args[i])) {
                        print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        std::cout << "Erro: Incompatibilidade de tipo no argumento " << i + 1 
                                  << " da chamada para '" << func_name << "'. Esperado '" 
                                  << declared_params[i] << "', mas recebeu '" << provided_args[i] << "'." << std::endl;
                        types_match = false;
                        (yyval.t_attr)->ok = false;
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
#line 2220 "parser.tab.c"
    break;

  case 52: /* call_args_opt: %empty  */
#line 725 "parser.y"
    {
        (yyval.plist_attr) = new ListAttr();
        (yyval.plist_attr)->ok = true;
        (yyval.plist_attr)->param_types_list = std::vector<std::string>();
    }
#line 2230 "parser.tab.c"
    break;

  case 53: /* call_args_opt: expression call_args_tail  */
#line 731 "parser.y"
    {
        (yyval.plist_attr) = (yyvsp[0].plist_attr);
        if ((yyvsp[-1].t_attr)->ok) {
            (yyval.plist_attr)->param_types_list.insert((yyval.plist_attr)->param_types_list.begin(), (yyvsp[-1].t_attr)->type);
        }
        else {
            (yyval.plist_attr)->ok = false;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2245 "parser.tab.c"
    break;

  case 54: /* call_args_tail: %empty  */
#line 745 "parser.y"
    {
        (yyval.plist_attr) = new ListAttr();
        (yyval.plist_attr)->ok = true;
        (yyval.plist_attr)->param_types_list = std::vector<std::string>();
    }
#line 2255 "parser.tab.c"
    break;

  case 55: /* call_args_tail: ',' expression call_args_tail  */
#line 751 "parser.y"
    {
        (yyval.plist_attr) = (yyvsp[0].plist_attr);
        if ((yyvsp[-1].t_attr)->ok) {
            (yyval.plist_attr)->param_types_list.insert((yyval.plist_attr)->param_types_list.begin(), (yyvsp[-1].t_attr)->type);
        }
        else {
            (yyval.plist_attr)->ok = false;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2270 "parser.tab.c"
    break;

  case 56: /* expression: or_exp  */
#line 765 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2281 "parser.tab.c"
    break;

  case 57: /* or_exp: or_exp OR and_exp  */
#line 775 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "OR", 
            [](const auto& t1, const auto& t2) { return t1 == "BOOL" && t2 == "BOOL"; },
            [](const auto& t1, const auto& t2) { return "BOOL"; });
    }
#line 2291 "parser.tab.c"
    break;

  case 58: /* or_exp: and_exp  */
#line 780 "parser.y"
              { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2297 "parser.tab.c"
    break;

  case 59: /* and_exp: and_exp AND not_exp  */
#line 785 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "AND",
            [](const auto& t1, const auto& t2) { return t1 == "BOOL" && t2 == "BOOL"; },
            [](const auto& t1, const auto& t2) { return "BOOL"; });
    }
#line 2307 "parser.tab.c"
    break;

  case 60: /* and_exp: not_exp  */
#line 790 "parser.y"
              { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2313 "parser.tab.c"
    break;

  case 61: /* not_exp: NOT not_exp  */
#line 795 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && (yyvsp[0].t_attr)->type == "BOOL") {
            (yyval.t_attr)->type = "BOOL";
        } else {
            print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
            std::cout << "Erro de tipo: Operando de NOT deve ser BOOLEAN." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[0].t_attr);
    }
#line 2332 "parser.tab.c"
    break;

  case 62: /* not_exp: rel_exp  */
#line 809 "parser.y"
              { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2338 "parser.tab.c"
    break;

  case 63: /* rel_exp: rel_exp LT add_exp  */
#line 812 "parser.y"
                            {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "<",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2350 "parser.tab.c"
    break;

  case 64: /* rel_exp: rel_exp LE add_exp  */
#line 819 "parser.y"
                     {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "<=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2362 "parser.tab.c"
    break;

  case 65: /* rel_exp: rel_exp GT add_exp  */
#line 826 "parser.y"
                    {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), ">",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2374 "parser.tab.c"
    break;

  case 66: /* rel_exp: rel_exp GE add_exp  */
#line 833 "parser.y"
                     {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), ">=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2386 "parser.tab.c"
    break;

  case 67: /* rel_exp: rel_exp EQ add_exp  */
#line 840 "parser.y"
                     {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "=",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2398 "parser.tab.c"
    break;

  case 68: /* rel_exp: rel_exp NE add_exp  */
#line 847 "parser.y"
                     {
    handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "<>",
        [](const auto& t1, const auto& t2) { 
            return (is_numeric(t1) && is_numeric(t2)) || (t1 == t2); 
        },
        [](const auto& t1, const auto& t2) { return "BOOL"; });
}
#line 2410 "parser.tab.c"
    break;

  case 69: /* rel_exp: add_exp  */
#line 854 "parser.y"
          { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2416 "parser.tab.c"
    break;

  case 70: /* add_exp: add_exp PLUS mult_exp  */
#line 860 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "+",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            resolve_arithmetic_type);
    }
#line 2426 "parser.tab.c"
    break;

  case 71: /* add_exp: add_exp MINUS mult_exp  */
#line 866 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "-",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            resolve_arithmetic_type);
    }
#line 2436 "parser.tab.c"
    break;

  case 72: /* add_exp: mult_exp  */
#line 871 "parser.y"
               { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2442 "parser.tab.c"
    break;

  case 73: /* mult_exp: mult_exp MULT exp_exp  */
#line 876 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "*", 
        [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); }, 
        resolve_arithmetic_type);
    }
#line 2452 "parser.tab.c"
    break;

  case 74: /* mult_exp: mult_exp DIV exp_exp  */
#line 882 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "/", 
        [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); }, 
        resolve_arithmetic_type);
    }
#line 2462 "parser.tab.c"
    break;

  case 75: /* mult_exp: exp_exp  */
#line 887 "parser.y"
              { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2468 "parser.tab.c"
    break;

  case 76: /* exp_exp: unary_exp EXP_OP exp_exp  */
#line 892 "parser.y"
    {
        handle_binary_op((yyval.t_attr), (yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].t_attr), (yyvsp[0].t_attr), "^",
            [](const auto& t1, const auto& t2) { return is_numeric(t1) && is_numeric(t2); },
            [](const auto& t1, const auto& t2) { return "FLOAT"; });
    }
#line 2478 "parser.tab.c"
    break;

  case 77: /* exp_exp: unary_exp  */
#line 897 "parser.y"
                { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2484 "parser.tab.c"
    break;

  case 78: /* unary_exp: MINUS unary_exp  */
#line 902 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = "ERR";
        if ((yyval.t_attr)->ok && ((yyvsp[0].t_attr)->type == "INT" || (yyvsp[0].t_attr)->type == "FLOAT")) {
            (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        } else {
            print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
            std::cout << "Erro de tipo: Operando unário '-' deve ser numérico." << std::endl;
            (yyval.t_attr)->ok = false;
        }
        delete (yyvsp[0].t_attr);
    }
#line 2502 "parser.tab.c"
    break;

  case 79: /* unary_exp: primary_exp  */
#line 915 "parser.y"
                  { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2508 "parser.tab.c"
    break;

  case 80: /* primary_exp: literal  */
#line 919 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2514 "parser.tab.c"
    break;

  case 81: /* primary_exp: call_exp  */
#line 920 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2520 "parser.tab.c"
    break;

  case 82: /* primary_exp: NEW NAME  */
#line 922 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string type_name = *(yyvsp[0].sval);
        auto lookup_result = SymbolTable::lookup(type_name);
        if (!lookup_result || lookup_result->tag != Tag::STRUCT) {
            print_token_location((yylsp[0]).first_line, (yylsp[0]).first_column);
            std::cout << "Erro: Tipo '" << type_name << "' não é um struct para 'NEW'." << std::endl;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        } else {
            (yyval.t_attr)->ok = true;
            (yyval.t_attr)->type =  type_name ;
        }
        delete (yyvsp[0].sval);
    }
#line 2540 "parser.tab.c"
    break;

  case 83: /* primary_exp: var  */
#line 937 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2546 "parser.tab.c"
    break;

  case 84: /* primary_exp: ref_var  */
#line 938 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2552 "parser.tab.c"
    break;

  case 85: /* primary_exp: deref_var  */
#line 939 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2558 "parser.tab.c"
    break;

  case 86: /* primary_exp: '(' expression ')'  */
#line 940 "parser.y"
                        { (yyval.t_attr) = (yyvsp[-1].t_attr); }
#line 2564 "parser.tab.c"
    break;

  case 87: /* var: NAME  */
#line 945 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string var_base_name = *(yyvsp[0].sval);
        delete (yyvsp[0].sval);

        auto lookup_result = SymbolTable::lookup(var_base_name);
        if (!lookup_result || (lookup_result->tag != Tag::VAR && lookup_result->tag != Tag::PROC_PARAM)) {
            print_token_location((yylsp[0]).first_line, (yylsp[0]).first_column);
            std::cout << "Erro: Variável '" << var_base_name << "' não declarada." << std::endl;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        } else {
            (yyval.t_attr)->ok = true;
            (yyval.t_attr)->type = lookup_result->type;
        }
    }
#line 2585 "parser.tab.c"
    break;

  case 88: /* var: var '.' NAME  */
#line 962 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok;
        (yyval.t_attr)->type = "ERR";

        if ((yyval.t_attr)->ok) {
            std::string base_type_name = (yyvsp[-2].t_attr)->type;
            std::string field_name = *(yyvsp[0].sval);

            auto base_type_info_opt = SymbolTable::lookup(base_type_name);

            if (!base_type_info_opt || base_type_info_opt->tag != Tag::STRUCT) {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro de tipo: Tentativa de acessar o campo '" << field_name 
                        << "' em um tipo não-struct ('" << base_type_name << "')." << std::endl;
                (yyval.t_attr)->ok = false;
            } else {
                auto& base_type_info = *base_type_info_opt;

                const auto& members_map = base_type_info.members;
                auto member_iterator = members_map.find(field_name);

                if (member_iterator == members_map.end()) {
                    print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                    std::cout << "Erro de tipo: O tipo '" << base_type_name 
                            << "' não possui um membro chamado '" << field_name << "'." << std::endl;
                    (yyval.t_attr)->ok = false;
                } else {
                    (yyval.t_attr)->ok = true;
                    (yyval.t_attr)->type = member_iterator->second;
                }
            }
        }
        
        // Limpa a memória do atributo da variável.
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].sval);
    }
#line 2628 "parser.tab.c"
    break;

  case 89: /* var: var '[' expression ']'  */
#line 1001 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-3].t_attr)->ok && (yyvsp[-1].t_attr)->ok;
        (yyval.t_attr)->type = "ERR";

        if ((yyval.t_attr)->ok) {
            std::string base_type = (yyvsp[-3].t_attr)->type;
            std::string index_type = (yyvsp[-1].t_attr)->type;

            if (index_type != "INT") {
                print_token_location((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                std::cout << "Erro de tipo: O índice de um array deve ser um inteiro, mas foi '" << index_type << "'." << std::endl;
                (yyval.t_attr)->ok = false;
            }
            else {
                if (base_type.rfind("ARRAY(", 0) == 0) {
                    (yyval.t_attr)->type = base_type.substr(6, base_type.length() - 7);
                } else {
                    print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                    std::cout << "Erro de tipo: Tentativa de indexar um tipo não-array ('" << base_type << "')." << std::endl;
                    (yyval.t_attr)->ok = false;
                }
            }
        }
        delete (yyvsp[-3].t_attr);
        delete (yyvsp[-1].t_attr);
    }
#line 2660 "parser.tab.c"
    break;

  case 90: /* ref_var: REF '(' var ')'  */
#line 1032 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok;
        if ((yyval.t_attr)->ok) {
            (yyval.t_attr)->type = "REF(" + (yyvsp[-1].t_attr)->type + ")";
        } else {
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2675 "parser.tab.c"
    break;

  case 91: /* deref_var: DEREF '(' var ')'  */
#line 1046 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok;
        if((yyval.t_attr)->ok) {
            if ((yyvsp[-1].t_attr)->type.rfind("REF(", 0) == 0) {
                (yyval.t_attr)->type = (yyvsp[-1].t_attr)->type.substr(4, (yyvsp[-1].t_attr)->type.length() - 5);
            } else {
                print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                std::cout << "Erro de tipo: DEREF exige um tipo de referência." << std::endl;
                (yyval.t_attr)->ok = false;
                (yyval.t_attr)->type = "ERR";
            }
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2695 "parser.tab.c"
    break;

  case 92: /* deref_var: DEREF '(' deref_var ')'  */
#line 1062 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok;
        if((yyval.t_attr)->ok) {
            if ((yyvsp[-1].t_attr)->type.rfind("REF(", 0) == 0) {
                (yyval.t_attr)->type = (yyvsp[-1].t_attr)->type.substr(4, (yyvsp[-1].t_attr)->type.length() - 5);
            } else {
                print_token_location((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                std::cout << "Erro de tipo: DEREF exige um tipo de referência (cascata)." << std::endl;
                (yyval.t_attr)->ok = false;
                (yyval.t_attr)->type = "ERR";
            }
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2715 "parser.tab.c"
    break;

  case 93: /* literal: FLOAT_LITERAL  */
#line 1080 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "FLOAT"; delete (yyvsp[0].sval); }
#line 2721 "parser.tab.c"
    break;

  case 94: /* literal: INT_LITERAL  */
#line 1081 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "INT"; delete (yyvsp[0].sval); }
#line 2727 "parser.tab.c"
    break;

  case 95: /* literal: STRING_LITERAL  */
#line 1082 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "STRING"; delete (yyvsp[0].sval); }
#line 2733 "parser.tab.c"
    break;

  case 96: /* literal: bool_literal  */
#line 1083 "parser.y"
                      { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2739 "parser.tab.c"
    break;

  case 97: /* literal: NULL_LIT  */
#line 1084 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "NULL"; }
#line 2745 "parser.tab.c"
    break;

  case 98: /* bool_literal: TRUE  */
#line 1088 "parser.y"
            { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "BOOL"; }
#line 2751 "parser.tab.c"
    break;

  case 99: /* bool_literal: FALSE  */
#line 1089 "parser.y"
            { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "BOOL"; }
#line 2757 "parser.tab.c"
    break;

  case 100: /* type: FLOAT_T  */
#line 1093 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "FLOAT"; }
#line 2763 "parser.tab.c"
    break;

  case 101: /* type: INT_T  */
#line 1094 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "INT"; }
#line 2769 "parser.tab.c"
    break;

  case 102: /* type: STRING_T  */
#line 1095 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "STRING"; }
#line 2775 "parser.tab.c"
    break;

  case 103: /* type: BOOL_T  */
#line 1096 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "BOOL"; }
#line 2781 "parser.tab.c"
    break;

  case 104: /* type: NAME  */
#line 1098 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string type_name = *(yyvsp[0].sval);
        auto lookup_result = SymbolTable::lookup(type_name);
        
        if (lookup_result && lookup_result->tag == Tag::STRUCT) {
            (yyval.t_attr)->ok = true;
            (yyval.t_attr)->type = lookup_result->type;
        } else {
            print_token_location((yylsp[0]).first_line, (yylsp[0]).first_column);
            std::cout << "Erro: '" << type_name << "' não é um tipo válido ou struct declarado." << std::endl;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[0].sval);
    }
#line 2802 "parser.tab.c"
    break;

  case 105: /* type: REF '(' type ')'  */
#line 1115 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok;
        if ((yyval.t_attr)->ok) {
            (yyval.t_attr)->type = "REF(" + (yyvsp[-1].t_attr)->type + ")";
        } else {
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2817 "parser.tab.c"
    break;

  case 106: /* type: ARRAY '[' INT_LITERAL ']' OF type  */
#line 1126 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok) {
            (yyval.t_attr)->type = "ARRAY(" + (yyvsp[0].t_attr)->type + ")";
        } else {
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-3].sval);
        delete (yyvsp[0].t_attr);
    }
#line 2833 "parser.tab.c"
    break;


#line 2837 "parser.tab.c"

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

#line 1139 "parser.y"


void yyerror(const char *s) {
    extern int yylineno;
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}

int main(void) {
    SymbolTable::enter_scope("global");
    yyparse();
    
    std::cout << "\n--- Conteúdo Final da Tabela de Símbolos ---" << std::endl;
    SymbolTable::print_all();
    SymbolTable::exit_scope();
    
    return 0;
}
