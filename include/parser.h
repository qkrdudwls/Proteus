#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern void yyerror(const char *s);

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

#endif