/* ��һ��������,Ҫ��:
1.������Ǽ�λ��
2.�ֱ����ÿһλ����
3.�����������λ���� */
#include <stdio.h>

main()
{
    int n, count;

    count = 0;
    scanf("%d", &n);
    while (n) {
        printf("%d", n % 10);
        n /= 10;
        ++count;
    }
    printf("\n%d\n", count);
}