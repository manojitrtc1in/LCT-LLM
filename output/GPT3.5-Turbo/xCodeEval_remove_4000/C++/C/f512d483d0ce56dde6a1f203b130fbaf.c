#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 1010101
#define MAXF 1001
#define INF 1e9

typedef long long ll;

int vec[MAXN][20];
int vid[MAXN];
int pr[MAXN];
int primes[MAXN];
int prSize = 0;
int maxh = 0;
int used[MAXN];
int wSize = 0;
int w[MAXN][20];
int dc[MAXN];
int g[MAXN][MAXF * 2];
int dist[MAXN][MAXF * 2];
bool vis[MAXF * 2];
int ans[MAXF * 2][MAXF * 2];

int calc(int v[], int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 30 + v[i];
    }
    return res;
}

int calcd(int v[], int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}

void addUsed(int v[], int vSize, int t[], int tSize) {
    int x = calc(t, tSize);
    if (used[x] == 0) {
        int sz = wSize;
        used[x] = sz;
        memcpy(w[sz], t, sizeof(int) * tSize);
        dc[sz] = calcd(t, tSize);
        wSize++;
    }
    v[vSize] = used[x];
}

void reunique(int v[], int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || v[i] != v[i - 1]) {
            v[j++] = v[i];
        }
    }
}

bool isPrime(int x) {
    if (x <= 4 || x % 2 == 0 || x % 3 == 0) {
        return x == 2 || x == 3;
    }
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    wSize = 1;
    used[0] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (pr[i] == 0) {
            pr[i] = i;
            primes[prSize++] = i;
        }
        for (int j = 0; j < prSize && primes[j] <= pr[i] && primes[j] * i < MAXN; j++) {
            pr[primes[j] * i] = primes[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        memcpy(vec[i], vec[x], sizeof(int) * (vec[x][0] + 1));
        vec[i][++vec[i][0]] = cnt;
        int h = calc(vec[i], vec[i][0] + 1);
        maxh = maxh > h ? maxh : h;
        int id = used[h];
        if (id == 0) {
            id = wSize;
            used[h] = id;
            memcpy(w[id], vec[i], sizeof(int) * (vec[i][0] + 1));
            dc[id] = calcd(vec[i], vec[i][0] + 1);
            wSize++;
        }
        vid[i] = id;
    }
    for (int i = 0; i < wSize && i < MAXF; i++) {
        int cur[20];
        memcpy(cur, w[i], sizeof(int) * (w[i][0] + 1));
        for (int j = 0; j < cur[0]; j++) {
            int t[20];
            memcpy(t, cur, sizeof(int) * (cur[0] + 1));
            t[j + 1]--;
            addUsed(g[i], g[i][0]++, t, cur[0] + 1);
            t[j + 1] += 2;
            addUsed(g[i], g[i][0]++, t, cur[0] + 1);
        }
        cur[++cur[0]] = 1;
        addUsed(g[i], g[i][0]++, cur, cur[0]);
        qsort(g[i], g[i][0], sizeof(int), cmp);
        reunique(g[i], g[i][0]);
        dc[i] = calcd(w[i], w[i][0] + 1);
    }
    for (int i = 0; i < wSize; i++) {
        for (int j = 0; j < MAXF * 2; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < wSize; i++) {
        memset(vis, 0, sizeof(vis));
        int q[MAXF * 2];
        int qSize = 1;
        q[0] = i;
        int dp[MAXF * 2];
        for (int j = 0; j < wSize; j++) {
            dp[j] = INF;
        }
        dp[i] = 0;
        for (int j = 0; j < qSize; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 1; k <= g[cur][0]; k++) {
                int to = g[cur][k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[qSize++] = to;
                }
            }
        }
        for (int j = 1; j <= g[i][0]; j++) {
            int to = g[i][j];
            if (dc[to] < MAXF) {
                dist[i][dc[to]] = dist[i][dc[to]] < dp[to] ? dist[i][dc[to]] : dp[to];
            }
        }
    }
    for (int i = 0; i < wSize; i++) {
        dist[i][0] = INF;
        for (int j = i + 1; j < wSize; j++) {
            int res = INF;
            for (int k = 0; k < MAXF; k++) {
                res = res < dist[i][k] + dist[j][k] ? res : dist[i][k] + dist[j][k];
            }
            ans[i][j] = res;
        }
    }
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a = vid[a];
        b = vid[b];
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        printf("%d\n", ans[a][b]);
    }
}

int main() {
    solve();
    return 0;
}
