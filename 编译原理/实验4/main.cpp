#include "stdio.h"
#include "firstVT_lastVT.h"           //计算firstVT()和LastVT()的程序
#include "GetPriorityTable.h"         //创建算符优先关系表的程序
#include "Simple_Lexical_Analysis.h"  //词法分析的程序
#include "MainProc_Analysis.h"        //主分析程序,用来进行语法和语义分析
/*注意此处l是clear的缩写,简略标记,因为在后续算符优先分析中它和其他任何非终结符
(除#外)没任何关系,故分别对待
S-->v=E|E?|l
E-->E+T|E-T|T
T-->T*F|T/F|F
F-->(E)|v|c
10个终结符,需要构造priorTable[12][12]大小的表
  + - * / （ ） v c = ? # 外加一个结束符#
*/

//设置为全局变量,则字符串开始时被全部初始化为'\0'
//用于存储FIRSTVT集
char FIRSTVT[20][20];
char LASTVT[20][20];
char PriorityTable[20][20];    //优先符表
char INPUT[20][20];            //文法记录表
IDentifierTable idTbl[30];     //定义全局标识符表
SymbolTbl symbol[100];         //定义符号表,记录输入的程序片段
char SymbolTbl_Define[15]={ '=', '\?', '+', '-', '*', '/', '(', ')', 'v', 'c', 'l', '#', 'N', '\0' };
//定义各个终结符的syn

int main() {
    char ch;                   //是否继续的标记
    DisplayFirstVT_LasVT();    //计算并显示firstVT()和LastVT()
    createPriorityTable();     //创建算符优先关系表
    DisplayPriorityTable();    //打印算符优先关系表
    while(1) {
        Clear_Symbol_Tbl();    //首先要清空符号表,这样才能进行下一轮分析
        LexicalAnalysisCtl();  //词法分析,登记符号表
        MainProc_Analysis();   //语法语义分析,产生运行结果
        cout << "continue? y or n" << endl;
        cin >> ch;
        if(tolower(ch) != 'y') {
            cout << "the procedure is end" << endl;
            exit(0);
        }
    }
    return 0;
}