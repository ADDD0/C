#include <stdio.h>
#include <ctype.h>

#define  MAXWORD 100

struct tnode {            /* 树的节点                            */
    char *word;           /* 指向单词的指针                      */
    int count;            /* 单词出现的次数                      */
    struct tnode *left;   /* 左子节点                            */
    struct tnode *right;  /* 右子节点                            */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

/* 单词出现频率的统计                                            */
main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
}

struct tnode *talloc(void);
char *strdup(char *);

/* addtree函数: 在p的位置或p的下方增加一个w节点                  */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {      /* 该单词是一个新单词                  */
        p = talloc();     /* 创建一个新节点                      */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;       /* 新单词与节点中的单词匹配            */
    else if (cond < 0)    /* 如果小于该节点中的单词,则进入左子树 */
        p->left = addtree(p->left, w);
    else                  /* 如果大于该节点中的单词,则进入右子树 */
        p->right = addtree(p->right, w);
}

/* treeprint函数: 按序打印树p                                    */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
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

#include <stdlib.h>

/* talloc函数: 创建一个tnode                                     */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* 复制s到某个位置                                               */
char *strdup(char *s)
{
    char *p;

    /* 执行加1操作是为了在结尾加上字符'\0                        */
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}