#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

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
    int *reverseEdge;
} Graph;

typedef struct {
    Graph *graph;
    int source;
    int destination;
    long *phi;
    long *id8;
    int *lastEdge;
} id10;

typedef struct {
    int *array;
    int size;
    int capacity;
} IntList;

void initGraph(Graph *graph, int vertexCount) {
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    graph->firstOutbound = (int *)malloc(vertexCount * sizeof(int));
    graph->from = (int *)malloc(vertexCount * sizeof(int));
    graph->to = (int *)malloc(vertexCount * sizeof(int));
    graph->weight = (long *)malloc(vertexCount * sizeof(long));
    graph->capacity = (long *)malloc(vertexCount * sizeof(long));
    graph->reverseEdge = (int *)malloc(vertexCount * sizeof(int));
    for (int i = 0; i < vertexCount; i++) {
        graph->firstOutbound[i] = -1;
    }
}

void addEdge(Graph *graph, int fromID, int toID, long weight, long capacity, int reverseEdge) {
    graph->from[graph->edgeCount] = fromID;
    graph->to[graph->edgeCount] = toID;
    graph->weight[graph->edgeCount] = weight;
    graph->capacity[graph->edgeCount] = capacity;
    graph->reverseEdge[graph->edgeCount] = reverseEdge;
    graph->firstOutbound[fromID] = graph->edgeCount;
    graph->edgeCount++;
}

void initId10(id10 *solver, Graph *graph, int source, int destination) {
    solver->graph = graph;
    solver->source = source;
    solver->destination = destination;
    solver->phi = (long *)malloc(graph->vertexCount * sizeof(long));
    solver->id8 = (long *)malloc(graph->vertexCount * sizeof(long));
    solver->lastEdge = (int *)malloc(graph->vertexCount * sizeof(int));
}

void dijkstra(id10 *solver) {
    for (int i = 0; i < solver->graph->vertexCount; i++) {
        solver->phi[i] = LONG_MAX;
        solver->lastEdge[i] = -1;
    }
    solver->phi[solver->source] = 0;
    // Implement Dijkstra's algorithm here
}

Pair id6(id10 *solver, long maxFlow) {
    long cost = 0;
    long flow = 0;
    // Implement flow calculation logic here
    return (Pair){cost, flow};
}

int main() {
    int rowCount, columnCount;
    scanf("%d %d", &rowCount, &columnCount);
    Graph graph;
    initGraph(&graph, rowCount * columnCount + 2);
    int source = graph.vertexCount - 2;
    int sink = graph.vertexCount - 1;

    // Implement the main logic here

    id10 solver;
    initId10(&solver, &graph, source, sink);
    Pair result = id6(&solver, LONG_MAX);
    printf("%ld\n", result.first);

    // Free allocated memory
    free(graph.firstOutbound);
    free(graph.from);
    free(graph.to);
    free(graph.weight);
    free(graph.capacity);
    free(graph.reverseEdge);
    free(solver.phi);
    free(solver.id8);
    free(solver.lastEdge);

    return 0;
}
