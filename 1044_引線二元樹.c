#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *parent,*left,*right;
}node_t,*p_node_t;

p_node_t build_tree(char *s,int *now);

int main()
{
    char s[100];
    while(fgets(s,100,stdin) && strlen(s)>1)
    {
        //printf("%s",s);
        int *now;
        now = (int*)malloc(sizeof(int));
        *now = 0;
        p_node_t root=NULL;
        root = build_tree(s ,now);
        inorder(root);
        printf("\n");
    }
    return 0;
}

p_node_t build_tree(char *s,int *now)
{
    if(s[*now] == '\r' || s[*now] == '\n' )
        return NULL;
    if(s[*now] == ' ')
    {
        (*now)++;
        return NULL;
    }

    //printf("now : %d\n",*now);
    p_node_t newNode;
    newNode = (p_node_t)malloc(sizeof(node_t));
    newNode->data = s[*now];
    (*now)++;
    //printf("%c left\n",newNode->data);
    newNode->left = build_tree(s,now);
    //printf("%c right\n",newNode->data);
    newNode->right = build_tree(s,now);

    return newNode;
}

inorder(p_node_t root)
{
    if(root)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}

