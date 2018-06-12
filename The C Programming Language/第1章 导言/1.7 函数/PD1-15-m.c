/* 重新编写1.2节中的温度转换程序,使用函数实现温度转换计算    */
#include <stdio.h>

float fahr(float celsius);

/* print Celsius-Fahrenheit table
    for celsius = 0, 20, . . ., 300; floating-point version  */
main()
{
    float celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit of temperature table        */
    upper = 300;  /* upper limit                             */
    step = 20;    /* step size                               */

    celsius = lower;
    while (celsius <= upper) {
        printf("%3.0f  %6.1f\n", celsius, fahr(celsius));
        celsius += step;
    }
}

/* fahr: convert celsius into fahr                           */
float fahr(float celsius)
{
    return (9.0 * celsius) / 5.0 + 32.0;
}