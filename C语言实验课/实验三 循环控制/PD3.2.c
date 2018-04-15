/* 编程找出1000以内最小的10个素数与最大的10个素数
输出这20个素数及这20个素数之和
具体输出形式为:
最小素数:素数1,素数2,……,素数10
最大素数:素数1,素数2,……,素数10
素数之和:和的具体值                                                          */
#include <stdio.h>
#include <math.h>

#define  MAX  1000

main()
{
    int num[MAX];
    int i, j, count, sum;

    for (i = 2; i < MAX; ++i)
        num[i] = i;
    for (i = 2; i < sqrt(MAX); ++i) {  /* 筛选法求素数                       */
        for (j = 2 * i; j < MAX; j += i)
            num[j] = 0;                /* 令所有(根号n以下的正整数)的倍数为0 */
    }
    sum = 0;
    for (i = count = 1; count < 11; ++i) {
        if (num[i]) {
            printf("%4d", num[i]);
            ++count;
            sum += num[i];
        }
    }
    printf("\n");
    for (i = MAX - 1; count > 1; --i) {  /* 初始化count为11                  */
        if (num[i]) {
            printf("%4d", num[i]);
            --count;
            sum += num[i];
        }
    }
    printf("\nsum=%d\n", sum);
}