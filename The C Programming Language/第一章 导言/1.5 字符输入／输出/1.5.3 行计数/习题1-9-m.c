#include <stdio.h>

/* ��дһ�������븴�Ƶ�����ĳ���
�������������Ķ���ո���һ���ո���� */
main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(c);
			while ((c = getchar()) == ' ') {
				c = "";
			}
		}
		putchar(c);
	}
}