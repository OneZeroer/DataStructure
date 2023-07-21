#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MaxSize 50

typedef struct {
	int data[MaxSize];
	int top;
} SqstackInt;
typedef struct {
	char data[MaxSize];
	int top;
} SqstackChar;

void InitStackChar(SqstackChar *S){
	S->top = -1;
}

void InitStackInt(SqstackInt *S){
	S->top = -1;
} 

/*���ʽ�Ϸ��ʲ���Ҫ���intջ*/
bool StackEmpty(SqstackChar S){
	if(S.top == -1) return true;
	return false;
}

bool PopInt(SqstackInt *S,int *x){
	//ջΪ�ղ���Pop
	if(S->top == -1) return false; 
	(*x) = S->data[(S->top)--];
	return true;
}

bool PopChar(SqstackChar *S,char *x){
	//ջΪ�ղ���Pop
	if(S->top == -1) return false; 
	(*x) = S->data[(S->top)--];
	return true;
}

bool GetTopInt(SqstackInt S,int *x){
	if(S.top == -1) return false;
	(*x) = S.data[S.top];
	return true;
}

bool GetTopChar(SqstackChar S,char *x){
	if(S.top == -1) return false;
	(*x) = S.data[S.top];
	return true;
}

bool PushInt(SqstackInt *S,int x){
	//ջ������Push 
	if(S->top == MaxSize - 1) return false;
	S->data[++(S->top)] = x;
	return true;
}
bool PushChar(SqstackChar *S,char x){
	//ջ������Push 
	if(S->top == MaxSize - 1) return false;
	S->data[++(S->top)] = x;
	return true;
}

/*�Ӻ��������� a sign b*/
int compute(int a,int b,char sign){
	//a sign b; ensure a,b is legal
	switch(sign){
		case '-' : return (a - b);
		case '+' : return (a + b);
		case '*' : return (a * b);
		case '/' : return (a / b);
	}
	return 0;
}

/*��׺����*/
int Computation(char *s){
	SqstackInt stackNum;
	SqstackChar stackSign;
	InitStackInt(&stackNum);
	InitStackChar(&stackSign);
	int num=0,i=0;
	char shead;
	while(s[i]!=0){
		if('0' <= s[i] && s[i] <= '9'){
			//convert num
			num = 0;
			for(;'0' <= s[i] && s[i] <= '9';){
				num = num * 10 + (s[i++] - '0');
			}
			PushInt(&stackNum,num);
		}else{
			switch(s[i]){
				case '-' :
				case '+' :
				while(1){
						GetTopChar(stackSign,&shead);
						if(shead == '(' || StackEmpty(stackSign)){
							PushChar(&stackSign,s[i]);break;
						}else{
							PopChar(&stackSign,&shead);
							int a=0,b=0;
							//ע��˳�� 
							PopInt(&stackNum,&b);
							PopInt(&stackNum,&a);
							PushInt(&stackNum,compute(a,b,shead));	
						}
					}
					break;
				case '*' :
				case '/' :
					while(1){
						GetTopChar(stackSign,&shead);
						if(shead == '(' || shead == '+' || shead == '-' || StackEmpty(stackSign)){
							PushChar(&stackSign,s[i]);break;
						}else{
							PopChar(&stackSign,&shead);
							int a=0,b=0;
							//ע��˳�� 
							PopInt(&stackNum,&b);
							PopInt(&stackNum,&a);
							PushInt(&stackNum,compute(a,b,shead));	
						}
					}
					break;
				case '(' :
					PushChar(&stackSign,s[i]);break;
				case ')' :
					while(1){
						PopChar(&stackSign,&shead);
						if (shead == '(') break;
						int a=0,b=0;
						//ע��˳�� 
						PopInt(&stackNum,&b);
						PopInt(&stackNum,&a);
						PushInt(&stackNum,compute(a,b,shead));
					}
					break;			
			}
			i++;
		}
	}
	while(!StackEmpty(stackSign)){
		PopChar(&stackSign,&shead);
		int a=0,b=0;
		//ע��˳�� 
		PopInt(&stackNum,&b);
		PopInt(&stackNum,&a);
		PushInt(&stackNum,compute(a,b,shead));
	}
	PopInt(&stackNum,&num);
	return num;
}


void test(){
	char s[MaxSize];
	printf("������һ���Ϸ��ı��ʽ����֤����С��%d:\n",MaxSize);
	scanf("%s",s);
	int n = Computation(s);
	printf("�����: %d\n",n);
}

int main(void){
	test();
	return 0;
}
