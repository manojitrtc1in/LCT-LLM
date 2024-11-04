#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000010
#define F 1001
#define INF 1011111111

int vec[MAX_N][F];
int vid[MAX_N];
int pr[MAX_N];
int primes[MAX_N];
int used[MAX_N];
int dist[F * 2][F * 2];
bool vis[F * 2];
int dc[F * 2];
int g[F * 2][F * 2];
int w[F * 2][F];
int ans[303][303];

int calc(int *v, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 24 + v[i];
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
    int x = calc(t, size);
    if (!used[x]) {
        int sz = 0;
        while (used[sz]) sz++;
        used[x] = sz;
        memcpy(w[sz], t, size * sizeof(int));
        dc[sz] = calcd(t, size);
    }
    v[0] = used[x];
}

int solve() {
    memset(used, 0, sizeof(used));
    memset(pr, 0, sizeof(pr));
    memset(vec, 0, sizeof(vec));
    memset(g, 0, sizeof(g));
    memset(w, 0, sizeof(w));
    memset(ans, 0, sizeof(ans));

    w[0][0] = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[i] = i;
        }
        for (int j = 2; j < i; j++) {
            if (pr[j] * i > MAX_N || pr[j] > pr[i]) {
                break;
            }
            pr[pr[j] * i] = pr[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        vec[i][0] = cnt;
        memcpy(vec[i] + 1, vec[x], sizeof(vec[x]));
        int h = calc(vec[i], cnt + 1);
        int *id = &used[h];
        if (!(*id)) {
            *id = (int)w[0][0];
            memcpy(w[*id], vec[i], (cnt + 1) * sizeof(int));
        }
        vid[i] = *id;
    }

    int ws = 0;
    for (int i = 0; i < F; i++) {
        int *cur = w[i];
        for (int j = 0; j < cur[0]; j++) {
            int t[F];
            memcpy(t, cur, sizeof(cur));
            t[j]--;
            addUsed(g[i], t, cur[0]);
            t[j] += 2;
            addUsed(g[i], t, cur[0]);
        }
        cur[cur[0] + 1] = 1;
        addUsed(g[i], cur, cur[0] + 1);
    }

    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[F * 2];
        q[0] = i;
        int dp[F * 2];
        for (int j = 0; j < F * 2; j++) dp[j] = INF;
        dp[i] = 0;
        for (int j = 0; j < F * 2; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 0; k < F * 2; k++) {
                if (dp[g[cur][k]] == INF) {
                    dp[g[cur][k]] = dcur + 1;
                    q[j + 1] = g[cur][k];
                }
            }
        }
        for (int j = 0; j < used[0]; j++) {
            if (dc[j] < F) {
                dist[i][dc[j]] = (dist[i][dc[j]] < dp[j]) ? dist[i][dc[j]] : dp[j];
            }
        }
    }

    for (int i = 0; i < ws; i++) {
        dist[i][0] = INF;
        for (int j = 0; j <= i; j++) {
            int res = INF;
            for (int k = 0; k < F; k++) {
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
