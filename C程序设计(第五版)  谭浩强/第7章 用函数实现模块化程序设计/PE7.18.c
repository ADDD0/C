/* 给出年,月,日,计算该日是该年的第几天 */
#include <stdio.h>

main()
{
    int day(int d[3]);

    int a[3];

    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    printf("year:%d days:%d\n", a[0], day(a));
}

int day(int d[3])
{
    int month(int m[2]);

    int m[2];

    m[0] = d[0];
    m[1] = d[1];
    return month(m) + d[2];
}

int month(int m[2])
{
    int year(int y);

    int days = 0;

    switch (m[1] - 1)
    {
        case 12: days += 31;
        case 11: days += 30;
        case 10: days += 31;
        case 9: days += 30;
        case 8: days += 31;
        case 7: days += 31;
        case 6: days += 30;
        case 5: days += 31;
        case 4: days += 30;
        case 3: days += 31;
        case 2:
            if (year(m[0]))
                days += 29;
            else
                days += 28;
        case 1: days += 31;
    }
    return days;
}

int year(int y)
{
    if (y % 400 == 0 || y % 4 == 0 && y % 100)
        return 1;
    else
        return 0;
}