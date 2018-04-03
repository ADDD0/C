#include <stdio.h>

/* 输入两个正整数m和n,求其最大公约数和最小公倍数 */
main()
{
    int m, n, gy, temp;

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    temp = m * n;
    while (1) {
        if(!(m %= n)) {
            gy = n;
            break;
        }
        if(!(n %= m)) {
            gy = m;
            break;
        }
    }
    printf("%d\n", gy);
    printf("%d\n", temp / gy);
}