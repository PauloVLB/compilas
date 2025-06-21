/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NAME = 258,                    /* NAME  */
    FLOAT_LITERAL = 259,           /* FLOAT_LITERAL  */
    INT_LITERAL = 260,             /* INT_LITERAL  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    TRUE = 262,                    /* TRUE  */
    FALSE = 263,                   /* FALSE  */
    NULL_LIT = 264,                /* NULL_LIT  */
    LPAREN = 265,                  /* LPAREN  */
    RPAREN = 266,                  /* RPAREN  */
    SEMICOLON = 267,               /* SEMICOLON  */
    LBRACKET = 268,                /* LBRACKET  */
    RBRACKET = 269,                /* RBRACKET  */
    LBRACE = 270,                  /* LBRACE  */
    RBRACE = 271,                  /* RBRACE  */
    COLON = 272,                   /* COLON  */
    DOT = 273,                     /* DOT  */
    COMMA = 274,                   /* COMMA  */
    CARET = 275,                   /* CARET  */
    PROGRAM = 276,                 /* PROGRAM  */
    BEGIN_TOK = 277,               /* BEGIN_TOK  */
    END = 278,                     /* END  */
    VAR = 279,                     /* VAR  */
    PROCEDURE = 280,               /* PROCEDURE  */
    STRUCT = 281,                  /* STRUCT  */
    IN = 282,                      /* IN  */
    IF = 283,                      /* IF  */
    THEN = 284,                    /* THEN  */
    ELSE = 285,                    /* ELSE  */
    FI = 286,                      /* FI  */
    WHILE = 287,                   /* WHILE  */
    DO = 288,                      /* DO  */
    OD = 289,                      /* OD  */
    RETURN = 290,                  /* RETURN  */
    NEW = 291,                     /* NEW  */
    DEREF = 292,                   /* DEREF  */
    REF = 293,                     /* REF  */
    NOT = 294,                     /* NOT  */
    ARRAY = 295,                   /* ARRAY  */
    OF = 296,                      /* OF  */
    ASSIGN = 297,                  /* ASSIGN  */
    AND = 298,                     /* AND  */
    OR = 299,                      /* OR  */
    LT = 300,                      /* LT  */
    LE = 301,                      /* LE  */
    GT = 302,                      /* GT  */
    GE = 303,                      /* GE  */
    EQ = 304,                      /* EQ  */
    NE = 305,                      /* NE  */
    PLUS = 306,                    /* PLUS  */
    MINUS = 307,                   /* MINUS  */
    MULT = 308,                    /* MULT  */
    DIV = 309,                     /* DIV  */
    EXP_OP = 310,                  /* EXP_OP  */
    FLOAT_T = 311,                 /* FLOAT_T  */
    INT_T = 312,                   /* INT_T  */
    STRING_T = 313,                /* STRING_T  */
    BOOL_T = 314                   /* BOOL_T  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parser.y"

    std::string* sval;
    BoolAttr* b_attr;
    TypedAttr* t_attr;
    std::vector<std::string>* param_types_list;

#line 130 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
