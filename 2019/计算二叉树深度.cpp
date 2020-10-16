#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100

typedef char TElemType;  

typedef struct BitNode
{
	TElemType data;
	struct BitNode *lchild, *rchild;
} BitNode,*BITree;
 
 BitNode *p[MAXNUM+1]={NULL};
 int i,j,k=0;
 int depth=0; // 
 int h=1;
 char ch;
 BitNode *Create_bt(void) //���������� 
 {
 	BitNode *s,*t;
 	 printf("enter i,ch\n");
 	 scanf("%d,%c",&i,&ch);
 	while(i!=0&&ch!='#')
 	{
 		if(k<i) k=i;  //k��ʾ�ڵ���������±� 
 		  s=(BitNode*)malloc(sizeof(BitNode)); //����һ���ڴ�ռ� 
 		  s->data=ch;
 		  s->lchild=s->rchild=NULL;
 		  p[i]=s;
 		  if(i==1) t=s;
 		  else
 		  {
 		  	j=i/2;
 		  	if(i%2==0) p[j]->lchild=s; //����Ϊż�� 
 		  	else p[j]->rchild=s;
 		  }
 		  printf("enter i,ch\n");
 		  scanf("%d,%c",&i,&ch);
 	}
 	return t; 
 }
 
 void PreTreeDepth(BITree t, int h)  //ǰ����� 
 {
 	if(t!=NULL)
 	{
 		if(h>depth)  depth=h; //����ýڵ���ֵ����depth������depth��ֵ�� 
 		PreTreeDepth(t->lchild,h+1);
 		PreTreeDepth(t->rchild,h+1);		
	}
 }
 
 int main()
 {
 	BITree t;
 	t=Create_bt();
 	printf("\n");
 	PreTreeDepth(t,h);
 	printf("depth=%d",depth);
 	return 0;
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
