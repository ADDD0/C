/* for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
       s[i] = c;
在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句   */
#include <stdio.h>

main()
{
    int lim = 10;
    int i, c;
    char s[lim];

    i = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            break;
        else if (i < lim)
            s[i++] = c;
    s[i] = '\0';
    printf("%s\n", s);
}