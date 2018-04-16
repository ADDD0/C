/* 有一个已排好序的数组,要求输入一个数后,按原来排序的规律将它插入数组中 */
#include <stdio.h>

#define  LENGTH  20           /* 数组长度,最多能输入LENGTH-10个数字     */

/* 假设这是一个升序数列                                                 */
main()
{
    int i, j, new;
    int num[LENGTH]={4, 9, 16, 25, 36, 49, 64, 81, 100};

    for (i = 0; i < LENGTH && num[i]; ++i)
        printf("%d ", num[i]);
    printf("\n");
    while (1) {
        scanf("%d", &new);
        if (!new)             /* 输入0结束循环                          */
            break;
        for (i = LENGTH - 1; i >= 0; --i) {
            if (!(num[i]))
                continue;
            if (new < num[i])
                num[i + 1] = num[i];
            else {
                num[i + 1] = new;
                break;
            }
            if (i == 0)
                num[0] = new;
        }
        for (i = 0; i < LENGTH && num[i]; ++i)
            printf("%d ", num[i]);
        printf("\n");
    }


}