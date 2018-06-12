/* 编写一个统计空格,制表符与换行符个数的程序 */
#include <stdio.h>

/* count blanks, tabs, and newlines          */
main()
{
    int c, nb, nt, nl;

    nb = 0;  /* number of blanks             */
    nt = 0;  /* number of tabs               */
    nl = 0;  /* number of newlines           */
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("%d %d %d\n", nb, nt, nl);
}