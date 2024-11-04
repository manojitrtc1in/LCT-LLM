#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define REP(i, n) for(ll i=0; i<(n); i++)
#define rep(i, a, b) for(ll i=(a); i<(b); i++)
#define all(v) v.begin(), v.end()

typedef struct {
    ll to, rev;
    ll cap;
} Edge;

typedef struct {
    ll size;
    Edge* edges;
} Edges;

typedef struct {
    ll size;
    Edges* graph;
} Graph;

Graph createGraph(ll size) {
    Graph G;
    G.size = size;
    G.graph = (Edges*)malloc(size * sizeof(Edges));
    REP(i, size) {
        G.graph[i].size = 0;
        G.graph[i].edges = NULL;
    }
    return G;
}

void add_edge(Graph* G, ll from, ll to, ll cap, int revFlag, ll revCap) {
    Edges* edges = &(G->graph[from]);
    edges->size++;
    edges->edges = (Edge*)realloc(edges->edges, edges->size * sizeof(Edge));
    edges->edges[edges->size - 1].to = to;
    edges->edges[edges->size - 1].cap = cap;
    edges->edges[edges->size - 1].rev = G->graph[to].size + (from == to);
    if (revFlag) {
        Edges* revEdges = &(G->graph[to]);
        revEdges->size++;
        revEdges->edges = (Edge*)realloc(revEdges->edges, revEdges->size * sizeof(Edge));
        revEdges->edges[revEdges->size - 1].to = from;
        revEdges->edges[revEdges->size - 1].cap = revCap;
        revEdges->edges[revEdges->size - 1].rev = G->graph[from].size - 1;
    }
}

ll id0(Graph* G, ll v, ll t, ll f, int* used) {
    if (v == t) {
        return f;
    }
    used[v] = 1;
    REP(i, G->graph[v].size) {
        Edge* e = &(G->graph[v].edges[i]);
        if (!used[e->to] && e->cap > 0) {
            ll d = id0(G, e->to, t, f < e->cap ? f : e->cap, used);
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
        int* used = (int*)calloc(G->size, sizeof(int));
        ll f = id0(G, s, t, 1LL << 62, used);
        free(used);
        if (f == 0) {
            return flow;
        }
        flow += f;
    }
}

void id2(Graph* G, ll s, ll* d, ll* negative) {
    ll n = G->size;
    REP(i, n) {
        d[i] = 1LL << 62;
        negative[i] = 0;
    }
    d[s] = 0;
    REP(k, n - 1) {
        REP(i, n) {
            REP(j, G->graph[i].size) {
                Edge* e = &(G->graph[i].edges[j]);
                if (d[i] != 1LL << 62 && d[e->to] > d[i] + e->cap) {
                    d[e->to] = d[i] + e->cap;
                }
            }
        }
    }
    REP(k, n - 1) {
        REP(i, n) {
            REP(j, G->graph[i].size) {
                Edge* e = &(G->graph[i].edges[j]);
                if (d[i] != 1LL << 62 && d[e->to] > d[i] + e->cap) {
                    d[e->to] = d[i] + e->cap;
                    negative[e->to] = 1;
                }
                if (negative[i] == 1) {
                    negative[e->to] = 1;
                }
            }
        }
    }
}

void Dijkstra(Graph* G, ll s, ll* d) {
    ll n = G->size;
    REP(i, n) {
        d[i] = 1LL << 62;
    }
    d[s] = 0;
    typedef struct {
        ll first;
        ll second;
    } P;
    P* q = (P*)malloc(n * sizeof(P));
    ll qSize = 0;
    q[qSize].first = 0;
    q[qSize].second = s;
    qSize++;
    while (qSize > 0) {
        ll minIndex = 0;
        REP(i, qSize) {
            if (q[i].first < q[minIndex].first) {
                minIndex = i;
            }
        }
        P a = q[minIndex];
        q[minIndex] = q[qSize - 1];
        qSize--;
        if (d[a.second] < a.first) {
            continue;
        }
        REP(i, G->graph[a.second].size) {
            Edge e = G->graph[a.second].edges[i];
            if (d[e.to] > d[a.second] + e.cap) {
                d[e.to] = d[a.second] + e.cap;
                q[qSize].first = d[e.to];
                q[qSize].second = e.to;
                qSize++;
            }
        }
    }
    free(q);
}

void id4(Graph* G, ll** d) {
    ll n = G->size;
    REP(i, n) {
        REP(j, n) {
            d[i][j] = i != j ? 1LL << 62 : 0;
        }
    }
    REP(i, n) {
        REP(j, G->graph[i].size) {
            Edge e = G->graph[i].edges[j];
            if (e.cap < d[i][e.to]) {
                d[i][e.to] = e.cap;
            }
        }
    }
    REP(i, n) {
        REP(j, n) {
            REP(k, n) {
                if (d[j][k] > d[j][i] + d[i][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
        }
    }
}

int tsort(Graph* graph, ll* order) {
    int n = graph->size;
    int k = 0;
    int* in = (int*)calloc(n, sizeof(int));
    REP(i, n) {
        REP(j, graph->graph[i].size) {
            in[graph->graph[i].edges[j].to]++;
        }
    }
    ll* que = (ll*)malloc(n * sizeof(ll));
    ll queSize = 0;
    REP(i, n) {
        if (in[i] == 0) {
            que[queSize] = i;
            queSize++;
        }
    }
    while (queSize > 0) {
        ll v = que[queSize - 1];
        queSize--;
        order[k] = v;
        k++;
        REP(i, graph->graph[v].size) {
            Edge e = graph->graph[v].edges[i];
            in[e.to]--;
            if (in[e.to] == 0) {
                que[queSize] = e.to;
                queSize++;
            }
        }
    }
    free(in);
    free(que);
    if (k != n) {
        return 0;
    }
    else {
        return 1;
    }
}

typedef struct {
    ll n;
    ll log2_n;
    ll** parent;
    ll* depth;
} Lca;

Lca createLca(Graph* g, ll root) {
    Lca lca;
    lca.n = g->size;
    lca.log2_n = 0;
    ll tmp = lca.n;
    while (tmp > 0) {
        tmp >>= 1;
        lca.log2_n++;
    }
    lca.parent = (ll**)malloc(lca.log2_n * sizeof(ll*));
    REP(k, lca.log2_n) {
        lca.parent[k] = (ll*)malloc(lca.n * sizeof(ll));
        REP(v, lca.n) {
            lca.parent[k][v] = -1;
        }
    }
    lca.depth = (ll*)malloc(lca.n * sizeof(ll));
    REP(i, lca.n) {
        lca.depth[i] = -1;
    }
    lca.depth[root] = 0;
    typedef struct {
        ll first;
        ll second;
    } P;
    P* q = (P*)malloc(lca.n * sizeof(P));
    ll qSize = 0;
    q[qSize].first = 0;
    q[qSize].second = root;
    qSize++;
    while (qSize > 0) {
        ll minIndex = 0;
        REP(i, qSize) {
            if (q[i].first < q[minIndex].first) {
                minIndex = i;
            }
        }
        P a = q[minIndex];
        q[minIndex] = q[qSize - 1];
        qSize--;
        if (lca.depth[a.second] < a.first) {
            continue;
        }
        REP(i, g->graph[a.second].size) {
            Edge e = g->graph[a.second].edges[i];
            if (lca.depth[e.to] == -1) {
                lca.parent[0][e.to] = a.second;
                lca.depth[e.to] = lca.depth[a.second] + 1;
                q[qSize].first = lca.depth[e.to];
                q[qSize].second = e.to;
                qSize++;
            }
        }
    }
    free(q);
    REP(k, lca.log2_n - 1) {
        REP(v, lca.n) {
            if (lca.parent[k][v] < 0) {
                lca.parent[k + 1][v] = -1;
            }
            else {
                lca.parent[k + 1][v] = lca.parent[k][lca.parent[k][v]];
            }
        }
    }
    return lca;
}

ll getLca(Lca* lca, ll u, ll v) {
    if (lca->depth[u] > lca->depth[v]) {
        ll tmp = u;
        u = v;
        v = tmp;
    }
    for (ll k = 0; k < lca->log2_n; k++) {
        if ((lca->depth[v] - lca->depth[u]) >> k & 1) {
            v = lca->parent[k][v];
        }
    }
    if (u == v) {
        return u;
    }
    for (ll k = lca->log2_n - 1; k >= 0; k--) {
        if (lca->parent[k][u] != lca->parent[k][v]) {
            u = lca->parent[k][u];
            v = lca->parent[k][v];
        }
    }
    return lca->parent[0][u];
}

typedef struct {
    ll* data;
    ll num;
} UnionFind;

UnionFind createUnionFind(ll size) {
    UnionFind uf;
    uf.data = (ll*)malloc(size * sizeof(ll));
    REP(i, size) {
        uf.data[i] = -1;
    }
    uf.num = size;
    return uf;
}

ll merge(UnionFind* uf, ll x, ll y) {
    x = root(uf, x);
    y = root(uf, y);
    if (x != y) {
        if (uf->data[y] < uf->data[x]) {
            ll tmp = x;
            x = y;
            y = tmp;
        }
        uf->data[x] += uf->data[y];
        uf->data[y] = x;
    }
    uf->num -= (x != y);
    return x != y;
}

ll same(UnionFind* uf, ll x, ll y) {
    return root(uf, x) == root(uf, y);
}

ll root(UnionFind* uf, ll x) {
    return uf->data[x] < 0 ? x : uf->data[x] = root(uf, uf->data[x]);
}

ll size(UnionFind* uf, ll x) {
    return -uf->data[root(uf, x)];
}

ll num(UnionFind* uf) {
    return uf->num;
}

typedef struct {
    ll size;
    ll* dat;
} Array;

Array createArray(ll size) {
    Array arr;
    arr.size = size;
    arr.dat = (ll*)malloc(size * sizeof(ll));
    return arr;
}

ll sum(Array* arr, ll k) {
    ll ret = 0;
    for (; k > 0; k -= k & -k) {
        ret += arr->dat[k];
    }
    return ret;
}

ll sumRange(Array* arr, ll a, ll b) {
    return sum(arr, b) - sum(arr, a);
}

void add(Array* arr, ll k, ll x) {
    for (++k; k <= arr->size; k += k & -k) {
        arr->dat[k] += x;
    }
}

ll lower_bound(Array* arr, ll w) {
    if (w <= 0) {
        return -1;
    }
    ll x = 0;
    ll p = arr->size / 2;
    while (p > 0) {
        if (x + p <= arr->size && arr->dat[x + p] < w) {
            w -= arr->dat[x + p];
            x += p;
        }
        p /= 2;
    }
    return x;
}

void divisor(ll n, Array* ret) {
    REP(i, n) {
        if (n % (i + 1) == 0) {
            add(ret, i);
            if ((i + 1) * (i + 1) != n) {
                add(ret, n / (i + 1));
            }
        }
    }
}

void id5(ll n, Array* ret) {
    REP(i, n) {
        if (n % (i + 1) == 0) {
            add(ret, i);
            ll count = 0;
            while (n % (i + 1) == 0) {
                n /= (i + 1);
                count++;
            }
            add(ret, count);
        }
    }
    if (n != 1) {
        add(ret, n);
        add(ret, 1);
    }
}

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod;
        }
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

Combination createCombination(ll n, ll mod) {
    Combination comb;
    comb.mod = mod;
    ll size = n < mod ? n + 1 : mod;
    comb.fact = (ll*)malloc(size * sizeof(ll));
    comb.fact[0] = 1;
    REP(i, size - 1) {
        comb.fact[i + 1] = comb.fact[i] * (i + 1LL) % mod;
    }
    comb.fact_inv = (ll*)malloc(size * sizeof(ll));
    comb.fact_inv[size - 1] = mod_inv(comb.fact[size - 1], mod);
    for (ll i = size - 1; i > 0; i--) {
        comb.fact_inv[i - 1] = comb.fact_inv[i] * i % mod;
    }
    return comb;
}

ll nCr(Combination* comb, ll n, ll r) {
    if (n < r) {
        return 0;
    }
    if (n < comb->mod) {
        return ((comb->fact[n] * comb->fact_inv[r] % comb->mod) * comb->fact_inv[n - r]) % comb->mod;
    }
    ll ret = 1;
    while (n || r) {
        ll _n = n % comb->mod;
        ll _r = r % comb->mod;
        n /= comb->mod;
        r /= comb->mod;
        (ret *= nCr(comb, _n, _r)) %= comb->mod;
    }
    return ret;
}

ll nPr(Combination* comb, ll n, ll r) {
    return (comb->fact[n] * comb->fact_inv[n - r]) % comb->mod;
}

ll nHr(Combination* comb, ll n, ll r) {
    return nCr(comb, r + n - 1, r);
}

typedef struct {
    ll mod;
    ll root;
} NTT;

NTT createNTT(ll mod, ll root) {
    NTT ntt;
    ntt.mod = mod;
    ntt.root = root;
    return ntt;
}

void bit_reverse(ll* a, ll n) {
    ll i = 0;
    REP(j, n - 1) {
        for (ll k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) {
            ll tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
}

void _ntt(ll* a, ll n, ll mod, ll root, int sign) {
    ll tmp = (mod - 1) * mod_pow((ll)n, mod - 2, mod) % mod;
    ll h = mod_pow(root, tmp, mod);
    if (sign == -1) {
        h = mod_pow(h, mod - 2, mod);
    }
    bit_reverse(a, n);
    for (ll m = 1; m < n; m <<= 1) {
        const ll m2 = 2 * m;
        ll _base = mod_pow((ll)h, (ll)(n / m2), mod);
        ll _w = 1;
        for (int x = 0; x < m; ++x) {
            for (ll s = x; s < n; s += m2) {
                ll u = a[s];
                ll d = (a[s + m] * _w) % mod;
                a[s] = (u + d) % mod;
                a[s + m] = (u - d + mod) % mod;
            }
            _w = (_w * _base) % mod;
        }
    }
}

void ntt(ll* input, ll size, ll mod, ll root) {
    _ntt(input, size, mod, root, 1);
}

void intt(ll* input, ll size, ll mod, ll root) {
    _ntt(input, size, mod, root, -1);
    const ll n_inv = mod_pow((ll)size, mod - 2, mod);
    REP(i, size) {
        input[i] = (input[i] * n_inv) % mod;
    }
}

ll* convolution(ll* a, ll* b, ll size, ll mod, ll root) {
    ll result_size = 2 * size - 1;
    ll n = 1;
    while (n < result_size) {
        n <<= 1;
    }
    ll* _a = (ll*)malloc(n * sizeof(ll));
    ll* _b = (ll*)malloc(n * sizeof(ll));
    REP(i, n) {
        _a[i] = i < size ? a[i] : 0;
        _b[i] = i < size ? b[i] : 0;
    }
    ntt(_a, n, mod, root);
    ntt(_b, n, mod, root);
    REP(i, n) {
        _a[i] = (_a[i] * _b[i]) % mod;
    }
    intt(_a, n, mod, root);
    _a = (ll*)realloc(_a, result_size * sizeof(ll));
    return _a;
}

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    Matrix a = (Matrix)malloc(n * sizeof(Array));
    REP(i, n) {
        ll t;
        scanf("%lld", &t);
        a[i].size = 0;
        a[i].dat = NULL;
        REP(j, t) {
            ll tmp;
            scanf("%lld", &tmp);
            if (a[i].size < k) {
                add(&(a[i]), tmp);
            }
        }
    }
    Array w;
    w.size = n;
    w.dat = (ll*)malloc(n * sizeof(ll));
    REP(i, n) {
        w.dat[i] = sum(&(a[i]), a[i].size);
    }
    ll ans = 0;
    void solve(Array*, ll, ll, void (*)(Array*, ll, ll), ll, ll);
    void solve(Array* dp, ll l, ll r) {
        if (r - l == 1) {
            ll sum = 0;
            REP(i, a[l].size + 1) {
                if (i != a[l].size) {
                    sum += a[l].dat[i];
                }
                chmax(ans, dp->dat[k - i] + sum);
            }
            return;
        }
        ll m = (r + l) / 2;
        Array dp2;
        dp2.size = dp->size;
        dp2.dat = (ll*)malloc(dp2.size * sizeof(ll));
        REP(i, dp2.size) {
            dp2.dat[i] = dp->dat[i];
        }
        REP(i, m, r) {
            REP(j, dp2.size) {
                if (a[i].size + j <= k) {
                    chmax(dp2.dat[j + a[i].size], dp2.dat[j] + w.dat[i]);
                }
            }
        }
        solve(&dp2, l, m);
        REP(i, l, m) {
            REP(j, dp->size) {
                if (a[i].size + j <= k) {
                    chmax(dp->dat[j + a[i].size], dp->dat[j] + w.dat[i]);
                }
            }
        }
        solve(dp, m, r);
        free(dp2.dat);
    }
    Array dp;
    dp.size = k + 1;
    dp.dat = (ll*)malloc(dp.size * sizeof(ll));
    solve(&dp, 0, n);
    printf("%lld\n", ans);
    return 0;
}
