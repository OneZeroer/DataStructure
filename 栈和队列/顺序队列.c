#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 20
#define ElemType int

/*
此队列最大容纳数为MaxSize-1，rear指向将要插入的位置 
仅实现带tag的 
*/ 
typedef struct{
	ElemType data[MaxSize];
	int front , rear;
//	int tag;	//代表最后一次操作，插入为1，删除为0
//	int size;	//代表队列长度 
} SqQueue;


void InitQueue(SqQueue *Q){
	//队头等于队尾等于0
	Q->front = Q->rear = 0;
//	Q->tag = 0; 
}

bool QueueEmpty(SqQueue Q){
	if(Q.front == Q.rear /*&& Q.tag == 0*/) return true;
	return false;
}

bool DeQueue(SqQueue *Q , ElemType *x){
	if(QueueEmpty(*Q)) return false;
	(*x) = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

bool GetHead(SqQueue Q , ElemType *x){
	if(QueueEmpty(Q)) return false;
	(*x) = Q.data[Q.front];
	return true;
}

bool EnQueue(SqQueue *Q , ElemType x){
	if(Q->front == (Q->rear + 1) % MaxSize) return false;
//	if(Q->front == Q->rear && Q->tag == 1) return false;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize;
	return true;
}

void test(){
	SqQueue Q;
	InitQueue(&Q);
	printf("Init : front : %d\trear : %d\n",Q.front,Q.rear);
	ElemType x=3,temp=0;
	printf("IsEmpty : %d\n",QueueEmpty(Q));
	printf("En :temp : %d\tHead : %d\tTrue : %d\n",temp,GetHead(Q,&temp),EnQueue(&Q,x));
	temp = 0;
	printf("De : temp : %d\tTrue : %d\n",temp,DeQueue(&Q,&temp));
}

int main(void){
	test();
	return 0;
}
