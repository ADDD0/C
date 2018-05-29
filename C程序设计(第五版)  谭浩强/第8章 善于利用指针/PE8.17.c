/* 写一函数,实现两个字符串的比较
即自己写一个strcmp函数
函数原型为int strcmp(char *p1, char *p2);
设p1指向字符串s1,p2指向字符串s2
要求当s1=s2时,返回值为0;
若s1≠s2,返回它们二者第1个不同字符的ASCII码差值
(如"BOY"与"BAD",第2个字母不同,O与A之差为79-65=14)
如果s1>s2,则输出正值;如果s1<s2,则输出负值         */
#include <stdio.h>

main()
{
    char s1[100], s2[100], *p1, *p2;

    gets(s1);
    gets(s2);
    for (p1 = s1, p2 = s2; *p1 == *p2 && *p1; ++p1, ++p2)
        ;
    if (*p1)
        printf("%d\n", *p1 - *p2);
    else
        printf("0\n");
}