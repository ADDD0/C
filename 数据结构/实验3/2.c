#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

LinkList CreateList(LinkList L, int n) {  //尾插法
    int i;
    LinkList p, pre;

    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    pre = L;
    for (i = n; i > 0; --i) {
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        pre->next = p;
        pre = p;
    }
    pre->next = NULL;
    return L;
}

void Show(LinkList L) {
    for (L = L->next; L; L = L->next)
        printf("%d     ", L->data);
    printf("\n");
}

int main() {
    LinkList La, Lb;

    La = CreateList(La, 6);
    Show(La);
    Lb = CreateList(Lb, 7);
    Show(Lb);
    return 0;
}