#include <stdio.h>

main()
{
    int i, j, new;
    int num[8]={2, 8, 20, 36, 54, 72, 89};

    scanf("%d", &new);
    for (i = 7; i >= 0; --i) {
        if (!(num[i]))
            continue;
        if (new < num[i])
            num[i + 1] = num[i];
        else {
            num[i + 1] = new;
            break;
        }
        if (!i)
            num[i] = new;
    }
    for (i = 0; i < 8; ++i)
        printf("%d ", num[i]);
    printf("\n");

}