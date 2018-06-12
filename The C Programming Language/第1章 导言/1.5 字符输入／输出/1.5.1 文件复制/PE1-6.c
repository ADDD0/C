/* 验证表达式getchar()!=EOF的值是0还是1 */
#include <stdio.h>

main()
{
    int c;

    while (c = getchar() != EOF)
        printf("%d\n", c);
    printf("%d - EOF\n", c);
}