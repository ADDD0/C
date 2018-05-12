/* 编程实现:删除一个字符串中的所有*号,并将其中的小写字母转换成大写字母,输出变化后的字符串
例如:
若从键盘上输入一个字符串为:****abCD**Efg*hi*Jk******,最终在屏幕上的输出结果为:ABCDEFGHIJK

要求如下:
//主函数                 用户自定义函数
void main()              void my_del(char *s)
{                        {
    char a[80];              对数组s中的字符进行处理;
    输入待处理的字符串;  }
    my_del(s);
    输出处理后的字符串;
}                                                                                         */
#include <stdio.h>
#include <ctype.h>

main()
{
    void my_del(char *s);
    int a[80];

    gets(a);
    my_del(a);
    puts(a);
}

void my_del(char *s)
{
    int i, j;

    i = j = 0;
    while (*(s + i) != '\0') {
        if (*(s + i) == '*')
            ;
        else {
            if (islower(*(s + i)))
                *(s + j) = toupper(*(s + i));
            else
                *(s + j) = *(s + i);
            ++j;
        }
        ++i;
    }
    *(s + j) = '\0';
}