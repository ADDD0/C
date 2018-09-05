/* 排序算法合集
/*
/* 默认排序数据类型为int
/* 默认按递增顺序进行排序
/* n = sizeof(v) / sizeof(int)
/* */
#include <stdio.h>

/* 冒泡排序 */
void bubble(int v[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; ++i)
        for (j = 0; j < n - 1 - j; ++j)
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
}

/* 希尔排序 */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

/* 快速排序 */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap函数: 交换v[i]与v[j]的值 */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}