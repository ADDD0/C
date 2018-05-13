/* 用递归方法求n阶勒让德多项式的值,递归公式为
          1                                      (n=0)
P[n](x) = x                                      (n=1)
          ((2n-1)*x*P[n-1](x)-(n-1)*P[n-2](x))/n (n≥1)
          书上给的公式好像是错的??                     */
#include <stdio.h>

main()
{
    float LP(int n, float x);

    int n;
    float x;

    printf("Please input n and x:");
    scanf("%d %f", &n, &x);
    printf("The value is:%f\n", LP(n, x));
}

float LP(int n, float x)
{
    if (!n)
        return 1;
    else if (n == 1)
        return x;
    else
        return ((2 * n - 1) * x * LP(n - 1, x) - (n - 1) * LP(n - 2, x)) / n;
}