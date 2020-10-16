#include <stdio.h>
#include <stdlib.h>
#define N 19
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];

typedef struct
{ KeyType key; //KeyType为关键字的数据类型
  //InfoType data; //其他数据项
} NodeType;

typedef NodeType SeqList[MAXL]; //查找顺序表类型

int SeqSearch(SeqList R,int n,KeyType k) //顺序查找
{
  int i=0;
  while (i<n && R[i].key!=k) //从表头往后找
    i++;
  if (i>=n) //未找到返回0
   return 0;
  else 
   return i+1;
}

int BinSearch(SeqList R,int n,KeyType k) //折半查找
{ 
  int low=0,high=n-1,mid;
  while (low<=high) //当前区间存在元素时循环
  { 
    mid=(low+high)/2;
    if (R[mid].key==k) //查找成功返回其逻辑序号mid+1
      return mid+1;
    if (k<R[mid].key) //继续在R[low..mid-1]中查找
      high=mid-1;
    else
      low=mid+1; //继续在R[mid+1..high]中查找
  }
    return 0; 
}

void compare(SeqList R) //冒泡排序法
{
  int i,j,t;
  for(j=0;j<19;j++)
	    for(i=0;i<18-j;i++)
	     if(R[i].key>R[i+1].key)
	      {t=R[i].key;R[i].key=R[i+1].key;R[i+1].key=t;}
  printf("排好序的数组为：\n");
  for(j=0;j<10;j++)
	       printf("%d\t",R[j].key);
  for(j=10;j<19;j++)
	       printf("%d\t",R[j].key);
}

int main()
{
  int x,k,o;
  SeqList R={5,4,3,2,1,9,8,6,7,10,12,11,14,13,15,23,78,69,55};
  compare(R);
  printf("输入待查元素x:");
  scanf("%d",&x);
  k=SeqSearch(R,N,x);//利用顺序查找
  if(k>0)
    printf("顺序查找待查元素的位置是%d！\n",k);
  else
    printf("顺序查找没有这个元素!\n");
  o=BinSearch(R,N,x);
  if(o>0)
    printf("折半查找待查元素的位置是%d!\n",o);
  else
    printf("折半查找没有这个元素!\n");
  system("pause");
  return 0;
}