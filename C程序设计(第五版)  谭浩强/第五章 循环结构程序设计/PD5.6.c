/* 求1!+2!+3!+4!+…+20! */
#include <stdio.h>

#define  LIMIT  20

main()
{
    int n, i, j, sum;

    for (n = LIMIT, sum = 0; n > 0; --n) {
        for (i = j = n; j > 1; --j)
            i *= (j - 1);
        sum += i;
    }
    printf("%d\n", sum);
}