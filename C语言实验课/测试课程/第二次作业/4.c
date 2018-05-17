#include <stdio.h>
#include <ctype.h>

main()
{
    int c;

    while ((c = getchar()) != '\n')
        if (!isupper(c))
            putchar(c);
    putchar(c);
}