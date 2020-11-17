#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int code;
    int password;
}Elemtype;

typedef struct Node
{
    Elemtype data;
    struct Node* next;
}Node,LinkList;

int CreateCLinkList(LinkList *&L,int n)
{

    Node *s,*r;
    int p,c;
    L=(Node*)malloc(sizeof(Node));
    r=L;
    
    for(c=1;c<=n;c++)
    {
        s=(Node*)malloc(sizeof(Node));
        printf("请输入当前第%d人的密码:\n",c);
        scanf("%d",&p);
        s->data.code = c;
        s->data.password = p;
        r->next = s;
        r=s;
        r->next=L->next;
    }
    
    return 0;
}


int DelNode(LinkList *L,int n)
{
    int m,i;
    Node *q,*f; 
    printf("请输入初始报数上限:\n");
    scanf("%d",&m);
    q=L ;
	
while(n>1)
	{ 
	for(i=1;i<m;i++)
        q=q->next;
	    f=q->next;
        q->next=f->next;
	    m=f->data.password;
        printf("%d",f->data .code );
        free(f);
        
			
	
	}
    
return 0;
}


void main()
{
	int n;
    LinkList *L;
    printf("请输入参加人数:\n");
    scanf("%d",&n);
    CreateCLinkList(L,n);
    DelNode(L,n);
}
