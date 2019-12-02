#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "iostream"
using namespace std;

typedef struct {
    char IDentifier[30];  //标识符长度
    int value;            //定义标识符代表的数值
} IDentifierTable;

typedef struct {
    int syn;    //种别码
    int value;  //数值或者标识符入口指针
} SymbolTbl;

extern char FIRSTVT[20][20];
extern char LASTVT[20][20];
extern char PriorityTable[20][20];
extern char INPUT[20][20];
extern IDentifierTable idTbl[30];
extern SymbolTbl symbol[100];  //定义符号表
/*单词种别码设计:
        =   1
        ？  2
        +   3
        -   4
        *   5
        /   6
       （   7
        ）  8
        v   9
        c   10
      clear 11
        #   12
        N   13
*/
//此处简单起见,就只考虑标识符,运算符,数字
//定义一个结构存储(种别码、单词的入口地址)或者(种别码,常数值)或者(种别码)
//插入到标识符表中
void InsertID(char name[], int entry, int value) {
    strcpy(idTbl[entry].IDentifier, name);  //插入名字
    idTbl[entry].value = value;             //插入数值
}

//查找符号表中是否有空闲位置
int ScanEntry(char name[]) {
    for (int i=0; i < 30; ++i)
        if (strcmp(idTbl[i].IDentifier, name) == 0)
            return i;  //返回入口地址
    return -1;         //失败返回失败码
}

//查找符号表中是否有空闲位置
void Insert_Into_SymbolTbl(int syn, int value, int &pointer) {
    symbol[pointer].syn = syn;
    symbol[pointer].value = value;
    pointer++;
}

//查找表中是否已经存在该标识符
bool IsExist(char id[]) {
    for (int i=0; i < 30; ++i)
        if (strcmp(idTbl[i].IDentifier, id) == 0)
            return true;
  return false;
}

//查找表中是否已经存在该标识符
int Search_Free_Entity() {
    for (int i=0; i < 30; ++i)
        if (strcmp(idTbl[i].IDentifier, "") == 0)
            return i;  //返回空闲入口
  return -1;           //查找失败
}

/*********************判断是否为字母********************/
bool IsLetter(char letter) {
    //注意C语言允许下划线也为标识符的一部分可以放在首部或其他地方
    if (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z' || letter=='_')
        return true;
    else
        return false;
}
/*********************判断是否为字母********************/


/*****************判断是否为数字************************/
bool IsDigit(char digit) {
    if (digit >= '0' && digit <= '9')
        return true;
    else
        return false;
}
/*****************判断是否为数字************************/

void Scanner(char sentence[], char name[], int &syn, int &scan_point, int &value) {
    char token[30], ch;
    int p_token=0;      //token的指针
    int digit_value=0;  //记录常数的大小
    for (int n=0; n < 30; ++n)
        token[n] = '\0';  //对字符数组清零
    ch = sentence[scan_point];  //读入一个字符
    if (ch == '#' && scan_point == 0) {
        //该字符的种别码已经在主程序中登记了
        scan_point++;               //刚开始的第一个字符一定为'#'
        ch = sentence[scan_point];  //指针下移,扫描下一字符
    }
    if (IsLetter(ch)) {
        //ch是否为字母
        while (IsLetter(ch) || IsDigit(ch)) {
            //ch是否为字母或数字
            token[p_token++] = ch;
            scan_point++;
            ch = sentence[scan_point];  //读入一个字符
        }
        token[p_token] = '\0';
        syn = 9;  //代表找到了标识符
        if (strcmp(token, "clear") == 0)
            //代表找到了保留字"clear"
            syn=11;
        strcpy(name, token);  //带回标识符
    } else if (IsDigit(ch)) {
        //ch是否为数字
        digit_value = 0;
        while (IsDigit(ch)) {
            //此处假设只是整数
            digit_value = digit_value*10 + ch - '0';
            scan_point++;
            ch = sentence[scan_point];  //读入一个字符
        }
        value = digit_value;  //带回整数值
        syn = 10;
    } else {
        switch (ch) {
            case '=': syn=1;  break;
            case '?': syn=2;  break;
            case '+': syn=3;  break;
            case '-': syn=4;  break;
            case '*': syn=5;  break;
            case '/': syn=6;  break;
            case '(': syn=7;  break;
            case ')': syn=8;  break;
            case '#': syn=12; break;
            default: printf("输入句子有误!\n"); exit(0); break;
        }
        scan_point++;  //保持指针始终指向待判断的字符
        ch = sentence[scan_point];  //读入一个字符
    }
}

//检查句子是不是#。。。#的形式
bool Check_Is_Right(char sentence[]) {
    int len=strlen(sentence)-1;
    if (sentence[0] == '#' && sentence[len] == '#')
        //&&sentence[strlen[sentence]-1]=='#'
        return true;
    return false;
}

//主控程序
void LexicalAnalysisCtl() {
    char sentence[100]="\0";
    int syn=-1;
    char name[30]="";
    int value;
    int scan_point=0;  //从开始处扫描
    int id_pointer;    //定义标识符表入口指针
    int sym_pointer=0,entry;
    do {
        printf("请输入句子,以#开始并且以#结束\n");
        scanf("%s", sentence);
    } while (!Check_Is_Right(sentence));
    Insert_Into_SymbolTbl(12, -1, sym_pointer);
    printf("(%d ,  )\n", 12);
    while (syn != 12) {
        //直到扫描到第二个'#'为止
        Scanner(sentence, name, syn, scan_point, value);
        switch (syn) {
            //若是单词
            case 9:
                printf("(%d , %s)\n", syn, name);
                //登记到表中
                if (!IsExist(name)) {
                    //不存在则插入
                    //查找可插入位置
                    id_pointer = Search_Free_Entity();
                    InsertID(name, id_pointer, -1);  //-1代表还没被赋值
                }
                //搜索该标识符的入口地址放入value中
                entry = ScanEntry(name);
                Insert_Into_SymbolTbl(syn, entry, sym_pointer);
                break;
            case 10:
                //常数
                Insert_Into_SymbolTbl(syn, value, sym_pointer);
                printf("(%d  , %d)\n", syn, value);
                break;
            default:
                printf("(%d ,  )\n", syn);
                Insert_Into_SymbolTbl(syn, -1, sym_pointer);  //-1代表该处不需要值
        }
    }
    printf("--------------------词法分析正确!!!-------------------------\n");
    //打印出符号表和标识符表
    printf("标识符的入口地址  标识符  标识符的值(-1代表没被赋值)\n");
    //标识符表
    for (int m1=0; m1 < 30; ++m1)
        if (strcmp(idTbl[m1].IDentifier,"") != 0)
            printf("\t%d     %s    %d\n", m1, idTbl[m1].IDentifier, idTbl[m1].value);
    printf("符号表的入口地址  种别码  具体的值(或标识符入口)\n");
    //符号表
    for (int m2=0; m2 < sym_pointer; ++m2)
        printf("\t%d       %d     %d\n", m2, symbol[m2].syn, symbol[m2].value);
    printf("---------------------------------------------------------------\n");
}

void Clear_Symbol_Tbl() {
    //将符号表的syn全部设置为0
    for (int i=0; i < 100; ++i) {
        symbol[i].syn = 0;     //代表没定义
        symbol[i].value = -1;  //指定为-1
    }
}

void Clear_IDentifier_Tbl() {
    //清空标识符表
    for (int i=0; i < 30; ++i) {
        strcpy(idTbl[i].IDentifier, "");
        idTbl[i].value = -1;
    }
}