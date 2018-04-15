/* 输入一个3位数,编程将这个3位数的每一位
分解出来,并按照个位,十位,百位的顺序输出
例如:输入为957  输出为:7    5    9       */
#include <stdio.h>

main()
{
    int n;

    printf("Input a three-digit integer:");
    scanf("%d", &n);
    for ( ; n; n /= 10)
        printf("%3d", n % 10);
    printf("\n");
}