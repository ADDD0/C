/* 编写函数htoi(s),把由十六进制数字组成的字符串(包含可选的前缀0x或0X)
转换为与之等价的整型值.字符串中允许包含的数字包括:0~9,a~f以及A~F      */
#include <stdio.h>

#define  YES  1
#define  NO   0

/* htoi函数:将十六进制字符串s转换为整型数                             */
int htoi(char s[])
{
    int hexdigit, i, inhex, n;

    i = 0;
    if (s[i] == '0') {   /* 跳过可选的0x或0X                          */
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;               /* 要返回的整型值                            */
    inhex = YES;         /* 假定为有效的十六进制数字                  */
    for ( ; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = NO;  /* 非有效的十六进制数字                      */
        if (inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
}