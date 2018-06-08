#include<stdio.h>

typedef struct complex
{
    float repart, impart;
} Complex;

Complex add(Complex a,Complex b);
Complex substract(Complex a,Complex b);

main()
{
    Complex a,b,c;
    char op;

    scanf("(%f%fi)%c(%f%fi)",
    &a.repart, &a.impart, &op, &b.repart, &b.impart);
    if (op == '+')
        c = add(a, b);
    else if (op == '-')
        c = substract(a, b);
    printf("%.2f%+.2fi\n", c.repart, c.impart);//输出格式符后面有+号表示输出数时要带正负号
}

Complex add(Complex a, Complex b)
{
    Complex c;

    c.repart = a.repart + b.repart;
    c.impart = a.impart + b.impart;
    return c;
}

Complex substract(Complex a, Complex b)
{
    Complex c;

    c.repart = a.repart - b.repart;
    c.impart = a.impart - b.impart;
    return c;
}