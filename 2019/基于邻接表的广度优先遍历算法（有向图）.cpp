#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 //�����г���
#define N 5
#define VEX_NUM 4
#define Num 100

 typedef int ElemType;
 
 typedef struct{
 	ElemType data[MAXSIZE];
 	int  front , rear;
 }SqQueue;
 
 typedef  char VertxType;    //��������Ԫ�ص���������

 typedef struct node{         //����洢�߻���Ϣ�ĵ����������������� 
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
 
 void InitQueue(SqQueue *Sq)
 {
 	Sq->rear = Sq->front = 0;
 }
 
 int QueueEmpty(SqQueue *Sq) //�ж϶ӿ�
 {
 	return((Sq->rear == Sq->front )?1:0);
 } 
 
 int Enequeue(SqQueue *Sq,ElemType x) //���
 {
 	if(Sq->rear > MAXSIZE)
 	{
 		printf("\n Queue is full!");
 		return 0;
	}
	else{
		Sq->data[Sq->rear]=x;
		Sq->rear++;
		return 1; 
	}
 }
 
 int DelQueue(SqQueue *Sq,ElemType *y) //��ͷɾ������������ͷָ��front��1 
 {
 	if(Sq->front == Sq->rear )
	 {
	 	printf("Queue is empty!");
	 	return 0;
	 } 
	 else{
	 	*y=Sq->data[Sq->front];
	 	Sq->front++;
	 	return 1;
	 }
 } 
 
 void Bfs(AlGraph &G,int v){
    EdgeNode *p;
    SqQueue * Q=(SqQueue *)malloc(sizeof(SqQueue)); 
     //ʹ�ö��нṹ�洢������Ϣ
    InitQueue(Q);
    printf("%3c",G.adjlist[v].vertex);
     visited[v] = 1;
     Enequeue(Q,v);
     while(!QueueEmpty(Q)){      //�������
		 DelQueue(Q,&v);
		 p= G.adjlist[v].firstedge; 
		 while(p){
			 if(!visited[p->adjvex])
			 { 
			     printf("%3c",G.adjlist[p->adjvex].vertex);
			     visited[p->adjvex] = 1;
			     Enequeue(Q,v);
			 }
			 p=p->next;
		 }
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
	Bfs(G,0);
	getchar();
	system("pause");
	return 0;
}

