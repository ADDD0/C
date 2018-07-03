/* 编写函数any(s1,s2),将字符串s2中的任一字符在字符串s1中第一次
出现的位置作为结果返回.如果s1中不包含s2中的字符,则返回-1.
(标准库函数strpbrk具有同样的功能,但它返回的是指向该位置的指针.)   */
#include <stdio.h>

main()
{
    int any(char s1[], char s2[]);
    char s1[128], s2[128];

    gets(s1);
    gets(s2);
    printf("%d\n", any(s1, s2));
}

/* any: return first location in s1 where any char from s2 occurs */
int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])  /* match found?                  */
                return i;        /* location first match          */
    return -1;                   /* otherwise, no match           */
}