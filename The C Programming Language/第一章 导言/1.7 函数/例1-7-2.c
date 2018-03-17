/* power函数：求底数的n次幂；n >= 0 */
/* （早期C语言版本中的实现方法） */
power(base, n);
{
	int i, p;
	
	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}