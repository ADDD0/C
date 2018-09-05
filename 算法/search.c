/* 查找算法合集
/*
/* 默认查找数据类型为int
/* n = sizeof(v) / sizeof(int)
/* */
#include <stdio.h>

/* 折半查找(需要提前排好序) */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}