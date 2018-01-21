#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int val;
    struct tree_node *left,*right;
}tree_node_t,*ptree_node_t;

typedef struct queue_node
{
    int val;
    struct queue_node *next;
}queue_node_t,*pqueue_node_t;

int main()
{
    int N;
    int i;
    int val;
    while(scanf("%d",&N) != EOF)
    {
        pqueue_node_t queue;
        queue       = (pqueue_node_t)malloc(sizeof(queue_node_t));
        queue->val  = 0;
        queue->next = NULL;

        for(i=0;i<N;i++)
        {
            scanf("%d",&val);
            EnQueue(val,queue);
            //printf("queue->next->val : %d\n",queue->next->val);
        }
        //printQueue(queue);
        int sum = 0;
        while(queue->val > 1)
        {
            //printQueue(queue);
            int a = DeQueue(queue);
            int b = DeQueue(queue);
            //printf("a : %d,b : %d\n",a,b);
            sum += a;
            sum += b;
            EnQueue(a+b,queue);
        }
        printf("%d\n",sum);
    }

    return 0;
}

void EnQueue(int val,pqueue_node_t queue)
{
    queue->val++;
    pqueue_node_t newnode;
    newnode         = (pqueue_node_t)malloc(sizeof(queue_node_t));
    newnode->val    = val;
    newnode->next   = NULL;
    if(queue->next == NULL)               // queue 是空的
    {
        queue->next     = newnode;
        newnode->next   = NULL;
        return ;
    }
    else if(queue->next->val > val)       // 插入第一顆
    {
        newnode->next   = queue->next;
        queue->next     = newnode;
        return ;
    }
    else                            // 插中間 或 插最後
    {
        pqueue_node_t temp;
        temp = queue->next;
        while(temp->next != NULL )
        {
            if(temp->next->val > val)
                break;
            temp = temp->next;
        }
        if(temp->next != NULL)      // 插中間
        {
            newnode->next   = temp->next;
            temp->next      = newnode;
        }
        else                        // 插最後
        {
            temp->next      = newnode;
        }
        return ;
    }
}

int DeQueue(pqueue_node_t queue)
{
    if(queue->val == 0 )
        return -1;
    queue->val--;
    int ans = queue->next->val;
    pqueue_node_t temp;
    temp = queue->next;

    if(queue->next->next != NULL)
    {
        queue->next = queue->next->next;
    }
    else
    {
        queue->next = NULL;
    }
    free(temp);
    return ans;
}

void printQueue(pqueue_node_t queue)
{
    pqueue_node_t temp = queue->next;
    while(temp != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

