#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d ",&n);
    int i;
    for(i=0;i<n;i++)
    {
        char str[100];
        fgets (str, 100, stdin);
        int CP;
        CP = 0;
        int BCount;
        BCount = 0;
        int j;
        for(j=0;j<strlen(str);j++)
        {
            if(str[j] == 'G' && BCount > 0)
            {
                CP++;
                BCount--;
            }
            else if(str[j] == 'B')
            {
                BCount++;
            }
        }
        printf("%d\n",CP);
        fflush(stdin);
    }
    return 0;
}

