#include <stdio.h>
#include <stdlib.h>
#define INFINITE  100
#define MAXV 4
#define Num 100

typedef char Vextype;

typedef struct 
{
    Vextype vexs[MAXV];
    int  arcs[MAXV][MAXV];
    int vexnum,edgenum;
} Mgraph;

void creat_Mgraph(Mgraph *G,int e)  //修改 边由权值取代 
{
	int i,j,k,v;
	G->vexnum=e; //增加
  for(i=0;i<MAXV;i++)
	  scanf("%c",&G->vexs[i]);
      for(i=0;i<MAXV;i++)
		  for(j=0;j<MAXV;j++)
			  { G->arcs[i][j]=100; G->arcs[i][i]=0;}
		printf("请输入i,j,v：\n");
      for(k=0;k<e;k++)
		{
			scanf("%d%d%d",&i,&j,&v);
            G->arcs[i][j]=v;G->arcs[j][i]=v; //无向图的邻接矩阵
			//G->arcs[i][j]=1; //有向图的邻接矩阵 
		}
}

void output(Mgraph *G)
{
	int i,j;
	for(i=0;i<MAXV;i++)
	 printf("%6c",G->vexs[i]);
	printf("\n");
     for(i=0;i<MAXV;i++) 
	 {
	    for(j=0;j<MAXV;j++)
			printf("%6d",G->arcs[i][j]);
	    printf("\n");
	 }
}

int dist[MAXV],path[MAXV]; //全局变量 
 
void Dijkstra(Mgraph *G,int v)
{
    //int dist[MAXV],path[MAXV];
    int s[MAXV];
    int i,j,min,u;
    for(i=0;i<G->vexnum;i++)
    {  

        dist[i]=G->arcs[v][i];
        s[i] = 0;
        if(G->arcs[v][i]<INFINITE)
            path[i] = v;
        else
            path[i] = -1;       
    }
   
     s[v]=1;
    for(i=0;i<G->vexnum ;i++)
    {
        min = INFINITE;
        //取出dist中最小的
        for(j=0;j<G->vexnum;j++)
        {
            if(s[j]==0&&dist[j]<min)
            {
                min = dist[j];
                u = j;
            }
        }
        //经过上面的遍历已经取出dist中最小的了，接下来要做的就是访问这个形成最小距离的顶点u
        //设置已经访问
        s[u] = 1;
        for(j=0;j<G->vexnum;j++)
        {
            if(s[j]==0)
                if(G->arcs[u][j]<INFINITE && dist[u]+G->arcs[u][j]<dist[j])
                {
                    dist[j] = dist[u]+G->arcs[u][j];
                    path[j] = u;
                }
        }
    }
  
}

int main()
{
	Mgraph *G;
	int e,i,v,j;
	printf("请输入边数e的值和%d个顶点:\n",MAXV);
	scanf("%d",&e);
	getchar();
	
	G=(Mgraph*)malloc(sizeof(Mgraph));
	
	creat_Mgraph(G,e);
	printf("\n邻接矩阵为：\n");
	output(G);
    
    Dijkstra(G,0);
    
    printf("\n输出dist数组的值：\n");
	for(j=0;j<MAXV;j++)
	 { printf("%4d",dist[j]);}
	  
	printf("\n输出path数组的值：\n");
	for(j=0;j<MAXV;j++)
	 { printf("%4d",path[j]);}  
	return 0;
}

