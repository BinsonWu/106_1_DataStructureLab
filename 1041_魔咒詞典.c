/*
 ============================================================================
 Name        : 42_魔咒詞典.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char Magic[10000][20],Function[10000][80];			// Magic Dictionary
	char TestData[80];														// Test Data
	int i,j,k;																		// For Loop
	int DataNum = 0;														// Input N Data
	int TestNum = 0;														// Test N Data
	int IfFind = 0;																// If We Find Data
	char InputData[100];													// For Input Data
	memset(Magic[DataNum],'\0',sizeof(char)*20);
	memset(Function[DataNum],'\0',sizeof(char)*80);
	memset(InputData,'\0',sizeof(char)*100);
	while( fgets(InputData,100,stdin) && strlen(InputData) ){
		if( strcmp(InputData,"@END@\n") == 0 )
			break;

		for(i=0; InputData[i] != '\n' ;i++){
			Magic[DataNum][i] = InputData[i];
			if(InputData[i] == ']')
				break;
		}
		i +=2;						// Jump Over ' '
		for(j=0; InputData[i+j] != '\n' ;j++){
			Function[DataNum][j] = InputData[i+j];
		}
		DataNum++;
		if(DataNum != 10001){
			memset(Magic[DataNum],'\0',sizeof(char)*20);
			memset(Function[DataNum],'\0',sizeof(char)*80);
			memset(InputData,'\0',sizeof(char)*100);
		}
		fflush(stdin);
	}

	/*for(i=0;i<DataNum;i++){
		printf("Magic\t\t: %s\n",Magic[i]);
		printf("Function\t: %s\n",Function[i]);
	}*/

	scanf("%d ",&TestNum);
	for(i=0;i<TestNum;i++){
		fgets(TestData,80,stdin);
		TestData[ strlen(TestData) -1 ] = '\0';
		if(TestData[0] == '['){
			for(j=0;j<DataNum;j++){
				//printf("TestData\t: %s\n",TestData);
				//printf("Magic\t: %s\n",Magic[j]);
				if( strcmp(TestData,Magic[j]) == 0 ){
					printf("%s\n",Function[j]);
					IfFind = 1;
					break;
				}
			}
		}
		else{
			for(j=0;j<DataNum;j++){
				//printf("TestData\t: %s\n",TestData);
				//printf("Magic\t: %s\n",Function[j]);
				if( strcmp(TestData,Function[j]) == 0 ){
					for(k=1;k<strlen(Magic[j])-1;k++){
						printf("%c",Magic[j][k]);
					}
					printf("\n");
					IfFind = 1;
					break;
				}
			}
		}
		if(IfFind == 0)
			printf("what?\n");

		// Init
		IfFind = 0;
		memset(TestData,'\0',sizeof(char)*80);
		fflush(stdin);
	}

	return EXIT_SUCCESS;
}

