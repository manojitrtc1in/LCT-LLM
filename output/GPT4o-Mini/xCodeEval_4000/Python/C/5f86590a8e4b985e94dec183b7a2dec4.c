#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

typedef struct LinkedListNodeBase {
    struct LinkedListNodeBase *prev;
    struct LinkedListNodeBase *next;
} LinkedListNodeBase;

void connect(LinkedListNodeBase *self, LinkedListNodeBase *node) {
    self->next = node;
    node->prev = self;
}

LinkedListNodeBase* splice(LinkedListNodeBase *self, LinkedListNodeBase *fragment) {
    if (fragment->prev) fragment->prev->next = NULL;

    LinkedListNodeBase *u = self;
    LinkedListNodeBase *v = fragment;
    LinkedListNodeBase *w = self->next;

    connect(u, v);
    while (v->next) v = v->next;
    connect(v, w);

    return v;
}

void splice1(LinkedListNodeBase *self, LinkedListNodeBase *node) {
    connect(node, self->next);
    connect(self, node);
}

void eject(LinkedListNodeBase *self) {
    self->prev->next = self->next;
}

typedef struct AbstractHeap {
    void (*push)(struct AbstractHeap *self, int key, int value);
    void (*pop)(struct AbstractHeap *self);
    void (*decrease_key)(struct AbstractHeap *self, int value, int key);
    void (*merge)(struct AbstractHeap *self, struct AbstractHeap *other);
    bool (*contains)(struct AbstractHeap *self, int value);
    int (*getitem)(struct AbstractHeap *self, int value);
    int (*len)(struct AbstractHeap *self);
    bool (*bool)(struct AbstractHeap *self);
} AbstractHeap;

typedef struct FibHeapNode {
    LinkedListNodeBase base;
    int key;
    int value;
    struct FibHeapNode *parent;
    struct FibHeapNode *child;
    int degree;
    bool mark;
} FibHeapNode;

typedef struct FibonacciHeap {
    AbstractHeap base;
    int n;
    FibHeapNode *root;
    // Add index structure here
} FibonacciHeap;

void push(FibonacciHeap *self, int key, int value) {
    FibHeapNode *node = malloc(sizeof(FibHeapNode));
    node->key = key;
    node->value = value;
    node->parent = NULL;
    node->child = NULL;
    node->degree = 0;
    node->mark = false;

    if (self->root == NULL) {
        connect(node, node);
        self->root = node;
        self->n = 1;
    } else {
        splice1(self->root, node);
        if (key < self->root->key) self->root = node;
        self->n++;
    }
}

typedef struct Graph {
    int maxV;
    bool isflow;
    bool sparse;
    int **E;
    int *V;
    int *V_index;
    int nV;
    int nE;
} Graph;

Graph* create_graph(int maxV, bool isflow, bool sparse) {
    Graph *g = malloc(sizeof(Graph));
    g->maxV = maxV;
    g->isflow = isflow;
    g->sparse = sparse;
    g->nV = 0;
    g->nE = 0;
    g->V = malloc(maxV * sizeof(int));
    g->V_index = malloc(maxV * sizeof(int));
    g->E = malloc(maxV * sizeof(int*));
    for (int i = 0; i < maxV; i++) {
        g->E[i] = malloc(maxV * sizeof(int));
        for (int j = 0; j < maxV; j++) {
            g->E[i][j] = isflow ? 0 : INT_MAX;
        }
    }
    return g;
}

void add_vertex(Graph *g, int label) {
    g->V[g->nV] = label;
    g->V_index[label] = g->nV;
    g->nV++;
}

void add_edge(Graph *g, int u_label, int v_label, int w) {
    int u = g->V_index[u_label];
    int v = g->V_index[v_label];
    g->E[u][v] = w;
    g->nE++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *G = create_graph(n, false, true);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(G, v, u, 1);
    }
    int k;
    scanf("%d", &k);
    int *p = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        scanf("%d", &p[i]);
    }

    // Implement the rest of the logic here...

    free(p);
    for (int i = 0; i < n; i++) {
        free(G->E[i]);
    }
    free(G->E);
    free(G->V);
    free(G->V_index);
    free(G);
    return 0;
}
