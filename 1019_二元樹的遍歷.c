/*
 ============================================================================
 Name        : 20_二元樹的遍歷.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char val;
	int lch,rch;
}node_t,*pnode_t;

void PreOrder(pnode_t NodeList,int nth);
void InOrder(pnode_t NodeList,int nth);
void PostOrder(pnode_t NodeList,int nth);

int main(void) {
	int n;
	scanf("%d ",&n);
	int i;
	node_t NodeList[28];
	for(i=1;i<=n;i++){
		char c,val;
		int lch,rch;
		scanf("%c%c%d%c%d%c",&val,&c,&lch,&c,&rch,&c);
		NodeList[i].val = val;
		NodeList[i].lch = lch;
		NodeList[i].rch = rch;
		//printf("%d : %c %d %d\n",i,NodeList[i].val,NodeList[i].lch,NodeList[i].rch = rch);
	}
	PreOrder(NodeList,1);
	printf("\n");
	InOrder(NodeList,1);
	printf("\n");
	PostOrder(NodeList,1);
	printf("\n");
	return EXIT_SUCCESS;
}

void PreOrder(pnode_t NodeList,int nth){
	if(nth != 0){
		printf("%c",NodeList[nth].val);
		PreOrder(NodeList,NodeList[nth].lch);
		PreOrder(NodeList,NodeList[nth].rch);
	}
}

void InOrder(pnode_t NodeList,int nth){
	if(nth != 0){
		InOrder(NodeList,NodeList[nth].lch);
		printf("%c",NodeList[nth].val);
		InOrder(NodeList,NodeList[nth].rch);
	}
}

void PostOrder(pnode_t NodeList,int nth){
	if(nth != 0){
		PostOrder(NodeList,NodeList[nth].lch);
		PostOrder(NodeList,NodeList[nth].rch);
		printf("%c",NodeList[nth].val);
	}
}

