//程序功能大意说明
//该子程序主要是求算符优先文法中的firstVT()和lastVT()
//因为求firstVT()和lastVT(),可能造成的递归性,我们需要慎重对待
//直至求完所有集合的元素为止
//这里要注意递归的运用和FirstVT(),LastVT()的定义
//firstVT(E)为a...或Qa....中的终结符a,以及firstVT(Q)中的所有元素。
//lastVT(E)为...a或....aQ中的终结符a,以及lastVT(Q)中的所有元素。

#include<ctype.h>

//引用外部变量
extern char FIRSTVT[20][20];
extern char LASTVT[20][20];
extern char PriorityTable[20][20];
extern char INPUT[20][20];

//填写firstVT集合
void setFIRSTVT(char X, int T) {        //X为终结符,T标记产生式id
     for (int i=0; i < 20; ++i)
         if (i == T) {
           for (int j=0; j < 20; ++j)   //扫描判断是否加入
               if (X == FIRSTVT[i][j])  //若集合中已出现,则不加
                      return;
               else if (FIRSTVT[i][j] == '\0') {
                  FIRSTVT[i][j] = X;    //填入数组最后
                  break;
               }
           break;
         }
}

//找出FIRSTVT集元素
void getFIRSTVT(char X, int S) {
    int j=0;  //j当前数组指针
    int T=0;  //X position
    int L=0;  //X offspring length
    char C[20];

    for (int i=0; i < 20; ++i)
       if (INPUT[i][0] == X) {  //找到将要处理的产生式
         T = i;                 //标记产生式的位置
         break;
       }
    //按照规则从产生式的右部第一个字符开始处理,直至遇上'/n'
    //每一次都判断指针j指向的字符若满足p-->w中w的规定则放进C[]
    //若遇上'|'或'\n'则求这段右部对应的firstVT()
    for (int i=4; i < 20; ++i) {
        if (INPUT[T][i] == '|' || INPUT[T][i] == '\n') {  //刚开始走不到这里
            L = j;  //j指针所指位置为C[]中字符串的长度
            j = 0;  //交给L后就清零,以供下一次使用
            for (int k=0; k < L; ++k)
                //要是数组C[]中的终结符,如小写字母'a'~'z',加减乘除,乘方,#
                //则归入fisrstVT集中
                //若是Aab...则a成为F()一部分,b被忽略,A求first集,除非A==X
                //若是QRa...则不是算符优先文法,故不可能
                //若是a...则只是填进a
                if (islower(C[k]) || C[k] == '+' || C[k] == '*' || C[k] == '-'
                || C[k]== '/' || C[k] == '!' || C[k] == '(' || C[k] == ')' ||
                C[k] == '#' || C[k] == '\?' || C[k] == '=') {
                    //只能用一次,因是算符优先文法,故前两个中必会至少存在一个终结符
                    setFIRSTVT(C[k], S);  //存入FIRSTVT中,S标记产生式的位置
                    break;                //跳出循环保证存入的是最左边的终结符
                }
            if (isupper(C[0]) && C[0] != X) {
                //若C[0]中为A~Z,并且C[0]不是X(否则将无限循环),则递归的进行填充
                int flag=0;
                for (int count=0; count < 20; ++count)
                    if (INPUT[count][0] == C[0])  //找到将要处理的产生式
                        flag = 1;                 //若存在,则填充
                if (flag == 1)
                    getFIRSTVT(C[0], S);  //S为子集中的元素填入父集中指明了方向
            }
        } else if (INPUT[T][i] != '|' && INPUT[T][i] != '\0') {  //该行没结束,过滤'\0'
            C[j] = INPUT[T][i];  //j从0开始
            j++;                 //移进
        }
        if (INPUT[T][i] == '\n')
            //该行结束
            break;
    }
}

//存储LASTVT集
void setLASTVT(char X, int T) {         //X为终结符,T标记产生式id
    for (int i=0; i < 20; ++i)
        if (i == T) {
            for (int j=0; j < 20; ++j)
                if (X == LASTVT[i][j])  //若集合中已出现,则不加
                    break;
                else if (LASTVT[i][j] == '\0') {
                    LASTVT[i][j] = X;   //填入数组最后
                    return;
                }
           break;
         }
}

//找出LASTVT集元素
void getLASTVT(char X, int S) {
    int j=0;  //j当前数组指针
    int T=0;  //X position
    int L=0;  //X offspring length
    char C[20];

    for (int i=0; i < 20; ++i)
        if (INPUT[i][0] == X) {  //找到将要处理的产生式
            T = i;               //标记产生式的位置
            break;
        }
    //按照规则从产生式的右部第一个字符开始处理,直至遇上'/n'
    //每一次都判断指针j指向的字符若满足p-->w中w的规定则放进C[]
    //若遇上'|'或'\n'则求这段右部对应的LASTVT()
    for (int i=4; i < 20; ++i) {
        if (INPUT[T][i] == '|' || INPUT[T][i] == '\n') {  //刚开始走不到这里
            L = j;  //j指针所指位置为C[]中字符串的长度
            j = 0;  //交给L后就清零,以供下一次使用
            for (int k=L-1; k >= 0; --k)
                //要是数组C[]中的终结符,如小写字母'a'~'z',加减乘除,乘方,#
                //则归入LASTVT集中
                //若是Aab...则a成为F()一部分,b被忽略,A求first集,除非A==X
                //若是QRa...则不是算符优先文法,故不可能
                //若是a...则只是填进a
                if (islower(C[k]) || C[k] == '+' || C[k] == '*' || C[k] == '-'
                || C[k]== '/' || C[k] == '!' || C[k] == '(' || C[k] == ')' ||
                C[k] == '#' || C[k] == '\?' || C[k] == '=') {
                    //只能用一次
                    setLASTVT(C[k], S);  //存入LASTVT中,S标记产生式的位置
                    break;               //跳出循环保证存入的是最左边的终结符
                }
            if (isupper(C[L-1]) && C[L-1] != X) {
                //若C[0]中为A~Z,并且C[]中没有终结符,则递归的进行填充
                int flag=0;
                for (int count=0; count < 20; ++count)
                    if (INPUT[count][0] == C[L-1])  //找到将要处理的产生式
                flag=1;
                if (flag == 1)  //同firstVT()
                    getLASTVT(C[L-1], S);  //S为子集中的元素填入父集中指明了方向
            }
        } else if (INPUT[T][i] != '|' && INPUT[T][i] != '\0') {  //该行没结束,过滤'\0'
           C[j] = INPUT[T][i];  //j从0开始
           j++;                 //移进
        }
        if (INPUT[T][i] == '\n')
            //该行结束
            break;
    }
}

void DisplayFirstVT_LasVT() {
    printf("\t*-------------------------------------------------------*\n");
    printf("\t|\t欢迎使用算符优先文法分析器......                |\n");
    printf("\t|\t因时间有限，适用范围可能有限！                  |\n");
    printf("\t|\t请输入算符优先文法，按两次回车代表输入完成:     |\n");
    printf("\t*-------------------------------------------------------*\n");
    for (int i=0; i < 20; ++i) {  //获得产生式放入input[][]中
        for(int j=0; j < 20; ++j) {
            scanf("%c", &INPUT[i][j]);
            if (INPUT[i][j] == '\n')
                break;            //每行接收一个产生式
        }
        if (INPUT[i][0] == '\n')
            break;                //遇到又一次回车,结束输入
    }
    //保存FIRSTVT集
    for (int i=0; INPUT[i][0] != '\n'; ++i)  //对所有的产生式
        getFIRSTVT(INPUT[i][0], i);          //第i+1个产生式求fistvt(),核心算法
    printf("FIRSTVT SET:\n");
    for (int i=0; INPUT[i][0] != '\n'; ++i) {
        //对所有产生式,进行输出fistvt集,最大处理能力20个产生式
        printf("FIRSTVT(");
        printf("%c", INPUT[i][0]);
        printf(")={");
        for (int j=0; FIRSTVT[i][j] != '\0'; ++j) {
            printf("%c", FIRSTVT[i][j]);
            if (FIRSTVT[i][j+1] != '\0')
                printf(",");  //添加逗号
        }
        printf("}\n");
    }
    printf("\n");
    for (int i=0; INPUT[i][0] != '\n'; ++i)  //对所有的产生式
        getLASTVT(INPUT[i][0], i);           //第i+1个产生式求lastvt(),核心算法
    for (int i=0; INPUT[i][0] != '\n'; ++i) {
        printf("LASTVT(");
        printf("%c", INPUT[i][0]);
        printf(")={");
        for (int j=0; LASTVT[i][j] != '\0'; ++j) {  //逐次输出
            printf("%c", LASTVT[i][j]);
            if(LASTVT[i][j+1] != '\0')
                printf(",");
        }
        printf("}\n");
   }
   printf("\n");
}