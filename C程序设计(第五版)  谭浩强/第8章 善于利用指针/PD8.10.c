/* 将一个5×5的矩阵中最大的元素放在中心,4个角分别放4个最小的元素
(顺序为从左到右,从上到下依次从小到大存放),写一函数实现之.用main函数调用 */
#include <stdio.h>

#define  N  3

main()
{
    void sort(int *p);
    int *swap(int *p, int n);

    int a[N];
    int i, j;
	
	for (i = 0; i < N * N; ++i)
		scanf("%d", a + i);
    sort(a);
	for (i = 0; i < N * N; ++i) {
		if (i % N)
			printf("\n");
		printf("%d ", a + i);
	}
}

void sort(int *p)
{
    int i, j, t;
    int *min[4], *max, *q;

    *min[0] = *min[1] = *min[2] = *min[3] = *p;
	for (i = 0; i < 4; ++i) {/* 每次循环找出一个最小值并交换位置 */
        for (j = i; j < N * N; ++j)
            if (*(p + j) < *min[i])
                min[i] = p + j;
        q = swap(p, i);/* 交换时的位置 */
        t = *q, *q = *min[i], *min[i] = t;
    }
    for (i = 0; i < N * N; ++i)
        if (*(p + i) > *max)
            max = p + i;
    t = *(p + i / 2), *(p + i / 2) = *max, *max = t;
}

int *swap(int *p, int n)
{
    switch (n) {
        case 0: return p;
        case 1: return p + N - 1;
        case 2: return p + N * N - N;
        case 3: return p + N * N - 1;
    }
}