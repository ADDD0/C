/* 编写函数itob(n,s,b),将整数n转换为以b为底的数
并将转换结果以字符的形式保存到字符串s中.例如,
itob(n,s,16)把整数n格式化成十六进制整数保存在s中     */
/* itob函数:将数字n转换为字符串并保存到s中 - 以b为底 */
void itob(int n, char s[], int b)
{
    int i, j, sign;
    void reverse(char s[]);

    if ((sign = n) < 0)      /* 记录符号             */
        n = -n;              /* 使n成为正数          */
    i = 0;
    do {                     /* 以反序生成数字       */
        j = n % b;           /* 取下一个数字         */
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n /= b) > 0);  /* 删除该数字           */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}