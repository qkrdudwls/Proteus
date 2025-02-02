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

#ifndef YY_NOTATION_NOTATION_PARSER_TAB_H_INCLUDED
# define YY_NOTATION_NOTATION_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef NOTATION_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define NOTATION_DEBUG 1
#  else
#   define NOTATION_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define NOTATION_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined NOTATION_DEBUG */
#if NOTATION_DEBUG
extern int notation_debug;
#endif

/* Token kinds.  */
#ifndef NOTATION_TOKENTYPE
# define NOTATION_TOKENTYPE
  enum notation_tokentype
  {
    NOTATION_EMPTY = -2,
    NOTATION_EOF = 0,              /* "end of file"  */
    NOTATION_error = 256,          /* error  */
    NOTATION_UNDEF = 257,          /* "invalid token"  */
    NOTATION_PREFIX = 258,         /* NOTATION_PREFIX  */
    NOTATION_INFIX = 259,          /* NOTATION_INFIX  */
    NOTATION_POSTFIX = 260,        /* NOTATION_POSTFIX  */
    NOTATION_DIGIT = 261,          /* NOTATION_DIGIT  */
    NOTATION_PLUS = 262,           /* NOTATION_PLUS  */
    NOTATION_MINUS = 263,          /* NOTATION_MINUS  */
    NOTATION_MULT = 264,           /* NOTATION_MULT  */
    NOTATION_DIV = 265,            /* NOTATION_DIV  */
    NOTATION_EXP = 266,            /* NOTATION_EXP  */
    NOTATION_MOD = 267,            /* NOTATION_MOD  */
    NOTATION_LPAREN = 268,         /* NOTATION_LPAREN  */
    NOTATION_RPAREN = 269,         /* NOTATION_RPAREN  */
    NOTATION_NEWLINE = 270,        /* NOTATION_NEWLINE  */
    NOTATION_UMINUS = 271,         /* NOTATION_UMINUS  */
    NOTATION_UPLUS = 272           /* NOTATION_UPLUS  */
  };
  typedef enum notation_tokentype notation_token_kind_t;
#endif

/* Value type.  */
#if ! defined NOTATION_STYPE && ! defined NOTATION_STYPE_IS_DECLARED
union NOTATION_STYPE
{
#line 12 "./parser/notation_parser.y"

    int ival;
    struct Node* node;

#line 94 "notation_parser.tab.h"

};
typedef union NOTATION_STYPE NOTATION_STYPE;
# define NOTATION_STYPE_IS_TRIVIAL 1
# define NOTATION_STYPE_IS_DECLARED 1
#endif


extern NOTATION_STYPE notation_lval;


int notation_parse (void);


#endif /* !YY_NOTATION_NOTATION_PARSER_TAB_H_INCLUDED  */
