#include <stdio.h>

/* 编写一个C程序,运行时输入a,b,c三个值,输出其中值最大者 */
main()
{
    int a, b, c;

    scanf("%d, %d, %d", &a, &b, &c);
    if (a > b)
        b = a;
    if (b > c)
        c = b;
    printf("max = %d\n", c);
}
