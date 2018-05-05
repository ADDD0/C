//输入两个整数,然后让用户选择1或2,选1时调用max函数,输出二者中的大数,选2时调用min函数,输出二者中的小数
#include<stdio.h>
int main()
  {
    int max(int,int);   //函数声明
    int min(int,int);   //函数声明
    int (*p)(int,int);  //定义指向函数的指针变量
    int a,b,c,n;
    printf("please enter a and b:");
    scanf("%d,%d",&a,&b);
    printf("please choose 1 or 2:");
    scanf("%d",&n);     //输入1或2
    if(n==1)            //如输入1,使p指向max函数
      p=max;
    else if(n==2)       //如输入2,使p指向min函数
      p=min;
    c=(*p)(a,b);        //调用p指向的函数
    printf("a=%d,b=%d\n",a,b);
    if(n==1)
      printf("max=%d\n",c);
    else
      printf("min=%d\n",c);
    return 0;
  }

int max(int x,int y)
  {
    int z;
    if(x>y)
      z=x;
    else
      z=y;
    return(z);
  }

int min(int x,int y)
  {
    int z;
    if(x<y)
      z=x;
    else
      z=y;
    return(z);
  }