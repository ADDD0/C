/* 编写一个函数invert(x,p,n),该函数返回对x执行下列
操作后的结果值:将x中从第p位开始的n个(二进制)位求反
(即,1变成0,0变成1),x的其余各位保持不变             */
unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p - n + 1));
}