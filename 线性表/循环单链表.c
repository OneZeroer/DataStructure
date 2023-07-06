#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

#define ElemType int

typedef struct LNode{
	//**�ֺ� 
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;


bool  InitList(LinkList *L){
	*L = (LNode *)malloc(sizeof(LNode));
	// �ж��Ƿ����ɹ� 
	if (*L == NULL) return false;
	(*L)->next = *L;
	return true;
}

bool Empty(LinkList L){
	//LΪNULL���쳣�������Ҫ�ȿ��ǣ�����û���ǣ� 
	if(L==NULL) return false;
	if(L->next == L) return true;
	return false;
}

bool isTail(LinkList L,LNode *p){
	if(L==NULL || p==NULL) return false;
	if(p->next == L) return true;
	return false;
} 

void test(){
	LinkList L = NULL;
	InitList(&L);
	printf("L : %p  and L->next : %p\n",L,L->next);
	printf("Empty : %d\n",Empty(L));
	printf("isTail : %d\n",isTail(L,L));
}

int main(void){
	test();
	return 0;
}
