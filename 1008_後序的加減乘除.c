/*
 ============================================================================
 Name        : Problem_I.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
	int mystack[15];
	int top;
}stack_t,*pstack_t;

void push( pstack_t stk,int val );
int pop( pstack_t stk );

int main(void) {
	char str[16];
	char c;

	while(scanf("%s%c",str,&c) != EOF){
		int strLen = strlen(str);
		int i;
		stack_t stk;
		stk.top = -1;
		for(i=0;i<strLen;i++){
			if( '0' <= str[i] && str[i] <= '9'  ){
				push(&stk,str[i] - '0');
			}
			else{
				if(stk.top < 1){
					printf("Input Error\n");
					break;
				}
				else{
					int a,b;
					b = pop(&stk);
					a = pop(&stk);
					if(str[i] == '+'){
						a = a+b;
					}else if( str[i] == '-' ){
						a = a-b;
					}else if( str[i] == '*' ){
						a = a*b;
					}else if( str[i] == '/' ){
						a = a/b;
					}else{
						printf("Input Error\n");
						break;
					}
					push(&stk,a);
				}
			}
			if(i==strLen-1){
				if(stk.top == 0)
					printf("%d\n",stk.mystack[0]);
				else
					printf("Input Error\n");
			}
		}
	}
	return EXIT_SUCCESS;
}

void push( pstack_t stk ,int val){
	if(stk->top != 15){
		stk->top++;
		stk->mystack[stk->top] = val;
	}
}

int  pop( pstack_t stk ){
	if(stk->top != -1){
		stk->top--;
		return stk->mystack[stk->top+1];
	}
	return -1;
}

