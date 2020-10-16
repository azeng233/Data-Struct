#include <stdio.h>
#include <stdlib.h>
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

typedef struct 
{
  AdjList adjlist;
  int vexnum,arcnum;
} AlGraph;                           //����洢ͼ��Ϣ����������

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
  printf("%c",G.adjlist[i].vertex);
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
	AlGraph G;
	CreateAlGraph(G);
	printf("\n");
	Printf(G);
  getchar();
	return 0; 
}

