/* 有一个已排好序的数组,要求输入一个数后,按原来排序的规律将它插入数组中 */
#include <stdio.h>

#define  LENGTH  20

/* 假设这是一个升序数列 */
main()
{
	int i, j, new;
	int num[LENGTH]={1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
	
	while ((new = getchar()) != EOF) {
		for (i = 0; i < LENGTH - 1; ++i) {
			if (new >= num[i] && new <= num[i + 1]) {
				for (j = LENGTH; j > i; --j)
					num[j] = num[j - 1];
			}
			num[j] = c;
		}
	}
}