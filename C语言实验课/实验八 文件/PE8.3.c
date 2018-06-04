/* 将2—100之间的所有素数写入到一个磁盘文件num.dat中
#include "sdtio.h"
void main()
{
    FILE *fp;
    定义需要的变量;
    以wb的方式打开文件num.dat;
    if(打开失败)
    {
        输出失败信息;
        exit(0);
    }
    for(i=2;i<=100;i++)
    {
        for(j=2;j<i;j++)
            if(i%j==0)
                break;
        if(i是素数)
            使用fwrite函数将i写入文件num.dat中;
    }
    关闭文件fp;
}                                                   */
#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *fp;
    int i, j;

    if ((fp = fopen("num.dat", "wb")) == NULL) {
        printf("can not open file\n");
        exit(0);
    }
    for (i = 2; i <= 100; ++i) {
        for (j = 2; j < i; ++j)
            if(i % j == 0)
                break;
        if(i == j)
            fwrite(&i, sizeof(int), 1, fp);
    }
    fclose(fp);
}