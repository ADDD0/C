/* 对atof函数进行扩充,使它可以处理形如123.45e-6的科学表示法
其中,浮点数后面可能会紧跟一个e或E以及一个指数(可能有正负号) */
#include <stdio.h>
#include <ctype.h>

main()
{
    double atof(char s[]);
    char s[128];

    gets(s);
    printf("%g\n", atof(s));
}

/* atof: convert string s to double                         */
double atof(char s[])
{
    double val, power;
    int exp, i, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space    */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        sign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        if (sign == 1)
            while (exp-- > 0)        /* positive exponent   */
                val *= 10;
        else
            while (exp-- > 0)        /* negative exponent   */
                val /= 10;
    }
    return val;
}