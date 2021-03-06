/* 编写一个程序,以合理的方式打印任何输入.该程序至少能够根据
用户的习惯以八进制或十六进制打印非图形字符,并截断长文本行      */
#include <stdio.h>
#include <ctype.h>

#define  MAXLINE 100  /* max number of chars in one line       */
#define  OCTLEN  6    /* length of an octal value              */

/* print arbitrary input in a sensible way                     */
main()
{
    int c, pos;
    int inc(int pos, int n);

    pos = 0;                           /* position in the line */
    while ((c = getchar()) != EOF)
        if (iscntrl(c) || c == ' ') {  /* non-graphic or blank */
            pos = inc(pos, OCTLEN);
            printf(" \\%03o ", c);
            if (c == '\n') {           /* newline character ?  */
                pos = 0;
                putchar('\n');
            }
        } else {                       /* graphic character    */
            pos = inc(pos, 1);
            putchar(c);
        }
    return 0;
}

/* inc: increment position counter for output                  */
int inc(int pos, int n)
{
    if (pos + n < MAXLINE)
        return pos + n;
    else {
        putchar('\n');
        return n;
    }
}