/* 13个人围成一圈,从第1个人开始顺序报号1,2,3
凡报到3者退出圈子,找出最后留在圈子中的人原来的序号
要求用链表实现                                       */
#include <stdio.h>
#include <malloc.h>

typedef struct person
{
    int number;
    struct person *next;
} Head;

Head *talloc(void)
{
    return (Head *) malloc(sizeof(Head));
}

main()
{
    Head *h, *pre, *p;
    int i, n, flag;

    printf("Input number n:");
    scanf("%d", &n);
    pre = h = talloc();
    for (i = 0; i < n - 1; ++i) {
        p = talloc();
        p -> number = i + 2;
        pre -> next = p;
        pre = p;
    }
    p -> next= h;  /* 使链表形成一个环               */
    h -> number = flag = 1;
    while (n - 1) {
        ++flag;    /* 这里记录的是下一个人将要报的数 */
        if (flag == 3) {
            h -> next = h -> next -> next;
            --n;
            flag = 1;
        }
        h = h -> next;
    }
    printf("%d\n", h -> number);
}