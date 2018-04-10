/* 编写函数reverse(s),将字符串s中的字符顺序颠倒过来
使用该函数编写一个程序,每次颠倒一个输入行中的字符顺序 */
#include <stdio.h>

#define  MAXLINE  1000    /* 允许的输入行的最大长度   */

int getline(char line[], int maxline);
void reverse(char s[]);

/* 反转输入行,一次反转一行                            */
main()
{
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

/* getline函数:将一行读入到s中并返回其长度            */
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

/* reverse函数:反向字符串                             */
void reverse(char s[])
{
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0')  /* 找到字符串末尾            */
        ++i;
    --i;                  /* 从'\0'开始倒退            */
    if (s[i] == '\n')
        --i;              /* 留下换行符                */
    j = 0;                /* 开始新字符串              */
    while (j < i) {
        temp = s[i];
        s[j] = s[i];      /* 交换字符                  */
        s[i] = temp;
        --i;
        ++j;
    }
}