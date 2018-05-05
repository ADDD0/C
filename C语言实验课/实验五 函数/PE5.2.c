/* 编写递归程序:实现将一个整数的每一个数位分解出来并逆序输出
例如:
	输入的整数为:3675
    输出的结果为:5        7        6        3

具体要求:
①转换过程通过编写递归函数实现；
②在主函数输入要转换的整数n,且n可以是任意整数

提示:
①问题规模逐渐缩小的方法为:n=n/10
②问题的最小尺度为:n是一位数
③取出个位的方法为:n%10										 */
#include <stdio.h>

main()
{
	void res(int n);
	int n;
	
	printf("请输入整数:");
	scanf("%d", &n);
	res(n);
}

void res(int n)
{
	if (n < 10) {
		printf("%d\t\n", n);
		return 0;
	}
	printf("%d\t", n % 10);
	n /= 10;
	res(n);
}