#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} pi;

typedef struct {
    ll first;
    pi second;
} spi;

typedef struct {
    ll first;
    ll second;
    ll third;
} ppi;

typedef struct {
    ll first;
    pi second;
    ll third;
} vppi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
} vi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
} vvi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
} vpi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
} vvpi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
} vb;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
} vvb;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
} mii;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
} si;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
} msi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
} mspi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
} vsi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
} vppi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
} vsi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
} vmsi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
} vmspi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
} vmsi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
} vmspi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
} vmsi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
    ll twentysecond;
} vmspi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
    ll twentysecond;
    ll twentythird;
} vmsi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
    ll twentysecond;
    ll twentythird;
    ll twentyfourth;
} vmspi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
    ll twentysecond;
    ll twentythird;
    ll twentyfourth;
    ll twentyfifth;
} vmsi;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
    ll twentysecond;
    ll twentythird;
    ll twentyfourth;
    ll twentyfifth;
    ll twentysixth;
} vmspi;

const double PI = 3.141592653589793238463;

pi zero = { -1,-1 };

void cinArr(vi *arr) {
    for (int i = 0; i < arr->first; i++) {
        scanf("%lld", &arr->second[i]);
    }
}

void cinArr(vi *arr) {
    for (int i = 0; i < arr->first; i++) {
        scanf("%lld", &arr->second[i]);
    }
}

void cinMatr(vvi *matr) {
    ll n = matr->first;
    ll m = matr->second;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &matr->third[i][j]);
        }
    }
}

int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0, 0, 1,-1 };

vi prim;
vi prims;
void er() {
    ll n = 1e6;
    prim = vi(n + 1);
    for (int i = 0; i <= n; i++) {
        prim.second[i] = i;
    }
    for (ll i = 2; i <= n; i++) {
        if (prim.second[i] == i) {
            prims.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                if (prim.second[j] == j) {
                    prim.second[j] = i;
                }
            }
        }
    }
}

typedef struct {
    ll N;
    ll n;
    vvi up;
    vvi g;
    vi lvl;
} LCA;

void dfs(LCA *lca, ll v, ll h) {
    lca->lvl.second[v] = h;
    for (ll u : lca->g.second[v]) {
        dfs(lca, u, h + 1);
    }
}

LCA *newLCA(vi *parent) {
    LCA *lca = (LCA *)malloc(sizeof(LCA));
    lca->n = parent->first;
    lca->N = log2(lca->n) + 1;
    lca->g = vvi(lca->n);
    lca->lvl = vi(lca->n);
    ll core = -1;
    for (int i = 0; i < lca->n; i++) {
        if (parent->second[i] != -1) {
            lca->g.second[parent->second[i]].push_back(i);
        }
        else {
            core = i;
        }
    }
    dfs(lca, core, 0);
    lca->up = vvi(lca->N, vi(lca->n));
    lca->up.second[0] = *parent;
    for (int i = 1; i < lca->N; i++) {
        for (int j = 0; j < lca->n; j++) {
            ll parent = lca->up.second[i - 1].second[j];
            if (parent == -1) {
                lca->up.second[i].second[j] = -1;
            }
            else {
                lca->up.second[i].second[j] = lca->up.second[i - 1].second[parent];
            }
        }
    }
    return lca;
}

ll getParent(LCA *lca, ll v, ll needUp) {
    for (int i = lca->N - 1; i >= 0; i--) {
        if (lca->up.second[i].second[v] != -1 && lca->lvl.second[v] - lca->lvl.second[lca->up.second[i].second[v]] <= needUp) {
            needUp -= lca->lvl.second[v] - lca->lvl.second[lca->up.second[i].second[v]];
            v = lca->up.second[i].second[v];
        }
    }
    if (needUp != 0) {
        return -1;
    }
    else {
        return v;
    }
}

ll getLCA(LCA *lca, ll a, ll b) {
    if (lca->lvl.second[a] > lca->lvl.second[b]) {
        ll del = abs(lca->lvl.second[a] - lca->lvl.second[b]);
        a = getParent(lca, a, del);
    }
    if (lca->lvl.second[a] < lca->lvl.second[b]) {
        ll del = abs(lca->lvl.second[a] - lca->lvl.second[b]);
        b = getParent(lca, b, del);
    }
    if (a == b) {
        return a;
    }
    for (int i = lca->N - 1; i >= 0; i--) {
        if (lca->up.second[i].second[a] != lca->up.second[i].second[b]) {
            a = lca->up.second[i].second[a];
            b = lca->up.second[i].second[b];
        }
    }
    return lca->up.second[0].second[a];
}

ll getLvl(LCA *lca, ll v) {
    return lca->lvl.second[v];
}

typedef struct {
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
            return (pi) { acb,d };
        }
        else {
            return (pi) { acd,b };
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
            return (pi) { b,d };
        }
        else {
            return (pi) { d,b };
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
                return (pi) { bc,d };
            }
            if (lbd > lcd) {
                return (pi) { bd,c };
            }
            return (pi) { cd,b };
        }
        ll bc = getLCA(node->lca, b, c);
        ll cd = getLCA(node->lca, c, d);
        ll lbc = getLvl(node->lca, bc);
        ll lcd = getLvl(node->lca, cd);
        if (lbc > lcd) {
            return (pi) { bc,d };
        }
        else {
            return (pi) { cd,b };
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
                return (pi) { ab,d };
            }
            if (lad > lbd) {
                return (pi) { ad,b };
            }
            return (pi) { bd,a };
        }
        ll ab = getLCA(node->lca, b, a);
        ll ad = getLCA(node->lca, a, d);
        ll lab = getLvl(node->lca, ab);
        ll lad = getLvl(node->lca, ad);
        if (lab > lad) {
            return (pi) { ab,d };
        }
        else {
            return (pi) { ad,b };
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
            return (pi) { abc,d };
        }
        if (lacd == ans) {
            return (pi) { acd,b };
        }
        if (lbcd == ans) {
            return (pi) { bcd,a };
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
            return (pi) { abc,d };
        }
        if (labd == ans) {
            return (pi) { abd,c };
        }
        if (lacd == ans) {
            return (pi) { acd,b };
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
        return (pi) { abc,d };
    }
    if (labd == ans) {
        return (pi) { abd,c };
    }
    if (lacd == ans) {
        return (pi) { acd,b };
    }
    if (lbcd == ans) {
        return (pi) { bcd,a };
    }
    return zero;
}

Node *newNode(ll l, ll r, vi *arr, LCA *lca) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->l = l;
    node->r = r;
    if (l == r) {
        node->a = -1;
        node->del = arr->second[l];
    }
    else {
        ll mid = (l + r) / 2;
        node->lChildren = newNode(l, mid, arr, lca);
        node->rChildren = newNode(mid + 1, r, arr, lca);
        ll len1 = mid - l + 1;
        ll len2 = r - mid;
        pi p = merge(node, node->lChildren->a, node->rChildren->a, len1, len2);
        node->a = p.first;
        node->del = p.second;
    }
    return node;
}

Node *newNode(vi *arr, LCA *lca) {
    return newNode(0, arr->first - 1, arr, lca);
}

pi getValue(Node *node) {
    return (pi) { node->a,node->del };
}

pi getValue(Node *node, ll left, ll right) {
    if (node->l == left && node->r == right) {
        return getValue(node);
    }
    ll mid = (node->l + node->r) / 2;
    pi p1, p2;
    ll len1 = 0;
    ll len2 = 0;
    p1 = p2 = zero;
    if (left <= mid) {
        p1 = getValue(node->lChildren, left, fmin(right, mid));
        len1 = fmin(right, mid) - left + 1;
    }
    if (right > mid) {
        p2 = getValue(node->rChildren, fmax(mid + 1, left), right);
        len2 = right - fmax(mid + 1, left) + 1;
    }
    pi p = merge(node, p1, p2, len1, len2);
    return p;
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

ll gcd(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}

ll nok(ll a, ll b) {
    ll nnod = gcd(a, b);
    ll ans = a / nnod * b;
    return ans;
}

ll divup(ll a, ll b) {
    if (a % b == 0) {
        return a / b;
    }
    else {
        return a / b + 1;
    }
}

typedef struct {
    ll first;
    ll second;
    ll third;
} ppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
} pppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
} ppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
} pppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
} ppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
} pppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
} ppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
} pppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
} ppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
} pppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
} ppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
} pppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
} ppppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
} pppppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
} ppppppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
} pppppppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
} ppppppppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
} pppppppppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
} ppppppppppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
    ll twentysecond;
} pppppppppppppppppppppp;

typedef struct {
    ll first;
    ll second;
    ll third;
    ll fourth;
    ll fifth;
    ll sixth;
    ll seventh;
    ll eighth;
    ll ninth;
    ll tenth;
    ll eleventh;
    ll twelfth;
    ll thirteenth;
    ll fourteenth;
    ll fifteenth;
    ll sixteenth;
    ll seventeenth;
    ll eighteenth;
    ll nineteenth;
    ll twentieth;
    ll twentyfirst;
    ll twentysecond;
    ll twentythird;
