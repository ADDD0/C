/* 编写程序entab,将空格串替换为最少数量
的制表符和空格,但要保持单词之间的间隔不变                */
#include <stdio.h>

#define  TABINC  8              /* tab increment size    */

/* replace strings of blanks with tabs and blanks        */
main()
{
    int c, nb, nt, pos;

    nb = 0;                     /* # of blanks necessary */
    nt = 0;                     /* # of tabs necessary   */
    for (pos = 1; (c = getchar()) != EOF; ++pos)
        if (c == ' ') {
            if (pos % TABINC != 0)
                ++nb;           /* increment # of blanks */
            else {
                nb = 0;         /* reset # of blanks     */
                ++nt;           /* one more tab          */
            }
        } else {
            for ( ; nt > 0; --nt)
                putchar('\t');  /* output tab(s)         */
            if (c == '\t')      /* forget the blank(s)   */
                nb = 0;
            else                /* output blank(s)       */
                for ( ; nb > 0; --nb)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                pos = pos + (TABINC - (pos-1) % TABINC) - 1;
        }
}