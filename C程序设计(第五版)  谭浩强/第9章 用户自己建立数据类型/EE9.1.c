//把一个学生的信息(包括学号,姓名,性别,住址)放在一个结构体变量中,然后输出这个学生的信息
#include<stdio.h>
int main()
  {
    struct Student                                 //声明结构体类型struct Student
      {
        long int num;                              //以下4行为结构体的成员
        char name[20];
        char sex;
        char addr[20];
      }a={10101,"Li Lin",'M',"123 Beijing Road"};  //定义结构体变量a并初始化
    printf("NO.:%ld\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr);
    return 0;
  }