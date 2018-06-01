/* 编程实现:将从键盘输入的一组学生的姓名及3科成绩信息
将这些信息存储到磁盘文件f1.dat中,当输入学号为0时,输入结束

程序结构
#include "sdtio.h"
定义需要的结构体类型
void main()
{
    FILE *fp;
    定义结构体变量及其它需要的变量;
    以wb的方式打开文件f1.dat;
    if(打开失败)
    {
        输出失败信息;
        exit(0);
    }
    读入第一个学生的学号;
    while(学号!=0)
    {
        读入学生的姓名及成绩信息;
        使用fwrite函数,将该学生的信息写入文件f1.dat中;
        读入学生的学号;
    }
    关闭文件fp;
}                                                         */
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
    FILE *fp;
    Student *p;
    int i, *s;

    if ((fp = fopen("f1.dat", "wb")) == NULL) {
        printf("can not open file\n");
        exit(0);
    }
    p = talloc();
    scanf("%d", p -> sno);
    while (*p -> sno) {
        scanf("%s", p -> sname);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            scanf("%d", s);
        fwrite(p, sizeof(Student), 1, fp);
        scanf("%d", p -> sno);
    }
    fclose(fp);
}