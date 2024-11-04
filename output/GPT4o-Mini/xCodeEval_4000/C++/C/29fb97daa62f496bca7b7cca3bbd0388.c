#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

#define MAX_C 20
#define INF 1000000000
#define LINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef double db;
typedef struct {
    int st;
    int nd;
} pii;

typedef struct {
    int value;
} mod;

typedef struct {
    int *data;
    int size;
    int capacity;
} vector_int;

void vector_init(vector_int *v) {
    v->size = 0;
    v->capacity = 4;
    v->data = malloc(v->capacity * sizeof(int));
}

void vector_push_back(vector_int *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_clear(vector_int *v) {
    v->size = 0;
}

void vector_free(vector_int *v) {
    free(v->data);
}

int vector_size(vector_int *v) {
    return v->size;
}

int vector_get(vector_int *v, int index) {
    return v->data[index];
}

void vector_set(vector_int *v, int index, int value) {
    v->data[index] = value;
}

void vector_print(vector_int *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

ll fastpow(ll a, ll k, ll m) {
    ll res = 1LL;
    while (k) {
        if (k & 1LL)
            res = (res * a) % m;
        a = (a * a) % m;
        k >>= 1;
    }
    return res;
}

ll extgcd(ll a, ll b, ll *k, ll *l) {
    if (b == 0) {
        *k = 1; *l = 0;
        return a;
    }
    ll res = extgcd(b, a % b, l, k);
    *l -= a / b * (*k);
    return res;
}

int dag(vector_int *g[], vector_int *cur) {
    int n = vector_size(cur);
    bool dp[1 << 20] = {false};
    int reach[20] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vector_size(g[cur->data[i]]); j++) {
            reach[i] |= 1 << (g[cur->data[i]]->data[j]);
        }
    }

    int res = 0;
    dp[0] = true;
    for (int m = 1; m < (1 << n); m++) {
        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) {
                dp[m] = dp[m] || (dp[m ^ (1 << i)] && ((reach[i] & m) == 0));
            }
        }
        if (dp[m]) {
            res = __builtin_popcount(m) > res ? __builtin_popcount(m) : res;
        }
    }

    return res;
}

int solve() {
    int n;
    scanf("%d", &n);
    char s[n + 1], t[n + 1];
    scanf("%s %s", s, t);
    
    vector_int G[MAX_C], g[MAX_C];
    for (int i = 0; i < MAX_C; i++) {
        vector_init(&G[i]);
        vector_init(&g[i]);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int a = s[i] - 'a', b = t[i] - 'a';
            vector_push_back(&G[a], b);
            vector_push_back(&G[b], a);
            vector_push_back(&g[a], b);
        }
    }

    vector_int cur;
    vector_init(&cur);
    bool vis[MAX_C] = {false};
    int res = 0;

    for (int i = 0; i < MAX_C; i++) {
        if (!vis[i]) {
            vector_clear(&cur);
            // DFS
            void dfs(int v) {
                vis[v] = true;
                vector_push_back(&cur, v);
                for (int j = 0; j < vector_size(&G[v]); j++) {
                    int s = G[v].data[j];
                    if (!vis[s]) dfs(s);
                }
            }
            dfs(i);
            int s = dag(g, &cur);
            res += 2 * vector_size(&cur) - 1 - s;
        }
    }

    for (int i = 0; i < MAX_C; i++) {
        vector_free(&G[i]);
        vector_free(&g[i]);
    }
    vector_free(&cur);
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
