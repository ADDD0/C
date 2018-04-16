/* 从键盘上输入一个4×4整数矩阵,以主对角线为对称轴,
将左下角的每一个数组元素与对应的右上角的数据元素进行比较
(例如a[2][1]与a[1][2]进行比较),将其中的较大者送入右上角对应位置,
最后输出该矩阵所有的右上角元素(含对角线上的数据)
例如:
    输入的矩阵为:       输出结果为:
    2   5   6   8       2   5   9   8
    3   9   5   7           9   5   8
    9   4   2   3               2   7
    6   8   7   5                   5                            */
#include <stdio.h>

main()
{
    int a[4][4];
    int i, j, t;

    for (i = 0; i < 4; ++i)
        scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    for (i = 0; i < 3; ++i)
        for (j = i + 1; j < 4; ++j)
            if (a[i][j] < a[j][i]) {
                t = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = t;
            }
    printf("\n");
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < i; ++j)
            printf("   ");
        for (j = i; j < 4; ++j)
            printf("%d  ", a[i][j]);
        printf("\n");
    }
    printf("\n");


}