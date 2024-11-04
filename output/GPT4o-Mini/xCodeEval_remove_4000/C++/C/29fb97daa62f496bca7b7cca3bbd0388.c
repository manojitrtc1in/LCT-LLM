#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef long long ll;
typedef double db;
typedef long double ldb;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    ll first;
    ll second;
} pll;

typedef struct {
    db first;
    db second;
} pdb;

typedef struct {
    ldb first;
    ldb second;
} pldb;

typedef struct {
    int first;
    ll second;
} pil;

typedef struct {
    ll first;
    int second;
} pli;

typedef struct {
    int *data;
    int size;
    int capacity;
} vi;

typedef struct {
    ll *data;
    int size;
    int capacity;
} vl;

typedef struct {
    char **data;
    int size;
    int capacity;
} vs;

typedef struct {
    char *data;
    int size;
    int capacity;
} vc;

typedef struct {
    bool *data;
    int size;
    int capacity;
} vb;

typedef struct {
    db *data;
    int size;
    int capacity;
} vdb;

typedef struct {
    ldb *data;
    int size;
    int capacity;
} vpld;

typedef struct {
    pii *data;
    int size;
    int capacity;
} vpii;

typedef struct {
    pll *data;
    int size;
    int capacity;
} vpll;

typedef struct {
    pdb *data;
    int size;
    int capacity;
} vpdb;

typedef struct {
    pldb *data;
    int size;
    int capacity;
} vpldb;

typedef struct {
    pil *data;
    int size;
    int capacity;
} vpil;

typedef struct {
    pli *data;
    int size;
    int capacity;
} vpli;

typedef struct {
    vi *data;
    int size;
    int capacity;
} vvi;

#define MOD 7

typedef struct {
    int value;
} Modular;

Modular create_modular(ll v) {
    Modular m;
    m.value = v % MOD;
    if (m.value < 0) m.value += MOD;
    return m;
}

Modular modular_add(Modular a, Modular b) {
    return create_modular(a.value + b.value);
}

Modular modular_sub(Modular a, Modular b) {
    return create_modular(a.value - b.value);
}

Modular modular_mul(Modular a, Modular b) {
    return create_modular((ll)a.value * b.value);
}

Modular modular_div(Modular a, Modular b) {
    return modular_mul(a, modular_inv(b));
}

Modular modular_inv(Modular a) {
    return modular_exp(a, MOD - 2);
}

Modular modular_exp(Modular a, ll k) {
    Modular res = create_modular(1);
    while (k) {
        if (k & 1) res = modular_mul(res, a);
        a = modular_mul(a, a);
        k >>= 1;
    }
    return res;
}

int scanf_t_int() {
    int x;
    scanf("%d", &x);
    return x;
}

ll scanf_t_ll() {
    ll x;
    scanf("%lld", &x);
    return x;
}

db scanf_t_db() {
    db x;
    scanf("%lf", &x);
    return x;
}

ldb scanf_t_ldb() {
    ldb x;
    scanf("%Lf", &x);
    return x;
}

char scanf_t_char() {
    char x;
    scanf(" %c", &x);
    return x;
}

char* scanf_t_string(int n) {
    char *x = (char *)malloc(n + 1);
    scanf("%s", x);
    return x;
}

void printf_t_int(const int x, char end) {
    printf("%d%c", x, end);
}

void printf_t_ll(const ll x, char end) {
    printf("%lld%c", x, end);
}

void printf_t_db(const db x, char end) {
    printf("%.8lf%c", x, end);
}

void printf_t_ldb(const ldb x, char end) {
    printf("%.10Lf%c", x, end);
}

void printf_t_char(const char x, char end) {
    printf("%c%c", x, end);
}

void printf_t_string(const char* x, char end) {
    printf("%s%c", x, end);
}

void print() {
    printf("\n");
}

void print_int(const int last) {
    printf_t_int(last, '\n');
}

void print_ll(const ll last) {
    printf_t_ll(last, '\n');
}

void print_db(const db last) {
    printf_t_db(last, '\n');
}

void print_ldb(const ldb last) {
    printf_t_ldb(last, '\n');
}

void print_char(const char last) {
    printf_t_char(last, '\n');
}

void print_string(const char* last) {
    printf_t_string(last, '\n');
}

int dag(vvi *g, vi *cur) {
    int n = cur->size;
    bool *dp = (bool *)calloc(1 << n, sizeof(bool));
    int *reach = (int *)calloc(n, sizeof(int));
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g->data[cur->data[i]].size; j++) {
            reach[i] |= 1 << g->data[cur->data[i]].data[j];
        }
    }

    int res = 0;
    for (int m = 1; m < (1 << n); m++) {
        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) {
                dp[m] = dp[m] || (dp[m ^ (1 << i)] && ((reach[i] & m) == 0));
            }
        }
        if (dp[m]) {
            res = fmax(res, __builtin_popcount(m));
        }
    }

    free(dp);
    free(reach);
    return res;
}

int solve() {
    int n = scanf_t_int();
    char *s = scanf_t_string(n);
    char *t = scanf_t_string(n);
    int C = 20;

    vvi G;
    G.size = C;
    G.data = (vi *)malloc(C * sizeof(vi));
    for (int i = 0; i < C; i++) {
        G.data[i].data = (int *)malloc(0);
        G.data[i].size = 0;
        G.data[i].capacity = 0;
    }

    vvi g;
    g.size = C;
    g.data = (vi *)malloc(C * sizeof(vi));
    for (int i = 0; i < C; i++) {
        g.data[i].data = (int *)malloc(0);
        g.data[i].size = 0;
        g.data[i].capacity = 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            // Add b to G[a]
            G.data[a].data = (int *)realloc(G.data[a].data, (G.data[a].size + 1) * sizeof(int));
            G.data[a].data[G.data[a].size++] = b;
            // Add a to G[b]
            G.data[b].data = (int *)realloc(G.data[b].data, (G.data[b].size + 1) * sizeof(int));
            G.data[b].data[G.data[b].size++] = a;
            // Add b to g[a]
            g.data[a].data = (int *)realloc(g.data[a].data, (g.data[a].size + 1) * sizeof(int));
            g.data[a].data[g.data[a].size++] = b;
        }
    }

    vi cur;
    cur.data = (int *)malloc(0);
    cur.size = 0;
    cur.capacity = 0;

    bool *vis = (bool *)calloc(C, sizeof(bool));

    void dfs(int v) {
        vis[v] = true;
        cur.data = (int *)realloc(cur.data, (cur.size + 1) * sizeof(int));
        cur.data[cur.size++] = v;
        for (int j = 0; j < G.data[v].size; j++) {
            if (!vis[G.data[v].data[j]]) {
                dfs(G.data[v].data[j]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < C; i++) {
        if (!vis[i]) {
            cur.size = 0;
            dfs(i);
            int s = dag(&g, &cur);
            res += 2 * cur.size - 1 - s;
        }
    }

    free(s);
    free(t);
    free(vis);
    for (int i = 0; i < C; i++) {
        free(G.data[i].data);
        free(g.data[i].data);
    }
    free(G.data);
    free(g.data);
    free(cur.data);
    return res;
}

int main() {
    int t = scanf_t_int();
    while (t--) {
        print_int(solve());
    }
    return 0;
}
