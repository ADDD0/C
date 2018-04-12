/* 输出以下的杨辉三角形(要求输出10行) */
#include <stdio.h>

#define  LINE  16

main()
{
    int row, col;
    int num[LINE][LINE] = {0};

    for (row = 0; row < LINE; ++row) {
        for (col = 0; col < LINE; ++col) {
            if (col == 0)
                num[row][col] = 1;
            else if (row)
                num[row][col] = num[row - 1][col - 1] + num[row - 1][col];
            if (num[row][col])
                printf("%4d ", num[row][col]);
        }
    printf("\n");
    }
}