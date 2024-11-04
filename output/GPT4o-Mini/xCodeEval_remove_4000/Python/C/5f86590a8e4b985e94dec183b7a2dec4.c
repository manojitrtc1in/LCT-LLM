#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define INF INT_MAX

typedef struct Node {
    struct Node *prev, *next;
} Node;

typedef struct id17 {
    Node *prev, *next;
} id17;

Node* connect(Node* self, Node* node) {
    self->next = node;
    node->prev = self;
    return node;
}

Node* splice(Node* self, Node* fragment) {
    if (fragment->prev) fragment->prev->next = NULL;

    Node* u = self;
    Node* v = fragment;
    Node* w = self->next;

    connect(u, v);
    while (v->next) v = v->next;
    connect(v, w);

    return v;
}

void splice1(Node* self, Node* node) {
    connect(node, self->next);
    connect(self, node);
}

void eject(Node* self) {
    self->prev->next = self->next;
}

typedef struct AbstractHeap {
    int n;
    Node *root;
    void (*push)(struct AbstractHeap*, int, int);
    void (*pop)(struct AbstractHeap*);
    bool (*id6)(struct AbstractHeap*);
    int (*id18)(struct AbstractHeap*);
} AbstractHeap;

typedef struct id13 {
    int key, value;
    struct id13 *parent, *child;
    int degree;
    bool mark;
} id13;

typedef struct id0 {
    AbstractHeap base;
    int n;
    id13 *index[100]; // Assuming a max size of 100 for simplicity
} id0;

void push_id0(id0* self, int key, int value) {
    id13* node = malloc(sizeof(id13));
    node->key = key;
    node->value = value;
    node->parent = NULL;
    node->child = NULL;
    node->degree = 0;
    node->mark = false;

    self->index[value] = node;

    if (self->base.root == NULL) {
        connect(node, node);
        self->base.root = node;
        self->n = 1;
    } else {
        splice1(self->base.root, node);
        if (key < self->base.root->key) self->base.root = node;
        self->n++;
    }
}

void pop_id0(id0* self) {
    id13* z = self->base.root;

    if (z->child) {
        for (Node* c = z->child; c; c = c->next) c->parent = NULL;
        splice(z, z->child);
    }

    if (z->next == z) {
        self->base.root = NULL;
    } else {
        self->base.root = z->next;
        eject(z);
    }

    self->n--;
    free(self->index[z->value]);
}

bool id6_id0(id0* self) {
    return self->n > 0;
}

int id18_id0(id0* self) {
    return self->n;
}

typedef struct Graph {
    int maxV;
    bool isflow;
    bool sparse;
    int *V;
    int **E;
    int *adj;
    int nV;
    int nE;
} Graph;

Graph* create_graph(int maxV, bool isflow, bool sparse) {
    Graph* graph = malloc(sizeof(Graph));
    graph->maxV = maxV;
    graph->isflow = isflow;
    graph->sparse = sparse;
    graph->V = malloc(maxV * sizeof(int));
    graph->E = malloc(maxV * sizeof(int*));
    graph->adj = malloc(maxV * sizeof(int));
    graph->nV = 0;
    graph->nE = 0;

    for (int i = 0; i < maxV; i++) {
        graph->E[i] = malloc(maxV * sizeof(int));
        for (int j = 0; j < maxV; j++) {
            graph->E[i][j] = isflow ? 0 : INF;
        }
    }

    return graph;
}

void add_vertex(Graph* graph, int label) {
    graph->V[graph->nV++] = label;
}

void add_edge(Graph* graph, int u, int v, int w) {
    graph->E[u][v] = w;
    graph->adj[u] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph* G = create_graph(n, false, true);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(G, u, v, 1);
    }

    int k;
    scanf("%d", &k);
    int* p = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        scanf("%d", &p[i]);
    }

    // Additional logic for processing the graph and paths...

    free(p);
    for (int i = 0; i < n; i++) {
        free(G->E[i]);
    }
    free(G->E);
    free(G->V);
    free(G->adj);
    free(G);
    return 0;
}
