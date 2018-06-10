/* 编写程序detab,将输入中的制表符替换成适当数目的空格
使空格充满到下一个制表符终止位的地方                              */
#include <stdio.h>

#define  TABINC  8               /* tab increment size            */

/* replace tabs with the proper number of blanks                  */
main()
{
    int c, nb, pos;

    nb = 0;                      /* number of blanks necessary    */
    pos = 0;                     /* position of character in line */
    while ((c = getchar()) != EOF) {
        if (c == '\t') {         /* tab character                 */
            nb = TABINC - pos % TABINC;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {  /* newline character             */
            putchar(c);
            pos = 0;
        } else {                 /* all other characters          */
            putchar(c);
            ++pos;
        }
    }
}