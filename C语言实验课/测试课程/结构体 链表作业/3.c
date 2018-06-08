#include <stdio.h>

typedef struct date
{
    int year, month, day;
} Date;

main()
{
    int day(Date);
    Date date;

    scanf("%d-%d-%d", &date.year, &date.month, &date.day);
    printf("%d\n", day(date));
}

int day(Date p)
{
    int month(Date);

    return month(p) + p.day;
}

int month(Date p)
{
    int year(Date);

    int days = 0;

    switch (p.month - 1)
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
            if (year(p))
                days += 29;
            else
                days += 28;
        case 1: days += 31;
    }
    return days;
}

int year(Date p)
{
    if (p.year % 400 == 0 || p.year % 4 == 0 && p.year % 100)
        return 1;
    else
        return 0;
}