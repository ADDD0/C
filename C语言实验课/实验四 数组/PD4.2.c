/* 从键盘输入一个字符串,用字符数组存放
要求统计出其中字母字符,数字字符和其他字符的个数
例如:
从键盘输入的字符串:abcd123a4WE$$$12***
程序的输出结果为:字母=7     数字=6     其他=6   */
#include <stdio.h>
#include <ctype.h>

main()
{
    int a[128];
    int i, nl, nd, no;

    nl = nd = no = 0;
    for (i = 0; i < 128 && (a[i] = getchar()) != '\n'; ++i) {
        if (isalpha(a[i]))
            ++nl;
        else if (isdigit(a[i]))
            ++nd;
        else
            ++no;
    }
    printf("字母=%d     数字=%d     其他=%d\n", nl, nd, no);
}