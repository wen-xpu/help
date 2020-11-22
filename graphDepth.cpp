#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
int visited[MAX_VERTEX_NUM];
#define TRUE 1
#define FALSE 0
typedef enum {DG,DN,UDG,UDN} GraphKind;     //DG表示有向图，DN表示有向网，UDG表示无向图，UDN表示无向网
typedef struct ArcNode
{
	int adj;
}ArcNode;
typedef struct
{
	char vertex[MAX_VERTEX_NUM];     //顶点一维数组
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //邻接矩阵
	int vexnum,arcnum;
	GraphKind kind;
}AdjMatrix;

 //求顶点位置函数
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

//创建一个有向图
int CreateDG(AdjMatrix *G)
{
	int i,j,k;
	char v1,v2;
	printf("请输入图的顶点数和弧数：");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=0;i<G->vexnum;i++) //初始化邻接矩阵
	{
		for(j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj=0;
		}
	}
	fflush(stdin);
    printf("请输入所有顶点:");	
    for(i=0;i<G->vexnum;i++)
    {
         G->vertex[i]=getchar();    //输入图的顶点
    }
    
    for (k=0;k<G->arcnum;k++)
	{
		printf("请输入一条弧的两个顶点:\n");
		fflush(stdin);
		scanf("%c,%c",&v1, &v2);  //输入一条弧的两个顶点
        i=LocateVertex(G, v1);
		j=LocateVertex(G, v2);	
		G->arcs[i][j].adj=1;
	}
	return 1;
}


//深度优先遍历v0所在的连通子图
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

//深度优先遍历图G
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
	printf("深度优先搜索图G的结果为：\n");
	TraverseGraph(&G);
	return 0;
}



