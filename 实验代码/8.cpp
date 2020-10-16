#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef char InfoType[10];
typedef int KeyType; //定义关键字类型
typedef struct //记录类型
{ KeyType key; //关键字项
  //InfoType data; //其他数据项,类型为InfoType
} RecType; //排序的记录类型定义

void input(RecType R[],int n)
{
  int i;
  for(i=1;i<=n;i++)
  scanf("%d",&R[i].key);
}

void print(RecType R[],int n)
{
  int i;
  for(i=1;i<=n;i++)
    printf("%4d",R[i].key);
}

void BubbleSort(RecType R[],int n) //冒泡排序
{ 
  int i,j; RecType temp;
  for (i=0;i<n-1;i++)
  {
    for (j=n-1;j>i;j--) //比较找本趟最小关键字的记录
      if (R[j].key<R[j-1].key)
      { temp=R[j]; //R[j]与R[j-1]交换
        R[j]=R[j-1];
        R[j-1]=temp; 
      }
  }
}

void QuickSort(RecType R[],int s,int t)
//对R[s]至R[t]的元素进行快速排序
{ 
  int i=s,j=t; RecType tmp;
  if (s<t) //区间内至少存在2个元素的情况
  { tmp=R[s]; //用区间的第1个记录作为基准
    while (i!=j) //从两端交替向中间扫描,直至i=j为止
    { 
      while (j>i && R[j].key>=tmp.key) j--;
      R[i]=R[j];
      while (i<j && R[i].key<=tmp.key) i++;
      R[j]=R[i];
    }
  R[i]=tmp;
  QuickSort(R,s,i-1); //对左区间递归排序
  QuickSort(R,i+1,t); //对右区间递归排序
 }
//递归出口：不需要任何操作
}

int main()
{
  int i;
  RecType R[N+1];
  printf("\n********************************************************\n");
  printf("请输入数字:\n");
  input(R,N);
  printf("输入的数字排序为(未排序):\n");
  print(R,N);
  printf("\n********************************************************\n");
  printf("\n**************请选择你想选择的选项来进行排序************\n");
  printf("\n******************输入  1：进行冒泡排序*****************\n");
  printf("\n******************输入  2：进行快速排序*****************\n");
  printf("\n********************输入  0：退出排序*******************\n");
  printf("请输入：");
  scanf("%d",&i);  printf("\n");
  while(i)
  {
      switch(i)
      {
        case 1:BubbleSort(R,N);break;
        case 2:QuickSort(R,0,N);break;
        case 0:break;
      }
    print(R,N);
    
    printf("\n请继续选择......\n");
    scanf("%d",&i);
  }
  system("pause");
  return 0;
}
