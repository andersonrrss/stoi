#include <stdio.h>
#include "stoi.h"

int main(void)
{
    int result;
    if(stoi("1024", &result) != 0)
        return 1;

    printf("Inteiro: %d\n", result);
    return 0;
}