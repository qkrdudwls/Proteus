%{
    #include "parser.tab.h"
%}

%%
[0-9]+ {yylval=atoi(yytext); return __DIGIT__;}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"(" {return '(';}
")" {return ')';}
[ \t]+ {}
\n {return '\n';} 
. {printf("Error: %c\n", yytext[0]); exit(1);}
%%

int yywrap(){
    return 1;
}