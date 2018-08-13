/* 对程序entab和detab的功能做一些扩充,以接受下列缩写的命令:
entab -m +n 表示制表符从第m列开始,每隔n列停止
选择(对使用者而言)比较方便的默认行为                         */
#include <stdio.h>

#define  MAXLINE  100          /* maximum line size          */
#define  TABINC   8            /* default tab increment size */
#define  YES      1
#define  NO       0

void esettab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);

/* replace strings of blanks with tabs                       */
main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];

    esettab(argc, argv, tab);  /* initialize tab stops       */
    entab(tab);                /* replace blanks w/ tab      */
    return 0;
}

void entab(char *tab)
{
    int c, pos;
    int nb = 0;
    int nt = 0;

    for (pos = 1; (c = getchar()) != EOF; pos++)
        if (c == ' ') {
            if (tabpos(pos, tab) == NO)
                ++nb;
            else {
                nb = 0;
                ++nt;
            }
        } else {
            for ( ; nt > 0; nt--)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            else
                for ( ; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while (tabpos(pos, tab) != YES)
                    ++pos;
        }
}