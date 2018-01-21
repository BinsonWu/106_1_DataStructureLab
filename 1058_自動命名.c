/*
 ============================================================================
 Name        : 50_自動命名.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char str[256];
	memset(str,'\0',256);
	while(1){
		fgets(str,256,stdin);
		if(strcmp(str,"  \n") == 0)
			break;
		// Solution 1
		/*char strCopy[256];
		strcpy(strCopy,str);
		printf("%s\n",strCopy);
		char *SeparationChar = " ";
		char *name;
		name = strtok(strCopy,SeparationChar);
		while(name != NULL){
			int i;
			for(i=0;i<strlen(name);i++){
				if(i==0)
					printf ("%c",toupper(name[i]));
				else
					printf ("%c",tolower(name[i]));
			}
		    name = strtok (NULL, SeparationChar);
		}
		printf("\n");*/

		// Solution 2
		int i;
		int nth=1;
		for(i=0;i<strlen(str)-1;i++){
			if(str[i] == ' '){
				nth = 1;
			}else if(nth == 1){
				printf("%c",toupper(str[i]));
				nth++;
			}else {
				printf("%c",tolower(str[i]));
				nth++;
			}
		}
		printf("\n");

		memset(str,'\0',256);
	}
	printf("over\n");
	return EXIT_SUCCESS;
}

