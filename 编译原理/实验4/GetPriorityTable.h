//此分程序主要是计算优先关系表
//优先分析表是算符优先文法的关键,因此应该慎重对待
//如何建表,建什么类型的表,表的使用是不是方便都是我们要考虑的情况

extern char FIRSTVT[20][20];
extern char LASTVT[20][20];
extern char PriorityTable[20][20];
extern char INPUT[20][20];

int IsVT(char ch) {  //判断是否是终结符
    if (islower(ch) || ch == '+' || ch == '*' || ch == '-'
    || ch== '/' || ch == '!' || ch == '(' || ch == ')' ||
    ch == '#' || ch == '\?' || ch == '=')
        return 1;    //为终结符
    return 0;        //不是终结符
}

int SearchTbl(char ch) {  //返回符号所在的行列
    int index=-1;
    //该排列即为优先关系表中元素的排列情况
    //行和列的排列相同便于查找和引用
    //因此即可以查行又可以查列
    char temp[13]={ '+', '-', '*', '/', '(', ')', 'v', 'c', '=', '?', '#', '\0' };
    for (int i=0; i < 11; ++i)
        if (ch == temp[i]) {
           index = i + 1;
           break;
        }
    return index;         //返回所查找的横(纵)坐标
}

int FL_map(char ch) {               //这个映射既是查找产生式左部的位置
    switch(ch) {
        case 'S': return 0; break;
        case 'E': return 1; break;
        case 'T': return 2; break;
        case 'F': return 3; break;
        default: return -1; break;  //查找失败
    }
}

void createPriorityTable() {              //创建并填写优先级表
    //对每个产生式遍历,求出四种关系1.=,2.<,3.>,4.没有关系
    char temp[13]={ '+', '-', '*', '/', '(', ')', 'v', 'c', '=', '?', '#', '\0' };
    int j, L;
    int tbl_row, tbl_column;              //表的元素坐标
    char C[20];
    for (int r=1; r < 12; ++r) {
        PriorityTable[0][r] = temp[r-1];  //初始化行头,第0行
        PriorityTable[r][0] = temp[r-1];  //初始化第0列
    }
    //扫描产生式的右部,如果发现终结符且该终结符周围有其他字符
    //若该其他字符为终结符,则这两者关系为相等
    //若该其他字符为非终结符,则根据非终结符的firstVT,LastVt填表
    for (int p=0; p < 4; ++p) {
        j = 0;
        for (int i=4; i < 20; ++i) {
            if (INPUT[p][i] == '|' || INPUT[p][i] == '\n') {  //刚开始走不到这里
                L = j;      //j指针所指位置为C[]中字符串的长度
                j = 0;      //交给L后就清零,以供下一次使用
                if (L > 1)  //大于一则处理,否则不关心
                    //对于清零指令l自动忽略
                    if(IsVT(C[0]) && IsVT(C[1]) || L == 3 && IsVT(C[0]) && IsVT(C[2]) && FL_map(C[1]) != -1) {
                        tbl_row = SearchTbl(C[0]);                 //记录行数
                        if (IsVT(C[1]))
                            tbl_column = SearchTbl(C[1]);
                        if (IsVT(C[2]) && L==3)
                            tbl_column = SearchTbl(C[2]);
                        PriorityTable[tbl_row][tbl_column] = '=';  //填表
                        if (L == 3 && IsVT(C[0]) && IsVT(C[1]) && FL_map(C[2]) != -1) {
                            //v=E,这种情况
                            int count_1=0;
                            char temp_column;
                            tbl_row=SearchTbl(C[1]);  //=<firstVT(E)
                            while (FIRSTVT[FL_map(C[2])][count_1] != '\0') {  //填写小于关系
                                temp_column = FIRSTVT[FL_map(C[2])][count_1];
                                tbl_column = SearchTbl(temp_column);       //将上述结果再次转换
                                PriorityTable[tbl_row][tbl_column] = '<';  //填写关系
                                count_1++;  //准备填写下一个
                            }
                            count_1 = 0;              //清零
                        }
                        if (L == 3 && IsVT(C[0]) && IsVT(C[2]) && FL_map(C[1]) != -1) {
                            char temp_row, temp_column;
                            int reg=0;
                            tbl_row=SearchTbl(C[0]);
                            while (FIRSTVT[FL_map(C[1])][reg] != '\0') {
                                //填写小于关系 '('<firstVT(E)
                                temp_column = FIRSTVT[FL_map(C[1])][reg];
                                tbl_column = SearchTbl(temp_column);
                                PriorityTable[tbl_row][tbl_column] = '<';
                                reg++;
                            }
                            reg = 0;  //清零
                            tbl_column = SearchTbl(C[2]);
                            while (LASTVT[FL_map(C[1])][reg] != '\0') {
                                //填写大于关系 lastVT(E)>')'
                                temp_row = LASTVT[FL_map(C[1])][reg];
                                tbl_row = SearchTbl(temp_row);
                                PriorityTable[tbl_row][tbl_column] = '>';
                                reg++;
                            }
                            reg = 0;  //reset
                        }
                    } else if (FL_map(C[0]) != -1 && IsVT(C[1])) {
                        //C[0]肯定为非终结符lastVT(C[0])>C[1]
                        //填写大于关系
                        char temp_row, temp_column;
                        int count=0;
                        tbl_column = SearchTbl(C[1]);
                        while (LASTVT[FL_map(C[0])][count] != '\0') {
                            //填写大于关系
                            temp_row = LASTVT[FL_map(C[0])][count];
                            tbl_row = SearchTbl(temp_row);
                            PriorityTable[tbl_row][tbl_column] = '>';
                            count++;
                        }
                        count = 0;
                        if (L == 3) {
                            //在这种情况下C[2]必为非终结符,求C[2]的firstVT(),填写小于关系
                            //E+T,E-T,T*F,T/F等情况
                            tbl_row = SearchTbl(C[1]);
                            while (FIRSTVT[FL_map(C[2])][count] != '\0') {
                                //填写小于关系
                                temp_column = FIRSTVT[FL_map(C[2])][count];
                                tbl_column = SearchTbl(temp_column);
                                PriorityTable[tbl_row][tbl_column] = '<';
                                count++;
                            }
                            count = 0;
                        }
                    }
            } else if (INPUT[p][i] != '|' && INPUT[p][i] != '\0') {  //该行没结束,过滤'\0'
                C[j] = INPUT[p][i];  //j从0开始
                j++;                 //移进
            }
            if (INPUT[p][i] == '\n')
                //该行结束
                break;
        }
    }
    //补上#的关系
    for (int m1=1; m1 < 11; ++m1)
        PriorityTable[SearchTbl('#')][m1] = '<';  //补行
    for (int m2=1; m2 < 11; ++m2)
        PriorityTable[m2][SearchTbl('#')] = '>';  //补列
    PriorityTable[SearchTbl('#')][SearchTbl('#')] = '=';
}

void DisplayPriorityTable() {
    //显示优先关系表查看是否正确
    printf("构造的算符优先关系表如下:\n");
    for (int i=0; i < 12; ++i) {
        for (int j=0; j < 12; ++j)
            printf("%c ", PriorityTable[i][j]);
        printf("\n");
    }
}