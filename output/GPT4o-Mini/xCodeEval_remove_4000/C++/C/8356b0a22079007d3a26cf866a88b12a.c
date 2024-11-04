#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1005
#define INF 1e18
#define LL long long

inline int read() {
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

typedef struct {
    LL dist[77][77];
} mat;

typedef struct {
    int to, rev, cap;
} edge;

LL qp(LL x, LL p, LL mod) {
    LL ans = 1;
    while (p) {
        if (p & 1) ans = ans * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}

LL inv(LL x, LL mod) {
    return qp(x, mod - 2, mod);
}

void FWT(int a[], int n, LL mod) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y) % mod;
                a[i + j + d] = (x - y + mod) % mod;
            }
}

void UFWT(int a[], int n, LL mod) {
    LL rev = inv(2, mod);
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = (1LL * (x + y) * rev) % mod;
                a[i + j + d] = (1LL * (x - y) * rev % mod + mod) % mod;
            }
}

void solve(int a[], int b[], int n, LL mod) {
    FWT(a, n, mod);
    FWT(b, n, mod);
    for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % mod;
    UFWT(a, n, mod);
}

edge G[MAXN];
int dist[MAXN], seen[MAXN];
int src = 1002, snk = 1003;

void Clear() {
    for (int i = 0; i < MAXN; i++) {
        G[i].cap = 0;
    }
}

void bfs(int s) {
    for (int i = 0; i < MAXN; i++) dist[i] = -1;
    dist[s] = 0;
    int Q[MAXN], front = 0, rear = 0;
    Q[rear++] = s;
    while (front < rear) {
        int x = Q[front++];
        for (int i = 0; i < G[x].cap; i++) {
            edge e = G[x][i];
            if (e.cap && dist[e.to] == -1) {
                dist[e.to] = dist[x] + 1;
                Q[rear++] = e.to;
            }
        }
    }
}

int dfs(int now, int dest, int fl) {
    if (now == dest) return fl;
    for (int *i = &seen[now]; *i < G[now].cap; (*i)++) {
        edge ed = G[now][*i];
        if (ed.cap && dist[ed.to] == dist[now] + 1) {
            int f = dfs(ed.to, dest, fl < ed.cap ? fl : ed.cap);
            if (f) {
                ed.cap -= f;
                G[ed.to][ed.rev].cap += f;
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

LL c[9];
int id[256];
mat T1;
int cc = 0;

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

mat Build(int pos) {
    mat ret = T1;
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

mat mul(mat x, mat y) {
    mat ret;
    for (int i = 1; i <= cc; i++) {
        for (int j = 1; j <= cc; j++) {
            for (int k = 1; k <= cc; k++) {
                ret.dist[i][j] = ret.dist[i][j] < x.dist[i][k] + y.dist[k][j] ? ret.dist[i][j] : x.dist[i][k] + y.dist[k][j];
            }
        }
    }
    return ret;
}

LL dp[77], dp2[77];

void Mul(mat X) {
    for (int i = 1; i <= cc; i++) {
        dp2[i] = INF;
    }
    for (int i = 1; i <= cc; i++) {
        for (int j = 1; j <= cc; j++) {
            dp2[j] = dp2[j] < dp[i] + X.dist[i][j] ? dp2[j] : dp[i] + X.dist[i][j];
        }
    }
    for (int i = 1; i <= cc; i++) dp[i] = dp2[i];
}

mat mqp(mat x, LL p) {
    mat R;
    for (int i = 1; i <= cc; i++) R.dist[i][i] = 0;
    while (p) {
        if (p & 1) R = mul(R, x);
        x = mul(x, x);
        p >>= 1;
    }
    return R;
}

bool normal(int pos) {
    for (int i = 1; i <= q; i++) {
        if (p[i] <= pos && pos - p[i] < k) return false;
    }
    return true;
}

int main() {
    int x = read(), k = read(), n = read(), q = read();
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
            mat Tra = Build(now + 1);
            Mul(Tra);
            now++;
            continue;
        }
        int Nxt = n + 1;
        for (int i = 1; i <= q; i++) {
            if (p[i] > now) {
                Nxt = Nxt < p[i] ? Nxt : p[i];
            }
        }
        int di = Nxt - now - 1;
        mat Tra = mqp(T1, di);
        Mul(Tra);
        now = Nxt - 1;
    }
    printf("%lld\n", dp[id[(1 << x) - 1]]);
    return 0;
}
