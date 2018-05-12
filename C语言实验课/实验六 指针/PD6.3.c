/* 编写程序:找出5╳5矩阵对角线上元素中的最大值及其所在的位置(行号和列号)
要求如下:
//主函数                         用户自定义函数
void main()                      int my_find(int (*p)[5],int n,int *r,int *c)
{                                {
    int a[5][5],max,row,col;         在n个一维数组中找到最大值及其位置;
    输入待处理的二维数组;        }
    max=my_find(a,5,&row,&col);
    输出max,row,col中的值;
}                                                                             */
#include <stdio.h>

#define  N  5

main()
{
    int my_find(int (*p)[N], int n, int *r, int *c);
    int a[N][N], max, row, col;
    int *r, *c;

    for (row = 0; row < N; ++row)
        for (col = 0; col < N; ++col)
            scanf("%d", *(a + row) + col);
    r = &row;
    c = &col;
    max = my_find(a, N, r, c);
    printf("max=%d,row=%d,col=%d\n", max, row + 1, col + 1);
}

int my_find(int (*p)[N], int n, int *r, int *c)
{
    int i, max;
    int *p1, *p2;

    for (i = max = 0 ; i < n; ++i) {
        p1 = *(p + i) + i;
        p2 = *(p + i) + n - 1 - i;
        if (*p1 > max) {
            max = *p1;
            *r = i;
            *c = i;
        } else if (*p2 > max) {
            max = *p2;
            *r = i;
            *c = n - 1 - i;
        }
    }
    return max;
}