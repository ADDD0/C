/* 求1!+2!+3!+4!+…+20! */
#include <stdio.h>

#define  LIMIT  20

main()
{
    int i, j, sum;

    for (i = j = 1, sum = 0; j <= LIMIT; ++j) {
		i *= j;
        sum += i;
    }
    printf("%ld\n", sum);
}