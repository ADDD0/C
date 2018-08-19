#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum {NAME, PARENS, BRACKETS};
enum {NO, YES};

extern int tokentype;
extern char token[];
int prevtoken = NO;

int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    if (prevtoken == YES) {
        prevtoken = NO;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

/* nexttoken: get the next token and push it back */
int nexttoken(void)
{
    int type;
    extern int prevtoken;

    type = gettoken();
    prevtoken = YES;
    return type;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

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