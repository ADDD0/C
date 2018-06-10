/* 给计算器程序增加访问sin,exp与pow等库函数的操作
有关这些库函数的详细信息,请参见附录B.4节中的头文件<math.h> */
#include <stdio.h>
#include <math.h>      /* 为了使用atof()函数               */

#define  MAXOP  100    /* 操作数或运算符的最大长度         */
#define  NUMBER '0'    /* 标识找到一个数                   */
#define  NAME   'n'    /* 标识找到一个(函数)名称           */

int getop(char []);
void push(double);
double pop(void);
void mathfnc(char []);

/* 逆波兰计算器                                            */
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
            case NAME:
                mathfnc(s);
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
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("errod: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* mathfuc函数:检查可支持字符串s的数学函数                 */
void mathfnc(char [])
{
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: %s not supported\n", s);
}