/* 一个数如果恰好等于它的因子之和,这个数就称为"完数"
编程序找出1000以内的完数,并按下面格式输出其因子:
6 its factors are 1,2,3                              */
#include <stdio.h>
#include <math.h>

main()
{
    int n, i, sum;

    for (n = 1; n < 1000; ++n) {
        sum = 1;
        for (i = 2; i < n / 2 + 1; ++i)
            if (n % i == 0)
                sum += i;
        if (n == sum) {
            printf("%d its factors are 1", n);
            for (i = 2; i < n / 2 + 1; ++i)
                if (n % i == 0)
                    printf(",%d", i);
            printf("\n");
        }
    }
}