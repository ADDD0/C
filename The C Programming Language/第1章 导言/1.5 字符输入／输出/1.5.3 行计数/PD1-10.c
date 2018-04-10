/* 编写一个将输入复制到输出的程序,并将其中的
制表符替换为\t,把回退符替换为\b,把反斜杠替换为\\.
这样可以将制表符和回退符以可见的方式显示出来      */
#include <stdio.h>

/* 用可见字符替换制表符和回退符                   */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}