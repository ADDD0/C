/* 有一个分数序列
2/1,3/2,5/3,8/5,13/8,21/13,…
求出这个数列的前20项之和     */
#include <stdio.h>

main()
{
    int n;
    float i, j, k, sum;

    i = j = 1.0;
    sum = 0.0;
    for (n = 1; n < 21; ++n) {
        k = i + j;
        sum += (k / j);
        i = j;
        j = k;
    }
    printf("%f\n", sum);
}