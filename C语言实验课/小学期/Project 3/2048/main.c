/*
 * Copyright (C) Judge Young
 * E-mail: yjjtc@126.com
 * Version: 1.0
 */

/* 有一定改动 */
#include <stdio.h>
#include <time.h>     /* 包含设定随机数种子所需要的time()函数                         */
#include <conio.h>    /* 包含Windows平台上完成输入字符不带回显和回车确认的getch()函数 */
#include <windows.h>  /* 包含Windows平台上完成设定输出光标位置达到清屏功能的函数      */

void start_game();  /* 开始游戏 */
void reset_game();  /* 重置游戏 */

/* 往左右上下四个方向移动 */
void move_left();
void move_right();
void move_up();
void move_down();

void timint(int);        /* 每隔一段时间会自动填入数字                    */
void refresh_show();     /* 刷新界面显示                                  */
void add_rand_num();     /* 生成随机数,本程序中仅生成2或4,概率之比设为2:1 */
void check_game_over();  /* 检测是否输掉游戏,设定游戏结束标志             */
int get_null_count();    /* 获取游戏面板上空位置数量                      */

int board[4][4];      /* 游戏数字面板,抽象为二维数组                  */
int score;            /* 游戏的分                                     */
int best;             /* 游戏最高分                                   */
int if_need_add_num;  /* 是否需要生成随机数标志,1表示需要,0表示不需要 */
int if_game_over;     /* 是否游戏结束标志,1表示游戏结束,0表示正常     */

/* 主函数 */
int main()
{
    start_game();
}

/* 开始游戏 */
void start_game()
{
    reset_game();
    char cmd;

    while (1) {
        timing(10);
        cmd = getch();                       /* 接收标准输入流字符命令 */

        /* 判断是否需已经输掉游戏                                      */
        if (if_game_over) {
            if (tolower(cmd) == 'y') {       /* 重玩游戏               */
                reset_game();
                continue;
            } else if (tolower(cmd) == 'n')  /* 退出                   */
                return;
            else
                continue;
        }

        /* 先设定不默认需要生成随机数,需要时再设定为1                  */
        if_need_add_num = 0;

        /* 命令解析: w,s,a,d字符代表上下左右命令                       */
        switch (tolower(cmd)) {
            case 'a':
                move_left();
                break;
            case 'd':
                move_right();
                break;
            case 'w':
                move_up();
                break;
            case 's':
                move_down();
                break;
            default : continue;
        }

        score > best ? best = score : 1;     /* 打破得分纪录           */

        /* 默认为需要生成随机数时也同时需要刷新显示,反之亦然           */
        if (if_need_add_num) {
            add_rand_num();
            refresh_show();
        }
    }
}
/* 计时函数 */
void timing(int s)
{
	sleep(s);
	if (get_null_count()) {
		add_rand_num();
		refresh_show();
	}
	timing(s);
}

/* 重置游戏 */
void reset_game()
{
    score = 0;
    if_need_add_num = 1;
    if_game_over = 0;

    /* 了解到游戏初始化时出现的两个数一定会有个2,所以先随机生成一个2,其他均为0     */
    srand(time(0));
    int n = rand() % 16;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            board[i][j] = (!n-- ? 2 : 0);

    /* 前面已经生成了一个2,这里再生成一个随机的2或者4,且设定生成2的概率是4的两倍   */
    add_rand_num();

    /* 在这里刷新界面并显示的时候,界面上已经默认出现了两个数字,其他的都为空(值为0) */
    system("cls");
    refresh_show();
}

/* 生成随机数 */
void add_rand_num()
{
    srand(time(0));
    int n = rand() % get_null_count();               /* 确定在何处空位置生成随机数                  */
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (!board[i][j] && !n--) {              /* 定位待生成的位置                            */
                board[i][j] = (rand() % 3 ? 2 : 4);  /* 确定生成何值,设定生成2的概率是4的概率的两倍 */
                return;
            }
}

/* 获取空位置数量 */
int get_null_count()
{
    int n = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            !board[i][j] ? n++ : 1;
    return n;
}

/* 检查游戏是否结束 */
void check_game_over()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 3; ++j)
            /* 横向和纵向比较挨着的两个元素是否相等,若有相等则游戏不结束 */
            if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i]) {
                if_game_over = 0;
                return;
            }
    if_game_over = 1;
}

/*
 * 如下四个函数,实现上下左右移动时数字面板的变化算法
 * 左和右移动的本质一样,区别仅仅是列项的遍历方向相反
 * 上和下移动的本质一样,区别仅仅是行项的遍历方向相反
 * 左和上移动的本质也一样,区别仅仅是遍历时行和列互换
 */

/* 左移函数 */
void move_left()
{
    /* 变量i用来遍历行项的下标,并且在移动时所有行相互独立,互不影响                            */
    for (int i = 0; i < 4; ++i)
        /* 变量j为列下标,变量k为待比较（合并）项的下标,循环进入时k<j                          */
        for (int j = 1, k = 0; j < 4; ++j)
            if (board[i][j] > 0)          /* 找出k后面第一个不为空的项,下标为j,之后分三种情况 */
            {
                /* 情况1: k项和j项相等,此时合并方块并计分                                     */
                if (board[i][k] == board[i][j]) {
                    score += board[i][k++] <<= 1;
                    board[i][j] = 0;
                    if_need_add_num = 1;  /* 需要生成随机数和刷新界面                         */
                }
                /* 情况2: k项为空,则把j项赋值给k项,相当于j方块移动到k方块                     */
                else if (!board[i][k]) {
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                    if_need_add_num = 1;
                }
                /* 情况3: k项不为空,且和j项不相等,此时把j项赋值给k+1项,相当于移动到k+1的位置  */
                else {
                    board[i][++k] = board[i][j];
                    /* 判断j项和k项是否原先就挨在一起,若不是则把j项赋值为空(值为0)            */
                    if (j != k) {
                        board[i][j] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
}

/* 右移函数 */
void move_right()
{
    /* 仿照左移操作,区别仅仅是j和k都反向遍历 */
    for (int i = 0; i < 4; ++i)
        for (int j = 2, k = 3; j >= 0; --j)
            if (board[i][j] > 0) {
                if (board[i][k] == board[i][j]) {
                    score += board[i][k--] <<= 1;
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } else if (!board[i][k]) {
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } else {
                    board[i][--k] = board[i][j];
                    if (j != k) {
                        board[i][j] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
}

/* 上移函数 */
void move_up()
{
    /* 仿照左移操作,区别仅仅是行列互换后遍历 */
    for (int i = 0; i < 4; ++i)
        for (int j = 1, k = 0; j < 4; ++j)
            if (board[j][i] > 0) {
                if (board[k][i] == board[j][i]) {
                    score += board[k++][i] <<= 1;
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } else if (!board[k][i]) {
                    board[k][i] = board[j][i];
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } else {
                    board[++k][i] = board[j][i];
                    if (j != k) {
                        board[j][i] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
}

/* 下移函数 */
void move_down()
{
    /* 仿照左移操作,区别仅仅是行列互换后遍历,且j和k都反向遍历 */
    for (int i = 0; i < 4; ++i)
        for (int j = 2, k = 3; j >= 0; --j)
            if (board[j][i] > 0) {
                if (board[k][i] == board[j][i]) {
                    score += board[k--][i] <<= 1;
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } else if (!board[k][i]) {
                    board[k][i] = board[j][i];
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } else {
                    board[--k][i] = board[j][i];
                    if (j != k) {
                        board[j][i] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
}


/* 刷新界面 */
void refresh_show()
{
    /* 重设光标输出位置方式清屏可以减少闪烁,system("cls")为备用清屏命令,均为Windows平台相关 */
    COORD pos = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    printf("\n\n\n\n");
    printf("                GAME: 2048     SCORE: %06d    BEST: %06d\n", score, best);
    printf("             --------------------------------------------------\n\n");

    /* 绘制表格和数字                                                                       */
    printf("                        ┌──┬──┬──┬──┐\n");
    for (int i = 0; i < 4; ++i) {
        printf("                        │");
        for (int j = 0; j < 4; ++j) {
            if (board[i][j]) {
                HANDLE JB = GetStdHandle(STD_OUTPUT_HANDLE);  /* 创建并实例化句柄           */

                int n = board[i][j];
                int digit = 0;


                for ( ; n; ++digit)
                    n /= 10;
                switch(digit) {
                    case 1:
                    switch(board[i][j]) {
                        case 2: case 4: SetConsoleTextAttribute(JB, 248); break;
                        case 8: SetConsoleTextAttribute(JB, 143); break;
                    }
                    printf("  %d ", board[i][j]);
                    break;

                    case 2:
                    switch(board[i][j]) {
                        case 16: SetConsoleTextAttribute(JB, 206); break;
                        case 32: SetConsoleTextAttribute(JB, 234); break;
                        case 64: SetConsoleTextAttribute(JB, 169); break;
                    }
                    printf(" %d ", board[i][j]);
                    break;

                    case 3:
                    switch(board[i][j]) {
                        case 128: SetConsoleTextAttribute(JB, 157); break;
                        case 256: SetConsoleTextAttribute(JB, 217); break;
                        case 512: SetConsoleTextAttribute(JB, 154); break;
                    }
                    printf(" %d", board[i][j]);
                    break;

                    case 4:
                    switch(board[i][j]) {
                        case 1024: SetConsoleTextAttribute(JB, 174); break;
                        case 2048: SetConsoleTextAttribute(JB, 236); break;
                        default: SetConsoleTextAttribute(JB, 192); break;
                    }
                    printf("%4d", board[i][j]);
                    break;

                    default :
                    n = board[i][j];
                    for (int k = 1; k < 20; ++k) {
                        n >>= 1;
                        if (n == 1) {
                            SetConsoleTextAttribute(JB, 192);
                            /* 超过四位的数字用2的幂形式表示,如2^13形式                     */
                            printf("2^%02d", k);
                            break;
                        }
                    }
                    break;
                }

                SetConsoleTextAttribute(JB, 7);
                printf("│");
            }
            else
                printf("    │");
        }

        if (i < 3)
            printf("\n                        ├──┼──┼──┼──┤\n");
        else
            printf("\n                        └──┴──┴──┴──┘\n");
    }

    printf("\n             --------------------------------------------------\n");
    printf("                            W↑  A←  →D  ↓S");

    if (!get_null_count()) {
        check_game_over();
        if (if_game_over)   /* 判断是否输掉游戏                                             */
            printf("\r                    GAME OVER! TRY THE GAME AGAIN? [Y/N]");
    }
}