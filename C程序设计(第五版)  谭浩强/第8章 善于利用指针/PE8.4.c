/* 有n个整数,使前面各数顺序向后移m个位置,最后m个数变成最前面m个数
写一函数实现以上功能,在主函数中输入n个整数和输出调整后的n个数     */
#include <stdio.h>

#define  N  9

main()
{
    void rightrot(int *p1, int *p2, int m);

    int a[N], b[N];
    int *p, m;

    printf("Please enter %d number:", N);
    for (p = a; p < a + N; ++p)
        scanf("%d", p);
    printf("Please enter the rotate value:");
    scanf("%d", &m);
    rightrot(a, b, m);
    for (p = b; p < b + N; ++p)
        printf("%d ", *p);
    printf("\n");
}

void rightrot(int *p1, int *p2, int m)
{
    int i, j;

    for (i = 0; i < N - m; ++i)
        *(p2 + i + m) = *(p1 + i);
    for (j = 0; i < N; ++i, ++j)
        *(p2 + j) = *(p1 + i);
}