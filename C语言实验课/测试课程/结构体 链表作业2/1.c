#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  LEN  sizeof(staff)

typedef struct staff
{
    int sno, wage;
    char name[10], dep[10];
    struct staff *next;
} staff;

void initial(staff *head);
void del(staff *head);
void output(staff *head);

main()
{
    staff *head;

    head = (staff *) malloc(LEN);
    initial(head);
    del(head);
    output(head);
}

void initial(staff *head)
{
    staff *pre, *p;

    pre = head;
    p = (staff *) malloc(LEN);
    scanf("%d", &p -> sno);
    while (p -> sno) {
        scanf("%s %s %d",p -> name, p -> dep, &p -> wage);
        pre -> next = p;
        pre = p;
        p = (staff *) malloc(LEN);
        scanf("%d", &p -> sno);
    }
    pre -> next = NULL;
}

void del(staff *head)
{
    staff *pre, *p;
    char finddep[10];

    scanf("%s", finddep);
    pre = head;
    do {
        p = pre -> next;
        if (!strcmp(p -> dep, finddep)) {
            if (!p -> next) {
                pre -> next = NULL;
                break;
            }
            p = p -> next;
            pre -> next = p;
        }
        pre = p;
    } while (pre -> next);
}

void output(staff *head)
{
    staff *p;

    p = head;
    while (p = p -> next)
        printf("%d %s %s %d\n", p -> sno, p -> name, p -> dep, p -> wage);
}