#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

LinkList CreateList(LinkList L, int n) {  //头插法
    int i;
    LinkList p;

    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    for (i = n; i > 0; --i) {
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
    return L;
}

void Show(LinkList L) {
    for (L = L->next; L; L = L->next)
        printf("%d     ", L->data);
    printf("\n");
}

void InsertSort(LinkList L) {
    LinkList head, tail, p, pre, after;

    head = tail = L->next;
    while (p = tail->next)
        if (p->data < head->data) {       //插入位置为链表头部
            tail->next = p->next;
            p->next = head;
            head = p;
        } else if (p->data > tail->data)  //插入位置为链表尾部
            tail = p;
        else {                            //插入位置为链表中间
            tail->next = p->next;
            pre = head;
            while (after = pre->next)
                if (p->data < after->data) {
                    pre->next = p;
                    p->next = after;
                    break;
                } else
                    pre = after;
        }
    L->next = head;
}

void SelectSort(LinkList L) {
    LinkList prep1=L, p1, prep2, p2, premin, min, temp;

    for (p1 = prep1->next; p1; prep1 = prep1->next, p1 = prep1->next) {
        premin = prep1;
        prep2 = min = p1;
        for (p2 = prep2->next; p2; prep2 = prep2->next, p2 = prep2->next)
            if (min->data > p2->data) {
                premin = prep2;
                min = p2;
            }
        if (p1 != min) {
            temp = min->next;
            prep1->next = min;
            if(p1->next == min) {
                min->next = p1;
                p1->next = temp;
            } else {
                min->next = p1->next;
                premin->next = p1;
                p1->next = temp;
            }
        }
    }
}

int main() {
    LinkList  M, N;

    M = CreateList(M, 6);
    printf("Original:");
    Show(M);
    InsertSort(M);                        //对单链表M进行直接插入排序
    printf("Sorted:");
    Show(M);
    N = CreateList(N, 5);
    printf("Original:");
    Show(N);
    SelectSort(N);                        //对单链表N进行直接选择排序
    printf("Sorted:");
    Show(N);
    return 0;
}