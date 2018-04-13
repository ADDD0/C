/* 编一程序,将两个字符串连接起来,不要用strcat函数 */
#include <stdio.h>

main()
{
    char s[128], t[128];
    int c, i, j;

    printf("Please enter a string:\n");
    for (i = 0; (c = getchar()) != '\n'; ++i)
        s[i] = c;
    printf("Please enter another string:\n");
    for (j = 0; (c = getchar()) != '\n'; ++j)
        t[j] = c;
    i = j = 0;
    while (s[i] != '\0')
        ++i;
    while ((s[i++] = t[j++]) != '\0') {
        ;
    }
    printf("%s\n", s);
}