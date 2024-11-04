#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define C 20
#define INF 1000000000
#define LINF 1000000000000000000
#define M 1000000007

typedef long long ll;
typedef double db;

typedef struct {
    int value;
} mod;

typedef struct {
    int st;
    int nd;
} pii;

typedef struct {
    ll st;
    ll nd;
} pll;

typedef struct {
    db st;
    db nd;
} pdb;

typedef struct {
    ll st;
    int nd;
} pil;

typedef struct {
    int st;
    ll nd;
} pli;

typedef struct {
    int* data;
    int size;
    int capacity;
} vi;

vi G[C];
vi cur;
int masks[C];
bool dp[1 << C], vis[C];
int mask;

void init_vi(vi* v, int capacity) {
    v->data = (int*)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void push_back(vi* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void clear(vi* v) {
    v->size = 0;
}

void free_vi(vi* v) {
    free(v->data);
}

void dfs(int v) {
    vis[v] = true;
    mask |= 1 << v;
    push_back(&cur, v);

    for (int i = 0; i < G[v].size; i++) {
        int s = G[v].data[i];
        if (!vis[s]) {
            dfs(s);
        }
    }
}

int count() {
    vi sub;
    init_vi(&sub, 1);
    for (int m = mask; m; m = (m - 1) & mask) {
        push_back(&sub, m);
    }
    for (int i = sub.size - 1; i >= 0; i--) {
        int m = sub.data[i];
        for (int j = 0; j < cur.size; j++) {
            int v = cur.data[j];
            if (m & (1 << v)) {
                dp[m] |= dp[m ^ (1 << v)] && ((m & masks[v] & mask) == 0);
            }
        }
        if (dp[m]) {
            res = fmax(res, __builtin_popcount(m));
        }
    }
    free_vi(&sub);
    return res;
}

int solve() {
    int n;
    scanf("%d", &n);
    char s[n + 1], t[n + 1];
    scanf("%s %s", s, t);

    auto get = [](char c) { return c - 'a'; };

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int a = get(s[i]);
            int b = get(t[i]);
            push_back(&G[a], b);
            push_back(&G[b], a);
            masks[a] |= 1 << b;
        }
    }

    int res = 0;
    dp[0] = true;
    for (int i = 0; i < C; i++) {
        if (!vis[i]) {
            mask = 0;
            clear(&cur);
            dfs(i);
            int tmp = count();
            res += 2 * cur.size - 1 - tmp;
        }
    }

    memset(vis, false, sizeof(vis));
    memset(masks, 0, sizeof(masks));
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < C; i++) {
        clear(&G[i]);
    }

    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
    return 0;
}
