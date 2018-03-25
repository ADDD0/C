#include <stdio.h>

#define  MAXLINE   1000  /* 允许的输入行的最大长度 */
#define  LONGLINE  80

int getline(char line[], int maxline);

/* 编写一个程序，打印长度大于80个字符的所有输入行  */
main()
{
    int len;             /* 当前行长度             */
    char line[MAXLINE];  /* 当前的输入行           */
    
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > LONGLINE) {
            printf("%s", line);
        }
    return 0;
}

/* getline函数：将一行读入到s中并返回其长度        */
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