//通过指针变量输出整型数组a的10个元素
#include<stdio.h>
int main()
  {
    int i,a[10],*p=a;;     //p的初值是a,p指向a[0]
    printf("please enter 10 integer numbers:");
    for(i=0;i<10;i++)
      scanf("%d",p++);     //输入10个整数给a[0]~a[9]
    p=a;                   //重新使p指向a[0]
    for(i=0;i<10;i++,p++)
      printf("%d ",*p);    //想输出a[0]~a[9]
    printf("\n");
    return 0;
  }