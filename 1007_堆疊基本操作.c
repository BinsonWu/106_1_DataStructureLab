/*
 ============================================================================
 Name        : Problem_H.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	int mystack[4];
	int top;
}stack_t;

void printStack(stack_t stk);

int main(void) {
	int order;
	stack_t stk;
	stk.top=-1;
	while( scanf("%d",&order) != EOF ){
		if(order == 1){
			int value;
			scanf("%d",&value);
			if(stk.top != 3){
				stk.top++;
				stk.mystack[stk.top] = value;
				printStack(stk);
			}
			else{
				printf("Stack Full\n");
			}
		}
		else if(order == 2){
			if(stk.top != -1){
				stk.top--;
				printStack(stk);
			}
			if(stk.top == -1){
				printf("Stack Empty\n");
			}
		}
		else{
			printf("Error Order!\n");
		}
	}
	return EXIT_SUCCESS;
}

void printStack(stack_t stk){
	int i;
	for(i=0;i<=stk.top;i++){
		if(i == stk.top)
			printf("%d\n",stk.mystack[i]);
		else
			printf("%d ",stk.mystack[i]);
	}
}

