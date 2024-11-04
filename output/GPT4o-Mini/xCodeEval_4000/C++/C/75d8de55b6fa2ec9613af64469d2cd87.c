#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
} BiEdge;

typedef struct {
    BiEdge **edges;
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

Graph createGraph(int vertexCount) {
    Graph g;
    g.vertexCount = vertexCount;
    g.edgeCount = 0;
    g.edges = (BiEdge **)malloc(vertexCount * sizeof(BiEdge *));
    for (int i = 0; i < vertexCount; i++) {
        g.edges[i] = NULL;
    }
    return g;
}

void addEdge(Graph *g, BiEdge *edge) {
    g->edges[g->edgeCount++] = edge;
}

void freeGraph(Graph *g) {
    for (int i = 0; i < g->edgeCount; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
}

void decreaseByOne(arr *array, int n) {
    for (int i = 0; i < n; i++) {
        array->data[i]--;
    }
}

void calcQ(Graph *g, arr *q, int vert, int last) {
    q->data[vert] = 1;
    for (int i = 0; i < g->edgeCount; i++) {
        BiEdge *e = g->edges[i];
        int next = e->to;
        if (next == last) continue;
        calcQ(g, q, next, vert);
        q->data[vert] += q->data[next];
    }
}

void go(Graph *g, arr *q, arr *answer, int vert, int last) {
    int id = -1;
    for (int i = 0; i < g->edgeCount; i++) {
        BiEdge *e = g->edges[i];
        int next = e->to;
        if (next == last) continue;
        go(g, q, answer, next, vert);
        if (id == -1 || q->data[next] > q->data[id]) {
            id = next;
        }
    }

    ll delta = 0; // Placeholder for weight difference
    arr cur = createArr(q->size + 2);
    if (id == -1) {
        cur.data[0] = 0;
        cur.data[1] = (delta > 0) ? 1 : 0;
        return;
    }

    arr aid = answer[id];
    for (int i = 0; i <= q->data[id]; i++) {
        cur.data[i] = aid.data[i] + delta;
    }

    int sz = q->data[id];
    for (int i = sz + 1; i <= q->data[vert]; i++) {
        cur.data[i] = -1;
    }

    for (int i = 0; i < g->edgeCount; i++) {
        BiEdge *e = g->edges[i];
        int next = e->to;
        if (next == last || next == id) continue;
        arr anext = answer[next];
        for (int j = 0; j <= sz; j++) {
            for (int k = 0; k <= q->data[next]; k++) {
                // Maximization logic here
            }
        }
        sz += q->data[next];
    }

    if (vert == 0) {
        for (int i = 0; i < n; i++) {
            cur.data[i + 1] = cur.data[i] + (cur.data[i] > 0 ? 1 : 0);
        }
        return;
    }

    for (int i = sz; i >= 0; i--) {
        // Maximization logic here
    }
}

void solve(int n, int m, arr b, arr w, arr x, arr y) {
    Graph graph = createGraph(n);
    for (int i = 0; i < n - 1; i++) {
        BiEdge *edge = (BiEdge *)malloc(sizeof(BiEdge));
        edge->from = x.data[i];
        edge->to = y.data[i];
        addEdge(&graph, edge);
    }

    arr q = createArr(n);
    calcQ(&graph, &q, 0, -1);

    arr answer = createArr(3002);
    go(&graph, &q, &answer, 0, -1);
    printf("%d\n", answer.data[m].first);

    freeArr(&q);
    freeArr(&answer);
    freeGraph(&graph);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d %d", &n, &m);
        arr b = createArr(n);
        arr w = createArr(n);
        arr x = createArr(n - 1);
        arr y = createArr(n - 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &b.data[j]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &w.data[j]);
        }
        for (int j = 0; j < n - 1; j++) {
            scanf("%d %d", &x.data[j], &y.data[j]);
        }
        decreaseByOne(&x, n - 1);
        decreaseByOne(&y, n - 1);
        solve(n, m, b, w, x, y);
        freeArr(&b);
        freeArr(&w);
        freeArr(&x);
        freeArr(&y);
    }
    return 0;
}
