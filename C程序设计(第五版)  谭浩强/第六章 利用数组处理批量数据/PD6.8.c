/* 找出一个二维数组中的鞍点,即该位置上的元素在该行上最大,在该列上最小 */
#include <stdio.h>

#define  ROW     3
#define  COLUMN  3
const int a[ROW][COLUMN] = {{3, 7, 5},{1, 4, 2},{8, 6, 9}};

main()
{
    int row, col, i, rowMax, colMin, max, min;

    for (row = 0; row < ROW; ++row) {
        max = 0;
        for (col = 0; col < COLUMN; ++col)
            if (a[row][col] > max) {
                max = a[row][col];
                rowMax = row;
                colMin = col;
            }
        min = max;
        for (i = 0; i < ROW; ++i)
            if (a[i][colMin] < min) {
                min = a[i][colMin];
                break;
            }
        if (min == max) {
            printf("row=%d, colume=%d\nthe value is %d\n", rowMax, colMin, max);
            break;
        }
    }
}