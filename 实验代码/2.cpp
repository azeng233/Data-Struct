#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int ElemType,Status;
typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LNode,*LinkList;

Status Createlist(LinkList &L) //����β�巨���ҳ�ʼ��
{
  L = (LinkList)malloc(sizeof(LNode));
  L->next=NULL;
  int n;
  printf("������Ҫ����������ĳ���n:");
  scanf("%d",&n);
  LNode * s;
	LNode * r = L;
	int i;
	ElemType ele;
  printf("������Ҫ�����Ԫ��:");
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

LNode * SearchList_Elem(LinkList L) //����ֵ����
{
  ElemType find_ele;
  printf("������Ҫ���ҵ�ֵ��");
  scanf("%d",&find_ele);
  LNode *p=L->next;
  while(p!=NULL&&p->data!=find_ele)
  {
    p=p->next;
  }
  return p;
}

LNode * SearchList_Pos(LinkList L) //������Ų���
{
  int i;int j=0;
  printf("������Ҫ���ҵ���ţ�");
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
    printf("���ҵ�λ�ó����˷�Χ��");
    return NULL;
  }
  return p;
}

LNode * GetList_Pos(LinkList L,int pos) //�����ں�����
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
		printf("����λ�ó�����Χ��");
		return NULL;	
	}
	return node;
}


Status InsertList(LinkList &L) //����
{
  ElemType insertelem;int pos;
  printf("������Ҫ�����Ԫ���Լ�����λ�ã�");
  scanf("%d,%d",&insertelem,&pos);
  LNode *node;
  LNode *newnode=(LNode *)malloc(sizeof(LNode));
  newnode->data = insertelem;
  node = GetList_Pos(L,pos-1); //�ҵ�����ǰ��
  newnode->next = node->next;
  node->next = newnode;
  return OK;
}

Status DeleteList(LinkList &L) //ɾ��
{
  int pos;ElemType *Dele_elem;
  printf("������Ҫɾ����Ԫ���Լ�����λ�ã�");
  scanf("%d,%d",&Dele_elem,&pos);
  LNode *node;
  LNode *del_node;
  node = GetList_Pos(L,pos-1);
  del_node = node->next;
  node->next = del_node->next;
  free(del_node);
  return OK;
}

void PrintList(LinkList L) //��ӡ
{
	LNode * node = L->next;
	printf("����Ԫ��Ϊ:\n"); 
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
  printf("���濪ʼ��ֵ���ң�\n");
  SearchList_Elem(L);
  printf("���濪ʼλ�ò��ң�\n");
  SearchList_Pos(L);
  InsertList(L);
  PrintList(L);
  DeleteList(L);
  PrintList(L);
  return 0;
}
