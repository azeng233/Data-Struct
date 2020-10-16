#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char *DString;

int Index(DString S, DString T, int pos)//返回子串T在主串S中第pos个字符之后的位置，若不存在，返回0
{
    int i, j;
    i = pos;//用于主串S中当前位置下标，若pos不为1时,则从pos位置开始匹配
    j = 1;//用于子串T多种当前位置下标值
    while (i<=S[0] - T[0] +1&&j<=T[0])//若i的长度小于可匹配长度，且j小于T的长度时循环
    {
        if (S[i]==T[j])//两字符相等时继续匹配
        {
            j++;
            i++;
        }
        else//指针后退重新匹配
        {
            i = i - j + 2;    //注意这个索引的加2，i退回到上次匹配首位的下一个位置
            j = 1;//j退回子串T的首位
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
	
	printf("请输入主串(并以#作为结束标志！)： \n"); 
	scanf("%c", &c);
	while( c != '#' )
	{
		S[n++] = c;
		S[n] = '\0';
		scanf("%c", &c);

	}
	S[0] = n-1;	
	
	printf("请输入子串(并以#作为结束标志！)： \n");
	scanf("%c", &e);
	while( e != '#' )
	{
		T[k++] = e;
		T[k] = '\0';
		scanf("%c", &e);
	}
	T[0] = k-1;	
			
	printf("请输入主串中开始进行匹配的位置（首字符位置为1）：\n");
	scanf("%d", &pos);
  
  int result = Index(S,T,pos);
  if( result != -1 )
	{
		printf("主串与子串在主串的第%d个字符（首字符的位置为1）处首次匹配", result);
	}			
	else
	{
		printf("无匹配子串\n");	
	}
  return 0;
}
