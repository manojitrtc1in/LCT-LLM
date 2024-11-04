#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Edge {
    struct Point* vertex0;
    struct Point* vertex1;
    int bidirectional;
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
        graph->vertices[i] = (Vertex*)malloc(sizeof(Vertex));
        graph->vertices[i]->index = i;
        graph->vertices[i]->edges = NULL;
        graph->vertices[i]->num_edges = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int vertex0, int vertex1, int bidirectional) {
