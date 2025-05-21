/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NAME = 258,
    FLOAT_LITERAL = 259,
    INT_LITERAL = 260,
    STRING_LITERAL = 261,
    TRUE = 262,
    FALSE = 263,
    NULL_LIT = 264,
    PROGRAM = 265,
    BEGIN = 266,
    END = 267,
    VAR = 268,
    PROCEDURE = 269,
    STRUCT = 270,
    IN = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    FI = 275,
    WHILE = 276,
    DO = 277,
    OD = 278,
    RETURN = 279,
    NEW = 280,
    DEREF = 281,
    REF = 282,
    NOT = 283,
    ASSIGN = 284,
    AND = 285,
    OR = 286,
    LT = 287,
    LE = 288,
    GT = 289,
    GE = 290,
    EQ = 291,
    NE = 292,
    PLUS = 293,
    MINUS = 294,
    MULT = 295,
    DIV = 296,
    EXP_OP = 297,
    FLOAT_T = 298,
    INT_T = 299,
    STRING_T = 300,
    BOOL_T = 301
  };
#endif
/* Tokens.  */
#define NAME 258
#define FLOAT_LITERAL 259
#define INT_LITERAL 260
#define STRING_LITERAL 261
#define TRUE 262
#define FALSE 263
#define NULL_LIT 264
#define PROGRAM 265
#define BEGIN 266
#define END 267
#define VAR 268
#define PROCEDURE 269
#define STRUCT 270
#define IN 271
#define IF 272
#define THEN 273
#define ELSE 274
#define FI 275
#define WHILE 276
#define DO 277
#define OD 278
#define RETURN 279
#define NEW 280
#define DEREF 281
#define REF 282
#define NOT 283
#define ASSIGN 284
#define AND 285
#define OR 286
#define LT 287
#define LE 288
#define GT 289
#define GE 290
#define EQ 291
#define NE 292
#define PLUS 293
#define MINUS 294
#define MULT 295
#define DIV 296
#define EXP_OP 297
#define FLOAT_T 298
#define INT_T 299
#define STRING_T 300
#define BOOL_T 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "parser.y"

    char* str;

#line 153 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
