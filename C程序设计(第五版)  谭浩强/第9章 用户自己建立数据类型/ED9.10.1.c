//编写一个输出链表的函数print
#include<stdio.h>
#define LEN sizeof(struct Student)
struct Student                                    //声明结构体类型struct Student
  {
    long num;
    float score;
    struct Student *next;
  };
int n;                                            //全局变量n
void print(struct Student *head)                  //定义print函数
  {
    struct Student *p;                            //在函数中定义struct Student类型的变量p
    printf("\nNow,These %d records are:\n",n);
    p=head;                                       //使p指向第1个结点
    if(head!=NULL)                                //若不是空表
      do
        {
          printf("%ld %5.1f\n",p->num,p->score);  //输出一个结点中的学号与成绩
          p=p->next;                              //p指向下一个结点
        } while(p!=NULL);                         //当p不是"空地址"
  }