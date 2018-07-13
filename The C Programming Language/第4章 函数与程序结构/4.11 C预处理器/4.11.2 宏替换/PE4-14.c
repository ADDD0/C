/* 定义宏swap(t,x,y)以交换t类型的两个参数
(使用程序块结构会对你有所帮助) */
#include <stdio.h>
#define  dprint(A, B) { printf(#A " = %g  ", A); \
                        printf(#B " = %g\n", B); }
#define  swap(t, x, y) { t _z;   \
                         _z = y; \
                         y = x;  \
                         x = _z; }

main()
{
    float x = 0, y = 1;

    dprint(x, y);
    swap(float, x, y);
    dprint(x, y);
}