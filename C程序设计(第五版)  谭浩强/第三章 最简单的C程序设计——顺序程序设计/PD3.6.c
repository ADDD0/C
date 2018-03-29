#include <stdio.h>

/* 编写一个密码表,密码规律是:
   用原来的字母后面第4个字母代替原来的字母
   例:“China”-->"Glmre"                     */
main()
{
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'V' || c >= 'a' && c <= 'v')
            putchar(c + 4);
        else if (c >= 'W' && c <= 'Z' || c >= 'w' && c <= 'z')
            putchar(c - 22);
        else
            putchar(c);
    }
}