/* 一个球从100m高度自由落下,每次落地后反弹回原高度的一半,
再落下,再反弹求它在第10次落地时共经过多少米,第10次反弹多高 */
#include <stdio.h>

main()
{
    int n;
    float h, sum;

    h = sum = 100.0;
    for (n = 1; n < 10; ++n) {
        sum += h;
        h /= 2;
    }
    printf("%f\n%f\n", sum, h);
}