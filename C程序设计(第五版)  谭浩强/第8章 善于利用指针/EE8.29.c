//有一个指针数组,其元素分别指向一个整型数组的元素
//用指向指针数据的指针变量,输出整型数组各元素的值
//这是一个简单例子,目的是为了说明它的用法
#include<stdio.h>
int main()
  {
    int a[5]={1,3,5,7,9};
    int *num[5]={&a[0],&a[1],&a[2],&a[3],&a[4]};
    int **p,i;  //p是指向指针型数据的指针变量
    p=num;      //使p指向num[0]
    for(i=0;i<5;i++)
      {
        printf("%d ",**p);
        p++;
      }
    printf("\n");
    return 0;
  }