//写一程序,判断某一年是否为闰年
#include<stdio.h>
int main()
  {
    int year,leap;
    printf("enter year:");
    scanf("%d",&year);
    if((year%4==0&&year%100!=0)||(year%400==0))
      leap=1;
    else
      leap=0;
    if(leap)
      printf("%d is ",year);
    else
      printf("%d is not ",year);
    printf("a leap year.\n");
    return 0;
  }