#include <stdio.h>

main()
{
    int y1, m1, d1;
    int y2, m2, d2;

    scanf("%d/%d/%d", &y1, &m1, &d1);
    scanf("%d/%d/%d", &y2, &m2, &d2);
    if (y1 > y2)
        printf("1");
    else if (y1 < y2)
        printf("0");
    else {
        if (m1 > m2)
            printf("1");
        else if (m1 < m2)
            printf("0");
        else {
            if (d1 > d2)
                printf("1");
            else
                printf("0");
        }
    }
    printf("\n");
}