/* 输入一个字符串,内有数字和非数字字符,例如:
A123x456 17960? 302tab5876
将其中连续的数字作为一个整数,依次存放到一数组a中
例如,123放在a[0],456放在a[1]…统计共有多少个整数,并输出这些数 */
#include <stdio.h>
#include <ctype.h>

main()
{
    int s[200];
    int a[20], i, j;

    for (i = j = 0; (*(s + i) = getchar()) != '\n'; ++i) {
        if (!isdigit(*(s + i)))
            continue;
        else {
            *(a + j) = *(s + i) - '0';
            ++i;
            while (isdigit(*(s + i) = getchar())) {
                *(a + j) = (*(a + j)) * 10 + *(s + i) - '0';
                ++i;
            }
            ++j;
        }
        if (*(s + i) == '\n')
            break;
    }
    printf("%d\n", j);
    for (i = 0; i < j; ++i)
        printf("%d ", *(a + i));
    printf("\n");
}