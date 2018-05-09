/* 编写一个函数excape(s,t),将字符串t复制到字符串s中,并在复制过程中将换行符,
制表符等不可见字符分别转换为\n,\t等相应的可见的转义字符序列,要求使用switch语句
再编写一个具有相反功能的函数,在复制过程中将转义字符序列转换为实际字符          */
/* unescape函数:将转义字符序列转换为实际字符                                   */
/* 在复制字符串t到s的同时                                                      */
void unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
        switch (t[i]) {
        case '\\':         /* 反斜杠                                           */
            switch (t[++i]) {
                case 'n':  /* 实际换行符                                       */
                    s[j++] = '\n';
                    break;
                case 't':  /* 实际制表符                                       */
                    s[j++] = '\t';
                    break;
                default:   /* 所有其他字符                                     */
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
                }
                break;
        default:           /* 不是一个反斜杠                                   */
            s[j++] = t[i];
            break;
        }
    s[j] = '\0';
}