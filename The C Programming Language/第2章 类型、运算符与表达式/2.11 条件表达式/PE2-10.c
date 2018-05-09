/* 重新编写将大写字母转换为小写字母的函数lower
并用条件表达式替代其中的if-else结构            */
/* lower函数:将c转换成小写(仅支持ASCII)        */
int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}