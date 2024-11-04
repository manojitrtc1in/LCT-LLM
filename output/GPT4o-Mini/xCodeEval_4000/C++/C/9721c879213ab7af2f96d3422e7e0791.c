#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
} vector_pi;

typedef struct {
    ll *data;
    size_t size;
    size_t capacity;
} vector_ll;

typedef struct {
    ll *parent;
    ll *size;
    ll n;
} SNM;

pi zero = { -1,-1 };

void cinArr(vector_ll *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        scanf("%lld", &arr->data[i]);
    }
}

void cinMatr(vector_ll *arr, size_t n, size_t m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            scanf("%lld", &arr->data[i * m + j]);
        }
    }
}

vector_pi create_vector_pi(size_t capacity) {
    vector_pi v;
    v.data = (pi *)malloc(capacity * sizeof(pi));
    v.size = 0;
    v.capacity = capacity;
    return v;
}

void push_back_vector_pi(vector_pi *v, pi value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (pi *)realloc(v->data, v->capacity * sizeof(pi));
    }
    v->data[v->size++] = value;
}

void free_vector_pi(vector_pi *v) {
    free(v->data);
}

void free_vector_ll(vector_ll *v) {
    free(v->data);
}

void er(vector_ll *prim, vector_ll *prims) {
    ll n = 1e6;
    prim->data = (ll *)malloc((n + 1) * sizeof(ll));
    prim->size = n + 1;
    prim->capacity = n + 1;
    for (ll i = 0; i <= n; i++) {
        prim->data[i] = i;
    }
    for (ll i = 2; i <= n; i++) {
        if (prim->data[i] == i) {
            push_back_vector_pi(prims, (pi){i, 0});
            for (ll j = i * i; j <= n; j += i) {
                if (prim->data[j] == j) {
                    prim->data[j] = i;
                }
            }
        }
    }
}

typedef struct {
    ll N;
    ll n;
    vector_ll up[20];
    vector_ll g;
    vector_ll lvl;
} LCA;

void dfs(LCA *lca, ll v, ll h) {
    lca->lvl.data[v] = h;
    for (ll i = 0; i < lca->g.size; i++) {
        if (lca->g.data[i] == v) {
            dfs(lca, i, h + 1);
        }
    }
}

LCA create_LCA(vector_ll *parent) {
    LCA lca;
    lca.n = parent->size;
    lca.N = log2(lca.n) + 1;
    lca.g.data = (ll *)malloc(lca.n * sizeof(ll));
    lca.g.size = lca.n;
    lca.lvl.data = (ll *)malloc(lca.n * sizeof(ll));
    lca.lvl.size = lca.n;
    ll core = -1;
    for (ll i = 0; i < lca.n; i++) {
        if (parent->data[i] != -1) {
            lca.g.data[parent->data[i]] = i;
        } else {
            core = i;
        }
    }
    dfs(&lca, core, 0);
    for (ll i = 0; i < lca.N; i++) {
        lca.up[i].data = (ll *)malloc(lca.n * sizeof(ll));
        lca.up[i].size = lca.n;
    }
    for (ll i = 0; i < lca.n; i++) {
        lca.up[0].data[i] = parent->data[i];
    }
    for (ll i = 1; i < lca.N; i++) {
        for (ll j = 0; j < lca.n; j++) {
            ll parent = lca.up[i - 1].data[j];
            if (parent == -1) {
                lca.up[i].data[j] = -1;
            } else {
                lca.up[i].data[j] = lca.up[i - 1].data[parent];
            }
        }
    }
    return lca;
}

ll getParent(LCA *lca, ll v, ll needUp) {
    for (ll i = lca->N - 1; i >= 0; i--) {
        if (lca->up[i].data[v] != -1 && lca->lvl.data[v] - lca->lvl.data[lca->up[i].data[v]] <= needUp) {
            needUp -= lca->lvl.data[v] - lca->lvl.data[lca->up[i].data[v]];
            v = lca->up[i].data[v];
        }
    }
    return (needUp != 0) ? -1 : v;
}

ll getLCA(LCA *lca, ll a, ll b) {
    if (lca->lvl.data[a] > lca->lvl.data[b]) {
        ll del = abs(lca->lvl.data[a] - lca->lvl.data[b]);
        a = getParent(lca, a, del);
    }
    if (lca->lvl.data[a] < lca->lvl.data[b]) {
        ll del = abs(lca->lvl.data[a] - lca->lvl.data[b]);
        b = getParent(lca, b, del);
    }
    if (a == b) {
        return a;
    }
    for (ll i = lca->N - 1; i >= 0; i--) {
        if (lca->up[i].data[a] != lca->up[i].data[b]) {
            a = lca->up[i].data[a];
            b = lca->up[i].data[b];
        }
    }
    return lca->up[0].data[a];
}

ll getLvl(LCA *lca, ll v) {
    return lca->lvl.data[v];
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

Node *create_Node(ll l, ll r, vector_ll *arr, LCA *lca) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->l = l;
    node->r = r;
    node->lca = lca;
    if (l == r) {
        node->a = -1;
        node->del = arr->data[l];
    } else {
        ll mid = (l + r) / 2;
        node->lChildren = create_Node(l, mid, arr, lca);
        node->rChildren = create_Node(mid + 1, r, arr, lca);
        ll len1 = mid - l + 1;
        ll len2 = r - mid;
        pi p = merge(node, node->lChildren->getValue(), node->rChildren->getValue(), len1, len2);
        node->a = p.first;
        node->del = p.second;
    }
    return node;
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
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll gcd_extended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0; *y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd_extended(b % a, a, &x1, &y1);
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

SNM create_SNM(ll n) {
    SNM snm;
    snm.parent = (ll *)malloc(n * sizeof(ll));
    snm.size = (ll *)malloc(n * sizeof(ll));
    snm.n = n;
    for (ll i = 0; i < n; i++) {
        snm.parent[i] = i;
        snm.size[i] = 1;
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

bool chec(ll day, vector_pi *pr, vector_ll *arr) {
    vector_pi bue = create_vector_pi(10);
    ll sum = 0;
    for (size_t i = 0; i < arr->size; i++) {
        pi p;
        p.first = i;
        p.second = -day;
        for (size_t j = 0; j < pr->size; j++) {
            if (pr->data[j].first == i) {
                sum += arr->data[i];
                push_back_vector_pi(&bue, (pi){ -pr->data[j].second, i });
                break;
            }
        }
    }
    qsort(bue.data, bue.size, sizeof(pi), [](const void *a, const void *b) {
        return ((pi *)a)->first - ((pi *)b)->first;
    });

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
    free_vector_pi(&bue);
    return (moneyDelete + sum * 2 <= day);
}

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    vector_ll arr;
    arr.data = (ll *)malloc(n * sizeof(ll));
    arr.size = n;
    arr.capacity = n;
    cinArr(&arr);
    vector_pi pr = create_vector_pi(m);
    for (int i = 0; i < m; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        push_back_vector_pi(&pr, (pi){ b - 1, -a });
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
    free(arr.data);
    free(pr.data);
    return 0;
}
