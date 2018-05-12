//求Fibonacci(斐波那契)数列的前40个数
//这个数列有如下特点:
//第1,2两个数为1,1
//从第3个数开始,该数是其前面两个数之和
//即该数列为1,1,2,3,5,8,13,…
#include<stdio.h>
int main()
  {
    int f1=1,f2=1,f3;
    int i;
    printf("%12d\n%12d\n",f1,f2);
    for(i=1;i<=38;i++)
      {
        f3=f1+f2;
        printf("%12d\n",f3);
        f1=f2;
        f2=f3;
      }
    return 0;
  }