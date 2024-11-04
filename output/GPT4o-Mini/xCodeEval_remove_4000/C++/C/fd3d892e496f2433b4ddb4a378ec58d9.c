#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000010
#define F 5001
#define INF 0x3f3f3f3f

typedef long long ll;
typedef struct {
    int a[303][303];
} ans_t;

int vec[1010101][F];
int vid[1010101];
int pr[1010101];
int primes[1000000];
int used[1000000];
ll maxh;
int dist[301][F * 2];
bool vis[F * 2];
int dc[F * 2];
int g[F * 2][F];
int w[1000000][F];
int ans[303][303];

ll calc(int* v, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 30 + v[i];
    }
    return res;
}

int calcd(int* v, int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}

void addUsed(int* v, int size, int* t, int t_size) {
    ll x = calc(t, t_size);
    if (!used[x]) {
        int sz = (int)used[0];
        used[x] = sz;
        memcpy(w[sz], t, sizeof(int) * t_size);
        dc[sz] = calcd(t, t_size);
    }
    v[size++] = used[x];
}

int solve() {
    memset(used, 0, sizeof(used));
    memset(pr, 0, sizeof(pr));
    memset(vec, 0, sizeof(vec));
    memset(dist, INF, sizeof(dist));
    memset(ans, INF, sizeof(ans));

    w[0][0] = 0;
    used[0] = 0;

    for (int i = 2; i < MAXN; ++i) {
        if (!pr[i]) {
            pr[i] = i;
            primes[primes[0]++] = i;
        }
        for (int j = 1; j < primes[0]; j++) {
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
        memcpy(vec[i] + 1, vec[x], sizeof(int) * (vec[x][0] + 1));
        vec[i][0]++;

        ll h = calc(vec[i], vec[i][0]);
        maxh = (maxh > h) ? maxh : h;
        int id = used[h];
        if (!id) {
            id = (int)w[0][0]++;
            memcpy(w[id], vec[i], sizeof(int) * (vec[i][0] + 1));
        }
        vid[i] = id;
    }

    int ws = (int)w[0][0];
    for (int i = 0; i < ws; ++i) {
        int* cur = w[i];
        for (int j = 0; j < cur[0]; ++j) {
            int t[F];
            memcpy(t, cur, sizeof(int) * (cur[0] + 1));
            t[j]--;
            addUsed(g[i], 0, t, cur[0]);
            t[j] += 2;
            addUsed(g[i], 0, t, cur[0]);
        }
        cur[cur[0]++] = 1;
        addUsed(g[i], 0, cur, cur[0]);
    }

    for (int i = 0; i < ws; ++i) {
        memset(vis, 0, sizeof(vis));
        int q[F];
        int front = 0, back = 0;
        q[back++] = i;
        int dp[F * 2];
        memset(dp, INF, sizeof(dp));
        dp[i] = 0;

        while (front < back) {
            int cur = q[front++];
            int dcur = dp[cur];
            for (int j = 0; j < g[cur][0]; j++) {
                int to = g[cur][j];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[back++] = to;
                }
            }
        }

        for (int j = 0; j < ws; j++) {
            if (dc[j] < F) {
                dist[i][dc[j]] = (dist[i][dc[j]] < dp[j]) ? dist[i][dc[j]] : dp[j];
            }
        }
    }

    for (int i = 0; i < ws; ++i) {
        dist[i][0] = INF;
        for (int j = 0; j <= i; ++j) {
            int res = INF;
            for (int k = 0; k < F; ++k) {
                res = (res < dist[i][k] + dist[j][k]) ? res : (dist[i][k] + dist[j][k]);
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
