/* 编程实现一个简单计算器功能,能够计算表达式:data1 op data2,其中op为运算符+,-,*,/
具体要求:
①输入前要有提示,检查输入数据的合法性,若输入的数据不合法则输出错误信息
②特别注意除数为0的情况
举例:
输入为:5*6↙  输出为:5*6=30                                                       */
#include <stdio.h>

main()
{
    float data1, data2;
    char op;

    printf("Please enter the expression,for example:5*6\n:");
    scanf("%f%c%f", &data1, &op, &data2);  /* 无法判断data2格式出错               */
    switch (op) {
        case '+': printf("%.2f%c%.2f=%.2f\n", data1, op, data2, data1 + data2);break;
        case '-': printf("%.2f%c%.2f=%.2f\n", data1, op, data2, data1 - data2);break;
        case '*': printf("%.2f%c%.2f=%.2f\n", data1, op, data2, data1 * data2);break;
        case '/': {
            if (data2) {
                printf("%.2f%c%.2f=%.2f\n", data1, op, data2, data1 / data2);
                break;
            } else {
                printf("Divisor cannot be 0\n");
                break;
            }
        }
        default : printf("Invalid data\n");
    }
}