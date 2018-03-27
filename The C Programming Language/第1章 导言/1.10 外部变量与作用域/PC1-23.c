#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

/* 编写一个删除C语言程序中所有的注释语句。
要正确处理带引号的字符串与字符常量。在C语言中，注释不允许嵌套 */
main()
{
    int c;

    while ((c = getchar()) != EOF)
        rcomment(c);
    return 0;
}

/* rcomment：读取每个字符，移除注释                           */
void rcomment(int c)
{
    int d;

    if (c == '/') {
        if ((d = getchar()) == '*')
            in_comment();           /* 注释开始               */
        else if (d == '/') {
            putchar(c);             /* 另一个反斜杠           */
            rcomment(d);
        } else {
            putchar(c);             /* 不是注释               */
            putchar(d);
        }
    }
    else if (c == '\'' || c == '"')
        echo_quote(c);              /* 引号开始               */
    else
        putchar(c);                 /* 不是注释               */
}

/* in_comment：有效注释内部                                   */
void in_comment(void)
{
    int c, d;

    c = getchar();                  /* 前一字符               */
    d = getchar();                  /* 当前字符               */
    while (c != '*' || d != '/') {  /* 搜寻末尾               */
        c = d;
        d = getchar();
    }
}

/* echo_quote：引号内的回显字符串                             */
void echo_quote(int c)
{
    int d;

    putchar(c);
    while ((d = getchar()) != c) {  /* 搜寻末尾               */
        putchar(d);
        if (d == '\\')
            putchar(getchar());     /* 忽略转义序列           */
    }
    putchar(d);
}