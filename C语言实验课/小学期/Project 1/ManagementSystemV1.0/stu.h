#ifndef STU_H
#define STU_H

#define COURSE 3  /* 科目数量 */

typedef struct node
{
    int sno;
    char sname[10];
    int term;
    float sco[COURSE];
    float aver;
    int rank;
    struct node *next;
} Student;

Student *talloc(void);

Student *h;

#endif