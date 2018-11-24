#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

LinkList CreateList(LinkList L, int n) {
    int i;
    LinkList p, pre;

    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    pre=L;
    for (i = n; i > 0; --i) {
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        pre->next = p;
        pre = p;
    }
    pre->next = NULL;
    return L;
}

void ReverseList(LinkList L) {
    LinkList pre, p;

    pre = L->next;
    L->next = NULL;
    while (p = pre->next) {
        pre->next = L->next;
        L->next = pre;
        pre = p;
    }
    pre->next = L->next;
    L->next = pre;
}

void Show(LinkList L) {
    for (L = L->next; L; L = L->next)
        printf("%d     ", L->data);
    printf("\n");
}

int main() {
    LinkList L;

    L = CreateList(L, 6);
    Show(L);
    ReverseList(L);
    printf("The after reverse L is:\n");
    Show(L);
    return 0;
}