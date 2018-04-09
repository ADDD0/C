/* 编写一个函数rightrot(x, n),该函数返回将x循环右移
(即从最右端移出的位将从最左端移入)n(二进制)位后所得到的值 */
unsigned rightrot(unsigned x, int n)
{
    int wordlength(void);
    int rbit;          /* 最右边的位                      */

    while (n-- > 0) {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;    /* 将x右移1位                      */
        x = x | rbit;  /* 完成一次循环                    */
    }
    return x;
}

/**/
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;
	 
	for (i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}