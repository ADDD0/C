#include <stdio.h>
#include "file.h"
#include "stu.h"

void read(char filename[])
{
    FILE *fp;
    Student *pre, *p;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\n--The specified file was not found\n");
        printf("--Create a new file to save the data\n");
        creat();
        return;
    }

    printf("\n--Found file");
    printf("--The linked list has been loaded\n");
    pre = h;
    while (!feof(fp)) {
        p = talloc();
        fscanf(fp, "%d %s %d", &p->sno, p->sname, &p->term);
        for (i = 0; i < COURSE; ++i)
            fscanf(fp, "%f", p->sco + i);
        fscanf(fp, "%f %d ", &p->aver, &p->rank);
        pre -> next = p;
        pre = p;
    }
    pre -> next = NULL;
}

void creat()
{
    Student *pre, *p;
    float *s;

    pre = h;
    printf("\n--Note: This operation will eliminate the previous list\n");
    /* 创建后会删除原先的链表 */
    printf("--(Stop when the student's ID is 0)\n");
    printf("Data input:\n");
    printf("--format: %%d   %%s    %%d   %%f*3\n");
    printf("--       (ID)(name)(term)(score)\n");
    p = talloc();
    scanf("%d", &p->sno);
    while (p->sno) {
        scanf("%s %d", p->sname, &p->term);
        p->aver = 0.0;
        for (s = p->sco; s < p->sco + COURSE; ++s) {
            scanf("%f", s);
            p->aver += *s;
        }
        p->aver /= COURSE;
        pre->next = p;
        pre = p;
        p = talloc();
        scanf("%d", &p->sno);
    }
    getchar();
    pre->next = NULL;
    printf("\n--Data input completed\n");

    sort();
    printf("--The linked list has been initialized\n");
}

void sort()
{
    Student *pt, *p;
    int count = 0;

    if (h->next)
        p = h;
    else {
        printf("--No data, input data again\n");
        creat();
    }
    while (p = p->next) {
        p->rank = 0;
        ++count;
    }
    while (count > 1) {
        pt = h->next;
        while (pt->rank != 0)
            pt = pt->next;
        p = pt;
        while (p = p->next)
            if (p->aver < pt->aver && p->rank == 0)
                pt = p;
        pt->rank = count;
        --count;
    }
    p = h->next;
    while (p->rank)
        p = p->next;
    p->rank = 1;
}

void save(char filename[])
{
    FILE *fp;
    Student *p = h;
    float *s;

    fp = fopen(filename, "w");
    while (p = p->next) {
        fprintf(fp, "%d %s %d ", p->sno, p->sname, p->term);
        for (s = p->sco; s < p->sco + COURSE; ++s)
            fprintf(fp, "%f ", *s);
        fprintf(fp, "%f %d\n", p->aver, p->rank);
    }
    fclose(fp);
    putchar(10);
}