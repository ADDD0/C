/* 编写一个程序,用以读入一个C语言程序,并按字母表顺序分组打印
变量名,要求每一组内各变量名的前6个字符相同,其余字符不同.字符
串和注释中的单词不予考虑,请将6作为一个可在命令行中设定的参数  */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define  MAXWORD 100
#define  YES 1
#define  NO  0

struct tnode {            /* the tree node                    */
    char *word;           /* points to the text               */
    int match;            /* match found                      */
    struct tnode *left;   /* left child                       */
    struct tnode *right;  /* right child                      */
};

struct tnode *addtreex(struct tnode *, char *, int, int *);
void treexprint(struct tnode *);
int getword(char *, int);

/* print in alphabetic order each group of variable names     */
/* identical in the first num characters (default 6)          */
main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];
    int found = NO;       /* YES if match was found           */
    int num;              /* number of the first ident. chars */

    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtreex(root, word, num, &found);
        found = NO;
    }
    treexprint(root);
    return 0;
}

struct tnode *talloc(void);
int compare(char *, struct tnode *, int, int *);

/* addtreex: add a node with w, at or below p                 */
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
    int cond;

    if (p == NULL) {      /* a new word has arrived           */
        p = talloc();     /* make a new node                  */
        p->word = strdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    } else if ((cond = compare(w, p, num, found)) < 0)
        p->left = addtreex(p->left, w, num, found);
    else if (cond > 0)
        p->right = addtreex(p->right, w, num, found);
    return p;
}

/* compare: compare words and update p->match                 */
int compare(char *s, struct tnode *p, int num, int *found)
{
    int i;
    char *t = p->word;

    for (i = 0; *s == *t; i++, s++, t++)
        if (*s == '\0')
            return 0;
    if (i >= num) {       /* identical in first num chars ?   */
        *found = YES;
        p->match = YES;
    }
    return *s - *t;
}

/* treexprint: in-order print of tree p if p->match == YES    */
void treexprint(struct tnode *p)
{
    if (p != NULL) {
        treexprint(p->left);
        if (p->match)
            printf("%s\n", p->word);
        treexprint(p->right);
    }
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}