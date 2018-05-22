#include <stdio.h>

main()
{
    int a[10];
    int i, sum, aver;

    for (i = 0; i < 10; ++i)
        scanf("%d", &a[i]);
    for (i = sum = 0; i < 10; ++i)
        sum += a[i];
    aver = sum / 10;
    for (i = 0; i < 10; ++i)
        if (a[i] > aver)
            printf("%d ", a[i]);
    printf("\n");
}