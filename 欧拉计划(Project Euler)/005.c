/* 找出最小的能被1-20中每个数整除的数 */
main()
{
    int lcm(int x, int y);
    int i, s;

    for (i = s = 1; i < 20; ++i){
        s = lcm(s, i);
        printf("%d\n", s);
    }
}

int lcm(int x, int y)
{
    int gcd(int x, int y);
    return (x * y / gcd(x, y));
}

int gcd(int x, int y)
{
    int t;

    while (t = x % y) {
        x = y;
        y = t;
    }
    return y;
}