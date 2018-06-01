/* 综合本章例9.9(建立链表的函数creat),例9.10(输出链表的函数print)
和本章习题第7题(删除链表中结点的函数del),第8题(插入结点的函数insert)
再编写一个主函数,先后调用这些函数,用以上5个函数组成一个程序
实现链表的建立,输出,删除和插入,在主函数中指定需要删除和插入的结点的数据 */
#include <stdio.h>
#include <malloc.h>

typedef struct stu
{
    int sno;
    char sname[10];
    int sco[3];
    struct stu *next;
} Student;

Student *talloc(void)
{
    return (Student *) malloc(sizeof(Student));
}

main()
{
    void creat(Student *h);
    void print(Student *h);
    void del(Student *h);
    void insert();
    void sort();/*增加排序功能*/
    void search();/*增加搜索功能*/


    Student *h, *p;
    int i, choice, *s;

    h = talloc();
    for (i = 0; i < 5; ++i) {/* 初始化一个含有5个数据的链表 */
        p = talloc();
        p -> sno = i + 100;
        p -> sname[0] = 'a' + i;
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            *s = 90;
        h -> next = p;
        h = p;
    }

    do {
        printf("1: Create a new nodelist\n");
        printf("2: Print current nodelist\n");
        printf("3: Delete one node\n");
        printf("4: Insert one node\n");
        printf("5: Sort current nodelist\n");
        printf("6: Search in nodelist\n");
        printf("0: Exit\n");
        printf("Your choice is:");
        scanf("%d", &choice);
        switch (choice) {
            case 1: creat(h), break;
            case 2: print(h), break;
            case 3: del(h), break;
        }

    } while (choice);


}

void creat(Student *h)
{
    Student *pre, *p;
    int n, i, *s;

    pre = h;
    printf("Note: This operation will eliminate the previous list\n");
    printf("Input nodelist's length n:");
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        printf("Input student %d's info:", i + 1);
        p = talloc();
        scanf("%d %s", p -> sno, p -> sname);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            scanf("%d", s);
        pre -> next = p;
        pre = p;
    }
    p -> next = NULL;
}

void print(Student *h)
{
    Student *p;
    int *s;

    p = h -> next;
    while (p) {
        printf("No.%d %s:", p -> sno, p -> sname);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            printf("  %d", *s);
        printf("\n");
        p = p -> next;
    }
}

void del(Student *h)
{
    Student *pre, *p;
    int choice = 1, findnum;
    char findname[10];

    printf("0: Stop deleting\n");
    printf("1: Delete node by student's No.(default)\n");
    printf("2: Delete node by student's name\n");
    printf("Your choice is:");
    scanf("%d", &choice);
    if (!choice)
        return;
    else if (choice == 1) {
        printf("Input No.:");
        scanf("%d", findnum)
        pre = h;
        do {
            p = p -> next;
            if (p -> sno == findnum)
                pt = p;
        } while (p -> next);


            p = p -> next;
        }




    }



}

void sort()
{
    printf("1: sort by student's No.s(default)\n");
    printf("0: sort by student's names\n");

    switch()
}