#include <stdio.h>

#define  LOWER  2000
#define  UPPER  2500

/* 判定2000-2500年中的哪一年是闰年    */
main()
{
    int year, n;

    for (year = LOWER, n = 1; year <= UPPER; year += 4, ++n)
    {
        if (year % 400 == 0)
            printf("%d ", year);
        else if (year % 4 == 0 && year % 100 != 0)
            printf("%d ", year);
        if (!(n % 8))  /* 满8个换一行 */
            putchar('\n');
    }
}