/* 写一个函数,输入一个十六进制数,输出相应的十进制数 */
#include <stdio.h>

main()
{
    int htoi(char s[]);
    int hn[10];

    scanf("%s", &hn);
    printf("hex:%s,dec:%d\n", hn, htoi(hn));
}

int htoi(char s[])
{
    int i, dn;

    for (i = dn = 0; s[i] != '\0'; ++i) {
        if ('0' <= s[i] && s[i] <= '9')
            dn = dn * 16 + s[i] - '0';
        else if ('a' <= s[i] && s[i] <= 'f')
            dn = dn * 16 + s[i] - 'a' + 10;
        else if ('A' <= s[i] && s[i] <= 'F')
            dn = dn * 16 + s[i] - 'A' + 10;
    }
    return dn;
}