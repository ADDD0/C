/* 找出1000以下自然数中3和5的倍数之和 */
main()
{
    int i, sum = 0;

    for (i = 3; i < 1000; i += 3)
        sum += i;
    for (i = 5; i < 1000; i += 5)
        sum += i;
    for (i = 15; i < 1000; i += 15)
        sum -= i;
    printf("%d\n", sum);
}