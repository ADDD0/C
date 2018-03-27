#include <stdio.h>

#define  MAXLINE   1000  /* 允许的输入行的最大长度     */

int getline(char line[], int maxline);
int remove(char s[]);

/* 编写一个程序，
删除每个输入行末尾的空格及制表符，并删除完全是空格的行 */
main()
{
    char line[MAXLINE];  /* 当前的输入行               */
    
    while (getline(line, MAXLINE) > 0)
        if (remove(line) > 0)
            printf("%s", line);
    return 0;
}

/* getline函数：将一行读入到s中并返回其长度            */
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

/* remove函数：从字符串s中删除末尾的空格及制表符       */
int remove(char s[])
{
    int i;
    
    while (s[i] != '\n')
        ++i;
    --i;
    while (i > 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if (i > 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}