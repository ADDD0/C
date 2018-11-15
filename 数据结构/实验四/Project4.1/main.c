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

void MergeList(LinkList La, LinkList Lb) {
    LinkList pa=La->next, pb=Lb->next, pc=La, pf;

    free(Lb);
    while (pa && pb)
        if (pa->data < pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else if (pa->data > pb->data) {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        } else {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            pf = pb;
            pb = pb->next;
            free(pf);
        }
    pc->next = pa ? pa : pb;
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
    MergeList(La, Lb);
    Show(La);
    return 0;
}