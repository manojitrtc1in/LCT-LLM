#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAXV 100000

typedef struct LinkedListNodeBase {
    struct LinkedListNodeBase* prev;
    struct LinkedListNodeBase* next;
} LinkedListNodeBase;

LinkedListNodeBase* LinkedListNodeBase_new() {
    LinkedListNodeBase* node = (LinkedListNodeBase*)malloc(sizeof(LinkedListNodeBase));
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void LinkedListNodeBase_connect(LinkedListNodeBase* self, LinkedListNodeBase* node) {
    self->next = node;
    node->prev = self;
}

LinkedListNodeBase* LinkedListNodeBase_splice(LinkedListNodeBase* self, LinkedListNodeBase* fragment) {
    if (fragment->prev) fragment->prev->next = NULL;

    LinkedListNodeBase* u = self;
    LinkedListNodeBase* v = fragment;
    LinkedListNodeBase* w = self->next;

    LinkedListNodeBase_connect(u, v);
    while (v->next) v = v->next;
    LinkedListNodeBase_connect(v, w);

    return v;
}

void LinkedListNodeBase_splice1(LinkedListNodeBase* self, LinkedListNodeBase* node) {
    LinkedListNodeBase_connect(node, self->next);
    LinkedListNodeBase_connect(self, node);
}

void LinkedListNodeBase_eject(LinkedListNodeBase* self) {
    self->prev->next = self->next;
}

typedef struct _FibHeapNode {
    LinkedListNodeBase base;
    int key;
    int value;
    struct _FibHeapNode* parent;
    struct _FibHeapNode* child;
    int degree;
    bool mark;
} _FibHeapNode;

_FibHeapNode* _FibHeapNode_new(int key, int value) {
    _FibHeapNode* node = (_FibHeapNode*)malloc(sizeof(_FibHeapNode));
    node->base.prev = NULL;
    node->base.next = NULL;
    node->key = key;
    node->value = value;
    node->parent = NULL;
    node->child = NULL;
    node->degree = 0;
    node->mark = false;
    return node;
}

typedef struct FibonacciHeap {
    LinkedListNodeBase* root;
    int n;
    int* index;
} FibonacciHeap;

FibonacciHeap* FibonacciHeap_new() {
    FibonacciHeap* heap = (FibonacciHeap*)malloc(sizeof(FibonacciHeap));
    heap->root = NULL;
    heap->n = 0;
    heap->index = NULL;
    return heap;
}

bool FibonacciHeap_empty(FibonacciHeap* heap) {
    return heap->n == 0;
}

void FibonacciHeap_push(FibonacciHeap* heap, int key, int value) {
    _FibHeapNode* node = _FibHeapNode_new(key, value);
    if (heap->root == NULL) {
        LinkedListNodeBase_connect(&node->base, &node->base);
        heap->root = &node->base;
        heap->n = 1;
    } else {
        LinkedListNodeBase_splice1(heap->root, &node->base);
        if (key < ((_FibHeapNode*)heap->root)->key) {
            heap->root = &node->base;
        }
        heap->n++;
    }
}

void FibonacciHeap_link(_FibHeapNode* y, _FibHeapNode* x) {
    LinkedListNodeBase_eject(&y->base);
    y->parent = x;
    if (x->child) {
        LinkedListNodeBase_splice1(x->child, &y->base);
    } else {
        x->child = y;
        LinkedListNodeBase_connect(&y->base, &y->base);
    }
    x->degree++;
    y->mark = false;
}

void FibonacciHeap_consolidate(FibonacciHeap* heap) {
    int maxDegree = log(heap->n) / log(2) + 1;
    _FibHeapNode** A = (_FibHeapNode**)malloc(maxDegree * sizeof(_FibHeapNode*));
    for (int i = 0; i < maxDegree; i++) {
        A[i] = NULL;
    }

    LinkedListNodeBase* x = heap->root;
    while (true) {
        LinkedListNodeBase* next = x->next;
        _FibHeapNode* node = (_FibHeapNode*)x;
        int d = node->degree;
        while (A[d] != NULL) {
            _FibHeapNode* y = A[d];
            if (node->key > y->key) {
                _FibHeapNode* temp = node;
                node = y;
                y = temp;
            }
            FibonacciHeap_link(y, node);
            A[d] = NULL;
            d++;
        }
        A[d] = node;
        if (x == heap->root) {
            break;
        }
        x = next;
    }

    heap->root = NULL;
    for (int i = 0; i < maxDegree; i++) {
        if (A[i] != NULL) {
            if (heap->root == NULL) {
                heap->root = &A[i]->base;
            } else {
                LinkedListNodeBase_splice1(heap->root, &A[i]->base);
                if (A[i]->key < ((_FibHeapNode*)heap->root)->key) {
                    heap->root = &A[i]->base;
                }
            }
        }
    }

    free(A);
}

int FibonacciHeap_pop(FibonacciHeap* heap) {
    _FibHeapNode* z = (_FibHeapNode*)heap->root;

    if (z->child) {
        LinkedListNodeBase* c = z->child;
        do {
            ((_FibHeapNode*)c)->parent = NULL;
            c = c->next;
        } while (c != z->child);
        LinkedListNodeBase_splice(z, z->child);
    }

    if (z->next == z) {
        heap->root = NULL;
    } else {
        heap->root = z->next;
        LinkedListNodeBase_eject(z);
        FibonacciHeap_consolidate(heap);
    }

    int value = z->value;
    free(z);
    heap->n--;
    return value;
}

typedef struct Implicit2Heap {
    int tree[MAXV][2];
    int index[MAXV];
    int size;
} Implicit2Heap;

Implicit2Heap* Implicit2Heap_new() {
    Implicit2Heap* heap = (Implicit2Heap*)malloc(sizeof(Implicit2Heap));
    heap->size = 0;
    memset(heap->tree, 0, sizeof(heap->tree));
    memset(heap->index, 0, sizeof(heap->index));
    return heap;
}

bool Implicit2Heap_empty(Implicit2Heap* heap) {
    return heap->size == 0;
}

void Implicit2Heap_push(Implicit2Heap* heap, int key, int value) {
    int i = heap->size++;
    heap->index[value] = i;
    heap->tree[i][0] = key;
    heap->tree[i][1] = value;
    int j = (i + 1) / 2 - 1;
    while (i > 0 && heap->tree[j][0] > heap->tree[i][0]) {
        int temp[2];
        memcpy(temp, heap->tree[i], sizeof(temp));
        memcpy(heap->tree[i], heap->tree[j], sizeof(temp));
        memcpy(heap->tree[j], temp, sizeof(temp));
        heap->index[heap->tree[i][1]] = i;
        heap->index[heap->tree[j][1]] = j;
        i = j;
        j = (i + 1) / 2 - 1;
    }
}

void Implicit2Heap_heapify(Implicit2Heap* heap, int i) {
    int left = (i + 1) * 2 - 1;
    int right = (i + 1) * 2 + 1 - 1;
    int smallest = i;
    if (left < heap->size && heap->tree[left][0] < heap->tree[smallest][0]) {
        smallest = left;
    }
    if (right < heap->size && heap->tree[right][0] < heap->tree[smallest][0]) {
        smallest = right;
    }
    if (smallest != i) {
        int temp[2];
        memcpy(temp, heap->tree[i], sizeof(temp));
        memcpy(heap->tree[i], heap->tree[smallest], sizeof(temp));
        memcpy(heap->tree[smallest], temp, sizeof(temp));
        heap->index[heap->tree[i][1]] = i;
        heap->index[heap->tree[smallest][1]] = smallest;
        Implicit2Heap_heapify(heap, smallest);
    }
}

int Implicit2Heap_pop(Implicit2Heap* heap) {
    int value = heap->tree[0][1];
    heap->index[value] = -1;
    heap->size--;
    if (heap->size > 0) {
        memcpy(heap->tree[0], heap->tree[heap->size], sizeof(heap->tree[0]));
        heap->index[heap->tree[0][1]] = 0;
        Implicit2Heap_heapify(heap, 0);
    }
    return value;
}

typedef struct _PairingHeapNode {
    LinkedListNodeBase base;
    int key;
    int value;
    struct _PairingHeapNode* parent;
    struct _PairingHeapNode* left;
    struct _PairingHeapNode* right;
} _PairingHeapNode;

_PairingHeapNode* _PairingHeapNode_new(int key, int value) {
    _PairingHeapNode* node = (_PairingHeapNode*)malloc(sizeof(_PairingHeapNode));
    node->base.prev = NULL;
    node->base.next = NULL;
    node->key = key;
    node->value = value;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct PairingHeap {
    LinkedListNodeBase* root;
    int* index;
} PairingHeap;

PairingHeap* PairingHeap_new() {
    PairingHeap* heap = (PairingHeap*)malloc(sizeof(PairingHeap));
    heap->root = NULL;
    heap->index = NULL;
    return heap;
}

bool PairingHeap_empty(PairingHeap* heap) {
    return heap->root == NULL;
}

void PairingHeap_push(PairingHeap* heap, int key, int value) {
    _PairingHeapNode* node = _PairingHeapNode_new(key, value);
    if (heap->root == NULL) {
        heap->root = &node->base;
    } else {
        heap->root = LinkedListNodeBase_splice(heap->root, &node->base);
    }
}

void PairingHeap_link(_PairingHeapNode* y, _PairingHeapNode* x) {
    LinkedListNodeBase_eject(&y->base);
    y->parent = x;
    if (x->left == NULL) {
        x->left = y;
        y->parent = x;
    } else {
        _PairingHeapNode* r = x->left;
        while (r->right) {
            r = r->right;
        }
        r->right = y;
        y->parent = r;
    }
}

void PairingHeap_consolidate(PairingHeap* heap) {
    _PairingHeapNode* A[MAXV];
    for (int i = 0; i < MAXV; i++) {
        A[i] = NULL;
    }

    LinkedListNodeBase* x = heap->root;
    while (x != NULL) {
        LinkedListNodeBase* next = x->next;
        _PairingHeapNode* node = (_PairingHeapNode*)x;
        int d = node->degree;
        while (A[d] != NULL) {
            _PairingHeapNode* y = A[d];
            if (node->key > y->key) {
                _PairingHeapNode* temp = node;
                node = y;
                y = temp;
            }
            PairingHeap_link(y, node);
            A[d] = NULL;
            d++;
        }
        A[d] = node;
        x = next;
    }

    heap->root = NULL;
    for (int i = 0; i < MAXV; i++) {
        if (A[i] != NULL) {
            if (heap->root == NULL) {
                heap->root = &A[i]->base;
            } else {
                heap->root = LinkedListNodeBase_splice(heap->root, &A[i]->base);
            }
        }
    }
}

int PairingHeap_pop(PairingHeap* heap) {
    _PairingHeapNode* z = (_PairingHeapNode*)heap->root;

    if (z->left == NULL) {
        heap->root = NULL;
    } else {
        heap->root = z->left;
        LinkedListNodeBase_eject(&z->base);
        PairingHeap_consolidate(heap);
    }

    int value = z->value;
    free(z);
    return value;
}

typedef struct Graph {
    int maxV;
    bool isflow;
    bool sparse;
    int V[MAXV];
    int E[MAXV][MAXV];
    int adj[MAXV][MAXV];
    int levels[MAXV][MAXV];
    int nV;
    int nE;
} Graph;

Graph* Graph_new(int maxV, bool isflow, bool sparse) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->maxV = maxV;
    graph->isflow = isflow;
    graph->sparse = sparse;
    memset(graph->V, 0, sizeof(graph->V));
    memset(graph->E, 0, sizeof(graph->E));
    memset(graph->adj, 0, sizeof(graph->adj));
    memset(graph->levels, 0, sizeof(graph->levels));
    graph->nV = 0;
    graph->nE = 0;
    return graph;
}

void Graph_add_vertex(Graph* graph, int label) {
    graph->V[graph->nV] = label;
    graph->nV++;
}

void Graph_add_edge(Graph* graph, int u_label, int v_label, int w) {
    int u = -1;
    int v = -1;
    for (int i = 0; i < graph->nV; i++) {
        if (graph->V[i] == u_label) {
            u = i;
        }
        if (graph->V[i] == v_label) {
            v = i;
        }
    }
    if (u != -1 && v != -1) {
        if (graph->isflow) {
            graph->E[u][v] += w;
            graph->adj[u][v] = 1;
            graph->adj[v][u] = 1;
        } else {
            graph->E[u][v] = w;
            graph->adj[u][v] = 1;
        }
        graph->nE++;
    }
}

void Graph_trim(Graph* graph, int u_label) {
    int u = -1;
    for (int i = 0; i < graph->nV; i++) {
        if (graph->V[i] == u_label) {
            u = i;
        }
    }
    if (u != -1) {
        for (int v = 0; v < graph->nV; v++) {
            graph->adj[u][v] = 0;
            graph->adj[v][u] = 0;
        }
        if (graph->sparse) {
            memset(graph->E[u], 0, sizeof(graph->E[u]));
        } else {
            for (int v = 0; v < graph->nV; v++) {
                graph->E[u][v] = 0;
            }
        }
    }
}

int Graph_bfs_levels(Graph* graph, int s, int t) {
    memset(graph->levels[s], 0, sizeof(graph->levels[s]));
    graph->levels[s][s] = 0;

    LinkedListNodeBase* queue = LinkedListNodeBase_new();
    LinkedListNodeBase_connect(queue, &graph->levels[s][0]);
    while (queue != NULL) {
        LinkedListNodeBase* u = queue;
        LinkedListNodeBase_eject(u);
        for (int v = 0; v < graph->nV; v++) {
            if (graph->E[u->value][v] > 0 && graph->levels[s][v] == 0) {
                graph->levels[s][v] = graph->levels[s][u->value] + 1;
                LinkedListNodeBase* node = LinkedListNodeBase_new();
                LinkedListNodeBase_connect(node, &graph->levels[s][v]);
                LinkedListNodeBase_connect(queue, node);
            }
        }
    }

    return graph->levels[s][t];
}

int Graph_push_blocking_flow(Graph* graph, int s, int t) {
    int A[MAXV];
    for (int i = 0; i < MAXV; i++) {
        A[i] = -1;
    }

    int blocking_flow = 0;
    LinkedListNodeBase* pointers[MAXV];
    for (int u = 0; u < graph->nV; u++) {
        pointers[u] = graph->adj[u][0] ? &graph->adj[u][0] : NULL;
    }

    int u = s;
    while (true) {
        if (u == t) {
            break;
        }
        if (pointers[u] != NULL) {
            int v = pointers[u]->value;
            if (graph->levels[s][v] == graph->levels[s][u] + 1 && graph->E[u][v] > 0) {
                int v_flow = Graph_push_blocking_flow(graph, v, t);
                graph->E[u][v] -= v_flow;
                graph->E[v][u] += v_flow;
                blocking_flow += v_flow;
                if (blocking_flow == 0) {
                    pointers[u] = pointers[u]->next;
                }
            } else {
                pointers[u] = pointers[u]->next;
            }
        } else {
            int min_flow = graph->isflow ? 1 : 0;
            for (int v = 0; v < graph->nV; v++) {
                if (graph->levels[s][v] == graph->levels[s][u] + 1 && graph->E[u][v] > min_flow) {
                    int v_flow = Graph_push_blocking_flow(graph, v, t);
                    graph->E[u][v] -= v_flow;
                    graph->E[v][u] += v_flow;
                    blocking_flow += v_flow;
                    if (blocking_flow == 0) {
                        pointers[u] = pointers[u]->next;
                    }
                }
            }
        }
    }

    return blocking_flow;
}

int Graph_max_flow(Graph* graph, int s, int t) {
    int E_saved[MAXV][MAXV];
    memcpy(E_saved, graph->E, sizeof(E_saved));

    int mf = 0;
    while (Graph_bfs_levels(graph, s, t) != 0) {
        mf += Graph_push_blocking_flow(graph, s, t);
    }

    memcpy(graph->E, E_saved, sizeof(graph->E));
    return mf;
}

void Graph_single_source_spaths(Graph* graph, int s, int* t_labels, int t_labels_size, int d_limit, Implicit2Heap* heap, int* spaths, int* parents, int* found, int* stop) {
    int t_set[MAXV];
    memset(t_set, 0, sizeof(t_set));
    for (int i = 0; i < t_labels_size; i++) {
        t_set[t_labels[i]] = 1;
    }

    Implicit2Heap_push(heap, 0, s);
    memset(spaths, -1, sizeof(int) * MAXV);
    memset(parents, -1, sizeof(int) * MAXV);
    int t_found[MAXV];
    int t_found_size = 0;
    while (!Implicit2Heap_empty(heap)) {
        int su = heap->tree[0][0];
        int u = Implicit2Heap_pop(heap);
        if (su >= d_limit) {
            *stop = d_limit;
            break;
        }
        spaths[u] = su;
        if (t_set[u]) {
            t_set[u] = 0;
            t_found[t_found_size] = u;
            t_found_size++;
            if (t_found_size == t_labels_size) {
                *stop = su;
                break;
            }
        }
        for (int v = 0; v < graph->nV; v++) {
            int sv = su + graph->E[u][v];
            if (graph->E[u][v] > 0) {
                if (spaths[v] == -1) {
                    Implicit2Heap_push(heap, sv, v);
                    parents[v] = u;
                } else if (sv < spaths[v]) {
                    Implicit2Heap_push(heap, sv, v);
                    parents[v] = u;
                }
            }
        }
    }
    if (Implicit2Heap_empty(heap)) {
        *stop = INFINITY;
    }

    found = (int*)malloc(sizeof(int) * t_found_size);
    memcpy(found, t_found, sizeof(int) * t_found_size);
}

int Graph_shortest_path(Graph* graph, int s, int t, int* t_labels, int t_labels_size, int d_limit) {
    int spaths[MAXV];
    int parents[MAXV];
    int found[MAXV];
    int stop;
    Implicit2Heap* heap = Implicit2Heap_new();
    Graph_single_source_spaths(graph, s, t_labels, t_labels_size, d_limit, heap, spaths, parents, found, &stop);
    free(heap);
    return spaths[t];
}

bool Graph_is_bipartite(Graph* graph) {
    int colors[MAXV];
    memset(colors, 0, sizeof(colors));
    for (int s = 0; s < graph->nV; s++) {
        if (colors[s] != 0) {
            continue;
        }
        colors[s] = 1;
        LinkedListNodeBase* queue = LinkedListNodeBase_new();
        LinkedListNodeBase_connect(queue, &graph->adj[s][0]);
        while (queue != NULL) {
            LinkedListNodeBase* u = queue;
            LinkedListNodeBase_eject(u);
            for (int v = 0; v < graph->nV; v++) {
                if (graph->adj[u->value][v] && colors[v] == 0) {
                    colors[v] = -colors[u->value];
                    LinkedListNodeBase* node = LinkedListNodeBase_new();
                    LinkedListNodeBase_connect(node, &graph->adj[v][0]);
                    LinkedListNodeBase_connect(queue, node);
                } else if (graph->adj[u->value][v] && colors[v] == colors[u->value]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int roads[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &roads[i][0], &roads[i][1]);
    }
    int k;
    scanf("%d", &k);
    int p[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &p[i]);
    }

    Graph* G = Graph_new(n, false, true);
    for (int i = 1; i <= n; i++) {
        Graph_add_vertex(G, i);
    }
    for (int i = 0; i < m; i++) {
        Graph_add_edge(G, roads[i][1], roads[i][0], 1);
    }

    int spaths[MAXV];
    int min_rebuild = 0;
    int max_rebuild = 0;
    for (int i = 0; i < k - 1; i++) {
        int u = p[i];
        int u_d = Graph_shortest_path(G, p[k - 1], u, NULL, 0, INFINITY);
        int v = p[i + 1];
        int v_d = Graph_shortest_path(G, p[k - 1], v, NULL, 0, INFINITY);

        if (v_d != u_d - 1) {
            min_rebuild++;
            max_rebuild++;
            continue;
        }

        bool found = false;
        for (int w = 0; w < G->nV; w++) {
            if (w != v && spaths[w] == v_d) {
                max_rebuild++;
                found = true;
                break;
            }
        }
        if (!found) {
            min_rebuild++;
            max_rebuild++;
        }
    }

    printf("%d %d\n", min_rebuild, max_rebuild);

    free(G);
}
