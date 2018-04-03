#include <stdio.h>

/* 求1!+2!+3!+4!+…+20! */
main()
{
    int n, i, j, sum;

    for (n = 20, sum = 0; n > 0; --n) {
        for (i = j = n; j > 1; --j)
            i *= (j - 1);
        sum += i;
    }
    printf("%d\n", sum);
}