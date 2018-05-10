/* 已知a,b,编程实现将a,b的值互换后输出 */
#include <stdio.h>

main()
{
    int a, b, t;

    a = 13, b = 9;
    printf("a=%d b=%d\n", a, b);
    t = a, a = b, b = t;
    printf("a=%d b=%d\n", a, b);
}