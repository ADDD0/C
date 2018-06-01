/* 已有a,b两个链表,每个链表中的结点包括学号,成绩
要求把两个链表合并,按学号升序排列                                 */
#include <stdio.h>
#include <malloc.h>

typedef struct stu
{
    int sno;
    int sco[3];
    struct stu *next;
} Student;

Student *talloc(void)
{
    return (Student *) malloc(sizeof(Student));
}

main()
{
    Student *a, *b, *pre, *p, *pt;
    int i, *s, t;

    pre = a = talloc();
    for (i = 0; i < 5; ++i) {
        p = talloc();
        p -> sno = i + 100;
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            *s = 90;
        pre -> next = p;
        pre = p;
    }
    pre -> next = NULL;
    pre = b = talloc();
    for (i = 0; i < 3; ++i) {
        p = talloc();
        p -> sno = i + 200;
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            *s = 100;
        pre -> next = p;
        pre = p;
    }                         /* 这之前均为a,b链表的初始化        */
    pre -> next = a -> next;  /* 此时b链表的尾部连接到a链表的头部 */

    p = b -> next;            /* 输出a,b合并后的链表              */
    while (p) {
        printf("No.%d", p -> sno);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            printf("  %3d", *s);
        printf("\n");
        p = p -> next;
    }
    printf("\n");

    pre = b -> next;          /* 类似选择排序法                   */
    while (pre -> next) {     /* 指向倒数第二个结点时跳出循环     */
        p = pt = pre;
        do {
            p = p -> next;
            if (p -> sno < pt -> sno)
                pt = p;
        } while (p -> next);  /* 指向最后一个结点时跳出循环       */
        t = pre -> sno, pre -> sno = pt -> sno, pt -> sno = t;
        for (i = 0; i < 3; ++i)
            t = pre -> sco[i], pre -> sco[i] = pt -> sco[i], pt -> sco[i] = t;
        pre = pre -> next;
    }

    p = b -> next;            /* 输出a,b合并后按升序排序的链表    */
    while (p) {
        printf("No.%d", p -> sno);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            printf("  %3d", *s);
        printf("\n");
        p = p -> next;
    }
}