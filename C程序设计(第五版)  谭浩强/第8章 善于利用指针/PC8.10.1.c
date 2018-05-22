/* 将一个5×5的矩阵中最大的元素放在中心,4个角分别放4个最小的元素
(顺序为从左到右,从上到下依次从小到大存放),写一函数实现之.用main函数调用         */
/* 尽可能不破坏原来的数组结构                                                   */
#include <stdio.h>

#define  N  5

main()
{
    void sort(int *p);

    int a[N * N];
    int i, j;

    for (i = 0; i < N * N; ++i)
        scanf("%d", a + i);
    sort(a);
    for (i = 0; i < N * N; ++i) {
        if (!(i % N))
            printf("\n");
        printf("%d ", *(a + i));
    }
    printf("\n");
}

void sort(int *p)
{
    int *swap(int *p, int n);

    int *min[4], *max, *q;
    int i, j, k, t;

    for (i = 0, max = p; i < N * N; ++i)                /* 找出最大值并交换位置 */
        if (*(p + i) > *max)
            max = p + i;
    t = *(p + N * N / 2), *(p + N * N / 2) = *max, *max = t, max = p + N * N / 2;
    /* 将p+N*N/2的值赋给max                                                     */
    min[0] = min[1] = min[2] = min[3] = max;
    for (i = 0; i < 4; ++i) {
    /* 每次循环找出一个最小值并交换位置                                         */
        for (j = 1; j < N * N; ++j) {
            for (k = i; k > 0; --k)                     /* 跳过前i个最小值      */
                if (p + j == min[k])
                    j++;
            if (*(p + j) <= *min[i])
                min[i] = p + j;
        }
        q = swap(p, i);                                 /* 交换时的位置         */
        t = *q, *q = *min[i], *min[i] = t, min[i] = q;  /* 将q的值赋给min[i]    */
    }
}

int *swap(int *p, int n)
{
    switch (n) {
        case 0: return p;                               /* 左上角               */
        case 1: return p + N - 1;                       /* 右上角               */
        case 2: return p + N * N - N;                   /* 左下角               */
        case 3: return p + N * N - 1;                   /* 右下角               */
    }
}