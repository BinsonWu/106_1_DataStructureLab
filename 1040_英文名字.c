/*
 ============================================================================
 Name        : 41_英文名字.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash{
	int key;
	char data[10];
}hash_t;

int main(void) {
	hash_t HashTable[26];
	int i;
	for(i=0;i<26;i++){
		HashTable[i].key = -1;
		memset(HashTable[i].data,'\0',10);
	}

	for(i=0;i<26;i++){
		char str[10];
		scanf("%s",str);
		int key = str[0]-'A';
		int index = key;
		while(HashTable[index%26].key != -1){
			index++;
		}
		HashTable[index%26].key = key;
		strcpy(HashTable[index%26].data,str);
	}

	for(i=0;i<26;i++){
		printf("%d %d %s\n",i,HashTable[i].key,HashTable[i].data);
	}

	return EXIT_SUCCESS;
}

