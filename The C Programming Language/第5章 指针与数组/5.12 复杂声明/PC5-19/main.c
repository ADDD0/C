/* 修改undcl程序,使它在把
文字描述转换为声明的过程中不会生成多余的圆括号    */
#include <stdio.h>
#include <string.h>

#define  MAXTOKEN  100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int gettoken(void);
int nexttoken(void);

int tokentype;         /* type of last token      */
char token[MAXTOKEN];  /* last token string       */
char out[1000];

/* undcl: convert word description to declaration */
main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                if ((type = nexttoken()) == PARENS ||
                    type == BRACKETS)
                    sprintf(temp, "(*%s)", out);
                else
                    sprintf(temp, "*%s", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
        printf("%s\n", out);
    }
    return 0;
}