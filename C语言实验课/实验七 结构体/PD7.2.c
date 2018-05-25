/* 编写程序实现:使用后插法建立一个带头结点的存储学生信息的单链表
并将建立后的学生链表中的信息输出到屏幕上,学生的结构体类型可自行定义

具体要求:
①单链表的建立和单链表的显示分别使用函数实现
②在main函数中完成初始化工作并调用上述两个函数

例如:
//f_create函数建立单链表                //main函数
void f_create(struct stu *h,int n)      void main()
{                                       {
    建立n个学生信息的带头结点的单链表;      struct stu *Head;
}                                           初始化空链表Head;
                                            输入学生的人数n;
//f_show函数,在屏幕上显示单链表的内容       f_create(Head,n);
void f_show(struct stu *h)                  f_show(Head);
{                                       }
    显示单链表h中的内容;
}                                                                   */
#include <stdio.h>
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
    void f_show(struct stu *h);

    struct stu *Head;
    int n;
    printf("Input number n:");
    scanf("%d", &n);
    Head = talloc();
    f_create(Head, n);
    f_show(Head);
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
    p -> next = NULL;
}

void  f_show(struct stu *h)
{
    struct stu *p;
    int *s;

    p = h -> next;
    while (p) {
        printf("No.%s %s:", p -> sno, p -> sname);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            printf("  %d", *s);
        printf("\n");
        p = p -> next;
    }
}