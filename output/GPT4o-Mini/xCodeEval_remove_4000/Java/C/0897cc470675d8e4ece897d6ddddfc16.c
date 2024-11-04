#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 2000

typedef struct {
    int from, to;
    long weight, capacity;
} Edge;

typedef struct {
    int vertexCount;
    int edgeCount;
    int firstOutbound[MAX_VERTICES];
    Edge edges[MAX_EDGES];
} Graph;

typedef struct {
    long *phi;
    long *id4;
    int *lastEdge;
    int vertexCount;
    int source, destination;
} id6;

Graph* createGraph(int vertexCount) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertexCount = vertexCount;
    g->edgeCount = 0;
    memset(g->firstOutbound, -1, sizeof(g->firstOutbound));
    return g;
}

int addEdge(Graph *g, int fromID, int toID, long weight, long capacity) {
    Edge *e = &g->edges[g->edgeCount];
    e->from = fromID;
    e->to = toID;
    e->weight = weight;
    e->capacity = capacity;

    e->nextOutbound = g->firstOutbound[fromID];
    g->firstOutbound[fromID] = g->edgeCount++;
    return g->edgeCount - 1;
}

void solve(int n, char *s, int *a) {
    int cnt[26] = {0};
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
    }
    
    Graph *g = createGraph(n + 100);
    int source = n + 100 - 2, target = source + 1;

    for (int i = 0; i * 2 < n; ++i) {
        addEdge(g, i, target, 0, 2);
    }

    for (int i = 0; i < 26; ++i) {
        addEdge(g, source, i + n, 0, cnt[i]);
        for (int j = 0; j * 2 < n; ++j) {
            int w = 0;
            if (s[j] == s[n - j - 1]) {
                if (s[j] == i + 'a') w = -max(a[j], a[n - j - 1]);
                addEdge(g, i + n, j, w, 1);
            } else {
                if (s[j] == i + 'a') w -= a[j];
                if (s[n - j - 1] == i + 'a') w -= a[n - j - 1];
                addEdge(g, i + n, j, w, 1);
            }
        }
    }

    // Implement id6 and flow calculation here...

    free(g);
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    solve(n, s, a);
    return 0;
}
