#include <stdio.h>

/* 输入4个整数,要求按由小到大的顺序输出 */
main()
{
    void swap(int *i, int *j);
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    swap(&a, &b);
    swap(&b, &c);
    swap(&c, &d);
    swap(&a, &b);
    swap(&b, &c);
    swap(&a, &b);
    printf("%d %d %d %d\n", a, b, c, d);
    printf("%d %d %d %d\n", d, c, b, a);
}

void swap(int *i, int *j)
{
    int temp;

    if (*j > *i) {
        temp = *i;
        *i = *j;
        *j = temp;
    }
}