//用函数求整数a和b中的大者
//通过指针变量调用它所指向的函数
#include<stdio.h>
int main()
  {
    int max(int,int);   //函数声明
    int (*p)(int,int);  //定义指向函数的指针变量p
    int a,b,c;
    p=max;              //使p指向max函数
    printf("please enter a and b:");
    scanf("%d,%d",&a,&b);
    c=(*p)(a,b);        //通过指针变量调用max函数
    printf("a=%d\nb=%d\nmax=%d\n",a,b,c);
    return 0;
  }

int max(int x,int y)    //定义max函数
  {
    int z;
    if(x>y)
      z=x;
    else
      z=y;
    return(z);
  }