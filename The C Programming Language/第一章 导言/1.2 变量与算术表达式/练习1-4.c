#include <stdio.h>

/* ��дһ�������ӡ�����¶�ת��Ϊ��Ӧ�����¶ȵ�ת���� */
main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;						  /* �¶ȱ������ */
	upper = 300;					  /* �¶ȱ������ */
	step = 20;								  /* ���� */
	
	printf("Celsius Fahr\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0*celsius) / 5.0 + 32.0;
		printf("%4.0f  %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}