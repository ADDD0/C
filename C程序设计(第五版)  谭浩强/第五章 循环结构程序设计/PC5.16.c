/* 输出以下图案:
      *
     ***
    *****
   *******
    *****
     ***
      *          */
#include <stdio.h>

#define  LINE  80

main()
{
    int n, i;

    for (n = LINE; n > 0; --n) {
        for (i = n - 1; i > 0; --i)
            putchar(' ');
        for (i = 2 * (LINE - n) + 1; i > 0; --i)
            putchar('*');
        putchar('\n');
    }
    for (n = LINE - 1; n > 0; --n) {
        for (i = LINE - n; i > 0; --i)
            putchar(' ');
        for (i = 2 * (n - 1) + 1; i > 0; --i)
            putchar('*');
        putchar('\n');
    }
}