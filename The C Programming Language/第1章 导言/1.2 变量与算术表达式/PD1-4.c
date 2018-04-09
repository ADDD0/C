/* 编写一个程序打印
摄氏温度转换为相应华氏温度的转换表  */
#include <stdio.h>

/* 当celsius=0,20,…,300时,打印
摄氏温度与华氏温度对照表;浮点数版本 */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* 温度表的下限   */
    upper = 300;  /* 温度表的上限   */
    step = 20;    /* 步长           */

    printf("Celsius Fahr\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 * celsius) / 5.0 + 32.0;
        printf("%4.0f  %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}