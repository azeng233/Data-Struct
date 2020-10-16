#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct Node{
  char name[20];
  int tel[50];
};
typedef struct{
  struct Node* mylist;
  int len;
  int listsize;
}Sqlist;

void InitList_Sq(Sqlist &L)
{
  L.mylist=(Node *)malloc(100*sizeof(Node));
  L.len = 0;
  L.listsize=100;
}

void createlist(Sqlist &L)//nΪ�û�����
{
  L.len = 0;
  int n;
  printf("������Ҫ¼����û�������\n");
  scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("�������%dλ������:\n",i);
		scanf("%s",&L.mylist[i-1].name);
    printf("�������%dλ�ĵ绰:\n",i);
    scanf("%s",&L.mylist[i-1].tel);
    L.len++;
	}
 } 

 void print(Sqlist &L)
{
   struct Node *q=L.mylist;
   for(q;q<L.mylist+L.len;q++)	
	{
    printf("   %s       %s\n",q->name,q->tel);
  }
} 

void Listinsert(Sqlist &L)
{
	int x;
  printf("�������������ӵ�������\n");
  scanf("%d",&x);
	if(x<1||x>L.len+1)
	{
    printf("����λ�ô���,�Ƚ��˳��˴β���"); 
    getchar();
    exit(1);
  }
	struct Node cur;
  printf("���������ӵ����֣�\n");
  scanf("%s",cur.name);
  printf("���������ӵĺ���:\n");
  scanf("%s",cur.tel);
  struct Node *p,*q;
  q=&(L.mylist[L.len-1]);
  for(p=&(L.mylist[L.len-1]);p>=q;--p) *(p+1)=*p;
  *q=cur;
  ++L.len;
}

 void deletelist(Sqlist &L) 
 {
 	int x;
   printf("������Ҫɾ������ţ�");
   scanf("%d",&x);
 	if(x<1||x>L.len)
  {
 	 printf("ɾ��ʧ�ܣ��Ƚ��˳�!\n");
   getchar();
   exit(1);
  }
 	struct Node *p,*q;
   p=&(L.mylist[x-1]);
   q=L.mylist+L.len-1;
   --L.len;
 }

/* void searchlist(Sqlist &L) //eΪ�û�����
{
	int i=1;
  char e;
  printf("������Ҫɾ�����û���������");
  scanf("%s",&e);
	while(i<L.len&&L.mylist[i-1].name!=e)
	i++;
	if(i>=L.len)
	printf("����");
	else
	printf("�����ҵ��û��绰����Ϊ%d,",L.mylist[i-1].tel);
	printf("\n");
}*/

int main()
{
  Sqlist L;
  InitList_Sq(L);
  createlist(L);
  print(L);
  Listinsert(L);
  print(L);
  deletelist(L);
  print(L);
  return 0;
}
