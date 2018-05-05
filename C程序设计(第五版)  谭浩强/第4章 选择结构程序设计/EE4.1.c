//在例3.5的基础上对程序进行改进
//题目要求解得ax²+bx+c=0方程的根
//由键盘输入a,b,c
//假设a,b,c的值任意,并不保证b²-4ac≥0
//需要在程序中进行判别,如果b²-4ac≥0,就计算并输出方程的两个实根
//如果b²-4ac<0,就输出"此方程无实根"的信息
#include<stdio.h>
#include<math.h>                                            //程序中要调用求平方根函数sqrt
int main()
  {
    double a,b,c,disc,x1,x2,p,q;                            //disc是判别式sqrt(b²-4ac)
    scanf("%lf%lf%lf",&a,&b,&c);                            //输入双精度浮点型变量的值要用格式声明"%lf"
    disc=b*b-4*a*c;
    if(disc<0)                                              //若b²-4ac<0
        printf("This equation hasn't real rootn");          //输出"此方程无实根"
    else                                                    //b²-4ac≥0
      {
        p=-b/(2.0*a);
        q=sqrt(disc)/(2.0*a);
        x1=p+q;x2=p-q;                                      //求出方程的两个根
        printf("real roots:\nx1=%7.2f\nx2=%7.2f\n",x1,x2);  //输出方程的两个根
      }
    return 0;
  }