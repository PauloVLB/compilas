// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 7 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>

#include "types/attrs.hpp"
#include "symbol_table/symbol_table.hpp"

void yyerror(const char *s);
int yylex(void);
std::vector<std::unordered_map<std::string, TokenInfo>> SymbolTable::scopes;


#line 56 "parser.cpp"


#include "parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 134 "parser.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_decls: // opt_decls
      case symbol_kind::S_decl_tail: // decl_tail
      case symbol_kind::S_decl: // decl
      case symbol_kind::S_var_decl: // var_decl
      case symbol_kind::S_proc_decl: // proc_decl
      case symbol_kind::S_rec_decl: // rec_decl
        value.YY_MOVE_OR_COPY< BoolAttr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_init_opt: // var_init_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< TypedAttr > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_decls: // opt_decls
      case symbol_kind::S_decl_tail: // decl_tail
      case symbol_kind::S_decl: // decl
      case symbol_kind::S_var_decl: // var_decl
      case symbol_kind::S_proc_decl: // proc_decl
      case symbol_kind::S_rec_decl: // rec_decl
        value.move< BoolAttr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_init_opt: // var_init_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_type: // type
        value.move< TypedAttr > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_decls: // opt_decls
      case symbol_kind::S_decl_tail: // decl_tail
      case symbol_kind::S_decl: // decl
      case symbol_kind::S_var_decl: // var_decl
      case symbol_kind::S_proc_decl: // proc_decl
      case symbol_kind::S_rec_decl: // rec_decl
        value.copy< BoolAttr > (that.value);
        break;

      case symbol_kind::S_var_init_opt: // var_init_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_type: // type
        value.copy< TypedAttr > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_decls: // opt_decls
      case symbol_kind::S_decl_tail: // decl_tail
      case symbol_kind::S_decl: // decl
      case symbol_kind::S_var_decl: // var_decl
      case symbol_kind::S_proc_decl: // proc_decl
      case symbol_kind::S_rec_decl: // rec_decl
        value.move< BoolAttr > (that.value);
        break;

      case symbol_kind::S_var_init_opt: // var_init_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_type: // type
        value.move< TypedAttr > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_decls: // opt_decls
      case symbol_kind::S_decl_tail: // decl_tail
      case symbol_kind::S_decl: // decl
      case symbol_kind::S_var_decl: // var_decl
      case symbol_kind::S_proc_decl: // proc_decl
      case symbol_kind::S_rec_decl: // rec_decl
        yylhs.value.emplace< BoolAttr > ();
        break;

      case symbol_kind::S_var_init_opt: // var_init_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_type: // type
        yylhs.value.emplace< TypedAttr > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: PROGRAM NAME BEGIN_TOK opt_decls END
#line 56 "parser.y"
    {   
        // std::cout << "quawuda" << std::endl;
        yylhs.value.as < BoolAttr > ().ok = yystack_[1].value.as < BoolAttr > ().ok;
        if(yylhs.value.as < BoolAttr > ().ok) {
            printf("Análise sintática concluída com sucesso!\n");
        }
        if (!yylhs.value.as < BoolAttr > ().ok) {
            printf("Erro de tipo encontrado no programa.\n");
		}
    }
#line 604 "parser.cpp"
    break;

  case 3: // opt_decls: %empty
#line 70 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = true;
    }
#line 612 "parser.cpp"
    break;

  case 4: // opt_decls: decl decl_tail
#line 74 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = yystack_[1].value.as < BoolAttr > ().ok && yystack_[0].value.as < BoolAttr > ().ok;
    }
#line 620 "parser.cpp"
    break;

  case 5: // decl_tail: %empty
#line 81 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = true;
    }
#line 628 "parser.cpp"
    break;

  case 6: // decl_tail: ';' decl decl_tail
#line 85 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = yystack_[1].value.as < BoolAttr > ().ok && yystack_[0].value.as < BoolAttr > ().ok;
    }
#line 636 "parser.cpp"
    break;

  case 7: // decl: var_decl
#line 92 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = yystack_[0].value.as < BoolAttr > ().ok;
    }
#line 644 "parser.cpp"
    break;

  case 8: // decl: proc_decl
#line 96 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = yystack_[0].value.as < BoolAttr > ().ok;
    }
#line 652 "parser.cpp"
    break;

  case 9: // decl: rec_decl
#line 100 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = yystack_[0].value.as < BoolAttr > ().ok;
    }
#line 660 "parser.cpp"
    break;

  case 10: // var_decl: VAR NAME ':' type var_init_opt
#line 107 "parser.y"
    {
        yystack_[0].value.as < TypedAttr > ().type = yystack_[1].value.as < TypedAttr > ().type;
        bool insert_ok = SymbolTable::insert("name", TokenInfo({}, yystack_[1].value.as < TypedAttr > ().type, Tag::VAR));
        if (!insert_ok) {
            std::cout << "Erro: Variável '" << "name" << "' já declarada." << std::endl;
            yylhs.value.as < BoolAttr > ().ok = false;
        } else {
            yylhs.value.as < BoolAttr > ().ok = yystack_[0].value.as < TypedAttr > ().ok;
        }
    }
#line 675 "parser.cpp"
    break;

  case 11: // var_decl: VAR NAME ASSIGN expression
#line 118 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = yystack_[0].value.as < TypedAttr > ().ok;
        SymbolTable::print_all();
        SymbolTable::insert("name", TokenInfo({}, yystack_[0].value.as < TypedAttr > ().type, Tag::VAR));
    }
#line 685 "parser.cpp"
    break;

  case 12: // var_init_opt: %empty
#line 127 "parser.y"
    {
        //$$.ok = true;
        //$$.type = "bool";
    }
#line 694 "parser.cpp"
    break;

  case 13: // var_init_opt: ASSIGN expression
#line 132 "parser.y"
    {
        // $$.ok = true;
        // $$.type = "bool";
    }
#line 703 "parser.cpp"
    break;

  case 14: // proc_decl: PROCEDURE NAME '(' opt_param_list ')' opt_type block
#line 140 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = true;
    }
#line 711 "parser.cpp"
    break;

  case 24: // rec_decl: STRUCT NAME '{' opt_paramfield_decls '}'
#line 171 "parser.y"
    {
        yylhs.value.as < BoolAttr > ().ok = true;
    }
#line 719 "parser.cpp"
    break;

  case 31: // stmt_list: stmt stmt_tail
#line 193 "parser.y"
    {
        std::cout << "Socorro" << std::endl;
    }
#line 727 "parser.cpp"
    break;

  case 53: // expression: or_exp
#line 258 "parser.y"
      {
        yylhs.value.as < TypedAttr > ().ok = true;
        yylhs.value.as < TypedAttr > ().type = "ERR";
      }
#line 736 "parser.cpp"
    break;

  case 98: // type: FLOAT_T
#line 367 "parser.y"
      {
        yylhs.value.as < TypedAttr > ().ok = true;
        yylhs.value.as < TypedAttr > ().type = "FLOAT";
      }
#line 745 "parser.cpp"
    break;

  case 99: // type: INT_T
#line 372 "parser.y"
    {
        yylhs.value.as < TypedAttr > ().ok = true;
        yylhs.value.as < TypedAttr > ().type = "INT";
    }
#line 754 "parser.cpp"
    break;

  case 100: // type: STRING_T
#line 377 "parser.y"
    {
        yylhs.value.as < TypedAttr > ().ok = true;
        yylhs.value.as < TypedAttr > ().type = "STRING";
    }
#line 763 "parser.cpp"
    break;

  case 101: // type: BOOL_T
#line 382 "parser.y"
    {
        yylhs.value.as < TypedAttr > ().ok = true;
        yylhs.value.as < TypedAttr > ().type = "BOOL";
    }
#line 772 "parser.cpp"
    break;

  case 102: // type: NAME
#line 387 "parser.y"
    {
        auto lookup_result = SymbolTable::lookup("name");
        if (lookup_result) {
            if (lookup_result->tag != Tag::STRUCT) {
                std::cout << "Erro: '" << "name" << "' não é um tipo." << std::endl;
                yylhs.value.as < TypedAttr > ().ok = false;
                yylhs.value.as < TypedAttr > ().type = "ERR";
            }
            else {
                yylhs.value.as < TypedAttr > ().ok = true;
                yylhs.value.as < TypedAttr > ().type = lookup_result->type;
            }
        } else {
            std::cout << "Erro: Tipo '" << "name" << "' não declarado." << std::endl;
            yylhs.value.as < TypedAttr > ().ok = false;
            yylhs.value.as < TypedAttr > ().type = "ERR";
        }
    }
#line 795 "parser.cpp"
    break;

  case 103: // type: REF '(' type ')'
#line 406 "parser.y"
    {
        yylhs.value.as < TypedAttr > ().ok = yystack_[1].value.as < TypedAttr > ().ok;
        yylhs.value.as < TypedAttr > ().type = yystack_[1].value.as < TypedAttr > ().type;
    }
#line 804 "parser.cpp"
    break;


#line 808 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -120;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      43,    52,    67,    62,  -120,     7,    76,    82,    94,    91,
      61,  -120,  -120,  -120,   -20,    54,    57,  -120,     7,  -120,
       9,    41,   109,   109,    61,     6,  -120,  -120,  -120,  -120,
    -120,  -120,   110,    64,    66,     9,    20,     9,  -120,  -120,
      88,    90,  -120,    56,     8,    35,  -120,    79,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,    73,    68,  -120,  -120,  -120,
    -120,    95,    85,    84,    87,    86,    93,  -120,     9,   134,
       9,  -120,  -120,    16,   140,  -120,  -120,    92,     9,     9,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    41,   141,     9,  -120,    41,    97,   109,  -120,  -120,
     109,  -120,    96,    98,    42,    99,    42,   100,   101,   102,
    -120,    90,  -120,     8,     8,     8,     8,     8,     8,    35,
      35,  -120,  -120,  -120,   103,   104,  -120,  -120,    41,   138,
      87,    93,  -120,     9,  -120,  -120,    42,  -120,  -120,  -120,
    -120,   115,  -120,     7,  -120,  -120,  -120,    98,  -120,    41,
      61,    48,  -120,  -120,   142,     9,     9,     9,   144,   111,
    -120,  -120,  -120,  -120,  -120,   119,   128,  -120,   143,   145,
    -120,  -120,  -120,    48,  -120,     9,     9,    48,    48,   111,
    -120,  -120,   146,   147,  -120,    48,   148,  -120,  -120,  -120
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     3,     0,     0,     0,     0,
       5,     7,     8,     9,     0,     0,     0,     2,     0,     4,
       0,     0,    15,    25,     5,    85,    91,    92,    93,    96,
      97,    95,     0,     0,     0,     0,     0,     0,    78,    11,
      53,    55,    57,    59,    66,    69,    72,    74,    76,    80,
      81,    82,    77,    94,   102,     0,     0,    98,    99,   100,
     101,    12,     0,     0,    17,     0,    27,     6,    49,     0,
       0,    84,    79,     0,     0,    58,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,    19,     0,    16,    24,
       0,    26,     0,    51,    85,     0,    85,     0,     0,     0,
      83,    54,    56,    60,    61,    62,    63,    64,    65,    67,
      68,    70,    71,    73,     0,     0,    13,    29,     0,     0,
      17,    27,    48,     0,    50,    86,    85,    89,    90,    88,
     103,     0,    20,    22,    14,    18,    28,    51,    87,     0,
       5,    30,    52,   104,     0,     0,     0,    46,     0,    32,
      34,    35,    36,    37,    38,     0,     0,    23,     0,     0,
      45,    47,    21,     0,    31,     0,     0,    30,    30,    32,
      39,    40,    42,     0,    33,    30,     0,    44,    43,    41
  };

  const short
  parser::yypgoto_[] =
  {
    -120,  -120,  -120,   -23,   -15,  -120,  -120,  -120,  -120,    33,
    -120,  -120,  -120,  -120,  -120,    38,   -16,  -102,   -13,    -9,
    -120,  -120,  -120,  -120,  -120,  -120,  -119,  -120,    24,   -37,
    -120,   105,   -27,  -120,    49,    14,   -50,   136,  -120,   -69,
     -95,  -120,   -71,  -120,  -120,   -85
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     9,    19,    10,    11,    94,    12,    63,    98,
     129,   144,   151,    13,    65,   101,    64,   158,   174,   159,
     160,   161,   186,   162,   163,   170,    38,   102,   134,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      71,    50,    51,    52,    53,    61
  };

  const unsigned char
  parser::yytable_[] =
  {
      77,    67,   108,    24,   107,   109,   124,    66,    75,   135,
     127,    20,    25,    26,    27,    28,    29,    30,    31,   106,
       6,     7,     8,    25,    26,    27,    28,    29,    30,    31,
      21,   103,   164,   105,    32,    33,    34,    35,   121,   122,
     123,   148,    33,   142,    54,    32,    33,    34,    86,    87,
      36,    25,   112,     1,   164,     3,   126,    68,   164,   164,
      37,    36,    69,    70,   153,   155,   164,     4,    55,   156,
      56,    37,   157,     5,    33,   182,   183,    88,    89,    14,
     166,   130,   165,   188,   131,    15,    57,    58,    59,    60,
      80,    81,    82,    83,    84,    85,   147,    16,    69,    70,
     119,   120,   166,    17,   165,    22,   166,   166,   165,   165,
      18,    23,    62,    72,   166,    73,   165,    74,   168,   169,
     171,    78,    79,    90,    91,    92,    93,   154,   150,   113,
     114,   115,   116,   117,   118,    95,    96,   104,   180,   181,
      97,    99,   100,   106,   110,   149,   125,   128,   132,   143,
     175,   133,   137,   138,   139,   140,   172,   136,   167,   176,
     173,   177,   141,   145,   179,   185,   184,   178,   189,   146,
     187,   152,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111
  };

  const short
  parser::yycheck_[] =
  {
      37,    24,    73,    18,    73,    74,    91,    23,    35,   104,
      95,    31,     3,     4,     5,     6,     7,     8,     9,     3,
      13,    14,    15,     3,     4,     5,     6,     7,     8,     9,
      50,    68,   151,    70,    25,    26,    27,    28,    88,    89,
      90,   136,    26,   128,     3,    25,    26,    27,    40,    41,
      41,     3,    79,    10,   173,     3,    93,    51,   177,   178,
      51,    41,    56,    57,   149,    17,   185,     0,    27,    21,
      29,    51,    24,    11,    26,   177,   178,    42,    43,     3,
     151,    97,   151,   185,   100,     3,    45,    46,    47,    48,
      34,    35,    36,    37,    38,    39,   133,     3,    56,    57,
      86,    87,   173,    12,   173,    51,   177,   178,   177,   178,
      49,    54,     3,     3,   185,    51,   185,    51,   155,   156,
     157,    33,    32,    44,    51,    57,    31,   150,   143,    80,
      81,    82,    83,    84,    85,    50,    52,     3,   175,   176,
      53,    55,    49,     3,    52,    30,     5,    50,    52,    11,
      31,    53,    52,    52,    52,    52,    12,    58,    16,    31,
      49,    18,    58,   130,   173,    19,   179,    22,    20,   131,
      23,   147,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78
  };

  const signed char
  parser::yystos_[] =
  {
       0,    10,    60,     3,     0,    11,    13,    14,    15,    61,
      63,    64,    66,    72,     3,     3,     3,    12,    49,    62,
      31,    50,    51,    54,    63,     3,     4,     5,     6,     7,
       8,     9,    25,    26,    27,    28,    41,    51,    85,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     100,   101,   102,   103,     3,    27,    29,    45,    46,    47,
      48,   104,     3,    67,    75,    73,    75,    62,    51,    56,
      57,    99,     3,    51,    51,    91,    96,    88,    33,    32,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    51,    57,    31,    65,    50,    52,    53,    68,    55,
      49,    74,    86,    88,     3,    88,     3,    98,   101,    98,
      52,    90,    91,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    95,   104,     5,    88,   104,    50,    69,
      75,    75,    52,    53,    87,    99,    58,    52,    52,    52,
      52,    58,   104,    11,    70,    68,    74,    88,    99,    30,
      63,    71,    87,   104,    62,    17,    21,    24,    76,    78,
      79,    80,    82,    83,    85,    98,   101,    16,    88,    88,
      84,    88,    12,    49,    77,    31,    31,    18,    22,    78,
      88,    88,    76,    76,    77,    19,    81,    23,    76,    20
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    59,    60,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    65,    65,    66,    67,    67,    68,    68,    69,
      69,    70,    71,    71,    72,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    80,    81,    81,    82,    83,    84,    84,    85,    86,
      86,    87,    87,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    93,
      94,    94,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    98,    99,    99,    99,   100,   101,
     101,   102,   102,   102,   102,   102,   103,   103,   104,   104,
     104,   104,   104,   104,   104
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     5,     0,     2,     0,     3,     1,     1,     1,
       5,     4,     0,     2,     7,     0,     2,     0,     3,     0,
       2,     4,     0,     3,     5,     0,     2,     0,     3,     3,
       0,     2,     0,     3,     1,     1,     1,     1,     1,     3,
       3,     6,     0,     2,     5,     2,     0,     1,     4,     0,
       2,     0,     3,     1,     3,     1,     3,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     1,     1,     3,     2,     0,     3,     4,     4,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NAME",
  "FLOAT_LITERAL", "INT_LITERAL", "STRING_LITERAL", "TRUE", "FALSE",
  "NULL_LIT", "PROGRAM", "BEGIN_TOK", "END", "VAR", "PROCEDURE", "STRUCT",
  "IN", "IF", "THEN", "ELSE", "FI", "WHILE", "DO", "OD", "RETURN", "NEW",
  "DEREF", "REF", "NOT", "ARRAY", "OF", "ASSIGN", "AND", "OR", "LT", "LE",
  "GT", "GE", "EQ", "NE", "PLUS", "MINUS", "MULT", "DIV", "EXP_OP",
  "FLOAT_T", "INT_T", "STRING_T", "BOOL_T", "';'", "':'", "'('", "')'",
  "','", "'{'", "'}'", "'.'", "'['", "']'", "$accept", "program",
  "opt_decls", "decl_tail", "decl", "var_decl", "var_init_opt",
  "proc_decl", "opt_param_list", "paramfield_tail", "opt_type", "block",
  "proc_body_opt", "rec_decl", "opt_paramfield_decls",
  "paramfield_decl_tail", "paramfield_decl", "stmt_list", "stmt_tail",
  "stmt", "assign_stmt", "if_stmt", "else_opt", "while_stmt",
  "return_stmt", "return_exp_opt", "call_stmt", "call_args_opt",
  "call_args_tail", "expression", "or_exp", "and_exp", "not_exp",
  "rel_exp", "add_exp", "mult_exp", "exp_exp", "unary_exp", "primary_exp",
  "var", "var_suffix", "ref_var", "deref_var", "literal", "bool_literal",
  "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    55,    55,    70,    73,    81,    84,    91,    95,    99,
     106,   117,   127,   131,   139,   145,   147,   150,   152,   155,
     157,   161,   164,   166,   170,   176,   178,   181,   183,   187,
     190,   192,   198,   200,   204,   205,   206,   207,   208,   212,
     213,   217,   220,   222,   226,   230,   233,   235,   239,   242,
     244,   247,   249,   257,   265,   266,   270,   271,   275,   276,
     280,   281,   282,   283,   284,   285,   286,   290,   291,   292,
     296,   297,   298,   302,   303,   307,   308,   312,   313,   314,
     315,   316,   317,   318,   326,   329,   331,   332,   336,   340,
     341,   349,   350,   351,   352,   353,   357,   358,   366,   371,
     376,   381,   386,   405,   410
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1407 "parser.cpp"

#line 413 "parser.y"


void yy::parser::error(const std::string& msg) {
    std::cerr << "Erro de sintaxe: " << msg << std::endl;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}

int main(void) {
    SymbolTable::enter_scope();
    yy::parser parser;
    return parser.parse();
}
