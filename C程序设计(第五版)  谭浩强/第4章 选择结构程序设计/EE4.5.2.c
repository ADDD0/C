//有一阶跃函数:
//   -1 (x<0)
//y= 0  (x=0)
//   1  (x>0)
//编一程序,输入一个x值,要求输出相应的y值
#include<stdio.h>
int main()
  {
    int x,y;
    scanf("%d",&x);
    if(x>=0)  //注意分析此if语句
      if(x>0)
        y=1;
      else
        y=0;
    else
      y=-1;
    printf("x=%d,y=%d\n",x,y);
    return 0;
  }