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
 int h=1; //���԰�h�����ȫ�ֱ���Ϊ1 
 int depth=0; // 
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
  void PreOrder(BITree root) //������������������㷨
 {
    if(root!=NULL)
	{
		printf("%c",root->data);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	 } 
 }

 void InOrder(BITree root) //������������������㷨 
 {
	 if(root!=NULL)
	{
		InOrder(root->lchild);
		printf("%c",root->data);
		InOrder(root->rchild);
	 } 
 }  
 
 void ProOrder(BITree root) //������������������㷨 
 {
	 if(root!=NULL)
	{
		ProOrder(root->lchild);
	    ProOrder(root->rchild);	
	    printf("%c",root->data);
	 } 
 }
 
 int  leaf(BITree root)
 {
 	int LeafCount; 
 	if(root==NULL)
 	LeafCount=0; 
 	else if((root->lchild==NULL)&&(root->rchild==NULL))
    LeafCount=1;
    else
    LeafCount=leaf(root->lchild)+leaf(root->rchild);
	return LeafCount;
 }
 
 void PreTreeDepth(BITree root, int h)  //ǰ����� 
 {
 	if(root!=NULL)
 	{
 		if(h>depth)  depth=h; //����ýڵ���ֵ����depth������depth��ֵ�� 
 		PreTreeDepth(root->lchild,h+1);
 		PreTreeDepth(root->rchild,h+1);	
	}	
 }
 
 int main()
 {
 	 
 	BITree root;
 	root=Create_bt();
 	
 	printf("��������Ľ��Ϊ��\n");
 	PreOrder(root);
 	printf("\n");
 	
 	printf("��������Ľ��Ϊ��\n");
 	InOrder(root);
 	printf("\n");
 	
 	printf("��������Ľ��Ϊ��\n");
 	ProOrder(root);
 	printf("\n");
 	
 	leaf(root);
 	printf("Ҷ�ӽڵ�ĸ�����: ");
 	printf("%d",leaf(root));
 	printf("\n");
 	
 	PreTreeDepth(root,h);
 	printf("depth=%d",depth);  //����֮ǰ��depth+1 
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
