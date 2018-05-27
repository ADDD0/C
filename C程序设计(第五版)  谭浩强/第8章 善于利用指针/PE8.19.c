/* (1)编写一个函数new,对n个字符开辟连续的存储空间
此函数应返回一个指针(地址),指向字符串开始的空间
new(n)表示分配n个字节的内存空间
(2)写一函数free,将前面用new函数占用的空间释放
free(p)表示将p(地址)指向的单元以后的内存段释放 */
#include <stdio.h>

main()
{
    char *new(int n);
    void free(void *p);

    int n;
    char *p;

    scanf("%d", &n);
    p = new(n);
    free(p);
}

char *new(int n)
{
    return (char *) malloc(sizeof(char) * n);
}