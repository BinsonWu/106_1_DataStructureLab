/*
 ============================================================================
 Name        : Problem_G.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int r,c;
	scanf("%d%d",&r,&c);
	int Matric[r][c];
	int i,j;
	for(i = 0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&Matric[i][j]);
		}
	}

	for(i = 0;i<c;i++){
		for(j=0;j<r;j++){
			printf("%d ",Matric[j][i]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}

