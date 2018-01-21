/*
 ============================================================================
 Name        : Problem_F.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	while(scanf("%d",&n) != EOF){
		int Matrix[101][101];
		if(n == 1){
			scanf("%d",&Matrix[0][0]);
			printf("Yes!\n");
			continue;
		}
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&Matrix[i][j]);
			}
		}
		int IfSymmetry = 1;
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if( Matrix[i][j] != Matrix[j][i] ){
					IfSymmetry = 0;
					break;
				}
			}
		}
		if(IfSymmetry == 1)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	return EXIT_SUCCESS;
}

