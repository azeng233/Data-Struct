#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define N 5  //让数组可以变得更加庞大！ 
//typedef char InfoType[10];
typedef int KeyType; //定义关键字类型
typedef struct //记录类型
{   KeyType key; //关键字项
  //InfoType data; //其他数据项,类型为InfoType
} RecType; //排序的记录类型定义

void input(RecType R[],int n)
{
  int i;
  for(i=1;i<=n;i++)
  scanf("%d",&R[i].key); //取消r[0]直接从r[1]开始输入 
}

void print(RecType R[],int n)
{
  int i;
  for(i=1;i<=n;i++)
    printf("%d\t",R[i].key);
}

void BubbleSort(RecType R[],int n) //冒泡排序  从后往前 
{ 
  int i,j; RecType temp;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=n-i;j++) //比较找本趟最小关键字的记录
      if (R[j].key>R[j+1].key)
      { temp=R[j]; //R[j]与R[j-1]交换
        R[j]=R[j+1];
        R[j+1]=temp; 
      }
  }
//   printf("\n");
}
  
void BubbleSort1(RecType R[],int n) //冒泡排序 从前往后 
{ 
int i,j; RecType temp;
  for (i=1;i<=n;i++)
  {
    for (j=n;j>i;j--) //比较找本趟最小关键字的记录
      if (R[j].key<R[j-1].key)
      { temp=R[j]; //R[j]与R[j-1]交换
        R[j]=R[j-1];
        R[j-1]=temp; 
      }
  }
//   printf("\n");
}

void BubbleSort2(RecType R[],int n) {
  int i,j; RecType temp;
  for (i=1;i<=n;i++){
    for(j=n;j>i;j--)
     if(R[j-1].key<R[j].key){
       temp=R[j];
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
//递归出口
}

void love() {
	float y, x, z; 
	for (double y = 2.5; y >= -1.6; y = y - 0.2) 
 { 
 for (double x = -3; x <= 4.8; x = x + 0.1) 
 { 
 (pow((x*x + y*y - 1), 3) <= 3.6*x*x*y*y*y 
 || (x>-2.4 && x<-2.1 && y<1.5 && y>-1) 
 || (((x<2.5 && x>2.2) || (x>3.4 && x<3.7)) && y>-1 && y<1.5) 
 || (y>-1 && y<-0.6 && x<3.7 && x>2.2)) ? printf("*") : printf(" "); 
 }
 printf("\n"); 
 }
}

int main()
{
  int i,N;
  printf("请输入要进行排序的数组的长度：  ");
  scanf("%d",&N);
  while(!N) {
  	printf("您输入的信息有误，请重新输入:   ");
  	scanf("%d",&N);
  }
  RecType R[N+1];
//  printf("\n********************************************************\n");
  printf("请输入数字:\n");
  input(R,N);
  printf("输入的数字排序为(未排序):\n");
  print(R,N);
  printf("\n********************************************************\n");
  printf("\n**************请选择你想选择的选项来进行排序************\n");
  printf("\n*************输入  1：进行冒泡排序(顺序输出)************\n");
  printf("\n*************输入  2：进行冒泡排序(逆序输出)************\n");
  printf("\n******************输入  3：进行快速排序*****************\n");
  printf("\n********************输入  0：退出排序*******************\n");
  printf("\n********************************************************\n");
  printf("请输入(0/1/2)：");
  scanf("%d",&i);  //printf("\n");
  while(i)
  {
      switch(i)
      {
        case 1:printf("冒泡排序(顺序输出)后的结果是:\t"); BubbleSort(R,N);print(R,N);break;
        case 2:printf("冒泡排序(逆序输出)后的结果是:\t"); BubbleSort2(R,N);print(R,N);break;
        case 3:printf("快速排序后的结果是:\t"); QuickSort(R,1,N);print(R,N);break;
        case 0:break;
        default:printf("您输入的选项有误，请重新选择！");
      }
//    print(R,N);
    printf("\n请继续选择(0/1/2):");
    scanf("%d",&i);
    if(i == 0) {
	   love();
	   printf("\n即将退出排序程序！期待下次与您见面！\n");
	}
  }
//  system("pause");
  return 0;
}
