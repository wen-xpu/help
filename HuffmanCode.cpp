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

struct codetype code[N];//存放整个数的顶点和编码
struct codetype codesec[N];//存放即将编码的字符串的顶点和编码
struct codetype codeth[N];//存放字符串的编码以供译码使用

int writeHTData(HuffmanTree ht,int n) //写入hfmTree文件(哈夫曼树)
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


int readHEData(codetype codesec[N],int n) //读取hfmEncoding文件
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
int readCFData(codetype codeth[N],int n)//读取CodeFile文件
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
int readTXData()//读取TextFile文件并写入CodePrint文件(紧凑格式)
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
	for(i=1;i<=m;i++)//找到第一个最小值
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
	for(i=1;i<=m;i++)//找到第二个不与第一个相同的最小值
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
	for(i=1;i<=n;i++)//1-n号初始化存放叶子节点
	{
		ht[i].data=c[i];
		ht[i].weight=w[i];
		ht[i].LChild=0;
		ht[i].RChild=0;
		ht[i].parent=0;
	}
	for(i=n+1;i<=m;i++)//n+1-m号初始化存放非叶子节点
	{
		ht[i].data=0;
		ht[i].weight=0;
		ht[i].LChild=0;
		ht[i].RChild=0;
		ht[i].parent=0;
	}
	for(i=n+1;i<=m;i++)
	{
		select(ht,n,s1,s2);//s1小于s2
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].LChild=s1;
		ht[i].RChild=s2;
	}
	for(i=n+1;i<=m;i++)
	{
		printf("合并为%f\n",ht[i].weight);
	}
	writeHTData(ht,n);
	main_menu();
}
int EncodingHT(HuffmanTree ht,codetype code[N],int n)//创建哈夫曼表
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
	if((fp=fopen("hfmEncoding.txt", "w"))==NULL)  //哈夫曼表写入hfmEncoding文件(各个叶子节点的编码)
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
int Encoding(codetype codesec[N],int n)//编码
{
	char str[100];
	int i,j,a=1;
	FILE *fpsec;
    readHEData(codesec,n);
	printf("请输入要进行编码的语句:");
	fflush(stdin);
    gets(str);
	printf("该语句的编码为：");
	if((fp=fopen("CodeFile.txt", "w"))==NULL)  //写入CodeFile文件(字符串的二进制编码)
	{
		return 0;
	}
	if((fpsec=fopen("TextFile.txt", "w"))==NULL)  //写入TextFile文件
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
				fprintf(fp,"%s\n",codesec[j].bit);//加换行写入CodeFile供译码使用
				fprintf(fpsec,"%s",codesec[j].bit);//不加换行写入TextFile
			}
			
		}
	}
	fclose(fp);
	fclose(fpsec);
}
int Decoding(codetype codesec[N],int n)//译码
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
    printf("=                   哈夫曼树                          =\n");
    printf("=                                                     =\n");
    printf("=                 1: 创建哈夫曼树                     =\n");
    printf("=                 2: 创建哈夫曼表                     =\n");
    printf("=                 3: 编码                             =\n");
	printf("=                 4: 译码                             =\n");
	printf("=                 5: 以紧凑格式输出                   =\n");
	printf("=                 6: 退出                             =\n");
    printf("*******************************************************\n");
}




	
int main()
{
	int n,a,m,deep;
	int x=1;
	float w[N];
	char c[N];
	int choic_number; //命令选择
	HuffmanTree ht;
    main_menu();
	while(x)
    {
       printf("\n输入选项:");
       scanf("%d",&choic_number);
       
	switch(choic_number)
       {
           case 1:
			   printf("请输入字符个数：");
	           scanf("%d",&n);
			   m=2*n-1;
			   for(a=1;a<=n;a++)
			   {
				   printf("请输入第%d个字符的顶点\n",a);
		           fflush(stdin);
		           scanf("%c",&c[a]);
			   }
	           for(a=1;a<=n;a++)
			   {
				   printf("请输入第%d个字符的权值\n",a);
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
			   printf("该编码的紧凑格式为：\n");
			   readTXData();                    break;
		   case 6:
			   x=0;                             break;                                
           default: 
			   printf("\n请输入正确的选择!\n"); break;
       }
	}
	return 0;
}