/* 编写程序计算2和-3的0到5次幂
程序的输出形式为:
2的0次幂:1     -3的0次幂:1
2的1次幂:2     -3的1次幂:-3
2的2次幂:4     -3的2次幂:9
2的3次幂:8     -3的3次幂:-27
2的4次幂:16    -3的4次幂:81
2的5次幂:32    -3的5次幂:-243

具体要求:
①编写一个power(int x,int n)函数计算x的n次幂
power函数的形式为:
int power(int x,int n)
{
    编写代码实现求x的n次幂;
}
②在主函数中多次调用power函数,得到所要求的结果
void main()
{
    for(i=0;i<=5;i++)
    {
        printf("2的%d次幂:%d\t",i,power(2,i));
        printf("-3的%d次幂:%d\n",i,power(-3,i));
    }                                            */
#include <stdio.h>

main()
{
    int power(int x, int n);
    int i;

    for (i = 0; i <= 5; ++i) {
        printf("2的%d次幂:%d\t", i, power(2,i));
        printf("-3的%d次幂:%d\n", i, power(-3,i));
    }
}

int power(int x, int n)
{
    int pow = 1;

    while(n-- > 0)
        pow *= x;
    return pow;
}