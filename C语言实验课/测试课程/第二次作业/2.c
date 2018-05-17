#include <stdio.h>

main()
{
    int n;
    int i, j, t, sum;

    scanf("%d", &n);
    for (i = sum = 0; i <= n; ++i) {
        for (j = i, t = 0; j > 0; --j)
            t = t * 10 + i;
        sum += t;
    }
    printf("%d\n", sum);
}