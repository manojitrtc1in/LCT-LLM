#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

#define MAXN 1000010
#define F 5001
#define INF 1011111111

typedef long long ll;
typedef struct {
    int a, b, c;
} triple;

int vec[1010101][F];
int vid[1010101];
int pr[1010101];
int primes[100000];
int prime_count = 0;
ll maxh;
int dist[301][F * 2];
bool vis[F * 2];
int dc[F * 2];
int g[F * 2][F];
int g_size[F * 2];
triple w[1000000];
int w_size = 0;
int ans[303][303];

ll calc(int *v, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 30 + v[i];
    }
    return res;
}

int calcd(int *v, int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}

void addUsed(int *v, int *t, int size) {
    ll x = calc(t, size);
    if (vid[x] == 0) {
        int sz = w_size;
        vid[x] = sz + 1;
        assert(w_size == sz);
        for (int i = 0; i < size; i++) {
            w[sz].a = t[i];
        }
        dc[sz] = calcd(t, size);
        w_size++;
    }
    v[g_size[v]] = vid[x];
    g_size[v]++;
}

int solve() {
    w[0].a = 0;
    vid[0] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[prime_count++] = i;
        }
        for (int j = 0; j < prime_count; j++) {
            if (primes[j] * i > MAXN || primes[j] > pr[i]) {
                break;
            }
            pr[primes[j] * i] = primes[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        memcpy(vec[i], vec[x], sizeof(vec[x]));
        vec[i][g_size[i]] = cnt;
        g_size[i]++;
        ll h = calc(vec[i], g_size[i]);
        maxh = fmax(maxh, h);
        int id = vid[h];
        if (!id) {
            id = w_size + 1;
            w[w_size++] = vec[i];
        }
        vid[i] = id;
    }

    int ws = w_size;
    for (int i = 0; i < ws; i++) {
        for (int j = 0; j < g_size[i]; j++) {
            int t[F];
            memcpy(t, g[i], sizeof(g[i]));
            t[j]--;
            addUsed(g[i], t, g_size[i]);
            t[j] += 2;
            addUsed(g[i], t, g_size[i]);
        }
        g[i][g_size[i]] = 1;
        addUsed(g[i], g[i], g_size[i] + 1);
        sort(g[i], g_size[i]);
        reunique(g[i], &g_size[i]);
        dc[i] = calcd(w[i], g_size[i]);
    }

    memset(dist, INF, sizeof(dist));
    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[F];
        int q_size = 0;
        q[q_size++] = i;
        int dp[F * 2];
        for (int j = 0; j < ws; j++) {
            dp[j] = INF;
        }
        dp[i] = 0;
        for (int j = 0; j < q_size; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 0; k < g_size[cur]; k++) {
                int to = g[cur][k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[q_size++] = to;
                }
            }
        }
        for (int j = 0; j < ws; j++) {
            if (dc[j] < F) {
                dist[i][dc[j]] = fmin(dist[i][dc[j]], dp[j]);
            }
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
