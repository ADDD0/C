/* 以上介绍的getch与ungetch函数不能正确地处理压回的EOF
考虑压回EOF时应该如何处理?请实现你的设计方案           */
#include <stdio.h>

#define  BUFSIZE  100

int buf[BUFSIZE];  /* buffer for ungetch               */
int bufp = 0;      /* next free position in buf        */

/* getch: get a (possibly pushed back) character       */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back onto the input         */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}