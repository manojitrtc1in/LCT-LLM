#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define ull unsigned long long
#define rep(i,m,n) for(ll (i)=(ll)(m);i<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define all(hoge) (hoge).begin(),(hoge).end()
typedef struct { ll first, second; } P;

#define m_pi 3.1415926535897932L
#define MOD 1000000007
#define INF 1LL << 61
#define EPS 1e-10
typedef int bool;
#define true 1
#define false 0

typedef struct {
    int to, rev;
    ll cap;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} Edges;

typedef struct {
    Edges* graph;
    int size;
    int capacity;
} Graph;

void add_edge(Graph* G, int from, int to, ll cap, bool revFlag, ll revCap) {
    Edges* edges = &(G->graph[from]);
    if (edges->size == edges->capacity) {
        edges->capacity *= 2;
        edges->edges = (Edge*)realloc(edges->edges, edges->capacity * sizeof(Edge));
    }
    edges->edges[edges->size].to = to;
    edges->edges[edges->size].cap = cap;
    edges->edges[edges->size].rev = edges->size + (from == to);
    edges->size++;
    if (revFlag) {
        edges = &(G->graph[to]);
        if (edges->size == edges->capacity) {
            edges->capacity *= 2;
            edges->edges = (Edge*)realloc(edges->edges, edges->capacity * sizeof(Edge));
        }
        edges->edges[edges->size].to = from;
        edges->edges[edges->size].cap = revCap;
        edges->edges[edges->size].rev = edges->size - 1;
        edges->size++;
    }
}

ll max_flow_dfs(Graph* G, ll v, ll t, ll f, bool* used) {
    if (v == t) {
        return f;
    }
    used[v] = true;
    Edges* edges = &(G->graph[v]);
    for (int i = 0; i < edges->size; ++i) {
        Edge* e = &(edges->edges[i]);
        if (!used[e->to] && e->cap > 0) {
            ll d = max_flow_dfs(G, e->to, t, (f < e->cap) ? f : e->cap, used);
            if (d > 0) {
                e->cap -= d;
                G->graph[e->to].edges[e->rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(Graph* G, ll s, ll t) {
    ll flow = 0;
    for (;;) {
        bool* used = (bool*)calloc(G->size, sizeof(bool));
        ll f = max_flow_dfs(G, s, t, INF, used);
        free(used);
        if (f == 0) {
            return flow;
        }
        flow += f;
    }
}

void BellmanFord(Graph* G, ll s, ll* d, bool* negative) {
    for (int i = 0; i < G->size; i++) {
        d[i] = INF;
        negative[i] = false;
    }
    d[s] = 0;
    for (int k = 0; k < G->size - 1; k++) {
        for (int i = 0; i < G->size; i++) {
            for (int j = 0; j < G->graph[i].size; j++) {
                Edge* e = &(G->graph[i].edges[j]);
                if (d[i] != INF && d[e->to] > d[i] + e->cap) {
                    d[e->to] = d[i] + e->cap;
                }
            }
        }
    }
    for (int k = 0; k < G->size - 1; k++) {
        for (int i = 0; i < G->size; i++) {
            for (int j = 0; j < G->graph[i].size; j++) {
                Edge* e = &(G->graph[i].edges[j]);
                if (d[i] != INF && d[e->to] > d[i] + e->cap) {
                    d[e->to] = d[i] + e->cap;
                    negative[e->to] = true;
                }
                if (negative[i] == true) negative[e->to] = true;
            }
        }
    }
}

void Dijkstra(Graph* G, ll s, ll* d) {
    for (int i = 0; i < G->size; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    int* used = (int*)calloc(G->size, sizeof(int));
    used[s] = 1;
    while (1) {
        int minv = INF;
        int u = -1;
        for (int i = 0; i < G->size; i++) {
            if (!used[i] && minv > d[i]) {
                minv = d[i];
                u = i;
            }
        }
        if (u == -1) {
            break;
        }
        used[u] = 1;
        for (int i = 0; i < G->graph[u].size; i++) {
            Edge* e = &(G->graph[u].edges[i]);
            if (d[e->to] > d[u] + e->cap) {
                d[e->to] = d[u] + e->cap;
            }
        }
    }
    free(used);
}

void WarshallFloyd(Graph* G, ll** d) {
    for (int i = 0; i < G->size; i++) {
        for (int j = 0; j < G->size; j++) {
            d[i][j] = ((i != j) ? INF : 0);
        }
    }
    for (int i = 0; i < G->size; i++) {
        for (int j = 0; j < G->graph[i].size; j++) {
            Edge* e = &(G->graph[i].edges[j]);
            if (d[i][e->to] > e->cap) {
                d[i][e->to] = e->cap;
            }
        }
    }
    for (int i = 0; i < G->size; i++) {
        for (int j = 0; j < G->size; j++) {
            for (int k = 0; k < G->size; k++) {
                if (d[j][i] != INF && d[i][k] != INF) {
                    if (d[j][k] > d[j][i] + d[i][k]) {
                        d[j][k] = d[j][i] + d[i][k];
                    }
                }
            }
        }
    }
}

bool tsort(Graph* graph, int* order) {
    int n = graph->size, k = 0;
    int* in = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph->graph[i].size; j++) {
            Edge* e = &(graph->graph[i].edges[j]);
            in[e->to]++;
        }
    }
    int* que = (int*)calloc(n, sizeof(int));
    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            que[tail++] = i;
        }
    }
    while (head != tail) {
        int v = que[head++];
        order[k++] = v;
        for (int i = 0; i < graph->graph[v].size; i++) {
            Edge* e = &(graph->graph[v].edges[i]);
            if (--in[e->to] == 0) {
                que[tail++] = e->to;
            }
        }
    }
    free(in);
    free(que);
    if (k != n) {
        return false;
    }
    else {
        return true;
    }
}

typedef struct {
    int n;
    int log2_n;
    int** parent;
    int* depth;
} Lca;

void Lca_dfs(Graph* g, int v, int p, int d, Lca* lca) {
    lca->parent[0][v] = p;
    lca->depth[v] = d;
    for (int i = 0; i < g->graph[v].size; i++) {
        Edge* e = &(g->graph[v].edges[i]);
        if (e->to != p) Lca_dfs(g, e->to, v, d + 1, lca);
    }
}

Lca* Lca_new(Graph* g, int root) {
    Lca* lca = (Lca*)malloc(sizeof(Lca));
    lca->n = g->size;
    lca->log2_n = log2(g->size) + 1;
    lca->parent = (int**)malloc(lca->log2_n * sizeof(int*));
    for (int k = 0; k < lca->log2_n; k++) {
        lca->parent[k] = (int*)malloc(lca->n * sizeof(int));
    }
    lca->depth = (int*)malloc(lca->n * sizeof(int));
    Lca_dfs(g, root, -1, 0, lca);
    for (int k = 0; k + 1 < lca->log2_n; k++) {
        for (int v = 0; v < g->size; v++) {
            if (lca->parent[k][v] < 0) {
                lca->parent[k + 1][v] = -1;
            }
            else {
                lca->parent[k + 1][v] = lca->parent[k][lca->parent[k][v]];
            }
        }
    }
    return lca;
}

int Lca_get(Lca* lca, int u, int v) {
    if (lca->depth[u] > lca->depth[v]) {
        int tmp = u;
        u = v;
        v = tmp;
    }
    for (int k = 0; k < lca->log2_n; k++) {
        if ((lca->depth[v] - lca->depth[u]) >> k & 1) {
            v = lca->parent[k][v];
        }
    }
    if (u == v) {
        return u;
    }
    for (int k = lca->log2_n - 1; k >= 0; k--) {
        if (lca->parent[k][u] != lca->parent[k][v]) {
            u = lca->parent[k][u];
            v = lca->parent[k][v];
        }
    }
    return lca->parent[0][u];
}

typedef struct {
    int* data;
    int n;
} UnionFind;

UnionFind* UnionFind_new(int size) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->data = (int*)malloc(size * sizeof(int));
    uf->n = size;
    for (int i = 0; i < size; i++) {
        uf->data[i] = -1;
    }
    return uf;
}

bool UnionFind_merge(UnionFind* uf, int x, int y) {
    x = UnionFind_root(uf, x);
    y = UnionFind_root(uf, y);
    if (x != y) {
        if (uf->data[y] < uf->data[x]) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        uf->data[x] += uf->data[y];
        uf->data[y] = x;
    }
    return x != y;
}

bool UnionFind_same(UnionFind* uf, int x, int y) {
    return UnionFind_root(uf, x) == UnionFind_root(uf, y);
}

int UnionFind_root(UnionFind* uf, int x) {
    return uf->data[x] < 0 ? x : uf->data[x] = UnionFind_root(uf, uf->data[x]);
}

int UnionFind_size(UnionFind* uf, int x) {
    return -uf->data[UnionFind_root(uf, x)];
}

int UnionFind_num(UnionFind* uf) {
    int count = 0;
    for (int i = 0; i < uf->n; i++) {
        if (uf->data[i] < 0) {
            count++;
        }
    }
    return count;
}

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    Pair* data;
    int size;
    int capacity;
} Vector;

Vector* Vector_new() {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    return vec;
}

void Vector_push_back(Vector* vec, Pair value) {
    if (vec->size == vec->capacity) {
        vec->capacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;
        vec->data = (Pair*)realloc(vec->data, vec->capacity * sizeof(Pair));
    }
    vec->data[vec->size] = value;
    vec->size++;
}

void Vector_free(Vector* vec) {
    free(vec->data);
    free(vec);
}

void divisor(ll n, Vector* ret) {
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            Pair p;
            p.first = i;
            p.second = 0;
            Vector_push_back(ret, p);
            if (i * i != n) {
                p.first = n / i;
                Vector_push_back(ret, p);
            }
        }
    }
}

void prime_factorization(ll n, Vector* ret) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            Pair p;
            p.first = i;
            p.second = 0;
            Vector_push_back(ret, p);
            while (n % i == 0) {
                n /= i;
                ret->data[ret->size - 1].second++;
            }
        }
    }
    if (n != 1) {
        Pair p;
        p.first = n;
        p.second = 1;
        Vector_push_back(ret, p);
    }
}

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x, ll mod) {
    return mod_pow(x, mod - 2, mod);
}

typedef struct {
    ll* fact;
    ll* fact_inv;
    ll mod;
} Combination;

Combination* Combination_new(ll n, ll mod) {
    Combination* comb = (Combination*)malloc(sizeof(Combination));
    comb->mod = mod;
    ll _n = (n < mod) ? n + 1 : mod;
    comb->fact = (ll*)malloc(_n * sizeof(ll));
    comb->fact[0] = 1;
    for (ll i = 1; i < _n; i++) {
        comb->fact[i] = (comb->fact[i - 1] * i) % mod;
    }
    comb->fact_inv = (ll*)malloc(_n * sizeof(ll));
    comb->fact_inv[_n - 1] = mod_inv(comb->fact[_n - 1], mod);
    for (ll i = _n - 1; i > 0; i--) {
        comb->fact_inv[i - 1] = (comb->fact_inv[i] * i) % mod;
    }
    return comb;
}

ll Combination_nCr(Combination* comb, ll n, ll r) {
    if (n < r) return 0;
    if (n < comb->mod) return ((comb->fact[n] * comb->fact_inv[r] % comb->mod) * comb->fact_inv[n - r]) % comb->mod;
    ll ret = 1;
    while (n || r) {
        ll _n = n % comb->mod, _r = r % comb->mod;
        n /= comb->mod;
        r /= comb->mod;
        (ret *= Combination_nCr(comb, _n, _r)) %= comb->mod;
    }
    return ret;
}

ll Combination_nPr(Combination* comb, ll n, ll r) {
    return (comb->fact[n] * comb->fact_inv[n - r]) % comb->mod;
}

ll Combination_nHr(Combination* comb, ll n, ll r) {
    return Combination_nCr(comb, r + n - 1, r);
}

ll popcount(ll x) {
    x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
    x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
    x = (x & 0x0F0F0F0F0F0F0F0F) + (x >> 4 & 0x0F0F0F0F0F0F0F0F);
    x = (x & 0x00FF00FF00FF00FF) + (x >> 8 & 0x00FF00FF00FF00FF);
    x = (x & 0x0000FFFF0000FFFF) + (x >> 16 & 0x0000FFFF0000FFFF);
    x = (x & 0x00000000FFFFFFFF) + (x >> 32 & 0x00000000FFFFFFFF);
    return x;
}

ll mod = 998244353;

ll extgcd(ll a, ll b, ll* x, ll* y) {
    if (a < b) return extgcd(b, a, y, x);
    if (b > 0) {
        int g = extgcd(b, a % b, y, x);
        *y -= (a / b) * (*x);
        return g;
    }
    else {
        *x = 1, * y = 0;
        return a;
    }
}

int main() {
    ll m;
    scanf("%lld", &m);
    ll h1, a1, x1, y1;
    scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);
    Vector* t = Vector_new();
    int* used = (int*)calloc(m, sizeof(int));
    used[h1] = 1;
    Pair p;
    p.first = h1;
    Vector_push_back(t, p);
    while (1) {
        ll tmp = (t->data[t->size - 1].first * x1 + y1) % m;
        p.first = tmp;
        Vector_push_back(t, p);
        if (used[tmp]) break;
        used[tmp] = 1;
    }
    used = (int*)calloc(m, sizeof(int));
    ll h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    used[h2] = 1;
    Vector* s = Vector_new();
    p.first = h2;
    Vector_push_back(s, p);
    while (1) {
        ll tmp = (s->data[s->size - 1].first * x2 + y2) % m;
        p.first = tmp;
        Vector_push_back(s, p);
        if (used[tmp]) break;
        used[tmp] = 1;
    }
    ll l1 = -1, l2 = -1;
    ll mn1 = INF, mn2 = INF;
    ll now = 0;
    while (1) {
        if (t->data[t->size - 1].first == t->data[now].first) {
            l1 = t->size - now - 1;
        }
        if (t->data[now].first == a1) {
            mn1 = now;
            break;
        }
        now++;
        if (now == t->size) break;
    }
    now = 0;
    while (1) {
        if (s->data[s->size - 1].first == s->data[now].first) {
            l2 = s->size - now - 1;
        }
        if (s->data[now].first == a2) {
            mn2 = now;
            break;
        }
        now++;
        if (now == s->size) break;
    }
    ll calc() {
        if (mn1 != INF && mn2 != INF) {
            if (mn1 == mn2) return mn1;
            if (mn1 > mn2 && l2 == -1) return -1;
            if (mn1 < mn2 && l1 == -1) return -1;
            if (l1 == -1) {
                if ((mn1 - mn2) % l2 == 0) return mn1;
                else return -1;
            }
            if (l2 == -1) {
                if ((mn2 - mn1) % l1 == 0) return mn2;
                else return -1;
            }
            if (l1 == l2) {
                if (abs(mn1 - mn2) % l1 == 0) return (mn1 > mn2) ? mn1 : mn2;
                else return -1;
            }
            if (mn2 > mn1 && (mn2 - mn1) % l1 == 0) return mn2;
            if (mn1 > mn2 && (mn1 - mn2) % l2 == 0) return mn1;
            if (abs(mn2 - mn1) % abs(gcd(l1, l2)) != 0) return -1;
            ll x, y;
            ll g = extgcd(l1, l2, &x, &y);
            x *= (mn2 - mn1) / g;
            y *= (mn2 - mn1) / g;
            ll mn = INF;
            while (x * l1 + mn1 < max(mn1, mn2)) {
                x += l2 / g;
            }
            mn = x * l1 + mn1;
            while (1) {
                x -= l2 / g;
                if (x * l1 + mn1 >= max(mn1, mn2)) {
                    if (mn > x * l1 + mn1) mn = x * l1 + mn1;
                }
                else break;
            }
            return mn;
        }
        else return -1;
    }
    printf("%lld\n", calc());
    return 0;
}
