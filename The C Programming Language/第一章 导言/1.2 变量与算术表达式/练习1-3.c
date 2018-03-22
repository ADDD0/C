#include <stdio.h>

/*	修改温度转换程序，
使之能在转换表的顶部打印一个标题		*/
main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		/*	温度表的下限	*/
	upper = 300;	/*	温度表的上限 	*/
	step = 20;		/*	步长			*/
	
	printf("Fahr Celsius\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%4.0f  %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}