/* 求S=a+aa+aaa+…+aa…a(n个a)之值,其中a是一个数字,n表示a的位数,n由键盘输入 */
#include <stdio.h>

#define  A  2

main()
{
    int a, n, i, sum;

    scanf("%d", &n);
    for (a = A, i = sum = 0; n > 0; --n, sum += i)
        i = i * 10 + a;
    printf("%d\n", sum);
}