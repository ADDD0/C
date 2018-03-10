#include <stdio.h>

/* 验证表达式getchar()!=EOF的值是0还是1 */
main()
{
	int c;
	
	while (c = getchar() != EOF)
		printf("%d\n", c);
	printf("%d - EOF\n", c);
}