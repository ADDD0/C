#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu
{
    int sno;
    char sname[10];
    int sco[3];
} Student;

void initial(Student *p, int n);
void output(Student *p, int n);

main()
{
    Student *p;
    int n;

    scanf("%d", &n);
    p = (Student *) calloc(n, sizeof(Student));
    initial(p, n);
    output(p, n);
}

void initial(Student *p, int n)
{
    int i;

    for (i = 0; i < n; ++i)
        scanf("%d %s %d %d %d", &p[i].sno, p[i].sname, &p[i].sco[0], &p[i].sco[1], &p[i].sco[2]);
}

void output(Student *p, int n)
{
    int i;

    for (i = 0; i < n; ++i) {
        printf("%d %s %d %d %d ", p[i].sno, p[i].sname, p[i].sco[0], p[i].sco[1], p[i].sco[2]);
        printf("%d\n", p[i].sco[0] + p[i].sco[1] + p[i].sco[2]);
    }
}