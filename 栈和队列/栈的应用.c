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


/* 基本操作 copy */
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

/* 括号匹配 */
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

/*中缀转后缀，输入m要保证合法,最大数字长度不超过10*/
bool Convert(char *s,char *h){
	Sqstack stack;
	InitStack(&stack);
	char num[10],shead;
	int i = 0,count = 0;
	while (s[i]!='\0'){
		if(s[i]==' '){
			i++;continue;
		}else if ('0' <= s[i] && s[i] <= '9'){
			//数字的判断
			int j; 
			for (j=0;'0' <= s[i] && s[i] <= '9';j++){
				num[j] = s[i++];
			}
			num[j] = ' ';
			//赋给h 
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
						//为了美观 
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
中缀表达式计算
需要用到两种栈，重写写一个c文件了。。。 
*/



void test(){
	char s[MaxSize] , h[MaxSize];
	printf("请输入一串括号：\n"); 
	scanf("%s",s);
	bool t = bracketCheck(s);
	printf("括号匹配结果 : %d\n",t);
	memset(s,'\0',MaxSize);
	printf("请输入一个合法的中缀表达式：\n");
	//由于scanf，不能读入空格，因此输入较为严格 
	scanf("%s",s);
	/*
	fgets(s, MaxSize, stdin);
	s[strcspn(s, "\n")] = '\0';
	*/
	printf("表达式：%s\n",s);
	printf("转化结果 : %d\n",Convert(s,h));
	printf("转化后 : %s\n",h); 
} 

int main(void){
	test();
	return 0;
}
