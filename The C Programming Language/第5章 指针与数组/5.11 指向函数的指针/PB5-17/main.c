/* 增加字段处理功能,以使得排序程序可以根据行内的不同字段进行排序
每个字段按照一个单独的选项集合进行排序(在对本书索引进行排序时
索引条目使用了-df选项,而对页码排序时使用了-n选项)                */
#include <stdio.h>
#include <ctype.h>

#define  NUMERIC 1         /* numeric sort                       */
#define  DECR    2         /* sort in decreasing order           */
#define  FOLD    4         /* fold upper and lower cases         */
#define  DIR     8         /* directory order                    */
#define  LINES   100       /* max # of lines to be sorted        */

int charcmp(char *, char *);
void error(char *);
int numcmp(char *, char *);
void readargs(int argc, char *argv[]);
int readlines(char *lineptr[], int maxlines);
void qsort(char *v[], int left, int right,
           int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int order);

char option = 0;
int pos1 = 0;              /* field beginning with pos1          */
int pos2 = 0;              /* ending just before pos2            */

/* sort input lines                                              */
main(int argc, char *argv[])
{
    char *lineptr[LINES];  /* pointers to text lines             */
    int nlines;            /* number of input lines read         */
    int rc = 0;

    readargs(argc, argv);
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

/* readargs: read program arguments                              */
void readargs(int argc, char *argv[])
{
    int c;
    int atoi(char *);

    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+') {
        if (c == '-' && !isdigit(*(argv[0] + 1)))
            while (c = *++argv[0])
                switch (c) {
                case 'd':  /* directory order                    */
                    option |= DIR;
                    break;
                case 'f':  /* fold upper and lower cases         */
                    option |= FOLD;
                    break;
                case 'n':  /* numeric sort                       */
                    option |= NUMERIC;
                    break;
                case 'r':  /* sort in decreasing order           */
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    error("Usage: sort -dfnr [+pos1] [-pos2]");
                    break;
                }
        else if (c == '-')
            pos2 = atoi(argv[0] + 1);
        else if ((pos1 = atoi(argv[0] + 1)) < 0)
            error("Usage: sort -dfnr [+pos1] [-pos2]");
    }
    if (argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");

}

void error(char *s)
{
    printf("%s\n", s);
    exit(1);
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