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
 
 int  leaf(BITree t)
 {
 	int LeafCount; 
 	if(t==NULL)
 	LeafCount=0; 
 	else if((t->lchild==NULL)&&(t->rchild==NULL))
    LeafCount=1;
    else
    LeafCount=leaf(t->lchild)+leaf(t->rchild);
	return LeafCount;
 }
 
 
 void PreOrder(BITree t) //������������������㷨
 {
    if(t!=NULL)
	{
	    printf("%c",t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	 } 
 }
 
 int main()
 {  int LeafCount;
 	BITree t;
 	t=Create_bt();
 	printf("��������Ľ��Ϊ��\n");
 	PreOrder(t);
 	printf("\n");
 	leaf(t);
 	printf("Ҷ�ӽڵ�ĸ�����: \n");
 	printf("%d",leaf(t));
	system("pause");
 	return 0;
 } 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
