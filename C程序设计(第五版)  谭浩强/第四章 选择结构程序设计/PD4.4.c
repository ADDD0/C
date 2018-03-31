#include <stdio.h>

/* 有3个整数a,b,c,由键盘输入,输出其中最大的数 */
main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
        b = a;
    if (b > c)
        c = b;
    printf("max=%d", c);
}