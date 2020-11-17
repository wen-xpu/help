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
void PreOrder(BiTree root)     //先序遍历二叉树
{
	if(root!=NULL)
	{
		printf("%c",root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
}
void InOrder(BiTree root)      //中序遍历二叉树
{
	if(root!=NULL)
	{
		InOrder(root->LChild);
		printf("%c",root->data);
		InOrder(root->RChild);
	}
}
void PostOrder(BiTree root)     //后序遍历二叉树
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
	printf("请输入二叉树的内容:");
	CreateBiTree(root);
	PreOrder(root);
	printf("先序输出\n");
	InOrder(root);
    printf("中序输出\n");
	PostOrder(root);
	printf("后序输出\n");
		
	
	return 0;
}




