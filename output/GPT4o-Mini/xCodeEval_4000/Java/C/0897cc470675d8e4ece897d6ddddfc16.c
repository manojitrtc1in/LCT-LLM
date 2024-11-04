#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 2000
#define ALPHABET_SIZE 26

typedef struct {
    int from, to;
    long weight, capacity;
} Edge;

typedef struct {
    int vertexCount;
    int edgeCount;
    int firstOutbound[MAX_VERTICES];
    int nextOutbound[MAX_EDGES];
    Edge edges[MAX_EDGES];
    long capacity[MAX_EDGES];
    long weight[MAX_EDGES];
} Graph;

typedef struct {
    long first;
    long second;
} Pair;

typedef struct {
    int size;
    int elements[MAX_VERTICES];
    int at[MAX_VERTICES];
} Heap;

Graph* createGraph(int vertexCount) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertexCount = vertexCount;
    g->edgeCount = 0;
    memset(g->firstOutbound, -1, sizeof(g->firstOutbound));
    return g;
}

void addEdge(Graph* g, int from, int to, long weight, long capacity) {
    Edge* e = &g->edges[g->edgeCount];
    e->from = from;
    e->to = to;
    e->weight = weight;
    e->capacity = capacity;
    g->nextOutbound[g->edgeCount] = g->firstOutbound[from];
    g->firstOutbound[from] = g->edgeCount++;
}

void addFlowWeightedEdge(Graph* g, int from, int to, long weight, long capacity) {
    addEdge(g, from, to, weight, capacity);
    addEdge(g, to, from, -weight, 0);
}

void dijkstra(Graph* g, int source, long* dist, int* lastEdge) {
    int visited[MAX_VERTICES] = {0};
    for (int i = 0; i < g->vertexCount; i++) {
        dist[i] = LONG_MAX;
        lastEdge[i] = -1;
    }
    dist[source] = 0;

    for (int i = 0; i < g->vertexCount - 1; i++) {
        int u = -1;
        for (int j = 0; j < g->vertexCount; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = 1;

        for (int edgeID = g->firstOutbound[u]; edgeID != -1; edgeID = g->nextOutbound[edgeID]) {
            Edge* e = &g->edges[edgeID];
            if (e->capacity > 0 && dist[u] + e->weight < dist[e->to]) {
                dist[e->to] = dist[u] + e->weight;
                lastEdge[e->to] = edgeID;
            }
        }
    }
}

Pair minCostMaxFlow(Graph* g, int source, int target) {
    long totalCost = 0, totalFlow = 0;
    long dist[MAX_VERTICES];
    int lastEdge[MAX_VERTICES];

    while (1) {
        dijkstra(g, source, dist, lastEdge);
        if (lastEdge[target] == -1) break;

        long flow = LONG_MAX;
        for (int v = target; v != source; v = g->edges[lastEdge[v]].from) {
            flow = flow < g->edges[lastEdge[v]].capacity ? flow : g->edges[lastEdge[v]].capacity;
        }

        for (int v = target; v != source; v = g->edges[lastEdge[v]].from) {
            g->edges[lastEdge[v]].capacity -= flow;
            g->edges[lastEdge[v] ^ 1].capacity += flow;
        }

        totalCost += flow * dist[target];
        totalFlow += flow;
    }

    return (Pair){totalCost, totalFlow};
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    int a[n];
    int cnt[ALPHABET_SIZE] = {0};

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        cnt[s[i] - 'a']++;
    }

    Graph* g = createGraph(n + 100);
    int source = n + 98, target = n + 99;

    for (int i = 0; i * 2 < n; ++i) {
        addFlowWeightedEdge(g, i, target, 0, 2);
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        addFlowWeightedEdge(g, source, i + n, 0, cnt[i]);
        for (int j = 0; j * 2 < n; ++j) {
            int w = 0;
            if (s[j] == s[n - j - 1]) {
                if (s[j] == i + 'a') w = -((a[j] > a[n - j - 1]) ? a[j] : a[n - j - 1]);
                addFlowWeightedEdge(g, i + n, j, w, 1);
            } else {
                if (s[j] == i + 'a') w -= a[j];
                if (s[n - j - 1] == i + 'a') w -= a[n - j - 1];
                addFlowWeightedEdge(g, i + n, j, w, 1);
            }
        }
    }

    Pair result = minCostMaxFlow(g, source, target);
    printf("%ld\n", -result.first);

    free(g);
    return 0;
}
