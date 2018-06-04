/* 在题目2的程序中添加一个函数f_search
该函数的功能用于实现:从键盘上输入一个姓名,
在单链表中查找该姓名的学生是否存在(可虑可能有重名的情况)
若存在,则输出学生的详细信息,若不存在,给出相应的提示
void f_search(struct stu *h)
{
    count=0;
    将p指向首结点;
    输入要查找的姓名;
    while(p!=NULL)
    {
        if(p->sname是要查找的姓名)
        {
            count++;
            输出p指向结点的内容;
        }
        p指向下一个结点;
    }
    if(count==0)
        printf(“No this name.\n”);
}                                                        */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct stu
{
    char sno[6];
    char sname[10];
    int sco[3];
    struct stu *next;
};

struct stu *talloc(void)
{
    return (struct stu *) malloc(sizeof(struct stu));
}

main()
{
    void f_create(struct stu *h, int n);
    void f_search(struct stu *h);

    struct stu *Head;
    int n;

    printf("Input number n:");
    scanf("%d", &n);
    Head = talloc();
    f_create(Head, n);
    f_search(Head);
}

void f_create(struct stu *h, int n)
{
    struct stu *pre, *p;
    int i, *s;

    pre = h;
    for (i = 0; i < n; ++i) {
        printf("Input student %d's info:", i + 1);
        p = talloc();
        scanf("%s %s", p -> sno, p -> sname);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            scanf("%d", s);
        pre -> next = p;
        pre = p;
    }
    pre -> next = NULL;
}

void f_search(struct stu *h)
{
    struct stu *p;
    char find[10];
    int count = 0, *s;

    p = h -> next;
    printf("Search name:");
    scanf("%s", find);
    while (p) {
        if (!strcmp(p -> sname, find)) {
            ++count;
            printf("No.%s %s:", p -> sno, p -> sname);
            for (s = p -> sco;  s < p -> sco + 3; ++s)
                printf("  %d", *s);
            printf("\n");
        }
        p = p -> next;
    }
    if (count)
        printf("Found %d '%s'\n", count, find);
    else
        printf("No this name.\n");
}