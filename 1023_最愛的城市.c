/*
 ============================================================================
 Name        : 24_最愛的城市.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct city{
	int Path[10];
}city_t,*pcity_t;

void PtoP(pcity_t AllCity,int e,int n,int now,int cost);

int MinLength;
int Check[10];

int main(void) {
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
		MinLength = 10000;
		city_t AllCity[10];
		int i,j;
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				AllCity[i].Path[j] = -1;
			}
		}
		for(i=0;i<10;i++){
			Check[i] = 0;
		}

		int x,y;
		int val;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&val);
			AllCity[x-1].Path[y-1] = val;
			AllCity[y-1].Path[x-1] = val;
		}
		int s,e;
		scanf("%d%d",&s,&e);
		PtoP(AllCity,e-1,n,s-1,0);
		if(MinLength == 10000)
			printf("No path\n");
		else
			printf("%d\n",MinLength);
	}
	return EXIT_SUCCESS;
}

void PtoP(pcity_t AllCity,int e,int n,int now,int cost){
	Check[now] = 1;
	if(now == e){
		//printf("Goal!\n");
		if(cost < MinLength)
			MinLength = cost;
		Check[now] = 0;
		return;
	}
	if(now != e){
		//printf("Now : %d \n",now);
		int i;
		for(i=0;i<n;i++){
			if( i == now)
				continue;
			if( AllCity[now].Path[i] != -1 && Check[i] == 0){
				int val = AllCity[now].Path[i];
				PtoP(AllCity,e,n,i,cost+val);
			}
		}
	}
	Check[now] = 0;
}

