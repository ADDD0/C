#include <stdio.h>

main()
{
    float a[5][5];
    int i, j;
    float sum;

    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j)
            scanf("%f", &a[i][j]);
    for (i = sum = 0; i < 5; ++i)
        sum += a[i][i] + a[i][4 - i];
    printf("%.2f\n", sum - a[2][2]);
}