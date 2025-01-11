#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#define PLUS 1
#define MINUS 2
#define MULT 3
#define DIV 4
#define LPAREN 5
#define RPAREN 6
#define DIGIT 7
#define NUM 8

extern int yylex();
extern int yylval; 

#endif