#include <stdio.h>

/* 给一个正整数,要求:
1.求出它是几位数
2.分别输出每一位数字
3.按逆序输出各位数字 */
main()
{
    int n, count;

	count = 0;
    scanf("%d", &n);
    while (n != 0) {
        printf("%d", n % 10);
        n /= 10;
        ++count;
    }
    printf("\n%d\n", count);
}