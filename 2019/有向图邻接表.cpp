#include <stdio.h>
#include <stdlib.h>
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

typedef struct 
{
  AdjList adjlist;
  int vexnum,arcnum;
} AlGraph;                           //定义存储图信息的数据类型

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
  printf("%c",G.adjlist[i].vertex);
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
	AlGraph G;
	CreateAlGraph(G);
	printf("\n");
	Printf(G);
  getchar();
	return 0; 
}

