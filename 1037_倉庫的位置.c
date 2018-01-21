/*
 ============================================================================
 Name        : 38_倉庫的位置.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int *data,int N);
int Caculated(int *data,int N,int pos);

int main(void) {
	int T;
	int i,j,k;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		int N;
		int data[1000];
		scanf("%d",&N);
		/*long long int sum = 0;
		int ave;
		for(j=0;j<N;j++){
			scanf("%d",&data[j]);
			sum += data[j];
		}
		if(N==1){
			printf("%d 0\n",data[0]);
			continue;
		}
		sort(data,N);
		ave = sum / N;
		printf("Sum : %d\n",sum);
		//printf("Ave : %d\n",ave);
		for(j=0;j<N;j++){
			if(data[j] == ave){
				printf("%d %d\n",data[j],Caculated(data,N,data[j]));
				break;
			}
			else if(data[j] > ave){
				//printf("Close  1: %d , 2:%d.\n",data[j-1],data[j]);
				//printf("%d %d %d %d\n",data[j-2],data[j-1],data[j],data[j+1]);
				float choice1,choice2;
				choice1 = abs(data[j-1] - ave);
				choice2 = abs(data[j] - ave);
				if(choice1 > choice2 ){
					printf("%d %d\n",data[j],Caculated(data,N,data[j]));
				}else{
					printf("%d %d\n",data[j],Caculated(data,N,data[j-1]));
				}
				break;
			}
		}*/
		for(j=0;j<N;j++){
			scanf("%d",&data[j]);
		}
		if(N==1){
			printf("%d 0\n",data[0]);
			continue;
		}

		int sum[1000];
		int min = 100000000;
		int minpos = -1;
		for(j=0;j<N;j++)
			sum[j] = 0;
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				if(j!=k)
					sum[j] += abs(data[j] - data[k]);
			}
			//printf("Nth : %d,Sum : %d\n",j,sum[j]);
			if(sum[j] < min){
				min = sum[j];
				minpos = j;
			}
		}
		printf("%d %d\n",data[minpos],min);
	}
	return EXIT_SUCCESS;
}

void sort(int *data,int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N-1-i;j++){
			if(data[j] > data[j+1]){
				int temp;
				temp 		= data[j];
				data[j] 		= data[j+1];
				data[j+1] 	= temp;
			}
		}
	}
}

int Caculated(int *data,int N,int pos){
	int i;
	int sum = 0;
	for(i=0;i<N;i++){
		sum += abs(data[i]-pos);
	}
	return sum;
}

