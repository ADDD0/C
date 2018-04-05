#include <stdio.h>

/* 求(1+2+3+…+100)+(1*1+2*2+3*3+…+50*50)+(1/1+1/2+1/3+…+1/10) */
main()
{
    int k;
    float j, sum;

    sum = 0.0;
    for (k = 100; k > 0; --k)
        sum += k;
    for (k = 50; k > 0; --k)
        sum += k * k;
    for (k = 10; k > 0; --k) {
        j = 1.0 / k;
        sum += j;
    }
    printf("%f\n", sum);
}