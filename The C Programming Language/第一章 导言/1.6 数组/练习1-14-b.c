#include <stdio.h>
#include <ctype.h>

#define  MAXHIST 15				  /* 直方图最大长度 */
#define  MAXCHAR 128				/* 不同字符个数 */

/* 编写一个程序，打印输入中各个字符出现频度的直方图 */
/* 水平方向直方图 									*/
main()
{
	int c, i;
	int len;						/* 每一条的长度 */
	int maxvalue;					/* cc[]的最大值 */
	int cc[MAXCHAR];				  /* 字符计数器 */
	
	for (i = 0; i < MAXCHAR; ++i)
		cc[i] = 0;
	while ((c = getchar()) != EOF)
		if (c < MAXCHAR)
			++cc[c];
	maxvalue = 0;
	for (i = 1; i < MAXCHAR; ++i)
		if (cc[i] > maxvalue)
			maxvalue = cc[i];
	
	for (i = 1; i < MAXCHAR; ++i) {
		if (isprint(i))
			printf("%5d - %c - %5d : ", i, i, cc[i]);
		else
			printf("%5d -   - %5d :", i, cc[i]);
		if (cc[i] > 0) {
			if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		} else
			len = 0;
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
}