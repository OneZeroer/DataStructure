#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 20
#define Elemtype int

typedef struct {
	Elemtype data[MaxSize];
	int top;
} Sqstack;


void InitStack(Sqstack *S){
	S->top = -1;
} 

bool StackEmpty(Sqstack S){
	if(S.top == -1) return true;
	return false;
}

bool Pop(Sqstack *S,Elemtype *x){
	//栈为空不能Pop
	if(S->top == -1) return false; 
	(*x) = S->data[(S->top)--];
	return true;
}

bool GetTop(Sqstack S,Elemtype *x){
	if(S.top == -1) return false;
	(*x) = S.data[S.top];
	return true;
}

bool Push(Sqstack *S,Elemtype x){
	//栈满不能Push 
	if(S->top == MaxSize - 1) return false;
	S->data[++(S->top)] = x;
	return true;
}

void test(){
	Sqstack S;
	InitStack(&S);
	printf("Init : S->top is %d\n",S.top);
	Elemtype x = 1,temp = 0;
	Push(&S,x);
	printf("Push : temp : %d\n",S.data[S.top]);
	GetTop(S,&temp);
	printf("Get : temp : %d\n",temp);
	Pop(&S,&temp);
	printf("Pop : top : %d \t temp : %d\n",S.top,temp);
}

int main(void){
	test();
	return 0;
}
