#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *ChildList;
    int apear;
}node_t,*pnode_t;

void AddNode(pnode_t root,char str[100],int nth,int length);

int time;

int main()
{
    time =0;
    node_t root;
    int i,j;
    root.ChildList = (pnode_t)malloc(sizeof(node_t)*26);
    for(i=0;i<26;i++)
    {
        root.ChildList[i].apear = 0;
    }
    char str[100];
    memset(str,'\0',sizeof(str));
    while( scanf("%s",str) != EOF )
    {
        AddNode(&root,str,0,strlen(str));
        memset(str,'\0',sizeof(str));
    }
    printf("%d\n",time+1);
    return 0;
}

void AddNode(pnode_t root,char str[100],int nth,int length)
{
    if(nth != length)
    {
        int index = str[nth] - 'A';
        if(root->ChildList[ index ].apear == 0)
        {
            time++;
            int i;
            root->ChildList[ index ].ChildList = (pnode_t)malloc(sizeof(node_t)*26);
            for(i=0;i<26;i++)
            {
                root->ChildList[ index ].ChildList[i].apear = 0;
            }
            root->ChildList[ index ].apear = 1;
            AddNode(&root->ChildList[ index ],str,nth+1,length);
        }
        else
        {
            AddNode(&root->ChildList[ index ],str,nth+1,length);
        }
    }
}

