#include <stdio.h>

#define  DAYS  10

/* 猴子吃桃问题
猴子第1天摘下若干个桃子,当即吃了一半,
还不过瘾,又多吃了一个.第2天早上又将
剩下的桃子吃掉一半,又多吃了一个.以后
每天早上都吃了前一天剩下的一半零一个
到第10天早上想再吃时,就只剩一个桃子了
求第1天共摘多少个桃子 */
main()
{
    int n, sum;

    for (n = DAYS - 1, sum = 1; n > 0; --n)
        sum = 2 * (sum + 1);
    printf("%d\n", sum);
}