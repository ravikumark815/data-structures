/*

Author: https://github.com/ravikumark815

------- Graphs -------

Insert Edge     : Insert an edge into the graph
Delete Graph    : Delete graph and exit
Display Graph   : Display graph in matrix format
Prefill graph   : Create a graph with prefilled values

*/

#include <stdio.h>
#include <stdlib.h>

struct graph_t {
    int vertices;
    int **matrix;
};

struct graph_t* create_graph() 
{
    struct graph_t * new_graph = (struct graph_t *) malloc (sizeof(struct graph_t));
    if (new_graph == NULL) {
        printf(">>> Error: Memory Insufficient to create graph\n");
        exit(1);
    }
    printf("\nEnter the no of vertices: ");
    scanf("%d", &new_graph->vertices);

    new_graph->matrix = (int**) calloc (new_graph->vertices, sizeof(int*));
    if(new_graph->matrix == NULL) {
        printf(">>> Error: Memory insufficient to create matrix\n");
        exit(1);
    }

    for(int i=0; i<new_graph->vertices; i++)
    {
        new_graph->matrix[i] = (int*) calloc (new_graph->vertices, sizeof(int));
        if(new_graph->matrix == NULL) {
            printf(">>> Error: Memory insufficient to create matrix[%d]\n", i);
            exit(1);
        }
    }
    
    return new_graph;
}

void insert_edge (struct graph_t * graph)
{
    int src, dst, weight;
    printf("Enter edge in the format [Source Destination Weight]: ");
    scanf("%d %d %d", &src, &dst, &weight);

    graph->matrix[src][dst] = weight;
    graph->matrix[dst][src] = weight;
    return;
}

void delete_graph (struct graph_t *graph)
{
    for (int i=0; i<graph->vertices; i++)
        free(graph->matrix[i]);
    free(graph->matrix);
    free(graph);
    
    exit(0);
}

void display_graph (struct graph_t *graph)
{
    printf("\nDisplay:\n    ");
    for (int i = 0; i < graph->vertices; i++)
        printf("(%d) ", i);
    printf("\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("(%d) ", i);
        for (int j = 0; j < graph->vertices; j++)
            printf(" %d  ", graph->matrix[i][j]);
        printf("\n");
    }
    
    // for (int i = 0; i < graph->V; ++i) {
    //     printf("(%d)", i);

    //     for (int j = 0; j < graph->V; ++j) {
    //         if (graph->adjMatrix[i][j] != 0) {
    //             printf("--%d--(%d)", graph->adjMatrix[i][j], j);
    //         }
    //     }

    //     printf("\n");
    // }

    return;
}

void prefill_graph (struct graph_t *graph)
{
    graph->vertices = 5;

    graph->matrix[0][1] = 4;
    graph->matrix[0][4] = 3;
    graph->matrix[1][0] = 4;
    graph->matrix[1][2] = 1;
    graph->matrix[1][3] = 2;
    graph->matrix[1][4] = 5;
    graph->matrix[2][1] = 1;
    graph->matrix[2][3] = 8;
    graph->matrix[3][1] = 2;
    graph->matrix[3][2] = 8;
    graph->matrix[3][4] = 6;
    graph->matrix[4][0] = 3;
    graph->matrix[4][1] = 5;
    graph->matrix[4][3] = 6;
    
    return;
}

void main() 
{
    printf("------- Graphs -------");
    struct graph_t* graph = create_graph();
    int choice = 0;
    
    while(1){
        printf("\n---------------------\n");
        printf("1.Insert Edge\n2.Display Graph\n3.Delete Graph\n4.Prefill Graph\n");
        printf("\nChoose your Option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert_edge(graph);
                    break;
            case 2: display_graph(graph);
                    break;
            case 3: delete_graph(graph);
                    break;
            case 4: prefill_graph(graph);
                    break;
            default: return;
        }
    }
    
    return;
}