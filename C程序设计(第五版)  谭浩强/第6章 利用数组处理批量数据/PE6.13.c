/* 编一程序,将两个字符串连接起来,不要用strcat函数 */
#include <stdio.h>

main()
{
    char s[128], t[128];
    int c, i, j;

    printf("Please enter a string:\n");
    gets(s);
    printf("Please enter another string:\n");
    gets(t);
    i = j = 0;
    while (s[i] != '\0')
        ++i;
    while ((s[i++] = t[j++]))
        ;
    printf("%s\n", s);
}