//输出以下4*5的矩阵
//  1   2   3   4   5
//  2   4   6   8  10
//  3   6   9  12  15
//  4   8  12  16  20
#include<stdio.h>
int main()
  {
    int i,j,n=0;
    for(i=1;i<=4;i++)
      for(j=1;j<=5;j++,n++)  //n用来累计输出数据的个数
        {
          if(n%5==0)         //控制在输出5个数据后换行
            printf("\n");
          printf("%d\t",i*j);
        }
    printf("\n");
    return 0;
  }