#include <stdio.h>
#include <string.h>
#include "edit.h"
#include "file.h"
#include "stu.h"

void edit()
{
    int choice;

    printf("\n0: Stop editing\n");
    printf("1: Insert nodes\n");
    printf("2: Modify nodes\n");
    printf("3: Delete nodes\n");
    printf("Your choice is:");
    scanf("%d", &choice);
    switch (choice) {
        case 0: return;
        case 1: insert(); break;
        case 2: modify(); break;
        case 3: del(); break;
        default : printf("Invalid command code\n\n");
    }
    edit();
}

void insert()
{
    Student *pre, *p;
    int choice, insertnum;
    float *s;

    printf("\n0: Stop inserting\n");
    printf("1: Insert a node at the head of the list\n");  /* 插入头结点           */
    printf("2: Insert a node at the end of the list\n");   /* 插入尾结点           */
    printf("3: Insert a node after any student No.\n");    /* 在任意学号后插入结点 */
    printf("Your choice is:");
    scanf("%d", &choice);
    if (!choice) {
        putchar(10);
        return;
    }
    printf("Input student info:");
    p = talloc();
    scanf("%d %s %d", &p->sno, p->sname, &p->term);
    p->aver = 0.0;
    for (s = p->sco; s < p->sco + COURSE; ++s) {
        scanf("%f", s);
        p->aver += *s;
    }
    p->aver /= COURSE;

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
                    if (pre->next) {    /* 类似于插入头结点 */
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
            break;
        default : printf("Invalid command code\n");
    }
    sort();
    insert();  /* 递归调用 */
}

void modify()
{
    Student *p;
    int i, choice, findnum, findterm;
    char findname[10];

    printf("\n0: Stop modifing\n");
    printf("1: Modify node by student's No. ,name and term\n");  /* 通过学号,姓名和学期修改结点 */
    printf("Your choice is:");
    scanf("%d", &choice);
    if (!choice) {
        putchar(10);
        return;
    }
    printf("Input student's No. ,name and term:");
    scanf("%d %s %d", &findnum, findname, &findterm);

    p = h->next;
    switch (choice) {
        case 1:
            while (p) {
                if (p->sno == findnum && strcmp(p->sname, findname) == 0 && p->term == findterm) {
                    p->aver = 0;
                    printf("Input student's new scores:");  /* 只能修改成绩 */
                    for (i = 0; i < COURSE; ++i)
                        scanf("%f", p->sco + i);
                    for (i = 0; i < COURSE; ++i)
                        p->aver += *(p->sco + i);
                    p->aver /= COURSE;
                }
                p = p->next;
            }
            break;
        default : printf("Invalid command code\n");
    }
    sort();
    modify();  /* 递归调用 */
}

void del()
{
    Student *pre, *p;
    int choice, findnum;
    char findname[10];

    printf("\n0: Stop deleting\n");
    printf("1: Delete node by student's No.\n");       /* 通过学号删除结点 */
    printf("2: Delete node by student's name\n");      /* 通过姓名删除结点 */
    printf("3: Delete nodelist\n");                    /* 删除整个链表     */
    printf("Your choice is:");
    scanf("%d", &choice);
    switch (choice) {
        case 0:
            return;
        case 1:
            printf("Input No.:");
            scanf("%d", &findnum);
            pre = h;
            do {
                p = pre->next;
                if (p->sno == findnum) {               /* 发现匹配学号     */
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
        case 3:
            h->next = NULL;
            break;
        default : printf("Invalid command code\n");
    }
    sort();
    del();  /* 递归调用 */
}