#include <stdio.h>

/*	编写一个程序，把较长的输入行“折”成短一些的两行或
多行，折行的位置在输入行的第n列之前的最后一个非空格之后*/
main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar('\n');
			while ((c = getchar()) == ' ') {
				;
			}
		}
		putchar(c);
	}
}