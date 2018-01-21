#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
	char id[5];
	char name[100];
	char sex[5];
	int age;
}student;

typedef struct Stack2{
	char id[5];
}cstud;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i=0,j=0,temp=0,count=0,s;
		student list[n];
		for(i=0;i<n;i++){
			scanf("%s%s%s%d",list[i].id,list[i].name,list[i].sex,&list[i].age);
		}
		scanf("%d",&s);
		cstud counter[s];
		for(i=0;i<s;i++){
			scanf("%s",counter[i].id);
		}
		for(i=0;i<s;i++){
			for(j=0;j<n;j++){
				if(strcmp(counter[i].id,list[j].id)==0){
					temp++;
					count=j;
				}
			}
			if(temp==1){
				printf("%s %s %s %d\n",list[count].id,list[count].name,list[count].sex,list[count].age);
			}
			else{
				printf("No Answer!\n");
			}
			temp=0;
			count=0;
		}

	}
	return 0;
}

