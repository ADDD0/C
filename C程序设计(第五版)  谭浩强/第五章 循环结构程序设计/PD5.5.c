#include <stdio.h>

/* 求S=a+aa+aaa+…+aa…a(n个a)之值,其中a是一个数字,n表示a的位数,n由键盘输入 */
main()
{
    int a, n, i, sum;

    scanf("%d", &n);
    for (a = 2, i = sum = 0; n > 0; --n) {
        i = i * 10 + a;
        sum += i;
    }
    printf("%d", sum);
}