//定义一个字符数组,在其中存放字符串"I love China!",输出该字符串和第8个字符
#include<stdio.h>
int main()
  {
    char string[]="I love China!";  //定义字符数组string
    printf("%s\n",string);          //用%s格式声明输出string,可以输出整个字符串
    printf("%c\n",string[7]);       //用%c格式输出一个字符数组元素
    return 0;
  }