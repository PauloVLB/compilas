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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    PROGRAM = 265,                 /* PROGRAM  */
    BEGIN_TOK = 266,               /* BEGIN_TOK  */
    END = 267,                     /* END  */
    VAR = 268,                     /* VAR  */
    PROCEDURE = 269,               /* PROCEDURE  */
    STRUCT = 270,                  /* STRUCT  */
    IN = 271,                      /* IN  */
    IF = 272,                      /* IF  */
    THEN = 273,                    /* THEN  */
    ELSE = 274,                    /* ELSE  */
    FI = 275,                      /* FI  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    OD = 278,                      /* OD  */
    RETURN = 279,                  /* RETURN  */
    NEW = 280,                     /* NEW  */
    DEREF = 281,                   /* DEREF  */
    REF = 282,                     /* REF  */
    NOT = 283,                     /* NOT  */
    ARRAY = 284,                   /* ARRAY  */
    OF = 285,                      /* OF  */
    ASSIGN = 286,                  /* ASSIGN  */
    AND = 287,                     /* AND  */
    OR = 288,                      /* OR  */
    LT = 289,                      /* LT  */
    LE = 290,                      /* LE  */
    GT = 291,                      /* GT  */
    GE = 292,                      /* GE  */
    EQ = 293,                      /* EQ  */
    NE = 294,                      /* NE  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    MULT = 297,                    /* MULT  */
    DIV = 298,                     /* DIV  */
    EXP_OP = 299,                  /* EXP_OP  */
    FLOAT_T = 300,                 /* FLOAT_T  */
    INT_T = 301,                   /* INT_T  */
    STRING_T = 302,                /* STRING_T  */
    BOOL_T = 303                   /* BOOL_T  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "parser.y"

    char* str;

#line 116 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
