#include <stdio.h>
#include <math.h>

main()
{
	double n;
	int judge=1;
	int i;
	
	scanf("%lf", &n);
	for (i = 2; i < (int)sqrt(n)+1; i++)
	{
		if ((int)n % i == 0)
		{
			judge = 0;
			break;
		}
	}
	if (judge)
		printf("%.0f is a prime number\n", n);
	else
		printf("%.0f is not a prime number\n", n);
}