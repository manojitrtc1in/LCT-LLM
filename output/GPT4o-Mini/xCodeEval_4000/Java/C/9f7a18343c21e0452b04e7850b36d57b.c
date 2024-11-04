#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    long first;
    long second;
} Pair;

typedef struct {
    int vertexCount;
    int edgeCount;
    int *firstOutbound;
    int *from;
    int *to;
    long *weight;
    long *capacity;
    int *nextOutbound;
    int *reverseEdge;
} Graph;

typedef struct {
    Graph *graph;
    int source;
    int destination;
    long *phi;
    long *dijkstraResult;
    int *lastEdge;
    int *visited;
    int visitIndex;
} MinCostFlow;

Graph* createGraph(int vertexCount) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    graph->firstOutbound = (int *)malloc(vertexCount * sizeof(int));
    for (int i = 0; i < vertexCount; i++) {
        graph->firstOutbound[i] = -1;
    }
    graph->from = (int *)malloc(vertexCount * sizeof(int));
    graph->to = (int *)malloc(vertexCount * sizeof(int));
    graph->weight = (long *)malloc(vertexCount * sizeof(long));
    graph->capacity = (long *)malloc(vertexCount * sizeof(long));
    graph->nextOutbound = (int *)malloc(vertexCount * sizeof(int));
    graph->reverseEdge = (int *)malloc(vertexCount * sizeof(int));
    return graph;
}

void addEdge(Graph *graph, int fromID, int toID, long weight, long capacity) {
    graph->from[graph->edgeCount] = fromID;
    graph->to[graph->edgeCount] = toID;
    graph->weight[graph->edgeCount] = weight;
    graph->capacity[graph->edgeCount] = capacity;
    graph->nextOutbound[graph->edgeCount] = graph->firstOutbound[fromID];
    graph->firstOutbound[fromID] = graph->edgeCount++;
}

MinCostFlow* createMinCostFlow(Graph *graph, int source, int destination) {
    MinCostFlow *mcf = (MinCostFlow *)malloc(sizeof(MinCostFlow));
    mcf->graph = graph;
    mcf->source = source;
    mcf->destination = destination;
    mcf->phi = (long *)malloc(graph->vertexCount * sizeof(long));
    mcf->dijkstraResult = (long *)malloc(graph->vertexCount * sizeof(long));
    mcf->lastEdge = (int *)malloc(graph->vertexCount * sizeof(int));
    mcf->visited = (int *)malloc(graph->vertexCount * sizeof(int));
    return mcf;
}

void fordBellman(MinCostFlow *mcf) {
    for (int i = 0; i < mcf->graph->vertexCount; i++) {
        mcf->phi[i] = LONG_MAX;
    }
    mcf->phi[mcf->source] = 0;
    // Implement queue logic here
}

void dijkstraAlgorithm(MinCostFlow *mcf) {
    for (int i = 0; i < mcf->graph->vertexCount; i++) {
        mcf->dijkstraResult[i] = LONG_MAX;
        mcf->lastEdge[i] = -1;
    }
    mcf->dijkstraResult[mcf->source] = 0;
    // Implement heap logic here
}

Pair minCostMaxFlow(MinCostFlow *mcf, long maxFlow) {
    long cost = 0;
    long flow = 0;
    // Implement flow logic here
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
    Graph *graph = createGraph(2 * shoe + 2);
    int source = 2 * shoe, sink = 2 * shoe + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id = i * m + j;
            if ((i + j) % 2 == 0) {
                // Add edges based on neighbors
                addEdge(graph, source, id, 0, 1);
            } else {
                addEdge(graph, id, sink, 0, 1);
            }
        }
    }

    MinCostFlow *mcf = createMinCostFlow(graph, source, sink);
    fordBellman(mcf);
    Pair ans = minCostMaxFlow(mcf, LONG_MAX);
    printf("%ld\n", ans.first);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(graph->firstOutbound);
    free(graph->from);
    free(graph->to);
    free(graph->weight);
    free(graph->capacity);
    free(graph->nextOutbound);
    free(graph->reverseEdge);
    free(graph);
    free(mcf->phi);
    free(mcf->dijkstraResult);
    free(mcf->lastEdge);
    free(mcf->visited);
    free(mcf);

    return 0;
}
