#include <stdio.h>

/* ��֤���ʽgetchar()!=EOF��ֵ��0����1 */
main()
{
	int c;
	
	while (c = getchar() != EOF)
		printf("%d\n", c);
	printf("%d - EOF\n", c);
}