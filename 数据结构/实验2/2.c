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

int SortListInsert(SqList *L, int e) {
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

void ListSearch_Sq(SqList M, int e) {
    int i, flag=0;

    for (i = 0; i < M.length; ++i)
        if (M.elem[i] == e) {
            printf("Find %d at M[%d]\n", e, i + 1);
            flag = 1;
        }
    if (!flag)
        printf("Not found\n");
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
    printf("Input %d numbers, Please:\n", n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &e);
        SortListInsert(&M, e);
    }
    SortListInsert(&M, 999);
    printf("After insert:\n");
    ListPrint(M);
    printf("Input number you want to search:");
    scanf("%d", &e);
    ListSearch_Sq(M, e);
    return 0;
}