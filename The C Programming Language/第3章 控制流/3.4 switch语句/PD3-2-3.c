/* 编写一个函数excape(s,t),将字符串t复制到字符串s中,并在复制过程中将换行符,
制表符等不可见字符分别转换为\n,\t等相应的可见的转义字符序列,要求使用switch语句
再编写一个具有相反功能的函数,在复制过程中将转义字符序列转换为实际字符          */
#include <stdio.h>

main()
{
    void unescape(char s[], char t[]);
    char s[128], t[128];

    gets(t);
    unescape(s, t);
    puts(s);
}

/* unescape: convert escape sequences into real characters
    while copying the string t to s                                            */
void unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
        switch (t[i]) {
            case '\\':         /* backslash                                    */
                switch (t[++i]) {
                    case 'n':  /* real newline                                 */
                        s[j++] = '\n';
                        break;
                    case 't':  /* real tab                                     */
                        s[j++] = '\t';
                        break;
                    default:   /* all other chars                              */
                        s[j++] = '\\';
                        s[j++] = t[i];
                        break;
                    }
                break;
            default:           /* not a backslash                              */
                s[j++] = t[i];
                break;
        }
    s[j] = '\0';
}