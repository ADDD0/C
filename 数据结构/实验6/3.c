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

int DepthOfBiTree(BiTree T) {  //二叉树深度
    int depth=0;

    if (T) {
        ++depth;
        if (DepthOfBiTree(T->lchild) > DepthOfBiTree(T->rchild))
            depth += DepthOfBiTree(T->lchild);
        else
            depth += DepthOfBiTree(T->rchild);
    }
    return depth;
}

int SumOfNode(BiTree T) {      //结点总数
    int sum=0;

    if (T) {
        if (T->lchild || T->rchild)
            ++sum;
        sum += SumOfNode(T->lchild) + SumOfNode(T->rchild);
    }
    return sum;
}

int main() {
    BiTree T;

    T = CreateBiTree(T);
    printf("BiTree has been initialized.\n");
    printf("The depth of BiTree is:%d\n", DepthOfBiTree(T));
    printf("The nodes of BiTree is:%d\n", SumOfNode(T));
    return 0;
}