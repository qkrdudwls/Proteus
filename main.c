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

void print_warnings();

int main(void){
    char input[256];
    int status;
    int result;
    int command;
    int N = 2;
    YY_BUFFER_STATE buffer = NULL;

    print_warnings();

    while(1){
        mode = 0;
        arithmetic_mode = 0;
        command = 0;

        printf("------ Proteus 2.0 ------\n");
        printf("1. Arithmetic Expression Evaluation & Base Conversion\n");
        printf("2. Notation Conversion\n");
        printf("3. Exit\n");
        printf("-------------------------\n");
        printf("Enter the Command Number: ");
        scanf("%d", &command);
        printf("\n");

        while(getchar() != '\n');

        if(command == 3){
            break;
        }else if(command < 1 || command > 3){
            printf("Invalid Command.\n");
            while(getchar() != '\n');
            continue;
        }

        printf("Enter an expression: ");
        fgets(input, 256, stdin);

        if(input[0] == '\n'){
            printf("Empty input is not allowed.\n");
            continue;
        }
        
        printf("\n");

        switch(command){
            case 1:
                mode = 1;
                arithmetic_mode = 0;
                printf("-------------------------\n");
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
                if(buffer == NULL){
                    printf("Error initializing scan buffer.\n");
                    continue;
                }
                status = arithmetic_parse();
                yy_delete_buffer(buffer);


                if(status == 0){
                    result = arithmetic_lval;
                    convertBase(result, N);
                }else{
                    printf("Error parsing expression: %s\n", input);
                }
                break;
            
            case 2:
                mode = 2;
                notation_mode = 0;
                printf("-------------------------\n");
                printf("1. Infix to Prefix\n");
                printf("2. Infix to Postfix\n");
                printf("-------------------------\n");
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
                if(buffer == NULL){
                    printf("Error initializing scan buffer.\n");
                    continue;
                }
                status = notation_parse();
                yy_delete_buffer(buffer);

                if(status != 0){
                    printf("Error parsing expression: %s\n", input);
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

void print_warnings() {
    printf("------ Proteus 2.0 Usage Warnings ------\n");
    printf("> Commands must be entered as numbers. Please enter the correct command number.\n");
    printf("> Expressions must be 256 characters or less. Longer expressions may result in errors.\n");
    printf("> Base N must be a value between 2 and 36. Any other values will cause an error.\n");
    printf("> If invalid input is entered, please try again.\n");
    printf("> Pay close attention to error messages that occur during parsing.\n");
    printf("> Note: The program uses the int data type for command inputs and base N.\n");
    printf("        Ensure the values entered are within the valid range for int to avoid potential issues.\n");
    printf("> Error reports are welcome.\n");
    printf("----------------------------------------\n");
    printf("\n");
}