#include <stdio.h>
#include <ctype.h>

/* lower函数: 将输入转换为小写形式 */
main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(tolower(c));
    return 0;
}