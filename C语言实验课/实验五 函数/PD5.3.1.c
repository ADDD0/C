/* 编写程序求两个整数的最大公约数和最小公倍数
具体要求:
①编写两个用户自定义函数分别求出最大公约数和最小公倍数
②将main函数和两个自定义函数放在同一个源程序文件(.c)中进行编译,链接并运行
③将main函数和两个自定义函数分别放在不同的源程序文件(.c)中进行编译,链接并运行

提示:
①求最大公约数的方法:辗转相除法
    I.将m,n较大者送入m中,较小者送入n中
    II.r=m%n
    III.若r==0,则n为最大公约数
        否则将n→m中,r→n中,重复执行II,III
②求最小公倍数的方法:m*n/最大公约数                                           */
#include <stdio.h>

main()
{
    int lcm(int m, int n);
    int gcd(int m, int n);
    int x, y;

    printf("请输入两个整数:");
    scanf("%d %d", &x, &y);
    printf("最大公约数为:%d\n最小公倍数为:%d\n", gcd(x, y), lcm(x, y));
}

int lcm(int m, int n)
{
    return m * n / gcd(m, n);
}

int gcd(int m, int n)
{
    int r;

    while (r = m % n) {
        m = n;
        n = r;
    }
    return n;
}