#include <stdio.h>

main()
{
    int n;

    scanf("%d", &n);
    if (!n)
        printf("NO\n");
    while (n) {
        if (n == 1) {
            printf("YES\n");
            break;
        } else if (n % 2) {
            printf("NO\n");
            break;
        } else
            n /= 2;
    }
}