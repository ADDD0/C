#include <stdio.h>
#include <ctype.h>

main()
{
    int c;
    int nl, nd, no;

    nl = nd = no = 0;
    while ((c = getchar()) != '\n') {
        if (isalpha(c))
            ++nl;
        else if (isdigit(c))
            ++nd;
        else
            ++no;
    }
    printf("Letters=%d\nDigits=%d\nOthers=%d\n", nl, nd, no);
}