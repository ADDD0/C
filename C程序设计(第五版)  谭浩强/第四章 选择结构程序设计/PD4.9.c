#include <stdio.h>

/* 给一个正整数,要求:
   1.求出它是几位数
   2.分别输出每一位数字
   3.按逆序输出各位数字 */
main()
{
    int c, i, count;
    char re[count];

    count = 0;
    while ((c = getchar()) != '\n') {
        re[count] = c;
        ++count;
    }
    printf("%d", count);
    for (i = count; i >= 0; --i)
        printf("%c", re[i]);
}