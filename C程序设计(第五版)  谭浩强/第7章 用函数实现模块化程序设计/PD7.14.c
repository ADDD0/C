/* 输入10个学生5门课的成绩,分别用函数实现下列功能:
① 计算每个学生的平均分
② 计算每门课的平均分
③ 找出所有50个分数中最高的分数所对应的学生和课程
④ 计算平均分方差:
σ=ΣXi²/n-(ΣXi/n)²
其中,Xi为某一学生的平均分 */
#include <stdio.h>

main()
{
    float average_student(float a[5]);
    float average_subject(float a[10]);
    float variance(float a[10][5]);

    float st[10][5];
    float su[5][10];
    int i, j, row;
    float max = 0;

    for (i = 0; i < 10; ++i) {
        printf("student %d's score:", i + 1);
        scanf("%f %f %f %f %f", &st[i][0], &st[i][1], &st[i][2], &st[i][3], &st[i][4]);
    }
    printf("\n");
    for (i = 0; i < 10; ++i) {
        printf("student %d's average score:%f\n", i + 1, average_student(st[i]));
        for (j = 0; j < 5; ++j) {
            su[j][i] = st[i][j];
            if (st[i][j] > max) {
                max = st[i][j];
                row = i;
            }
        }
    }
    printf("\n");
    for (i = 0; i < 5; ++i)
        printf("subject %d's average score:%f\n", i + 1, average_subject(su[i]));
    printf("\n");
    printf("highest score:%f\nstudent %d:%.2f %.2f %.2f %.2f %.2f\n",
    max, row + 1, st[row][0], st[row][1], st[row][2], st[row][3], st[row][4]);
    printf("\n");
    printf("variance is:%f\n", variance(st));
}

float average_student(float a[5])
{
    int i;
    float sum = 0.0;

    for (i = 0; i < 5; ++i)
        sum += a[i];
    return (sum / 5);
}

float average_subject(float a[10])
{
    int i;
    float sum = 0.0;

    for (i = 0; i < 10; ++i)
        sum += a[i];
    return (sum / 10);
}

float variance(float a[10][5])
{
    int i;
    float sum1 = 0.0;
    float sum2 = 0.0;

    for (i = 0; i < 10; ++i) {
        sum1 += average_student(a[i]) * average_student(a[i]);
        sum2 += average_student(a[i]);
    }
    return (sum1 / 10 - (sum2 / 10) * (sum2 / 10));
}