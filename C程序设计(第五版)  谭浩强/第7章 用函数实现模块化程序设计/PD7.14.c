/* 输入10个学生5门课的成绩,分别用函数实现下列功能:
① 计算每个学生的平均分
② 计算每门课的平均分
③ 找出所有50个分数中最高的分数所对应的学生和课程
④ 计算平均分方差:
σ=ΣXi²/n-(ΣXi/n)²
其中,Xi为某一学生的平均分                                  */
#include <stdio.h>

#define  Nop  3
#define  Nos  3

main()
{
    float average_student(float *p);
    float average_subject(float *p);
    float variance(float a[Nop][Nos]);

    float a[Nop][Nos];
    int i, j, row;
    float max = 0;

    for (i = 0; i < Nop; ++i) {
        printf("student %d's score:", i + 1);
        for (j = 0; j < Nos; ++j)
            scanf("%f", &a[i][j]);
    }
    printf("\n");
    for (i = 0; i < Nop; ++i) {
        printf("student %d's average score:%.2f\n", i + 1, average_student(a[i]));
        for (j = 0; j < Nos; ++j)
            if (a[i][j] > max) {
                max = a[i][j];
                row = i;
            }
    }
    printf("\n");
    for (i = 0; i < Nos; ++i)
        printf("subject %d's average score:%.2f\n", i + 1, average_subject(&a[0][i]));
    printf("\nhighest score:%.2f\nstudent %d:",max, row + 1);
    for (i = 0; i < Nos; ++i)
        printf("%.2f ", a[row][i]);
    printf("\n\nvariance is:%.2f\n", variance(a));
}

float average_student(float *p)
{
    int i;
    float sum = 0;

    for (i = 0; i < Nos; ++i)
        sum += *(p + i);
    return sum / Nos;
}

float average_subject(float *p)  /* 这个函数最好用指针编写 */
{
    int i;
    float sum = 0;

    for (i = 0; i < Nop; ++i)
        sum += *(p + i * Nos);
    return sum / Nop;
}

float variance(float a[Nop][Nos])
{
    int i;
    float sum1 = 0, sum2 = 0;

    for (i = 0; i < Nop; ++i) {
        sum1 += average_student(a[i]) * average_student(a[i]);
        sum2 += average_student(a[i]);
    }
    return sum1 / Nop - (sum2 / Nop) * (sum2 / Nop);
}