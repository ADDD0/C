/* 修改第5章的模式查找程序,使它从一个命名文件的集合中读取
输入(有文件名参数时),如果没有文件名参数,则从标准输入中读取
输入.当发现一个匹配行时,是否应该将相应的文件名打印出来?    */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  MAXLINE 1000       /* maximum input line length   */

/* find: print lines that match pattern from 1st argument  */
main(int argc, char *argv[])
{
    char pattern[MAXLINE];
    int c, except = 0, number = 0;
    FILE *fp;
    void fpat(FILE *fp, char *fname, char *pattern,
              int except, int number);

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    break;
            }
    if (argc >= 1)
        strcpy(pattern, *argv);
    else {
        printf("Usage: find [-x] [-n] pattern [file ...]\n");
        exit(1);
    }
    if (argc == 1)          /* read standard input         */
        fpat(stdin, "", pattern, except, number);
    else
        while (--argc > 0)  /* get a named file            */
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "find: can't open %s\n", *argv);
                exit(1);
            } else {        /* named file has been opened  */
                fpat(fp, *argv, pattern, except, number);
                fclose(fp);
            }
    return 0;
}

/* fpat: find pattern                                      */
void fpat(FILE *fp, char *fname, char *pattern,
          int except, int number)
{
    char line[MAXLINE];
    long lineno = 0;

    while (fgets(line, MAXLINE, fp) != NULL) {
        ++lineno;
        if ((strstr(line, pattern) != NULL) != except) {
            if (*fname)     /* have a file name            */
                printf("%s - ", fname);
            if (number)     /* print line number           */
                printf("%ld: ", lineno);
            printf("%s", line);
        }
    }
}