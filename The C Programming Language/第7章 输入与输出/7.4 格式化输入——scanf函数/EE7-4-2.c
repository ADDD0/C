#include <stdio.h>

main()
{
    int day, month, year, getline(char *, int);
    char monthname[20], line[100];

    while (getline(line, sizeof(line)) > 0)
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line);    /* 25 Dec 1988形式的日期数据 */
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line);    /* mm/dd/yy形式的日期数据    */
        else
            printf("invalid: %s\n", line);  /* 日期形式无效              */
}

int getline(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}