/* 用筛选法求100之内的素数                                     */
#include <stdio.h>
#include <math.h>

#define  MAX  1000

main()
{
    int num[MAX];
    int i, j, count;

    for (i = 2; i < MAX; ++i)
        num[i] = 1;
    for (i = 2; i < sqrt(MAX); ++i)
        for (j = 2 * i; j < MAX; j += i)
            num[j] = 0;  /* 令所有(根号n以下的正整数)的倍数为0 */
    for (i = 2; i < MAX; ++i)
        if (num[i]) {
            printf("%4d ", i);
            ++count;
            if (!(count % 15))
                printf("\n");
        }
    printf("\n");
}