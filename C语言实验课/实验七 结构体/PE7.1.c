/* 编写程序:从键盘上输入10名学生的姓名及三科考试成绩
从中找出成绩最高和成绩最低的学生的信息并输出

具体要求:
①使用结构体数组实现
②在main函数中输入学生的信息,输出结果
③查找最高和最低成绩的功能由用户自定义函数实现

例如:
#include "stdio.h"
#define N 10
struct Stu                  struct Stu f_max(struct Stu *p)
{                           {
    char sno[6];                查找成绩最高的学生;
    char sname[10];         }
    int sco[3];
}
void main()                 struct Stu f_min(struct Stu *p)
{                           {
    struct Stu s[N],s1,s2;      查找成绩最低的学生;
    输入N个学生的信息;      }
    s1=f_max(s);
    s2=f_min(s);
    输出s1,s2;
}                                                           */
#include <stdio.h>

#define  N  10

struct Stu
    {
        char sno[6];
        char sname[10];
        int sco[3];
    };

main()
{
    struct Stu f_max(struct Stu *p);
    struct Stu f_min(struct Stu *p);

    struct Stu s[N], s1, s2, *p;
    int *q;

    for (p = s; p < s + N; ++p) {
        scanf("%s %s", p -> sno, p -> sname);
        for (q = p -> sco; q < p -> sco + 3; ++q)
            scanf("%d", q);
    }
    s1 = f_max(s);
    s2 = f_min(s);
    printf("max:%s  %s", s1.sno, s1.sname);
    for (q = s1.sco; q < s1.sco + 3; ++q)
        printf("  %d", *q);
    printf("\nmin:%s  %s", s2.sno, s2.sname);
    for (q = s2.sco; q < s2.sco + 3; ++q)
        printf("  %d", *q);
    printf("\n");
}

struct Stu f_max(struct Stu *p)
{
    struct Stu smax;
    int i, sum, max, *s;

    for (s = p -> sco, max = 0; s < p -> sco + 3; ++s)
        max += *s;
    smax = *p++;
    for (i = 0; i < N - 1; ++i, ++p) {
        for (s = p -> sco, sum = 0; s < p -> sco + 3; ++s)
            sum += *s;
        if (sum > max) {
            max = sum;
            smax = *p;
        }
    }
    return smax;
}

struct Stu f_min(struct Stu *p)
{
    struct Stu smin;
    int i, sum, min, *s;

    for (s = p -> sco, min = 0; s < p -> sco + 3; ++s)
        min += *s;
    smin = *p++;
    for (i = 0; i < N - 1; ++i, ++p) {
        for (s = p -> sco, sum = 0; s < p -> sco + 3; ++s)
            sum += *s;
        if (sum < min) {
            min = sum;
            smin = *p;
        }
    }
    return smin;
}