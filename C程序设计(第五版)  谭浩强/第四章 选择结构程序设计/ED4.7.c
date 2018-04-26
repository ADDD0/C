//用switch语句处理菜单命令
//在许多应用程序中,用菜单对流程进行控制
//例如从键盘输入一个'A'或'a'字符,就会执行A操作
//输入一个'B'或'b'字符,就会执行B操作
#include<stdio.h>
int main()
  {
    void action1(int,int),action2(int,int);  //函数声明
    char ch;
    int a=15,b=23;
    ch=getchar();
    switch(ch)
      {
        case'a':
        case'A':action1(a,b);break;          //调用action1函数,执行A操作
        case'b':
        case'B':action2(a,b);break;          //调用action2函数,执行B操作
        default:putchar('\a');               //如果输入其他字符,发出警告
      }
    return 0;
  }

void action1(int x,int y)                    //执行加法的函数
  {
    printf("x+y=%d\n",x+y);
  }

void action2(int x,int y)                    //执行乘法的函数
  {
    printf("x*y=%d\n",x+y);
  }