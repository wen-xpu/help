#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	char data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &root)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='*')
		root=NULL;
	else
	{
		root=(BiTNode*)malloc(sizeof(BiTNode));
		root->data=ch;
		CreateBiTree(root->LChild);
		CreateBiTree(root->RChild);
	}
}
void PreOrder(BiTree root)     //�������������
{
	if(root!=NULL)
	{
		printf("%c",root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
}
void InOrder(BiTree root)      //�������������
{
	if(root!=NULL)
	{
		InOrder(root->LChild);
		printf("%c",root->data);
		InOrder(root->RChild);
	}
}
void PostOrder(BiTree root)     //�������������
{
	if(root!=NULL)
	{
		PostOrder(root->LChild);
		PostOrder(root->RChild);
		printf("%c",root->data);
	}
}
int main()
{
	BiTree root;
	printf("�����������������:");
	CreateBiTree(root);
	PreOrder(root);
	printf("�������\n");
	InOrder(root);
    printf("�������\n");
	PostOrder(root);
	printf("�������\n");
		
	
	return 0;
}




