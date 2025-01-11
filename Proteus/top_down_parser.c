#include <ctype.h>
#include <string.h>
#include "parser.h"

#define MAX_INPUT_SIZE 256

char input[MAX_INPUT_SIZE];
char token;
int pivot;
int yylval;

void match(char c);
void Expression();
void ExpressionPrime();
void Term();
void TermPrime();
void Factor();

int main(void){
    int isquit = 0;

    while(isquit == 0){
        memset(input, 0 ,sizeof(input));
        fprintf(stdout, "Enter an expression (Type quit to exit):");
        fscanf(stdin, "%255s", input);

        if(strcmp(input, "quit") == 0){
            isquit = 1;
            break;
        }

        pivot = 0;
        token = input[0];
        Expression();

        if(token == '\0'){
            fprintf(stdout, "Parsing complete\n");
        }else{
            fprintf(stderr, "Syntax error\n");
        }

        fprintf(stdout, "\n");
    }    
    return 0; 
}

void match(char c){
    if(token == c){
        token = input[++pivot];
    }else{
        fprintf(stderr, "Token mismatch\n");
        exit(1);
    }
}

void Expression(){
    Term();
    ExpressionPrime();
}

void ExpressionPrime(){
    switch(token){
        case '+':
            match('+');
            Term();
            ExpressionPrime();
            break;
        case '-':
            match('-');
            Term();
            ExpressionPrime();
            break;
        default:
            break;
    }
}

void Term(){
    Factor();
    TermPrime();
}

void TermPrime(){
    switch(token){
        case '*':
            match('*');
            Factor();
            TermPrime();
            break;
        case '/':
            match('/');
            Factor();
            TermPrime();
            break;
        default:
            break;
    }
}

void Factor() {
    if (token == '(') {
        match('(');
        Expression();
        match(')');
    } else if (isdigit(token)) {
        while (isdigit(token)) {
            match(token);
        }
    } else {
        fprintf(stderr, "Syntax error\n");
        exit(1);
    }
}
