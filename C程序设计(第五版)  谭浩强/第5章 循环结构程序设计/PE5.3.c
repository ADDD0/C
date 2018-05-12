/* 输入两个正整数m和n,求其最大公约数和最小公倍数 */
#include <stdio.h>

main()
{
    int m, n, r, temp;

    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    temp = m * n;
    while (r) {  /* 辗转相除法                   */
        m = n;
        n = r;
    }
    printf("%d\n", n);
    printf("%d\n", temp / n);
}