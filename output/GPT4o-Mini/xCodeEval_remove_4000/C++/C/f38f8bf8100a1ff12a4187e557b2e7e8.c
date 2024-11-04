#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int dr[4] = { 0, 0, -1, 1 }, dc[4] = { -1, 1, 0, 0 };

typedef struct {
    int N;
    struct {
        int v;
        int w;
    } **E;
} Dijkstra;

Dijkstra* createDijkstra(int n) {
    Dijkstra* dk = (Dijkstra*)malloc(sizeof(Dijkstra));
    dk->N = n;
    dk->E = (struct { int v; int w; }**)malloc((n + 1) * sizeof(struct { int v; int w; }));
    for (int i = 0; i <= n; i++) {
        dk->E[i] = (struct { int v; int w; }*)malloc(n * sizeof(struct { int v; int w; }));
    }
    return dk;
}

void insertDijkstra(Dijkstra* dk, int u, int v, int w) {
    dk->E[u][dk->E[u][0].v++] = (struct { int v; int w; }){v, w};
}

int* dijkstra(Dijkstra* dk, int start, int end) {
    int* dist = (int*)malloc((dk->N + 1) * sizeof(int));
    for (int i = 0; i <= dk->N; i++) dist[i] = INF;
    dist[start] = 0;

    int* pq = (int*)malloc((dk->N + 1) * sizeof(int));
    int pqSize = 0;
    pq[pqSize++] = start;

    while (pqSize > 0) {
        int u = pq[--pqSize];
        if (u == end) return dist;

        for (int i = 0; i < dk->E[u][0].v; i++) {
            int v = dk->E[u][i].v;
            int w2 = dist[u] + dk->E[u][i].w;
            if (dist[v] > w2) {
                dist[v] = w2;
                pq[pqSize++] = v;
            }
        }
    }
    return dist;
}

void freeDijkstra(Dijkstra* dk) {
    for (int i = 0; i <= dk->N; i++) {
        free(dk->E[i]);
    }
    free(dk->E);
    free(dk);
}

int main() {
    int n, e, s, u, v, w;
    scanf("%d%d", &n, &e);
    Dijkstra* dk = createDijkstra(n);
    scanf("%d", &s);
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &u, &v, &w);
        insertDijkstra(dk, u, v, w);
    }
    int* ans = dijkstra(dk, s, n);
    for (int i = 1; i <= n; i++) {
        if (ans[i] >= INF) printf("INF\n");
        else printf("%d\n", ans[i]);
    }
    free(ans);
    freeDijkstra(dk);
    return 0;
}
