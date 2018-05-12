int lcm(int m, int n)
{
    return m * n / gcd(m, n);
}