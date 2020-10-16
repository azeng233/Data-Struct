#include <stdio.h>
#include <stdlib.h>
#define N 5
//typedef char InfoType[10];
typedef int KeyType; //����ؼ�������
typedef struct //��¼����
{ KeyType key; //�ؼ�����
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

void BubbleSort(RecType R[],int n) //ð������
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
           //printf("%d\t",R[i]);
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

int main()
{
  int i;
  RecType R[N+1];
//  printf("\n********************************************************\n");
  printf("����������:\n");
  input(R,N);
  printf("�������������Ϊ(δ����):\n");
  print(R,N);
  printf("\n********************************************************\n");
  printf("\n**************��ѡ������ѡ���ѡ������������************\n");
  printf("\n******************����  1������ð������*****************\n");
  printf("\n******************����  2�����п�������*****************\n");
  printf("\n********************����  0���˳�����*******************\n");
  printf("������(0/1/2)��");
  scanf("%d",&i);  //printf("\n");
  while(i)
  {
      switch(i)
      {
        case 1:printf("ð�������Ľ����:\t"); BubbleSort(R,N);break;
        case 2:printf("���������Ľ����:\t"); QuickSort(R,1,N);break;
        case 0:break;
      }
    print(R,N);
    
    printf("\n�����ѡ��(0/1/2):");
    scanf("%d",&i);
    if(i == 0) printf("\n�����˳���������ڴ��´��������棡");
  }
//  system("pause");
  return 0;
}
