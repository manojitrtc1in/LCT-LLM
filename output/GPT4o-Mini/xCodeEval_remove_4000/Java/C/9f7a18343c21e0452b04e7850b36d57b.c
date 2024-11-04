#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    long first;
    long second;
} Pair;

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

Graph* createGraph(int vertexCount) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    graph->from = (int *)malloc(sizeof(int) * vertexCount);
    graph->to = (int *)malloc(sizeof(int) * vertexCount);
    graph->weight = (long *)malloc(sizeof(long) * vertexCount);
    graph->capacity = (long *)malloc(sizeof(long) * vertexCount);
    graph->nextOutbound = (int *)malloc(sizeof(int) * vertexCount);
    graph->firstOutbound = (int *)malloc(sizeof(int) * vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        graph->firstOutbound[i] = -1;
    }
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

void initializeGraph(Graph *graph, int n, int m, int **a) {
    int shoe = m * n / 2;
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    int source = 2 * shoe, sink = 2 * shoe + 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int id = i * m + j;
            if ((i + j) % 2 == 0) {
                for (int z = 0; z < 4; ++z) {
                    int i1 = i + dx[z];
                    int j1 = j + dy[z];
                    if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= m) continue;
                    int id1 = i1 * m + j1;
                    int wt = (a[i][j] == a[i1][j1]) ? 0 : 1;
                    addEdge(graph, id, id1, wt, 1);
                }
                addEdge(graph, source, id, 0, 1);
            } else {
                addEdge(graph, id, sink, 0, 1);
            }
        }
    }
}

Pair id2(id5 *mcf) {
    // Implementation of the flow algorithm would go here
    Pair result;
    result.first = 0; // Placeholder for cost
    result.second = 0; // Placeholder for flow
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] -= 1;
        }
    }

    Graph *graph = createGraph(2 * (m * n / 2) + 2);
    initializeGraph(graph, n, m, a);

    id5 *mcf = (id5 *)malloc(sizeof(id5));
    mcf->graph = graph;
    mcf->source = 2 * (m * n / 2);
    mcf->destination = 2 * (m * n / 2) + 1;

    Pair ans = id2(mcf);
    printf("%ld\n", ans.first);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(graph->from);
    free(graph->to);
    free(graph->weight);
    free(graph->capacity);
    free(graph->nextOutbound);
    free(graph->firstOutbound);
    free(graph);
    free(mcf);

    return 0;
}
