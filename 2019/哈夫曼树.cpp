#include <stdio.h>
#define N 4
#define M 2*N-1

typedef struct hnode
{
	int weight;
	int parent;
	int lchild,rchild;
}Hnode;

void huffman_tree(int w[N],Hnode Ht[M]) //哈夫曼算法 
{
	int i,j;
	int m1,m2,p1,p2;
	for(i=0;i<M;i++)
	{
		Ht[i].parent=-1;
		Ht[i].lchild=-1;
		Ht[i].rchild=-1;
		Ht[i].weight=0;
	}
	for(i=0;i<N;i++)
	    Ht[i].weight=w[i];
	printf("显示初始化的结果：\n");
	for(i=0;i<M;i++)
	{
		printf("%3d%3d%3d%3d",Ht[i].weight,Ht[i].parent,Ht[i].lchild,Ht[i].rchild);
		printf("\n");
	}
	for(i=N;i<M;i++)
	{
		m1=m2=32767; p1=p2=0;
		  for(j=0;j<i;j++)
		  {
		  	if(Ht[j].weight<m1&&Ht[j].parent==-1)
		  	{
		  		m2=m1; p2=p1;
		  		m1=Ht[j].weight;
		  		//p2=j;
				p1=j;
			}
			else if(Ht[j].weight<m2&&Ht[j].parent==-1)
			{
				m2=Ht[j].weight;
				p2=j;
			}
		  }
		Ht[p1].parent=i; Ht[p2].parent=i;
		Ht[i].lchild=p1; Ht[i].rchild=p2;
		Ht[i].weight=Ht[p1].weight+Ht[p2].weight;
	}
}

//帮你加输出函数    
void Print(int w[N],Hnode Ht[M])
{
	for(int i=0;i<M;i++)
	{
		printf("%3d%3d%3d%3d",Ht[i].weight,Ht[i].parent,Ht[i].lchild,Ht[i].rchild);
		printf("\n");
	}
}


int main()
{
	int w[N];
	Hnode Ht[M];
	int i;
	printf("请输入数字：\n");
	for(i=0;i<N;i++)
	{	
	//	scanf("%d",w[i]);缺少&
         scanf("%d",&w[i]);
	}

	huffman_tree(w,Ht);
	printf("****************************结果********************************\n");
	Print(w,Ht);
	return 0;
}

































 

