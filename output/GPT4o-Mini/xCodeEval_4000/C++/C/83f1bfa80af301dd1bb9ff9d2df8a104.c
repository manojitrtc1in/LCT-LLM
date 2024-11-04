#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MAX_N 1000010
#define F 3001
#define INF 1011111111

typedef long long ll;
typedef struct {
    int a, b, c;
} triple;

int vec[MAX_N][F];
int vid[MAX_N];
int pr[MAX_N];
int primes[MAX_N];
ll maxh;
int dist[F * 2][F * 2];
bool vis[F * 2];
int dc[F * 2];
int g[F * 2][F];
int g_size[F * 2];
triple w[MAX_N];
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
        int sz = w_size++;
        vid[x] = sz;
        w[sz] = (triple){.a = t[0], .b = t[1], .c = t[2]};
        dc[sz] = calcd(t, size);
    }
    v[0] = vid[x];
}

int solve() {
    w[0] = (triple){0, 0, 0};
    vid[0] = 0;

    for (int i = 2; i < MAX_N; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[i] = i;
        }
        for (int p = 2; p * i < MAX_N; p++) {
            if (p > pr[i]) {
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
        memcpy(vec[i], vec[x], sizeof(vec[x]));
        vec[i][cnt] = cnt;

        ll h = calc(vec[i], cnt + 1);
        maxh = fmax(maxh, h);
        int id = vid[h];
        if (!id) {
            id = w_size++;
            w[id] = (triple){.a = vec[i][0], .b = vec[i][1], .c = vec[i][2]};
        }
        vid[i] = id;
    }

    int ws = w_size;
    for (int i = 0; i < ws; i++) {
        for (int j = 0; j < g_size[i]; j++) {
            int t[3];
            memcpy(t, g[i], sizeof(g[i]));
            t[j]--;
            addUsed(g[i], t, 3);
            t[j] += 2;
            addUsed(g[i], t, 3);
        }
        memcpy(g[i], w[i], sizeof(w[i]));
        g[i][3] = 1;
        addUsed(g[i], g[i], 4);
        qsort(g[i], g_size[i], sizeof(int), cmp);
    }

    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[F * 2];
        q[0] = i;
        int dp[F * 2];
        for (int j = 0; j < ws; j++) {
            dp[j] = INF;
        }
        dp[i] = 0;
        for (int j = 0; j < F * 2; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 0; k < g_size[cur]; k++) {
                int to = g[cur][k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[++j] = to;
                }
            }
        }
        for (int j = 0; j < ws; j++) {
            if (dc[j] < F) {
                dist[i][dc[j]] = fmin(dist[i][dc[j]], dp[j]);
            }
        }
    }

    for (int i = 0; i < ws; i++) {
        for (int j = 0; j <= i; j++) {
            int res = INF;
            for (int k = 0; k < F; k++) {
                res = fmin(res, dist[i][k] + dist[j][k]);
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
