#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
#define M 2*N-1
void main_menu();
FILE *fp;
int n;
typedef struct 
{
	float weight;
	char data;
	int parent;
	int LChild;
	int RChild;
}HTNode,HuffmanTree[M+1];
struct codetype
{
	char data;
	char bit[N];
};

struct codetype code[N];//����������Ķ���ͱ���
struct codetype codesec[N];//��ż���������ַ����Ķ���ͱ���
struct codetype codeth[N];//����ַ����ı����Թ�����ʹ��

int writeHTData(HuffmanTree ht,int n) //д��hfmTree�ļ�(��������)
{
	int i;
	int m=2*n-1;
	if((fp=fopen("hfmTree.txt", "w"))==NULL)
	{
		return 0;
	}
	for (i=1;i<=m;i++)
	{
		fprintf(fp, "%f %c %d %d %d\n", ht[i].weight,ht[i].data,ht[i].parent,ht[i].LChild,ht[i].RChild);
	}
	fclose(fp);
	return 0;
}


int readHEData(codetype codesec[N],int n) //��ȡhfmEncoding�ļ�
{
	
	FILE *fp;
    int i;
   fp=fopen("hfmEncoding.txt","r");
   if(fp==NULL) 
   {
      return(-1);
   }
   for (i=1;i<=M;i++)
	{
		fscanf(fp, "%c %s\n",&codesec[i].data,&codesec[i].bit);
	}
   fclose(fp);
   return(0);
}
int readCFData(codetype codeth[N],int n)//��ȡCodeFile�ļ�
{
	FILE *fp;
    int i;
   fp=fopen("CodeFile.txt","r");
   if(fp==NULL) 
   {
      return(-1);
   }
   for(i=1;i<=100;i++)
   {
	   fscanf(fp,"%s\n",&codeth[i].bit);
   }
   fclose(fp);
   return(0);
}
int readTXData()//��ȡTextFile�ļ���д��CodePrint�ļ�(���ո�ʽ)
{
	int i=0;
	char ch;
	FILE *fpsec;
   fp=fopen("TextFile.txt","r");
   if(fp==NULL) 
   {
      return(-1);
   }
   if((fpsec=fopen("CodePrint.txt", "w"))==NULL)
	{
		return 0;
	}
   while((ch=fgetc(fp))!=EOF)
   {
	   printf("%c",ch);
	   fprintf(fpsec,"%c",ch);
	   i++;
	   if(i==50)
	   {
		   printf("\n");
		   fprintf(fpsec,"\n");
		   i=0;
	   }
	   
   }
   fclose(fp);
   fclose(fpsec);
   return(0);
}




void select(HuffmanTree ht,int n,int &s1,int &s2)
{
	int i,min1,min2;
    int m=2*n-1;
	for(i=1;i<=m;i++)//�ҵ���һ����Сֵ
	{
		if(ht[i].parent==0&&ht[i].weight!=0)
		{
			min1=i;
			break;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(ht[i].parent==0&&ht[i].weight<ht[min1].weight&&ht[i].weight!=0)
		{
			min1=i;
		}
		s1=min1;
	}
	for(i=1;i<=m;i++)//�ҵ��ڶ��������һ����ͬ����Сֵ
	{
		if(ht[i].parent==0&&i!=s1&&ht[i].weight!=0&&ht[i].weight!=0)
		{
			min2=i;
			break;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(ht[i].parent==0&&i!=s1)
		{
			if(ht[i].weight<ht[min2].weight&&ht[i].weight!=0)
			{
				min2=i;
			}
		}
		s2=min2;
	}
}

void CreatHuff(HuffmanTree ht,int n,float w[N],char c[N])
{
	int i,s1,s2;
	int m=2*n-1;
	for(i=1;i<=n;i++)//1-n�ų�ʼ�����Ҷ�ӽڵ�
	{
		ht[i].data=c[i];
		ht[i].weight=w[i];
		ht[i].LChild=0;
		ht[i].RChild=0;
		ht[i].parent=0;
	}
	for(i=n+1;i<=m;i++)//n+1-m�ų�ʼ����ŷ�Ҷ�ӽڵ�
	{
		ht[i].data=0;
		ht[i].weight=0;
		ht[i].LChild=0;
		ht[i].RChild=0;
		ht[i].parent=0;
	}
	for(i=n+1;i<=m;i++)
	{
		select(ht,n,s1,s2);//s1С��s2
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].LChild=s1;
		ht[i].RChild=s2;
	}
	for(i=n+1;i<=m;i++)
	{
		printf("�ϲ�Ϊ%f\n",ht[i].weight);
	}
	writeHTData(ht,n);
	main_menu();
}
int EncodingHT(HuffmanTree ht,codetype code[N],int n)//������������
{
	
	int m=2*n-1;
	int i,j,k,p,q;
	int depth[M];
	for(i=1;i<=n;i++)
	{
		p=i;
		for(j=1;ht[p].parent!=0;j++)
		{
			q=ht[p].parent;
			if(p==ht[q].LChild)
			{
				code[i].bit[j]='1';
			}
			else
			{
				code[i].bit[j]='0';
			}
			p=ht[p].parent;
			depth[i]=j;
		}
	
		printf("%c",ht[i].data);
		for(k=j;k>=1;k--)
		{
			printf("%c",code[i].bit[k]);
		}
		printf("\n");
		
	    
	}
	if((fp=fopen("hfmEncoding.txt", "w"))==NULL)  //��������д��hfmEncoding�ļ�(����Ҷ�ӽڵ�ı���)
	{
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		fprintf(fp, "%c", ht[i].data);
		for(k=depth[i];k>=1;k--)
		{
			fprintf(fp, "%c",code[i].bit[k]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	main_menu();
}
int Encoding(codetype codesec[N],int n)//����
{
	char str[100];
	int i,j,a=1;
	FILE *fpsec;
    readHEData(codesec,n);
	printf("������Ҫ���б�������:");
	fflush(stdin);
    gets(str);
	printf("�����ı���Ϊ��");
	if((fp=fopen("CodeFile.txt", "w"))==NULL)  //д��CodeFile�ļ�(�ַ����Ķ����Ʊ���)
	{
		return 0;
	}
	if((fpsec=fopen("TextFile.txt", "w"))==NULL)  //д��TextFile�ļ�
	{
		return 0;
	}
	for(i=0;i<=100;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(str[i]==codesec[j].data)
			{
				printf("%s",codesec[j].bit);
				fprintf(fp,"%s\n",codesec[j].bit);//�ӻ���д��CodeFile������ʹ��
				fprintf(fpsec,"%s",codesec[j].bit);//���ӻ���д��TextFile
			}
			
		}
	}
	fclose(fp);
	fclose(fpsec);
}
int Decoding(codetype codesec[N],int n)//����
{
	int i,j,k;
	codetype codeth[N];
	readCFData(codeth,n);
	for(i=1;i<=100;i++)
	{
		for(j=1;j<=n;j++)
		{
			k=strcmp(codeth[i].bit,codesec[j].bit);
				if(k==0)
				{
					
					break;
				}
		}
		printf("%c",codesec[j].data);
	}
	return 0;
	

}
	

void main_menu()
{
    printf("*******************************************************\n");                                                 
    printf("=                   ��������                          =\n");
    printf("=                                                     =\n");
    printf("=                 1: ������������                     =\n");
    printf("=                 2: ������������                     =\n");
    printf("=                 3: ����                             =\n");
	printf("=                 4: ����                             =\n");
	printf("=                 5: �Խ��ո�ʽ���                   =\n");
	printf("=                 6: �˳�                             =\n");
    printf("*******************************************************\n");
}




	
int main()
{
	int n,a,m,deep;
	int x=1;
	float w[N];
	char c[N];
	int choic_number; //����ѡ��
	HuffmanTree ht;
    main_menu();
	while(x)
    {
       printf("\n����ѡ��:");
       scanf("%d",&choic_number);
       
	switch(choic_number)
       {
           case 1:
			   printf("�������ַ�������");
	           scanf("%d",&n);
			   m=2*n-1;
			   for(a=1;a<=n;a++)
			   {
				   printf("�������%d���ַ��Ķ���\n",a);
		           fflush(stdin);
		           scanf("%c",&c[a]);
			   }
	           for(a=1;a<=n;a++)
			   {
				   printf("�������%d���ַ���Ȩֵ\n",a);
		           scanf("%f",&w[a]);		
			   } 
			   CreatHuff(ht,n,w,c);             break;
           
           case 2:
			   EncodingHT(ht,code,n);           break;
		   case 3: 
			   Encoding(codesec,n);             break;
		   case 4:
			   Decoding(codesec,n);             break;
		   case 5:
			   printf("�ñ���Ľ��ո�ʽΪ��\n");
			   readTXData();                    break;
		   case 6:
			   x=0;                             break;                                
           default: 
			   printf("\n��������ȷ��ѡ��!\n"); break;
       }
	}
	return 0;
}