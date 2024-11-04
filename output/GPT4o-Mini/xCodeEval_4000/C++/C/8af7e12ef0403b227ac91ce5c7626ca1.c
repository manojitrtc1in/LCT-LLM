#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MAX_N 1000010
#define F 10001
#define INF 1011111111

typedef long long ll;

int vec[MAX_N][F];
int vid[MAX_N];
int pr[MAX_N];
int primes[F];
ll maxh;
int dist[F][F];
bool vis[F];
int dc[F];
int g[F][F];
int g_size[F];

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

ll used[MAX_N];
int used_count = 0;

void addUsed(int *v, int *t, int size) {
    ll x = calc(t, size);
    if (!used[x]) {
        used[x] = ++used_count;
        memcpy(g[used_count], t, size * sizeof(int));
        dc[used_count] = calcd(t, size);
    }
    v[g[used_count]] = used[x];
}

int solve() {
    memset(pr, 0, sizeof(pr));
    memset(vec, 0, sizeof(vec));
    memset(vid, 0, sizeof(vid));
    memset(g, 0, sizeof(g));
    memset(g_size, 0, sizeof(g_size));
    memset(dist, INF, sizeof(dist));
    
    used[0] = 0;
    for (int i = 2; i < MAX_N; ++i) {
        if (!pr[i]) {
            pr[i] = i;
            primes[used_count++] = i;
        }
        for (int j = 0; j < used_count; j++) {
            int p = primes[j];
            if (p * i > MAX_N || p > pr[i]) {
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
        memcpy(vec[i] + 1, vec[x], (F - 1) * sizeof(int));
        ll h = calc(vec[i], F);
        maxh = fmax(maxh, h);
        vid[i] = used[h];
    }

    int ws = used_count;
    for (int i = 0; i < fmin(ws, 7000); ++i) {
        int *cur = g[i];
        for (int j = 0; j < F; j++) {
            int t[F];
            memcpy(t, cur, F * sizeof(int));
            t[j]--;
            addUsed(g[i], t, F);
            t[j] += 2;
            addUsed(g[i], t, F);
        }
        cur[F - 1] = 1;
        addUsed(g[i], cur, F);
        // Sort and unique logic would go here
        dc[i] = calcd(g[i], F);
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
        int ans = INF;
        for (int i = 1; i < 3000; ++i) {
            ans = fmin(ans, dist[a][i] + dist[b][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

int main() {
    return solve();
}
