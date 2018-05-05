//用函数求整数a和b中的大者
//通过函数名调用函数
#include<stdio.h>
int main()
  {
    int max(int,int);  //函数声明
    int a,b,c;
    printf("please enter a and b:");
    scanf("%d,%d",&a,&b);
    c=max(a,b);        //通过函数名调用max函数
    printf("a=%d\nb=%d\nmax=%d\n",a,b,c);
    return 0;
  }

int max(int x,int y)   //定义max函数
  {
    int z;
    if(x>y)
      z=x;
    else
      z=y;
    return(z);
  }