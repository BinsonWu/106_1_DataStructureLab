#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int arr[12];
    while(scanf("%d",&N) != EOF)
    {
        if(N == 0)
            break;
        int i,j;
        int ans[6];
        for(i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
        Find(arr,0,0,N,ans);
        printf("\n");
    }
    return 0;
}

/*
1 2 3 4 5 6 7
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7
*/

void Find(int arr[12],int NthSol,int NthArr,int limit,int ans[6])
{
    // Init 7-0 >= 6-0
    int i,j;
    int Range;
    Range = (limit - NthArr) - ( 6 - NthSol );
    //printf("Range : %d\n",Range);
    if(Range >= 0)
    {
        for(i=NthArr;i<= NthArr + Range;i++)
        {
            ans[NthSol] = arr[i];
            //printf("NthSol : %d,Arr i : %d , Val : %d\n",NthSol,i,arr[i]);
            if(NthSol == 5)
            {
                for(j=0;j<6;j++)
                {
                    if(j == 5)
                        printf("%d\n",ans[j]);
                    else
                        printf("%d ",ans[j]);
                }
            }
            else
            {
                Find(arr,NthSol+1,i+1,limit,ans);
            }
        }
    }
}

