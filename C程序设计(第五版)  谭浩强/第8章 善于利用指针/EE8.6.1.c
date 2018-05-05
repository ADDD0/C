//有一个整型数组a,有10个元素,要求输出数组中的全部元素
//下标法
#include<stdio.h>
int main()
  {
    int a[10];
    int i;
    printf("please enter 10 integer numbers:");
    for(i=0;i<10;i++)
      scanf("%d",&a[i]);
    for(i=0;i<10;i++)
      printf("%d ",a[i]);  //数组元素用数组名和下标表示
    printf("\n");
    return 0;
  }