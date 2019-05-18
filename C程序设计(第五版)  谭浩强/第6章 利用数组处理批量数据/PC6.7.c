/* 输出"魔方阵"
所谓魔方阵是指这样的方阵,
它的每一行,每一列和对角线之和均相等
例如,三阶魔方阵为
    8  1  6
    3  5  7
    4  9  2
要求输出1~n*n的自然数构成的魔方阵 */
#include <stdio.h>

#define  N  5

/* 只能输出奇数平方               */
main()
{
    int a[N][N] = {0};
    int count = 0;
    int row = 0, col = N / 2;
    int i = row, j = col;

    while (count++ <= N * N) {
        a[row][col] = count;
        if (i == 0)
            i = N - 1;
        else
            --i;
        j = (j + 1) % N;
        if (a[i][j] || row == 0 && col == N-1) {
            i = row + 1;
            j = col;
        }
        row = i;
        col = j;
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j)
            printf("%3d",a[i][j]);
        printf("\n");
    }
}