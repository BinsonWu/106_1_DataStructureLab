#include <stdio.h>
#include <stdlib.h>

int main(){
    	int n;
    	scanf("%d",&n);
    	int i;
    	for(i=0;i<n;i++){
    		int nth=0;
    		int j;
    		scanf("%d",&nth);
    		int int_arr[nth];
	    	for(j=0;j<nth;j++){
	    		scanf("%d",&int_arr[j]);
	    	}
	    	int max=0;
	    	for(j=0;j<nth;j++){
	    		if(int_arr[j] > max){
	    			max = int_arr[j];
	    		}
	    	}
	    	int Ans = max;
	    	int ifans = 0;

	    	while(ifans == 0){
	    		int ifwrong = 0;
	    		for(j=0;j<nth;j++){
	    			if( Ans%int_arr[j] != 0){
	    				ifwrong =1;
	    			}
	    		}
	    		if(ifwrong == 1){
	    			Ans += max;
	    		}
	    		else{
	    			ifans = 1;
	    		}
	    	}
	    	printf("%d\n",Ans);
	}

	return 0;
}

