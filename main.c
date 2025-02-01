#include "util.h"
#include "parser.h"
#include "notation.h"
#include "arithmetic_parser.tab.h"
#include "notation_parser.tab.h"

int mode;
int notation_mode;

void yyerror(const char *s){
    fprintf(stderr, "Error: %s\n", s);
}

void print_infix();
void print_prefix();
void print_postfix();

int main(void){
    char input[259];
    char expression[256];
    char prerequisites[3];
    int notation;
    int status;
    int result;
    int command, notation_command;
    int N = 2;
    YY_BUFFER_STATE buffer = NULL;

    while(1){
        input[0] = '\0';
        notation = 0;
        command = 0;

        printf("------ Proteus ------\n");
        printf("1. Arithmetic Expression Evaluation & Base Conversion\n");
        printf("2. Notation Conversion\n");
        printf("3. Exit\n");
        printf("----------------------\n");
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

        printf("----------------------\n");
        printf("Select the Notation to Input\n");
        printf("1. Infix Notation\n");
        printf("2. Prefix Notation\n");
        printf("3. Postfix Notation\n");
        printf("----------------------\n");
        printf("Enter the Notation Number (Default: Infix): ");
        scanf("%d", &notation_command);
        printf("\n");

        switch(notation_command){
            case 1:
            default:
                strcpy(prerequisites, "in");
                notation = 1;
                break;
            case 2:
                strcpy(prerequisites, "pr");
                notation = 2;
                break;
            case 3:
                strcpy(prerequisites, "po");
                notation = 3;
                break;
        }

        while(getchar() != '\n');

        printf("Enter an expression: ");
        fgets(expression, 256, stdin);

        if(input[0] == '\n'){
            printf("Error reading input\n");
            continue;
        }
        
        memcpy(input, prerequisites, 2);
        strcat(input, expression);
        printf("\n");

        switch(command){
            case 1:
                mode = 1;
                printf("----------------------\n");
                printf("\n");
                printf("Enter the base N.\nN is greater than or equal to 2 and less than or equal to 36.The default value is 2.\n");
                printf("Enter N: ");

                if(scanf("%d", &N) != 1){
                    printf("Invalid input for base N.\n");
                    while(getchar() != '\n');
                    continue;
                }

                printf("\n");

                buffer = yy_scan_string(input);
                status = arithmetic_parse();
                yy_delete_buffer(buffer);

                if(status == 0){
                    result = arithmetic_lval.ival;
                    convertBase(result, N);
                }else{
                    printf("Error parsing expression\n");
                }
                break;
            
            case 2:
                mode = 2;
                notation_mode = 0;

                switch(notation){
                    case 1:
                        print_infix();
                        break;
                    case 2:
                        print_prefix();
                        break;
                    case 3:
                        print_postfix();
                        break;
                    default:
                        break;
                }

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
                printf("\n");
                break;

            default:
                break;
        }
        printf("\n");
    }    

    printf("Program Terminated\n");
    return 0;
}

void print_infix(){
    printf("----------------------\n");
    printf("1. Infix to Prefix\n");
    printf("2. Infix to Postfix\n");
    printf("----------------------\n");
    printf("Enter the Command Number: ");
}

void print_prefix(){
    printf("----------------------\n");
    printf("1. Prefix to Infix\n");
    printf("2. Prefix to Postfix\n");
    printf("----------------------\n");
    printf("Enter the Command Number: ");
}

void print_postfix(){
    printf("----------------------\n");
    printf("1. Postfix to Infix\n");
    printf("2. Postfix to Prefix\n");
    printf("----------------------\n");
    printf("Enter the Command Number: ");
}