/* for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
       s[i] = c;
在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句   */
#include <stdio.h>

enum loop {NO, YES};
enum loop okloop = YES;

main()
{
    int lim = 128;
    int i, c;
    char s[lim];

    i = 0;
    while (okloop == YES)
        if (i >= lim - 1)   /* outside of valid range ?                 */
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if (c == EOF)  /* end of file ?                            */
            okloop = NO;
        else {
            s[i] = c;
            ++i;
        }
    s[i] = '\0';
    printf("%s\n", s);
}