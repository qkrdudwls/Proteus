#include <string.h>
#include "util.h"
#include "compiler.h"
#include "arithmetic_parser.tab.h"

void yyerror(const char *s){
    fprintf(stderr, "Error: %s\n", s);
}

int main(void){
    char input[256];
    int status;
    int result;
    int mode;
    int N = 2;
    YY_BUFFER_STATE buffer = NULL;

    while(1){
        mode = 0;
        printf("------ Proteus ------\n");
        printf("1. Arithmetic Expression Evaluation & Base Conversion\n");
        printf("2. Notation Conversion\n");
        printf("3. Exit\n");
        printf("Enter the mode: ");
        scanf("%d", &mode);
        printf("\n");

        while(getchar() != '\n');

        if(mode == 3){
            break;
        }else if(mode < 1 || mode > 3){
            printf("Invalid mode\n");
            while(getchar() != '\n');
            continue;
        }else{
            printf("Enter an expression: ");
            fgets(input, 256, stdin);
        }

        if(input[0] == '\n'){
            printf("Error reading input\n");
            return 1;
        }

        buffer = yy_scan_string(input);
        status = yyparse();
        yy_delete_buffer(buffer);
        
        switch(mode){
            case 1:
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

                if(status == 0){
                    result = yylval;
                    convertBase(result, N);
                }else{
                    printf("Error parsing expression\n");
                }
                break;
            
            case 2:
                break;

            default:
                break;
        }
        printf("\n");
    }    

    printf("Program Terminated\n");
    return 0;
}