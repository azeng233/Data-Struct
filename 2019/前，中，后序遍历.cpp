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
 BitNode *Create_bt(void) //建立二叉树 
 {
 	BitNode *s,*t;
 	 printf("enter i,ch\n");
 	 scanf("%d,%c",&i,&ch);
 	while(i!=0&&ch!='#')
 	{
 		if(k<i) k=i;  //k表示节点在数组的下标 
 		  s=(BitNode*)malloc(sizeof(BitNode)); //分配一段内存空间 
 		  s->data=ch;
 		  s->lchild=s->rchild=NULL;
 		  p[i]=s;
 		  if(i==1) t=s;
 		  else
 		  {
 		  	j=i/2;
 		  	if(i%2==0) p[j]->lchild=s; //左孩子为偶数 
 		  	else p[j]->rchild=s;
 		  }
 		  printf("enter i,ch\n");
 		  scanf("%d,%c",&i,&ch);
 	}
 	return t; 
 }
 
 void PreOrder(BITree root) //建立先序遍历二叉树算法
 {
    if(root!=NULL)
	{
		printf("%c",root->data);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	 } 
 }

 void InOrder(BITree root) //建立中序遍历二叉树算法 
 {
	 if(root!=NULL)
	{
		InOrder(root->lchild);
		printf("%c",root->data);
		InOrder(root->rchild);
	 } 
 }  
 
 void ProOrder(BITree root) //建立后序遍历二叉树算法 
 {
	 if(root!=NULL)
	{
		ProOrder(root->lchild);
	    ProOrder(root->rchild);	
	    printf("%c",root->data);
	 } 
 }  
 
 int main()
 {
 	BITree root;
 	root=Create_bt();
 	
 	printf("先序遍历的结果为：\n");
 	PreOrder(root);
 	printf("\n");
 	
 	printf("中序遍历的结果为：\n");
 	InOrder(root);
 	printf("\n");
 	
 	printf("后序遍历的结果为：\n");
 	ProOrder(root);
 	printf("\n");
 	
 	return 0;
 }
 
 
