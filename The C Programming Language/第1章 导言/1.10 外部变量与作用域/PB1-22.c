/* 编写一个程序,把较长的输入行“折”成短一些的两行或多行
,折行的位置在输入行的第n列之前的最后一个非空格之后     */
#include <stdio.h>

#define  MAXCOL  10       /* 输入行最大列数            */
#define  TABINC  8        /* 制表符增量                */

char line[MAXCOL];        /* 输入行                    */

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

/* 将较长输入行折叠成两个或更多短一些的行              */
main()
{
    int c, pos;

    pos = 0;              /* 行列中的位置              */
    while ((c = getchar()) != EOF) {
        line[pos] = c;    /* 存储当前字符              */
        if (c == '\t')    /* 扩展制表符                */
            pos = exptab(pos);
        else if (c == '\n') {
            printl(pos);  /* 打印当前输入行            */
            pos = 0;
        } else if (++pos >= MAXCOL) {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}

/* printl:打印此行直到pos列                            */
void printl(int pos)
{
    int i;
    for (i = 0; i < pos; ++i)
        putchar(line[i]);
    if (pos > 0)          /* 有字符串被打印            */
        putchar('\n');
}

/* exptab:将制表符扩展成空格                           */
int exptab(int pos)
{
    line[pos] = ' ';      /* 制表符至少占一个空格      */
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
        line[pos] = ' ';
    if (pos < MAXCOL)     /* 当前行剩余空间            */
        return pos;
    else {                /* 当前行已满                */
        printl(pos);
        return 0;         /* 重置当前行位置            */
    }
}

/* findblnk:找到空格位置                               */
int findblnk(int pos)
{
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)         /* 行列中没有空格            */
        return MAXCOL;
    else                  /* 至少一个空格              */
        return pos+1;     /* 空格后的位置              */
}

/* newpos:用新的位置重排此行                           */
int newpos(int pos)
{
    int i, j;

    if (pos <= 0 || pos >= MAXCOL)
        return 0;         /* 无需重排                  */
    else {
        i = 0;
        for (j = pos; j < MAXCOL; ++j) {
            line[i] = line[j];
            ++i;
        }
        return i;         /* 行列的新位置              */
    }
}