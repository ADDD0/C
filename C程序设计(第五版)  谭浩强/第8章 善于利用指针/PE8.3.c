/* 输入10个整数,将其中最小的数与第一个数对换,把最大的数与最后一个数对换
写3个函数:①输入10个数;②进行处理;③输出10个数                          */
#include <stdio.h>

#define  N  10

main()
{
    void input(int *p);
    void trans(int *p);
    void output(int *p);

    int a[N];

    input(a);
    trans(a);
    output(a);
}

void input(int *p)
{
    int i;

    for (i = 0; i < N; ++i)
        scanf("%d", p + i);
}

void trans(int *p)
{
    int i, t;
    int *max, *min;

    max = min = p;
    for (i = 0; i < N; ++i) {
        if (*(p + i) > *max)
            max = p + i;
        if (*(p + i) < *min)
            min = p + i;
    }
    t = *p, *p = *max, *max = t;
    t = *(p + N - 1), *(p + N - 1) = *min, *min = t;
}

void output(int *p)
{
    int i;

    for (i = 0; i < N; ++i)
        printf("%d ", *(p + i));
    printf("\n");
}