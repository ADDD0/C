/* 编写一个函数excape(s,t),将字符串t复制到字符串s中,并在复制过程中将换行符,
制表符等不可见字符分别转换为\n,\t等相应的可见的转义字符序列,要求使用switch语句
再编写一个具有相反功能的函数,在复制过程中将转义字符序列转换为实际字符          */
/* escape函数:将换行符和制表符转义为可视序列                                   */
/* 在复制字符串t到s的同时                                                      */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
        switch (t[i]) {
            case '\n':  /* 换行符                                              */
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':  /* 制表符                                              */
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:    /* 所有其他字符                                        */
                s[j++] = t[i];
                break;
        }
    s[j] = '\0';
}