#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char Str1[1000],Str2[1000];
    int Data1[1000],Data2[1000],Ans[1000];
    memset(Str1,'\0',sizeof(Str1));
    memset(Str2,'\0',sizeof(Str2));
    memset(Data1,0,sizeof(Data1));
    memset(Data2,0,sizeof(Data2));
    memset(Ans,0,sizeof(Ans));
    int i;
    while(gets(Str1) && strlen(Str1))
    {
        gets(Str2);
        char *number;
        int Data1Len,Data2Len;
        Data1Len = 0;
        Data2Len = 0;

        number = strtok(Str1," ");

        while(number != NULL)
        {
            Data1[Data1Len] = atoi(number);
            Data1Len++;
            number = strtok(NULL," ");
        }

        number = strtok(Str2," ");

        while(number != NULL)
        {
            Data2[Data2Len] = atoi(number);
            Data2Len++;
            number = strtok(NULL," ");
        }
        int Nth1,Nth2,NthAns;
        Nth1 = Nth2 = NthAns = 0;

        while(Nth1 < Data1Len || Nth2 < Data2Len)
        {
            if(Nth1 < Data1Len && Nth2 < Data2Len)
            {
                if(Data1[Nth1+1] > Data2[Nth2+1] )
                {
                    Ans[NthAns] = Data1[Nth1];
                    Ans[NthAns+1] = Data1[Nth1+1];
                    Nth1 += 2;
                    NthAns += 2;
                }
                else if(Data1[Nth1+1] < Data2[Nth2+1] )
                {
                    Ans[NthAns] = Data2[Nth2];
                    Ans[NthAns+1] = Data2[Nth2+1];
                    Nth2 += 2;
                    NthAns += 2;
                }
                else if(Data1[Nth1+1] == Data2[Nth2+1] )
                {
                    Ans[NthAns] = Data1[Nth1] + Data2[Nth2];
                    Ans[NthAns+1] = Data1[Nth1+1];
                    Nth1 += 2;
                    Nth2 += 2;
                    NthAns += 2;
                }
            }
            else
            {
                while(Nth1 < Data1Len)
                {
                    Ans[NthAns] = Data1[Nth1];
                    Ans[NthAns+1] = Data1[Nth1+1];
                    Nth1 += 2;
                    NthAns += 2;
                }
                while(Nth2 < Data2Len)
                {
                    Ans[NthAns] = Data2[Nth2];
                    Ans[NthAns+1] = Data2[Nth2+1];
                    Nth2 += 2;
                    NthAns += 2;
                }
            }
        }
        for(i=0;i<NthAns-1;i+=2)
        {
            if(Ans[i] != 0)
            {
                if(i == NthAns-2)
                    printf("%d %d\n",Ans[i],Ans[i+1]);
                else
                    printf("%d %d ",Ans[i],Ans[i+1]);
            }

        }
        memset(Str1,'\0',sizeof(Str1));
        memset(Str2,'\0',sizeof(Str2));
        memset(Data1,0,sizeof(Data1));
        memset(Data2,0,sizeof(Data2));
        memset(Ans,0,sizeof(Ans));
    }

    return 0;
}

