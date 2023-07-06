#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

#define ElemType int

typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;

bool InitDLinkList(DLinkList *L){
	*L = (DNode *)malloc(sizeof(DNode));
	if(*L==NULL) return false;
	(*L)->next =(*L)->prior = *L;
	return true;
}

bool Empty(DLinkList L){
	//L���ǺϷ�ѭ�������ʱ�򣬷���false 
	if(L==NULL || L->next==NULL || L->prior==NULL) return false;
	if(L->next==L && L->prior==L) return true;
	return false; 
}

bool isTail(DLinkList L,DNode *p){
	//����Ҫ���жϣ�����������û�У���΢�ж�һ�� ,���̫ϸ 
	if(L==NULL || p==NULL) return false;
	if(p->next==L) return true;
	return false;
}

bool InsertNextDNode(DNode *p,DNode *s){
	if(p==NULL || s==NULL) return false;
	s->next = p->next;
	//�ⲽ�����ٹ�p�ǲ���β�ڵ��� 
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true; 
}

bool DeleteNextDNode(DNode *p){
	//Ĭ�ϲ��ᴫ��ͷ�ڵ㣬ֻ�ǻ���������������ϸ�� 
	//��һ�������ж�p�Ƿ���β�ڵ� 
	if (p==NULL) return false;
	DNode *q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return true; 
} 

void test(){
	DLinkList L;
 	InitDLinkList(&L);
 	DNode *p,*s;
 	p = (DNode *)malloc(sizeof(DNode));
 	s = (DNode *)malloc(sizeof(DNode));
 	p->data = 6;
 	s->data = 4;
 	L->data = -1;
 	//ע��printf����ջ˳����ִ�е�Ҫ�ź��� 
 	printf("InsertNext : %d\t\tTrue : %d\n",L->next->data,InsertNextDNode(L,p));
 	printf("isTail : %d\n",isTail(L,p));
 	printf("InsertNext : %d\t\tTrue : %d\n",L->next->next->data,InsertNextDNode(p,s));
 	printf("DeleteNext : %d\t\tTrue : %d",L->next->next->data,DeleteNextDNode(p));
}

int main(void){
	test();
	return 0;
}

