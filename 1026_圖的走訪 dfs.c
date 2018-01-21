#include <stdio.h>
#include <stdlib.h>
struct node_ori
{
    int num;
    struct node_ori *next;
};
typedef struct node_ori node_t;


struct graph_ori
{
    int numnode;
    node_t ** adjLists;
    int *visited;
};
typedef struct graph_ori Graph_t;

node_t *createnode(int n)
{
    node_t *newnode;
    newnode = (node_t*)malloc(sizeof(node_t));
    newnode -> num = n;
    newnode -> next = NULL;
    return newnode;
}
Graph_t *creategraph(int num)
{
    Graph_t *Graph;
    Graph = (Graph_t*)malloc(sizeof(Graph_t));
    Graph -> numnode = num;
    Graph -> adjLists = (node_t**)malloc((num+1)*sizeof(node_t*));
    Graph -> visited = (int*)malloc((num+1)*sizeof(int));

    int i;
    for (i=1; i<=num; i++)
    {
        Graph -> visited[i]=0;
        Graph -> adjLists[i]=NULL;
    }
    return Graph;

}

void add(Graph_t* graph, int src, int dest)
{
    node_t *temp1 = graph -> adjLists[src];
    node_t *newnode = createnode(dest);
    if (temp1 == NULL)
    {
        graph -> adjLists[src] = newnode;
    }
    else
    {
        while (temp1 -> next !=NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = newnode;
    }

    node_t *temp2 = graph->adjLists[dest];
    newnode = createnode(src);
    if (temp2 == NULL)
    {
        graph->adjLists[dest] = newnode;
    }
    else

    {
        while (temp2 -> next !=NULL)
          {

            temp2 = temp2 -> next;
          }

        temp2 -> next = newnode;
    }


}

void DFS(Graph_t* graph, int vertex)
{
    node_t *adjLists = graph->adjLists[vertex];
    node_t *temp = adjLists;
    graph -> visited[vertex]=1;
    printf("%d ", vertex);
    while (temp!=NULL)
    {
        int nextvertex = temp -> num;
        if (graph -> visited[nextvertex]==0)
        {
            DFS(graph, nextvertex);
        }
        temp = temp -> next;
    }
}

int main()
{
    int n, e, i;
    while (scanf("%d%d", &n, &e)!=EOF)
    {
        Graph_t *graph = creategraph(n);
        for (i=0; i<e; i++)
        {
            int from, to;
            scanf("%d%d", &from, &to);
            add(graph, from, to);
        }
        DFS(graph, 1);
        printf("\n");

    }


}

