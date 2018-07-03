/* 重新编写函数squeeze(s1, s2)
将字符串s1中任何与字符串s2中字符匹配的字符都删除        */
#include <stdio.h>

main()
{
    void squeeze(char s1[], char s2[]);
    char s1[128], s2[128];

    gets(s1);
    gets(s2);
    squeeze(s1, s2);
    puts(s1);
}

/* squeeze: delete each char in s1 which is in s2       */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if (s2[j] == '\0')  /* end of string - no match */
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}