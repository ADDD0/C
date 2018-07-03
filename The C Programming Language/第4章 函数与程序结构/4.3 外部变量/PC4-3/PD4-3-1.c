/* 在有了基本框架后,对计算器程序进行扩充就比较简单了
在该程序中加入取模(%)运算符,并注意考虑负数的情况            */
#include <stdio.h>
#include <math.h>    /* for atof()                          */

#define  MAXOP  100  /* max size of operand or operator     */
#define  NUMBER '0'  /* signal that a number was found      */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator                                */
main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}