/* ��д�������2��-3��0��5����
����������ʽΪ:
2��0����:1     -3��0����:1
2��1����:2     -3��1����:-3
2��2����:4     -3��2����:9
2��3����:8     -3��3����:-27
2��4����:16        -3��4����:81
2��5����:32        -3��5����:-243

����Ҫ��:
�ٱ�дһ��power(int x,int n)��������x��n����
power��������ʽΪ:
int power(int x,int n)
{
    ��д����ʵ����x��n����;
}
�����������ж�ε���power����,�õ���Ҫ��Ľ��
void main()
{
    for(i=0;i<=5;i++)
    {
        printf("2��%d����:%d\t",i,power(2,i));
        printf("-3��%d����:%d\n",i,power(-3,i));
    }                                            */
#include <stdio.h>

main()
{
    int power(int x, int n);
    int i;

    for (i = 0; i <= 5; ++i) {
        printf("2��%d����:%d\t", i, power(2,i));
        printf("-3��%d����:%d\n", i, power(-3,i));
    }
}

int power(int x, int n)
{
    int pow = 1;

    while(n-- > 0)
        pow *= x;
    return pow;
}