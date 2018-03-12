#include <stdio.h>

#define  LOWER  2000
#define  UPPER  2500

main()
{
	int year;
	
	for (year = LOWER; year <= UPPER; year += 4)
	{
		if (year % 400 == 0)
			printf("%d\n", year);
		else if (year % 4 == 0 && year % 100 != 0)
			printf("%d\n", year);
	}
}