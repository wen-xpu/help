#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 50
typedef struct
{
	char elem[Stack_Size];
	int top;
}SeqStack;
void InitStack(SeqStack *&S)     //栈的初始化
{
	S=(SeqStack *)malloc(sizeof(SeqStack));
	S->top = -1;
}
int Push(SeqStack *S,char str[100],int i)     //进栈
{
	    int a;
		if(S->top==Stack_Size-1)
		return false;
	    for(a=0;a<i;a++)
		{
			S->top++;
    	    S->elem[S->top] = str[a];
	    }
	    return true;
}

char TakeOut(SeqStack *S)    //出栈
{
	char y;
	if(S->top==-1)
		return false;
	else
	{
		y = S->elem[S->top];
		S->top--;
		return y;
	}
}
int Judge(SeqStack *S,char str[100],int i)
{
	int j;
    char y;
	bool x=true;
	for(j=0;j<i;j++)
	{
		y=TakeOut(S);
		if(y!=str[j])
		{
			x=false;
		     break;
		}
	}
	if(x==true)
		printf("此序列是回文序列");
	else	
		printf("此序列不是回文序列");
	return 0;

}
int judgeLegal(char str[100])
{
	int count=0;
	int j;
	int k=0;
	char c;
	int flag=1;
	printf("请输入需要判断的字符序列：\n");
    
	while(flag)
	{
		while((c=getchar())!='@')
		{
		   str[k]=c;
	       k++;
		}fflush(stdin);
		for(j=0;j<k;j++)
		{
			if(str[j]=='&')
				count++;
		}
		if(count!=1)
		{ 
			
			printf("输入错误，只能输入一个‘&’\n");
		    for(j=0;j<100;j++)
			str[j]='\0';
			k=judgeLegal(str);
			return(k);
		}
		else flag=0;
		
	}
return(k);
}
	



int main()
{
	int i,k;
	char str[100];
	SeqStack *S;
    i=judgeLegal(str);
	InitStack(S);
	Push(S,str,i);
	Judge(S,str,i);
	return 0; 
}