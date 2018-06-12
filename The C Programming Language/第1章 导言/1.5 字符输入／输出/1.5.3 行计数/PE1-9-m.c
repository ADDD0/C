/* 编写一个将输入复制到输出的程序,并将其中连续的多个空格用一个空格代替 */
#include <stdio.h>

/* replace string of blanks with a single blank                        */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ') {
            while ((c = getchar()) == ' ')
                ;
            putchar(c);
        }
    }
}