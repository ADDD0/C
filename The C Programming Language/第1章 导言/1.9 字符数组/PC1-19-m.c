/* 编写函数reverse(s),将字符串s中的字符顺序颠倒过来
使用该函数编写一个程序,每次颠倒一个输入行中的字符顺序 */
#include <stdio.h>

#define  MAXLINE  1000  /* maximum input line size    */

int getline(char line[], int maxline);
void reverse(char s[], int len);

/* reverse input lines, a line at a time              */
main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        reverse(line, len);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* reverse: reverse string s                          */
void reverse(char s[], int len)
{
    while (--len > 0)
        putchar(s[len - 1]);
    putchar('\n');
}