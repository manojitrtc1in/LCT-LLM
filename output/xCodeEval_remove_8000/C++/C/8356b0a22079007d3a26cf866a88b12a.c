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

int src = 1002, snk = 1003;
Edge G[MAXN][MAXN];
int dist[MAXN], seen[MAXN];
int n, x, k, q, tl;
Matrix T1;
int cc = 0;
LL c[MAXN];

void Clear() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            G[i][j].to = 0;
            G[i][j].rev = 0;
            G[i][j].cap = 0;
        }
    }
}

void bfs(int s) {
    for (int i = 0; i < MAXN; i++) {
        dist[i] = -1;
    }
    dist[s] = 0;
    int queue[MAXN];
    int front = 0, rear = 0;
    queue[rear++] = s;
    while (front < rear) {
        int x = queue[front++];
        for (int i = 0; i < MAXN; i++) {
            Edge e = G[x][i];
            if (e.cap && dist[e.to] == -1) {
                dist[e.to] = dist[x] + 1;
                queue[rear++] = e.to;
            }
        }
    }
}

int dfs(int now, int dest, int fl) {
    if (now == dest) return fl;
    for (int i = seen[now]; i < MAXN; i++) {
        Edge *ed = &G[now][i];
        if (ed->cap && dist[ed->to] == dist[now] + 1) {
            int f = dfs(ed->to, dest, min(fl, ed->cap));
            if (f) {
                ed->cap -= f;
                G[ed->to][ed->rev].cap += f;
                return f;
            }
        }
    }
    return 0;
}

int dinic(int s, int t) {
    int ret = 0;
    while (1) {
        memset(seen, 0, sizeof(seen));
        bfs(s);
        if (dist[t] == -1) return ret;
        int f = dfs(s, t, INF);
        while (f) {
            ret += f;
            f = dfs(s, t, INF);
        }
    }
}

void _init() {
    for (int i = 0; i < (1 << k); i++) {
        int cnt = 0;
        for (int j = 0; j < k; ++j) {
            if (i >> j & 1) cnt++;
        }
        if (cnt != x) continue;

        id[i] = ++cc;
    }
    for (int i = 0; i < (1 << k); i++) {
        int cnt = 0;
        for (int j = 0; j < k; ++j) {
            if (i >> j & 1) cnt++;
        }
        if (cnt != x) continue;

        int v = i >> 1;
        int u = i & 1;
        if (!u) {
            T1.dist[id[i]][id[v]] = 0;
        } else {
            for (int j = 0; j < k; j++) {
                if (v & (1 << j)) continue;
                T1.dist[id[i]][id[v ^ (1 << j)]] = c[j + 1];
            }
        }
    }
}

int p[MAXN], wp[MAXN];
LL dp[MAXN], dp2[MAXN];

Matrix Build(int pos) {
    Matrix ret = T1;
    for (int i = 0; i < (1 << k); i++) {
        if (!id[i]) continue;
        for (int j = 1; j <= q; j++) {
            if (p[j] <= pos && pos - p[j] < k) {
                int pp = pos - p[j];
                pp = k - 1 - pp;
                if (i >> (pp + 1) & 1) continue;

                for (int l = 0; l < (1 << k); l++) {
                    if (!id[l]) continue;
                    if (l >> pp & 1) {
                        if (ret.dist[id[i]][id[l]] != INF) ret.dist[id[i]][id[l]] += wp[j];
                    }
                }
            }
        }
    }
    return ret;
}

Matrix mul(Matrix x, Matrix y) {
    Matrix ret;
    for (int i = 1; i <= cc; i++) {
        for (int j = 1; j <= cc; j++) {
            for (int k = 1; k <= cc; k++) {
                ret.dist[i][j] = min(ret.dist[i][j], x.dist[i][k] + y.dist[k][j]);
            }
        }
    }
    return ret;
}

void Mul(Matrix X) {
    for (int i = 1; i <= cc; i++) {
        dp2[i] = INF;
    }
    for (int i = 1; i <= cc; i++) {
        for (int j = 1; j <= cc; j++) {
            dp2[j] = min(dp2[j], dp[i] + X.dist[i][j]);
        }
    }
    for (int i = 1; i <= cc; i++) dp[i] = dp2[i];
}

Matrix mqp(Matrix x, LL p) {
    Matrix R;
    for (int i = 1; i <= cc; i++) R.dist[i][i] = 0;
    while (p) {
        if (p & 1) R = mul(R, x);
        x = mul(x, x);
        p >>= 1;
    }
    return R;
}

int normal(int pos) {
    for (int i = 1; i <= q; i++) {
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
    for (int i = 1; i <= k; i++) {
        c[i] = read();
    }
    _init();

    for (int i = 1; i <= q; i++) {
        p[i] = read();
        wp[i] = read();
    }
    for (int i = 1; i <= cc; i++) dp[i] = INF;
    dp[id[(1 << x) - 1]] = 0;
    int now = k;
    while (now < n) {
        if (!normal(now + 1)) {
            Matrix Tra = Build(now + 1);
            Mul(Tra);
            now++;
            continue;
        }
        int Nxt = n + 1;
        for (int i = 1; i <= q; i++) {
            if (p[i] > now) {
                Nxt = min(Nxt, p[i]);
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
