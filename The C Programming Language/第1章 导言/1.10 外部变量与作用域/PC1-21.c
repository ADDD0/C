/* 编写程序entab,将空格串替换为最少数量
的制表符和空格,但要保持单词之间的间隔不变               */
#include <stdio.h>

#define  TABINC  8                  /* 制表符增量       */

/* 用制表符和空格替换字符串中的空格                     */
main()
{
    int c, nb, nt, pos;

    nb = 0;                         /* 必要的空格数     */
    nt = 0;                         /* 必要的制表符数目 */
    for (pos = 1; (c = getchar()) != EOF; ++pos)
        if (c == ' ') {
            if (pos % TABINC != 0)
                ++nb;               /* 增加空格数目     */
            else {
                nb = 0;             /* 重置空格数目     */
                ++nt;               /* 加一个制表符     */
            }
        } else {
                for ( ; nt > 0; --nt)
                    putchar('\t');  /* 输出制表符       */
                if (c == '\t')      /* 忽略空格         */
                    nb = 0;
                else                /* 输出空格         */
                    for ( ; nb > 0; --nb)
                        putchar(' ');
                putchar(c);
                if (c == '\n')
                    pos = 0;
                else if (c == '\t')
                    pos = pos + (TABINC - (pos-1) % TABINC) - 1;
        }
}