/* 编写一个程序,打印输入中各个字符出现频度的直方图        */
#include <stdio.h>
#include <ctype.h>

#define  MAXHIST  15   /* max length of histogram         */
#define  MAXCHAR  128  /* max different characters        */

/* print vertical histogram freq. of different characters */
main()
{
    int c, i, j;
    int maxvalue;      /* maximum value for cc[]          */
    int cc[MAXCHAR];   /* character counters              */

    for (i = 0; i < MAXCHAR; ++i)
        cc[i] = 0;
    while ((c = getchar()) != EOF)
        if (c < MAXCHAR)
            ++cc[c];
    maxvalue = 0;
    for (i = 0; i < MAXCHAR; ++i)
        if (cc[i] > maxvalue)
            maxvalue = cc[i];

    for (i = MAXHIST; i > 0; --i) {
        for (j = 1; j < MAXCHAR; ++j)
            if (cc[j] * MAXHIST / maxvalue >= i)
                printf("  * ");
            else if (cc[j] > 0)
                printf("    ");
        putchar('\n');
    }
    for (i = 1; i < MAXCHAR; ++i)
        if (cc[i] != 0)
            printf("%4d", i);
    putchar('\n');
    for (i = 1; i < MAXCHAR; ++i)
        if (cc[i] != 0) {
            if (isprint(i))
                printf("%3c ", i);
            else
                printf("    ");
        }
    putchar('\n');
    for (i = 1; i < MAXCHAR; ++i)
        if (cc[i] != 0)
            printf("%3d ", cc[i]);
    putchar('\n');
}
