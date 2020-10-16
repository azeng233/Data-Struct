#include <stdio.h>
#include <stdlib.h>
#define VEX_NUM 4
#define Num 100

typedef  char VertxType;    //定义数据元素的数据类型

typedef struct node{         //定义存储边或弧信息的单链表结点的数据类型 
int adjvex;
  struct node *next;
}EdgeNode;

typedef struct vnode{      //定义存储图结点的数据类型 
  VertxType vertex;
  EdgeNode *firstedge;
}VertexNode;

typedef VertexNode AdjList[Num];

typedef struct {
  AdjList adjlist;
  int vexnum,arcnum;
}AlGraph;                           //定义存储图信息的数据类型

int visited[VEX_NUM]={0};

void Dfs_m1(AlGraph &G, int v)
//图的深度遍历
 {
   int i;
   EdgeNode *p;
   visited[v]=1;
       printf("%3c",G.adjlist[v].vertex);
       p= G.adjlist[v].firstedge; 
      while(p)
     {
      if (visited[p->adjvex]==0 )        
	   Dfs_m1(G, p->adjvex);  
       p=p->next; 
     }  
} /*Dfs_m1*/

void DFsTraverse(AlGraph &G)
{       //整个图的深度优先遍历算法
	for(int v=0;v<G.vexnum;v++){
		for(int i=0;i<G.vexnum;i++) visited[i]=0;
	    if(!visited[v])  Dfs_m1(G,v);
	    printf("  完成此次遍历\n");
	}
}

void CreateAlGraph(AlGraph &G)
{
  int i,j,k;
  EdgeNode *s;
  printf(" 输入顶点数，边数：\n");
  scanf("%d%d",&(G.vexnum),&(G.arcnum));
  getchar();  //收回多余输入字符 
  printf("   输入顶点信息  \n");
for(i=0;i<G.vexnum;i++)
{
  scanf("%c",&(G.adjlist[i].vertex));
  printf("%-5c",G.adjlist[i].vertex);
  G.adjlist[i].firstedge=NULL;
}
printf("\n边数=%d\n",G.arcnum);
printf("   \n边的信息 \n");
getchar();   //收回多余输入字符
 //for(k=0;k<2*G.arcnum;k++) //用于无向图 
 for(k=0;k<G.arcnum;k++)//用于创建有向图 
    {
	scanf("%d%d",&i,&j);
	s=(EdgeNode*)malloc(sizeof(EdgeNode));
	s->adjvex=j;
	s->next=G.adjlist[i].firstedge;
	G.adjlist[i].firstedge=s;
   }
}

void Printf(AlGraph &G)
{
    int i;
    EdgeNode *p;
    for(i=0;i<G.vexnum;i++)
    {  
     printf("%-5c",G.adjlist[i].vertex);
     p=G.adjlist[i].firstedge;
      while(p)
	  {
	     printf("%-3d",p->adjvex);
         p=p->next;
	  }
     printf("\n");
   }
}

int main()
{
	int v=0;
	AlGraph G;
	CreateAlGraph(G);
	printf("\n");
	Printf(G);
	printf("\n");
	printf("深度优先遍历的结果是：\n");
	DFsTraverse(G);
	//Dfs_m1(G,0);
	return 0; 	
}
