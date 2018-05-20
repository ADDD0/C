/* 将一个5×5的矩阵中最大的元素放在中心,4个角分别放4个最小的元素
(顺序为从左到右,从上到下依次从小到大存放),写一函数实现之.用main函数调用 */
/* 能正确处理所有情况                                */
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

    for (i = 0, min[i] = p + i; i < 4; ++i)
		for (j = i; j < N * N; ++j) {
			if (*min[i] < *(p + j))
			
		}
	
	min[0] = max = p;
    for (i = 0; i < N * N; ++i)                             /* 找出最小值并交换位置 */
        if (*(p + i) < *(min[0]))
            min[0] = p + i;
    t = *p, *p = *(min[0]), *(min[0]) = t, min[0] = p;      /* 将p的值赋给min[0]    */
    for (i = 0; i < N * N; ++i)                             /* 找出最大值并交换位置 */
        if (*(p + i) > *max)
            max = p + i;
    t = *(p + N * N / 2), *(p + N * N / 2) = *max, *max = t, max = p + N * N / 2;
    /* 将p+N*N/2的值赋给max                                                         */
    min[1] = min[2] = min[3] = max;
    for (i = 1; i < 4; ++i) {
    /* 每次循环找出一个最小值并交换位置                                             */
        for (j = 0; j < N * N; ++j)
            if (*(min[i - 1]) < *(p + j) && *(p + j) < *(min[i]))
                min[i] = p + j;
            /* 核心:找出最小值min[i]的条件为min[i]存在且大于min[n-1]                */
        q = swap(p, i);                                     /* 交换时的位置         */
        t = *q, *q = *(min[i]), *(min[i]) = t, min[i] = q;  /* 将q的值赋给min[i]    */
    }
}

int *swap(int *p, int n)
{
    switch (n) {
        case 1: return p + N - 1;                           /* 右上角               */
        case 2: return p + N * N - N;                       /* 左下角               */
        case 3: return p + N * N - 1;                       /* 右下角               */
    }
}