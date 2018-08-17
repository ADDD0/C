/* 增加选项-d(代表目录顺序).该选项表明只对字母,数字和空格
进行比较.要保证该选项可以和-f组合在一起使用               */
#include <stdio.h>
#include <ctype.h>

#define  NUMERIC 1         /* numeric sort                */
#define  DECR    2         /* sort in decreasing order    */
#define  FOLD    4         /* fold upper and lower cases  */
#define  DIR     8         /* directory order             */
#define  LINES   100       /* max # of lines to be sorted */

int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void qsort(char *v[], int left, int right,
           int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int order);

char option = 0;

/* sort input lines                                       */
main(int argc, char *argv[])
{
    char *lineptr[LINES];  /* pointers to text lines      */
    int nlines;            /* number of input lines read  */
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
            case 'd':      /* directory order             */
                option |= DIR;
                break;
            case 'f':      /* fold upper and lower cases  */
                option |= FOLD;
                break;
            case 'n':      /* numeric sort                */
                option |= NUMERIC;
                break;
            case 'r':      /* sort in decreasing order    */
                option |= DECR;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                argc = 1;
                rc = -1;
                break;
            }
    if (argc)
        printf("Usage: sort -dfnr \n");
    else
        if ((nlines = readlines(lineptr, LINES)) > 0) {
            if (option & NUMERIC)
                qsort((void **) lineptr, 0, nlines - 1,
                     (int (*)(void *, void *)) numcmp);
            else
                qsort((void **) lineptr, 0, nlines - 1,
                     (int (*)(void *, void *)) charcmp);
            writelines(lineptr, nlines, option & DECR);
        } else {
            printf("input too big to sort \n");
            rc = -1;
        }
    return rc;
}

void writelines(char *lineptr[], int nlines, int decr)
{
    int i;

    if (decr)
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}