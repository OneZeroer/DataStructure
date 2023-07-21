#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MaxSize 50
#define Elemtype char

typedef struct {
	Elemtype data[MaxSize];
	int top;
} Sqstack;


/* �������� copy */
void InitStack(Sqstack *S){
	S->top = -1;
} 

bool StackEmpty(Sqstack S){
	if(S.top == -1) return true;
	return false;
}

bool Pop(Sqstack *S,Elemtype *x){
	//ջΪ�ղ���Pop
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
	//ջ������Push 
	if(S->top == MaxSize - 1) return false;
	S->data[++(S->top)] = x;
	return true;
}

/* ����ƥ�� */
bool bracketCheck(char *s){
	int i = 0;
	char rev = 0;
	Sqstack stack;
	InitStack(&stack);
	while (s[i] != '\0'){
		switch(s[i]){
			case '(' : 
				Push(&stack,s[i]);break;
			case '[' :
				Push(&stack,s[i]);break;
			case '{' :
				Push(&stack,s[i]);break;
			case ')' :
				Pop(&stack,&rev);
				if(rev == '(') break;
				return false;
			case ']' :
				Pop(&stack,&rev);
				if(rev == '[') break;
				return false;
			case '}' :
				Pop(&stack,&rev);
				if(rev == '{') break;
				return false;
			default :
				return false;
		}
		i++;
	}
	if(StackEmpty(stack)) return true;
	return false;
}

/*��׺ת��׺������mҪ��֤�Ϸ�,������ֳ��Ȳ�����10*/
bool Convert(char *s,char *h){
	Sqstack stack;
	InitStack(&stack);
	char num[10],shead;
	int i = 0,count = 0;
	while (s[i]!='\0'){
		if(s[i]==' '){
			i++;continue;
		}else if ('0' <= s[i] && s[i] <= '9'){
			//���ֵ��ж�
			int j; 
			for (j=0;'0' <= s[i] && s[i] <= '9';j++){
				num[j] = s[i++];
			}
			num[j] = ' ';
			//����h 
			for (int k=0;k<=j;k++,count++){
				h[count] = num[k];
			}
		}else{
			switch(s[i]){
				case '(' :
					Push(&stack,s[i]);
					break;
				case ')' :
					while(1){
						Pop(&stack,&shead);
						if(shead == '(') break;
						h[count++] = shead;
						//Ϊ������ 
						h[count++] = ' ';	
					}
					break;
				case '-' :
				case '+' :
					while(1){
						GetTop(stack,&shead);
						if(shead == '(' || StackEmpty(stack)){
							Push(&stack,s[i]);break;
						}else{
							Pop(&stack,&shead);
							h[count++] = shead; 
							h[count++] = ' ';	
						}
					}
					break;
				case '*':
				case '/':
					while(1){
						GetTop(stack,&shead);
						if(shead == '(' || shead == '+' || shead == '-' || StackEmpty(stack)){
							Push(&stack,s[i]);break;
						}else{
							Pop(&stack,&shead);
							h[count++] = shead; 
							h[count++] = ' ';	
						}
					}
					break;
			}
			i++;
		}
	}
	while(!StackEmpty(stack)){
		Pop(&stack,&shead);
		h[count++] = shead; 
		h[count++] = ' ';
	}
	h[count++] = '\0';
	return true;
}

/*
��׺���ʽ����
��Ҫ�õ�����ջ����ддһ��c�ļ��ˡ����� 
*/



void test(){
	char s[MaxSize] , h[MaxSize];
	printf("������һ�����ţ�\n"); 
	scanf("%s",s);
	bool t = bracketCheck(s);
	printf("����ƥ���� : %d\n",t);
	memset(s,'\0',MaxSize);
	printf("������һ���Ϸ�����׺���ʽ��\n");
	//����scanf�����ܶ���ո���������Ϊ�ϸ� 
	scanf("%s",s);
	/*
	fgets(s, MaxSize, stdin);
	s[strcspn(s, "\n")] = '\0';
	*/
	printf("���ʽ��%s\n",s);
	printf("ת����� : %d\n",Convert(s,h));
	printf("ת���� : %s\n",h); 
} 

int main(void){
	test();
	return 0;
}
