/* 编写函数strrindex(s,t),它返回字符串t在s中最右边出现的位置
如果s中不包含t,则返回-1                                      */
#include <stdio.h>

main()
{
    int strrindex(char s[], char t[]);
    char s[128], t[128];

    gets(s);
    gets(t);
    printf("%d\n", strrindex(s, t));
}

/* strrindex: returns rightmost index of t in s, -1 if none  */
int strrindex(char s[], char t[])
{
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}