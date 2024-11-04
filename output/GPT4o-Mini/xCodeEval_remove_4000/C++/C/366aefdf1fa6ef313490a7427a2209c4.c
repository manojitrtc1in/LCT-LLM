#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000010
#define F 30001
#define INF 0x3f3f3f3f

typedef long long ll;
typedef struct {
    int a[300];
    int size;
} Vector;

Vector vec[MAXN];
int vid[MAXN];
int pr[MAXN];
Vector primes;
ll maxh;
int dist[301][F];
bool vis[F];
int dc[F];
Vector g[F];
Vector w;
int ans[300][300];

ll calc(Vector* v) {
    ll res = 0;
    for (int i = 0; i < v->size; i++) {
        res = res * 30 + v->a[i];
    }
    return res;
}

int calcd(Vector* v) {
    int res = 1;
    for (int i = 0; i < v->size; i++) {
        res *= v->a[i] + 1;
    }
    return res;
}

void addUsed(Vector* v, Vector* t) {
    ll x = calc(t);
    if (!used[x]) {
        int sz = (int)used.size();
        used[x] = sz;
        w.size++;
        w.a[sz] = *t;
        dc[sz] = calcd(t);
    }
    v->a[v->size++] = used[x];
}

int solve() {
    w.size = 0;
    used[0] = 0;
    for (int i = 2; i < MAXN; ++i) {
        if (!pr[i]) {
            pr[i] = i;
            primes.a[primes.size++] = i;
        }
        for (int j = 0; j < primes.size; j++) {
            int p = primes.a[j];
            if (p * i > MAXN || p > pr[i]) {
                break;
            }
            pr[p * i] = p;
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        vec[i].size = vec[x].size + 1;
        for (int t = 0; t < vec[x].size; t++) {
            vec[i].a[t] = vec[x].a[t];
        }
        vec[i].a[vec[i].size - 1] = cnt;
        ll h = calc(&vec[i]);
        maxh = max(maxh, h);
        int* id = &used[h];
        if (!*id) {
            *id = (int)w.size;
            w.a[w.size++] = vec[i];
        }
        vid[i] = *id;
    }

    int ws = (int)w.size;
    for (int i = 0; i < ws && i < 20000; ++i) {
        Vector cur = w.a[i];
        for (int j = 0; j < cur.size; ++j) {
            Vector t = cur;
            t.a[j]--;
            addUsed(&g[i], &t);
            t.a[j] += 2;
            addUsed(&g[i], &t);
        }
        cur.a[cur.size++] = 1;
        addUsed(&g[i], &cur);
        sort(g[i]);
        reunique(g[i]);
        dc[i] = calcd(&w.a[i]);
    }

    for (int i = 0; i < ws; ++i) {
        memset(vis, 0, sizeof(vis));
        Vector q;
        q.size = 0;
        q.a[q.size++] = i;
        int dp[F];
        for (int j = 0; j < used.size; j++) {
            dp[j] = INF;
        }
        dp[i] = 0;
        for (int j = 0; j < q.size; j++) {
            int cur = q.a[j];
            int dcur = dp[cur];
            for (int k = 0; k < g[cur].size; k++) {
                int to = g[cur].a[k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q.a[q.size++] = to;
                }
            }
        }
        for (int j = 0; j < used.size; j++) {
            if (dc[j] < F) {
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j]);
            }
        }
    }

    for (int i = 0; i < ws; ++i) {
        dist[i][0] = INF;
        for (int j = 0; j <= i; ++j) {
            int res = INF;
            for (int k = 0; k < F; ++k) {
                res = min(res, dist[i][k] + dist[j][k]);
            }
            ans[i][j] = res;
        }
    }
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        a = vid[a];
        b = vid[b];
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        printf("%d\n", ans[a][b]);
    }
    return 0;
}

int main() {
    solve();
    return 0;
}
