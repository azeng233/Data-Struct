#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char *DString;

int Index(DString S, DString T, int pos)//�����Ӵ�T������S�е�pos���ַ�֮���λ�ã��������ڣ�����0
{
    int i, j;
    i = pos;//��������S�е�ǰλ���±꣬��pos��Ϊ1ʱ,���posλ�ÿ�ʼƥ��
    j = 1;//�����Ӵ�T���ֵ�ǰλ���±�ֵ
    while (i<=S[0] - T[0] +1&&j<=T[0])//��i�ĳ���С�ڿ�ƥ�䳤�ȣ���jС��T�ĳ���ʱѭ��
    {
        if (S[i]==T[j])//���ַ����ʱ����ƥ��
        {
            j++;
            i++;
        }
        else//ָ���������ƥ��
        {
            i = i - j + 2;    //ע����������ļ�2��i�˻ص��ϴ�ƥ����λ����һ��λ��
            j = 1;//j�˻��Ӵ�T����λ
        }
    }
    if (j > T[0]) return i - T[0];
    else return 0;
}
int main()
{
  char S[20];
  char T[20];
  char c, e;
	int n = 1;
	int k = 0;

	int pos;
	
	printf("����������(����#��Ϊ������־��)�� \n"); 
	scanf("%c", &c);
	while( c != '#' )
	{
		S[n++] = c;
		S[n] = '\0';
		scanf("%c", &c);

	}
	S[0] = n-1;	
	
	printf("�������Ӵ�(����#��Ϊ������־��)�� \n");
	scanf("%c", &e);
	while( e != '#' )
	{
		T[k++] = e;
		T[k] = '\0';
		scanf("%c", &e);
	}
	T[0] = k-1;	
			
	printf("�����������п�ʼ����ƥ���λ�ã����ַ�λ��Ϊ1����\n");
	scanf("%d", &pos);
  
  int result = Index(S,T,pos);
  if( result != -1 )
	{
		printf("�������Ӵ��������ĵ�%d���ַ������ַ���λ��Ϊ1�����״�ƥ��", result);
	}			
	else
	{
		printf("��ƥ���Ӵ�\n");	
	}
  return 0;
}
