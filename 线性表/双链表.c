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
 	//**判断是否分配到
	if(L==NULL){
		return false;
	} 
 	(*L)->next = (*L)->prior = NULL;
 	return true;
 }
 
 bool Empty(DLinkList L){
 	if (L->next==NULL){
 		return true;
	 }
	 return false;
 }
 
 bool InsertNextNode(DNode *p,DNode *s){
 	//判断不可插入的情况 
 	if (p==NULL || s==NULL){
 		return false;
	 }
 	s->next = p->next;
 	//判断p为尾节点的情况 
 	if(p->next != NULL){
 		p->next->prior = s;
	 }
	 p->next = s;
	 s->prior = p;
	 return true;
 }
 
 bool InsertPriorNode(DNode *p,DNode *s){
 	//带头节点
 	//头节点处不允许前插 
	 if(p->prior == NULL){
	 	return false;
	 }
	 return InsertNextNode(p->prior,s);
 }
 bool DeleteNextNode(DNode *p){
 	//带头结点
	//**后面没有不允许删除，本身为空也不行 
	if(p->next==NULL || p==NULL){
		return false;
	} 
	DNode *q = p->next;
	p->next = q->next;
	//判断q是否是尾节点
	if(q->next != NULL){
		q->next->prior = p;
	}
	//**Delete记得free
	free(q); 
	return true; 
 }
 
 bool DestoryList(DLinkList L){
 	if(L==NULL){
 		return false;
	 }
 	while(L->next != NULL){
 		DeleteNextNode(L);
	 }
	 free(L);
	 //**L要指向NULL
	 L = NULL;
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
 	printf("begin");
 	printf("判断为空：%d\n",Empty(L));
 	printf("后插：%d\n",InsertNextNode(L,p));
 	printf("%d\n",L->next->data);
 	printf("前插：%d\n",InsertPriorNode(p,s));
 	printf("%d\n",L->next->data);
 }
 int main(void){
 	test();
 	return 0;
 }
