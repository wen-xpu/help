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

int main()
{
	int i=0;
    int count=0;
	int j;
	int flag=1;
	char c;
	char str[100];
	SeqStack *S;
	while(flag)
	{
		printf("请输入需要判断的字符序列：\n");
        while((c=getchar())!='@')
		{
		   str[i]=c;
	       i++;
		}fflush(stdin);
		for(j=0;j<i;j++)
		{
			if(str[j]=='&')
				count++;
		}
		if(count!=1)
		{ 
			i=0;
			printf("输入错误，只能输入一个‘&’\n");
		count = 0; 
		continue;
		for(j=0;j<100;j++)
			str[j]='\0';
		
		}
		else
		{
			flag=0;
			count=0;
		}
		
	}
	InitStack(S);
	Push(S,str,i);
	Judge(S,str,i);
	return 1;
		
}