//如果已有的数据已经以二进制形式存储在一个磁盘文件stu_list中
//要求从其中读入数据并输出到stu.dat文件中
#include<stdio.h>
#define SIZE 10
struct Student_type
  {
    char name[10];
    int num;
    int age;
    char addr[15];
  }stud[SIZE];

void load()
  {
    FILE *fp;
    int i;
    if((fp=fopen("stu_list","rb"))==NULL)                      //打开输入文件stu_list
      {
        printf("cannot open infile\n");
        return;
      }
    for(i=0;i<SIZE;i++)
      if(fread(&stud[i],sizeof(struct Student_type),1,fp)!=1)  //从stu_list文件中读数据
        {
          if(feof(fp))
            {
              fclose(fp);
              return;
            }
          printf("file read error\n");
        }
     fclose(fp);
  }

void save()
  {
    FILE *fp;
    int i;
    if((fp=fopen("stu.dat","wb"))==NULL)
      {
        printf("cannot open file\n");
        return;
      }
    for(i=0;i<SIZE;i++)
      if(fwrite(&stud[i],sizeof(struct Student_type),1,fp)!=1)
        printf("file write error\n");
    fclose(fp);
  }

int main()
  {
    load();
    save();
    return 0;
  }