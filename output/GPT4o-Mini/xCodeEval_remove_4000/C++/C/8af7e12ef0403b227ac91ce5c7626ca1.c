#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 1000000000
#define MAXN 1000010
#define F 10001

typedef long long ll;
typedef struct {
    int a[1010101];
    int size;
} vector_int;

typedef struct {
    ll key;
    int value;
} map_entry;

typedef struct {
    map_entry entries[1010101];
    int size;
} map_ll_int;

vector_int vec[1010101];
int vid[1010101];
int pr[1010101];
vector_int primes;
ll maxh;
int dist[301][F];
bool vis[F];
int dc[F];
vector_int g[F];
vector_int w[1010101];
map_ll_int used;

ll calc(vector_int* v) {
    ll res = 0;
    for (int i = 0; i < v->size; i++) {
        res = res * 30 + v->a[i];
    }
    return res;
}

int calcd(vector_int* v) {
    int res = 1;
    for (int i = 0; i < v->size; i++) {
        res *= v->a[i] + 1;
    }
    return res;
}

void addUsed(vector_int* v, vector_int* t) {
    ll x = calc(t);
    if (!used.entries[x].key) {
        int sz = used.size++;
        used.entries[x].key = x;
        used.entries[x].value = sz;
        w[sz] = *t;
        dc[sz] = calcd(t);
    }
    v->a[v->size++] = used.entries[x].value;
}

int solve() {
    memset(vid, 0, sizeof(vid));
    memset(pr, 0, sizeof(pr));
    memset(dist, INF, sizeof(dist));
    memset(dc, 0, sizeof(dc));
    memset(vis, 0, sizeof(vis));
    used.size = 0;

    w[0].size = 0;
    used.entries[0].key = 0;

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
        maxh = (maxh > h) ? maxh : h;
        int* id = &used.entries[h].value;
        if (!*id) {
            *id = (int)w[0].size;
            w[*id] = vec[i];
        }
        vid[i] = *id;
    }

    int ws = (int)w[0].size;
    for (int i = 0; i < ws && i < 7000; ++i) {
        vector_int cur = w[i];
        for (int j = 0; j < cur.size; ++j) {
            vector_int t = cur;
            t.a[j]--;
            addUsed(&g[i], &t);
            t.a[j] += 2;
            addUsed(&g[i], &t);
        }
        cur.a[cur.size++] = 1;
        addUsed(&g[i], &cur);
        // Sort and unique logic can be added here
        dc[i] = calcd(&w[i]);
    }

    for (int i = 0; i < ws; ++i) {
        memset(vis, 0, sizeof(vis));
        vector_int q;
        q.size = 0;
        q.a[q.size++] = i;
        int dp[1010101];
        memset(dp, INF, sizeof(dp));
        dp[i] = 0;

        for (int j = 0; j < q.size; ++j) {
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
                dist[i][dc[j]] = (dist[i][dc[j]] < dp[j]) ? dist[i][dc[j]] : dp[j];
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
        int ans = INF;
        for (int i = 1; i < 3000; ++i) {
            ans = (ans < dist[a][i] + dist[b][i]) ? ans : (dist[a][i] + dist[b][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

int main() {
    solve();
    return 0;
}
