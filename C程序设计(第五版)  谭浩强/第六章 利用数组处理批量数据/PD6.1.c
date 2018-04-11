/* 用筛选法求100之内的素数 */
#include <stdio.h>
#include <math.h>

#define  MAX  1000

main()
{
    int num[MAX];
    int i, j, count;

    for (i = 2; i < MAX; ++i)
        num[i] = i;
    for (i = 2; i < sqrt(MAX); ++i) {
        for (j = 2 * i; j < MAX; j += i)
            num[j] = 0;
    }
    for (i = 2; i < MAX; ++i) {
        if (num[i]) {
            printf("%4d ", num[i]);
            ++count;
            if (!(count % 15))
                printf("\n");
        }
    }
    printf("\n");
}