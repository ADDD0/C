#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  NUMBER  '0'     /* 标识找到一个数 */

int getch(void);
void ungetch(int);

/* getop函数:获取下一个运算符或数值操作数  */
int getop(char s[])
{
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;        /* 不是数         */
    if (c == '-')
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;  /* 负数           */
        else {
            if (c != EOF)
                ungetch(c);
            return '-';  /* 减号标记       */
        }
    if (isdigit(c))      /* 收集整数部分   */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')        /* 收集小数部分   */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}