#include<stdio.h>

int main(){
	int num,i,temp,ans,set=1;
	while(1){
		scanf("%d",&num);
		if(num == 0) break;
		int array[num]; 
		temp = 0;
		ans = 0;
		for(i=0;i<num;i++){
			scanf("%d",&array[i]);
			temp += array[i];
		}
		temp = temp / num;
		for(i=0;i<num;i++){
			if(array[i] > temp)
			ans += (array[i] - temp);
		}
		printf("Set #%d\n",set);
		printf("The minimum number of moves is %d.\n\n",ans);
		set++; 
	}
	return 0;
} 
