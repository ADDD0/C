#include <stdio.h>

/* ��һ��������,Ҫ��:
   1.������Ǽ�λ��
   2.�ֱ����ÿһλ����
   3.�����������λ���� */
main()
{
    int c, i, count;
    char re[count];

    count = 0;
    while ((c = getchar()) != '\n') {
        re[count] = c;
        ++count;
    }
    printf("%d", count);
    for (i = count; i >= 0; --i)
        printf("%c", re[i]);
}