/* 编写函数itob(n,s,b),将整数n转换为以b为底的数,并将转换结果以
字符的形式保存到字符串s中
例如,itob(n,s,16)把整数n格式化成十六进制整数保存在s中            */
#include <stdio.h>

main()
{
    void itob(int n, char s[], int b);
    int n, b;
    char s[128];

    scanf("%d %d", &n, &b);
    itob(n, s, b);
    puts(s);
}

/* itob: convert n to characters in s - base b                   */
void itob(int n, char s[], int b)
{
    int i, j, sign;
    void reverse(char s[]);

    if ((sign = n) < 0)      /* record sign                      */
        n = -n;              /* make n positive                  */
    i = 0;
    do {                     /* generate digits in reverse order */
        j = n % b;           /* get next digit                   */
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n /= b) > 0);  /* delete it                        */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0')
        ++i;
    --i;
    if (s[i] == '\n')
        --i;
    j = 0;
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}