#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
int visited[MAX_VERTEX_NUM];
#define TRUE 1
#define FALSE 0
typedef enum {DG,DN,UDG,UDN} GraphKind;     //DG��ʾ����ͼ��DN��ʾ��������UDG��ʾ����ͼ��UDN��ʾ������
typedef struct ArcNode
{
	int adj;
}ArcNode;
typedef struct
{
	char vertex[MAX_VERTEX_NUM];     //����һά����
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //�ڽӾ���
	int vexnum,arcnum;
	GraphKind kind;
}AdjMatrix;

 //�󶥵�λ�ú���
int LocateVertex(AdjMatrix *G,char v)
{
	int j=-1;
	int k;
	for(k=0;k<G->vexnum;k++)
		if(G->vertex[k]==v)
		{
			j=k;
			break;
		}
		return(j);
}

//����һ������ͼ
int CreateDG(AdjMatrix *G)
{
	int i,j,k;
	char v1,v2;
	printf("������ͼ�Ķ������ͻ�����");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=0;i<G->vexnum;i++) //��ʼ���ڽӾ���
	{
		for(j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj=0;
		}
	}
	fflush(stdin);
    printf("���������ж���:");	
    for(i=0;i<G->vexnum;i++)
    {
         G->vertex[i]=getchar();    //����ͼ�Ķ���
    }
    
    for (k=0;k<G->arcnum;k++)
	{
		printf("������һ��������������:\n");
		fflush(stdin);
		scanf("%c,%c",&v1, &v2);  //����һ��������������
        i=LocateVertex(G, v1);
		j=LocateVertex(G, v2);	
		G->arcs[i][j].adj=1;
	}
	return 1;
}


//������ȱ���v0���ڵ���ͨ��ͼ
void DepthFirstSearch(AdjMatrix *G,int v0)
{
	int vj;
	printf("%c",G->vertex[v0]);
	visited[v0]=TRUE;
	for(vj=0;vj<G->vexnum;vj++)
	{
		if(!visited[vj]&&G->arcs[v0][vj].adj==1)
			DepthFirstSearch(G,vj);
	}
}

//������ȱ���ͼG
void TraverseGraph(AdjMatrix *G)
{
	int vi;
	for(vi=0;vi<G->vexnum;vi++)
	{
		visited[vi]=FALSE;
	}
	for(vi=0;vi<G->vexnum;vi++)
	{
		if(!visited[vi])
			DepthFirstSearch(G,vi);
		printf("\n");
	}
}


int main()
{
	
	AdjMatrix G;
	G.kind=DG;
	CreateDG(&G);
	printf("�����������ͼG�Ľ��Ϊ��\n");
	TraverseGraph(&G);
	return 0;
}



