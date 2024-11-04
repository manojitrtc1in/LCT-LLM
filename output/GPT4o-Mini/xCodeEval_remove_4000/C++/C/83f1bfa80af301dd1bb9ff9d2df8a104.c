#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000010
#define F 3001
#define INF 0x3f3f3f3f

typedef long long ll;
typedef struct {
    int a[303][303];
} ans_t;

int vec[1010101][10];
int vid[1010101];
int pr[1010101];
int primes[1000000];
int primes_count = 0;
ll maxh;
int dist[301][F * 2];
bool vis[F * 2];
int dc[F * 2];
int g[F * 2][100];
int g_size[F * 2];
ans_t ans;

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

int used[10000000];
int w[10000000][10];
int w_size = 0;

void addUsed(int *v, int size, int *t, int t_size) {
    ll x = calc(t, t_size);
    if (!used[x]) {
        int sz = w_size;
        used[x] = sz;
        memcpy(w[sz], t, t_size * sizeof(int));
        g[sz][0] = calcd(t, t_size);
        g_size[sz] = 1;
        w_size++;
    }
    v[0] = used[x];
}

int solve() {
    w[0][0] = 0;
    used[0] = 0;

    for (int i = 2; i < MAXN; ++i) {
        if (!pr[i]) {
            pr[i] = i;
            primes[primes_count++] = i;
        }
        for (int j = 0; j < primes_count; j++) {
            int p = primes[j];
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
        vec[i][0] = cnt;
        int size = 1;
        for (int t = 0; t < size; t++) {
            vec[i][t + 1] = vec[x][t];
        }
        auto h = calc(vec[i], size + 1);
        maxh = max(maxh, h);
        int id = used[h];
        if (!id) {
            id = w_size;
            memcpy(w[w_size++], vec[i], (size + 1) * sizeof(int));
        }
        vid[i] = id;
    }

    int ws = w_size;
    for (int i = 0; i < ws; ++i) {
        int cur[10];
        memcpy(cur, w[i], sizeof(cur));
        for (int j = 0; j < cur[0]; ++j) {
            int t[10];
            memcpy(t, cur, sizeof(t));
            t[j]--;
            addUsed(g[i], g_size[i], t, cur[0]);
            t[j] += 2;
            addUsed(g[i], g_size[i], t, cur[0]);
        }
        cur[cur[0] + 1] = 1;
        addUsed(g[i], g_size[i], cur, cur[0] + 1);
        g_size[i]++;
        dc[i] = calcd(w[i], cur[0]);
    }

    for (int i = 0; i < ws; ++i) {
        dist[i][0] = INF;
        for (int j = 0; j < ws; ++j) {
            int res = INF;
            for (int k = 0; k < F; ++k) {
                res = min(res, dist[i][k] + dist[j][k]);
            }
            ans.a[i][j] = res;
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
        printf("%d\n", ans.a[a][b]);
    }
    return 0;
}

int main() {
    memset(pr, 0, sizeof(pr));
    memset(used, 0, sizeof(used));
    memset(g_size, 0, sizeof(g_size));
    memset(dist, 0, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    memset(dc, 0, sizeof(dc));
    solve();
    return 0;
}
