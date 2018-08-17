#include <stdio.h>
#include <string.h>

#define  MAXLINES  5000   /* 待排序的最大行数                */
char *lineptr[MAXLINES];  /* 指向文本行的指针                */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines );

void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(char *, char *);

/* 对输入的文本行进行排序                                    */
main(int argc, char *argv[])
{
    int nlines;           /* 读入的输入行数                  */
    int numeric = 0;      /* 若进行数值排序,则numeric的值为1 */

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0 ) {
        qsort((void **) lineptr, 0, nlines - 1,
              (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}