#include <stdio.h>

#define  IN   1                 /* 在单词内     */
#define  OUT  0                 /* 在单词外     */

/* 编写一个程序，以每行一个单词的形式打印其输入 */
main()
{
	int c, state;
	
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				putchar('\n');  /* 单词结束     */
				state = OUT;
			}
		} else if (state == OUT) {
			state = IN;         /* 单词开始     */
			putchar(c);
		} else                  /* 单词内部     */
			putchar(c);
	}
}