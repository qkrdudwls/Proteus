#include "util.h"

#if defined(__x86_64__) || defined(_M_X64)
    #define SYSTEM_BITS 64
#elif defined(__i386) || defined(_M_IX86)
    #define SYSTEM_BITS 32
#endif

void convertResult(int num, int N){
    const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t size = (SYSTEM_BITS == 32) ? 33 : 65;
    char *result = (char *)malloc(size);
    char *ptr = &result[size - 1];
    int isNegative = num < 0;
    if (isNegative) {
        num = -num;
    }
    *ptr = '\0';

    do {
        *--ptr = digits[num % N];
        num /= N;
    } while (num != 0);

    if (isNegative) {
        *--ptr = '-';
    }

    printf("Converted Result: %s\n", ptr);

    free(result);
}