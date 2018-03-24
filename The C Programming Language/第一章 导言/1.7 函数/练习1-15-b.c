#include <stdio.h>

float celsius(float fahr);

/* 重新编写1.2节中的温度转换程序，使用函数实现温度转换计算 */
main()
{
	float fahr;
	int lower, upper, step;
	
	lower = 0;    /* 温度表的下限                          */
	upper = 300;  /* 温度表的上限                          */
	step = 20;    /* 步长                                  */
	
	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f  %6.1f\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
}

/* 摄氏度：华氏度转换为摄氏度                              */
float celsius(float fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}