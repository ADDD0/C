#include <stdio.h>

/* �޸��¶�ת������
ʹ֮����ת����Ķ�����ӡһ������ */
main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;	 /* �¶ȱ������ */
	upper = 300; /* �¶ȱ������ */
	step = 20;			 /* ���� */
	
	printf("Fahr Celsius\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%4.0f  %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}