#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Edge {
    struct Point* vertex0;
    struct Point* vertex1;
    bool bidirectional;
} Edge;

typedef struct Vertex {
    int index;
    struct Edge** edges;
    int num_edges;
} Vertex;

typedef struct Graph {
    struct Vertex** vertices;
    int num_vertices;
} Graph;

Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = (Vertex**)malloc(num_vertices * sizeof(Vertex*));
    graph->num_vertices = num_vertices;

    for (int i = 0; i < num_vertices; i++) {
        Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
        vertex->index = i;
        vertex->edges = NULL;
        vertex->num_edges = 0;
        graph->vertices[i] = vertex;
    }

    return graph;
}

void addEdge(Graph* graph, int vertex0_index, int vertex1_index, bool bidirectional) {
    Vertex* vertex0 = graph->vertices[vertex0_index];
    Vertex* vertex1 = graph->vertices[vertex1_index];

    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->vertex0 = vertex0;
    edge->vertex1 = vertex1;
    edge->bidirectional = bidirectional;

    vertex0->num_edges++;
    vertex0->edges = (Edge**)realloc(vertex0->edges, vertex0->num_edges * sizeof(Edge*));
    vertex0->edges[vertex0->num_edges - 1] = edge;

    if (bidirectional) {
        vertex1->num_edges++;
        vertex1->edges = (Edge**)realloc(vertex1->edges, vertex1->num_edges * sizeof(Edge*));
        vertex1->edges[vertex1->num_edges - 1] = edge;
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->vertices[i]->edges);
        free(graph->vertices[i]);
    }
    free(graph->vertices);
    free(graph);
}

int main() {
    int n;
    scanf("%d", &n);

    Graph* graph = createGraph(n);

    for (int i = 0; i < n; i++) {
        int x, y;
