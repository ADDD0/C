#include "stdio.h"

int main()
{
    float a[10];
    float sum, aver;
    int i;

    for (i = 0; i < 10; ++i)
        scanf("%f", &a[i]);
    for (i = sum = 0; i < 10; ++i)
        sum += a[i];
    aver = sum / 10;
    printf("Total:%.2f\nAverage:%.2f\n", sum, aver);
    return 0;
}