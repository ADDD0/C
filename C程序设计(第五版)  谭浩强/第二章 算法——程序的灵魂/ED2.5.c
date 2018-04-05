#include <stdio.h>
#include <math.h>

/* 给出一个大于或等于3的正整数,判断它是不是一个素数 */
main()
{
    int i, judge;
    double n;

    judge = 1;
    scanf("%lf", &n);
    for (i = 2; i < (int)sqrt(n) + 1; ++i)
    {
        if ((int)n % i == 0)
        {
            judge = 0;
            break;
        }
    }
    if (judge)
        printf("%.0f is a prime number\n", n);
    else
        printf("%.0f is not a prime number\n", n);
}