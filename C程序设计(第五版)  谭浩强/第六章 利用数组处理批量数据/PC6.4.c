/* 有一个已排好序的数组,要求输入一个数后,按原来排序的规律将它插入数组中 */
#include <stdio.h>

#define  LENGTH  20           /* 数组长度,最多能输入LENGTH-10个数字     */

/* 假设这是一个升序数列                                                 */
main()
{
    int i, j, new, max = 100;
    int num[LENGTH]={4, 9, 16, 25, 36, 49, 64, 81, max};

    for (i = 0; i < LENGTH && num[i]; ++i)
        printf("%d ", num[i]);
    printf("\n");
    while (1) {
        scanf("%d", &new);
        if (!new)             /* 输入0结束循环                          */
            break;
        if (new <= num[0]) {  /* 先判断再插入                           */
            for (i = LENGTH - 1; i > 0; --i)
                num[i] = num[i - 1];
            num[0] = new;
        } else if (new >= max) {
            max = new;
            for (i = LENGTH - 1; !num[i]; --i)
                ;
            num[++i] = new;
        } else {
            for (i = 0; i < LENGTH; ++i)
                if (new >= num[i] && new <= num[i + 1]) {
                    for (j = LENGTH - 1; j > i; --j)
                        num[j] = num[j - 1];
                    num[++j] = new;
                    break;
                }
        }
        for (i = 0; i < LENGTH && num[i]; ++i)
            printf("%d ", num[i]);
        printf("\n");
    }
    printf("\n");
}