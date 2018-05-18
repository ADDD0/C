/* 有n个人围成一圈,顺序排号.从第1个人开始报数(从1到3报数),
凡报到3的人退出圈子,问最后留下的是原来第几号的那位         */
#include <stdio.h>

#define  N  20

main()
{
    int a[N];
    int *p, i, flag, n;

    for (p = a; p < a + N; ++p)
        *p = 1;
    n = N;
    flag = 1;
    while (n - 1)
        for (p = a; p < a + N; ++p)
            if (*p) {
                if (flag == 3) {
                    *p = 0;
                    --n;
                    flag = 1;
                }
                else
                    ++flag;
            }
    for (i = 0; i < N; ++i)
        if (*(a + i))
            printf("%d\n", i + 1);
}