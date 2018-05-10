#include "stdio.h"

int main()
{
    int n, sum;

    scanf("%d", &n);
    for (sum = 0; n; n /= 10)
        sum += n % 10;
    printf("%d\n", sum);
    return 0;
}