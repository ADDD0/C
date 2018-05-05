//有a个学生,每个学生有b门课程的成绩
//要求在用户输入学生序号以后,能输出该学生的全部成绩
//用指针函数来实现
#include<stdio.h>
int main()
  {
    float score[][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}};
    //定义数组,存放成绩
    float *search(float(*pointer)[4],int n);  //函数声明
    float *p;
    int i,k;
    printf("enter the number of student:");
    scanf("%d",&k);                           //输入要找的学生的序号
    printf("The scores of No.%d are:\n",k);
    p=search(score,k);                        //调用search函数,返回score[k][0]的地址
    for(i=0;i<4;i++)
      printf("%5.2f\t",*(p+i));               //输出score[k][0]~score[k][3]的值
    printf("\n");
    return 0;
  }

float *search(float(*pointer)[4],int n)       //形参pointer是指向一维数组的指针变量
  {
    float *pt;
    pt=*(pointer+n);                          //pt的值是&score[k][0]
    return(pt);
  }