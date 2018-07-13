/* qsort函数: 以递增顺序对v[left] …v[right]进行排序                    */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)                   /* 若数组包含的元素数少于两个 */
        return;                          /* 则不执行任何操作           */
    swap(v, left, (left + right) / 2);   /* 将划分子集的元素           */
    last = left;                         /* 移动到v[0]                 */
    for (i = left + 1; i <= right; i++)  /* 划分子集                   */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);                 /* 恢复划分子集的元素         */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap函数: 交换v[i]与v[j]的值                                        */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}