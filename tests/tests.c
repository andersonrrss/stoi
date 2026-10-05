#include <stdio.h>
#include "stoi.h"

static int pass = 0, fail = 0;

#define CHECK_OK(input, expected) do {                                  \
    int v = 0;                                                          \
    int r = stoi(input, &v);                                            \
    if(r == 0 && v == (expected)) pass++;                               \
    else {fail++; printf("FALHOU: \"%s\", r=%d v=%d (esperado: %d)\n",  \
        input, r, v, (expected));}                                      \
} while(0);

#define CHECK_ERR(input) do {                                           \
    int v = 0;                                                          \
    int r = stoi(input, &v);                                            \
    if(r != 0) pass++;                                                  \
    else {fail++; printf("FALHOU: \"%s\", deveria dar erro (v=%d)\n",   \
        input, v);}                                                     \
} while(0);

int main(void)
{
    CHECK_OK("1024", 1024);
    CHECK_OK("0", 0);
    CHECK_OK("-90", -90);
    CHECK_OK("-1", -1);
    CHECK_OK("+5", 5);
    CHECK_ERR("");
    CHECK_ERR("-");
    CHECK_ERR("+");
    CHECK_ERR("+-23");
    CHECK_ERR("12a");

    printf("%d passaram, %d falharam\n", pass, fail);
    return fail != 0;
}