#include <stdio.h>

/* for (i = 0; i < lim - 1; && (c = getchar()) != '\n' && c !=EOF; ++i) s[i] = c */
/* 在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句         */
enum loop {NO, YES};
enum loop okloop = YES;

i = 0;
while (okloop == YES)
    if (i >= lim - 1)   /* 有效范围外                                            */
        okloop = NO;
    else if ((c = getchar()) == '\n')
        okloop = NO;
    else if (c == EOF)  /* 文件末尾                                              */
        okloop = NO;
    else {
        s[i] = c;
        ++i;
    }
        