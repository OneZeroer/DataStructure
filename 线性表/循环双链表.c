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
	//L不是合法循环链表的时候，返回false 
	if(L==NULL || L->next==NULL || L->prior==NULL) return false;
	if(L->next==L && L->prior==L) return true;
	return false; 
}

bool isTail(DLinkList L,DNode *p){
	//按理要做判断，但是王道书没有，稍微判断一下 ,不深究太细 
	if(L==NULL || p==NULL) return false;
	if(p->next==L) return true;
	return false;
}

bool InsertNextDNode(DNode *p,DNode *s){
	if(p==NULL || s==NULL) return false;
	s->next = p->next;
	//这步不用再管p是不是尾节点了 
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true; 
}

bool DeleteNextDNode(DNode *p){
	//默认不会传入头节点，只是基本操作不做过分细究 
	//这一步不再判断p是否是尾节点 
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
 	//注意printf的入栈顺序，先执行的要放后面 
 	printf("InsertNext : %d\t\tTrue : %d\n",L->next->data,InsertNextDNode(L,p));
 	printf("isTail : %d\n",isTail(L,p));
 	printf("InsertNext : %d\t\tTrue : %d\n",L->next->next->data,InsertNextDNode(p,s));
 	printf("DeleteNext : %d\t\tTrue : %d",L->next->next->data,DeleteNextDNode(p));
}

int main(void){
	test();
	return 0;
}

