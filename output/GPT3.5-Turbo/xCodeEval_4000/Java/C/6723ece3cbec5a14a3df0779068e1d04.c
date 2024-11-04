#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    int node;
    long cost;
    long next;
} Edge;

int adj[MAXN];
int head[MAXN];
int dist[MAXN];
int mulpath[MAXN];
int memo[MAXN][MAXN];
int notmemo[MAXN][MAXN];
char c[MAXN];

int n, m, k;

void bfs(int s) {
    for (int i = 0; i < n; i++) {
        dist[i] = 1e9;
    }
    dist[s] = 0;
    Queue q;
    initQueue(&q);
    enqueue(&q, s);
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        for (int v = head[u]; v != -1; v = adj[v]) {
            if (dist[v] == 1e9) {
                dist[v] = dist[u] + 1;
                enqueue(&q, v);
            } else if (dist[v] == dist[u] + 1) {
                mulpath[v] = 1;
            }
        }
    }
}

int dp(int i, int count) {
    if (count > k) {
        return 1e9;
    }
    if (i >= n) {
        return 0;
    }
    if (memo[i][count] != -1) {
        return memo[i][count];
    }
    int ans = 1e9;
    for (int j = i; j < n; j++) {
        ans = min(ans, dp(j + 1, count + 1) + changes(i, j));
    }
    return memo[i][count] = ans;
}

int changes(int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (notmemo[i][j] != -1) {
        return notmemo[i][j];
    }
    if (c[i] != c[j]) {
        notmemo[i][j] = 1 + changes(i + 1, j - 1);
    } else {
        notmemo[i][j] = changes(i + 1, j - 1);
    }
    return notmemo[i][j];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        head[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        adj[i] = head[v];
        head[v] = i;
    }
    scanf("%d", &k);
    int p[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    bfs(p[k - 1]);
    int min = 0;
    int max = 0;
    for (int i = 0; i < k - 1; i++) {
        if (dist[p[i + 1]] + 1 == dist[p[i]]) {
            if (mulpath[p[i]]) {
                max++;
            }
        } else {
            min++;
            max++;
        }
    }
    printf("%d %d\n", min, max);
    return 0;
}
