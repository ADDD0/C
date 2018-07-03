/* 综合本章例9.9(建立链表的函数creat),例9.10(输出链表的函数print)
和本章习题第7题(删除链表中结点的函数del),第8题(插入结点的函数insert)
再编写一个主函数,先后调用这些函数,用以上5个函数组成一个程序
实现链表的建立,输出,删除和插入,在主函数中指定需要删除和插入的结点的数据 */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct stu
{
    int sno;
    char sname[10];
    int sco[3];
    struct stu *next;
} Student;

Student *talloc(void)
{
    return (Student *) malloc(sizeof(Student));
}

Student *h;  /* 链表头被声明为全局变量,不可更改               */

main()
{
    void creat();              /* 建立链表                    */
    void print();              /* 输出链表                    */
    void del();                /* 删除结点                    */
    void insert();             /* 插入结点                    */
    void sort();               /* 增加排序功能                */
    void search();             /* 增加搜索功能                */

    Student *pre, *p;
    int i, choice, *s;

    h = talloc();
    pre = h;
    for (i = 0; i < 5; ++i) {  /* 初始化一个含有5个数据的链表 */
        p = talloc();
        p->sno = i + 100;
        p->sname[0] = 'a' + i;
        for (s = p->sco;  s < p->sco + 3; ++s)
            *s = 90;
        pre->next = p;
        pre = p;
    }
    pre->next = NULL;

    while (1) {
        printf("%-30s", "1: Create a new nodelist");
        printf("%-30s", "2: Print current nodelist");
        printf("\n");
        printf("%-30s", "3: Delete nodes");
        printf("%-30s", "4: Insert nodes");
        printf("\n");
        printf("%-30s", "5: Sort current nodelist");
        printf("%-30s", "6: Search in nodelist");
        printf("\n0: Exit\n");
        printf("Your choice is:");
        scanf("%d", &choice);
        printf("\n");
        if (!choice) {
            printf("\n");
            return;
        }
        switch (choice) {
            case 1: creat(); break;
            case 2: print(); break;
            case 3: del(); break;
            case 4: insert(); break;
            case 5: sort(); break;
            case 6: search(); break;
            default : printf("Invalid command code\n");
        }
    }
}

void creat()
{
    Student *pre, *p;
    int n, i, *s;

    pre = h;
    printf("Note: This operation will eliminate the previous list\n");
    /* 创建后会删除原先的链表 */
    printf("Input nodelist's length n:");
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        printf("Input student %d's info:", i + 1);
        p = talloc();
        scanf("%d %s", &p->sno, p->sname);
        for (s = p->sco; s < p->sco + 3; ++s)
            scanf("%d", s);
        pre->next = p;
        pre = p;
    }
    p->next = NULL;
    printf("\n");
}

void print()
{
    Student *p;
    int *s;

    p = h->next;
    if (!p)  /* 链表为空时    */
        printf("Nodelist is not initialized or has been deleted\n");
    while (p) {
        printf("No.%d %s:", p->sno, p->sname);
        for (s = p->sco;  s < p->sco + 3; ++s)
            printf("  %d", *s);
        printf("\n");
        p = p->next;
    }
    printf("\n");
}

void del()
{
    Student *pre, *p;
    int choice, findnum;
    char findname[10];

    printf("0: Stop deleting\n");
    printf("1: Delete node by student's No.\n");         /* 通过学号删除结点 */
    printf("2: Delete node by student's name\n");        /* 通过姓名删除结点 */
    printf("3: Delete nodelist\n");                      /* 删除整个链表     */
    printf("Your choice is:");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Input No.:");
            scanf("%d", &findnum);
            pre = h;
            do {
                p = pre->next;
                if (p->sno == findnum) {            /* 发现匹配学号     */
                    if (!p->next) {                    /* 指向尾结点       */
                        pre->next = NULL;
                        break;
                    }
                    p = p->next;
                    pre->next = p;
                }
                pre = p;
            } while (pre->next);
            break;
        case 2:
            printf("Input name:");
            scanf("%s", findname);
            pre = h;
            do {
                p = pre->next;
                while (!strcmp(p->sname, findname)) {  /* 发现匹配姓名     */
                    if (!p->next) {                    /* 指向尾结点       */
                        pre->next = NULL;
                        break;
                    }
                    p = p->next;
                    pre->next = p;
                }
                pre = p;
            } while (pre->next);
            break;
        case 3: h->next = NULL;
        default : printf("\n"); return;
    }
    printf("\n");
    del(h);  /* 递归调用 */
}

void insert()
{
    Student *pre, *p;
    int choice, insertnum, *s;

    printf("0: Stop inserting\n");
    printf("1: Insert a node at the head of the list\n");  /* 插入头结点           */
    printf("2: Insert a node at the end of the list\n");   /* 插入尾结点           */
    printf("3: Insert a node after any student No.\n");    /* 在任意学号后插入结点 */
    printf("Your choice is:");
    scanf("%d", &choice);
    if (!choice) {
        printf("\n");
        return;
    }
    printf("Input student info:");
    p = talloc();
    scanf("%d %s", &p->sno, p->sname);
    for (s = p->sco; s < p->sco + 3; ++s)
    scanf("%d", s);
    pre = h;
    switch (choice) {
        case 1:
            p->next = pre->next;
            pre->next = p;
            break;
        case 2:
            while (pre->next)
                pre = pre->next;
            pre->next = p;
            p->next = NULL;
            break;
        case 3:
            printf("Input the location to insert(in No.):");
            scanf("%d", &insertnum);
            do {
                pre = pre->next;
                if (pre->sno == insertnum) {
                    if (pre->next) {  /* 类似于插入头结点 */
                        p->next = pre->next;
                        pre->next = p;
                        break;
                    }
                    else {              /* 类似于插入尾结点 */
                        pre->next = p;
                        p->next = NULL;
                    }
                }
            } while (pre->next);
        default : printf("\n"); return;
    }
    printf("\n");
    insert();  /* 递归调用 */
}

void sort()
{
    Student *pre, *p, *pt;
    int choice, t, i;
    char s[10];

    printf("11: Ascending by student's No.s\n");    /* 按学号升序排序 */
    printf("12: Descending by student's No.s\n");   /* 按学号降序排序 */
    printf("21: Ascending by student's names\n");   /* 按姓名升序排序 */
    printf("22: Descending by student's names\n");  /* 按姓名降序排序 */
    scanf("%d", &choice);
    switch (choice) {
        case 11:
            pre = h->next;
            while (pre->next) {
                p = pt = pre;
                do {
                    p = p->next;
                    if (p->sno < pt->sno)
                        pt = p;
                } while (p->next);
                t = pre->sno, pre->sno = pt->sno, pt->sno = t;
                strcpy(s, pre->sname), strcpy(pre->sname, pt->sname), strcpy(pt->sname, s);
                for (i = 0; i < 3; ++i)
                    t = pre->sco[i], pre->sco[i] = pt->sco[i], pt->sco[i] = t;
                pre = pre->next;
            }
            break;
        case 12:
            pre = h->next;
            while (pre->next) {
                p = pt = pre;
                do {
                    p = p->next;
                    if (p->sno > pt->sno)
                        pt = p;
                } while (p->next);
                t = pre->sno, pre->sno = pt->sno, pt->sno = t;
                strcpy(s, pre->sname), strcpy(pre->sname, pt->sname), strcpy(pt->sname, s);
                for (i = 0; i < 3; ++i)
                    t = pre->sco[i], pre->sco[i] = pt->sco[i], pt->sco[i] = t;
                pre = pre->next;
            }
            break;
        case 21:
            pre = h->next;
            while (pre->next) {
                p = pt = pre;
                do {
                    p = p->next;
                    if (strcmp(p->sname, pt->sname) < 0)
                        pt = p;
                } while (p->next);
                t = pre->sno, pre->sno = pt->sno, pt->sno = t;
                strcpy(s, pre->sname), strcpy(pre->sname, pt->sname), strcpy(pt->sname, s);
                for (i = 0; i < 3; ++i)
                    t = pre->sco[i], pre->sco[i] = pt->sco[i], pt->sco[i] = t;
                pre = pre->next;
            }
            break;
        case 22:
            pre = h->next;
            while (pre->next) {
                p = pt = pre;
                do {
                    p = p->next;
                    if (strcmp(p->sname, pt->sname) > 0)
                        pt = p;
                } while (p->next);
                t = pre->sno, pre->sno = pt->sno, pt->sno = t;
                strcpy(s, pre->sname), strcpy(pre->sname, pt->sname), strcpy(pt->sname, s);
                for (i = 0; i < 3; ++i)
                    t = pre->sco[i], pre->sco[i] = pt->sco[i], pt->sco[i] = t;
                pre = pre->next;
            }
            break;
    }
    printf("\n");
}

void search()
{
    void searchnum();
    void searchname();

    int choice;

    printf("1: Search in No.\n");
    printf("2: Search in name\n");
    scanf("%d", &choice);
    if (choice == 1)
        searchnum();
    else if (choice == 2)
        searchname();
}

void searchnum()
{
    struct stu *p;
    int findnum, *s;

    p = h->next;
    printf("Search No.:");
    scanf("%d", &findnum);
    while (p) {
        if (p->sno == findnum) {
            printf("No.%d %s:", p->sno, p->sname);
            for (s = p->sco;  s < p->sco + 3; ++s)
                printf("  %d", *s);
            printf("\n");
        }
        p = p->next;
    }
    printf("\n");
}

void searchname()
{
    struct stu *p;
    char findname[10];
    int *s;

    p = h->next;
    printf("Search name:");
    scanf("%s", findname);
    while (p) {
        if (!strcmp(p->sname, findname)) {
            printf("No.%d %s:", p->sno, p->sname);
            for (s = p->sco;  s < p->sco + 3; ++s)
                printf("  %d", *s);
            printf("\n");
        }
        p = p->next;
    }
    printf("\n");
}