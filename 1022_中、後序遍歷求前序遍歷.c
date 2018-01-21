/*
 ============================================================================
 Name        : 23_中後序遍歷求前序遍歷.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Tree[10000];

void CreateTree(char InOrderStr[26], char PostOrderStr[26] ,int nth);

int main(void) {
	memset(Tree,'\0',sizeof(Tree));
	char InOrderTree[26],PostOrderTree[26],PreOrderTree[26];
	memset(InOrderTree,'\0',sizeof(InOrderTree));
	memset(PostOrderTree,'\0',sizeof(PostOrderTree));
	memset(PreOrderTree,'\0',sizeof(PreOrderTree));
	char c;
	scanf("%s%c%s%c",InOrderTree,&c,PostOrderTree,&c);

	CreateTree(InOrderTree,PostOrderTree,0);
	printf("\n");
	return EXIT_SUCCESS;
}

void CreateTree(char InOrderStr[26], char PostOrderStr[26] ,int nth){
	if(InOrderStr[0] != '\0'){
		//printf("InOrderStr : %s , PostOrderStr : %s\n",InOrderStr,PostOrderStr);
		int TreeLen = strlen(InOrderStr) ;
		Tree[nth] = PostOrderStr[ TreeLen - 1 ];
		printf("%c",Tree[nth]);
		char NewInOrderStrLeft[26],NewPostOrderStrLeft[26];
		char NewInOrderStrRight[26],NewPostOrderStrRight[26];
		memset(NewInOrderStrLeft,'\0',sizeof(NewInOrderStrLeft));
		memset(NewPostOrderStrLeft,'\0',sizeof(NewPostOrderStrLeft));
		memset(NewInOrderStrRight,'\0',sizeof(NewInOrderStrRight));
		memset(NewPostOrderStrRight,'\0',sizeof(NewPostOrderStrRight));
		int i,j;

		// InOrder
		for(i=0;i<TreeLen;i++){
			if(InOrderStr[i] == Tree[nth] ){
				break;
			}else{
				NewInOrderStrLeft[i] = InOrderStr[i];
			}
		}
		int Line = i+1;
		for(j=0;j<TreeLen-Line;j++){
			NewInOrderStrRight[j] = InOrderStr[Line+j];
		}
		//printf("InOrder ,Left = %s,Right = %s\n",NewInOrderStrLeft,NewInOrderStrRight);

		// PostOrder
		for(i=0;i < strlen(NewInOrderStrLeft);i++){
			NewPostOrderStrLeft[i] = PostOrderStr[i];
		}
		for(;i < TreeLen-1;i++){
			NewPostOrderStrRight[ i - strlen(NewInOrderStrLeft) ] = PostOrderStr[i];
		}
		//printf("PostOrderStr ,Left = %s,Right = %s\n",NewPostOrderStrLeft,NewPostOrderStrRight);

		CreateTree(NewInOrderStrLeft,NewPostOrderStrLeft,0);
		CreateTree(NewInOrderStrRight,NewPostOrderStrRight,0);
	}
}


