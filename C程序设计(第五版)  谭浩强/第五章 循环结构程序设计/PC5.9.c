#include <stdio.h>

/* 一个数如果恰好等于它的因子之和,这个数就称为"完数"
   编程序找出1000以内的完数,并按下面格式输出其因子:
   6 its factors are 1,2,3                           */
main()
{
    int n, i, j, sum;

    for (n = sum = 1; n < 1000; ++n) {
        for (i = n - 1; i > 1; --i) {
            j = n / i;
            if (n == j * i) {
                if (j != i)
                    sum += j;
                else
                    sum += (j + i);
            }
        }
        if (n == sum) {
            printf("%d its factors are 1", n);
            for (i = n - 1; i > j; --i) {
                j = n / i;
                if (n == j * i)
                    printf(",%d,%d", j, i);
            }
            printf("\n");
        }
        sum = 1;
    }
}