//通过指向结构体变量的指针变量输出结构体变量中成员的信息
#include<stdio.h>
#include<string.h>
int main()
  {
    struct Student//声明结构体类型struct Student
      {
        long num;
        char name[20];
        char sex;
        float score;
      };
    struct Student stu_1;         //定义struct Student类型的变量stu_1
    struct Student *p;            //定义指向struct Student类型数据的指针变量p
    p=&stu_1;                     //p指向stu_1
    stu_1.num=10101;              //对结构体变量的成员赋值
    strcpy(stu_1.name,"Li Lin");  //用字符串复制函数给stu_1.name赋值
    stu_1.sex='M';
    stu_1.score=89.5;
    printf("NO.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
    stu_1.num,stu_1.name,stu_1.sex,stu_1.score);  //输出结果
    printf("\nNO.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
    (*p).num,(*p).name,(*p).sex,(*p).score);
    return 0;
  }