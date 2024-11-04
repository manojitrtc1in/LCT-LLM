#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} pi;

typedef struct {
    pi *data;
    size_t size;
    size_t capacity;
} vpi;

typedef struct {
    ll *data;
    size_t size;
    size_t capacity;
} vi;

typedef struct {
    ll *parent;
    ll *size;
    ll n;
} SNM;

typedef struct {
    ll **up;
    ll *lvl;
    vi g;
    ll N;
    ll n;
} LCA;

pi zero = { -1, -1 };

void cinArr(vi *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        scanf("%lld", &arr->data[i]);
    }
}

void id0(ll **matr, ll n, ll m) {
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            scanf("%lld", &matr[i][j]);
        }
    }
}

vi prim;
vi prims;

void er() {
    ll n = 1e6;
    prim.data = (ll *)malloc((n + 1) * sizeof(ll));
    prim.size = n + 1;
    prim.capacity = n + 1;
    for (ll i = 0; i <= n; i++) {
        prim.data[i] = i;
    }
    for (ll i = 2; i <= n; i++) {
        if (prim.data[i] == i) {
            prims.data[prims.size++] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (prim.data[j] == j) {
                    prim.data[j] = i;
                }
            }
        }
    }
}

void dfs(LCA *lca, ll v, ll h) {
    lca->lvl[v] = h;
    for (ll u = 0; u < lca->g.size; u++) {
        if (lca->g.data[v * lca->g.size + u] != -1) {
            dfs(lca, lca->g.data[v * lca->g.size + u], h + 1);
        }
    }
}

LCA createLCA(vi *parent) {
    LCA lca;
    lca.n = parent->size;
    lca.N = log2(lca.n) + 1;
    lca.g.size = lca.n;
    lca.g.data = (ll *)malloc(lca.n * sizeof(ll));
    lca.lvl = (ll *)malloc(lca.n * sizeof(ll));
    ll core = -1;
    for (size_t i = 0; i < lca.n; i++) {
        if (parent->data[i] != -1) {
            lca.g.data[parent->data[i] * lca.n + i] = i;
        } else {
            core = i;
        }
    }
    dfs(&lca, core, 0);
    lca.up = (ll **)malloc(lca.N * sizeof(ll *));
    for (ll i = 0; i < lca.N; i++) {
        lca.up[i] = (ll *)malloc(lca.n * sizeof(ll));
    }
    for (size_t i = 0; i < lca.n; i++) {
        lca.up[0][i] = parent->data[i];
    }
    for (size_t i = 1; i < lca.N; i++) {
        for (size_t j = 0; j < lca.n; j++) {
            ll parent = lca.up[i - 1][j];
            if (parent == -1) {
                lca.up[i][j] = -1;
            } else {
                lca.up[i][j] = lca.up[i - 1][parent];
            }
        }
    }
    return lca;
}

ll getParent(LCA *lca, ll v, ll needUp) {
    for (ll i = lca->N - 1; i >= 0; i--) {
        if (lca->up[i][v] != -1 && lca->lvl[v] - lca->lvl[lca->up[i][v]] <= needUp) {
            needUp -= lca->lvl[v] - lca->lvl[lca->up[i][v]];
            v = lca->up[i][v];
        }
    }
    return (needUp != 0) ? -1 : v;
}

ll getLCA(LCA *lca, ll a, ll b) {
    if (lca->lvl[a] > lca->lvl[b]) {
        ll del = abs(lca->lvl[a] - lca->lvl[b]);
        a = getParent(lca, a, del);
    }
    if (lca->lvl[a] < lca->lvl[b]) {
        ll del = abs(lca->lvl[a] - lca->lvl[b]);
        b = getParent(lca, b, del);
    }
    if (a == b) {
        return a;
    }
    for (ll i = lca->N - 1; i >= 0; i--) {
        if (lca->up[i][a] != lca->up[i][b]) {
            a = lca->up[i][a];
            b = lca->up[i][b];
        }
    }
    return lca->up[0][a];
}

ll getLvl(LCA *lca, ll v) {
    return lca->lvl[v];
}

SNM createSNM(ll n) {
    SNM snm;
    snm.n = n;
    snm.parent = (ll *)malloc(n * sizeof(ll));
    snm.size = (ll *)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++) {
        snm.parent[i] = i;
        snm.size[i] = 1;
    }
    return snm;
}

ll find_set(SNM *snm, ll v) {
    if (v == snm->parent[v])
        return v;
    ll ans = find_set(snm, snm->parent[v]);
    snm->parent[v] = ans;
    return ans;
}

void union_sets(SNM *snm, ll a, ll b) {
    a = find_set(snm, a);
    b = find_set(snm, b);
    if (a != b) {
        snm->parent[b] = a;
        snm->size[a] += snm->size[b];
    }
}

ll getSize(SNM *snm, ll v) {
    v = find_set(snm, v);
    return snm->size[v];
}

bool chec(ll day, vpi *pr, vi *arr) {
    vpi bue;
    ll sum = 0;
    for (size_t i = 0; i < arr->size; i++) {
        pi p;
        p.first = i;
        p.second = -day;
        // Implement lower_bound equivalent in C
        bool found = false;
        for (size_t j = 0; j < pr->size; j++) {
            if (pr->data[j].first == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            sum += arr->data[i];
        } else {
            bue.data[bue.size++] = (pi){ -pr->data[i].second, i };
        }
    }
    // Sort bue
    for (size_t i = 0; i < bue.size - 1; i++) {
        for (size_t j = i + 1; j < bue.size; j++) {
            if (bue.data[i].first > bue.data[j].first) {
                pi temp = bue.data[i];
                bue.data[i] = bue.data[j];
                bue.data[j] = temp;
            }
        }
    }
    ll moneyDelete = 0;
    for (size_t i = 0; i < bue.size; i++) {
        ll money = bue.data[i].first - moneyDelete;
        ll need = arr->data[bue.data[i].second];
        if (need <= money) {
            moneyDelete += need;
        } else {
            moneyDelete += money;
            sum += need - money;
        }
    }
    return (moneyDelete + sum * 2 <= day);
}

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    vi arr;
    arr.size = n;
    arr.data = (ll *)malloc(n * sizeof(ll));
    cinArr(&arr);
    vpi pr;
    pr.size = 0;
    pr.capacity = m;
    pr.data = (pi *)malloc(m * sizeof(pi));
    for (int i = 0; i < m; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        pr.data[pr.size++] = (pi){ b - 1, -a };
    }
    ll l = 0;
    ll r = 1e6;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (chec(mid, &pr, &arr)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", l);
    return 0;
}
