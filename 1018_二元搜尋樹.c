/*
 ============================================================================
 Name        : 19_二元搜尋樹.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *LeftChild,*RightChild;
}node_t,*pnode_t;

void AddNode(pnode_t root , int val);
void PrintInorder(pnode_t root);
void PrintPostorder(pnode_t root);

int PrintTime;
int n;

int main(void) {
	pnode_t root =NULL;

	scanf("%d",&n);
	int i;
	int val;
	for(i=0;i<n;i++){
		scanf("%d",&val);
		if(i==0){
			root = malloc(sizeof(node_t));
			root->val 				= val;
			root->LeftChild 		= NULL;
			root->RightChild 	= NULL;
		}else{
			AddNode(root,val);
		}
	}
	PrintTime = 0;
	PrintInorder(root);
	PrintTime = 0;
	PrintPostorder(root);
	return EXIT_SUCCESS;
}

void AddNode(pnode_t root , int val){
	if(val >= root->val){
		if(root->RightChild == NULL){
			root->RightChild		 				= malloc(sizeof(node_t));
			root->RightChild->val 				= val;
			root->RightChild->LeftChild 	= NULL;
			root->RightChild->RightChild 	= NULL;
		}else{
			AddNode(root->RightChild,val);
		}
	}else{
		if(root->LeftChild == NULL){
			root->LeftChild 							= malloc(sizeof(node_t));
			root->LeftChild->val 					= val;
			root->LeftChild->LeftChild 		= NULL;
			root->LeftChild->RightChild 	= NULL;
		}else{
			AddNode(root->LeftChild,val);
		}
	}
}


void PrintInorder(pnode_t root){
	if(root != NULL){
		PrintInorder(root->LeftChild);
		PrintTime++;
		if(PrintTime == n)
			printf("%d\n",root->val);
		else
			printf("%d ",root->val);
		PrintInorder(root->RightChild);
	}
}

void PrintPostorder(pnode_t root){
	if(root != NULL){
		PrintPostorder(root->LeftChild);
		PrintPostorder(root->RightChild);
		PrintTime++;
		if(PrintTime == n)
			printf("%d\n",root->val);
		else
			printf("%d ",root->val);
	}
}

