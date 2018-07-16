/* 采用指针而非数组索引方式改写前面章节和练习中的某些程序
例如getline(第1,4章);atoi,itoa以及它们的变体形式(第2,3,4章)
reverse(第3章);strindex,getop(第4章)等等                             */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define  NUMBER  '0'             /* signal that a number was found   */
#define  BUFSIZE 100
#define  SIZE    10

char buf[BUFSIZE];
int bufp = 0;

/* getline: read a line into s, return length                        */
int getline(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* atoi: convert s to integer; pointer version                       */
int atoi(char *s)
{
    int n, sign;

    for ( ; isspace(s); s++)     /* skip white space                 */
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')  /* skip sign                        */
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + *s - '0';
    return sign * n;
}

/* reverse: reverse string s in place                                */
void reverse(char *s)
{
    int c;
    char *t;

    for (t = s + (strlen(s) - 1); s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

/* itoa: convert n to characters in s; pointer version               */
void itoa(int n, char *s)
{
    int sign;
    char *t = s;                 /* save pointer to s                */

    if ((sign = n) < 0)          /* record sign                      */
        n = -n;                  /* make n positive                  */
    do {                         /* generate digits in reverse order */
        *s++ = n % 10 + '0';     /* get next digit                   */
    } while ((n /= 10) > 0);     /* delete it                        */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

/* strindex: return index of t in s, -1 if none                      */
int strindex(char *s, char *t)
{
    char *b = s;                 /* beginning of string s            */
    char *p, *r;

    for ( ; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r =='\0')
            return s - b;
    }
    return -1;
}

/* atof: convert string s to double; pointer version                 */
double atof(char *s)
{
    double val, power;
    int sign;

    for ( ; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        s++;
    for (power = 1.0; isdigit(*s); s++) {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return val * sign / power;
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

/* getop: get next operator or numeric operand; pointer ver          */
int getop(char *s)
{
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;                /* not a number                     */
    if (isdigit(c))              /* collect integer part             */
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')                /* collect fraction part            */
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}