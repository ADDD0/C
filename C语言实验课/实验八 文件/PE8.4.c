/* 将题目(3)中的num.dat中的数据读出并输出到屏幕上
#include "sdtio.h"
void main()
{
    FILE *fp;
    定义需要的变量;
    以rb的方式打开文件num.dat;
    if(打开失败)
    {
        输出失败信息;
        exit(0);
    }
    使用fread函数读出一个数据;
    while(文件fp没有结束)
    {
        将数据输出到屏幕上;
        使用fread函数读出一个数据;
    }
    关闭文件;
}                                                 */
#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *fp;
    int i;

    if ((fp = fopen("num.dat", "rb")) == NULL) {
        printf("can not open file\n");
        exit(0);
    }
    fread(&i, sizeof(int), 1, fp);
    while (!feof(fp)) {
        printf("%d ", i);
        fread(&i, sizeof(int), 1, fp);
    }
    printf("\n");
    fclose(fp);
}