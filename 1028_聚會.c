

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FindPath(int **Map,int N,int Now,int *visit,int *min,int cost,int Goal);

int main()
{
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    int **Map,**Min;
    int i,j;
    Map = malloc(sizeof(void*)*N);
    Min = malloc(sizeof(void*)*N);
    for(i=0;i<N;i++)
    {
        Map[i] = malloc(sizeof(int)*N);
        Min[i] = malloc(sizeof(int)*N);
        for(j=0;j<N;j++)
        {
            Map[i][j] = -1;
            Min[i][j] = -1;
        }
    }
    for(i=0;i<M;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        Map[x-1][y-1] = v;
    }
    int minGo[1],visit[N];
    memset(visit,0,sizeof(visit));
    /*memset(PathCost,-1,sizeof(PathCost));
    memset(PathCost,10000,sizeof(PathCost));*/
    minGo[0] = 10000;



    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
    		if(i != j){
    			visit[i] = 1;
    			FindPath(Map,N,i,visit,minGo,0,j);
    			visit[i] = 0;
    		}
    		Min[i][j] = minGo[0];
    		minGo[0] = 10000;
    		//printf("i : %d , j : %d , Ans : %d\n",i,j,Min[i][j]);
		}
    }
    int MaxAns =0;
    for(i=0;i<N;i++){
		if(i != K-1){
			if(MaxAns < Min[i][K-1] + Min[K-1][i])
				MaxAns = Min[i][K-1] + Min[K-1][i];
		}
	}
    printf("%d\n",MaxAns);
    return 0;
}

void FindPath(int **Map,int N,int Now,int *visit,int *min,int cost,int Goal)
{
    int i;
    if(visit[Goal] == 1)
    {
    	if(cost < min[0])
    		min[0] = cost;
        return;
    }

    for(i=0;i<N;i++)
    {
        if(Map[Now][i] != -1 && visit[i] == 0)
        {
            visit[i] = 1;
            //printf("i : %d\n",i);
            FindPath(Map,N,i,visit,min,cost + Map[Now][i],Goal);
            visit[i] = 0;
        }
    }
}


