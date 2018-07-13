/* 在上面的例子中,如果符号+或-的后面紧跟的不是数字
getint函数将把符号视为数字0的有效表达方式
修改该函数,将这种形式的+或-符号重新写回到输入流中      */
#include <stdio.h>
#include <ctype.h>

#define  BUFSIZE 100
#define  SIZE 10

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn        */
int getint(int *pn)
{
    int c, d, sign;

    while (isspace(c = getch()))  /* skip white space  */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);               /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
		d = c;
		if (!isdigit(c = getch())) {
			if (c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}
	}
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
			getch();
		if (r == '+' || r == '-') {
			array[n] = 0;
			getch();
		}
        if (r == EOF)
            break;
    }
    for (i = 0; i < n; ++i)
        printf("%d\n", array[i]);
}