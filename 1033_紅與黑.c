/*
 ============================================================================
 Name        : 34_紅與黑.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void walk(char **Array,char **AnsArray,int x,int y,int W, int H);

int max = 0;
int movex[4]={0,-1,0,1};
int movey[4]={-1,0,1,0};

int main(void) {
	int W,H;
	int i,j;
	int startx,starty;

	while( scanf("%d%d",&W,&H) != EOF ){
		if( W == 0 && H == 0)
			break;

		max = 0;

		char **Array;
		Array = (char **)malloc(H*sizeof(void *));
		for (i = 0; i < H; i++)
			Array[i] = (char *)malloc(W*sizeof(char));

		char **AnsArray;
		AnsArray = (char **)malloc(H*sizeof(void *));
		for (i = 0; i < H; i++)
			AnsArray[i] = (char *)malloc(W*sizeof(char));

		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				AnsArray[i][j] = ' ';
			}
		}

		for(i=0;i<H;i++){
			scanf("%s",Array[i]);
			for(j=0;j<W;j++){
				if(Array[i][j] == '@'){
					AnsArray[i][j] = 'B';
					startx = i;
					starty = j;
				}
			}
		}

		/*printf("Map : \n");
		for(i=0;i<H;i++){
				printf("%s\n",Array[i]);
		}*/
		walk(Array,AnsArray,startx,starty,W,H);
		int black = 0;
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				if( AnsArray[i][j] == 'B' )
					black++;
			}
		}
		printf("%d\n",black);
	}
	return EXIT_SUCCESS;
}

void walk(char **Array,char **AnsArray,int x,int y,int W, int H){
	//printf("Now :  x[%d] y[%d]\n",x,y);
	int i;
	for(i=0;i<4;i++){
		int nextx = x + movex[i];
		int nexty = y + movey[i];
		if(  0 <= nextx && nextx < H && 0 <= nexty && nexty < W ){
			if( Array[nextx][nexty] == '.' ){
				Array[nextx][nexty] = ' ';
				AnsArray[nextx][nexty] = 'B';
				walk(Array,AnsArray,nextx,nexty,W,H);
				//Array[nextx][nexty] = '.';
			}
		}
	}
}

