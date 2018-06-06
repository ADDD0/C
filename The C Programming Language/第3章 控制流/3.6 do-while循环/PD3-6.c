/* 修改itoa函数,使得该函数可以接收三个参数.
其中,第三个参数为最小字段宽度.为了保证转换后
所得的结果至少具有第三个参数指定的最小宽度
在必要时应在所得结果的左边填充一定的空格               */
#define  abs(x)  ((x) < 0 ? -(x) : (x))

/* itoa函数:将数字n转换为字符串并保存到s中,w字段宽     */
void itoa(int n, char s[], int w)
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
    if (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}