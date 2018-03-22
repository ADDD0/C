#include <stdio.h>

main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c >= 65 && c <= 86 || c >= 97 && c <= 118)
			putchar(c+4);
		else if (c >= 87 && c <= 90 || c >=119 && c <= 122)
			putchar(c-22);
		else
			putchar(c);
	}
}