#include <stdio.h>
#include <stdlib.h>
#define VEX_NUM 4

typedef char Vextype;

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

void Dfs_m(Mgraph *G, int i)
 {
 	int j;
   printf("%c",G->vexs[i] );
   visited[i] = 1; 
   for(j=0;j<VEX_NUM;j++)
   if (G->arcs[i][j] ==1 && !visited[j] )        
	 Dfs_m(G, j);     
} /*Dfs_m*/

int main()
{
	Mgraph *G;
	int e,i;
	printf("请输入边数e的值和%d个顶点:\n",VEX_NUM);
	scanf("%d",&e);
	getchar();
	
	G=(Mgraph*)malloc(sizeof(Mgraph));
	
	creat_Mgraph(G,e);
	output(G);
	printf("深度优先遍历的结果是：\n");
	Dfs_m(G,0);
}
