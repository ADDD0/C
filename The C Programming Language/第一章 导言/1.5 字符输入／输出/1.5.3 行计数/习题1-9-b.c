#include <stdio.h>

#define  NONBLANK 'a'

/* ��дһ�������븴�Ƶ�����ĳ���
�������������Ķ���ո���һ���ո���� */
main()
{
	int c, lastc;
	
	lastc = NONBLANK
	while ((c = getchar()) != EOF) {
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
}