/* 编写一个函数ungets(s),将整个字符串s压回到输入中
ungets(s)函数需要使用buf和bufp吗?它能否仅使用ungetch函数? */
#include <string.h>

/* ungets: push string back onto the input                */
void ungets(char s[])
{
    int len = strlen(s);
    void ungetch(int);

    while (len > 0)
        ungetch(s[--len]);
}