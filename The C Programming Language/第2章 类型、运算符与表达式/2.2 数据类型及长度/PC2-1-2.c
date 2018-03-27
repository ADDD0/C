#include <stdio.h>

/* 编写一个程序以确定分别由signed及unsigned
限定的char、short、int与long类型变量的取值范围 */
/* 直接计算 */
main()
{
    /* 有符号数据类型                          */
    printf("signed char min  = %d\n", -(char)((unsigned char) ~0 >> 1));
    printf("signed char max  = %d\n", (char)((unsigned char) ~0 >> 1));
    printf("signed short min = %d\n", -(short)((unsigned short) ~0 >> 1));
    printf("signed short max = %d\n", (short)((unsigned short) ~0 >> 1));
    printf("signed int min   = %d\n", -(int)((unsigned int) ~0 >> 1));
    printf("signed int max   = %d\n", (int)((unsigned int) ~0 >> 1));
    printf("signed long min  = %ld\n", -(long)((unsigned long) ~0 >> 1));
    printf("signed long max  = %ld\n", (long)((unsigned long) ~0 >> 1));
    /* 无符号数据类型                          */
    printf("unsigned char max  = %u\n", (unsigned char) ~0);
    printf("unsigned short max = %u\n", (unsigned short) ~0);
    printf("unsigned int max   = %u\n", (unsigned int) ~0);
    printf("unsigned long max  = %lu\n", (unsigned long) ~0);
}