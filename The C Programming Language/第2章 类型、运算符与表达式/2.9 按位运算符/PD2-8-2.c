/* 编写一个函数rightrot(x, n),该函数返回将x循环右移
(即从最右端移出的位将从最左端移入)n(二进制)位后所得到的值      */
/* rightrot函数:将x循环右移n位                                 */
unsigned rightrot(unsigned x, int n)
{
    int wordlength(void);
    unsigned rbits;

    if ((n = n % wordlength()) > 0) {
        rbits = ~(~0 << n) & x;               /* x最右边n位    */
        rbits = rbits << (wordlength() - n);  /* 左移最右边n位 */
        x = x >> n;                           /* x右移n位      */
        x = x | rbits;                        /* 循环完成      */
    }
    return x;
}

/* wordlength函数:计算计算机的字长                             */
int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}