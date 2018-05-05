/* 编写一个猜数游戏
由计算机"想"一个100以内的数请人猜,如果人猜对了,则结束游戏,猜错了则继续猜,直到猜对或达到一个规定的次数(例如10次)为止
具体要求:
①计算机"想"的数是一个随机数,并转换成100以内的整数形式
②如果人"猜"的数错误则给出提示信息,告诉人猜的是太大还是太小
③统计猜的次数,以此反映人"猜"的水平
提示:
C语言中随机数的生成是由下面两个函数实现的:srand()和rand()函数,它们所在的头文件为stdlib.h,具体请在程序中加入如下代码
#include "stdio.h"
#include "stdlib.h"
#include "time.h"  //程序中用到了时间函数
void main()
{
    int x;
    srand(time(0));  //用系统的当前时间作为生成随机数的种子,这样每次运行程序才能得到不同的随机数
    x=rand()%100;  //用rand函数得到一个随机数,和100取余后保证该数在100以内
}                                                                                                                   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
    int ans, guess;
    int count = 0;

    srand(time(0));
    ans = rand() % 100;

    do {
        ++count;
        printf("Input an integer within 100:");
        scanf("%d", &guess);
        if (ans < guess)
            printf("Too big\n");
        if (ans > guess)
            printf("Too small\n");
    } while (ans != guess && count < 10);
    if (ans != guess)
        printf("Game over\nThe answer is %d\n", ans);
    else
        printf("Congratulation!\nYou find the answer %d in %d times\n", ans, count);
}
