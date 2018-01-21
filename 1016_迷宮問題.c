/*
 ============================================================================
 Name        : 17_迷宮問題.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Map[101][101];
int MinMove;

void Move(int NowX,int NowY,int Count,int N,int M,int EndX,int EndY);

int main(void) {
	MinMove = 10000;
	int i,j;
	for(i=0;i<101;i++){
		for(j=0;j<101;j++){
			Map[i][j] = -1;
		}
	}
	int T;
	scanf("%d",&T);
	int k;
	for(k=0;k<T;k++)
	{
		int N,M;
		scanf("%d %d ",&N,&M);
		char c;
		int StartX,StartY;
		int EndX,EndY;
		char State;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				scanf("%c",&State);
				if(State == 'S'){
					Map[i][j] = 1;
					StartX = i;
					StartY = j;
				}
				if(State == 'E'){
					Map[i][j] = 0;
					EndX = i;
					EndY = j;
				}
				if(State == '-'){
					Map[i][j] = 0;
				}
				if(State == '#'){
					Map[i][j] = 1;
				}
			}
			scanf("%c",&c);
		}

		/*for(i=0;i<N;i++){
			printf("%3d : ",i);
			for(j=0;j<M;j++){
				printf("%d",Map[i][j]);
			}
			printf("\n");
		}*/

		// 0		1 		2 		3
		// x-1	x+1	y-1	y+1
		int FourMoveX[4],FourMoveY[4];
		if(StartX > EndX && StartY > EndY){
			FourMoveX[0] = -1;
			FourMoveY[0] = 0;
			FourMoveX[1] = 0;
			FourMoveY[1] = -1;
			FourMoveX[2] = 1;
			FourMoveY[2] = 0;
			FourMoveX[3] = 0;
			FourMoveY[3] = 1;
		}
		else if(StartX > EndX && StartY == EndY){
			FourMoveX[0] = -1;
			FourMoveY[0] = 0;
			FourMoveX[1] = 1;
			FourMoveY[1] = 0;
			FourMoveX[2] = 0;
			FourMoveY[2] = -1;
			FourMoveX[3] = 0;
			FourMoveY[3] = 1;
		}
		else if(StartX > EndX && StartY < EndY){
			FourMoveX[0] = -1;
			FourMoveY[0] = 0;
			FourMoveX[1] = 0;
			FourMoveY[1] = 1;
			FourMoveX[2] = 1;
			FourMoveY[2] = 0;
			FourMoveX[3] = 0;
			FourMoveY[3] = -1;
		}
		else if(StartX < EndX && StartY > EndY){
			FourMoveX[0] = 1;
			FourMoveY[0] = 0;
			FourMoveX[1] = 0;
			FourMoveY[1] = -1;
			FourMoveX[2] = -1;
			FourMoveY[2] = 0;
			FourMoveX[3] = 0;
			FourMoveY[3] = 1;
		}
		else if(StartX < EndX && StartY == EndY){
			FourMoveX[0] = 1;
			FourMoveY[0] = 0;
			FourMoveX[1] = -1;
			FourMoveY[1] = 0;
			FourMoveX[2] = 0;
			FourMoveY[2] = -1;
			FourMoveX[3] = 0;
			FourMoveY[3] = 1;
		}
		else if(StartX < EndX && StartY < EndY){
			FourMoveX[0] = 1;
			FourMoveY[0] = 0;
			FourMoveX[1] = 0;
			FourMoveY[1] = 1;
			FourMoveX[2] = -1;
			FourMoveY[2] = 0;
			FourMoveX[3] = 0;
			FourMoveY[3] = -1;
		}
		else if(StartX == EndX && StartY > EndY){
			FourMoveX[0] = 0;
			FourMoveY[0] = -1;
			FourMoveX[1] = 0;
			FourMoveY[1] = 1;
			FourMoveX[2] = 1;
			FourMoveY[2] = 0;
			FourMoveX[3] = -1;
			FourMoveY[3] = 0;
		}
		else if(StartX == EndX && StartY == EndY){
			FourMoveX[0] = 0;
			FourMoveY[0] = -1;
			FourMoveX[1] = 0;
			FourMoveY[1] = 1;
			FourMoveX[2] = 1;
			FourMoveY[2] = 0;
			FourMoveX[3] = -1;
			FourMoveY[3] = 0;
		}
		else if(StartX == EndX && StartY < EndY){
			FourMoveX[0] = 0;
			FourMoveY[0] = 1;
			FourMoveX[1] = 0;
			FourMoveY[1] = -1;
			FourMoveX[2] = 1;
			FourMoveY[2] = 0;
			FourMoveX[3] = -1;
			FourMoveY[3] = 0;
		}

		for(i=0;i<4;i++){
			if( StartX+FourMoveX[i] >= 0 && StartX+FourMoveX[i] <N && StartY+FourMoveY[i] >=0 && StartY+FourMoveY[i] < M){
				if(Map[StartX+FourMoveX[i]][StartY+FourMoveY[i]] == 0)
					Move(StartX+FourMoveX[i], StartY+FourMoveY[i],1,N,M,EndX,EndY);
			}
		}
		if( MinMove == 10000 ){
			printf("-1\n");
		}else{
			printf("%d\n",MinMove);
		}
		MinMove = 10000;
		for(i=0;i<101;i++){
			for(j=0;j<101;j++){
				Map[i][j] = -1;
			}
		}
	}

	return EXIT_SUCCESS;
}

void Move(int NowX,int NowY,int Count,int N,int M,int EndX,int EndY){
	if(MinMove != 10000)
		return;
	int i;
	Map[NowX][NowY] = 1;
	//printf("Now : %d %d\n",NowX,NowY);
	if(NowX == EndX && NowY == EndY){
		if(Count < MinMove){
			MinMove = Count;
		}
		Map[NowX][NowY] = 0;
		return;
	}
	int FourMoveX[4],FourMoveY[4];
	if(NowX > EndX && NowY > EndY){
		FourMoveX[0] = -1;
		FourMoveY[0] = 0;
		FourMoveX[1] = 0;
		FourMoveY[1] = -1;
		FourMoveX[2] = 1;
		FourMoveY[2] = 0;
		FourMoveX[3] = 0;
		FourMoveY[3] = 1;
	}
	else if(NowX > EndX && NowY == EndY){
		FourMoveX[0] = -1;
		FourMoveY[0] = 0;
		FourMoveX[1] = 1;
		FourMoveY[1] = 0;
		FourMoveX[2] = 0;
		FourMoveY[2] = -1;
		FourMoveX[3] = 0;
		FourMoveY[3] = 1;
	}
	else if(NowX > EndX && NowY < EndY){
		FourMoveX[0] = -1;
		FourMoveY[0] = 0;
		FourMoveX[1] = 0;
		FourMoveY[1] = 1;
		FourMoveX[2] = 1;
		FourMoveY[2] = 0;
		FourMoveX[3] = 0;
		FourMoveY[3] = -1;
	}
	else if(NowX < EndX && NowY > EndY){
		FourMoveX[0] = 1;
		FourMoveY[0] = 0;
		FourMoveX[1] = 0;
		FourMoveY[1] = -1;
		FourMoveX[2] = -1;
		FourMoveY[2] = 0;
		FourMoveX[3] = 0;
		FourMoveY[3] = 1;
	}
	else if(NowX < EndX && NowY == EndY){
		FourMoveX[0] = 1;
		FourMoveY[0] = 0;
		FourMoveX[1] = -1;
		FourMoveY[1] = 0;
		FourMoveX[2] = 0;
		FourMoveY[2] = -1;
		FourMoveX[3] = 0;
		FourMoveY[3] = 1;
	}
	else if(NowX < EndX && NowY < EndY){
		FourMoveX[0] = 1;
		FourMoveY[0] = 0;
		FourMoveX[1] = 0;
		FourMoveY[1] = 1;
		FourMoveX[2] = -1;
		FourMoveY[2] = 0;
		FourMoveX[3] = 0;
		FourMoveY[3] = -1;
	}
	else if(NowX == EndX && NowY > EndY){
		FourMoveX[0] = 0;
		FourMoveY[0] = -1;
		FourMoveX[1] = 0;
		FourMoveY[1] = 1;
		FourMoveX[2] = 1;
		FourMoveY[2] = 0;
		FourMoveX[3] = -1;
		FourMoveY[3] = 0;
	}
	else if(NowX == EndX && NowY == EndY){
		FourMoveX[0] = 0;
		FourMoveY[0] = -1;
		FourMoveX[1] = 0;
		FourMoveY[1] = 1;
		FourMoveX[2] = 1;
		FourMoveY[2] = 0;
		FourMoveX[3] = -1;
		FourMoveY[3] = 0;
	}
	else if(NowX == EndX && NowY < EndY){
		FourMoveX[0] = 0;
		FourMoveY[0] = 1;
		FourMoveX[1] = 0;
		FourMoveY[1] = -1;
		FourMoveX[2] = 1;
		FourMoveY[2] = 0;
		FourMoveX[3] = -1;
		FourMoveY[3] = 0;
	}
	for(i=0;i<4;i++){
		if( NowX+FourMoveX[i] >= 0 && NowX+FourMoveX[i] <N && NowY+FourMoveY[i] >=0 && NowY+FourMoveY[i] < M){
			if(Map[ NowX+FourMoveX[i] ][ NowY+FourMoveY[i] ] == 0)
				Move(NowX+FourMoveX[i], NowY+FourMoveY[i],Count+1,N,M,EndX,EndY);
		}
	}
	Map[NowX][NowY] = 0;
}

