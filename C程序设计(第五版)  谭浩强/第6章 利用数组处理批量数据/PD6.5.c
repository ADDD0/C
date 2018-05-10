/* 将一个数组中的值按逆序重新存放 */
#include <stdio.h>

#define  LENGTH  10

main()
{
    int i, t;
    int num[LENGTH] = {8, 6, 5, 4, 1};

    for (i = 0; i < LENGTH; ++i)
        printf("%d ", num[i]);
    printf("\n");
    for (i = 0; i < LENGTH / 2; ++i) {
        t = num[i], num[i] = num[LENGTH - 1 - i], num[LENGTH - 1 - i] = t;
    }
    for (i = 0; i < LENGTH; ++i)
        printf("%d ", num[i]);
    printf("\n");
}