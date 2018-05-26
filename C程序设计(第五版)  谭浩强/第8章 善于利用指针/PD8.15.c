/* 有一个班4个学生,5门课程
①求第1门课程的平均分
②找出有两门以上课程不及格的学生,输出他们的学号和全部课程成绩及平均成绩
③找出平均成绩在90分以上或全部课程成绩在85分以上的学生
分别编3个函数实现以上3个要求                                            */
#include <stdio.h>

main()
{
    void input(float *p[5]);
    float f1(float *p[5]);
    void f2(float *p[5]);
    void f3(float *p[5]);

    float a[4][5];

    input(a);
    printf("Average score of the first course:%.2f\n", f1(a));
    f2(a);
    f3(a);
}

void input(float *p[5])
{
    int i, j;

    for (i = 0; i < 4; ++i)
        for (j = 0; j < 5; ++j)
            scanf("%f", *(p + i) + j);
}

float f1(float *p[5])
{
    float sum;
    int i;

    for (i = 0; i < 4; ++i)
        sum += **(p + i);
    return sum / 4;
}

void f2(float *p[5])
{
    void print(float *p, int n);

    int i, j, fail;

    printf("\nRequest two:");
    for (i = fail = 0; i < 4; ++i, fail = 0)
        for (j = 0; j < 5; ++j)
            if (*(*(p + i) + j) < 60)
                ++fail;
            if (++fail == 2)
                print(p + i, i);
}

void f3(float *p[5])
{
    float aver(float *p);
    void print(float *p, int n);

    int i, j;

    printf("\nRequest three:");
    for (i = 0; i < 4; ++i)
        if (aver(p + i) > 90)
            print(p + i, i);
        else {
            for (j = 0; j < 5; ++j)
                if (*(*(p + i) + j) <= 85)
                    break;
            print(p + i, i);
        }
}

void print(float *p, int n)
{
    int i;

    printf("Student %d:", n);
    for (i = 0; i < 5; ++i)
        printf("%.2f  ", *(p + i));
    printf("\n");
}

float aver(float *p)
{
    float sum;
    int i;

    for (i = 0; i < 4; ++i)
        sum += *(p + i);
    return sum / 5;
}