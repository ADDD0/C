#include <stdio.h>

/* ��һ��������,Ҫ��:
   1.������Ǽ�λ��
   2.�ֱ����ÿһλ����
   3.�����������λ���� */
main()
{
    int n, count = 0;

    scanf("%d", &n);
    while (n != 0) {
        printf("%d", n % 10);
        n /= 10;
        ++count;
    }
    printf("\n%d\n", count);
}