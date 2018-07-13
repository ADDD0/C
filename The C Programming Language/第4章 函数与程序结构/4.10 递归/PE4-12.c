/* 运用printd函数的设计思想编写一个递归版本的
itoa函数,即通过递归调用把整数转换为字符串        */
#include <stdio.h>
#include <math.h>

/* itoa: convert n to characters in s; recursive */
void itoa(int n, char s[])
{
    static int i;

    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

main()
{
    int n;
    char s[128];

    printf("Input n:");
    scanf("%d", &n);
    itoa(n, s);
    puts(s);
}