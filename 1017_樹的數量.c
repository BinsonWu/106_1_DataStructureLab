/*
 ============================================================================
 Name        : 18_樹的數量.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	int node[101];
	int TreeNum = n;
	for(i=0;i<101;i++){
		node[i] = -1;
	}
	int parent,child;
	for(i=0;i<k;i++){
		scanf("%d%d",&parent,&child);
		if(node[child-1] == -1){
			node[child-1] = 1;
			TreeNum--;
		}
		//printf("%d %d \n",parent,child);
	}
	printf("%d\n",TreeNum);
	int nth =0;
	for(i=0;i<n;i++){
			if(node[i] == -1){
				printf("%d",i+1);
				nth++;
				if(nth == TreeNum)
					printf("\n");
				else
					printf(" ");
			}
	}
	return EXIT_SUCCESS;
}

