/* 在斐波那契数列中，找出4百万以下的项中值为偶数的项之和 */
main()
{
    int f1, f2, f, sum = 0;

    f1 = f2 = 1;
	while (f < 4000000) {
        f = f1 + f2, f1 = f2, f2 = f;
        if (!(f % 2))
            sum += f;
    }
    printf("%d\n", sum);
}