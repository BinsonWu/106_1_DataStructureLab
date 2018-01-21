/*
 ============================================================================
 Name        : 32_公路建設.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int Cost;
	int Case;
}onecity_t;

typedef struct{
	int x;
	int y;
	int cost;
	int Case;
}edge;

int Enough(int *citycheck,int n);
int VisitAll(int *visit,int n);
void FindPath(int N,int Now,int cost);
void BubbleSort(int *data,int n);
void BubbleSort2(edge *data,int n);
void Quick_Sort(int *data,int left,int right);

onecity_t city[500][500];
int citycheck[500];
int visit[500];
int path[500];
int minpath[500];
int min;
int nth;

int main(void) {
	/*FILE *fpin,*fpout;
	fpin = fopen("Road.in","r");
	fpout = fopen("Road.out","w");*/
	edge MyEdge[2000];
	int N ,M;
	int i,j,k;
	int x,y,cost;
	for(i=0;i<500;i++){
		for(j=0;j<500;j++){
			city[i][j].Cost = -1;
			city[i][j].Case = -1;
		}
	}
	for(i=0;i<500;i++){
		citycheck[i] = -1;
		visit[i] = -1;
		path[i] = -1;
		minpath[i] = -1;
	}
	//fscanf(fpin,"%d%d",&N,&M);
	scanf("%d%d",&N,&M);
	//printf("N:%d M:%d\n",N,M);
	for(i=0;i<M;i++){
		//fscanf(fpin,"%d%d%d",&x,&y,&cost);
		scanf("%d%d%d",&x,&y,&cost);
		//printf("x:%d y:%d cost:%d\n",x,y,cost);
		/*if(city[x-1][y-1].Cost != -1 && city[x-1][y-1].Cost > cost ){
			city[x-1][y-1].Cost 	= cost;
			city[x-1][y-1].Case 	= i+1;
			city[y-1][x-1].Cost	= cost;
			city[y-1][x-1].Case 	= i+1;
			citycheck[x-1] = 1;
			citycheck[y-1] = 1;
		}else if(city[x-1][y-1].Cost == -1){
			city[x-1][y-1].Cost 	= cost;
			city[x-1][y-1].Case 	= i+1;
			city[y-1][x-1].Cost	= cost;
			city[y-1][x-1].Case 	= i+1;
			citycheck[x-1] = 1;
			citycheck[y-1] = 1;
		}

		if( Enough(citycheck,N) != 1 ){
			//fprintf(fpout,"0\n");
			printf("0\n");
			continue;
		}
		min = 1000000;
		for(j=0;j<500;j++){
			minpath[j] = -1;
		}
		nth = 0;
		for(j=0;j<N;j++){
			visit[j] = 1;
			FindPath(N,j,0);
			visit[j] = -1;
		}
		float ans = min/2;
		//fprintf(fpout,"%.2f ",ans);
		printf("%.2f ",ans);
		//BubbleSort(minpath,N-1);
		Quick_Sort(minpath,0,N-2);
		for(j=0;minpath[j] != -1;j++){
			if(j != N-2){
				//fprintf(fpout,"%d ",minpath[j]);
				printf("%d ",minpath[j]);
			}
			else{
				//fprintf(fpout,"%d",minpath[j]);
				printf("%d",minpath[j]);
			}
		}
		//fprintf(fpout,"\n");
		printf("\n");*/
		int Case[2000];
		int CityGroup[500];
		for(j=0;j<500;j++){
			CityGroup[j] = j;
		}
		for(j=0;j<2000;j++){
			Case[j] = -1;
		}
		MyEdge[i].x 		= x-1;
		MyEdge[i].y 		= y-1;
		MyEdge[i].cost 	= cost;
		MyEdge[i].Case 	= i;
		BubbleSort2(MyEdge,i+1);
		/*for(j=0;j<=i;j++){
			printf("X:%d ,Y:%d ,Cost:%d ,Case:%d\n",MyEdge[j].x,MyEdge[j].y,MyEdge[j].cost,MyEdge[j].Case);
		}*/
		int mincost = 0;
		int getNedge = 0;
		for(j=0;j<=i;j++){
			if(CityGroup[ MyEdge[j].x ] !=  CityGroup[ MyEdge[j].y ] ){
				int val = CityGroup[ MyEdge[j].y ];
				for(k=0;k<N;k++){
					if(CityGroup[k] == val)
						CityGroup[k] = CityGroup[ MyEdge[j].x ] ;
				}
				//printf("Choice Case : %d\n",MyEdge[j].Case);
				Case[ MyEdge[j].Case ] = 1;
				mincost += MyEdge[j].cost;
				getNedge++;
			}
			if(getNedge == N-1)
				break;
		}
		if(getNedge < N-1)
			printf("0\n");
		else{
			float ans = mincost/2.00;
			//printf("%d ",mincost);
			printf("%.2f ",ans);
			for(j=0;j<2000;j++){
				if(Case[j] == 1){
					printf("%d ",j+1);
				}
			}
			printf("\n");
		}
	}

	/*fclose(fpin);
	fclose(fpout);*/
	return EXIT_SUCCESS;
}

void FindPath(int N,int Now,int cost)
{
	int i;
	if(nth == N-1){
		int sumOld=0,sumNew=0;
		/*printf("Goal! Cost : %d , Min : %d ,",cost,min);
		printf("Now Path : ");*/
		for(i=0;i<nth;i++){
			//printf("%d ",path[i]);
			sumOld 	+= minpath[i];
			sumNew 	+= path[i];
		}
		//printf(", sumOld : %d , sumNew : %d\n",sumOld,sumNew);
		 if(sumOld == -(N-1)){
			min = cost;
			for(i=0;i<nth;i++){
				minpath[i] = path[i];
			}
		}else if(min > cost  ){
			min = cost;
			for(i=0;i<nth;i++){
				minpath[i] = path[i];
			}
		}else if(min == cost && sumNew < sumOld){
			min = cost;
			for(i=0;i<nth;i++){
				minpath[i] = path[i];
			}
		}

		return;
	}
    for(i=0;i<N;i++)
    {
        if(city[Now][i].Cost != -1 && visit[i] == -1)
        {
            visit[i] = 1;
            path[nth] = city[Now][i].Case;
            nth++;
            FindPath(N,i,cost + city[Now][i].Cost);
            path[nth] = -1;
            nth--;
            visit[i] = -1;
        }
    }
}

int Enough(int *citycheck,int n){
	int i;
	for(i=0;i<n;i++){
		if(citycheck[i] == -1)
			return 0;
	}
	return 1;
}

int VisitAll(int *visit,int n){
	int i;
	printf("%d\n",n);
	for(i=0;i<n;i++){
		printf("%d : %d \n" ,i,visit[i]);
		if(visit[i] == -1)
			return 0;
	}
	return 1;
}
void Quick_Sort(int *data,int left,int right){
    if(left < right){
        int i = left + 1, j = right, splitting = data[left], temp;
        do{
            while(i < right && data[i] <= splitting) i++;   // Note the "<" and "<="
            while(j > left && data[j] > splitting) j--;
            if(i < j){
            temp = data[i]; data[i] = data[j]; data[j] = temp;   // Note this line, swap data[i + 1] and data[i]
            }
        }while(i < j);
        temp = data[j]; data[j] = data[left]; data[left] = temp;   // Note this line, swap data[j] and the data[left] (splitting)
        Quick_Sort(data,left, j - 1);
        Quick_Sort(data, j + 1, right);
    }
}

void BubbleSort(int *data,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(data [j] > data[j+1] ){
				int temp;
				temp 			= data [j];
				data [j] 		= data [j+1];
				data [j+1] 	= temp;
			}
		}
	}
}
void BubbleSort2(edge *data,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(data[j].cost > data[j+1].cost ){
				int temp;
				temp 				= data[j].x;
				data[j].x 			= data[j+1].x;
				data[j+1].x 		= temp;
				temp 				= data[j].y;
				data[j].y 			= data[j+1].y;
				data[j+1].y 		= temp;
				temp 				= data[j].cost;
				data[j].cost 		= data[j+1].cost;
				data[j+1].cost 	= temp;
				temp 				= data[j].Case;
				data[j].Case 	= data[j+1].Case;
				data[j+1].Case = temp;
			}
		}
	}
}

