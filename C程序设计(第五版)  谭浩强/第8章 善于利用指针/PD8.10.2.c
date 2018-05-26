/* 将一个5×5的矩阵中最大的元素放在中心,4个角分别放4个最小的元素
(顺序为从左到右,从上到下依次从小到大存放),写一函数实现之.用main函数调用               */
/* 会破坏原来的数组结构,所有元素从左到右,从上到下依次从小到大存放                     */
#include <stdio.h>

#define  N  5

main()
{
    void sort(int *p1, int *p2);

    int a[N * N], b[N * N];
    int i, j;

    for (i = 0; i < N * N; ++i)
        scanf("%d", a + i);
    sort(a, b);
    for (i = 0; i < N * N; ++i) {
        if (!(i % N))
            printf("\n");
        printf("%d ", *(b + i));
    }
    printf("\n");
}

void sort(int *p1, int *p2)
{
    int i, j, t;

    for (i = 0; i < N * N - 1; ++i)
        for (j = 0; j < N * N - 1 - i; ++j)
            if (*(p1 + j) > *(p1 + j + 1))
                t = *(p1 + j), *(p1 + j) = *(p1 + j + 1), *(p1 + j + 1) = t;
    *p2 = *p1;
    *(p2 + N - 1) = *(p1 + 1);
    *(p2 + N * N - N) = *(p1 + 2);
    *(p2 + N * N - 1) = *(p1 + 3);
    *(p2 + N * N / 2) = *(p1 + N * N - 1);
    for (i = 0, p1 += 4; i < N * N; ++i)  /* 向数组中不在四个角落及中心的位置依次赋值 */
        if (p2 + i != p2 && p2 + i != p2 + N - 1 &&
    p2 + i != p2 + N * N - N && p2 + i != p2 + N * N - 1 &&
    p2 + i != N * N / 2)
            *(p2 + i) = *p1++;
}