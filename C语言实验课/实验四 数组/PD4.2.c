/* �Ӽ�������һ���ַ���,���ַ�������
Ҫ��ͳ�Ƴ�������ĸ�ַ�,�����ַ��������ַ��ĸ���
����:
�Ӽ���������ַ���:abcd123a4WE$$$12***
�����������Ϊ:��ĸ=7     ����=6     ����=6   */
#include <stdio.h>
#include <ctype.h>

main()
{
    int a[128];
    int i, nl, nd, no;

    nl = nd = no = 0;
    for (i = 0; i < 128 && (a[i] = getchar()) != '\n'; ++i) {
        if (isalpha(a[i]))
            ++nl;
        else if (isdigit(a[i]))
            ++nd;
        else
            ++no;
    }
    printf("��ĸ=%d     ����=%d     ����=%d\n", nl, nd, no);
}