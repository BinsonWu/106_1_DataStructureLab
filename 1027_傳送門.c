/*
 ============================================================================
 Name        : 28_傳送門.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FindPath(int **Map,int N,int Now,int *visit,int *PathCost,int *min,int cost,int K);
void BubbleSort(int *data,int n);
void Quick_Sort(int *data,int left,int right);

int main()
{
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    int **Map;
    int i,j;
    Map = malloc(sizeof(void*)*N);
    for(i=0;i<N;i++)
    {
        Map[i] = malloc(sizeof(int)*N);
        for(j=0;j<N;j++)
        {
            Map[i][j] = -1;
        }
    }
    for(i=0;i<M;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        Map[x-1][y-1] = v;
        Map[y-1][x-1] = v;
    }
    int min[1],visit[N],PathCost[N];
    memset(visit,0,sizeof(visit));
    memset(PathCost,-1,sizeof(PathCost));
    visit[0] = 1;
    min[0] = 10000;
    FindPath(Map,N,0,visit,PathCost,min,0,K);
    printf("%d\n",min[0]);


    return 0;
}

void FindPath(int **Map,int N,int Now,int *visit,int *PathCost,int *min,int cost,int K)
{
    int i;
    if(visit[N-1] == 1)
    {
    	int TempData[N];
    	for(i=0;i<N;i++){
    		TempData[i] = PathCost[i];
		}
    	Quick_Sort(TempData,0,N-1);
		//BubbleSort(TempData,N);
    	/*for(i=0;i<N;i++){
			printf("%d ",TempData[i]) ;
		}
    	printf("\n");*/
    	for(i=N-1;i>N-1-K && TempData[i]!=-1;i--){
    		cost -= TempData[i];
    	}
    	if(cost < min[0])
    		min[0] = cost;
        return;
    }

    for(i=0;i<N;i++)
    {
        if(Map[Now][i] != -1 && visit[i] == 0)
        {
            visit[i] = 1;
            PathCost[i] = Map[Now][i];
            FindPath(Map,N,i,visit,PathCost,min,cost + Map[Now][i],K);
            visit[i] = 0;
            PathCost[i] = -1;
        }
    }
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
			if(data [j] < data[j+1] ){
				int temp;
				temp 			= data [j];
				data [j] 		= data [j+1];
				data [j+1] 	= temp;
			}
		}
	}
}

