#include <stdio.h>
#include <stdlib.h>

void deep_insert(int *deep,int val);
int deep_search_max(int *deep);
int deep_search_min(int *deep);
int JudgeMaxOrMin(int p);
int min_partner(int p);
int max_partner(int p);
void adjust_min(int *deep,int p);
void adjust_max(int *deep,int p);
void printDeep(int *deep);

void deep_delete(int *deep,int p);

int main()
{
    int deep[100000];
    int i;
    for(i=0;i<100000;i++)
        deep[i] = -1;
    // Let deep[0] to Deep Length
    deep[0] = 1;
    int order;
    while(scanf("%d",&order)!=EOF)
    {
        int val;

        if(order==1)
        {
            scanf("%d",&val);
            deep[0]++;
            deep_insert(deep,val);
            //printDeep(deep);
        }
        else if(order == 2)
        {
            printf("%d\n",deep_search_max(deep));
            deep_delete(deep,3);
            //printDeep(deep);
        }
        else if(order == 3)
        {
            printf("%d\n",deep_search_min(deep));
            deep_delete(deep,2);
            //printDeep(deep);
        }
    }
    return 0;
}

void deep_insert(int *deep,int val)
{
    int len = deep[0];
    deep[len] = val;
    if(deep[0] == 2)
    {
        return;
    }
    else
    {
        int partner;
        // Left : Min
        if( JudgeMaxOrMin(len) == 2 )
        {
            //printf("In Min\n");
            partner = max_partner(len);
            //printf("Len:%d,Partner:%d\n",deep[len],deep[partner]);
            if(deep[len] < deep[partner])
            {
                adjust_min(deep,len);
            }
            else
            {
                int temp;
                // Change with Partner's Parent
                if(deep[partner] == -1 && deep[len] > deep[partner/2])
                {
                    temp            = deep[len];
                    deep[len]       = deep[partner/2];
                    deep[partner/2] = temp;
                    adjust_max(deep,partner/2);
                }
                // Change with Partner
                else if(deep[partner] != -1)
                {
                    temp            = deep[len];
                    deep[len]       = deep[partner];
                    deep[partner]   = temp;
                    adjust_max(deep,partner);
                }
            }
        }
        // Right : Max
        else
        {
            //printf("In Max\n");
            partner = min_partner(len);
            //printf("Len:%d,Partner:%d\n",deep[len],deep[partner]);
            if(deep[len] > deep[partner])
            {
               adjust_max(deep,len);
            }
            else
            {

                int temp;
                temp            = deep[len];
                deep[len]       = deep[partner];
                deep[partner]    = temp;
                adjust_min(deep,partner);
            }
        }
    }
}
int deep_search_max(int *deep)
{
    return deep[3];
}
int deep_search_min(int *deep)
{
    return deep[2];
}

int JudgeMaxOrMin(int p) {
    while(p > 3)    p/=2;
    return p; /*2 left-min heap 3 right-max heap*/
}
/*
        1
    2           3           +- 1
  4    5     6      7       +- 2
 8 9 10 11 12 13  14 15     +- 4
*/
int min_partner(int p)
{
    int distance=1,ori=p;
    while(p>3)
    {
        p/=2;
        distance*=2;
    }
    return ori-distance;
}
int max_partner(int p)
{
    int distance=1,ori=p;
    while(p>3)
    {
        p/=2;
        distance*=2;
    }
    return ori+distance;
}

void adjust_min(int *deep,int p)
{
    int temp;
    while(p>3)
    {
        //printf("len : %d , parent : %d\n",p,p/2);
        if(deep[p] < deep[p/2])
        {
            temp        = deep[p];
            deep[p]     = deep[p/2];
            deep[p/2]   = temp;
        }
        else
            break;
        p/=2;
    }
}
void adjust_max(int *deep,int p)
{
    int temp;
    while(p>3)
    {
        if(deep[p] > deep[p/2])
        {
            temp        = deep[p];
            deep[p]     = deep[p/2];
            deep[p/2]   = temp;
        }
        else
            break;
        p/=2;
    }
}

void printDeep(int *deep)
{
    int i;
    for(i=1;i<=deep[0];i++)
    {
        printf("%d ",deep[i]);
    }
    printf("\n");
}

void deep_delete(int *deep,int p)
{
    if(p == deep[0])
    {
        deep[p] = -1;
        deep[0]--;
        return;
    }
    deep[p] = deep[deep[0]];
    //printf("NewHead:%d\n",deep[p]);
    deep[deep[0]] = -1;
    deep[0]--;
    int side = p;
    int temp;
    while(p<deep[0])
    {
        if(deep[p*2]==-1)
            break;
        if(side == 2)
        {
            // Find smaller side and compare
            if( (deep[p*2]<deep[p*2+1] && deep[p*2]<deep[p]) || (deep[p*2+1] && deep[p*2]<deep[p]) )
            {
                temp        = deep[p];
                deep[p]     = deep[p*2];
                deep[p*2]   = temp;
                p*=2;
            }
            else if( deep[p*2]>deep[p*2+1]  && deep[p*2+1]<deep[p] )
            {
                temp        = deep[p];
                deep[p]     = deep[p*2+1];
                deep[p*2+1] = temp;
                p = p*2+1;
            }
            else
                break;
        }
        else
        {
            // Find bigger side and compare
            if( deep[p*2]>deep[p*2+1] && deep[p*2]>deep[p])
            {
                temp        = deep[p];
                deep[p]     = deep[p*2];
                deep[p*2]   = temp;
                p*=2;
            }
            else if( deep[p*2]<deep[p*2+1]  && deep[p*2+1]>deep[p] )
            {
                temp        = deep[p];
                deep[p]     = deep[p*2+1];
                deep[p*2+1] = temp;
                p = p*2+1;
            }
            else
                break;
        }
    }
    int partner;
    if(side == 2)
    {
        partner = max_partner(p);
        if(deep[p] > deep[partner] && deep[partner]!=-1)
        {
            temp            = deep[p];
            deep[p]         = deep[partner];
            deep[partner]   = temp;
        }
    }
    else
    {
        partner = min_partner(p);
        if(deep[p] < deep[partner])
        {
            temp            = deep[p];
            deep[p]         = deep[partner];
            deep[partner]   = temp;
        }
    }
}
/*
1 3
1 100
2
1 4
3
1 2
1 50
1 25
1 35
1 45
1 60
2
2
2
3
3
3
*/
/*
  2  35
4  25
*/

