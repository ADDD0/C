//有5个学生坐在一起,问第5个学生多少岁,他说比第4个学生大2岁
//问第4个学生岁数,他说比第3个学生大2岁
//问第3个学生,又说比第2个学生大2岁
//问第2个学生,说比第1个学生大2岁
//最后问第1个学生,他说是10岁
//请问第5个学生多大
#include<stdio.h>
int main()
  {
    int age(int n);                  //对age函数的声明
    printf("NO.5,age:%d\n",age(5));  //输出第5个学生的年龄
    return 0;
  }

int age(int n)                       //定义递归函数
  {
    int c;
    if(n==1)                         //如果n等于1
      c=10;                          //年龄为10
    else                             //如果n不等于1
      c=age(n-1)+2;                  //年龄是前一个学生的年龄加2(如第4个学生年龄是第3个学生年龄加2)
    return(c);                       //返回年龄
  }