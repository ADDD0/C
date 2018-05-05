/* 写几个函数:
① 输入10个职工的姓名和职工号
② 按职工号由小到大顺序排序,姓名顺序也随之调整
③ 要求输入一个职工号,用折半查找法找出该职工的姓名,从主函数输入要查找的职工号,输出该职工姓名 */
//struct共用体???
#include <stdio.h>

main()
{
    void input(char a[10][2]);
    void sort(char a[10][2]);
    void output(char a[10][2]);


    char a[10][2];


    input(a);
    sort(a);
    output(a);
}

void input(char a[10][2])
{
    int i;

    for (i = 0; i < 10; ++i)
        scanf("%s %s", &a[i][0], &a[i][1]);
}

void sort(char a[10][2])
{
    int i, j;
    char temp;

    for (i = 0; i < 10; ++i)
        for (j = i; j < 9; ++j)
            if ((int)a[j][1] > (int)a[j + 1][1]) {//???
                temp = a[j][0];
                a[j][0] = a[j + 1][0];
                a[j + 1][0] = temp;
                temp = a[j][1];
                a[j][1] = a[j + 1][1];
                a[j + 1][1] = temp;
            }
}

void output(char a[10][2])
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("name:%snumber:%s\n", a[i][0], a[i][1]);
}