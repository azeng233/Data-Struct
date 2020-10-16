#include <stdio.h>

int main() {
	int a[10];
	int i,j,temp;
	
	printf("请输入数字： \n");
	for(i = 0;i < 5 ; i++)
	 scanf("%d",&a[i]);
	 printf("\n");
	 for(i = 0;i <4;i++) {
	 	for(j=0;j<4-i;j++) 
	 	 if(a[j]>a[j+1]) {
	 	 	temp = a[j];
	 	 	a[j]=a[j+1];
	 	 	a[j+1]=temp;
		  }
	 printf("第%d次排序的结果:",i+1); 
	 for(j=0;j<5;j++)
	  printf(" %d ",a[j]);
	  printf("\n");
	 }
	 printf("最终的排序结果是：");
	 for(i = 0;i <5;i++) 
	 printf(" %d ",a[i]);
	 return 0;
}
