/* 在数的对二的补码表示中,我们编写的itoa函数不能处理最大的负数,即n等于
-(2^(字长-1))的情况.请解释其原因.修改该函数,使它在任何机器上运行时都能
打印出正确的值                                                           */
#include <stdio.h>

#define  abs(x)  ((x) < 0 ? -(x) : (x))

main()
{
    void itoa(int n, char s[]);
    int n;
    char s[128];

    scanf("%d", &n);
    itoa(n, s);
    puts(s);
}

/* itoa: convert n to characters in s - modified                         */
void itoa(int n, char s[])
{
    int i, sign;
    void reverse(char s[]);
    void reverse(char s[]);

    sign = n;                        /* record sign                      */
    i = 0;
    do {                             /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';  /* get next digit                   */
    } while ((n /= 10) != 0);        /* delete it                        */
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