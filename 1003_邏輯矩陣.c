/*
 ============================================================================
 Name        : Problem_D.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Matrix[101][101];

int IfAllRowEven(int n);
int IfAllColEven(int n);

int main(void) {
	int n;

	while( scanf("%d",&n)){
		if(n == 0){
			break;
		}
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&Matrix[i][j]);
			}
		}
		if( IfAllRowEven(n) == 1 && IfAllColEven(n) == 1){
			printf("OK\n");
		}
		else{
			int IfFindChangeBit = 0;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					Matrix[i][j] = (Matrix[i][j] +1) %2;
					if( IfAllRowEven(n) == 1 && IfAllColEven(n) == 1){
						IfFindChangeBit = 1;
						printf("Change bit (%d,%d)\n",i+1,j+1);
						break;
					}
					Matrix[i][j] = (Matrix[i][j] +1) %2;
				}
			}
			if(IfFindChangeBit == 0){
				printf("Corrupt\n");
			}
		}
	}
	return EXIT_SUCCESS;
}

int IfAllRowEven(int n){
	int i,j;
	int IfEven=1;
	for(i=0;i<n;i++){
		int sum=0;
		for(j=0;j<n;j++){
			sum+= Matrix[i][j];
		}
		if(sum%2 != 0){
			IfEven=0;
			break;
		}
	}
	return IfEven;
}

int IfAllColEven(int n){
	int i,j;
		int IfEven=1;
		for(i=0;i<n;i++){
			int sum=0;
			for(j=0;j<n;j++){
				sum+= Matrix[j][i];
			}
			if(sum%2 != 0){
				IfEven=0;
				break;
			}
		}
		return IfEven;
}

