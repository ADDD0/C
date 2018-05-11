/* 重新编写1.2节中的温度转换程序,使用函数实现温度转换计算 */
#include <stdio.h>

float fahr(float celsius);

/* 打印华氏温度与摄氏温度对照表                           */
main()
{
    float celsius;
    int lower, upper, step;

    lower = 0;    /* 温度表的下限                         */
    upper = 300;  /* 温度表的上限                         */
    step = 20;    /* 步长                                 */

    celsius = lower;
    while (celsius <= upper) {
        printf("%3.0f  %6.1f\n", celsius, fahr(celsius));
        celsius += step;
    }
}

/* 华氏度:摄氏度转换为华氏度                              */
float fahr(float celsius)
{
    return (9.0 * celsius) / 5.0 + 32.0;
}