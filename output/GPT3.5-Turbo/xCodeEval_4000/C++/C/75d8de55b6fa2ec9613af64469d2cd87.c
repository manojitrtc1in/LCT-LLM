#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3000

typedef struct {
    int first;
    long long second;
} Pair;

Pair answer[MAX_N][3002];

typedef struct {
    int from;
    int to;
} Edge;

typedef struct {
    int vertexCount;
    int edgeCount;
    Edge** edges;
} Graph;

Graph* createGraph(int vertexCount) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    graph->edges = (Edge**)malloc(vertexCount * sizeof(Edge*));
    for (int i = 0; i < vertexCount; i++) {
        graph->edges[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, Edge* edge) {
    int from = edge->from;
    int to = edge->to;
    graph->edgeCount++;
    graph->edges[from] = (Edge*)realloc(graph->edges[from], graph->edgeCount * sizeof(Edge));
    graph->edges[from][graph->edgeCount - 1] = *edge;
    graph->edges[to] = (Edge*)realloc(graph->edges[to], graph->edgeCount * sizeof(Edge));
    Edge reverseEdge = {to, from};
    graph->edges[to][graph->edgeCount - 1] = reverseEdge;
}

Pair makePair(int first, long long second) {
    Pair pair;
    pair.first = first;
    pair.second = second;
    return pair;
}

void maxim(Pair* a, Pair b) {
    if (b.first > a->first || (b.first == a->first && b.second > a->second)) {
        *a = b;
    }
}

void calcQ(int vert, int last, int* q, Graph* graph) {
    int res = 1;
    for (int i = 0; i < graph->edgeCount; i++) {
        Edge* edge = &graph->edges[vert][i];
        int next = edge->to;
        if (next == last) {
            continue;
        }
        calcQ(next, vert, q, graph);
        res += q[next];
    }
    q[vert] = res;
}

void go(int vert, int last, int n, int m, int* b, int* w, int* x, int* y, int* q, Graph* graph) {
    int id = -1;
    for (int i = 0; i < graph->edgeCount; i++) {
        Edge* edge = &graph->edges[vert][i];
        int next = edge->to;
        if (next == last) {
            continue;
        }
        go(next, vert, n, m, b, w, x, y, q, graph);
        if (id == -1 || q[next] > q[id]) {
            id = next;
        }
    }
    Pair* cur = answer[vert];
    long long delta = w[vert] - b[vert];
    if (id == -1) {
        cur[0] = makePair(0, delta);
        cur[1] = makePair(delta > 0 ? 1 : 0, 0);
        return;
    }
    Pair* aid = answer[id];
    for (int i = 0; i <= q[id]; i++) {
        cur[i] = aid[i];
        cur[i].second += delta;
    }
    int sz = q[id];
    for (int i = sz + 1; i <= q[vert]; i++) {
        cur[i].first = -1;
        cur[i].second = 0;
    }
    for (int i = 0; i < graph->edgeCount; i++) {
        Edge* edge = &graph->edges[vert][i];
        int next = edge->to;
        if (next == last || next == id) {
            continue;
        }
        Pair* anext = answer[next];
        for (int i = 0; i <= sz; i++) {
            Pair temp = cur[i];
            cur[i].first = -1;
            cur[i].second = 0;
            for (int j = 0; j <= q[next]; j++) {
                Pair temp2 = anext[j];
                maxim(&cur[i + j], makePair(temp.first + temp2.first, temp.second + temp2.second));
            }
        }
        int nsz = sz + q[next];
        for (int i = sz + 1; i <= nsz; i++) {
            cur[i].first = -1;
            cur[i].second = 0;
        }
        for (int i = 0; i <= sz; i++) {
            for (int j = 0; j <= q[next]; j++) {
                Pair temp = cur[i];
                Pair temp2 = anext[j];
                maxim(&cur[i + j], makePair(temp.first + temp2.first, temp.second + temp2.second));
            }
        }
        sz = nsz;
    }
    if (vert == 0) {
        for (int i = n - 1; i >= 0; i--) {
            cur[i + 1] = makePair(cur[i].first + (cur[i].second > 0 ? 1 : 0), 0);
        }
        return;
    }
    for (int i = sz; i >= 0; i--) {
        cur[i + 1].first = -1;
        cur[i + 1].second = 0;
        maxim(&cur[i + 1], makePair(cur[i].first + (cur[i].second > 0 ? 1 : 0), 0));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int vertexCount, edgeCount;
        scanf("%d %d", &vertexCount, &edgeCount);
        Graph* graph = createGraph(vertexCount);
        int* b = (int*)malloc(vertexCount * sizeof(int));
        int* w = (int*)malloc(vertexCount * sizeof(int));
        int* x = (int*)malloc((vertexCount - 1) * sizeof(int));
        int* y = (int*)malloc((vertexCount - 1) * sizeof(int));
        int* q = (int*)malloc(vertexCount * sizeof(int));
        for (int j = 0; j < vertexCount; j++) {
            scanf("%d", &b[j]);
        }
        for (int j = 0; j < vertexCount; j++) {
            scanf("%d", &w[j]);
        }
        for (int j = 0; j < vertexCount - 1; j++) {
            scanf("%d %d", &x[j], &y[j]);
        }
        for (int j = 0; j < vertexCount - 1; j++) {
            x[j]--;
            y[j]--;
            Edge edge = {x[j], y[j]};
            addEdge(graph, &edge);
        }
        calcQ(0, -1, q, graph);
        go(0, -1, vertexCount, edgeCount, b, w, x, y, q, graph);
        printf("%d\n", answer[0][edgeCount].first);
        free(b);
        free(w);
        free(x);
        free(y);
        free(q);
        for (int j = 0; j < vertexCount; j++) {
            free(graph->edges[j]);
        }
        free(graph->edges);
        free(graph);
    }
    return 0;
}
