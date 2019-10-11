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

int ListInsert_Sq(SqList *L, int i, int e) {  //按顺序插入,不排序
    int *q, *p;

    if (i < 1 || i > L->length + 1)
        return ERROR;
    q = &(L->elem[i - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    ++L->length;
    return OK;
}

void ListPrint(SqList M) {
    int *p;

    for (p = M.elem; p <= (M.elem + M.length - 1); ++p)
        printf("%d    ", *p);
    printf("\n");
}

int main() {
    int i, n=5, e;
    SqList M;

    Init(&M);
    printf("Input %d numbers:\n", n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &e);
        ListInsert_Sq(&M, i, e);
    }
    ListInsert_Sq(&M, 3, 999);
    printf("After insert:\n");
    ListPrint(M);
    return 0;
}