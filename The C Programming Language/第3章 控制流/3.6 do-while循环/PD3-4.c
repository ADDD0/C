/* 在数的对二的补码表示中,我们编写的itoa函数不能
处理最大的负数,即n等于-(2^(字长-1))的情况,请解释其原因
修改该函数,使它在任何机器上运行时都能打印出正确的值    */
#define  abs(x)  ((x) < 0 ? -(x) : (x))

/* itoa函数:将数字n转换为字符串并保存到s中 - 改        */
void itoa(int n, char s[])
{
    int i, sign;
    void reverse(char s[]);

    sign = n;                        /* 记录符号       */
    i = 0;
    do {                             /* 以反序生成数字 */
        s[i++] = abs(n % 10) + '0';  /* 取下一个数字   */
    } while ((n /= 10) != 0);        /* 删除该数学     */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}