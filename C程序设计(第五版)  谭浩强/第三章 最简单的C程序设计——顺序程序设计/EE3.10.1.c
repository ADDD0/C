#include <stdio.h>
int main()
  {
    char c1,c2;
    c1=getchar();  //从键盘读入一个大写字母,赋给字符变量c1
    c2=c1+32;      //求对应小写字母的ASCII代码,放在字符变量c2中
    putchar(c2);   //输出c2的值,是一个字符
    putchar('\n');
    return 0;
  }