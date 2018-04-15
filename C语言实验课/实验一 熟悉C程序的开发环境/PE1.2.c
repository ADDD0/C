/* 已知a,b,c,d,编程找出这四个数中的最大值并输出                   */
#include <stdio.h>

main()
{
    int a, b, c, d, max;

    a = 9, b = 19, c = 99, d =13;
    max = a < b ? b : a;      /* 也可以使用三次if比较得出(更简便) */
    max = max < c ? c : max;  /* 这里是为了巩固下三目运算符的应用 */
    max = max < d ? d : max;
    printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
    printf("max=%d\n", max);
}