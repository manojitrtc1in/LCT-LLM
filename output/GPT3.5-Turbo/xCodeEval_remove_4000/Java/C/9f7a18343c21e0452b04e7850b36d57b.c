#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_COUNT 1000
#define MAX_EDGE_COUNT 2000
#define MAX_INT 2147483647

typedef struct {
    int id;
} Edge;

typedef struct {
    int vertexCount;
    int edgeCount;
    int firstOutbound[MAX_VERTEX_COUNT];
    int firstInbound[MAX_VERTEX_COUNT];
    Edge edges[MAX_EDGE_COUNT];
    int nextInbound[MAX_EDGE_COUNT];
    int nextOutbound[MAX_EDGE_COUNT];
    int from[MAX_EDGE_COUNT];
    int to[MAX_EDGE_COUNT];
    long weight[MAX_EDGE_COUNT];
    long capacity[MAX_EDGE_COUNT];
    int reverseEdge[MAX_EDGE_COUNT];
    int flags[MAX_EDGE_COUNT];
} Graph;

typedef struct {
    Graph* graph;
    int source;
    int destination;
    long phi[MAX_VERTEX_COUNT];
    long dist[MAX_VERTEX_COUNT];
    int lastEdge[MAX_VERTEX_COUNT];
    int heap[MAX_VERTEX_COUNT];
    int heapSize;
    int visited[MAX_VERTEX_COUNT];
    int visitIndex;
} MinCostFlow;

Graph* createGraph(int vertexCount) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    for (int i = 0; i < vertexCount; ++i) {
        graph->firstOutbound[i] = -1;
        graph->firstInbound[i] = -1;
    }
    return graph;
}

int addEdge(Graph* graph, int from, int to, long weight, long capacity, int reverseEdge) {
    int id = graph->edgeCount++;
    graph->edges[id].id = id;
    graph->from[id] = from;
    graph->to[id] = to;
    graph->weight[id] = weight;
    graph->capacity[id] = capacity;
    graph->reverseEdge[id] = reverseEdge;
    graph->flags[id] = 0;
    graph->nextOutbound[id] = graph->firstOutbound[from];
    graph->firstOutbound[from] = id;
    graph->nextInbound[id] = graph->firstInbound[to];
    graph->firstInbound[to] = id;
    return id;
}

void addFlow(Graph* graph, int id, long flow) {
    graph->capacity[id] -= flow;
    graph->capacity[graph->reverseEdge[id]] += flow;
}

void clearFlow(Graph* graph) {
    for (int i = 0; i < graph->edgeCount; ++i) {
        graph->capacity[i] = 0;
    }
}

MinCostFlow* createMinCostFlow(Graph* graph, int source, int destination) {
    MinCostFlow* mcf = (MinCostFlow*)malloc(sizeof(MinCostFlow));
    mcf->graph = graph;
    mcf->source = source;
    mcf->destination = destination;
    mcf->visitIndex = 0;
    return mcf;
}

void dijkstra(MinCostFlow* mcf) {
    int vertexCount = mcf->graph->vertexCount;
    for (int i = 0; i < vertexCount; ++i) {
        mcf->phi[i] = MAX_INT;
        mcf->dist[i] = MAX_INT;
        mcf->visited[i] = 0;
    }
    mcf->phi[mcf->source] = 0;
    mcf->dist[mcf->source] = 0;
    mcf->heapSize = 0;
    mcf->heap[mcf->heapSize++] = mcf->source;
    while (mcf->heapSize > 0) {
        int current = mcf->heap[0];
        mcf->visited[current] = mcf->visitIndex;
        mcf->heap[0] = mcf->heap[--mcf->heapSize];
        int i = 0;
        while (true) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            if (left >= mcf->heapSize) {
                break;
            }
            int next = i;
            if (mcf->dist[mcf->heap[next]] > mcf->dist[mcf->heap[left]]) {
                next = left;
            }
            if (right < mcf->heapSize && mcf->dist[mcf->heap[next]] > mcf->dist[mcf->heap[right]]) {
                next = right;
            }
            if (next == i) {
                break;
            }
            int temp = mcf->heap[i];
            mcf->heap[i] = mcf->heap[next];
            mcf->heap[next] = temp;
            i = next;
        }
        int edgeID = mcf->graph->firstOutbound[current];
        while (edgeID != -1) {
            int next = mcf->graph->to[edgeID];
            long total = mcf->graph->weight[edgeID] - mcf->phi[next] + mcf->phi[current] + mcf->dist[current];
            if (mcf->graph->capacity[edgeID] > 0 && mcf->dist[next] > total) {
                mcf->dist[next] = total;
                mcf->lastEdge[next] = edgeID;
                if (mcf->visited[next] != mcf->visitIndex) {
                    mcf->visited[next] = mcf->visitIndex;
                    mcf->heap[mcf->heapSize++] = next;
                }
                int j = mcf->heapSize - 1;
                while (j > 0 && mcf->dist[mcf->heap[j]] < mcf->dist[mcf->heap[(j - 1) / 2]]) {
                    int temp = mcf->heap[j];
                    mcf->heap[j] = mcf->heap[(j - 1) / 2];
                    mcf->heap[(j - 1) / 2] = temp;
                    j = (j - 1) / 2;
                }
            }
            edgeID = mcf->graph->nextOutbound[edgeID];
        }
    }
}

void minCostFlow(MinCostFlow* mcf, long maxFlow, long* cost, long* flow) {
    *cost = 0;
    *flow = 0;
    while (maxFlow > 0) {
        dijkstra(mcf);
        if (mcf->lastEdge[mcf->destination] == -1) {
            return;
        }
        for (int i = 0; i < mcf->graph->vertexCount; ++i) {
            if (mcf->dist[i] != MAX_INT) {
                mcf->phi[i] += mcf->dist[i];
            }
        }
        int vertex = mcf->destination;
        long currentFlow = maxFlow;
        long currentCost = 0;
        while (vertex != mcf->source) {
            int edgeID = mcf->lastEdge[vertex];
            currentFlow = currentFlow < mcf->graph->capacity[edgeID] ? currentFlow : mcf->graph->capacity[edgeID];
            currentCost += mcf->graph->weight[edgeID];
            vertex = mcf->graph->from[edgeID];
        }
        maxFlow -= currentFlow;
        *cost += currentCost * currentFlow;
        *flow += currentFlow;
        vertex = mcf->destination;
        while (vertex != mcf->source) {
            int edgeID = mcf->lastEdge[vertex];
            addFlow(mcf->graph, edgeID, currentFlow);
            vertex = mcf->graph->from[edgeID];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            a[i][j] -= 1;
        }
    }

    int shoe = m * n / 2;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    Graph* graph = createGraph(2 * shoe + 2);

    int source = 2 * shoe, sink = 2 * shoe + 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int id = i * m + j;
            if ((i + j) % 2 == 0) {
                for (int z = 0; z < 4; ++z) {
                    int i1 = i + dx[z];
                    int j1 = j + dy[z];
                    if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= m) {
                        continue;
                    }
                    int id1 = i1 * m + j1;
                    int wt = (a[i][j] == a[i1][j1]) ? 0 : 1;
                    addEdge(graph, id, id1, wt, 1, -1);
                }
                addEdge(graph, source, id, 0, 1, -1);
            } else {
                addEdge(graph, id, sink, 0, 1, -1);
            }
        }
    }

    MinCostFlow* mcf = createMinCostFlow(graph, source, sink);
    long cost, flow;
    minCostFlow(mcf, MAX_INT, &cost, &flow);
    printf("%ld\n", cost);

    return 0;
}
