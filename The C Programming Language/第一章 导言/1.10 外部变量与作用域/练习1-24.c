#include <stdio.h>

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

/* 编写一个程序，查找C语言程序中的
基本语法错误，如圆括号、方括号、花括号不配对等      */
main()
{
	int c;
	extern int brace, brack, paren;
	
	while ((c = getchar()) != EOF) {
		if (c == '/') {
			if ((c = getchar()) == '*')
				in_comment();       /* 注释内部     */
			else
				search(c);
		} else if (c == '\'' || c == '"')
			in_quote(c);            /* 引号内部     */
		else
			search(c);
		
		if (brace < 0) {            /* 输出错误     */
			printf("Unbalanced braces\n");
			brace = 0;
		} else if (brack < 0) {
			printf("Unbalanced brackets\n");
			brack = 0;
		} else if (paren < 0) {
			printf("Unbalanced parentheses\n");
			paren = 0;
		}
	
	if (brace > 0)                  /* 输出错误     */
		printf("Unbalanced braces\n");
	if (brack > 0)
		printf("Unbalanced brackets\n");
	if (paren > 0)
		printf("Unbalanced parentheses\n");
}

/* search：搜寻基本语法错误                         */
void search(int c)
{
	extern int brace, brack, paren;
	
	if (c == '{')
		++brace;
	else if (c == '}')
		--brace;
	else if (c == '[')
		++brack;
	else if (c == ']')
		--brack;
	else if (c == '(')
		++paren;
	else if (c == ')')
		--paren;
}

/* in_comment：有效注释内部                         */
void in_comment(void)
{
	int c, d;
	
	c = getchar();                  /* 前一字符     */
	d = getchar();                  /* 当前字符     */
	while (c != '*' || d != '/') {  /* 搜寻末尾     */
		c = d;
		d = getchar();
	}
}

/* in_quote：引号内部                               */
void in_quote(int c)
{
	int d;
	
	while ((d = getchar()) != c)    /* 搜寻末尾     */
		if (d == '\\')
			getchar();              /* 忽略转义序列 */
}