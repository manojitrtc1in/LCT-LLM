#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005
#define INF 1e18

typedef long long LL;

typedef struct {
    int to, rev, cap;
} Edge;

typedef struct {
    LL dist[77][77];
} Matrix;

int x, k, n, q;
int tl;
int id[256];
Matrix T1;
int cc = 0;
LL c[MAXN];
LL dp[77], dp2[77];

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void _init() {
    int i, j, v, u;
    for (i = 0; i < (1 << k); i++) {
        int cnt = 0;
        for (j = 0; j < k; ++j) {
            if (i >> j & 1) cnt++;
        }
        if (cnt != x) continue;

        id[i] = ++cc;
    }
    for (i = 0; i < (1 << k); i++) {
        int cnt = 0;
        for (j = 0; j < k; ++j) {
            if (i >> j & 1) cnt++;
        }
        if (cnt != x) continue;

        v = i >> 1;
        u = i & 1;
        if (!u) {
            T1.dist[id[i]][id[v]] = 0;
        } else {
            for (j = 0; j < k; j++) {
                if (v & (1 << j)) continue;
                T1.dist[id[i]][id[v ^ (1 << j)]] = c[j + 1];
            }
        }
    }
}

void bfs(int s, int dist[], Edge G[MAXN], int n) {
    int i, x;
    for (i = 0; i < n; i++) dist[i] = -1;
    dist[s] = 0;
    int queue[MAXN];
    int front = 0, rear = 0;
    queue[rear++] = s;
    while (front < rear) {
        x = queue[front++];
        for (i = 0; i < n; i++) {
            Edge e = G[x * n + i];
            if (e.cap && dist[e.to] == -1) {
                dist[e.to] = dist[x] + 1;
                queue[rear++] = e.to;
            }
        }
    }
}

int dfs(int now, int dest, int fl, int dist[], Edge G[MAXN], int seen[MAXN], int n) {
    int i, f;
    if (now == dest) return fl;
    for (i = seen[now]; i < n; i++) {
        Edge *ed = &G[now * n + i];
        if (ed->cap && dist[ed->to] == dist[now] + 1) {
            f = dfs(ed->to, dest, fl < ed->cap ? fl : ed->cap, dist, G, seen, n);
            if (f) {
                ed->cap -= f;
                G[ed->to * n + ed->rev].cap += f;
                return f;
            }
        }
    }
    return 0;
}

int dinic(int s, int t, Edge G[MAXN], int n) {
    int ret = 0;
    int dist[MAXN], seen[MAXN];
    while (1) {
        memset(seen, 0, sizeof(seen));
        bfs(s, dist, G, n);
        if (dist[t] == -1) return ret;
        int f = dfs(s, t, INF, dist, G, seen, n);
        while (f) {
            ret += f;
            f = dfs(s, t, INF, dist, G, seen, n);
        }
    }
}

Matrix mul(Matrix x, Matrix y) {
    Matrix ret;
    int i, j, k;
    for (i = 1; i <= cc; i++) {
        for (j = 1; j <= cc; j++) {
            for (k = 1; k <= cc; k++) {
                if (ret.dist[i][j] > x.dist[i][k] + y.dist[k][j]) {
                    ret.dist[i][j] = x.dist[i][k] + y.dist[k][j];
                }
            }
        }
    }
    return ret;
}

Matrix mqp(Matrix x, LL p) {
    Matrix R;
    int i;
    for (i = 1; i <= cc; i++) R.dist[i][i] = 0;
    while (p) {
        if (p & 1) R = mul(R, x);
        x = mul(x, x);
        p >>= 1;
    }
    return R;
}

int normal(int pos, int p[], int q) {
    int i;
    for (i = 1; i <= q; i++) {
        if (p[i] <= pos && pos - p[i] < k) return 0;
    }
    return 1;
}

int main() {
    x = read();
    k = read();
    n = read();
    q = read();
    n += k - x;
    int i, j;
    for (i = 1; i <= k; i++) {
        c[i] = read();
    }
    _init();

    int p[MAXN], wp[MAXN];
    for (i = 1; i <= q; i++) {
        p[i] = read();
        wp[i] = read();
    }
    for (i = 1; i <= cc; i++) dp[i] = 1e18;
    dp[id[(1 << x) - 1]] = 0;
    int now = k;
    while (now < n) {
        if (!normal(now + 1, p, q)) {
            Matrix Tra = Build(now + 1);
            Mul(Tra);
            now++;
            continue;
        }
        int Nxt = n + 1;
        for (i = 1; i <= q; i++) {
            if (p[i] > now) {
                if (Nxt > p[i]) Nxt = p[i];
            }
        }
        int di = Nxt - now - 1;
        Matrix Tra = mqp(T1, di);
        Mul(Tra);
        now = Nxt - 1;
    }
    printf("%lld\n", dp[id[(1 << x) - 1]]);
    return 0;
}
