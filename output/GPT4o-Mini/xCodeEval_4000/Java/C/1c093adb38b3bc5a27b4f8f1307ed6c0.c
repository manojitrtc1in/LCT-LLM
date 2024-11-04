#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTEX_COUNT 1000
#define MAX_EDGE_COUNT 2000

typedef struct {
    int first;
    long second;
} Pair;

typedef struct {
    int from;
    int to;
    long weight;
    long capacity;
    int reverseEdge;
} Edge;

typedef struct {
    int vertexCount;
    int edgeCount;
    int firstOutbound[MAX_VERTEX_COUNT];
    Edge edges[MAX_EDGE_COUNT];
} Graph;

typedef struct {
    int source;
    int destination;
    long phi[MAX_VERTEX_COUNT];
    long dijkstraResult[MAX_VERTEX_COUNT];
    int lastEdge[MAX_VERTEX_COUNT];
    int visited[MAX_VERTEX_COUNT];
    int visitIndex;
    Graph *graph;
} MinCostFlow;

void initGraph(Graph *graph, int vertexCount) {
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    for (int i = 0; i < vertexCount; i++) {
        graph->firstOutbound[i] = -1;
    }
}

void addEdge(Graph *graph, int from, int to, long weight, long capacity, int reverseEdge) {
    Edge *edge = &graph->edges[graph->edgeCount];
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
    edge->capacity = capacity;
    edge->reverseEdge = reverseEdge;
    graph->firstOutbound[from] = graph->edgeCount++;
}

void pushFlow(Graph *graph, int id, long flow) {
    graph->edges[id].capacity -= flow;
    graph->edges[graph->edges[id].reverseEdge].capacity += flow;
}

void dijkstraAlgorithm(MinCostFlow *mcf) {
    for (int i = 0; i < mcf->graph->vertexCount; i++) {
        mcf->dijkstraResult[i] = LONG_MAX;
        mcf->lastEdge[i] = -1;
    }
    mcf->dijkstraResult[mcf->source] = 0;

    // Implement a priority queue or similar structure here for efficiency
    // For simplicity, we will use a basic array-based approach

    for (int i = 0; i < mcf->graph->vertexCount; i++) {
        for (int j = 0; j < mcf->graph->vertexCount; j++) {
            if (mcf->graph->firstOutbound[j] != -1) {
                Edge *edge = &mcf->graph->edges[mcf->graph->firstOutbound[j]];
                if (edge->capacity > 0) {
                    long total = edge->weight + mcf->dijkstraResult[edge->from];
                    if (mcf->dijkstraResult[edge->to] > total) {
                        mcf->dijkstraResult[edge->to] = total;
                        mcf->lastEdge[edge->to] = mcf->graph->firstOutbound[j];
                    }
                }
            }
        }
    }
}

Pair minCostMaxFlow(MinCostFlow *mcf, long maxFlow) {
    long cost = 0;
    long flow = 0;
    while (maxFlow > 0) {
        dijkstraAlgorithm(mcf);
        if (mcf->lastEdge[mcf->destination] == -1) {
            break;
        }
        long currentFlow = maxFlow;
        long currentCost = 0;
        int vertex = mcf->destination;
        while (vertex != mcf->source) {
            int edgeID = mcf->lastEdge[vertex];
            currentFlow = (currentFlow < mcf->graph->edges[edgeID].capacity) ? currentFlow : mcf->graph->edges[edgeID].capacity;
            currentCost += mcf->graph->edges[edgeID].weight;
            vertex = mcf->graph->edges[edgeID].from;
        }
        maxFlow -= currentFlow;
        cost += currentCost * currentFlow;
        flow += currentFlow;
        vertex = mcf->destination;
        while (vertex != mcf->source) {
            int edgeID = mcf->lastEdge[vertex];
            pushFlow(mcf->graph, edgeID, currentFlow);
            vertex = mcf->graph->edges[edgeID].from;
        }
    }
    return (Pair){cost, flow};
}

int main() {
    int rowCount, columnCount;
    scanf("%d %d", &rowCount, &columnCount);
    
    int type[rowCount][columnCount];
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            scanf("%d", &type[i][j]);
        }
    }

    Graph graph;
    initGraph(&graph, rowCount * columnCount + 2);
    int source = graph.vertexCount - 2;
    int sink = graph.vertexCount - 1;

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            int index = i * columnCount + j;
            if ((i + j) % 2 == 0) {
                addEdge(&graph, source, index, 0, 1, -1);
                for (int k = 0; k < 4; k++) {
                    int row = i + (k == 0 ? 1 : (k == 2 ? -1 : 0));
                    int column = j + (k == 1 ? -1 : (k == 3 ? 1 : 0));
                    if (row >= 0 && row < rowCount && column >= 0 && column < columnCount) {
                        addEdge(&graph, index, row * columnCount + column, type[i][j] == type[row][column] ? 0 : 1, 1, -1);
                    }
                }
            } else {
                addEdge(&graph, index, sink, 0, 1, -1);
            }
        }
    }

    MinCostFlow mcf = {source, sink, {0}, {0}, {0}, {0}, 0, &graph};
    Pair result = minCostMaxFlow(&mcf, LONG_MAX);
    printf("%ld\n", result.first);

    return 0;
}
