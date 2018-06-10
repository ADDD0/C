#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  NUMBER '0'     /* 标识找到一个数 */
#define  NAME   'n'     /* 标识找到一个(函数)名称           */

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
    if (islower(c)) {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;/* 长度>1个字符,这是一个(函数)名 */
        else
            return c;/* 它可能是一个命令 */
    }
    if (!isdigit(c) && c != '.')
        return c;    /* 不是数            */
    if (isdigit(c))  /* 收集整数部分      */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')    /* 收集小数部分      */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}