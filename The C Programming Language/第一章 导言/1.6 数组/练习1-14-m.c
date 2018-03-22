#include <stdio.h>
#include <ctype.h>

#define  MAXHIST  15	/* 	直方图最大长度 				*/
#define  MAXCHAR  128	/* 	不同字符个数 				*/

/* 	编写一个程序，打印输入中各个字符出现频度的直方图	*/
/* 	垂直方向直方图										*/
main()
{
	int c, i, j;
	int maxvalue;		/*	cc[]的最大值 				*/
	int cc[MAXCHAR];	/*	字符计数器 					*/
	
	for (i = 0; i < MAXCHAR; ++i)
		cc[i] = 0;
	while ((c = getchar()) != EOF)
		if (c < MAXCHAR)
			++cc[c];
	maxvalue = 0;
	for (i = 0; i < MAXCHAR; ++i)
		if (cc[i] > maxvalue)
			maxvalue = cc[i];

	for (i = MAXHIST; i > 0; --i) {
		for (j = 1; j < MAXCHAR; ++j)
			if (cc[j] * MAXHIST / maxvalue >= i)
				printf("  * ");
			else if (cc[j] > 0)
				printf("    ");
		putchar('\n');
	}
	for (i = 1; i < MAXCHAR; ++i)
		if (cc[i] != 0)
			printf("%4d", i);
	putchar('\n');
	for (i = 1; i < MAXCHAR; ++i)
		if (cc[i] != 0) {
			if (isprint(i))
				printf("%3c ", i);
			else
				printf("    ");
		}
	putchar('\n');
	for (i = 1; i < MAXCHAR; ++i)
		if (cc[i] != 0)
			printf("%3d ", cc[i]);
	putchar('\n');
}
