/* 求1!+2!+3!+4!+…+20! */
#include <stdio.h>

#define  LIMIT  20

main()
{
    int j;
    float fac, sum;

    for (fac = 1, j = sum = 0; j < LIMIT; ++j, fac *= j, sum += fac)
        ;
    printf("%e\n", sum);
}