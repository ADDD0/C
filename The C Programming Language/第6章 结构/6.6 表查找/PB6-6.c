/* 以本节介绍的函数为基础,编写一个适合C语言程序使用的#define处理器的
简单版本(即无参数的情况).你会发现getch和ungetch函数非常有用  */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define  MAXWORD  100
#define  HASHSIZE 101

struct nlist {                    /* table entry:            */
    struct nlist *next;           /* next entry in the chain */
    char *name;                   /* defined name            */
    char *defn;                   /* replacement text        */
};

static struct nlist *hashtab[HASHSIZE];

int getword(char *, int);
void getdef(void);

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);

void ungets(char *);
void skipblanks(void);
void undef(char *);
void error(int, char *);

/* simple version of #define processor                       */
main()
{
    char w[MAXWORD];
    struct nlist *p;

    while (getword(w, MAXWORD) != EOF)
        if (strcmp(w, "#") == 0)  /* beginning of direct.    */
            getdef();
        else if (!isalpha(w[0]))
            printf("%s", w);      /* cannot be defined       */
        else if ((p = lookup(w)) == NULL)
            printf("%s", w);      /* not defined             */
        else
            ungets(p->defn);      /* push definition         */
    return 0;
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()) && c != '\n')
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

void ungets(char *s)
{
    int len = strlen(s);

    while (len > 0)
        ungetch(s[--len]);
}

/* getdef: get definition and install it                     */
void getdef(void)
{
    int i;
    char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

    skipblanks();
    if (!isalpha(getword(dir, MAXWORD)))
        error(dir[0], "getdef: expecting a directive after #");
    else if (strcmp(dir, "define") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD)))
            error(name[0], "getdef: non-alpha - name expected");
        else {
            skipblanks();
            for (i = 0; i < MAXWORD - 1; i++)
                if ((def[i] = getch()) == EOF || def[i] == '\n')
                    break;  /* end of definition             */
            def[i] = '\0';
            if (i <= 0)     /* no defination ?               */
                error('\n', "getdef: incomplete define");
            else            /* install defination            */
                install(name, def);
        }
    } else if (strcmp(dir, "undef") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD)))
            error(name[0], "getdef: non-alpha in undef");
        else
            undef(name);
    } else
        error(dir[0], "getdef: expecting a directive after #");
}

/* hash函数: 为字符串s生成散列值                             */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* install函数: 将(name, defn)加入到hashtab中                */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {  /* 未找到            */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else                              /* 已存在            */
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/* lookup函数: 在hashtab中查找s                              */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;      /* 找到s                         */
    return NULL;            /* 未找到s                       */
}

/* undef: remove a name and defination from the table        */
void undef(char *s)
{
    int h;
    struct nlist *prev, *np;

    prev = NULL;
    h = hash(s);            /* hash value of string s        */
    for (np = hashtab[h]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            break;
        prev = np;          /* remember previous entry       */
    }
    if (np != NULL) {       /* found name                    */
        if (prev == NULL)   /* first in the hash list ?      */
            hashtab[h] = np->next;
        else                /* elsewhere in the hash list    */
            prev->next = np->next;
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);  /* free allocated structure      */
    }
}

/* error: print error message and skip the rest of the line  */
void error(int c, char *s)
{
    printf("error: %s\n", s);
    while (c != EOF && c != '\n')
        c = getch();
}

/* skipblanks: skip blank and tab characters                 */
void skipblanks(void)
{
    int c;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    ungetch(c);
}