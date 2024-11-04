#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 1000000000

int vec[1010101][20];
int vid[1010101];
int pr[1010101];
int primes[1010101];
int primes_size = 0;
int calc(int v[], int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 24 + v[i];
    }
    return res;
}
int calcd(const int v[], int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}
int used[1010101];
int used_size = 0;
int w[1010101][20];
int w_size = 0;
void addUsed(int v[], int v_size, int t[], int t_size) {
    int x = calc(t, t_size);
    if (!used[x]) {
        used[x] = used_size;
        for (int i = 0; i < t_size; i++) {
            w[w_size][i] = t[i];
        }
        w_size++;
    }
    v[v_size] = used[x];
}
int ans[303][303];
int solve() {
    for (int i = 2; i < 1010101; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[primes_size++] = i;
        }
        for (int j = 0; j < primes_size && primes[j] <= pr[i] && primes[j] * i < 1010101; j++) {
            pr[primes[j] * i] = primes[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        for (int j = 0; j < 20; j++) {
            vec[i][j] = vec[x][j];
        }
        vec[i][cnt - 1]++;
        int h = calc(vec[i], cnt);
        int id = used[h];
        if (!id) {
            id = used_size;
            used[h] = id;
            for (int j = 0; j < cnt; j++) {
                w[id][j] = vec[i][j];
            }
            w_size++;
        }
        vid[i] = id;
    }
    int ws = w_size;
    for (int i = 0; i < ws && i < 1001; i++) {
        int cur[20];
        int cur_size = 0;
        for (int j = 0; j < 20; j++) {
            cur[j] = w[i][j];
            if (cur[j] > 0) {
                cur_size++;
            }
        }
        for (int j = 0; j < cur_size; j++) {
            int t[20];
            int t_size = 0;
            for (int k = 0; k < cur_size; k++) {
                t[k] = cur[k];
                if (k == j) {
                    t[k]--;
                }
                t_size++;
            }
            addUsed(g[i], g_size[i], t, t_size);
            for (int k = 0; k < cur_size; k++) {
                t[k] = cur[k];
                if (k == j) {
                    t[k]++;
                }
                t_size++;
            }
            addUsed(g[i], g_size[i], t, t_size);
        }
        cur[cur_size] = 1;
        addUsed(g[i], g_size[i], cur, cur_size + 1);
        qsort(g[i], g_size[i], sizeof(int), cmpfunc);
        int* end = unique(g[i], g[i] + g_size[i]);
        g_size[i] = end - g[i];
        dc[i] = calcd(w[i], cur_size);
    }
    for (int i = 0; i < used_size; i++) {
        for (int j = 0; j < F; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[1010101];
        int q_size = 0;
        q[0] = i;
        int dp[1010101];
        for (int j = 0; j < used_size; j++) {
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
        for (int j = 0; j < used_size; j++) {
            if (dc[j] < F) {
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j]);
            }
        }
    }
    for (int i = 0; i < ws; i++) {
        dist[i][0] = INF;
        for (int j = 0; j < i + 1; j++) {
            int res = INF;
            for (int k = 0; k < F; k++) {
                res = min(res, dist[i][k] + dist[j][k]);
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
    return 0;
}

int main() {
    solve();
    return 0;
}
