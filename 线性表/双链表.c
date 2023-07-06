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
 	//**�ж��Ƿ���䵽
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
 	//�жϲ��ɲ������� 
 	if (p==NULL || s==NULL){
 		return false;
	 }
 	s->next = p->next;
 	//�ж�pΪβ�ڵ����� 
 	if(p->next != NULL){
 		p->next->prior = s;
	 }
	 p->next = s;
	 s->prior = p;
	 return true;
 }
 
 bool InsertPriorNode(DNode *p,DNode *s){
 	//��ͷ�ڵ�
 	//ͷ�ڵ㴦������ǰ�� 
	 if(p->prior == NULL){
	 	return false;
	 }
	 return InsertNextNode(p->prior,s);
 }
 bool DeleteNextNode(DNode *p){
 	//��ͷ���
	//**����û�в�����ɾ��������Ϊ��Ҳ���� 
	if(p->next==NULL || p==NULL){
		return false;
	} 
	DNode *q = p->next;
	p->next = q->next;
	//�ж�q�Ƿ���β�ڵ�
	if(q->next != NULL){
		q->next->prior = p;
	}
	//**Delete�ǵ�free
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
	 //**LҪָ��NULL
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
 	printf("�ж�Ϊ�գ�%d\n",Empty(L));
 	printf("��壺%d\n",InsertNextNode(L,p));
 	printf("%d\n",L->next->data);
 	printf("ǰ�壺%d\n",InsertPriorNode(p,s));
 	printf("%d\n",L->next->data);
 }
 int main(void){
 	test();
 	return 0;
 }
