#include "BiTree.h"
#include <stdio.h>
#include <stdlib.h>

static int count=0;

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

int PreOrderTraverse(BiTree T) {
    if (T) {
        if (isupper(T->data))
            ++count;
        putchar(T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    } else
        return ERROR;
}

int main() {
    BiTree T;

    T = CreateBiTree(T);
    printf("The preorder of T is:\n");
    PreOrderTraverse(T);
    printf("\ncount=%d\n", count);
    return 0;
}