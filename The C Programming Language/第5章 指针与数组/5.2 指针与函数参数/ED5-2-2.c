#include <stdio.h>
#include <ctype.h>

#define  BUFSIZE 100
#define  SIZE 10

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

/* getint函数: 将输入中的下一个整型数赋值给*pn        */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))  /* 跳过空白符       */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);               /* 输入不是一个数字 */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

main()
{
    int r, i, n, array[SIZE];

    for (n = 0; n < SIZE; ++n) {
        while ((r = getint(&array[n])) == 0)
            getch();              /* 跳过非数字       */
        if (r == EOF)
            break;
    }
    for (i = 0; i < n; ++i)
        printf("%d\n", array[i]);
}