#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;
typedef struct {
    int first;
    ll second;
} pr;

typedef struct {
    int *data;
    size_t size;
} arr;

typedef struct {
    int from;
    int to;
    ll weight;
    ll capacity;
} FlowEdge;

typedef struct {
    FlowEdge **edges;
    int vertexCount;
    int edgeCount;
} Graph;

arr createArr(size_t size) {
    arr a;
    a.data = (int *)malloc(size * sizeof(int));
    a.size = size;
    return a;
}

void freeArr(arr *a) {
    free(a->data);
}

void addEdge(Graph *graph, FlowEdge *edge) {
    graph->edges[graph->edgeCount++] = edge;
}

Graph createGraph(int vertexCount) {
    Graph graph;
    graph.vertexCount = vertexCount;
    graph.edgeCount = 0;
    graph.edges = (FlowEdge **)malloc(vertexCount * sizeof(FlowEdge *));
    return graph;
}

void freeGraph(Graph *graph) {
    free(graph->edges);
}

void readInt(int *x) {
    scanf("%d", x);
}

void readIntArray(arr *a, int size) {
    for (size_t i = 0; i < size; i++) {
        scanf("%d", &a->data[i]);
    }
}

void solve(int n, int m, arr b, arr w, arr x, arr y) {
    Graph graph = createGraph(n);
    for (int i = 0; i < n - 1; i++) {
        FlowEdge *edge = (FlowEdge *)malloc(sizeof(FlowEdge));
        edge->from = x.data[i];
        edge->to = y.data[i];
        edge->weight = 0; // Initialize as needed
        edge->capacity = 0; // Initialize as needed
        addEdge(&graph, edge);
    }

    // Implement the logic of the original C++ code here...

    freeGraph(&graph);
}

int main() {
    int n;
    readInt(&n);
    for (int i = 0; i < n; i++) {
        int m;
        readInt(&m);
        arr b = createArr(n);
        arr w = createArr(n);
        readIntArray(&b, n);
        readIntArray(&w, n);
        arr x = createArr(n - 1);
        arr y = createArr(n - 1);
        readIntArray(&x, n - 1);
        readIntArray(&y, n - 1);
        solve(n, m, b, w, x, y);
        freeArr(&b);
        freeArr(&w);
        freeArr(&x);
        freeArr(&y);
    }
    return 0;
}
