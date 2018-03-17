#include <stdio.h>

#define  MAXHIST 15					   /* 直方图最大长度 */
#define  MAXWORD 11						 /* 单词最大长度 */
#define  IN		 1							 /* 在单词内 */
#define  OUT	 0							 /* 在单词外 */

/* 编写一个程序，打印输入中单词长度的直方图。
水平方向的直方图比较容易绘制，垂直方向的直方图则要困难些 */
/* 垂直方向直方图 										 */
main()
{
	int c, i, j, nc, state;
	int maxvalue;						 /* wl[]的最大值 */
	int ovflow;							 /* 溢出单词数目 */
	int wl[MAXWORD];				   /* 单词长度计数器 */
	
	state = OUT;
	nc = 0;							 /* 单词中的字符个数 */
	ovflow = 0;			   /* 大于单词最大长度的单词个数 */
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0)
				if (nc < MAXWORD)
					++wl[nc];
				else
					++ovflow;
			nc = 0;
		} else if (state == OUT) {
			state = IN;
			nc = 1;						   /* 新单词开始 */
		} else
			++nc;							 /* 在单词内 */
	}
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];

	for (i = MAXHIST; i > 0; --i) {
		for (j = 1; j < MAXWORD; ++j)
			if (wl[j] * MAXHIST / maxvalue >= i)
				printf(" * ");
			else
				printf("   ");
		putchar('\n');
	}
	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", i);
	putchar('\n');
	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", wl[i]);
	putchar('\n');
	if (ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
}