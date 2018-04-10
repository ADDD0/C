#include <stdio.h>
#include <limits.h>

/* 编写一个程序以确定分别由signed及unsigned
限定的char,short,int与long类型变量的取值范围
打印标准头文件中的相应值                     */
main()
{
    /* 有符号数据类型                        */
    printf("signed char min  = %d\n", SCHAR_MIN);
    printf("signed char max  = %d\n", SCHAR_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    printf("signed int min   = %d\n", INT_MIN);
    printf("signed int max   = %d\n", INT_MAX);
    printf("signed long min  = %ld\n", LONG_MIN);
    printf("signed long max  = %ld\n", LONG_MAX);
    /* 无符号数据类型                        */
    printf("unsigned char max  = %u\n", UCHAR_MAX);
    printf("unsigned short max = %u\n", USHRT_MAX);
    printf("unsigned int max   = %u\n", UINT_MAX);
    printf("unsigned long max  = %lu\n", ULONG_MAX);
}