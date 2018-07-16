/* 用指针方式实现第2章中的函数strcat
函数strcat(s,t)将t指向的字符串复制到s指向的字符串的尾部   */
/* strcat: concatenate t to the end of s; pointer version */
void strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}