#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100

void anal(int type, char *word) {
	switch (type) {
		case 0: printf("<0, %s>\n", word); break;
		case 1: printf("<1, %s>\n", word); break;
		case 2: printf("<2, %s>\n", word); break;
		case 3: printf("<3, %s>\n", word); break;
		case 4: printf("<4, %s>\n", word); break;
		case 5: printf("<5, %s>\n", word); break;
	}
}

void error() {
	printf("Wrong\n");
}

int getword(char *word, int lim) {
    int c;
    char *w = word;

	while (isspace(c = getchar()))
        ;
    if (c != EOF)
        *w++ = c;
	else
		return c;
	for ( ; --lim > 0; w++) {
		if (isspace(*w = getchar())) {
			break;
		}
	}
	*w = '\0';
    return word[0];
}

int main() {
	char word[100];
	
	while (getword(word, BUFSIZE) != EOF) {
		if (ispunct(word[0])) {
			if (strlen(word) == 1)
				anal(4, word);
			else
				error();
		} else if (isalpha(word[0])) {
			if (!strcmp(word, "if") || !strcmp(word, "then") || !strcmp(word, "else") || !strcmp(word, "while") || !strcmp(word, "do"))
				anal(5, word);
			else
				anal(0, word);
		} else if (isdigit(word[0])) {
			if (word[0] != '0')
				anal(1, word);
			else if (word[1] == 'x')
				anal(3, word);
			else
				anal(2, word);
		} else 
            error();
	}
	return 0;
}