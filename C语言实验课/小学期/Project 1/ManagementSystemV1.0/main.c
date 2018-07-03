#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stu.h"
#include "file.h"
#include "edit.h"
#include "search.h"

Student *talloc()
{
    return (Student *) malloc(sizeof(Student));
}

main()
{
    void printlist();


    char filename[20];
    int choice;

    h = talloc();
    printf("Please enter the file's name you want to operate:");
    gets(filename);
    if (strstr(filename, ".txt") == NULL)
        strcat(filename, ".txt");
    /* 如果输入的文件名不带扩展名,就在文件名末尾加上.txt */
    read(filename);
    while (1) {
        printf("0: Exit\n");
        printf("1: Edit information\n");
        printf("2: Search information\n");
        printf("3: Save information\n");
        printf("4: Print current information\n");
        printf("Your choice is:");
        scanf("%d", &choice);
        switch (choice) {
            case 0: return;
            case 1: edit(); break;
            case 2: search(); break;
            case 3: save(filename); break;
            case 4: printlist(); break;
            default : printf("Invalid command code\n\n");
        }
    }
}

void printlist()
{
    Student *p;
    float *s;

    p = h->next;
    if (!p)  /* 链表为空时    */
        printf("--Nodelist is not initialized or has been deleted\n");
    while (p) {
        printf("No.%d %s %d:", p->sno, p->sname, p->term);
        for (s = p->sco;  s < p->sco + 3; ++s)
            printf("  %f", *s);
        printf("  %f %d", p->aver, p->rank);
        printf("\n");
        p = p->next;
    }
    printf("\n");
}