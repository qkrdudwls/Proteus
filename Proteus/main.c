#include <string.h>
#include "util.h"
#include "compiler.h"
#include "parser.tab.h"

void yyerror(const char *s){
    fprintf(stderr, "Error: %s\n", s);
}

int main(void){
    char input[256];
    int status;
    int result;
    int N = 2;
    YY_BUFFER_STATE buffer = NULL;

    while(1){
        printf("------ Proteus ------\n");
        printf("Enter 'exit' to quit\n");
        printf("Enter an expression: ");
        fgets(input, 256, stdin);

        if(!input){
            printf("Error reading input\n");
            return 1;
        }
        if(strcmp(input, "exit\n") == 0){
            break;
        }
        
        printf("\n");
        printf("----------------------\n");
        printf("\n");
        printf("Enter the base N.\nN is greater than or equal to 2 and less than or equal to 36.The default value is 2.\n");
        printf("Enter N: ");

        if(scanf("%d", &N) != 1){
            printf("Invalid input for base N.\n");
            while(getchar() != '\n');
            continue;
        }
        
        while(getchar() != '\n');

        buffer = yy_scan_string(input);
        status = yyparse();
        yy_delete_buffer(buffer);

        if(status == 0){
            result = yylval;
            convertResult(result, N);
        }else{
            printf("Error parsing expression\n");
        }
    }    

    printf("Program Terminated\n");
    return 0;
}