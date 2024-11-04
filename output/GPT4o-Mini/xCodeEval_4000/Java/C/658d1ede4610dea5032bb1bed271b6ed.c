#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void addEdge(Graph *graph, int fromID, int toID, long weight, long capacity) {
    if (graph->edgeCount >= graph->vertexCount) {
        graph->vertexCount *= 2;
        graph->firstOutbound = realloc(graph->firstOutbound, graph->vertexCount * sizeof(int));
        graph->from = realloc(graph->from, graph->vertexCount * sizeof(int));
        graph->to = realloc(graph->to, graph->vertexCount * sizeof(int));
        graph->weight = realloc(graph->weight, graph->vertexCount * sizeof(long));
        graph->capacity = realloc(graph->capacity, graph->vertexCount * sizeof(long));
        graph->nextOutbound = realloc(graph->nextOutbound, graph->vertexCount * sizeof(int));
    }
    graph->from[graph->edgeCount] = fromID;
    graph->to[graph->edgeCount] = toID;
    graph->weight[graph->edgeCount] = weight;
    graph->capacity[graph->edgeCount] = capacity;
    graph->nextOutbound[graph->edgeCount] = graph->firstOutbound[fromID];
    graph->firstOutbound[fromID] = graph->edgeCount++;
}

void dijkstraAlgorithm(MinCostFlow *mcf) {
    for (int i = 0; i < mcf->graph->vertexCount; i++) {
        mcf->dijkstraResult[i] = LONG_MAX;
        mcf->lastEdge[i] = -1;
    }
    mcf->dijkstraResult[mcf->source] = 0;

    // Implement a simple priority queue or use an array to find the minimum
    // This is a simplified version, a real implementation would use a priority queue
    for (int i = 0; i < mcf->graph->vertexCount; i++) {
        for (int edgeID = mcf->graph->firstOutbound[i]; edgeID != -1; edgeID = mcf->graph->nextOutbound[edgeID]) {
            int next = mcf->graph->to[edgeID];
            long total = mcf->graph->weight[edgeID] + mcf->dijkstraResult[i];
            if (mcf->graph->capacity[edgeID] > 0 && mcf->dijkstraResult[next] > total) {
                mcf->dijkstraResult[next] = total;
                mcf->lastEdge[next] = edgeID;
            }
        }
    }
}

Pair minCostMaxFlow(Graph *graph, int source, int destination) {
    MinCostFlow mcf = {graph, source, destination, malloc(graph->vertexCount * sizeof(long)), malloc(graph->vertexCount * sizeof(long)), malloc(graph->vertexCount * sizeof(int)), malloc(graph->vertexCount * sizeof(int)), 0};
    long cost = 0, flow = 0;

    while (1) {
        dijkstraAlgorithm(&mcf);
        if (mcf.lastEdge[destination] == -1) {
            break;
        }
        long currentFlow = LONG_MAX;
        for (int vertex = destination; vertex != source; vertex = graph->from[mcf.lastEdge[vertex]]) {
            currentFlow = currentFlow < graph->capacity[mcf.lastEdge[vertex]] ? currentFlow : graph->capacity[mcf.lastEdge[vertex]];
        }
        flow += currentFlow;
        for (int vertex = destination; vertex != source; vertex = graph->from[mcf.lastEdge[vertex]]) {
            graph->capacity[mcf.lastEdge[vertex]] -= currentFlow;
            graph->capacity[mcf.lastEdge[vertex] ^ 1] += currentFlow; // Assuming reverse edge exists
            cost += currentFlow * graph->weight[mcf.lastEdge[vertex]];
        }
    }
    free(mcf.phi);
    free(mcf.dijkstraResult);
    free(mcf.lastEdge);
    free(mcf.visited);
    return (Pair){cost, flow};
}

int main() {
    int n;
    scanf("%d", &n);
    char *s = malloc(n * sizeof(char));
    scanf("%s", s);

    Graph graph = {0};
    graph.vertexCount = 128; // Adjust as needed
    graph.firstOutbound = malloc(graph.vertexCount * sizeof(int));
    memset(graph.firstOutbound, -1, graph.vertexCount * sizeof(int));
    graph.from = malloc(2 * n * sizeof(int));
    graph.to = malloc(2 * n * sizeof(int));
    graph.weight = malloc(2 * n * sizeof(long));
    graph.capacity = malloc(2 * n * sizeof(long));
    graph.nextOutbound = malloc(2 * n * sizeof(int));

    // Add edges and other logic here...

    Pair result = minCostMaxFlow(&graph, 0, 1); // Adjust source and destination
    printf("%ld\n", -result.first);

    free(s);
    free(graph.firstOutbound);
    free(graph.from);
    free(graph.to);
    free(graph.weight);
    free(graph.capacity);
    free(graph.nextOutbound);
    return 0;
}
