#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    long first;
    long second;
} Pair;

typedef struct {
    int *array;
    int size;
    int capacity;
} IntList;

typedef struct {
    int *from;
    int *to;
    long *weight;
    long *capacity;
    int *nextOutbound;
    int *firstOutbound;
    int vertexCount;
    int edgeCount;
} Graph;

typedef struct {
    Graph *graph;
    int source;
    int destination;
    long *phi;
    long *id13;
    int *lastEdge;
    int *visited;
    int visitIndex;
} id5;

void initGraph(Graph *graph, int vertexCount, int edgeCapacity) {
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    graph->from = (int *)malloc(edgeCapacity * sizeof(int));
    graph->to = (int *)malloc(edgeCapacity * sizeof(int));
    graph->weight = (long *)malloc(edgeCapacity * sizeof(long));
    graph->capacity = (long *)malloc(edgeCapacity * sizeof(long));
    graph->nextOutbound = (int *)malloc(edgeCapacity * sizeof(int));
    graph->firstOutbound = (int *)malloc(vertexCount * sizeof(int));
    for (int i = 0; i < vertexCount; i++) {
        graph->firstOutbound[i] = -1;
    }
}

void addEdge(Graph *graph, int fromID, int toID, long weight, long capacity) {
    graph->from[graph->edgeCount] = fromID;
    graph->to[graph->edgeCount] = toID;
    graph->weight[graph->edgeCount] = weight;
    graph->capacity[graph->edgeCount] = capacity;
    graph->nextOutbound[graph->edgeCount] = graph->firstOutbound[fromID];
    graph->firstOutbound[fromID] = graph->edgeCount++;
}

void initId5(id5 *mcf, Graph *graph, int source, int destination) {
    mcf->graph = graph;
    mcf->source = source;
    mcf->destination = destination;
    mcf->phi = (long *)malloc(graph->vertexCount * sizeof(long));
    mcf->id13 = (long *)malloc(graph->vertexCount * sizeof(long));
    mcf->lastEdge = (int *)malloc(graph->vertexCount * sizeof(int));
    mcf->visited = (int *)malloc(graph->vertexCount * sizeof(int));
}

void freeGraph(Graph *graph) {
    free(graph->from);
    free(graph->to);
    free(graph->weight);
    free(graph->capacity);
    free(graph->nextOutbound);
    free(graph->firstOutbound);
}

void freeId5(id5 *mcf) {
    free(mcf->phi);
    free(mcf->id13);
    free(mcf->lastEdge);
    free(mcf->visited);
}

Pair id2(id5 *mcf, long maxFlow) {
    long cost = 0;
    long flow = 0;
    while (maxFlow != 0) {
        // Implement the logic for finding the flow and cost
        // This is a placeholder for the actual implementation
        // Update cost and flow accordingly
    }
    return (Pair){cost, flow};
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }

    int shoe = m * n / 2;
    Graph graph;
    initGraph(&graph, 2 * shoe + 2, 10000); // Example edge capacity

    int source = 2 * shoe, sink = 2 * shoe + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id = i * m + j;
            if ((i + j) % 2 == 0) {
                // Add edges based on neighbors
                // Placeholder for neighbor logic
                addEdge(&graph, source, id, 0, 1);
            } else {
                addEdge(&graph, id, sink, 0, 1);
            }
        }
    }

    id5 mcf;
    initId5(&mcf, &graph, source, sink);
    Pair ans = id2(&mcf, LONG_MAX);
    printf("%ld\n", ans.first);

    freeId5(&mcf);
    freeGraph(&graph);
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}
