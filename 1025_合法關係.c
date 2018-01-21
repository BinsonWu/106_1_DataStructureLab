#include <stdio.h>
#include <stdlib.h>

typedef struct caw
{
    int master;
}caw_t,pcaw_t;

int main()
{

    int N,M;
    while(scanf("%d%d",&N,&M))
    {
        int i;
        caw_t AllCaw[100];
        for(i=0;i<100;i++)
        {
            AllCaw[i].master = -1;
        }
        if(N == 0)
            break;
        int legal = 1;
        for(i=0;i<M;i++)
        {
            int master,slave;
            scanf("%d%d",&master,&slave);
            if(master == slave)
                legal = 0;
            int now = master;
            while(AllCaw[now].master != -1)
            {
                if(AllCaw[now].master == slave)
                    legal = 0;
                now = AllCaw[now].master;
            }
            AllCaw[slave].master = master;
        }
        if(legal == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}

