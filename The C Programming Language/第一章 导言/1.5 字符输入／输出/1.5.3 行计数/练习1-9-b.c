#include <stdio.h>

#define  NONBLANK  'a'

/*	编写一个将输入复制到输出的程序，
并将其中连续的多个空格用一个空格代替	*/
main()
{
	int c, lastc;
	
	lastc = NONBLANK
	while ((c = getchar()) != EOF) {
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
}