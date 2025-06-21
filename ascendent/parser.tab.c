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
#line 5 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <iostream>
#include <vector>
#include <optional>
#include "types/attrs.hpp"
#include "symbol_table/symbol_table.hpp"

extern int yylex();
void yyerror(const char *s);

#line 86 "parser.tab.c"

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
  YYSYMBOL_M_proc_scope_enter = 77,        /* M_proc_scope_enter  */
  YYSYMBOL_proc_decl = 78,                 /* proc_decl  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

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
       0,    63,    63,    82,    86,    97,   101,   111,   112,   113,
     117,   139,   144,   155,   163,   188,   191,   205,   208,   222,
     227,   237,   249,   253,   263,   289,   292,   309,   312,   328,
     347,   369,   373,   384,   388,   398,   399,   400,   401,   402,
     406,   430,   454,   472,   476,   485,   501,   512,   517,   527,
     536,   558,   563,   575,   580,   591,   601,   616,   626,   641,
     651,   665,   674,   688,   702,   716,   730,   744,   758,   769,
     784,   799,   809,   824,   839,   849,   864,   874,   888,   898,
     899,   900,   916,   917,   918,   919,   923,   940,   979,  1011,
    1025,  1039,  1056,  1057,  1058,  1059,  1060,  1064,  1065,  1069,
    1070,  1071,  1072,  1073,  1090,  1101
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
  "decl", "var_decl", "var_init_opt", "M_proc_scope_enter", "proc_decl",
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

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,    26,    13,    12,  -148,     0,    51,    62,    72,    56,
      43,  -148,  -148,  -148,    21,  -148,    40,  -148,     0,  -148,
      71,    48,   109,    43,  -148,    55,    45,  -148,  -148,  -148,
    -148,    76,   116,    59,    57,    64,  -148,    71,   117,    14,
    -148,    77,    74,    61,    71,  -148,   109,  -148,    78,    70,
      80,  -148,  -148,  -148,  -148,  -148,  -148,   137,    81,    82,
      14,    52,    14,  -148,  -148,   101,   103,  -148,    22,   -36,
       9,  -148,    92,  -148,    10,  -148,  -148,  -148,  -148,    71,
      87,   116,  -148,  -148,    64,  -148,   108,    14,  -148,     6,
     147,  -148,  -148,    88,    14,    14,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,   149,    14,  -148,
      71,   131,    61,  -148,    71,    91,    93,  -148,    18,    95,
      39,  -148,   103,  -148,   -36,   -36,   -36,   -36,   -36,   -36,
       9,     9,  -148,  -148,  -148,  -148,    86,  -148,     0,  -148,
    -148,  -148,  -148,    14,  -148,  -148,  -148,  -148,  -148,    43,
       7,    93,   129,    14,    14,    14,   136,   100,  -148,  -148,
    -148,  -148,  -148,  -148,   -31,   119,  -148,  -148,   133,   130,
    -148,  -148,  -148,     7,  -148,    14,    14,     7,     7,   100,
    -148,  -148,   134,   132,  -148,     7,   138,  -148,  -148,  -148
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     0,     0,
       5,     7,     8,     9,     0,    13,     0,     2,     0,     4,
       0,     0,    25,     5,   103,     0,     0,    99,   100,   101,
     102,    11,    15,     0,     0,    27,     6,     0,     0,     0,
      10,     0,     0,    17,     0,    24,     0,    26,     0,     0,
      86,    92,    93,    94,    97,    98,    96,     0,     0,     0,
       0,     0,     0,    80,    12,    55,    57,    59,    61,    68,
      71,    74,    76,    78,    82,    83,    84,    79,    95,     0,
      19,     0,    16,    29,    27,   104,     0,    51,    81,     0,
       0,    60,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,    17,    28,     0,     0,    53,    86,     0,     0,
       0,    85,    56,    58,    62,    63,    64,    65,    66,    67,
      69,    70,    72,    73,    75,    87,     0,    20,    22,    14,
      18,   105,    50,     0,    52,    90,    91,    89,    88,     5,
      31,    53,     0,     0,     0,    47,     0,    33,    35,    36,
      37,    38,    39,    49,     0,     0,    54,    23,     0,     0,
      46,    48,    21,     0,    32,     0,     0,    31,    31,    33,
      40,    41,    43,     0,    34,    31,     0,    45,    44,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,   -23,   -17,  -148,  -148,  -148,  -148,  -148,
      53,  -148,  -148,  -148,  -148,  -148,    83,   122,    89,  -147,
      -8,    -1,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -145,
    -148,    23,   -60,  -148,    79,   -54,  -148,    35,    -5,   -59,
     114,  -148,   -86,  -148,   -77,  -148,  -148,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    19,    10,    11,    40,    21,    12,    42,
      82,   111,   139,   150,    13,    34,    47,    35,    43,   156,
     174,   157,   158,   159,   186,   160,   161,   170,   162,    63,
     115,   144,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    23,    93,   118,   120,   163,    91,    48,     1,   117,
      50,   175,   119,     4,    83,   102,   103,    50,    51,    52,
      53,    54,    55,    56,     6,     7,     8,   116,   163,     3,
     182,   183,   163,   163,     5,   153,   107,   108,   188,   154,
     163,   123,   155,    58,    58,   132,   133,   134,   136,   109,
      57,    58,    59,    60,    14,    50,    51,    52,    53,    54,
      55,    56,   104,   105,   164,    15,    61,    96,    97,    98,
      99,   100,   101,   165,    24,    16,    62,   107,   108,    17,
     137,   145,    20,   151,   141,   107,   108,   164,    57,    58,
      59,   164,   164,   168,   169,   171,   165,   130,   131,   164,
     165,   165,   147,    18,    61,    22,   107,   108,   165,    25,
      32,    26,    33,    38,    62,   180,   181,    37,    39,    41,
      44,   149,    49,    45,    46,    81,   152,    27,    28,    29,
      30,   124,   125,   126,   127,   128,   129,    80,    79,    86,
      88,    85,    87,    89,    90,    94,    95,   106,   110,   114,
     117,   121,   135,   138,   142,   148,   167,   143,   146,   172,
     173,   176,   177,   178,   185,   140,   187,   113,    84,   189,
     112,   184,   179,   122,   166,    92
};

static const yytype_uint8 yycheck[] =
{
      23,    18,    62,    89,    90,   150,    60,    37,    21,     3,
       3,    42,    89,     0,    44,    51,    52,     3,     4,     5,
       6,     7,     8,     9,    24,    25,    26,    87,   173,     3,
     177,   178,   177,   178,    22,    28,    67,    68,   185,    32,
     185,    95,    35,    37,    37,   104,   105,   106,   108,    79,
      36,    37,    38,    39,     3,     3,     4,     5,     6,     7,
       8,     9,    53,    54,   150,     3,    52,    45,    46,    47,
      48,    49,    50,   150,     3,     3,    62,    67,    68,    23,
     110,    63,    61,   143,   114,    67,    68,   173,    36,    37,
      38,   177,   178,   153,   154,   155,   173,   102,   103,   185,
     177,   178,    63,    60,    52,    65,    67,    68,   185,    38,
      62,    40,     3,    68,    62,   175,   176,    62,    42,     3,
      61,   138,     5,    66,    60,    64,   149,    56,    57,    58,
      59,    96,    97,    98,    99,   100,   101,    63,    61,    69,
       3,    63,    62,    62,    62,    44,    43,    55,    61,    41,
       3,    63,     3,    22,    63,    69,    27,    64,    63,    23,
      60,    42,    29,    33,    30,   112,    34,    84,    46,    31,
      81,   179,   173,    94,   151,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    71,     3,     0,    22,    24,    25,    26,    72,
      74,    75,    78,    84,     3,     3,     3,    23,    60,    73,
      61,    77,    65,    74,     3,    38,    40,    56,    57,    58,
      59,   117,    62,     3,    85,    87,    73,    62,    68,    42,
      76,     3,    79,    88,    61,    66,    60,    86,   117,     5,
       3,     4,     5,     6,     7,     8,     9,    36,    37,    38,
      39,    52,    62,    99,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    61,
      63,    64,    80,   117,    87,    63,    69,    62,     3,    62,
      62,   105,   110,   102,    44,    43,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    67,    68,   117,
      61,    81,    88,    86,    41,   100,   102,     3,   112,   114,
     112,    63,   104,   105,   107,   107,   107,   107,   107,   107,
     108,   108,   109,   109,   109,     3,   102,   117,    22,    82,
      80,   117,    63,    64,   101,    63,    63,    63,    69,    74,
      83,   102,    73,    28,    32,    35,    89,    91,    92,    93,
      95,    96,    98,    99,   112,   114,   101,    27,   102,   102,
      97,   102,    23,    60,    90,    42,    42,    29,    33,    91,
     102,   102,    89,    89,    90,    30,    94,    34,    89,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    76,    76,    77,    78,    79,    79,    80,    80,    81,
      81,    82,    83,    83,    84,    85,    85,    86,    86,    87,
      88,    89,    89,    90,    90,    91,    91,    91,    91,    91,
      92,    92,    93,    94,    94,    95,    96,    97,    97,    98,
      99,   100,   100,   101,   101,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   113,
     114,   114,   115,   115,   115,   115,   115,   116,   116,   117,
     117,   117,   117,   117,   117,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     0,     3,     1,     1,     1,
       5,     0,     2,     0,     8,     0,     2,     0,     3,     0,
       2,     4,     0,     3,     5,     0,     2,     0,     3,     3,
       3,     0,     2,     0,     3,     1,     1,     1,     1,     1,
       3,     3,     6,     0,     2,     5,     2,     0,     1,     1,
       4,     0,     2,     0,     3,     1,     3,     1,     3,     1,
       2,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     1,     1,     3,     1,     3,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     6
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PROGRAM NAME BEGIN_TOK opt_decls END  */
#line 64 "parser.y"
    {
        std::string program_name = *(yyvsp[-3].sval);
        delete (yyvsp[-3].sval);
        
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok;
        
        if ((yyval.b_attr)->ok) {
            printf("Análise sintática concluída com sucesso para o programa '%s'!\n", program_name.c_str());
        } else {
            printf("Análise sintática encerrada devido a erro no programa '%s'.\n", program_name.c_str());
        }
        delete (yyvsp[-1].b_attr);
    }
#line 1339 "parser.tab.c"
    break;

  case 3: /* opt_decls: %empty  */
#line 82 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1348 "parser.tab.c"
    break;

  case 4: /* opt_decls: decl decl_tail  */
#line 87 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1359 "parser.tab.c"
    break;

  case 5: /* decl_tail: %empty  */
#line 97 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1368 "parser.tab.c"
    break;

  case 6: /* decl_tail: ';' decl decl_tail  */
#line 102 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1379 "parser.tab.c"
    break;

  case 7: /* decl: var_decl  */
#line 111 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1385 "parser.tab.c"
    break;

  case 8: /* decl: proc_decl  */
#line 112 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1391 "parser.tab.c"
    break;

  case 9: /* decl: rec_decl  */
#line 113 "parser.y"
                { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1397 "parser.tab.c"
    break;

  case 10: /* var_decl: VAR NAME ':' type var_init_opt  */
#line 118 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        std::string var_name = *(yyvsp[-3].sval);
        bool insert_ok = SymbolTable::insert(var_name, TokenInfo({}, (yyvsp[-1].t_attr)->type, Tag::VAR));
        
        if (!insert_ok) {
            std::cout << "Erro: Variável '" << var_name << "' já declarada." << std::endl;
            YYABORT;
            (yyval.b_attr)->ok = false;
        } else {
            (yyval.b_attr)->ok = (yyvsp[-1].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        }
        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].t_attr);
        delete (yyvsp[0].t_attr);
        SymbolTable::print_all();
    }
#line 1419 "parser.tab.c"
    break;

  case 11: /* var_init_opt: %empty  */
#line 139 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = true;
        (yyval.t_attr)->type = "void";
    }
#line 1429 "parser.tab.c"
    break;

  case 12: /* var_init_opt: ASSIGN expression  */
#line 145 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 1440 "parser.tab.c"
    break;

  case 13: /* M_proc_scope_enter: %empty  */
#line 155 "parser.y"
    {
        SymbolTable::enter_scope();
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1450 "parser.tab.c"
    break;

  case 14: /* proc_decl: PROCEDURE NAME M_proc_scope_enter '(' opt_param_list ')' opt_type block  */
#line 164 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        std::string proc_name = *(yyvsp[-6].sval);
        bool insert_ok = SymbolTable::insert(proc_name, TokenInfo(*(yyvsp[-3].param_types_list), (yyvsp[-1].t_attr)->type, Tag::PROC));
        
        if (!insert_ok) {
            std::cout << "Erro: Redefinição do procedimento '" << proc_name << "'." << std::endl;
            YYABORT;
            (yyval.b_attr)->ok = false;
        } else {
            (yyval.b_attr)->ok = (yyvsp[-5].b_attr)->ok && (yyvsp[-1].t_attr)->ok && (yyvsp[0].b_attr)->ok;
        }
        
        delete (yyvsp[-6].sval);
        delete (yyvsp[-5].b_attr);
        delete (yyvsp[-3].param_types_list);
        delete (yyvsp[-1].t_attr);
        delete (yyvsp[0].b_attr);
        SymbolTable::print_all();
    }
#line 1475 "parser.tab.c"
    break;

  case 15: /* opt_param_list: %empty  */
#line 188 "parser.y"
    {
        (yyval.param_types_list) = new std::vector<std::string>();
    }
#line 1483 "parser.tab.c"
    break;

  case 16: /* opt_param_list: paramfield_decl paramfield_tail  */
#line 192 "parser.y"
    {
        (yyval.param_types_list) = (yyvsp[0].param_types_list);
        if ((yyvsp[-1].t_attr)->ok) {
            (yyval.param_types_list)->insert((yyval.param_types_list)->begin(), (yyvsp[-1].t_attr)->type);
        } else {
            (yyval.param_types_list)->clear();
        }
        delete (yyvsp[-1].t_attr);
    }
#line 1497 "parser.tab.c"
    break;

  case 17: /* paramfield_tail: %empty  */
#line 205 "parser.y"
    {
        (yyval.param_types_list) = new std::vector<std::string>();
    }
#line 1505 "parser.tab.c"
    break;

  case 18: /* paramfield_tail: ',' paramfield_decl paramfield_tail  */
#line 209 "parser.y"
    {
        (yyval.param_types_list) = (yyvsp[0].param_types_list);
        if ((yyvsp[-1].t_attr)->ok) {
            (yyval.param_types_list)->insert((yyval.param_types_list)->begin(), (yyvsp[-1].t_attr)->type);
        } else {
            (yyval.param_types_list)->clear();
        }
        delete (yyvsp[-1].t_attr);
    }
#line 1519 "parser.tab.c"
    break;

  case 19: /* opt_type: %empty  */
#line 222 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = true;
        (yyval.t_attr)->type = "void";
    }
#line 1529 "parser.tab.c"
    break;

  case 20: /* opt_type: ':' type  */
#line 228 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 1540 "parser.tab.c"
    break;

  case 21: /* block: BEGIN_TOK proc_body_opt stmt_list END  */
#line 238 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
        SymbolTable::exit_scope();
    }
#line 1552 "parser.tab.c"
    break;

  case 22: /* proc_body_opt: %empty  */
#line 249 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1561 "parser.tab.c"
    break;

  case 23: /* proc_body_opt: decl decl_tail IN  */
#line 254 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 1572 "parser.tab.c"
    break;

  case 24: /* rec_decl: STRUCT NAME '{' opt_struct_members '}'  */
#line 264 "parser.y"
    {
        std::string struct_name = *(yyvsp[-3].sval);

        if (SymbolTable::exists_in_current_scope(struct_name)) {
             std::cout << "Erro: Redefinição do tipo '" << struct_name << "'." << std::endl;
             YYABORT;
        }

        bool insert_ok = SymbolTable::insert(struct_name, TokenInfo({}, struct_name, Tag::STRUCT, *(yyvsp[-1].member_map)));
        
        if (!insert_ok) {
            std::cout << "Erro: Struct '" << struct_name << "' já declarado." << std::endl;
            YYABORT;
        }
        
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;

        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].member_map);
    }
#line 1598 "parser.tab.c"
    break;

  case 25: /* opt_struct_members: %empty  */
#line 289 "parser.y"
    {
        (yyval.member_map) = new std::unordered_map<std::string, std::string>();
    }
#line 1606 "parser.tab.c"
    break;

  case 26: /* opt_struct_members: struct_member_decl struct_member_tail  */
#line 293 "parser.y"
    {
        (yyval.member_map) = (yyvsp[0].member_map);
        auto& first_member_map = *(yyvsp[-1].member_map);
        const auto& [name, type] = *first_member_map.begin();

        if ((yyval.member_map)->count(name) > 0) {
            std::cout << "Erro: Membro da struct '" << name << "' já foi declarado." << std::endl;
            YYABORT;
        }
        (*(yyval.member_map))[name] = type;
        delete (yyvsp[-1].member_map);
    }
#line 1623 "parser.tab.c"
    break;

  case 27: /* struct_member_tail: %empty  */
#line 309 "parser.y"
    {
        (yyval.member_map) = new std::unordered_map<std::string, std::string>();
    }
#line 1631 "parser.tab.c"
    break;

  case 28: /* struct_member_tail: ';' struct_member_decl struct_member_tail  */
#line 313 "parser.y"
    {
        (yyval.member_map) = (yyvsp[0].member_map);
        auto& new_member_map = *(yyvsp[-1].member_map);
        const auto& [name, type] = *new_member_map.begin();

        if ((yyval.member_map)->count(name) > 0) {
            std::cout << "Erro: Membro da struct '" << name << "' já foi declarado." << std::endl;
            YYABORT;
        }
        (*(yyval.member_map))[name] = type;
        delete (yyvsp[-1].member_map);
    }
#line 1648 "parser.tab.c"
    break;

  case 29: /* struct_member_decl: NAME ':' type  */
#line 329 "parser.y"
    {
        (yyval.member_map) = new std::unordered_map<std::string, std::string>();
        
        if (!(yyvsp[0].t_attr)->ok) {
            std::cout << "Erro: Tipo '" << (yyvsp[0].t_attr)->type << "' inválido para membro de struct." << std::endl;
            YYABORT;
        }

        std::string member_name = *(yyvsp[-2].sval);
        std::string member_type = (yyvsp[0].t_attr)->type;
        (*(yyval.member_map))[member_name] = member_type;

        delete (yyvsp[-2].sval);
        delete (yyvsp[0].t_attr);
    }
#line 1668 "parser.tab.c"
    break;

  case 30: /* paramfield_decl: NAME ':' type  */
#line 348 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string field_name = *(yyvsp[-2].sval);
        bool insert_ok = SymbolTable::insert(field_name, TokenInfo({}, (yyvsp[0].t_attr)->type, Tag::PROC_PARAM));
        
        if (!insert_ok) {
            std::cout << "Erro: Parâmetro '" << field_name << "' já foi declarado." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
        } else {
            (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        }
        
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[-2].sval);
        delete (yyvsp[0].t_attr);
    }
#line 1690 "parser.tab.c"
    break;

  case 31: /* stmt_list: %empty  */
#line 369 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1699 "parser.tab.c"
    break;

  case 32: /* stmt_list: stmt stmt_tail  */
#line 374 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1710 "parser.tab.c"
    break;

  case 33: /* stmt_tail: %empty  */
#line 384 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1719 "parser.tab.c"
    break;

  case 34: /* stmt_tail: ';' stmt stmt_tail  */
#line 389 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[-1].b_attr)->ok && (yyvsp[0].b_attr)->ok;
        delete (yyvsp[-1].b_attr);
        delete (yyvsp[0].b_attr);
    }
#line 1730 "parser.tab.c"
    break;

  case 35: /* stmt: assign_stmt  */
#line 398 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1736 "parser.tab.c"
    break;

  case 36: /* stmt: if_stmt  */
#line 399 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1742 "parser.tab.c"
    break;

  case 37: /* stmt: while_stmt  */
#line 400 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1748 "parser.tab.c"
    break;

  case 38: /* stmt: return_stmt  */
#line 401 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].t_attr)->ok; delete (yyvsp[0].t_attr); }
#line 1754 "parser.tab.c"
    break;

  case 39: /* stmt: call_stmt  */
#line 402 "parser.y"
                  { (yyval.b_attr) = new BoolAttr(); (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok; delete (yyvsp[0].b_attr); }
#line 1760 "parser.tab.c"
    break;

  case 40: /* assign_stmt: var ASSIGN expression  */
#line 407 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        
        if (!(yyvsp[-2].t_attr)->ok || !(yyvsp[0].t_attr)->ok) {
            (yyval.b_attr)->ok = false;
        } else {
            bool is_compatible = ((yyvsp[-2].t_attr)->type == (yyvsp[0].t_attr)->type) || 
                                 ((yyvsp[0].t_attr)->type == "NULL" && (yyvsp[-2].t_attr)->type.rfind("REF(", 0) == 0);

            if (!is_compatible) {
                std::cout << "Erro de Tipo: Incompatibilidade na atribuição. "
                          << "Não é possível atribuir uma expressão do tipo '" << (yyvsp[0].t_attr)->type
                          << "' a uma variável do tipo '" << (yyvsp[-2].t_attr)->type << "'." << std::endl;
                YYABORT;
                (yyval.b_attr)->ok = false;
            } else {
                (yyval.b_attr)->ok = true;
            }
        }

        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 1788 "parser.tab.c"
    break;

  case 41: /* assign_stmt: deref_var ASSIGN expression  */
#line 431 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        
        if (!(yyvsp[-2].t_attr)->ok || !(yyvsp[0].t_attr)->ok) {
            (yyval.b_attr)->ok = false;
        } else {
            if ((yyvsp[-2].t_attr)->type != (yyvsp[0].t_attr)->type) {
                std::cout << "Erro de Tipo: Incompatibilidade na atribuição. "
                          << "Não é possível atribuir uma expressão do tipo '" << (yyvsp[0].t_attr)->type
                          << "' a uma variável do tipo '" << (yyvsp[-2].t_attr)->type << "'." << std::endl;
                YYABORT;
                (yyval.b_attr)->ok = false;
            } else {
                (yyval.b_attr)->ok = true;
            }
        }

        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 1813 "parser.tab.c"
    break;

  case 42: /* if_stmt: IF expression THEN stmt_list else_opt FI  */
#line 455 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        if ((yyvsp[-4].t_attr)->type != "BOOL") {
            std::cout << "Erro de tipo: Condição do IF deve ser BOOL, mas foi '" << (yyvsp[-4].t_attr)->type << "'." << std::endl;
            YYABORT;
            (yyval.b_attr)->ok = false;
        } else {
            (yyval.b_attr)->ok = (yyvsp[-4].t_attr)->ok && (yyvsp[-2].b_attr)->ok && (yyvsp[-1].b_attr)->ok;
        }
        delete (yyvsp[-4].t_attr);
        delete (yyvsp[-2].b_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 1831 "parser.tab.c"
    break;

  case 43: /* else_opt: %empty  */
#line 472 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = true;
    }
#line 1840 "parser.tab.c"
    break;

  case 44: /* else_opt: ELSE stmt_list  */
#line 477 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[0].b_attr)->ok;
        delete (yyvsp[0].b_attr);
    }
#line 1850 "parser.tab.c"
    break;

  case 45: /* while_stmt: WHILE expression DO stmt_list OD  */
#line 486 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        if ((yyvsp[-3].t_attr)->type != "BOOL") {
            std::cout << "Erro de tipo: Condição do WHILE deve ser BOOL, mas foi '" << (yyvsp[-3].t_attr)->type << "'." << std::endl;
            YYABORT;
            (yyval.b_attr)->ok = false;
        } else {
            (yyval.b_attr)->ok = (yyvsp[-3].t_attr)->ok && (yyvsp[-1].b_attr)->ok;
        }
        delete (yyvsp[-3].t_attr);
        delete (yyvsp[-1].b_attr);
    }
#line 1867 "parser.tab.c"
    break;

  case 46: /* return_stmt: RETURN return_exp_opt  */
#line 502 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 1878 "parser.tab.c"
    break;

  case 47: /* return_exp_opt: %empty  */
#line 512 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = true;
        (yyval.t_attr)->type = "void";
    }
#line 1888 "parser.tab.c"
    break;

  case 48: /* return_exp_opt: expression  */
#line 518 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 1899 "parser.tab.c"
    break;

  case 49: /* call_stmt: call_exp  */
#line 528 "parser.y"
    {
        (yyval.b_attr) = new BoolAttr();
        (yyval.b_attr)->ok = (yyvsp[0].t_attr)->ok;
        delete (yyvsp[0].t_attr);
    }
#line 1909 "parser.tab.c"
    break;

  case 50: /* call_exp: NAME '(' call_args_opt ')'  */
#line 537 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string func_name = *(yyvsp[-3].sval);
        delete (yyvsp[-3].sval);

        auto lookup_result = SymbolTable::lookup(func_name);
        if (!lookup_result || lookup_result->tag != Tag::PROC) {
            std::cout << "Erro: Função ou procedimento '" << func_name << "' não declarado." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        } else {
            (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok;
            (yyval.t_attr)->type = lookup_result->type;
        }
        delete (yyvsp[-1].t_attr);
    }
#line 1931 "parser.tab.c"
    break;

  case 51: /* call_args_opt: %empty  */
#line 558 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = true;
        (yyval.t_attr)->type = "void";
    }
#line 1941 "parser.tab.c"
    break;

  case 52: /* call_args_opt: expression call_args_tail  */
#line 564 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = "void";
        delete (yyvsp[-1].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 1953 "parser.tab.c"
    break;

  case 53: /* call_args_tail: %empty  */
#line 575 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = true;
        (yyval.t_attr)->type = "void";
    }
#line 1963 "parser.tab.c"
    break;

  case 54: /* call_args_tail: ',' expression call_args_tail  */
#line 581 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = "void";
        delete (yyvsp[-1].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 1975 "parser.tab.c"
    break;

  case 55: /* expression: or_exp  */
#line 592 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 1986 "parser.tab.c"
    break;

  case 56: /* or_exp: or_exp OR and_exp  */
#line 602 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && (yyvsp[-2].t_attr)->type == "BOOL" && (yyvsp[0].t_attr)->type == "BOOL") {
            (yyval.t_attr)->type = "BOOL";
        } else {
            std::cout << "Erro de tipo: Operandos de OR devem ser BOOLEAN." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2005 "parser.tab.c"
    break;

  case 57: /* or_exp: and_exp  */
#line 617 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2016 "parser.tab.c"
    break;

  case 58: /* and_exp: and_exp AND not_exp  */
#line 627 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && (yyvsp[-2].t_attr)->type == "BOOL" && (yyvsp[0].t_attr)->type == "BOOL") {
            (yyval.t_attr)->type = "BOOL";
        } else {
            std::cout << "Erro de tipo: Operandos de AND devem ser BOOLEAN." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2035 "parser.tab.c"
    break;

  case 59: /* and_exp: not_exp  */
#line 642 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2046 "parser.tab.c"
    break;

  case 60: /* not_exp: NOT not_exp  */
#line 652 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && (yyvsp[0].t_attr)->type == "BOOL") {
            (yyval.t_attr)->type = "BOOL";
        } else {
            std::cout << "Erro de tipo: Operando de NOT deve ser BOOLEAN." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[0].t_attr);
    }
#line 2064 "parser.tab.c"
    break;

  case 61: /* not_exp: rel_exp  */
#line 666 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2075 "parser.tab.c"
    break;

  case 62: /* rel_exp: rel_exp LT add_exp  */
#line 674 "parser.y"
                            {
  (yyval.t_attr) = new TypedAttr();
  (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
  if ((yyval.t_attr)->ok && (yyvsp[-2].t_attr)->type == (yyvsp[0].t_attr)->type) {
    (yyval.t_attr)->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    (yyval.t_attr)->ok = false;
    (yyval.t_attr)->type = "ERR";
  }
  delete (yyvsp[-2].t_attr);
  delete (yyvsp[0].t_attr);
}
#line 2094 "parser.tab.c"
    break;

  case 63: /* rel_exp: rel_exp LE add_exp  */
#line 688 "parser.y"
                     {
  (yyval.t_attr) = new TypedAttr();
  (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
  if ((yyval.t_attr)->ok && (yyvsp[-2].t_attr)->type == (yyvsp[0].t_attr)->type) {
    (yyval.t_attr)->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    (yyval.t_attr)->ok = false;
    (yyval.t_attr)->type = "ERR";
  }
  delete (yyvsp[-2].t_attr);
  delete (yyvsp[0].t_attr);
}
#line 2113 "parser.tab.c"
    break;

  case 64: /* rel_exp: rel_exp GT add_exp  */
#line 702 "parser.y"
                    {
  (yyval.t_attr) = new TypedAttr();
  (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
  if ((yyval.t_attr)->ok && (yyvsp[-2].t_attr)->type == (yyvsp[0].t_attr)->type) {
    (yyval.t_attr)->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    (yyval.t_attr)->ok = false;
    (yyval.t_attr)->type = "ERR";
  }
  delete (yyvsp[-2].t_attr);
  delete (yyvsp[0].t_attr);
}
#line 2132 "parser.tab.c"
    break;

  case 65: /* rel_exp: rel_exp GE add_exp  */
#line 716 "parser.y"
                     {
  (yyval.t_attr) = new TypedAttr();
  (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
  if ((yyval.t_attr)->ok && (yyvsp[-2].t_attr)->type == (yyvsp[0].t_attr)->type) {
    (yyval.t_attr)->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    (yyval.t_attr)->ok = false;
    (yyval.t_attr)->type = "ERR";
  }
  delete (yyvsp[-2].t_attr);
  delete (yyvsp[0].t_attr);
}
#line 2151 "parser.tab.c"
    break;

  case 66: /* rel_exp: rel_exp EQ add_exp  */
#line 730 "parser.y"
                     {
  (yyval.t_attr) = new TypedAttr();
  (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
  if ((yyval.t_attr)->ok && (yyvsp[-2].t_attr)->type == (yyvsp[0].t_attr)->type) {
    (yyval.t_attr)->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    (yyval.t_attr)->ok = false;
    (yyval.t_attr)->type = "ERR";
  }
  delete (yyvsp[-2].t_attr);
  delete (yyvsp[0].t_attr);
}
#line 2170 "parser.tab.c"
    break;

  case 67: /* rel_exp: rel_exp NE add_exp  */
#line 744 "parser.y"
                     {
  (yyval.t_attr) = new TypedAttr();
  (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
  if ((yyval.t_attr)->ok && (yyvsp[-2].t_attr)->type == (yyvsp[0].t_attr)->type) {
    (yyval.t_attr)->type = "BOOL";
  } else {
    std::cout << "Erro de tipo: Operandos de comparação incompatíveis." << std::endl;
    YYABORT;
    (yyval.t_attr)->ok = false;
    (yyval.t_attr)->type = "ERR";
  }
  delete (yyvsp[-2].t_attr);
  delete (yyvsp[0].t_attr);
}
#line 2189 "parser.tab.c"
    break;

  case 68: /* rel_exp: add_exp  */
#line 758 "parser.y"
          {
  (yyval.t_attr) = new TypedAttr();
 
  (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
  (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
  delete (yyvsp[0].t_attr);
}
#line 2201 "parser.tab.c"
    break;

  case 69: /* add_exp: add_exp PLUS mult_exp  */
#line 770 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && ((yyvsp[-2].t_attr)->type == "INT" || (yyvsp[-2].t_attr)->type == "FLOAT") && ((yyvsp[0].t_attr)->type == "INT" || (yyvsp[0].t_attr)->type == "FLOAT")) {
            (yyval.t_attr)->type = ((yyvsp[-2].t_attr)->type == "FLOAT" || (yyvsp[0].t_attr)->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de adição/subtração devem ser numéricos." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2220 "parser.tab.c"
    break;

  case 70: /* add_exp: add_exp MINUS mult_exp  */
#line 785 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && ((yyvsp[-2].t_attr)->type == "INT" || (yyvsp[-2].t_attr)->type == "FLOAT") && ((yyvsp[0].t_attr)->type == "INT" || (yyvsp[0].t_attr)->type == "FLOAT")) {
            (yyval.t_attr)->type = ((yyvsp[-2].t_attr)->type == "FLOAT" || (yyvsp[0].t_attr)->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de adição/subtração devem ser numéricos." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2239 "parser.tab.c"
    break;

  case 71: /* add_exp: mult_exp  */
#line 800 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2250 "parser.tab.c"
    break;

  case 72: /* mult_exp: mult_exp MULT exp_exp  */
#line 810 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && ((yyvsp[-2].t_attr)->type == "INT" || (yyvsp[-2].t_attr)->type == "FLOAT") && ((yyvsp[0].t_attr)->type == "INT" || (yyvsp[0].t_attr)->type == "FLOAT")) {
            (yyval.t_attr)->type = ((yyvsp[-2].t_attr)->type == "FLOAT" || (yyvsp[0].t_attr)->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de multiplicação/divisão devem ser numéricos." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2269 "parser.tab.c"
    break;

  case 73: /* mult_exp: mult_exp DIV exp_exp  */
#line 825 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && ((yyvsp[-2].t_attr)->type == "INT" || (yyvsp[-2].t_attr)->type == "FLOAT") && ((yyvsp[0].t_attr)->type == "INT" || (yyvsp[0].t_attr)->type == "FLOAT")) {
            (yyval.t_attr)->type = ((yyvsp[-2].t_attr)->type == "FLOAT" || (yyvsp[0].t_attr)->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de multiplicação/divisão devem ser numéricos." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2288 "parser.tab.c"
    break;

  case 74: /* mult_exp: exp_exp  */
#line 840 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2299 "parser.tab.c"
    break;

  case 75: /* exp_exp: unary_exp EXP_OP exp_exp  */
#line 850 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok && (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && ((yyvsp[-2].t_attr)->type == "INT" || (yyvsp[-2].t_attr)->type == "FLOAT") && ((yyvsp[0].t_attr)->type == "INT" || (yyvsp[0].t_attr)->type == "FLOAT")) {
            (yyval.t_attr)->type = ((yyvsp[-2].t_attr)->type == "FLOAT" || (yyvsp[0].t_attr)->type == "FLOAT") ? "FLOAT" : "INT";
        } else {
            std::cout << "Erro de tipo: Operandos de exponenciação devem ser numéricos." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-2].t_attr);
        delete (yyvsp[0].t_attr);
    }
#line 2318 "parser.tab.c"
    break;

  case 76: /* exp_exp: unary_exp  */
#line 865 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2329 "parser.tab.c"
    break;

  case 77: /* unary_exp: MINUS unary_exp  */
#line 875 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        if ((yyval.t_attr)->ok && ((yyvsp[0].t_attr)->type == "INT" || (yyvsp[0].t_attr)->type == "FLOAT")) {
            (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        } else {
            std::cout << "Erro de tipo: Operando unário '-' deve ser numérico." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[0].t_attr);
    }
#line 2347 "parser.tab.c"
    break;

  case 78: /* unary_exp: primary_exp  */
#line 889 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[0].t_attr)->ok;
        (yyval.t_attr)->type = (yyvsp[0].t_attr)->type;
        delete (yyvsp[0].t_attr);
    }
#line 2358 "parser.tab.c"
    break;

  case 79: /* primary_exp: literal  */
#line 898 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2364 "parser.tab.c"
    break;

  case 80: /* primary_exp: call_exp  */
#line 899 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2370 "parser.tab.c"
    break;

  case 81: /* primary_exp: NEW NAME  */
#line 901 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string type_name = *(yyvsp[0].sval);
        auto lookup_result = SymbolTable::lookup(type_name);
        if (!lookup_result || lookup_result->tag != Tag::STRUCT) {
            std::cout << "Erro: Tipo '" << type_name << "' não é um struct para 'NEW'." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        } else {
            (yyval.t_attr)->ok = true;
            (yyval.t_attr)->type =  type_name ;
        }
        delete (yyvsp[0].sval);
    }
#line 2390 "parser.tab.c"
    break;

  case 82: /* primary_exp: var  */
#line 916 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2396 "parser.tab.c"
    break;

  case 83: /* primary_exp: ref_var  */
#line 917 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2402 "parser.tab.c"
    break;

  case 84: /* primary_exp: deref_var  */
#line 918 "parser.y"
                        { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2408 "parser.tab.c"
    break;

  case 85: /* primary_exp: '(' expression ')'  */
#line 919 "parser.y"
                        { (yyval.t_attr) = (yyvsp[-1].t_attr); }
#line 2414 "parser.tab.c"
    break;

  case 86: /* var: NAME  */
#line 924 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string var_base_name = *(yyvsp[0].sval);
        delete (yyvsp[0].sval);

        auto lookup_result = SymbolTable::lookup(var_base_name);
        if (!lookup_result || (lookup_result->tag != Tag::VAR && lookup_result->tag != Tag::PROC_PARAM)) {
            std::cout << "Erro: Variável '" << var_base_name << "' não declarada." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        } else {
            (yyval.t_attr)->ok = true;
            (yyval.t_attr)->type = lookup_result->type;
        }
    }
#line 2435 "parser.tab.c"
    break;

  case 87: /* var: var '.' NAME  */
#line 941 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-2].t_attr)->ok;
        (yyval.t_attr)->type = "ERR";

        if ((yyval.t_attr)->ok) {
            std::string base_type_name = (yyvsp[-2].t_attr)->type; // ex: "Point"
            std::string field_name = *(yyvsp[0].sval);
            delete (yyvsp[0].sval);

            auto base_type_info_opt = SymbolTable::lookup(base_type_name);

            if (!base_type_info_opt || base_type_info_opt->tag != Tag::STRUCT) {
                std::cout << "Erro de tipo: Tentativa de acessar o campo '" << field_name 
                        << "' em um tipo não-struct ('" << base_type_name << "')." << std::endl;
                YYABORT;
                (yyval.t_attr)->ok = false;
            } else {
                auto& base_type_info = *base_type_info_opt;

                const auto& members_map = base_type_info.members;
                auto member_iterator = members_map.find(field_name);

                if (member_iterator == members_map.end()) {
                    std::cout << "Erro de tipo: O tipo '" << base_type_name 
                            << "' não possui um membro chamado '" << field_name << "'." << std::endl;
                    YYABORT;
                    (yyval.t_attr)->ok = false;
                } else {
                    (yyval.t_attr)->ok = true;
                    (yyval.t_attr)->type = member_iterator->second;
                }
            }
        }
        
        // Limpa a memória do atributo da variável.
        delete (yyvsp[-2].t_attr);
    }
#line 2478 "parser.tab.c"
    break;

  case 88: /* var: var '[' expression ']'  */
#line 980 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-3].t_attr)->ok && (yyvsp[-1].t_attr)->ok;
        (yyval.t_attr)->type = "ERR";

        if ((yyval.t_attr)->ok) {
            std::string base_type = (yyvsp[-3].t_attr)->type;
            std::string index_type = (yyvsp[-1].t_attr)->type;

            if (index_type != "INT") {
                std::cout << "Erro de tipo: O índice de um array deve ser um inteiro, mas foi '" << index_type << "'." << std::endl;
                YYABORT;
                (yyval.t_attr)->ok = false;
            }

            if ((yyval.t_attr)->ok) {
                if (base_type.rfind("ARRAY(", 0) == 0) {
                    (yyval.t_attr)->type = base_type.substr(6, base_type.length() - 7);
                } else {
                    std::cout << "Erro de tipo: Tentativa de indexar um tipo não-array ('" << base_type << "')." << std::endl;
                    YYABORT;
                    (yyval.t_attr)->ok = false;
                }
            }
        }
        delete (yyvsp[-3].t_attr);
        delete (yyvsp[-1].t_attr);
    }
#line 2511 "parser.tab.c"
    break;

  case 89: /* ref_var: REF '(' var ')'  */
#line 1012 "parser.y"
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
#line 2526 "parser.tab.c"
    break;

  case 90: /* deref_var: DEREF '(' var ')'  */
#line 1026 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok;
        if ((yyval.t_attr)->ok && (yyvsp[-1].t_attr)->type.rfind("REF(", 0) == 0) {
            (yyval.t_attr)->type = (yyvsp[-1].t_attr)->type.substr(4, (yyvsp[-1].t_attr)->type.length() - 5);
        } else {
            std::cout << "Erro de tipo: DEREF exige um tipo de referência." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2544 "parser.tab.c"
    break;

  case 91: /* deref_var: DEREF '(' deref_var ')'  */
#line 1040 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        (yyval.t_attr)->ok = (yyvsp[-1].t_attr)->ok;
        if ((yyval.t_attr)->ok && (yyvsp[-1].t_attr)->type.rfind("REF(", 0) == 0) {
            (yyval.t_attr)->type = (yyvsp[-1].t_attr)->type.substr(4, (yyvsp[-1].t_attr)->type.length() - 5);
        } else {
            std::cout << "Erro de tipo: DEREF exige um tipo de referência (cascata)." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[-1].t_attr);
    }
#line 2562 "parser.tab.c"
    break;

  case 92: /* literal: FLOAT_LITERAL  */
#line 1056 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "FLOAT"; delete (yyvsp[0].sval); }
#line 2568 "parser.tab.c"
    break;

  case 93: /* literal: INT_LITERAL  */
#line 1057 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "INT"; delete (yyvsp[0].sval); }
#line 2574 "parser.tab.c"
    break;

  case 94: /* literal: STRING_LITERAL  */
#line 1058 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "STRING"; delete (yyvsp[0].sval); }
#line 2580 "parser.tab.c"
    break;

  case 95: /* literal: bool_literal  */
#line 1059 "parser.y"
                      { (yyval.t_attr) = (yyvsp[0].t_attr); }
#line 2586 "parser.tab.c"
    break;

  case 96: /* literal: NULL_LIT  */
#line 1060 "parser.y"
                      { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "NULL"; }
#line 2592 "parser.tab.c"
    break;

  case 97: /* bool_literal: TRUE  */
#line 1064 "parser.y"
            { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "BOOL"; }
#line 2598 "parser.tab.c"
    break;

  case 98: /* bool_literal: FALSE  */
#line 1065 "parser.y"
            { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "BOOL"; }
#line 2604 "parser.tab.c"
    break;

  case 99: /* type: FLOAT_T  */
#line 1069 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "FLOAT"; }
#line 2610 "parser.tab.c"
    break;

  case 100: /* type: INT_T  */
#line 1070 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "INT"; }
#line 2616 "parser.tab.c"
    break;

  case 101: /* type: STRING_T  */
#line 1071 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "STRING"; }
#line 2622 "parser.tab.c"
    break;

  case 102: /* type: BOOL_T  */
#line 1072 "parser.y"
                { (yyval.t_attr) = new TypedAttr(); (yyval.t_attr)->ok = true; (yyval.t_attr)->type = "BOOL"; }
#line 2628 "parser.tab.c"
    break;

  case 103: /* type: NAME  */
#line 1074 "parser.y"
    {
        (yyval.t_attr) = new TypedAttr();
        std::string type_name = *(yyvsp[0].sval);
        auto lookup_result = SymbolTable::lookup(type_name);
        
        if (lookup_result && lookup_result->tag == Tag::STRUCT) {
            (yyval.t_attr)->ok = true;
            (yyval.t_attr)->type = lookup_result->type;
        } else {
            std::cout << "Erro: '" << type_name << "' não é um tipo válido ou struct declarado." << std::endl;
            YYABORT;
            (yyval.t_attr)->ok = false;
            (yyval.t_attr)->type = "ERR";
        }
        delete (yyvsp[0].sval);
    }
#line 2649 "parser.tab.c"
    break;

  case 104: /* type: REF '(' type ')'  */
#line 1091 "parser.y"
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
#line 2664 "parser.tab.c"
    break;

  case 105: /* type: ARRAY '[' INT_LITERAL ']' OF type  */
#line 1102 "parser.y"
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
#line 2680 "parser.tab.c"
    break;


#line 2684 "parser.tab.c"

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1115 "parser.y"


void yyerror(const char *s) {
    extern int yylineno;
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}

int main(void) {
    SymbolTable::enter_scope();
    yyparse();
    
    std::cout << "\n--- Conteúdo Final da Tabela de Símbolos ---" << std::endl;
    SymbolTable::print_all();
    SymbolTable::exit_scope();
    
    return 0;
}
