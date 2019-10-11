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

LinkList IntersectList(LinkList La, LinkList Lb) {
    LinkList pa=La->next, pb=Lb->next, pc=La, pf;

    free(Lb);
    while (pa && pb)
        if (pa->data < pb->data) {
            pf = pa;
            pa = pa->next;
            free(pf);
        } else if (pa->data > pb->data) {
            pf = pb;
            pb = pb->next;
            free(pf);
        } else {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            pf = pb;
            pb = pb->next;
            free(pf);
        }
    pc->next = NULL;
    return La;
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
    La = IntersectList(La, Lb);
    Show(La);
    return 0;
}