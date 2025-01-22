#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#define __PLUS__ 1
#define __MINUS__ 2
#define __MULT__ 3
#define __DIV__ 4
#define __LPAREN__ 5
#define __RPAREN__ 6
#define __DIGIT__ 7
#define __NUM__ 8

extern int yylex(); 
extern int yylval;

#endif