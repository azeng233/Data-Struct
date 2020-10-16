#include <stdio.h>
#include <stdlib.h>
#define VEX_NUM 4
#define Num 100

typedef  char VertxType;    //��������Ԫ�ص���������

typedef struct node{         //����洢�߻���Ϣ�ĵ���������������� 
int adjvex;
  struct node *next;
}EdgeNode;

typedef struct vnode{      //����洢ͼ������������ 
  VertxType vertex;
  EdgeNode *firstedge;
}VertexNode;

typedef VertexNode AdjList[Num];

typedef struct {
  AdjList adjlist;
  int vexnum,arcnum;
}AlGraph;                           //����洢ͼ��Ϣ����������

int visited[VEX_NUM]={0};

void Dfs_m1(AlGraph &G, int v)
//ͼ����ȱ���
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
{       //����ͼ��������ȱ����㷨
	for(int v=0;v<G.vexnum;v++){
		for(int i=0;i<G.vexnum;i++) visited[i]=0;
	    if(!visited[v])  Dfs_m1(G,v);
	    printf("  ��ɴ˴α���\n");
	}
}

void CreateAlGraph(AlGraph &G)
{
  int i,j,k;
  EdgeNode *s;
  printf(" ���붥������������\n");
  scanf("%d%d",&(G.vexnum),&(G.arcnum));
  getchar();  //�ջض��������ַ� 
  printf("   ���붥����Ϣ  \n");
for(i=0;i<G.vexnum;i++)
{
  scanf("%c",&(G.adjlist[i].vertex));
  printf("%-5c",G.adjlist[i].vertex);
  G.adjlist[i].firstedge=NULL;
}
printf("\n����=%d\n",G.arcnum);
printf("   \n�ߵ���Ϣ \n");
getchar();   //�ջض��������ַ�
 //for(k=0;k<2*G.arcnum;k++) //��������ͼ 
 for(k=0;k<G.arcnum;k++)//���ڴ�������ͼ 
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
	printf("������ȱ����Ľ���ǣ�\n");
	DFsTraverse(G);
	//Dfs_m1(G,0);
	return 0; 	
}
