/* 输出所有的"水仙花数",所谓"水仙花数"是指一个3位数,其各位数字立方和等于该数本身 */
#include <stdio.h>
#include <math.h>

main()
{
    int n;

    for (n = 100; n < 1000; ++n) {
        if (n == pow(n % 10, 3) + pow(n / 10 % 10, 3) + pow(n / 100, 3) )
            printf("%d\n", n);
    }
}