#include <stdio.h>
#include <math.h>

#define	 MAX  1000

main() 
{
	int n;
	
	printf("请输入一个小于1000的正整数：");
	scanf("%d", &n);
	while (!(n > 0 && n < MAX)) {
		printf("\n请重新输入：");
		scanf("%d", &n);
	}
	printf("%.2f", sqrt(n));
}