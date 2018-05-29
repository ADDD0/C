/* 已有a,b两个链表,每个链表中的结点包括学号,成绩
要求把两个链表合并,按学号升序排列                */
#include <stdio.h>
#include <malloc.h>

typedef struct stu
{
    int sno;
    int sco[3];
    struct stu *next;
} Student;

Student *talloc(void)
{
    return (Student *) malloc(sizeof(Student));
}

main()
{
    Student *a, *b, *pre, *p, *t, **t1, **t2;
    int i, *s;

    pre = a = talloc();
    for (i = 0; i < 5; ++i) {
        p = talloc();
        p -> sno = i + 100;
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            *s = 90;
        pre -> next = p;
        pre = p;
    }
    pre -> next = NULL;
    pre = b = talloc();
    for (i = 0; i < 3; ++i) {
        p = talloc();
        p -> sno = i + 200;
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            *s = 100;
        pre -> next = p;
        pre = p;
    }                         /* 这之前均为a,b链表的初始化 */
	printf("Ok\n");
    pre -> next = a -> next;/* 此时b链表的尾部连接到a链表的头部 */	
    for (pre = b -> next; pre -> next -> next; ++pre) {
		printf("No.%5d:\n", pre -> sno);
		for (p = pre; p -> next -> next; ++p) {
			printf("No.%10d:\n", p -> next -> sno);
            if (p -> sno > p -> next -> sno) {
				t1 = &p;
				t2 = &p -> next;
				t = *t1;
				*t1 = *t2;
				*t2 = t;
			}
                
			/* 借助二重指针交换地址(也可以使用交换数值的方法), */
        }
	}
        
    p = b -> next;
    while (p) {
        printf("No.%d:", p -> sno);
        for (s = p -> sco;  s < p -> sco + 3; ++s)
            printf("  %d", *s);
        printf("\n");
        p = p -> next;
    }
}