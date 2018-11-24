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

int PreOrderTraverse(BiTree T) {     //先序
    if (T) {
        putchar(T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    } else
        return ERROR;
}

int MediumOrderTraverse(BiTree T) {  //中序
    if (T) {
        MediumOrderTraverse(T->lchild);
        putchar(T->data);
        MediumOrderTraverse(T->rchild);
    } else
        return ERROR;
}

int SumLeaf(BiTree T) {              //叶子数
    if (!T)
        return 0;
    if (!SumLeaf(T->lchild) && !SumLeaf(T->rchild))
        return 1;
    else
        return SumLeaf(T->lchild) + SumLeaf(T->rchild);
}

int main() {
    BiTree T;

    T = CreateBiTree(T);
    printf("The preorder of T is:\n");
    PreOrderTraverse(T);
    putchar('\n');
    printf("The medium order of T is:\n");
    MediumOrderTraverse(T);
    putchar('\n');
    printf("The sum of the leaves is:%d\n", SumLeaf(T));
    return 0;
}