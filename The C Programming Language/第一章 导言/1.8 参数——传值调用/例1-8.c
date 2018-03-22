/*	power函数：求底数的n次幂； n>=0；版本2	*/
int power(int base, int n)
{
	int p;
	
	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}