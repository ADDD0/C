#include <stdio.h>

main()
{
    int n;

    scanf("%d", &n);
    while (n) {
        printf("%d", n % 10);
        n /= 10;
    }
    printf("\n");
}