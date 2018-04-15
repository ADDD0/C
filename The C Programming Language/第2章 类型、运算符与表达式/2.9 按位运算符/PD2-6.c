/* 编写一个函数setbits(x,p,n,y),该函数返回对x执行下列操作后的结果值:
将x中从第p位开始的n个(二进制)位设置为y中最右边n位的值,x的其余各位保持不变 */
/* setbits函数:将x中从第p位开始的n位设置为y中最右边n位的值                */
unsigned setbits(unsigned x, int p, int n,unsigned y)
{
    return x & ~(~(~0 << n) << (p - n + 1)) | (y & ~(~0 << n)) << (p - n + 1);
}