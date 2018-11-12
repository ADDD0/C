#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree CreateBitree(BiTree T) {
	int ch;
	
	if ((ch = getchar()) == '#')
		T = NULL;
	else {
		if (!(T = (BiTNode*) malloc(sizeof(BiTNode))))
			exit(0);
		T->data = ch;
		T->lchild = CreateBitree(T->lchild);
	}
	return T;
}

int preorder(BiTree T) {
	
}

int main() {
	BiTree T;
	
	T = CreateBitree(T);
	printf("The preOrder of T is:\n");
	preorder(T);
	return 0;
}