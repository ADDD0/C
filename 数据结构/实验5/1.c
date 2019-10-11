#include "BiTree.h"
#include <stdio.h>
#include <stdlib.h>

BiTree CreateBiTree(BiTree T) {
    char ch;

    if ((ch = getchar()) == '#')
        T = NULL;
    else {
        if (!(T = (BiTNode *) malloc(sizeof(BiTNode))))
            return ERROR;
        T->data = ch;
        T->lchild = CreateBiTree(T->lchild);
        T->rchild = CreateBiTree(T->rchild);
    }
    return T;
}

int main() {
    BiTree T;

    T = CreateBiTree(T);
    printf("BiTree has been initialized.\n");
    return 0;
}