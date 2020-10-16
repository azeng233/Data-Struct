#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define N 5  //��������Ա�ø����Ӵ� 
//typedef char InfoType[10];
typedef int KeyType; //����ؼ�������
typedef struct //��¼����
{   KeyType key; //�ؼ�����
  //InfoType data; //����������,����ΪInfoType
} RecType; //����ļ�¼���Ͷ���

void input(RecType R[],int n)
{
  int i;
  for(i=1;i<=n;i++)
  scanf("%d",&R[i].key); //ȡ��r[0]ֱ�Ӵ�r[1]��ʼ���� 
}

void print(RecType R[],int n)
{
  int i;
  for(i=1;i<=n;i++)
    printf("%d\t",R[i].key);
}

void BubbleSort(RecType R[],int n) //ð������  �Ӻ���ǰ 
{ 
  int i,j; RecType temp;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=n-i;j++) //�Ƚ��ұ�����С�ؼ��ֵļ�¼
      if (R[j].key>R[j+1].key)
      { temp=R[j]; //R[j]��R[j-1]����
        R[j]=R[j+1];
        R[j+1]=temp; 
      }
  }
//   printf("\n");
}
  
void BubbleSort1(RecType R[],int n) //ð������ ��ǰ���� 
{ 
int i,j; RecType temp;
  for (i=1;i<=n;i++)
  {
    for (j=n;j>i;j--) //�Ƚ��ұ�����С�ؼ��ֵļ�¼
      if (R[j].key<R[j-1].key)
      { temp=R[j]; //R[j]��R[j-1]����
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
//��R[s]��R[t]��Ԫ�ؽ��п�������
{ 
  int i=s,j=t; RecType tmp;
  if (s<t) //���������ٴ���2��Ԫ�ص����
  { tmp=R[s]; //������ĵ�1����¼��Ϊ��׼
    while (i!=j) //�����˽������м�ɨ��,ֱ��i=jΪֹ
    { 
      while (j>i && R[j].key>=tmp.key) j--;
      R[i]=R[j];
      while (i<j && R[i].key<=tmp.key) i++;
      R[j]=R[i];
    }
  R[i]=tmp;
  QuickSort(R,s,i-1); //��������ݹ�����
  QuickSort(R,i+1,t); //��������ݹ�����
 }
//�ݹ����
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
  printf("������Ҫ�������������ĳ��ȣ�  ");
  scanf("%d",&N);
  while(!N) {
  	printf("���������Ϣ��������������:   ");
  	scanf("%d",&N);
  }
  RecType R[N+1];
//  printf("\n********************************************************\n");
  printf("����������:\n");
  input(R,N);
  printf("�������������Ϊ(δ����):\n");
  print(R,N);
  printf("\n********************************************************\n");
  printf("\n**************��ѡ������ѡ���ѡ������������************\n");
  printf("\n*************����  1������ð������(˳�����)************\n");
  printf("\n*************����  2������ð������(�������)************\n");
  printf("\n******************����  3�����п�������*****************\n");
  printf("\n********************����  0���˳�����*******************\n");
  printf("\n********************************************************\n");
  printf("������(0/1/2)��");
  scanf("%d",&i);  //printf("\n");
  while(i)
  {
      switch(i)
      {
        case 1:printf("ð������(˳�����)��Ľ����:\t"); BubbleSort(R,N);print(R,N);break;
        case 2:printf("ð������(�������)��Ľ����:\t"); BubbleSort2(R,N);print(R,N);break;
        case 3:printf("���������Ľ����:\t"); QuickSort(R,1,N);print(R,N);break;
        case 0:break;
        default:printf("�������ѡ������������ѡ��");
      }
//    print(R,N);
    printf("\n�����ѡ��(0/1/2):");
    scanf("%d",&i);
    if(i == 0) {
	   love();
	   printf("\n�����˳���������ڴ��´��������棡\n");
	}
  }
//  system("pause");
  return 0;
}
