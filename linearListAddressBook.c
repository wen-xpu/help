
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define MaxSize 100
 
typedef struct 
{
    char name[20];
    char tel[15];
} ElemType;
typedef struct 
{
    ElemType data[MaxSize];
     int length;
} SqList;
 
void InitList(SqList *&L) //初始化线性表
{
    L=(SqList *)malloc(sizeof(SqList));    //分配存放线性表的空间
    L->length=0;                     //置空线性表长度为0
}
 
void DispList(SqList *L)  //输出线性表
{
    int i;
    printf("  NO           NAME           TEL   \n");
    for (i=0;i<L->length;i++)
    {
        printf("  %d           %s      %s",i+1,L->data[i].name,L->data[i].tel);
        printf("\n");
        //fflush(stdin); 
    }
 
    printf("目前联系人总数：%d\n",L->length);
        printf("\n"); 
}
 
bool ListInsert(SqList *&L,int i,ElemType e)    //插入数据元素
{
    int j;
    if(e.name=="\0") return false;
    if (i<1 || i>L->length+1)
        return false;          //参数错误时返回false
    i--;                        //将顺序表逻辑序号转化为物理序号
    for (j=L->length;j>i;j--)    //将data[i]及后面元素后移一个位置
      L->data[j]=L->data[j-1];
        
    L->data[i]=e;                //插入元素e
    L->length++;             //顺序表长度增1
    //printf("length=%d\n\n",L->length);
    return true;               //成功插入返回true
}
 
bool ListDelete(SqList *&L,int i,ElemType &e)   //删除数据元素
{
    int j;
    if (i<1 || i>L->length)     //参数错误时返回false
        return false;
    i--;                        //将顺序表逻辑序号转化为物理序号
    e=L->data[i];
    for (j=i;j<L->length-1;j++)  //将data[i]之后的元素前移一个位置
    {  L->data[j]=L->data[j+1];
       }
    L->length--;
    printf("length=%d\n\n",L->length);       
    return true;               //成功删除返回true
}
 
void menu1()
{ printf("       ----------------------------------\n");
  printf("           手机通讯录的应用(顺序表)\n");
  printf("       ----------------------------------\n");
  printf("            1.增加联系人信息\n");
  printf("            2.删除联系人信息\n");
  printf("            3.查找联系人信息\n");
  printf("            4.退出通讯录\n");
  printf("       ----------------------------------\n\n");
}

int LocateElem_name(SqList *&L,ElemType &e)
  {   int i=0;

    while ( i<L->length && strcmp(L->data[i].name,e.name)!=0)
       i++;
    if ( i>=L->length )  
        return 0;
    else 
    {  puts(L->data[i].name);
       puts(L->data[i].tel);
        printf("%s,%s\n",L->data[i].name,L->data[i].tel);
        return( i+1 );
  }
 
}
int LocateElem_tel(SqList *&L,ElemType &e)
  {   int i=0;

    while ( i<L->length && strcmp(L->data[i].tel,e.tel)!=0)
       i++;
    if ( i>=L->length )  
        return 0;
    else 
    {  puts(L->data[i].name);
       puts(L->data[i].tel);
        printf("%s,%s\n",L->data[i].name,L->data[i].tel);
        return( i+1 );
  }
 
}
void search(SqList*L)

{ ElemType e;
    SqList *L;

	int select;
 int i = 0, sum = 0;

	printf("***************************************************\n");

	printf("  1、按姓名查询  2、按电话号码查询\n");

	printf("***************************************************\n");

	printf("请输入查询方式:");

	scanf("%d", &select);

	if (select == 1)
	{printf("请输入联系人姓名：");
scanf("%s",&e.name);

LocateElem_name(L,e);}

	else if (select == 2)
	{	printf("请输入联系人号码：");
scanf("%s",&e.tel);

LocateElem_tel(L,e);}
	else

	{

		printf("请重新选择\n");

		

		search(L);

	}

}
 
void main()
{
    
    int flag=1;
    int  j,i;
    ElemType e;
    SqList *L;
   menu1();
    InitList(L);
     
         
    while(flag==1)
    { DispList(L); 
      printf("请选择：");
      scanf("%d",&j);
      switch(j)
      {  
      case 1: printf("请输入联系人姓名和电话号：");   
                scanf("%s %s",e.name,e.tel);
              printf("请输入插入数据的位置："); 
              scanf("%d",&i);
               fflush(stdin); 
                printf("\n");
               ListInsert(L,i,e);
                break;
     
      case 2:  printf("请输入删除数据的位置："); 
               scanf("%d",&i);
               ListDelete(L,i,e);
               break;
       case 3:  search(L);
                 break;
       case 4:  flag=0;
                printf("\n    不再输入记录,退出！！\n\n");
                break;
 
      }
    }
 
}