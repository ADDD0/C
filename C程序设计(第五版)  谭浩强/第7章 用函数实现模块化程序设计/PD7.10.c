/* 写一个函数,输入一行字符,将此字符串中最长的单词输出     */
/* 输入为1he23she45 python666 777788889999时,输出为python */
#include <stdio.h>

#define  MAXLINE  128

main()
{
    void longest(char s[], char t[]);

    char word[MAXLINE], lg[MAXLINE];

    gets(word);
    longest(word, lg);
    puts(lg);
}

void longest(char s[], char t[])
{
    int i, j, len, max;
    char p[MAXLINE];

    len = strlen(s);
    for (i = 0, j = 0, max = 0; i <= len; ++i) {
        if (isalpha(s[i]))
            p[j++] = s[i];
        else {
            p[j] = '\0';
            if (j > max) {
                max = j;
                strcpy(t, p);
            }
            j = 0;
        }
    }
}