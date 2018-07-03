/* 编写函数htoi(s),把由十六进制数字组成的字符串(包含可选的前缀0x或0X)
转换为与之等价的整型值.字符串中允许包含的数字包括:0~9,a~f以及A~F      */
#include <stdio.h>

#define  YES  1
#define  NO   0

main()
{
    int htoi(char s[]);
    char s[128];

    gets(s);
    printf("%d\n", htoi(s));
}

/* htoi: convert hexadecimal string s to integer                      */
int htoi(char s[])
{
    int hexdigit, i, inhex, n;

    i = 0;
    if (s[i] == '0') {   /* skip optional 0x or 0X                    */
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;               /* integer value to be returned              */
    inhex = YES;         /* assume valid hexadecimal digit            */
    for ( ; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = NO;  /* not a valid hexadecimal digit             */
        if (inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
}