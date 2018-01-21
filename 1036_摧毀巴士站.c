/*
 ============================================================================
 Name        : 37_摧毀巴士站.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int nthpath;
int iffind;
int maxcount;
void FindAllPath(int n,int g[50][50],int Now,int nth,int *temppath,int *StationVisitNum,int *visit,int k);

int main(void) {
	int n,m,k;
	int i,j,l;
	scanf("%d%d%d",&n,&m,&k);
	int g[50][50];
	int StationVisitNum[50];
	int visit[50];

	for(i=0;i<n;i++){
		StationVisitNum[i] = 0;
		visit[i] = 0;
		for(j=0;j<n;j++){
			g[i][j] = 0;
		}
	}
	visit[0]=1;

	for(i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(g[x-1][y-1] == 0){
			g[x-1][y-1] = 1;
		}
	}
	nthpath = 0;
	int temppath[n];
	for(i=0;i<n;i++){
		temppath[i] = -1 ;
	}

	int destroy = 0;
	iffind = 0;
	maxcount = 0;
	while(1){
		FindAllPath(n,g,0,0,temppath,StationVisitNum,visit,k);
		if(iffind == 0)
			break;
		destroy++;
		int hadfind=0;
		for(i=maxcount;i>0;i--){
			if(hadfind)
				break;
			for(j=0;j<n;j++){
				if(StationVisitNum[j] == i){
					//printf("Destroy %d.\n",j);
					for(l=0;l<n;l++){
							g[l][j] = 0;
					}
					hadfind = 1;
					break;
				}
			}
		}
		nthpath = 0;
		iffind = 0;
		maxcount = 0;
		for(i=0;i<n;i++){
			temppath[i] = -1 ;
			StationVisitNum[i] = 0;
		}
	}
	printf("%d\n",destroy);
	return EXIT_SUCCESS;
}

void FindAllPath(int n,int g[50][50],int Now,int nth,int *temppath,int *StationVisitNum,int *visit,int k){
	int i;
	//printf("Now : %d\n",Now);
	if(Now == n-1){
		if(nth <= k){
			for(i=0;i<nth-1;i++){
				//printf("%d ", temppath[i] );
				StationVisitNum[temppath[i]]++;
				if(maxcount < StationVisitNum[temppath[i]])
					maxcount = StationVisitNum[temppath[i]];
			}
			//printf("%d\n",Now);
			nthpath++;
			iffind = 1;
		}
		return ;
	}
	for(i=0;i<n;i++){
		if( g[Now][i] == 1 && visit[i] == 0){
			 visit[i] = 1;
			temppath[nth] = i;
			FindAllPath(n,g,i,nth+1,temppath,StationVisitNum,visit,k);
			 visit[i] =0;
			temppath[nth] = 0;
		}
	}

}

