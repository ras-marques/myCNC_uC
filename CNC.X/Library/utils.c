#include "header.h"

int isnumber(char check[]){
    int n;
    for(n = 0; n < strlen(check); n++){
        if(check[0] != 45 && (check[n] < 48 || check[n] > 57)){
            return 0;
        }
    }
    return 1;
}

float mod(float number){
    if(number >= 0) return number;
    else return -number;
}

float max_of_three(float x, float y, float z){
    long max = mod(x);
    if(mod(y) > max) max = mod(y);
    if(mod(z) > max) max = mod(z);
    return max;
}
