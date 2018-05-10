#include "stdio.h"

int main()
{
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);
    if (a + b > c && b + c > a && c + a > b)
        printf("%.2f\n", a + b + c);
    else
        printf("Wrong\n");
    return 0;
}