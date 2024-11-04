#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1010101
#define MAX_FACTORS 30001
#define MAX_DIST MAX_FACTORS

int vec[MAX_SIZE][MAX_FACTORS];
int vid[MAX_SIZE];
int pr[MAX_SIZE];
int primes[MAX_SIZE];
int pr_size = 0;
int used[MAX_SIZE];
int w[MAX_SIZE][MAX_FACTORS];
int dc[MAX_SIZE];
int g[MAX_SIZE][MAX_FACTORS];
int ans[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_DIST];
bool vis[MAX_SIZE];

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

long long calc(int v[], int size) {
    long long res = 0;
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

void addUsed(int v[], int size, int t[], int t_size) {
    long long x = calc(t, t_size);
    if (!used[x]) {
        int sz = used[0];
        used[x] = sz;
        memcpy(w[sz], t, sizeof(int) * t_size);
        dc[sz] = calcd(t, t_size);
        used[0]++;
    }
    v[size] = used[x];
}

void reunique(int v[], int size) {
    int i, j;
    for (i = 1, j = 1; i < size; i++) {
        if (v[i] != v[i - 1]) {
            v[j++] = v[i];
        }
    }
    size = j;
}

void solve() {
    used[0] = 1;
    for (int i = 2; i < MAX_SIZE; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[pr_size++] = i;
        }
        for (int j = 0; j < pr_size && primes[j] <= pr[i] && primes[j] * i < MAX_SIZE; j++) {
            pr[primes[j] * i] = primes[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        memcpy(vec[i], vec[x], sizeof(int) * vec[x][0]);
        vec[i][vec[x][0]] = cnt;
        int h = calc(vec[i], vec[i][0] + 1);
        if (h > used[0]) {
            used[0] = h;
        }
        if (!used[h]) {
            int sz = used[0];
            used[h] = sz;
            memcpy(w[sz], vec[i], sizeof(int) * (vec[i][0] + 1));
            used[0]++;
        }
        vid[i] = used[h];
    }

    int ws = used[0];
    for (int i = 0; i < ws; i++) {
        int cur[MAX_FACTORS];
        memcpy(cur, w[i], sizeof(int) * (w[i][0] + 1));
        for (int j = 0; j < cur[0]; j++) {
            int t[MAX_FACTORS];
            memcpy(t, cur, sizeof(int) * (cur[0] + 1));
            t[j + 1]--;
            addUsed(g[i], g[i][0], t, cur[0] + 1);
            t[j + 1] += 2;
            addUsed(g[i], g[i][0], t, cur[0] + 1);
        }
        cur[cur[0] + 1] = 1;
        addUsed(g[i], g[i][0], cur, cur[0] + 2);
        reunique(g[i], g[i][0]);
        dc[i] = calcd(w[i], w[i][0]);
    }

    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[MAX_SIZE];
        int q_size = 1;
        q[0] = i;
        int dp[MAX_SIZE];
        memset(dp, 0x3f, sizeof(dp));
        dp[i] = 0;
        for (int j = 0; j < q_size; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 1; k <= g[cur][0]; k++) {
                int to = g[cur][k];
                if (dp[to] == 0x3f3f3f3f) {
                    dp[to] = dcur + 1;
                    q[q_size++] = to;
                }
            }
        }
        for (int j = 0; j < used[0]; j++) {
            if (dc[j] < MAX_DIST) {
                dist[i][dc[j]] = dp[j];
            }
        }
    }

    for (int i = 0; i < ws; i++) {
        dist[i][0] = MAX_DIST;
        for (int j = 0; j < i; j++) {
            int res = MAX_DIST;
            for (int k = 0; k < MAX_DIST; k++) {
                if (dist[i][k] + dist[j][k] < res) {
                    res = dist[i][k] + dist[j][k];
                }
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
}

int main() {
    solve();
    return 0;
}
