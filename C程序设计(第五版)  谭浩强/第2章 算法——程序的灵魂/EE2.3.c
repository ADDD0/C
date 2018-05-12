/* 判定2000-2500年中的哪一年是闰年    */
#include <stdio.h>

#define  LOWER  2000
#define  UPPER  2500

main()
{
    int year, n;

    for (year = LOWER, n = 1; year <= UPPER; year += 4, ++n) {
        if (year % 4 == 0 && year % 100 || year % 400 == 0)
            printf("%5d", year);
        else
            printf("     ");
        if (!(n % 8))  /* 满8个换一行 */
            putchar('\n');
    }
    printf("\n");
}