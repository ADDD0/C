#include <stdio.h>
#include "search.h"
#include "file.h"
#include "stu.h"

void print(Student *p)
{
    float *s;

    printf("No.%d %s %d:", p->sno, p->sname, p->term);
    for (s = p->sco;  s < p->sco + 3; ++s)
        printf("  %.2f", *s);
    printf("  %.2f  %d\n", p->aver, p->rank);
}

void search()
{
    int choice, searchnum, searchterm;

    printf("\n--Search\n");
    printf("--0: Stop searching\n");
    printf("--1: Search in No.\n");
    printf("--2: Search in term\n");
    printf("--3: Search in failed scores\n");
    printf("Your choice is:");
    scanf("%d", &choice);
    if (!choice) {
        putchar(10);
        return;
    }
    switch (choice) {
        case 1:
            printf("Search No.:");
            scanf("%d", &searchnum);
            searchInNo(searchnum);
            break;
        case 2:
            printf("Search term:");
            scanf("%d", &searchterm);
            searchInTerm(searchterm);
            break;
        case 3:
            searchInScore();
            break;
        default : printf("Invalid command code\n");
    }
    search();  /* 递归调用 */
}

void searchInNo(int searchnum)
{
    Student *p;

    p = h->next;
    while (p) {
        if (p->sno == searchnum)
            print(p);
        p = p->next;
    }
}

void searchInTerm(int searchterm)
{
    Student *p;

    p = h->next;
    while (p) {
        if (p->term == searchterm)
            print(p);
        p = p->next;
    }
}

void searchInScore()
{
    Student *p;
    float *s;

    p = h->next;
    while (p) {
        for (s = p->sco; s < p->sco + COURSE; ++s)
            if (*s < 60) {
                print(p);
                break;
            }
        p = p->next;
    }
}