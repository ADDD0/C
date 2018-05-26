/* 写几个函数:
① 输入10个职工的姓名和职工号
② 按职工号由小到大顺序排序,姓名顺序也随之调整
③ 要求输入一个职工号,用折半查找法找出该职工的姓名
从主函数输入要查找的职工号,输出该职工姓名 */
#include <stdio.h>

#define  N  3

struct staff
{
    int sno;
    char sname[10];
};

main()
{
    void input(struct staff s[]);
    void sort(struct staff s[]);
    void find(struct staff s[]);
    void print(struct staff s);

    struct staff s[N];
    int i;

    input(s);
    sort(s);
    for (i = 0; i < N; ++i)
        print(s[i]);
    find(s);
}

void input(struct staff s[])
{
    int i;

    for (i = 0; i < N; ++i)
        scanf("%d %s", &s[i].sno, s[i].sname);
}

void sort(struct staff s[])
{
    struct staff t;
    int i, j;

    for (i = 0; i < N - 1; ++i)
        for (j = 0; j < N - 1 - i; ++j)
            if (s[j].sno > s[j + 1].sno)
                t = s[j], s[j] = s[j + 1], s[j + 1] = t;
}

void find(struct staff s[])
{
    void print(struct staff s);

    int x, low, high, mid;

    printf("Search No.:");
    scanf("%d", &x);
    low = 0;
    high = N - 1;
    mid = (low + high) / 2;
    while (low < high && x != s[mid].sno) {
        if (x < s[mid].sno)
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == s[mid].sno)
        print(s[mid]);
    else
        printf("Match failed\n");
}

void print(struct staff s)
{
    printf("No.%d name:%s\n", s.sno, s.sname);
}