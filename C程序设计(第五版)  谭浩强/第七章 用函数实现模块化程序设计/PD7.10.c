/* 写一个函数,输入一行字符,将此字符串中最长的单词输出 */
#include <stdio.h>

#define  IN   1  /* 在单词内     */
#define  OUT  0  /* 在单词外     */

main()
{
    int getlen(char word[]);
    int i, j, k, max, state;
    char s[128];
    char word[128];
    char longest[128];

	state = OUT;
    gets(s);	
    for (i = max = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
            state = OUT;
            if (max < getlen(word)) {
                max = getlen(word);
                for (k = 0; (longest[k] = word[k]) != '\0'; ++k)
                    printf("%c\n", longest[i]);
                longest[k] = '\0';
            }
        } else if (state == OUT) {
            state = IN;
            j = 0;
            word[j] = s[i];
			printf("%c\n", s[i]);
			printf(" %c", word[j]);
        } else
            word[j++] = s[i];
    }
    for (i = 0; longest[++i] != '\0'; )
        printf("%c", longest[i]); 
    printf("\n");
}

int getlen(char word[])
{
    int i;

    for (i = 0; word[++i] != '\0'; )
        ;
    return (i);
}