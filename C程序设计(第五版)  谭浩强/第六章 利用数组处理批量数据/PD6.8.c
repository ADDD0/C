/* 找出一个二维数组中的鞍点,即该位置上的元素在该行上最大,在该列上最小 */
#include <stdio.h>

main()
{
    int a[3][3] = {{3, 7, 5},{1, 4, 2},{8, 6, 9}};
    int row, col, i, maxrow, maxcol, max, min;

    for (row = 0; row < 3; ++row) {
        max = 0;
        for (col = 0; col < 3; ++col) {
            if (a[row][col] > max) {
                max = a[row][col];
                maxrow = row;
                maxcol = col;
            }
        }
        min = max;
        for (i = 0; i < 3; ++i) {
            if (a[i][maxcol] < min) {
                min = a[i][maxcol];
                break;
            }
        }
        if (min == max) {
            printf("row=%d, colume=%d\nthe value is %d\n", maxrow, maxcol, max);
            break;
        }

    }
}