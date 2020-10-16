#include <stdio.h>
#include <stdlib.h>
#define N 19
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];

typedef struct
{ KeyType key; //KeyTypeΪ�ؼ��ֵ���������
  //InfoType data; //����������
} NodeType;

typedef NodeType SeqList[MAXL]; //����˳�������

int SeqSearch(SeqList R,int n,KeyType k) //˳�����
{
  int i=0;
  while (i<n && R[i].key!=k) //�ӱ�ͷ������
    i++;
  if (i>=n) //δ�ҵ�����0
   return 0;
  else 
   return i+1;
}

int BinSearch(SeqList R,int n,KeyType k) //�۰����
{ 
  int low=0,high=n-1,mid;
  while (low<=high) //��ǰ�������Ԫ��ʱѭ��
  { 
    mid=(low+high)/2;
    if (R[mid].key==k) //���ҳɹ��������߼����mid+1
      return mid+1;
    if (k<R[mid].key) //������R[low..mid-1]�в���
      high=mid-1;
    else
      low=mid+1; //������R[mid+1..high]�в���
  }
    return 0; 
}

void compare(SeqList R) //ð������
{
  int i,j,t;
  for(j=0;j<19;j++)
	    for(i=0;i<18-j;i++)
	     if(R[i].key>R[i+1].key)
	      {t=R[i].key;R[i].key=R[i+1].key;R[i+1].key=t;}
  printf("�ź��������Ϊ��\n");
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
  printf("�������Ԫ��x:");
  scanf("%d",&x);
  k=SeqSearch(R,N,x);//����˳�����
  if(k>0)
    printf("˳����Ҵ���Ԫ�ص�λ����%d��\n",k);
  else
    printf("˳�����û�����Ԫ��!\n");
  o=BinSearch(R,N,x);
  if(o>0)
    printf("�۰���Ҵ���Ԫ�ص�λ����%d!\n",o);
  else
    printf("�۰����û�����Ԫ��!\n");
  system("pause");
  return 0;
}