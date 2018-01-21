#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i,j,k;
    int Node[500];
    int map[500][500];
    int visit[500];
    for(i=0;i<T;i++)
    {
        for(j=0;j<500;j++)
        {
            Node[j] = -1;
            visit[j] = 0;
            for(k=0;k<500;k++)
			{
            	map[j][k] = -1;
			}
        }
        int N,E;
        scanf("%d%d",&N,&E);
        for(j=0;j<E;j++)
        {
        	int x,y,cost;
            scanf("%d%d%d",&x,&y,&cost);
            map[x][y] = cost;
            map[y][x] = cost;
            if(j==0){
            	Node[0] = x;
            	visit[x] = 1;
            }
        }
        int len=1;
        int min,temp=0;
        int TotalCost = 0;
        min = 10000;
        for(j=0  ;j<len;j++){
        	for(k=0;k<N;k++){
        		//printf("Node[j] : %d,k : %d , map[ Node[j] ][k] : %d,visit[k] : %d\n",Node[j],k,map[ Node[j] ][k],visit[k]);
        		if( Node[j] != k && map[ Node[j] ][k] >= 0 && map[ Node[j] ][k] < min && visit[k] == 0){
        			min = map[ Node[j] ][k],temp = k;
        		}
        	}
        	if(j == len-1){
        		//printf("Temp : %d,Min : %d\n",temp,min);
        		Node[len] = temp;
        		visit[temp] = 1;
        		TotalCost += min;
        		j =-1;
        		len++;
        		min = 10000;
        		temp = -1;
        	}
        	if(len == N)
        		break;
        }
        printf("%d\n",TotalCost);
    }
    return 0;
}


