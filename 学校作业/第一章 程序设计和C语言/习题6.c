#include <stdio.h>

main()
{
	int a, b, c;
	scanf("%d, %d, %d", &a, &b, &c);
	if(a > b)
		b = a;
	if(b > c)
		c = b;
	printf("max=%d\n", c);
}
