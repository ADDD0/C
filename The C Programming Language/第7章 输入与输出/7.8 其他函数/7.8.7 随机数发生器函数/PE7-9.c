/* 类似于isupper这样的函数可以通过某种方式实现以达到节省空间或时间的目的
考虑节省空间或时间的实现方式                                             */
/* isupper: return 1 (ture) if c is an upper case letter                 */
int isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

#define isupper(c)  ((c) >= 'A' && (c) <= 'Z') ? 1 : 0