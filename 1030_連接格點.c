/*
 ============================================================================
 Name        : 31_連接格點.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int M,N;
	int V[1000001];
	int i,j,k,l;
	int inputx1,inputy1,inputx2,inputy2;
	int Ans = 0,cost = 0;
	memset(V,-1,1000001);
	scanf("%d%d",&M,&N);
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			V[i*N+j] = i*N+j;
		}
	}
	while(scanf("%d%d%d%d",&inputx1,&inputy1,&inputx2,&inputy2) != EOF){
		if( inputx1 == 0 && inputy1 == 0 && inputx2 == 0 && inputy2 == 0)
			break;
		int x1 = inputx1-1,y1 = inputy1-1,x2 = inputx2-1,y2 = inputy2-1;
		if( V[x1*N+y1] != V[x2*N+y2] ){
			int lit,big;
			if(V[x1*N+y1] < V[x2*N+y2]){
				lit 	= V[x1*N+y1];
				big 	= V[x2*N+y2];
			}
			else{
				lit 	= V[x2*N+y2];
				big 	= V[x1*N+y1];
			}
			for(i=0;i<M;i++){
				for(j=0;j<N;j++){
					if(V[i*N+j] == big)
						V[i*N+j] = lit;
				}
			}
			Ans++;
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<M-1;j++){
			if(V[j*N+i] != V[(j+1)*N+i]){
				int lit,big;
				if(V[j*N+i] < V[(j+1)*N+i]){
					lit 	= V[j*N+i];
					big 	=V[(j+1)*N+i];
				}
				else{
					lit 	= V[(j+1)*N+i];
					big 	= V[j*N+i];
				}
				for(k=0;k<M;k++){
					for(l=0;l<N;l++){
						if(V[k*N+l] == big)
							V[k*N+l] = lit;
					}
				}
				Ans++;
				cost++;
				//printf("$%d %d %d %d ,cost : %d\n",j,i,j,i,cost);
			}
			if(Ans == M*N-1)
				break;
		}
		if(Ans == M*N-1)
				break;
	}

	for(i=0;i<M;i++){
		for(j=0;j<N-1;j++){
			if(V[i*N+j] != V[i*N+j+1]){
				int lit,big;
				if(V[i*N+j] < V[i*N+j+1]){
					lit 	= V[i*N+j];
					big 	= V[i*N+j+1];
				}
				else{
					lit 	= V[i*N+j+1];
					big 	= V[i*N+j];
				}
				for(k=0;k<M;k++){
					for(l=0;l<N;l++){
						if(V[k*N+l] == big)
							V[k*N+l] = lit;
					}
				}
				Ans++;
				cost+=2;
			}
			if(Ans == M*N-1)
				break;
		}
		if(Ans == M*N-1)
			break;
	}
	printf("%d\n",cost);
	return EXIT_SUCCESS;
}

