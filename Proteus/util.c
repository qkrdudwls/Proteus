#include <stdio.h>
#include <stdlib.h>

void convertResult(int digit, int N){
    int result[32] = {0};
    
    if(digit < 0){
        result[31] = 1;
    }
    digit = (unsigned int)digit;

}