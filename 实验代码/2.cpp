#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int ElemType,Status;
typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LNode,*LinkList;

Status Createlist(LinkList &L) //利用尾插法并且初始化
{
  L = (LinkList)malloc(sizeof(LNode));
  L->next=NULL;
  int n;
  printf("请输入要建立的链表的长度n:");
  scanf("%d",&n);
  LNode * s;
	LNode * r = L;
	int i;
	ElemType ele;
  printf("请输入要加入的元素:");
  for(i=0;i<n;i++)
  {
     scanf("%d",&ele);
     getchar();
     s = (LNode *)malloc(sizeof(LNode));
     s->data = ele; r->next = s;r = s;
  }
  r->next = NULL;
  return OK;
}

LNode * SearchList_Elem(LinkList L) //按照值查找
{
  ElemType find_ele;
  printf("请输入要查找的值：");
  scanf("%d",&find_ele);
  LNode *p=L->next;
  while(p!=NULL&&p->data!=find_ele)
  {
    p=p->next;
  }
  return p;
}

LNode * SearchList_Pos(LinkList L) //按照序号查找
{
  int i;int j=0;
  printf("请输入要查找的序号：");
  scanf("%d",&i);
  if(i == 0)
      return L;
  if(i < 1)
      return NULL;
   LNode *p=L;
  while(p&&j<i)
  {
    p=p->next;
    j++;
  } 
  if(p == NULL)
  {
    printf("查找的位置超出了范围！");
    return NULL;
  }
  return p;
}

LNode * GetList_Pos(LinkList L,int pos) //运用在函数中
{
	if(pos == 0)
	{
		return L;
	}
	if(pos < 1)
	{
		return NULL;
	}
	LNode * node = L;
	int j = 0;
	while(node && j < pos)
	{
		
		node =node->next;
		j++;
	}
	if(node == NULL)
	{
		printf("插入位置超出范围！");
		return NULL;	
	}
	return node;
}


Status InsertList(LinkList &L) //插入
{
  ElemType insertelem;int pos;
  printf("请输入要插入的元素以及他的位置：");
  scanf("%d,%d",&insertelem,&pos);
  LNode *node;
  LNode *newnode=(LNode *)malloc(sizeof(LNode));
  newnode->data = insertelem;
  node = GetList_Pos(L,pos-1); //找到他的前驱
  newnode->next = node->next;
  node->next = newnode;
  return OK;
}

Status DeleteList(LinkList &L) //删除
{
  int pos;ElemType *Dele_elem;
  printf("请输入要删除的元素以及它的位置：");
  scanf("%d,%d",&Dele_elem,&pos);
  LNode *node;
  LNode *del_node;
  node = GetList_Pos(L,pos-1);
  del_node = node->next;
  node->next = del_node->next;
  free(del_node);
  return OK;
}

void PrintList(LinkList L) //打印
{
	LNode * node = L->next;
	printf("表中元素为:\n"); 
	while(node!= NULL)
	{
		printf("%d\t",node->data);
		node = node->next;
	} 
	printf("\n\n");
}

int main()
{
  LinkList L;
  Createlist(L);
  PrintList(L);
  printf("下面开始按值查找：\n");
  SearchList_Elem(L);
  printf("下面开始位置查找：\n");
  SearchList_Pos(L);
  InsertList(L);
  PrintList(L);
  DeleteList(L);
  PrintList(L);
  return 0;
}
