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

void addEdge(Graph* graph, int vertex0, int vertex1, bool bidirectional) {
