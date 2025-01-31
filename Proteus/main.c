#include "util.h"
#include "parser.h"
#include "notation.h"
#include "arithmetic_parser.tab.h"
#include "notation_parser.tab.h"

int mode;
int arithmetic_mode;
int notation_mode;

void yyerror(const char *s){
    fprintf(stderr, "Error: %s\n", s);
}

int main(void){
    char input[256];
    int status;
    int result;
    int command;
    int N = 2;
    YY_BUFFER_STATE buffer = NULL;

    while(1){
        mode = 0;
        arithmetic_mode = 0;
        command = 0;

        printf("------ Proteus ------\n");
        printf("1. Arithmetic Expression Evaluation & Base Conversion\n");
        printf("2. Notation Conversion\n");
        printf("3. Exit\n");
        printf("Enter the Command Number: ");
        scanf("%d", &command);
        printf("\n");

        while(getchar() != '\n');

        if(command == 3){
            break;
        }else if(command < 1 || command > 3){
            printf("Invalid Command\n");
            while(getchar() != '\n');
            continue;
        }

        printf("Enter an expression: ");
        fgets(input, 256, stdin);

        if(input[0] == '\n'){
            printf("Error reading input\n");
            return 1;
        }
        
        printf("\n");

        switch(command){
            case 1:
                mode = 1;
                arithmetic_mode = 0;
                printf("----------------------\n");
                printf("\n");
                printf("Enter the base N.\nN is greater than or equal to 2 and less than or equal to 36.The default value is 2.\n");
                printf("Enter N: ");

                if(scanf("%d", &N) != 1){
                    printf("Invalid input for base N.\n");
                    while(getchar() != '\n');
                    continue;
                }
                
                buffer = yy_scan_string(input);
                status = arithmetic_parse();
                yy_delete_buffer(buffer);

                if(status == 0){
                    result = arithmetic_lval;
                    convertBase(result, N);
                }else{
                    printf("Error parsing expression\n");
                }
                break;
            
            case 2:
                mode = 2;
                notation_mode = 0;
                printf("----------------------\n");
                printf("1. Infix to Prefix\n");
                printf("2. Infix to Postfix\n");
                printf("Enter the Command Number: ");
                scanf("%d", &command);
                printf("\n");

                while(getchar() != '\n');

                if(command == 1){
                    notation_mode = 1;
                } else if(command == 2){
                    notation_mode = 2;
                } else {
                    printf("Invalid Command\n");
                    continue;
                }

                buffer = yy_scan_string(input);
                status = notation_parse();
                yy_delete_buffer(buffer);

                if(status != 0){
                    printf("Error parsing expression\n");
                }
                break;

            default:
                break;
        }
        printf("\n");
    }    

    printf("Program Terminated\n");
    return 0;
}