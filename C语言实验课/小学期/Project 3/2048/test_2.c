/*
颜色函数SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),前景色 | 背景色 | 前景加强 | 背景加强);
	前景色：数字0-15 或 FOREGROUND_XXX 表示	（其中XXX可用BLUE、RED、GREEN表示） 
	前景加强：数字8 或 FOREGROUND_INTENSITY 表示
	背景色：数字16 32 64 或 BACKGROUND_XXX 三种颜色表示 
	背景加强： 数字128 或 BACKGROUND_INTENSITY 表示
主要应用：改变指定区域字体与背景的颜色
前景颜色对应值： 
　　0=黑色                8=灰色　　
  　1=蓝色                9=淡蓝色        十六进制        　　                        
　　2=绿色                10=淡绿色       0xa        　　
　　3=湖蓝色              11=淡浅绿色     0xb　
　　4=红色                12=淡红色       0xc　　
　　5=紫色                13=淡紫色       0xd        　　
　　6=黄色                14=淡黄色       0xe        　　
　　7=白色                15=亮白色       0xf 
　　也可以把这些值设置成常量。
*/
#include <stdio.h>
#include <windows.h>
void color(short x)	//自定义函根据参数改变颜色 
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
    else//默认的颜色白色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int main()
{       
	printf("此处为没调用颜色函数之前默认的颜色\n");
	//调用自定义color(x)函数 改变的颜色
    color(0);	printf("黑色\n");
    color(1); 	printf("蓝色\n");
    color(2); 	printf("绿色\n"); 
    color(3); 	printf("湖蓝色\n");
    color(4);  	printf("红色\n");
    color(5);  	printf("紫色\n");
    color(6); 	printf("黄色\n"); 
    color(7);  	printf("白色\n");
    color(8);  	printf("灰色\n");
    color(9); 	printf("淡蓝色\n");
    color(10); 	printf("淡绿色\n");
    color(11); 	printf("淡浅绿色\n"); 
    color(12);  printf("淡红色\n");
    color(13); 	printf("淡紫色\n");
    color(14); 	printf("淡黄色\n");
    color(15); 	printf("亮白色\n");
    color(16);    //因为这里大于15，恢复默认的颜色 
    printf("回到原来颜色\n");
    //直接使用颜色函数
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    printf("红色字体   前景加强 绿色背景 背景加强\n"); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    printf("亮白色字体 前景加强 红色背景 背景加强\n"); 
	//声明句柄再调用函数 
	HANDLE JB = GetStdHandle(STD_OUTPUT_HANDLE);//创建并实例化句柄 
	SetConsoleTextAttribute(JB, 2 | 8);
	printf("颜色及对应数字表：\n");

	for(int i = 0;i < 256;i ++){
		//color(16);printf(" "); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		printf("%-3d", i);
		color(16);printf(" "); 
		if((i + 1) % 16 == 0)	printf("\n");
	}
	color(16);
    return 0;
    //类似的函数还有system("color XX");（X是十六进制0~F之间的数,不过这种函数改变的是整个画面,而不能让多处局部变色;
}
 
