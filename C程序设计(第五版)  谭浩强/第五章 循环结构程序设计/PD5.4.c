#include <stdio.h>
#include <ctype.h>

/* 输入一行字符,分别统计出其中英文字母,空格,数字和其他字符的个数 */
main()
{
    int c, nl, nb, nd, no;

    nl = nb = nd = no = 0;
    while((c = getchar()) != '\n') {
        if (isalpha(c))
            ++nl;
        else if (c == ' ')
            ++nb;
        else if (isdigit(c))
            ++nd;
        else
            ++no;
    }
    printf("alpha:%d\nspace:%d\nnumeric:%d\nother:%d\n", nl, nb, nd, no);
}