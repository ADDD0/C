/* 编写程序:将从键盘上输入的一组数排序输出
具体要求:
①在main函数中输入待排序的数据,输出排序后的结果
②在自定义函数中实现将这组数据按照从大到小顺序进行排序的功能
③自定义函数的形式参数使用指针实现

例如:
//主函数               用户自定义函数
void main()            void f_sort(int *p,int n)
{                      {
    int a[10];             对数组p中的n个数进行排序;
    输入待排序的数据;  }
    f_sort(a,10);
    输出排序后的数据;
}                                                            */
#include <stdio.h>

main()
{
    void f_sort(int *p, int n);
    int a[10];
    int i;

    for (i = 0; i < 10; ++i)
        scanf("%d", a + i);
    f_sort(a, 10);
    for (i = 0; i < 10; ++i)
        printf("%d ", *(a + i));
    printf("\n");
}

void f_sort(int *p, int n)
{
    int i, j, t;

    for (i = 0; i < n - 1; ++i)
        for (j = 0; j < n - i - 1; ++j)
            if (*(p + j) < *(p + j + 1))
                t = *(p + j), *(p + j) = *(p + j + 1), *(p + j + 1) = t;
}