/* 输入4个整数,要求按由小到大的顺序输出     */
#include <stdio.h>

main()
{
    int a, b, c, d, t;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a > b)
        t = a, a = b, b = t;
    if (b > c)
        t = b, b = c, c = t;
    if (c > d)
        t = c, c = d, d = t;
    if (a > b)
        t = a, a = b, b = t;
    if (b > c)
        t = b, b = c, c = t;
    if (a > b)
        t = a, a = b, b = t;
    printf("%d %d %d %d\n", a, b, c, d);
    printf("%d %d %d %d\n", d, c, b, a);
}