/* 从键盘输入一个四位整数,首先分离出该正整数中的每一位数字,并按逆序输出各位数字
然后用分离出的每位数字组成一个最大四位数和一个最小四位数,并显示输出
例如,若输入的四位正整数为3157,按逆序输出分离出的各位数字为7   5   1   3
组成的最大数为7531,最小数为1357

具体要求:
①四位整数由键盘输入
输入前要有提示,检查输入数据的合法性,若输入的数据不合法则输出错误信息
②对输出结果的形式
7   5   1   3   max=7531   min=1357                                             */
#include <stdio.h>

main()
{
    int n, i, j, t;
    int max, min;
    int a[4];

    printf("Input a four-digit integer:");
    scanf("%d", &n);
    if (n >= 1000 && n < 10000) {
        i = 0;
        while (i - 4) {
            printf("%d   ", a[i++] = n % 10);
            n /= 10;
        }
        for (i = 0; i < 3; ++i)  /* 冒泡排序                                    */
            for (j = 0; j < 3 - i; ++j)
                if (a[j] < a[j + 1]) {
                    t = a[j], a[j] = a[j + 1], a[j + 1] = t;
                }
        for (max = min = i = 0; i < 4; ++i) {
            max = max * 10 + a[i];
            min = min * 10 + a[3 - i];
        }
        printf("max=%d   min=%d\n", max, min);
    } else
        printf("Invalid data\n");
}