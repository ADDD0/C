#include <stdio.h>

/* 求 */
main()
{
    int k, i;
    float j, sum;

    sum = 0.0;
    for (k = 100; k > 0; --k)
        sum += k;
    for (k = 50; k > 0; --k) {
        i = k * k;
        sum += i;
    }
    for (k = 10; k > 0; --k) {
        j = 1.0 / k;
        sum += j;
    }
    printf("%f\n", sum);
}