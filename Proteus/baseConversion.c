#include "util.h"
#include <stdlib.h>
#include <stdio.h>

void convertBase(int num, int N){
    const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char result[65];
    char *ptr = &result[64];
    int originalNum = num;

    *ptr = '\0';

    if(num == 0){
        *--ptr = digits[0];
    } else {
        if(num < 0){
            num = -num;
        }

        do {
            *--ptr = digits[num % N];
            num /= N;
        } while(num != 0);
    }

    if(originalNum < 0){
        *--ptr = '-';
    }

    printf("Converted Result: %s\n", ptr);
}
