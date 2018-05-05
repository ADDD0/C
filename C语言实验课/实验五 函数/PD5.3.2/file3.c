int gcd(int m, int n)
{
	int r;
	
	while (r = m % n) {
		m = n;
		n = r;
	}
	return n;
}