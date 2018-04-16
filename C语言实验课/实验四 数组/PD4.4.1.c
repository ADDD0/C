/* 利用两种方法实现连接两个字符串
方法1:利用C语言的库函数strcat()来实现两个字符串的连接
方法2:不允许使用连接函数strcat()
即自己编写程序将字符串2中的字符逐个复制到字符串1的后面,从而实现字符串的连接功能 */
#include <stdio.h>
#include <string.h>

main()
{
    char s[128], t[128];

    printf("Please enter a string:\n");
    scanf("%s", s);
    printf("Please enter another string:\n");
    scanf("%s", t);
    printf("%s\n", strcat(s, t));
}