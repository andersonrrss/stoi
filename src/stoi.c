#include "stoi.h"
#include <stdio.h>

int stoi(string s, int *out){
    int signal = 1;
    int final_result = 0;
    
    if(*s == '-')
    {
        signal = -1;
        s++; 
    }else if (*s == '+')
    {
        s++; 
    }

    if(*s == '\0')
    {
        return -1;
    }

    for(char *c = s; *c != '\0'; c++)
    {
        if('0' > *c || *c > '9')
        {
            return -1;
        }

        final_result = final_result * 10 + (*c - '0') * signal;
    }

    *out = final_result;
    return 0;
}