#include <stdio.h>
#include <math.h>

#define	 MAX  1000

main() 
{
	int n;
	
	printf("������һ��С��1000����������");
	scanf("%d", &n);
	while (!(n > 0 && n < MAX)) {
		printf("\n���������룺");
		scanf("%d", &n);
	}
	printf("%.2f", sqrt(n));
}