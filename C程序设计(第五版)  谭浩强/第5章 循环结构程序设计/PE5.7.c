/* 求(1+2+3+…+100)+(1*1+2*2+3*3+…+50*50)+(1/1+1/2+1/3+…+1/10) */
#include <stdio.h>

main()
{
    int k;
    float j, sum;

    sum = 0;

    for (k = 100; k > 0; sum += k, --k)
        ;
    for (k = 50; k > 0; sum += k * k, --k)
        ;
    for (k = 10; k > 0; sum += j, --k)
        j = 1.0 / k;
    printf("%f\n", sum);
}