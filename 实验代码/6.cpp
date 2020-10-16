#include <stdio.h>
#include <stdlib.h>
#define VEX_NUM 4
#define MAXSIZE 100 //最大队列长度
#define N 5
#define Num 100

typedef char Vextype;

typedef int ElemType;

typedef struct{
 	ElemType data[MAXSIZE];
 	int  front , rear;
}SqQueue;

void InitQueue(SqQueue *Sq)
 {
 	Sq->rear = Sq->front = 0;
 }
 
 int QueueEmpty(SqQueue *Sq) //判断队空
 {
 	return((Sq->rear == Sq->front )?1:0);
 } 
 
 int Enequeue(SqQueue *Sq,ElemType x) //入队
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
 
 int DelQueue(SqQueue *Sq,ElemType *y) //队头删除操作，即将头指针front加1 
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

typedef struct 
{
   Vextype vexs[VEX_NUM];
   int  arcs[VEX_NUM][VEX_NUM];
} Mgraph;

int visited[VEX_NUM]={0};

void creat_Mgraph(Mgraph *G,int e)
{
	int i,j,k;
    for(i=0;i<VEX_NUM;i++)
	 scanf("%c",&G->vexs[i]);
      for(i=0;i<VEX_NUM;i++)
		  for(j=0;j<VEX_NUM;j++)
			  G->arcs[i][j]=0;
      for(k=0;k<e;k++)
		{
			scanf("%d%d",&i,&j);
            G->arcs[i][j]=1;G->arcs[j][i]=1;
		}
}

void output(Mgraph *G)
{
	int i,j;
	for(i=0;i<VEX_NUM;i++)
	 printf("%3c",G->vexs[i]);
	printf("\n");
     for(i=0;i<VEX_NUM;i++) 
	 {
	    for(j=0;j<VEX_NUM;j++)
			printf("%3d",G->arcs[i][j]);
	    printf("\n");
	 }
}

void Bfs(Mgraph *G, int i)
{  
  SqQueue * Q=(SqQueue *)malloc(sizeof(SqQueue));
    int j;
     InitQueue(Q);
    printf("%c",G->vexs[i] );
     visited[i] = 1;
     Enequeue(Q,i);
     while(!QueueEmpty(Q)){
        DelQueue(Q,&i);
       for(j=0;j<VEX_NUM;j++)
       {
       if (G->arcs[i][j] ==1&& !visited[j] ) 
       {      printf("%c",G->vexs[j]);
           visited[j] = 1;
           Enequeue(Q,j);  
        }
   }
 }
}


void Dfs_m(Mgraph *G, int i)
 {
 	int j;
   printf("%c",G->vexs[i] );
   visited[i] = 1; 
   for(j=0;j<VEX_NUM;j++)
   if (G->arcs[i][j] ==1 && !visited[j] )        
	 Dfs_m(G, j);     
}

int main()
{
	Mgraph *G;
	int e,i;
	printf("请输入边数e的值和%d个顶点:\n",VEX_NUM);
	scanf("%d",&e);
	getchar();
	
	G=(Mgraph*)malloc(sizeof(Mgraph));
	
	creat_Mgraph(G,e);
	printf("\n邻接矩阵为：\n");
	output(G);
	
	printf("深度优先遍历的结果是：\n");
	Dfs_m(G,0);
	for(i=0;i<VEX_NUM;i++)
	visited[i]=0;
	printf("\n广度优先遍历的结果是：\n");
	Bfs(G,0);
  system("pause");
	return 0;
}