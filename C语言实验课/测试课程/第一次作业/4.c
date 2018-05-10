#include "stdio.h"

int main()
{
    int isleap(int year);
    int year, month, days;

    scanf("%d / %d", &year, &month);
    switch (month) {
        case 4: case 6: case 9: case 11: days = 30; break;
        case 2:
            if (isleap(year))
                days = 29;
            else
                days = 28;
            break;
        default: days = 31; break;
    }
    printf("%d\n", days);
    return 0;
}

int isleap(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100))
        return 1;
    else
        return 0;
}
