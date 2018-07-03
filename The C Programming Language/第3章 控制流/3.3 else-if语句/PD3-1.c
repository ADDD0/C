/* 在上面有关折半查找的例子中,whlie循环语句内共执行了两次测试,
其实只要一次就足够(代价是将更多的测试在循环外执行)
重写该函数,使得在循环内部只执行一次测试
比较两种版本函数的运行时间 */
/* binsearch: find x in v[0] <= v[1] <= . . . <= v[n-1]        */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low < high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;  /* found match                            */
    else
        return -1;   /* no match                               */
}