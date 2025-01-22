#include <stdio.h>
#include <stdlib.h>

#if defined(__x86_64__) || defined(_M_X64)
    #define SYSTEM_BITS 64
#elif defined(__i386) || defined(_M_IX86)
    #define SYSTEM_BITS 32
#endif

void convertResult(int num, int N){
    char *result = NULL;
    const char *digits="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t size = (SYSTEM_BITS == 32) ? 33 : 65;
    result = (char *)malloc(size);
    char *ptr = &result[sizeof(result)-1];
    int isNegative = num < 0;
    if(isNegative){
        num = -num;
    }
    *ptr = '\0';

    do{
        *--ptr = digits[num % N];
        num /= N;
    }while(num != 0);

    if(isNegative){
        *--ptr = '-';
    }

    printf("Converted Number: %s\n", ptr);

    free(result);
}

int main(void){
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    printf("Enter the base to convert to (2 ~ 36): ");
    int N;
    scanf("%d", &N);
    convertResult(num, N);
    return 0;
}