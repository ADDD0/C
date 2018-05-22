#include <stdio.h>

#define  N  15  /* 使用静态数组(对创建动态数组不是很熟悉,怕出错) */

main()
{
    int n;
    int row, col;
    int num[N][N] = {0};

    scanf("%d", &n);
    for (row = 0; row < n; ++row) {
        for (col = 0; col < row + 1; ++col) {
            if (!col)
                num[row][col] = 1;
            else if (row)
                num[row][col] = num[row - 1][col - 1] + num[row - 1][col];
            if (num[row][col])
                printf("%-5d", num[row][col]);
        }
        printf("\n");
    }
}