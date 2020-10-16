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

void createlist(Sqlist &L)//n为用户个数
{
  L.len = 0;
  int n;
  printf("请输入要录入的用户个数：\n");
  scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("请输入第%d位的名字:\n",i);
		scanf("%s",&L.mylist[i-1].name);
    printf("请输入第%d位的电话:\n",i);
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
  printf("请输入你想增加的数量：\n");
  scanf("%d",&x);
	if(x<1||x>L.len+1)
	{
    printf("输入位置错误,既将退出此次插入"); 
    getchar();
    exit(1);
  }
	struct Node cur;
  printf("请输入增加的名字：\n");
  scanf("%s",cur.name);
  printf("请输入增加的号码:\n");
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
   printf("请输入要删除的序号：");
   scanf("%d",&x);
 	if(x<1||x>L.len)
  {
 	 printf("删除失败！既将退出!\n");
   getchar();
   exit(1);
  }
 	struct Node *p,*q;
   p=&(L.mylist[x-1]);
   q=L.mylist+L.len-1;
   --L.len;
 }

/* void searchlist(Sqlist &L) //e为用户姓名
{
	int i=1;
  char e;
  printf("请输入要删除的用户的姓名：");
  scanf("%s",&e);
	while(i<L.len&&L.mylist[i-1].name!=e)
	i++;
	if(i>=L.len)
	printf("错误");
	else
	printf("所查找到用户电话号码为%d,",L.mylist[i-1].tel);
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
