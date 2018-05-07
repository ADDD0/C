/* 给一个正整数,要求:
1.求出它是几位数
2.分别输出每一位数字
3.按逆序输出各位数字 */
#include <stdio.h>

main()
{
    int n, count;

    count = 0;
    scanf("%d", &n);
    while (n) {
        printf("%d", n % 10);
        n /= 10;
        ++count;
    }
    printf("\n%d\n", count);
}