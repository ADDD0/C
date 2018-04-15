#include <stdio.h>
#include <math.h>

/* 给出一个大于或等于3的正整数,判断它是不是一个素数 */
main()
{
    int n, i, judge;

    judge = 1;
    scanf("%d", &n);
    for (i = 2; i < sqrt(n) + 1; ++i)
    {
        if (n % i == 0)
        {
            judge = 0;
            break;
        }
    }
    if (judge)
        printf("%d is a prime number\n", n);
    else
        printf("%d is not a prime number\n", n);
}