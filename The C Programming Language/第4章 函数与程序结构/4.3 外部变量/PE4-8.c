/* 假定最多只压回一个字符.请相应地修改getch与ungetch这两个函数 */
#include <stdio.h>

char buf = 0;

/* getch: get a (possibly pushed back) character               */
int getch(void)
{
    int c;

    if (buf != 0)
        c = buf;
    else
        c = getchar();
    buf = 0;
    return c;
}

/* ungetch: push character back onto the input                 */
void ungetch(int c)
{
    if (buf != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}