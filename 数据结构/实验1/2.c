#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

int Init(SqList *L) {
    L->elem = (int *) malloc(N * sizeof(int));
    if (!L->elem)
        return ERROR;
    L->length = 0;
    return OK;
}

int SortListInsert(SqList *L, int e) {  //排序插入
    int *q, *p;

    if (!L->length) {
        L->elem[0] = e;
        ++L->length;
        return OK;
    }
    q = &(L->elem[L->length - 1]);
    for (p = &(L->elem[0]); q >= p && e < *q; --q)
        *(q + 1) = *q;
    *(q + 1) = e;
    ++L->length;
    return OK;
}

void ListPrint(SqList M) {
    int *p;

    for (p = M.elem; p <= (M.elem + M.length - 1); ++p)
        printf("%d     ", *p);
    printf("\n");
}

int main() {
    int i, n=5, e;
    SqList M;

    Init(&M);
    printf("Input %d numbers:\n", n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &e);
        SortListInsert(&M, e);
    }
    SortListInsert(&M, 999);
    printf("After insert:\n");
    ListPrint(M);
    return 0;
}