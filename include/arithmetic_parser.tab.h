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

#ifndef YY_ARITHMETIC_ARITHMETIC_PARSER_TAB_H_INCLUDED
# define YY_ARITHMETIC_ARITHMETIC_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef ARITHMETIC_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define ARITHMETIC_DEBUG 1
#  else
#   define ARITHMETIC_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define ARITHMETIC_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined ARITHMETIC_DEBUG */
#if ARITHMETIC_DEBUG
extern int arithmetic_debug;
#endif

/* Token kinds.  */
#ifndef ARITHMETIC_TOKENTYPE
# define ARITHMETIC_TOKENTYPE
  enum arithmetic_tokentype
  {
    ARITHMETIC_EMPTY = -2,
    ARITHMETIC_EOF = 0,            /* "end of file"  */
    ARITHMETIC_error = 256,        /* error  */
    ARITHMETIC_UNDEF = 257,        /* "invalid token"  */
    ARITHMETIC_INFIX = 258,        /* ARITHMETIC_INFIX  */
    ARITHMETIC_PREFIX = 259,       /* ARITHMETIC_PREFIX  */
    ARITHMETIC_POSTFIX = 260,      /* ARITHMETIC_POSTFIX  */
    ARITHMETIC_DIGIT = 261,        /* ARITHMETIC_DIGIT  */
    ARITHMETIC_PLUS = 262,         /* ARITHMETIC_PLUS  */
    ARITHMETIC_MINUS = 263,        /* ARITHMETIC_MINUS  */
    ARITHMETIC_MULT = 264,         /* ARITHMETIC_MULT  */
    ARITHMETIC_DIV = 265,          /* ARITHMETIC_DIV  */
    ARITHMETIC_EXP = 266,          /* ARITHMETIC_EXP  */
    ARITHMETIC_MOD = 267,          /* ARITHMETIC_MOD  */
    ARITHMETIC_LPAREN = 268,       /* ARITHMETIC_LPAREN  */
    ARITHMETIC_RPAREN = 269,       /* ARITHMETIC_RPAREN  */
    ARITHMETIC_NEWLINE = 270,      /* ARITHMETIC_NEWLINE  */
    ARITHMETIC_UPLUS = 271,        /* ARITHMETIC_UPLUS  */
    ARITHMETIC_UMINUS = 272        /* ARITHMETIC_UMINUS  */
  };
  typedef enum arithmetic_tokentype arithmetic_token_kind_t;
#endif

/* Value type.  */
#if ! defined ARITHMETIC_STYPE && ! defined ARITHMETIC_STYPE_IS_DECLARED
union ARITHMETIC_STYPE
{
#line 9 "./parser/arithmetic_parser.y"

    int ival;

#line 93 "arithmetic_parser.tab.h"

};
typedef union ARITHMETIC_STYPE ARITHMETIC_STYPE;
# define ARITHMETIC_STYPE_IS_TRIVIAL 1
# define ARITHMETIC_STYPE_IS_DECLARED 1
#endif


extern ARITHMETIC_STYPE arithmetic_lval;


int arithmetic_parse (void);


#endif /* !YY_ARITHMETIC_ARITHMETIC_PARSER_TAB_H_INCLUDED  */
