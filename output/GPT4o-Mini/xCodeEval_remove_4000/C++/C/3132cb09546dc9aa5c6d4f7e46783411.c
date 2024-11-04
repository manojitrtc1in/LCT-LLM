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
} vpi;

typedef struct {
    ll *data;
    size_t size;
} vi;

typedef struct {
    ll *parent;
    ll *size;
    ll n;
} SNM;

const pi zero = { -1, -1 };

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
    prim.size = n + 1;
    prim.data = (ll *)malloc(prim.size * sizeof(ll));
    for (ll i = 0; i <= n; i++) {
        prim.data[i] = i;
    }
    for (ll i = 2; i <= n; i++) {
        if (prim.data[i] == i) {
            prims.size++;
            prims.data = (ll *)realloc(prims.data, prims.size * sizeof(ll));
            prims.data[prims.size - 1] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (prim.data[j] == j) {
                    prim.data[j] = i;
                }
            }
        }
    }
}

typedef struct {
    ll N;
    ll n;
    ll **up;
    ll **g;
    ll *lvl;

    void dfs(ll v, ll h) {
        lvl[v] = h;
        for (ll u = 0; u < g[v][0]; u++) {
            dfs(g[v][u], h + 1);
        }
    }
} LCA;

LCA *createLCA(vi *parent) {
    LCA *lca = (LCA *)malloc(sizeof(LCA));
    lca->n = parent->size;
    lca->N = log2(lca->n) + 1;
    lca->g = (ll **)malloc(lca->n * sizeof(ll *));
    lca->lvl = (ll *)malloc(lca->n * sizeof(ll));
    for (ll i = 0; i < lca->n; i++) {
        lca->g[i] = (ll *)malloc((lca->n + 1) * sizeof(ll));
        lca->g[i][0] = 0;
    }
    ll core = -1;
    for (ll i = 0; i < lca->n; i++) {
        if (parent->data[i] != -1) {
            lca->g[parent->data[i]][++lca->g[parent->data[i]][0]] = i;
        } else {
            core = i;
        }
    }
    lca->dfs(core, 0);
    lca->up = (ll **)malloc(lca->N * sizeof(ll *));
    for (ll i = 0; i < lca->N; i++) {
        lca->up[i] = (ll *)malloc(lca->n * sizeof(ll));
    }
    for (ll i = 0; i < lca->n; i++) {
        lca->up[0][i] = parent->data[i];
    }
    for (ll i = 1; i < lca->N; i++) {
        for (ll j = 0; j < lca->n; j++) {
            ll parent = lca->up[i - 1][j];
            if (parent == -1) {
                lca->up[i][j] = -1;
            } else {
                lca->up[i][j] = lca->up[i - 1][parent];
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

typedef struct Node {
    ll a;
    ll del;
    LCA *lca;
    ll l;
    ll r;
    struct Node *lChildren;
    struct Node *rChildren;
} Node;

pi merge(Node *node, pi x, pi y, ll len1, ll len2) {
    if (len1 > 2 && len2 > 2) {
        ll a = x.first;
        ll b = x.second;
        ll c = y.first;
        ll d = y.second;

        ll ac = getLCA(node->lca, a, c);
        ll acb = getLCA(node->lca, ac, b);
        ll acd = getLCA(node->lca, ac, d);
        if (getLvl(node->lca, acb) > getLvl(node->lca, acd)) {
            return (pi){ acb, d };
        } else {
            return (pi){ acd, b };
        }
    }
    if (len1 == 0) {
        return y;
    }
    if (len2 == 0) {
        return x;
    }
    ll a = x.first;
    ll b = x.second;
    ll c = y.first;
    ll d = y.second;

    if (len1 == 1 && len2 == 1) {
        if (getLvl(node->lca, b) > getLvl(node->lca, d)) {
            return (pi){ b, d };
        } else {
            return (pi){ d, b };
        }
    }

    if (len1 == 1) {
        if (len2 == 2) {
            ll bc = getLCA(node->lca, b, c);
            ll bd = getLCA(node->lca, b, d);
            ll cd = getLCA(node->lca, c, d);
            ll lbc = getLvl(node->lca, bc);
            ll lbd = getLvl(node->lca, bd);
            ll lcd = getLvl(node->lca, cd);
            if (lbc > lbd && lbc > lcd) {
                return (pi){ bc, d };
            }
            if (lbd > lcd) {
                return (pi){ bd, c };
            }
            return (pi){ cd, b };
        }

        ll bc = getLCA(node->lca, b, c);
        ll cd = getLCA(node->lca, c, d);
        ll lbc = getLvl(node->lca, bc);
        ll lcd = getLvl(node->lca, cd);
        if (lbc > lcd) {
            return (pi){ bc, d };
        } else {
            return (pi){ cd, b };
        }
    }
    if (len2 == 1) {
        if (len1 == 2) {
            ll ab = getLCA(node->lca, a, b);
            ll ad = getLCA(node->lca, a, d);
            ll bd = getLCA(node->lca, b, d);
            ll lab = getLvl(node->lca, ab);
            ll lad = getLvl(node->lca, ad);
            ll lbd = getLvl(node->lca, bd);
            if (lab > lad && lab > lbd) {
                return (pi){ ab, d };
            }
            if (lad > lbd) {
                return (pi){ ad, b };
            }
            return (pi){ bd, a };
        }

        ll ab = getLCA(node->lca, b, a);
        ll ad = getLCA(node->lca, a, d);
        ll lab = getLvl(node->lca, ab);
        ll lad = getLvl(node->lca, ad);
        if (lab > lad) {
            return (pi){ ab, d };
        } else {
            return (pi){ ad, b };
        }
    }
    if (len1 == 2 && len2 > 2) {
        ll abc = getLCA(node->lca, a, getLCA(node->lca, b, c));
        ll acd = getLCA(node->lca, a, getLCA(node->lca, c, d));
        ll bcd = getLCA(node->lca, b, getLCA(node->lca, c, d));

        ll labc = getLvl(node->lca, abc);
        ll lacd = getLvl(node->lca, acd);
        ll lbcd = getLvl(node->lca, bcd);
        ll ans = fmax(labc, fmax(lacd, lbcd));
        if (labc == ans) {
            return (pi){ abc, d };
        }
        if (lacd == ans) {
            return (pi){ acd, b };
        }
        if (lbcd == ans) {
            return (pi){ bcd, a };
        }
    }
    if (len2 == 2 && len1 > 2) {
        ll abc = getLCA(node->lca, a, getLCA(node->lca, b, c));
        ll abd = getLCA(node->lca, a, getLCA(node->lca, b, d));
        ll acd = getLCA(node->lca, a, getLCA(node->lca, c, d));

        ll labc = getLvl(node->lca, abc);
        ll labd = getLvl(node->lca, abd);
        ll lacd = getLvl(node->lca, acd);
        ll ans = fmax(labc, fmax(labd, lacd));
        if (labc == ans) {
            return (pi){ abc, d };
        }
        if (labd == ans) {
            return (pi){ abd, c };
        }
        if (lacd == ans) {
            return (pi){ acd, b };
        }
    }

    ll abc = getLCA(node->lca, a, getLCA(node->lca, b, c));
    ll abd = getLCA(node->lca, a, getLCA(node->lca, b, d));
    ll acd = getLCA(node->lca, a, getLCA(node->lca, c, d));
    ll bcd = getLCA(node->lca, b, getLCA(node->lca, c, d));

    ll labc = getLvl(node->lca, abc);
    ll labd = getLvl(node->lca, abd);
    ll lacd = getLvl(node->lca, acd);
    ll lbcd = getLvl(node->lca, bcd);
    ll ans = fmax(labc, fmax(labd, fmax(lacd, lbcd)));
    if (labc == ans) {
        return (pi){ abc, d };
    }
    if (labd == ans) {
        return (pi){ abd, c };
    }
    if (lacd == ans) {
        return (pi){ acd, b };
    }
    if (lbcd == ans) {
        return (pi){ bcd, a };
    }

    return zero;
}

Node *createNode(ll l, ll r, vi *arr, LCA *lca) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->l = l;
    node->r = r;
    node->lca = lca;
    if (l == r) {
        node->a = -1;
        node->del = arr->data[l];
    } else {
        ll mid = (l + r) / 2;
        node->lChildren = createNode(l, mid, arr, lca);
        node->rChildren = createNode(mid + 1, r, arr, lca);
        ll len1 = mid - l + 1;
        ll len2 = r - mid;
        pi p = merge(node, node->lChildren->getValue(), node->rChildren->getValue(), len1, len2);
        node->a = p.first;
        node->del = p.second;
    }
    return node;
}

Node *createTree(vi *arr, LCA *lca) {
    return createNode(0, arr->size - 1, arr, lca);
}

pi getValue(Node *node) {
    return (pi){ node->a, node->del };
}

pi getValueRange(Node *node, ll left, ll right) {
    if (node->l == left && node->r == right) {
        return getValue(node);
    }
    ll mid = (node->l + node->r) / 2;
    pi p1, p2;
    ll len1 = 0;
    ll len2 = 0;
    p1 = p2 = zero;
    if (left <= mid) {
        p1 = getValueRange(node->lChildren, left, fmin(right, mid));
        len1 = fmin(right, mid) - left + 1;
    }
    if (right > mid) {
        p2 = getValueRange(node->rChildren, fmax(mid + 1, left), right);
        len2 = right - fmax(mid + 1, left) + 1;
    }
    return merge(node, p1, p2, len1, len2);
}

void update(Node *node, ll l, ll r, ll value) {
    if (l == node->l && r == node->r) {
        return;
    }
    ll mid = (node->l + node->r) / 2;
    if (l <= mid) {
        update(node->lChildren, l, fmin(mid, r), value);
    }
    if (r > mid) {
        update(node->rChildren, fmax(mid + 1, l), r, value);
    }
}

ll gcd(ll a, ll b) {
    if (a < b) {
        ll temp = a;
        a = b;
        b = temp;
    }
    return (b == 0) ? a : gcd(b, a % b);
}

ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0; *y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}

ll nok(ll a, ll b) {
    ll nnod = gcd(a, b);
    return a / nnod * b;
}

ll divup(ll a, ll b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

SNM *createSNM(ll n) {
    SNM *snm = (SNM *)malloc(sizeof(SNM));
    snm->n = n;
    snm->parent = (ll *)malloc(n * sizeof(ll));
    snm->size = (ll *)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++) {
        snm->parent[i] = i;
        snm->size[i] = 1;
    }
    return snm;
}

void make_set(SNM *snm, int v) {
    snm->parent[v] = v;
}

int find_set(SNM *snm, int v) {
    if (v == snm->parent[v])
        return v;
    ll ans = find_set(snm, snm->parent[v]);
    snm->parent[v] = ans;
    return ans;
}

void union_sets(SNM *snm, int a, int b) {
    a = find_set(snm, a);
    b = find_set(snm, b);
    if (a != b) {
        snm->parent[b] = a;
        snm->size[a] += snm->size[b];
    }
}

ll getSize(SNM *snm, int v) {
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
        for (size_t j = 0; j < pr->size; j++) {
            if (pr->data[j].first == i) {
                sum += arr->data[i];
                bue.data[bue.size++] = (pi){ -pr->data[j].second, i };
                break;
            }
        }
    }
    qsort(bue.data, bue.size, sizeof(pi), cmp);

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
    pr.data = (pi *)malloc(m * sizeof(pi));
    for (int i = 0; i < m; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        pr.data[pr.size++] = (pi){ b - 1, -a };
    }
    ll l = 0;
    ll r = 1e18;
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
