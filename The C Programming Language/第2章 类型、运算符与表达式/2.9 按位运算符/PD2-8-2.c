/* 编写一个函数rightrot(x, n),该函数返回将x循环右移
(即从最右端移出的位将从最左端移入)n(二进制)位后所得到的值                    */
/* rightrot: rotate x to the right by n positions                            */
unsigned rightrot(unsigned x, int n)
{
    int wordlength(void);
    unsigned rbits;

    if ((n = n % wordlength()) > 0) {
        rbits = ~(~0 << n) & x;               /* n rightmost bits of x       */
        rbits = rbits << (wordlength() - n);  /* n rightmost bits to left    */
        x = x >> n;                           /* x shifted n positions right */
        x = x | rbits;                        /* rotation completed          */
    }
    return x;
}

int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}