//有若干个人员的数据,其中有学生和教师
//学生的数据中包括:姓名,号码,性别,职业,班级
//教师的数据包括:姓名,号码,性别,职业,职务
//要求用同一个表格来处理
#include<stdio.h>
struct                               //声明无名结构体类型
  {
    int num;                         //成员num(编号)
    char name[10];                   //成员name(姓名)
    char sex;                        //成员sex(性别)
    char job;                        //成员job(职业)
    union                            //声明无名共用体类型
      {
        int clas;                    //成员clas(班级)
        char position[10];           //成员position(职务)
      }category;                     //成员category是共用体变量
  }person[2];                        //定义结构体数组person,有两个元素
int main()
  {
    int i;
    for(i=0;i<2;i++)
      {
        printf("please enter the data of person:\n");
        scanf("%d %s %c %c",         //输入前4项
        &person[i].num,&person[i].name,&person[i].sex,&person[i].job);
        if(person[i].job=='s')       //如是学生,输入班级
          scanf("%d",&person[i].category.clas);
        else if(person[i].job=='t')  //如是教师,输入职务
          scanf("%s",&person[i].category.position);
        else                         //如job不是's'和't',显示"输入错误"
          printf("Input error!");
      }
    printf("\n");
    printf("No.  name      sex job class/position\n");
    for(i=0;i<2;i++)
      {
        if(person[i].job=='s')       //若是学生
          printf("%-6d%-10s%-4c%-4c%-10d\n",
          person[i].num,person[i].name,person[i].sex,person[i].job,person[i].category.clas);
        else                         //若是教师
          printf("%-6d%-10s%-4c%-4c%-10s\n",
          person[i].num,person[i].name,person[i].sex,person[i].job,person[i].category.position);
      }
      return 0;
  }