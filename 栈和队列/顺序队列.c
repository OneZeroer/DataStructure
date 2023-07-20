#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 20
#define ElemType int

/*
�˶������������ΪMaxSize-1��rearָ��Ҫ�����λ�� 
��ʵ�ִ�tag�� 
*/ 
typedef struct{
	ElemType data[MaxSize];
	int front , rear;
//	int tag;	//�������һ�β���������Ϊ1��ɾ��Ϊ0
//	int size;	//������г��� 
} SqQueue;


void InitQueue(SqQueue *Q){
	//��ͷ���ڶ�β����0
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
