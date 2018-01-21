/*
 ============================================================================
 Name        : 30_奶牛跨欄.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FindPath(int **Map,int N,int Now,int *visit,int *path,int *min,int cost,int Goal);

int main()
{
    int N,M,T;
    scanf("%d%d%d",&N,&M,&T);
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
    }
    int min[1],visit[N],Path[N];
    memset(Path,-1,sizeof(Path));
    memset(visit,0,sizeof(visit));


    for(i=0;i<T;i++){
    	int S,E;
    	min[0] = 1000000;
    	scanf("%d%d",&S,&E);
    	visit[S-1] = 1;
    	FindPath(Map,N,S-1,visit,Path,min,0,E-1);
    	visit[S-1] = 0;
    	if(min[0] == 1000000)
    		printf("-1\n");
    	else
    		printf("%d\n",min[0]);
    }
    return 0;
}

void FindPath(int **Map,int N,int Now,int *visit,int *path,int *min,int cost,int Goal)
{
    int i;
    if(visit[Goal] == 1)
    {
    	int max=0;
    	for(i=0;i<N;i++){
    		if(path[i] > max)
    			max  = path[i];
    	}
    	if(max < min[0])
    		min[0] = max;
        return;
    }

    for(i=0;i<N;i++)
    {
        if(Map[Now][i] != -1 && visit[i] == 0)
        {
            visit[i] = 1;
            path[i] = Map[Now][i];
            //printf("i : %d\n",i);
            FindPath(Map,N,i,visit,path,min,cost + Map[Now][i],Goal);
            visit[i] = 0;
            path[i] = -1;
        }
    }
}


