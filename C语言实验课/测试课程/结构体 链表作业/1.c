#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  LEN  sizeof(Candidate)

typedef struct candidate
{
    int cno;        //候选人编号
    int name[10];   //候选人名字
    int votes;      //票数
    struct candidate *next;
} Candidate;

void initial(Candidate *head);
void voting(Candidate *head);
void output(Candidate *head);

main()
{
    Candidate *head;

    head = (Candidate *) malloc(LEN);
    initial(head);
    voting(head);
    output(head);
}

void initial(Candidate *head)
{
    Candidate *pre, *p;

    pre = head;
    p = (Candidate *) malloc(LEN);
    scanf("%d", &p -> cno);
    while (p -> cno) {
        scanf("%s", p -> name);
        p -> votes = 0;
        pre -> next = p;
        pre = p;
        p = (Candidate *) malloc(LEN);
        scanf("%d", &p -> cno);
    }
    pre -> next = NULL;
}

void voting(Candidate *head)
{
    Candidate *p;
    int name[10];

    while (scanf("%s", name) != EOF) {
        p = head;
        while (p) {
            if (!strcmp(p -> name, name))
                ++p -> votes;
            p = p -> next;
        }
    }
}

void output(Candidate *head)
{
    Candidate *p;

    p = head;
    while (p = p -> next)
        printf("%-4d%-8s%-4d\n", p -> cno, p -> name, p -> votes);
}