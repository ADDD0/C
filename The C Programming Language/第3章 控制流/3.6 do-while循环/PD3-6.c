/* 修改itoa函数,使得该函数可以接收三个参数.其中,第三个参数为最小字段宽度
为了保证转换后所得的结果至少具有第三个参数指定的最小宽度,在必要时应在
所得结果的左边填充一定的空格                                             */
#include <stdio.h>

#define  abs(x)  ((x) < 0 ? -(x) : (x))

main()
{
    void itoa(int n, char s[], int w);
    int n, w;
    char s[128];

    scanf("%d %d", &n, &w);
    itoa(n, s, w);
    puts(s);
}

/* itoa: convert n to characters in s, w characters wide                 */
void itoa(int n, char s[], int w)
{
    int i, sign;
    void reverse(char s[]);

    sign = n;                        /* record sign                      */
    i = 0;
    do {                             /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';  /* get next digit                   */
    } while ((n /= 10) != 0);        /* delete it                        */
    if (sign < 0)
        s[i++] = '-';
    while (i < w)                    /* pad with blanks                  */
        s[i++] = ' ';
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