/* 写一个用矩形法求定积分的通用函数,分别求
∫_0^1(sinx)dx, ∫_0^1(cosx)dx, ∫_0^1(e^x)dx */
#include <stdio.h>
#include <math.h>

main()
{
    float integral(float(*)(float), float, float, int);
    float fsin(float);
    float fcos(float);
    float fexp(float);

    float a1, b1, a2, b2, a3, b3, c, (*p)(float);
    int n = 20;

    printf("input a1,b1:"), scanf("%f,%f", &a1, &b1);
    printf("input a2,b2:"), scanf("%f,%f", &a2, &b2);
    printf("input a3,b3:"), scanf("%f,%f", &a3, &b3);
    p = fsin, c = integral(p, a1, b1, n);
    printf("The integral of sin(x) is:%f\n", c);
    p = fcos, c = integral(p, a2, b2, n);
    printf("The integral of cos(x) is:%f\n", c);
    p = fexp, c = integral(p, a3, b3, n);
    printf("The integral of exp(x) is:%f\n", c);
}

float fsin(float x)
{
    return sin(x);
}

float fcos(float x)
{
    return cos(x);
}

float fexp(float x)
{
    return exp(x);
}

float integral(float(*p)(float), float a, float b, int n)
{
    int i;
    float x, h, s;

    h = (b - a) / n;
    x = a;
    for(i = s = 0; i < n; i++, x += h)
        s += (*p)(x) * h;
    return s;
}