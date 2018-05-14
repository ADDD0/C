/* 将一个5×5的矩阵中最大的元素放在中心,4个角分别放4个最小的元素
(顺序为从左到右,从上到下依次从小到大存放),写一函数实现之.用main函数调用 */
#include <stdio.h>

#define  N  3

main()
{
	void trans(int *p);
	
	int a[N][N];
	int i, j;
	
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			scanf("%d", *(*(a + i) + j));
	sort(a);
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j)
			print("%d ", *(*(a + i) + j));
		printf("\n");
	}
}

void sort(int *p)
{
	int *max, *min1, *min2, *min3, *min4;
	int i, j, t;
	
	for (i = 0; i < N * N; ++i)
		for (j = i; j < N * N - 1; ++j)
			if (*(p + j) > *(p + j + 1))
				t = *(p + j), *(p + j) = *(p + j + 1), *(p + j + 1) = t;
	max = *(p + i / 2);
	min1 = *p;
	min2 = *(p + N - 1);
	min3 = *(p + N * N - N);
	min4 = *(p + N * N - 1);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			if (*(*(a + i) + j) > *max)
				max = *(a + i) + j;
			else 
		}
			
}