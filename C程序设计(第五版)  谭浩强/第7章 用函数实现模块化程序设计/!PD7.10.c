/* 写一个函数,输入一行字符,将此字符串中最长的单词输出       */
#include <stdio.h>

#define  IN   1                /* 在单词内                  */
#define  OUT  0                /* 在单词外                  */

main()
{
    int i, j, state, max;
    char s[128];
    char word[128];
    char longest[128];

    state = OUT;
    gets(s);
    for (i = j = max = 0; ; ++i) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\0') {
            state = OUT;
            if (max < j + 1) {
                max = j + 1;   /* 单词长度大于max时存放起来 */
                for (j = 0; longest[j] = word[j]; ++j)
                    ;          /* 字符串复制                */
            }
        } else if (state == OUT) {
            state = IN;
            j = 0;
            word[j] = s[i];
        } else
            word[j++] = s[i];  /* 记录当前单词              */
        if (s[i] == '\0')
            break;
    }
    printf("%s\n", longest);
}