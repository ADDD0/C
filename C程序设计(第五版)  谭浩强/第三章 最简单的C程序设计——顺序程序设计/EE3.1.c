//有人用温度计测量出用华氏法表示的温度(如64F),今要求把它转换为以摄氏法表示的温度(如17.8C)
#include<stdio.h>
int main()
  {
    float f,c;                   //定义f和c为单精度浮点型变量
    f=64.0;                      //指定f的值
    c=(5.0/9)*(f-32);            //利用公式计算c的值
    printf("f=%f\nc=%f\n",f,c);  //输出c的值
    return 0;
  }