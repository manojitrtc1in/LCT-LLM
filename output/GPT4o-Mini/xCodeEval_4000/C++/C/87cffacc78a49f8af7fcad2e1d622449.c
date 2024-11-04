#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef long long ll;
typedef long double DOUBLE;

const DOUBLE EPS = 1e-9;
const DOUBLE PI = atan(1) * 4;
const ll M = 1000000007;

typedef struct {
    double x, y;
} PT;

PT pt_create(double x, double y) {
    PT p;
    p.x = x;
    p.y = y;
    return p;
}

double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(pt_create(p.x - q.x, p.y - q.y), pt_create(p.x - q.x, p.y - q.y)); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
double cos_u2v(const PT* u, const PT* v) { return dot(*u, *v) / sqrt(dot(*u, *u) * dot(*v, *v)); }
double sin_u2v(const PT* u, const PT* v) { return cross(*u, *v) / sqrt(dot(*u, *u) * dot(*v, *v)); }

typedef struct {
    ll* C;
    ll size;
} UnionFind;

UnionFind uf_create(ll n) {
    UnionFind uf;
    uf.C = (ll*)malloc(n * sizeof(ll));
    uf.size = n;
    for (int i = 0; i < n; i++) uf.C[i] = i;
    return uf;
}

ll uf_find(UnionFind* uf, ll x) {
    return (uf->C[x] == x) ? x : (uf->C[x] = uf_find(uf, uf->C[x]));
}

void uf_merge(UnionFind* uf, ll x, ll y) {
    uf->C[uf_find(uf, x)] = uf_find(uf, y);
}

ll mod(ll x, ll m) { return ((x % m) + m) % m; }
ll gcd(ll a, ll b) { for (; b > 0; swap(a, b)) a %= b; return a; }

ll extended_euclid(ll a, ll b, ll* x, ll* y) {
    ll xx = *y = 0;
    ll yy = *x = 1;
    while (b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = *x - q * xx; *x = t;
        t = yy; yy = *y - q * yy; *y = t;
    }
    return a;
}

ll mod_inverse(ll a, ll n) {
    ll x, y;
    ll d = extended_euclid(a, n, &x, &y);
    if (d > 1) return -1;
    return mod(x, n);
}

typedef struct {
    int m, n;
    ll* B;
    ll* N;
    DOUBLE** D;
} LPSolver;

LPSolver lps_create(DOUBLE** A, DOUBLE* b, DOUBLE* c, int m, int n) {
    LPSolver lp;
    lp.m = m;
    lp.n = n;
    lp.B = (ll*)malloc(m * sizeof(ll));
    lp.N = (ll*)malloc((n + 1) * sizeof(ll));
    lp.D = (DOUBLE**)malloc((m + 2) * sizeof(DOUBLE*));
    for (int i = 0; i < m + 2; i++) {
        lp.D[i] = (DOUBLE*)malloc((n + 2) * sizeof(DOUBLE));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            lp.D[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        lp.B[i] = n + i;
        lp.D[i][n] = -1;
        lp.D[i][n + 1] = b[i];
    }
    for (int j = 0; j < n; j++) {
        lp.N[j] = j;
        lp.D[m][j] = -c[j];
    }
    lp.N[n] = -1;
    lp.D[m + 1][n] = 1;
    return lp;
}

void lps_pivot(LPSolver* lp, int r, int s) {
    for (int i = 0; i < lp->m + 2; i++) if (i != r)
        for (int j = 0; j < lp->n + 2; j++) if (j != s)
            lp->D[i][j] -= lp->D[r][j] * lp->D[i][s] / lp->D[r][s];
    for (int j = 0; j < lp->n + 2; j++) if (j != s) lp->D[r][j] /= lp->D[r][s];
    for (int i = 0; i < lp->m + 2; i++) if (i != r) lp->D[i][s] /= -lp->D[r][s];
    lp->D[r][s] = 1.0 / lp->D[r][s];
    ll temp = lp->B[r];
    lp->B[r] = lp->N[s];
    lp->N[s] = temp;
}

int lps_simplex(LPSolver* lp, int phase) {
    int x = phase == 1 ? lp->m + 1 : lp->m;
    while (1) {
        int s = -1;
        for (int j = 0; j <= lp->n; j++) {
            if (phase == 2 && lp->N[j] == -1) continue;
            if (s == -1 || lp->D[x][j] < lp->D[x][s] || (lp->D[x][j] == lp->D[x][s] && lp->N[j] < lp->N[s])) s = j;
        }
        if (lp->D[x][s] > -EPS) return 1;
        int r = -1;
        for (int i = 0; i < lp->m; i++) {
            if (lp->D[i][s] < EPS) continue;
            if (r == -1 || lp->D[i][lp->n + 1] / lp->D[i][s] < lp->D[r][lp->n + 1] / lp->D[r][s] ||
                (lp->D[i][lp->n + 1] / lp->D[i][s]) == (lp->D[r][lp->n + 1] / lp->D[r][s]) && lp->B[i] < lp->B[r]) r = i;
        }
        if (r == -1) return 0;
        lps_pivot(lp, r, s);
    }
}

DOUBLE lps_solve(LPSolver* lp, DOUBLE* x) {
    int r = 0;
    for (int i = 1; i < lp->m; i++) if (lp->D[i][lp->n + 1] < lp->D[r][lp->n + 1]) r = i;
    if (lp->D[r][lp->n + 1] < -EPS) {
        lps_pivot(lp, r, lp->n);
        if (!lps_simplex(lp, 1) || lp->D[lp->m + 1][lp->n + 1] < -EPS) return -numeric_limits<DOUBLE>::infinity();
        for (int i = 0; i < lp->m; i++) if (lp->B[i] == -1) {
            int s = -1;
            for (int j = 0; j <= lp->n; j++)
                if (s == -1 || lp->D[i][j] < lp->D[i][s] || (lp->D[i][j] == lp->D[i][s] && lp->N[j] < lp->N[s])) s = j;
            lps_pivot(lp, i, s);
        }
    }
    if (!lps_simplex(lp, 2)) return numeric_limits<DOUBLE>::infinity();
    for (int i = 0; i < lp->m; i++) if (lp->B[i] < lp->n) x[lp->B[i]] = lp->D[i][lp->n + 1];
    return lp->D[lp->m][lp->n + 1];
}

void edgelist2adjlists(ll n, const ll* froms, const ll* tos, ll* v2e0, ll* e2n) {
    memset(v2e0, -1, n * sizeof(ll));
    ll en = sizeof(froms) / sizeof(froms[0]);
    for (int i = 0; i < en; i++) {
        ll f = froms[i];
        ll t = tos[i];
        e2n[i] = v2e0[f];
        v2e0[f] = i;
    }
}

typedef struct {
    const ll* v2e0;
    const ll* e2f;
    const ll* e2t;
    const ll* e2c;
    const ll* e2n;
    ll s, t;
} FordFulk;

FordFulk ff_create(const ll* _v2e0, const ll* _e2f, const ll* _e2t, const ll* _e2c, const ll* _e2n, ll _s, ll _t) {
    FordFulk ff;
    ff.s = _s;
    ff.t = _t;
    ff.v2e0 = _v2e0;
    ff.e2f = _e2f;
    ff.e2t = _e2t;
    ff.e2c = _e2c;
    ff.e2n = _e2n;
    return ff;
}

ll find_aug_path(FordFulk* ff, const ll* v2e0, const ll* e2f, const ll* e2t, const ll* e2c, const ll* e2n, ll s, ll t, ll* epath) {
    ll q2v[1000], q2p[1000], q2e[1000], q2f[1000];
    bool inq[1000] = {0};
    ll q_size = 0;

    q2v[q_size++] = s;
    q2p[0] = -1;
    q2e[0] = -1;
    q2f[0] = INT_MAX;
    inq[s] = true;

    for (ll i = 0; i < q_size; i++) {
        ll crt = q2v[i];
        ll f = q2f[i];
        for (ll j = v2e0[crt]; j != -1; j = e2n[j]) {
            ll to = e2t[j];
            ll rem = e2c[j];
            if (inq[to]) continue;
            if (rem <= 0) continue;
            q2v[q_size] = to;
            q2p[q_size] = i;
            q2e[q_size] = j;
            q2f[q_size] = f < rem ? f : rem;
            inq[to] = true;
            q_size++;
        }
    }

    for (ll i = 0; i < q_size; i++) {
        if (q2v[i] != t) continue;
        ll stk[1000];
        ll stk_size = 0;
        for (ll j = i; j > 0; j = q2p[j]) {
            stk[stk_size++] = q2e[j];
        }
        while (stk_size > 0) {
            epath[stk_size--] = stk[stk_size];
        }
        return q2f[i];
    }
    return 0;
}

ll eval(FordFulk* ff) {
    ll en = sizeof(ff->e2f) / sizeof(ff->e2f[0]);
    ll rsd[1000][2] = {0};
    for (ll i = 0; i < en; i++) {
        ll f = ff->e2f[i];
        ll t = ff->e2t[i];
        rsd[f][t] += ff->e2c[i];
        rsd[t][f] += 0;
    }

    ll nei[1000][2] = {0};
    ll ren = 0;
    for (ll i = 0; i < 1000; i++) {
        if (rsd[i][0] != 0) {
            nei[i][0] = ren++;
        }
    }

    ll rvn = sizeof(ff->v2e0) / sizeof(ff->v2e0[0]);
    ll rv2e0[rvn];
    memset(rv2e0, -1, rvn * sizeof(ll));
    ll re2f[ren], re2t[ren], re2c[ren], re2n[ren], re2p[ren];

    ll rei = 0;
    for (ll i = 0; i < 1000; i++) {
        if (rsd[i][0] != 0) {
            ll f = i;
            ll t = rsd[i][0];
            ll c = rsd[i][1];
            re2f[rei] = f;
            re2t[rei] = t;
            re2c[rei] = c;
            re2p[rei] = nei[t][0];
            re2n[rei] = rv2e0[f];
            rv2e0[f] = rei;
            rei++;
        }
    }

    ll sol = 0;
    ll epath[1000];
    while (1) {
        memset(epath, 0, sizeof(epath));
        ll res = find_aug_path(ff, rv2e0, re2f, re2t, re2c, re2n, ff->s, ff->t, epath);
        if (res == 0) break;
        for (ll i = 0; i < sizeof(epath) / sizeof(epath[0]); i++) {
            re2c[epath[i]] -= res;
            re2c[re2p[epath[i]]] += res;
        }
        sol += res;
    }
    return sol;
}

bool opp(char a, char b) {
    return (a == 'W' && b == 'E') || (a == 'E' && b == 'W') || (a == 'S' && b == 'N') || (a == 'N' && b == 'S');
}

char ccinv(char x) {
    switch (x) {
        case 'N': return 'S';
        case 'S': return 'N';
        case 'W': return 'E';
        case 'E': return 'W';
    }
    return 'W';
}

int main() {
    srand(time(NULL));
    char r[1000], a[1000], b[1000];
    scanf("%s", r);
    scanf("%s", a);
    scanf("%s", b);
    ll n = strlen(a);
    char ar[1000];
    for (ll i = 0; i < n; i++) {
        ar[i] = ccinv(a[n - 1 - i]);
    }
    ll va = 0, vb = 0, p = 1;
    for (ll i = 0, j = n - 1; i < n; i++, j--) {
        va = (va * 131 + ar[i]) % M;
        vb = (vb + b[j] * p) % M;
        p = (p * 131) % M;
        if (vb == va) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
