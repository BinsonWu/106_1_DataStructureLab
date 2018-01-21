#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    int Val;
    int SuccessTime;
}person_t;
int main()
{
    /*
    Set
    A HandleTime = 1,
    B HandleTime = 2.
    */
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int Val;
        char c;
        person_t QueueA[1000];
        person_t QueueB[1000];
        int QueueALen,QueueBLen;
        QueueALen = QueueBLen = 0;

        int MaxSuccessTime = 0;
        while(1)
        {
            scanf("%d%c",&Val,&c);

            if(Val%2 == 1)
            {
                QueueA[QueueALen].Val = Val;
                QueueA[QueueALen].SuccessTime = QueueALen*1+1;
                if( QueueA[QueueALen].SuccessTime > MaxSuccessTime )
                    MaxSuccessTime = QueueA[QueueALen].SuccessTime;
                QueueALen++;
            }
            else
            {
                QueueB[QueueBLen].Val = Val;
                QueueB[QueueBLen].SuccessTime = QueueBLen*2+2;
                if( QueueB[QueueBLen].SuccessTime > MaxSuccessTime )
                    MaxSuccessTime = QueueB[QueueBLen].SuccessTime;
                QueueBLen++;
            }
            if(c == '\n')
                break;
        }
        int i;
        int APos,BPos;
        APos = BPos = 0;
        for(i=1;i<=MaxSuccessTime;i++)
        {
            if(i == MaxSuccessTime)
            {
                if(APos < QueueALen && QueueA[APos].SuccessTime == i && BPos < QueueBLen && QueueB[BPos].SuccessTime == i)
                {
                    printf("%d %d\n",QueueA[APos].Val,QueueB[BPos].Val);
                    APos++;
                }
                else if(APos < QueueALen && QueueA[APos].SuccessTime == i)
                {
                    printf("%d ",QueueA[APos].Val);
                    APos++;
                }
                else if(BPos < QueueBLen && QueueB[BPos].SuccessTime == i)
                {
                    printf("%d ",QueueB[BPos].Val);
                    BPos++;
                }
            }
            if(APos < QueueALen && QueueA[APos].SuccessTime == i)
            {
                printf("%d ",QueueA[APos].Val);
                APos++;
            }
            if(BPos < QueueBLen && QueueB[BPos].SuccessTime == i)
            {
                printf("%d ",QueueB[BPos].Val);
                BPos++;
            }
        }
        printf("\n");

    }
    return 0;
}

