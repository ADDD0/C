/*  编程实现:从题目(1)建立的磁盘文件f1.dat中将所有学生的
信息姓名及3科成绩读出来,计算每个学生的总分及平均成绩

屏幕的输出形式为:
     姓名     科目1     科目2     科目3     总分     平均分

#include "sdtio.h"
定义需要的结构体类型(结构体类型同题目(1))
void main()
{
    FILE *fp;
    定义结构体变量及其它需要的变量;
    以rb的方式打开文件f1.dat；
    if(打开失败)
    {
        输出失败信息;
        exit(0);
    }
    使用fread函数读出一个学生的信息;
    while(文件fp没有结束)
    {
        计算读出学生的总分及平均分;
        按照规定的格式输出学生的信息,总分及平均分;
        使用fread函数读出一个学生的信息;
    }
    关闭文件;
}                                                           */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct stu
{
    int sno[6];
    char sname[10];
    int sco[3];
} Student;

Student *talloc(void)
{
    return (Student *) malloc(sizeof(Student));
}

main()
{
    int sum(int *);
    float aver(int *);

    FILE *fp;
    Student *p;
    int i, *s;

    if ((fp = fopen("f1.dat", "rb")) == NULL) {
        printf("can not open file\n");
        exit(0);
    }
    p = talloc();
    fread(p, sizeof(Student), 1, fp);
    while (!feof(fp)) {
        printf("%-5s ", p -> sname);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            printf("%-5d ", *s);
        printf("%-5d %-5.2f\n", sum(p -> sco), aver(p -> sco));
        fread(p, sizeof(Student), 1, fp);
    }
    fclose(fp);
}

int sum(int *p)
{
    int i, sum;

    for (i = sum = 0; i < 3; ++i)
        sum += *(p + i);
    return sum;
}

float aver(int *p)
{
    return (float) sum(p) / 3;
}