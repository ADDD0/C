//while和do…while循环的比较
//用do…while循环
#include<stdio.h>
int main()
  {
    int i,sum=0;
    printf("please enter i,i=?");
    scanf("%d",&i);
    do
      {
        sum=sum+i;
        i++;
      }
    while(i<=10);
    printf("sum=%d\n",sum);
    return 0;
  }