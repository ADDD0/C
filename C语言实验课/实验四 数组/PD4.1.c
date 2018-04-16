/* 用熟悉的一种排序方法对10个整数按照从小到大的顺序排序,输出排序后的结果
待排序的10个整数要求用scan()函数从键盘输入                               */
#include <stdio.h>

main()
{
    int i, j, t;
    int a[10];

    for (i = 0; i < 10; ++i)
        scanf("%d", &a[i]);
    for (i = 0; i < 9; ++i)
        for (j = 0; j < 9 - i; ++j)
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;3
            }
    for (i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    printf("\n");
}