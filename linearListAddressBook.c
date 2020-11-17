
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
 
void InitList(SqList *&L) //��ʼ�����Ա�
{
    L=(SqList *)malloc(sizeof(SqList));    //���������Ա�Ŀռ�
    L->length=0;                     //�ÿ����Ա���Ϊ0
}
 
void DispList(SqList *L)  //������Ա�
{
    int i;
    printf("  NO           NAME           TEL   \n");
    for (i=0;i<L->length;i++)
    {
        printf("  %d           %s      %s",i+1,L->data[i].name,L->data[i].tel);
        printf("\n");
        //fflush(stdin); 
    }
 
    printf("Ŀǰ��ϵ��������%d\n",L->length);
        printf("\n"); 
}
 
bool ListInsert(SqList *&L,int i,ElemType e)    //��������Ԫ��
{
    int j;
    if(e.name=="\0") return false;
    if (i<1 || i>L->length+1)
        return false;          //��������ʱ����false
    i--;                        //��˳����߼����ת��Ϊ�������
    for (j=L->length;j>i;j--)    //��data[i]������Ԫ�غ���һ��λ��
      L->data[j]=L->data[j-1];
        
    L->data[i]=e;                //����Ԫ��e
    L->length++;             //˳�������1
    //printf("length=%d\n\n",L->length);
    return true;               //�ɹ����뷵��true
}
 
bool ListDelete(SqList *&L,int i,ElemType &e)   //ɾ������Ԫ��
{
    int j;
    if (i<1 || i>L->length)     //��������ʱ����false
        return false;
    i--;                        //��˳����߼����ת��Ϊ�������
    e=L->data[i];
    for (j=i;j<L->length-1;j++)  //��data[i]֮���Ԫ��ǰ��һ��λ��
    {  L->data[j]=L->data[j+1];
       }
    L->length--;
    printf("length=%d\n\n",L->length);       
    return true;               //�ɹ�ɾ������true
}
 
void menu1()
{ printf("       ----------------------------------\n");
  printf("           �ֻ�ͨѶ¼��Ӧ��(˳���)\n");
  printf("       ----------------------------------\n");
  printf("            1.������ϵ����Ϣ\n");
  printf("            2.ɾ����ϵ����Ϣ\n");
  printf("            3.������ϵ����Ϣ\n");
  printf("            4.�˳�ͨѶ¼\n");
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

	printf("  1����������ѯ  2�����绰�����ѯ\n");

	printf("***************************************************\n");

	printf("�������ѯ��ʽ:");

	scanf("%d", &select);

	if (select == 1)
	{printf("��������ϵ��������");
scanf("%s",&e.name);

LocateElem_name(L,e);}

	else if (select == 2)
	{	printf("��������ϵ�˺��룺");
scanf("%s",&e.tel);

LocateElem_tel(L,e);}
	else

	{

		printf("������ѡ��\n");

		

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
      printf("��ѡ��");
      scanf("%d",&j);
      switch(j)
      {  
      case 1: printf("��������ϵ�������͵绰�ţ�");   
                scanf("%s %s",e.name,e.tel);
              printf("������������ݵ�λ�ã�"); 
              scanf("%d",&i);
               fflush(stdin); 
                printf("\n");
               ListInsert(L,i,e);
                break;
     
      case 2:  printf("������ɾ�����ݵ�λ�ã�"); 
               scanf("%d",&i);
               ListDelete(L,i,e);
               break;
       case 3:  search(L);
                 break;
       case 4:  flag=0;
                printf("\n    ���������¼,�˳�����\n\n");
                break;
 
      }
    }
 
}