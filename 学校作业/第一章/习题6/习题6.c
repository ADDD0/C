#include<stdio.h>
int main()
{
	int max(int x, int y);
	int a, b, c;
	scanf("%d, %d, %d", &a, &b, &c);
	b = max(a, b);
	c = max(b, c);
	printf("max=%d", c);
	return 0;
}
int max(int x, int y)
{
	int z;
	if(x > y)z = x;
	else z = y;
	return z;
}