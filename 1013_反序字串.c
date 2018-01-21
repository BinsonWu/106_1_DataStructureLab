#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[5];
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            int j;
            for(j=3;j>=0;j--)
            {
                printf("%c",str[j]);
            }
            printf("\n");
        }
        memset(str,'\0',5*sizeof(char));
    }

    return 0;
}

