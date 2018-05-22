/*编写程序:从键盘上输入10名学生的姓名及三科考试成绩
从中找出成绩最高和成绩最低的学生的信息并输出

具体要求:
①使用结构体数组实现
②在main函数中输入学生的信息,输出结果
③查找最高和最低成绩的功能由用户自定义函数实现

例如:
#include "stdio.h"
#define N 10
struct stu                          struct stu f_max(struct stu *p)
{                                   {
    char sno[6];                        查找成绩最高的学生;
    char sname[10];                 }
    int sco[3];
}
void main()                         struct stu f_min(struct stu *p)
{                                   {
    struct stu s[N],s1,s2;              查找成绩最低的学生;
    输入N个学生的信息;              }
    s1=f_max(s);
    s2=f_min(s);??这两句是想实现什么??
    输出s1,s2;
}                                                                   */
#include <stdio.h>

#define  N  3

main()
{
    struct stu
    {
        char sno[6];
        char sname[10];
        int sco[3];
    };

    struct stu f_max(struct stu *p);
    struct stu f_min(struct stu *p);

    struct stu s[N], s1, s2, *p;
    int *q;

    for (p = s; p < s + N; ++p) {
        scanf("%s %s", p -> sno, p -> sname);
        for (q = p -> sco; q < p -> sco + 3; ++q)
            scanf("%d", q);
    }

    s1 = f_max(s);
    s2 = f_min(s);
    printf("max:%-6s  %-10s", s1.sno, s1.sname);
    for (q = s1.sco; q < s1.sco + 3; ++q)
        printf("  %d", *q);
    printf("min:%-6s  %-10s", s2.sno, s2.sname);
    for (q = s2.sco; q < s2.sco + 3; ++q)
        printf("  %d", *q);
}

struct stu f_max(struct stu *p)
{
    struct stu smax;
    int i, sum, max, *s;

    max = 0;
    for (i = sum = 0; i < 3; ++i, ++p) {
        for (s = p -> sco; s < p -> sco + 3; ++s)
            sum += *s;
        if (sum > max)
            smax = *p;
    }
    return smax;
}

struct stu f_min(struct stu *p)
{
    struct stu smin;
    int i, sum, min, *s;

    q = p;
    min = 0;
    for (i = sum = 0; i < 3; ++i, ++p) {
        for (s = p -> sco; s < p -> sco + 3; ++s)
            sum += *s;
        if (sum < min) {
            smin = *p;
        }
    }
    return smin;
}