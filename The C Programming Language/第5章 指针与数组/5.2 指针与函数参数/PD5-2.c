/* 模仿函数getint的实现方法,编写一个读取浮点数的
函数getfloat.getfloat函数的返回值应该是什么类型? 	        */
#include <stdio.h>
#include <ctype.h>

#define  BUFSIZE 100
#define  SIZE 10

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

/* getfloat: get next floating-point number from input      */
int getfloat(float *pn)
{
    int c, sign;
	float power;

    while (isspace(c = getch()))       /* skip white space  */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);                    /* it's not a nubmer */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');  /* integer part      */
	if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');  /* fractional part   */
		power *= 10.0;
	}
    *pn *= sign / power;               /* final number      */
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
    int r, i, n;
	float array[SIZE];

    for (n = 0; n < SIZE; ++n) {
        while ((r = getfloat(&array[n])) == 0)
            getch();
        if (r == EOF)
            break;
    }
    for (i = 0; i < n; ++i)
        printf("%g\n", array[i]);
}