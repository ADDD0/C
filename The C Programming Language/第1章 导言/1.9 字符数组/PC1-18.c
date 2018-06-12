/* 编写一个程序,删除每个输入行末尾的空格及制表符,并删除完全是空格的行 */
#include <stdio.h>

#define  MAXLINE   1000   /* maximum input line size                  */

int getline(char line[], int maxline);
int remove(char s[]);

/* remove trailing blanks and tabs, and delete blank lines            */
main()
{
    char line[MAXLINE];   /* current input line                       */

    while (getline(line, MAXLINE) > 0)
        if (remove(line) > 0)
            printf("%s", line);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* remove: trailing blanks and tabs from character string s           */
int remove(char s[])
{
    int i;

    while (s[i] != '\n')  /* find newline character                   */
        ++i;
    --i;                  /* back off from '\n'                       */
    while (i > 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if (i > 0) {          /* is it a nonblank line?                   */
        ++i;
        s[i] = '\n';      /* put newline character back               */
        ++i;
        s[i] = '\0';      /* terminate the string                     */
    }
    return i;
}