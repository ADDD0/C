#include"iostream"
using namespace std;

extern char FIRSTVT[20][20];
extern char LASTVT[20][20];
extern char PriorityTable[20][20];
extern char INPUT[20][20];
extern IDentifierTable  idTbl[30];  //定义全局标识符表
extern SymbolTbl symbol[100];       //定义符号表
extern char SymbolTbl_Define[15];

//创建堆栈,准备对数据进行处理
#define MAXSIZE  300
//创建模板栈
template <typename T>
class Stack {
    public:
        //构造函数,进行初始化操作
        Stack() {
            top = -1;
        }
        //析构函数
        ~Stack(){}
        //判断栈是否为空
        bool IsEmpty() {
            if (top == -1)
                return true;
            else
                return false;
        }
        //返回栈顶元素
        T gettop() {
            return a[top];
        }
        //得到栈顶指针的数值
        int getTopPointer() {
            return top;
        }
        //定义遍历整个栈的能力
        T traverseStack(int pointer) {
            //若pointer<0则报错
            if (pointer < 0) {
                cout << "已到栈底,溢出!" << endl;
                exit(0);        //退出,分析失败
            }
            if (pointer > top) {
                cout << "试图访问栈外元素,超界!" << endl;
                exit(0);        //退出,分析失败
            }
            return a[pointer];  //返回元素值
        }
        //将元素压栈
        void push(T num) {
            if (top >= MAXSIZE)
                return;
            a[++top] = num;
        }
        //将元素弹出栈
        T pop() {
            if (top == -1) {
                cout << "栈已空,不能再弹" << endl;
                exit(0);
            }
            return a[top--];
        }
        //清空堆栈
        void Clear_Stack() {
            top = -1;
        }
    private:
        T  a[MAXSIZE];
        int top;
};

/* 单词种别码设计:
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
//char SymbolTbl_Define[15]={'=','\?','+','-','*','/','(',')','v','c','l','#','N','\0'};

/********经过以下几个函数就可以知道种别码对应的字符在符号表中的位置************/
//根据种别码返回相应字符
char SearchSyn(int syn) {
    return SymbolTbl_Define[syn-1];
}
char Prior_Position[13]={ '+', '-', '*', '/', '(', ')', 'v', 'c', '=', '?', '#', '\0' };
//搜索一个字符在优先符表中的位置
int Search_Priority_Setxy(char ch) {
    for (int i=0; i < 11; ++i)
        if (ch == Prior_Position[i])
            return i+1;
    return -1;
}

/*******************************************************************/
Stack<SymbolTbl> Reource_Symbol;  //定义堆栈
//打印出当前堆栈和符号表的上下文
void Print_Context(int Stack_Top, int Sym_Pointer) {
    int i, syn, value, sym_length;
    cout << "\t当前堆栈情况为" << endl;
    cout << "\t\t";
    for (int i=0; i <= Stack_Top; ++i) {
        //打印出堆栈
        syn = Reource_Symbol.traverseStack(i).syn;
        value = Reource_Symbol.traverseStack(i).value;
        cout << "(" << syn << "," << value << ")  ";
    }
    cout << endl << "\t当前符号表情况为" << endl;
    cout << "\t\t";
    for (i = 0; symbol[i].syn != 12; ++i)
        ;  //计算符号表的长度i
    sym_length = i + 1;  //长度,最后一个为#,从1开始数
    for (int j=Sym_Pointer; j < sym_length; ++j) {
        //打印出堆栈
        syn = symbol[j].syn;
        value = symbol[j].value;
        cout << "(" << syn << "," << value << ")  ";
    }
    cout << endl;
}

void MainProc_Analysis() {
    //现在的情况是已经分析出了句子的单词,并且变成了单词块,存放在SymbolTbl symbol中
    //并且分析出了标识符存放在了IDentifierTable idTbl中
    //分析出了算符优先分析的优先关系表存放在char PriorityTable中
    //已经编码出了种别码表,放在char SymbolTbl_Define中

    cout << "下面开始核心算法:" << endl;
    int i;
    int row_prior,column_prior;  //行列定位指针
    char Prior_Relation;         //优先关系
    int sym_length;              //符号表长度
    int pStackTop;               //栈顶指针
    int pScanStack;              //定义扫描堆栈指针
    int Statement_count=0;       //记录步骤序号

    //现在的算法是1.初始化栈,在栈中放入#(12,),然后开始分析
    SymbolTbl temp_sym;
    temp_sym.syn = 12;
    temp_sym.value = -1;  //-1代表这个地方不需要
    Reource_Symbol.push(temp_sym);  //将#压栈

    //对symbol中的内容定义指针,并且略过第一个#
    int Sym_scan_pointer=1;
    for (int i=1; symbol[i].syn != 12; ++i)
        ;  //计算符号表的长度i
    sym_length = i + 1;   //长度,最后一个为#,从1开始数
    //判断符号表第一个元素的syn==11?即是否为clear
    if (sym_length >= 3 && symbol[1].syn == 11) {
        //清除语句,清除屏幕并且清空标号表中的值
        Clear_IDentifier_Tbl();
        Clear_Symbol_Tbl();
        Reource_Symbol.Clear_Stack();
        system("cls");
        goto end;
    }
    //下面比较栈中元素和符号表中元素的大小关系
    pStackTop = Reource_Symbol.getTopPointer();
    pScanStack = pStackTop;  //扫描指针从栈顶开始
    Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
    while(1) {
        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));  //栈扫描指针
        column_prior = Search_Priority_Setxy(SearchSyn(symbol[Sym_scan_pointer].syn));  //符号表扫描指针
        Prior_Relation = PriorityTable[row_prior][column_prior];
        if (Prior_Relation == '<' || (Prior_Relation == '=' && (column_prior != 11 || row_prior != 11))) {
            //要是为小于或等于关系,则进栈
            //这里的等于关系可能为(N),v=,这两种关系
            Reource_Symbol.push(symbol[Sym_scan_pointer]);  //栈顶++
            //扫描指针后移,不能回头
            Sym_scan_pointer++;
            //注意此时还要改变堆栈指针的值
            pStackTop = Reource_Symbol.getTopPointer();  //得到变动后的栈顶指针,始终指向栈顶
            pScanStack = pStackTop;  //进行下一次判断,此时扫描指针指向新移进来的元素
            cout << Statement_count++ << ".这里是小于、等于关系,压栈!" << endl;
            Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
        } else if (Prior_Relation == '=' && column_prior == 11 && row_prior == 11) {
            //规约到最后#N,查看栈中是否满足情况
            //输出N的数值并结束
            int final_value;
            if (Reource_Symbol.gettop().syn == 13 && Reource_Symbol.getTopPointer() == 1) {
                //若满足#N的情况,则归约成功!
                cout << Statement_count++ << "." << "归约成功!!!" << endl;
                Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
                final_value = Reource_Symbol.gettop().value;
                printf("最后的结果为  %d  \n",final_value);
                Reource_Symbol.Clear_Stack();
                break;  //退出大循环,唯一的正确出口
            }
            else {
                cout << "句子错误,程序结束!" << endl;
                exit(0);
            }
        } else if (Prior_Relation == '>') {
            pStackTop = Reource_Symbol.getTopPointer();  //得到栈顶指针
            pScanStack = pStackTop;                      //扫描指针从栈顶开始
            while(Prior_Relation=='>') {
                //若优先关系始终为大于,则堆栈指针前移,不断寻找可归约串
                //因为可归约串始终在栈顶的某段区域,那么就要试探着先看一下栈顶元素是不是
                //若栈顶元素可归约,则直接归约为N(13,),否则查看栈顶方向的两个元素
                //因为文法的产生式右部最多只有三个元素,因此若是到了三个元素还没有搜索到
                //可归约串,则视为语法错误,停止分析
                //此处构建两个指针,一个既是栈顶指针,另一个为扫描可归约串的指针
                //这里不可能出现'('

                //判断栈顶元素是否可归约
                int judge=Reource_Symbol.traverseStack(pScanStack).syn;  //判断该种别码
                //若是单个变量或常量则规约为N
                //此处还要进行语义分析,对于标识符要查标识符表判断是否存在,若不存在则为错
                if (judge == 9) {
                    if (idTbl[Reource_Symbol.traverseStack(pScanStack).value].value == -1)
                        cout << "此变量可能没被定义,按照-1处理" << endl;
                    if (Reource_Symbol.traverseStack(pScanStack).value < 0) {
                        //若该变量的符号表入口地址为负值,则说明查无此元素,则认为语法出错,变量未定义
                        cout << "该变量未定义" << endl;
                        exit(0);
                    } else {
                        //否则将该标识符规约为N
                        temp_sym.syn = 13;
                        //获得符号表中关于该变量的值
                        temp_sym.value = idTbl[Reource_Symbol.traverseStack(pScanStack).value].value;
                        Reource_Symbol.pop();           //先弹出栈顶元素
                        Reource_Symbol.push(temp_sym);  //将N压栈
                        pStackTop = Reource_Symbol.getTopPointer();  //得到变动后的栈顶指针,始终指向栈顶
                        //扫描指针要前移,因为要分析终结符,而栈顶已变成非终结符
                        pScanStack = Reource_Symbol.getTopPointer() - 1;  //进行下一次判断
                        if (pScanStack < 0) {
                            cout << "句子错误,程序结束!" << endl;
                            exit(0);
                        }
                        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                        Prior_Relation = PriorityTable[row_prior][column_prior];  //此处列是不会变的,因为大于关系
                        cout << Statement_count++ << "." << "此处将变量规约为N" << endl;
                        Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
                    }
                } else if (judge == 10) {
                    //若是常量,则要记住该常量值以便进行规约时赋值
                    temp_sym.syn = 13;
                    temp_sym.value = Reource_Symbol.traverseStack(pScanStack).value;
                    Reource_Symbol.pop();           //先弹出栈顶元素
                    Reource_Symbol.push(temp_sym);  //将N压栈
                    pStackTop = Reource_Symbol.getTopPointer();
                    pScanStack = Reource_Symbol.getTopPointer() - 1;  //进行下一次判断
                    if (pScanStack < 0) {
                        cout << "句子错误,程序结束!" << endl;
                        exit(0);
                    }
                    row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                    Prior_Relation = PriorityTable[row_prior][column_prior];  //同标识符
                    cout << Statement_count++ << "." << "此处将常量规约为N" << endl;
                    Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
                } else if (judge == 1) {
                    //v=E,此时要进行赋值操作,然后规约
                    if (Reource_Symbol.traverseStack(pScanStack-1).syn == 9) {
                        //一定为9
                        //若前面为标识符则正确,应该为该变量赋值
                        //语义分析
                        idTbl[Reource_Symbol.traverseStack(pScanStack-1).value].value=Reource_Symbol.gettop().value;  //此时栈顶必为E
                        temp_sym.syn = 13;
                        temp_sym.value = Reource_Symbol.gettop().value;  //N中的值永远为真正的值,而不是地址
                        //开始归约
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();           //弹出三个元素
                        Reource_Symbol.push(temp_sym);  //规约为N
                        pStackTop = Reource_Symbol.getTopPointer();
                        pScanStack = Reource_Symbol.getTopPointer() - 1;  //始终指向规约后的第一个非终结符
                        if (pScanStack < 0) {
                           cout << "句子错误,程序结束!" << endl;
                           exit(0);
                        }
                        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                        Prior_Relation = PriorityTable[row_prior][column_prior];  //进行下次判断
                        cout << Statement_count++ << "." << "此处遇到等号要将v=E规约为N,程序面临结束!" << endl;
                        Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
                    } else {
                        cout << "等号前面应该有变量!" << endl;
                        exit(0);
                    }
                } else if (judge == 3) {
                    //+,此时栈顶应该为N+N的形式
                    //只需把两个数相加,并且把结果放在N中即可
                    if (Reource_Symbol.traverseStack(pScanStack-1).syn == 13 && Reource_Symbol.traverseStack(pScanStack+1).syn == 13) {
                        //一定为13
                        //若前面为N并且栈顶为N则正确
                        //语义分析,newtemp()
                        temp_sym.syn=13;
                        temp_sym.value = Reource_Symbol.traverseStack(pScanStack-1).value+Reource_Symbol.traverseStack(pScanStack+1).value;  //N中的值永远为真正的值,而不是地址
                        //开始归约
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();           //弹出三个元素
                        Reource_Symbol.push(temp_sym);  //规约为N
                        pStackTop = Reource_Symbol.getTopPointer();
                        pScanStack = Reource_Symbol.getTopPointer()-1;  //始终指向规约后的第一个非终结符
                        if (pScanStack < 0) {
                            cout << "句子错误,程序结束!" << endl;
                            exit(0);
                        }
                        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                        Prior_Relation = PriorityTable[row_prior][column_prior];  //进行下次判断
                        cout << Statement_count++ << "." << "此处为加法运算,将N+N规约为N,并进行语义分析!" << endl;
                        Print_Context(Reource_Symbol.getTopPointer(),Sym_scan_pointer);
                    } else {
                        cout << "加号两边应该都有变量,句子错误!" << endl;
                        exit(0);
                    }
                } else if (judge == 4) {
                    //-
                    if (Reource_Symbol.traverseStack(pScanStack-1).syn == 13 && Reource_Symbol.traverseStack(pScanStack+1).syn == 13)  {
                        //一定为13
                        //若前面为N并且栈顶为N则正确(N-N)
                        //语义分析,newtemp()
                        temp_sym.syn = 13;
                        //注意运算的顺序
                        temp_sym.value = Reource_Symbol.traverseStack(pScanStack-1).value-Reource_Symbol.traverseStack(pScanStack+1).value;  //N中的值永远为真正的值,而不是地址
                        //开始归约
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();           //弹出三个元素
                        Reource_Symbol.push(temp_sym);  //规约为N
                        pStackTop = Reource_Symbol.getTopPointer();
                        pScanStack = Reource_Symbol.getTopPointer() - 1;  //始终指向规约后的第一个非终结符
                        if (pScanStack < 0) {
                            cout << "句子错误,程序结束!" << endl;
                            exit(0);
                        }
                        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                        Prior_Relation = PriorityTable[row_prior][column_prior];  //进行下次判断
                        cout << Statement_count++ << "." << "此处为减法运算,将N-N规约为N,并进行语义分析!" << endl;
                        Print_Context(Reource_Symbol.getTopPointer(),Sym_scan_pointer);
                    } else {
                        cout << "减号两边应该都有变量,句子错误!" << endl;
                        exit(0);
                    }
                } else if (judge == 5) {
                    //*
                    if (Reource_Symbol.traverseStack(pScanStack-1).syn == 13 && Reource_Symbol.traverseStack(pScanStack+1).syn == 13)  {
                        //一定为13
                        //若前面为N并且栈顶为N则正确(N*N)
                        //语义分析,newtemp()
                        temp_sym.syn = 13;
                        //注意运算的顺序
                        temp_sym.value = Reource_Symbol.traverseStack(pScanStack-1).value*Reource_Symbol.traverseStack(pScanStack+1).value;  //N中的值永远为真正的值,而不是地址
                        //开始归约
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();           //弹出三个元素
                        Reource_Symbol.push(temp_sym);  //规约为N
                        pStackTop = Reource_Symbol.getTopPointer();
                        pScanStack = Reource_Symbol.getTopPointer() - 1;  //始终指向规约后的第一个非终结符
                        if (pScanStack < 0) {
                            cout << "句子错误,程序结束!" << endl;
                            exit(0);
                        }
                        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                        Prior_Relation = PriorityTable[row_prior][column_prior];  //进行下次判断
                        cout << Statement_count++ << "." << "此处为乘法运算,将N*N规约为N,并进行语义分析!" << endl;
                        Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
                    } else {
                        cout << "乘号两边应该都有变量,句子错误!" << endl;
                        exit(0);
                    }
                } else if (judge == 6) {
                    // /除
                    if (Reource_Symbol.traverseStack(pScanStack-1).syn == 13 && Reource_Symbol.traverseStack(pScanStack+1).syn == 13) {
                        //一定为13
                        //若前面为N并且栈顶为N则正确(N/N)
                        //语义分析,newtemp()
                        temp_sym.syn = 13;
                        //注意运算的顺序
                        temp_sym.value = Reource_Symbol.traverseStack(pScanStack-1).value/Reource_Symbol.traverseStack(pScanStack+1).value;  //N中的值永远为真正的值,而不是地址
                        //开始归约
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();           //弹出三个元素
                        Reource_Symbol.push(temp_sym);  //规约为N
                        pStackTop = Reource_Symbol.getTopPointer();
                        pScanStack = Reource_Symbol.getTopPointer() - 1;  //始终指向规约后的第一个非终结符
                        if (pScanStack < 0) {
                            cout << "句子错误,程序结束!" << endl;
                            exit(0);
                        }
                        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                        Prior_Relation = PriorityTable[row_prior][column_prior];  //进行下次判断
                        cout << Statement_count++ << "." << "此处为除法运算,将N/N规约为N,并进行语义分析!" << endl;
                        Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
                    } else {
                        cout << "除号两边应该都有变量,句子错误!" << endl;
                        exit(0);
                    }
                } else if(judge==8) {
                    // ) 若为右括号,这种情况一旦出现就要将(N)规约为N
                    //判断前面是不是"(N"
                    if (Reource_Symbol.traverseStack(pScanStack-1).syn == 13 && Reource_Symbol.traverseStack(pScanStack-2).syn == 7) {
                        //若前面为（N 则正确
                        //语义分析,newtemp()
                        temp_sym.syn = 13;
                        //N<-(N),N.value=(N).value
                        temp_sym.value = Reource_Symbol.traverseStack(pScanStack-1).value;  //N中的值永远为真正的值,而不是地址
                        //开始归约
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();           //弹出三个元素
                        Reource_Symbol.push(temp_sym);  //规约为N
                        pStackTop = Reource_Symbol.getTopPointer();
                        pScanStack = Reource_Symbol.getTopPointer() - 1;  //始终指向规约后的第一个非终结符
                        if (pScanStack < 0) {
                            cout << "句子错误,程序结束!" << endl;
                            exit(0);
                        }
                        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                        Prior_Relation = PriorityTable[row_prior][column_prior];  //进行下次判断
                        cout << Statement_count++ << "." << "此处为),将(N)规约为N,并进行语义分析!" << endl;
                        Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
                    } else {
                        cout << "括号不匹配,句子错误!" << endl;
                        exit(0);
                    }
                } else if (judge == 2) {
                    // ? 则问号前面必为N
                    if (Reource_Symbol.traverseStack(pScanStack-1).syn == 13) {
                        //语义分析,newtemp()
                        temp_sym.syn = 13;
                        temp_sym.value = Reource_Symbol.traverseStack(pScanStack-1).value;
                        //开始归约
                        Reource_Symbol.pop();
                        Reource_Symbol.pop();           //弹出2个元素
                        Reource_Symbol.push(temp_sym);  //规约为N
                        pStackTop = Reource_Symbol.getTopPointer();
                        pScanStack = Reource_Symbol.getTopPointer() - 1;  //始终指向规约后的第一个非终结符
                        if (pScanStack < 0) {
                            cout << "句子错误,程序结束!" << endl;
                            exit(0);
                        }
                        row_prior = Search_Priority_Setxy(SearchSyn(Reource_Symbol.traverseStack(pScanStack).syn));
                        Prior_Relation = PriorityTable[row_prior][column_prior];  //进行下次判断
                        cout << Statement_count++ << "." << "此处将 N? 规约为N" << endl;
                        Print_Context(Reource_Symbol.getTopPointer(), Sym_scan_pointer);
                    } else {
                        cout << "问号前面必须有N!" << endl;
                        exit(0);
                    }
                } else {
                    cout << "暂时还未定义" << endl;
                    exit(0);
                }
          }// end while(Prior_Relation=='>')
       }//end else if(Prior_Relation=='>')
   }//end while(1)
  end: ;
}//end

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