#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status,SElemType;
typedef struct {
  SElemType *base;
  SElemType *top;
  int stacksize;
} SqStack;

Status InitStack(SqStack &S)
{
  S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
  if(!S.base) exit(OVERFLOW);
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
  return OK;
}

Status Push(SqStack &S,SElemType e)
{
  if(S.top - S.base >= S.stacksize){
    S.base = (SElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(SElemType));
    if(!S.base) exit(OVERFLOW);
    S.top = S.base + S.stacksize;
    S.stacksize += STACKINCREMENT;
  }
  *S.top++ = e;
  return OK;
}

Status Pop(SqStack &S,SElemType &e){
  if(S.top == S.base) return ERROR;
  e = *--S.top;
  return OK;
}

bool StackEmpty(SqStack S){
  if(S.top==S.base)return true;//为空
  else
  return false;//不为空
}

void Conversion(void){
    //十进制整数转换成八进制
    int n;
    SqStack S;
    int e;
    printf("请输入十进制整数：");
    scanf("%d",&n);
    InitStack(S);
    while(n) {
        Push(S,n%8);
        n=n/8;
    }
    printf("得到八进制整数：");
    while(!StackEmpty(S)){
        Pop(S,e);
        printf("%d",e);
    }
}

int main()
{
  SqStack S;
  Conversion();
  system("pause");
  return 0;
}