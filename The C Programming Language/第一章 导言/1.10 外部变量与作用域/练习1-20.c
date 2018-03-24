#include <stdio.h>

#define  TABINC  8               /* 制表符增量       */

/* 编写程序detab，将输入中的制表符替换成适当
数目的空格，使空格充满到下一个制表符终止位的地方     */
main()
{
	int c, nb, pos;
	
	nb = 0;                      /* 必要的空格数     */
	pos = 0;                     /* 行列中的字符位置 */
	while ((c = getchar()) != EOF) {
		if (c == '\t') {         /* 制表符           */
			nb = TABINC - pos % TABINC;
			while (nb > 0) {
				putchar(' ');
				++pos;
				--nb;
			}
		} else if (c == '\n') {  /* 换行符           */
			putchar(c);
			pos = 0;
		} else {                 /* 所有其余字符     */
			putchar(c);
			++pos;
		}
	}
}