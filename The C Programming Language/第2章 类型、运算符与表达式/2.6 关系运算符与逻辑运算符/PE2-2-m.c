/* for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
       s[i] = c;
在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句   */
#include <stdio.h>

int i, c;

i = 0;
while ((c = getchar()) != EOF) {
    if (c != '\n')
        if (++i < lim - 1)
            s[i] = c;
}