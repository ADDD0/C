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

int SumOfNode(BiTree T) {  //度数为1的结点数
    int sum=0;

    if (T) {
        if (!T->lchild + !T->rchild == 1)
            ++sum;
        sum += SumOfNode(T->lchild) + SumOfNode(T->rchild);
    }
    return sum;
}

int main() {
    BiTree T;
    int countSum;

    T = CreateBiTree(T);
    printf("BiTree has been initialized.\n");
    countSum = SumOfNode(T);
    printf("The number of node with degree 1:%d\n", countSum);
    return 0;
}