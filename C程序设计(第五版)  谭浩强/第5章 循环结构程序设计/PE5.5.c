/* 求S=a+aa+aaa+…+aa…a(n个a)之值,其中a是一个数字,n表示a的位数,n由键盘输入 */
#include <stdio.h>

main()
{
    int a, n, tsum, sum;

    printf("Input a and n:");
    scanf("%d %d", &a, &n);
    for (tsum = sum = 0; n; --n) {
        tsum += a;
        a *= 10;
        sum += tsum;
    }
    printf("%d\n", sum);
}