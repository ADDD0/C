/* 在栈操作中添加几个命令,分别用于在不弹出元素情况下打印栈顶元素;
复制栈顶元素;交换栈顶两个元素的值.另外增加一个命令用于清空栈      */
#include <stdio.h>
#include <math.h>      /* 为了使用atof()函数                      */

#define  MAXOP  100    /* 操作数或运算符的最大长度                */
#define  NUMBER '0'    /* 标识找到一个数                          */

int getop(char []);
void push(double);
double pop(void);
void clear(void);

/* 逆波兰计算器                                                   */
main()
{
    int type;
    double op1, op2;
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
            case '?':  /* 打印栈顶元素                            */
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'c':  /* 清空栈                                  */
                clear();
                break;
            case 'd':  /* 复制栈顶元素                            */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':  /* 交换栈顶两个元素的值                    */
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
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

