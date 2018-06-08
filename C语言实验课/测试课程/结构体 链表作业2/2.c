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
void sort(Student *p, int n);
void output(Student *p, int n);

main()
{
    Student *p;
    int n;

    scanf("%d", &n);
    p = (Student *) calloc(n, sizeof(Student));
    initial(p, n);
    sort(p, n);
    output(p, n);
}

void initial(Student *p, int n)
{
    int i;

    for (i = 0; i < n; ++i)
        scanf("%d %s %d %d %d", &p[i].sno, p[i].sname, &p[i].sco[0], &p[i].sco[1], &p[i].sco[2]);
}

void sort(Student *p, int n)
{
    Student t;
    int i, j, sum1, sum2;

    for (i = 0; i < n - 1; ++i)
        for (j = 0; j < n - i - 1; ++j) {
            sum1 = p[j].sco[0] + p[j].sco[1] + p[j].sco[2];
            sum2 = p[j + 1].sco[0] + p[j + 1].sco[1] + p[j + 1].sco[2];
            if (sum1 < sum2)
                t = p[j], p[j] = p[j + 1], p[j + 1] = t;
        }
}

void output(Student *p, int n)
{
    int i;

    for (i = 0; i < n; ++i) {
        printf("%d %s %d %d %d ", p[i].sno, p[i].sname, p[i].sco[0], p[i].sco[1], p[i].sco[2]);
        printf("%d\n", p[i].sco[0] + p[i].sco[1] + p[i].sco[2]);
    }
}