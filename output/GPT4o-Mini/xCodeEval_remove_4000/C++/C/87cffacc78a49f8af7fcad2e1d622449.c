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

PT pt_add(PT p1, PT p2) { return (PT){p1.x + p2.x, p1.y + p2.y}; }
PT pt_sub(PT p1, PT p2) { return (PT){p1.x - p2.x, p1.y - p2.y}; }
PT pt_mul(PT p, double c) { return (PT){p.x * c, p.y * c}; }
PT pt_div(PT p, double c) { return (PT){p.x / c, p.y / c}; }
double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(pt_sub(p, q), pt_sub(p, q)); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
double id22(const PT* u, const PT* v) { return dot(*u, *v) / sqrt(dot(*u, *u) * dot(*v, *v)); }
double id6(const PT* u, const PT* v) { return cross(*u, *v) / sqrt(dot(*u, *u) * dot(*v, *v)); }
double id17(const PT* v) { return atan2(v->y, v->x); }

typedef struct {
    ll* C;
    ll n;
} UnionFind;

UnionFind* union_find_create(ll n) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->C = (ll*)malloc(n * sizeof(ll));
    uf->n = n;
    for (ll i = 0; i < n; i++) uf->C[i] = i;
    return uf;
}

ll union_find_find(UnionFind* uf, ll x) {
    return (uf->C[x] == x) ? x : (uf->C[x] = union_find_find(uf, uf->C[x]));
}

void union_find_merge(UnionFind* uf, ll x, ll y) {
    uf->C[union_find_find(uf, x)] = union_find_find(uf, y);
}

void union_find_free(UnionFind* uf) {
    free(uf->C);
    free(uf);
}

ll mod(ll x, ll m) { return ((x % m) + m) % m; }
ll gcd(ll a, ll b) { for (; b > 0; swap(a, b)) a %= b; return a; }

ll id11(ll a, ll b, ll* x, ll* y) {
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
    ll d = id11(a, n, &x, &y);
    if (d > 1) return -1;
    return mod(x, n);
}

void id8(ll n, const ll* froms, const ll* tos, ll* id16, ll* id4) {
    memset(id16, -1, n * sizeof(ll));
    ll en = sizeof(froms) / sizeof(froms[0]);
    for (ll i = 0; i < en; i++) {
        ll f = froms[i];
        ll t = tos[i];
        id4[i] = id16[f];
        id16[f] = i;
    }
}

typedef struct {
    const ll* id16;
    const ll* id13;
    const ll* id7;
    const ll* id9;
    const ll* id4;
    ll s, t;
} id18;

ll _find_aug_path(const ll* id16, const ll* id13, const ll* id7, const ll* id9, const ll* id4, ll s, ll t, ll* epath) {
    ll id24[1000], id0[1000], id21[1000], id27[1000];
    memset(id24, 0, sizeof(id24));
    memset(id0, -1, sizeof(id0));
    memset(id21, -1, sizeof(id21));
    memset(id27, INT_MAX, sizeof(id27));
    
    ll inq[1000] = {0};
    id24[0] = s;
    inq[s] = 1;

    for (ll i = 0; i < 1000; i++) {
        ll crt = id24[i];
        ll f = id27[i];
        for (ll j = id16[crt]; j != -1; j = id4[j]) {
            ll to = id7[j];
            ll rem = id9[j];
            if (inq[to]) continue;
            if (rem <= 0) continue;
            id24[i] = to;
            id0[i] = i;
            id21[i] = j;
            id27[i] = f < rem ? f : rem;
            inq[to] = 1;
        }
    }

    for (ll i = 0; i < 1000; i++) {
        if (id24[i] != t) continue;
        ll stk[1000], top = 0;
        for (ll j = i; j > 0; j = id0[j]) {
            stk[top++] = id21[j];
        }
        for (ll j = 0; j < top; j++) {
            epath[j] = stk[top - j - 1];
        }
        return id27[i];
    }
    return 0;
}

ll eval(id18* id) {
    ll en = id->id13[0]; // Assuming id13 is an array with size as first element
    ll rsd[1000] = {0};
    for (ll i = 0; i < en; i++) {
        ll f = id->id13[i];
        ll t = id->id7[i];
        rsd[f] += id->id9[i];
        rsd[t] += 0;
    }
    
    ll nei[1000] = {0};
    ll ren = 0;
    for (ll i = 0; i < 1000; i++) {
        if (rsd[i]) {
            nei[i] = ren++;
        }
    }
    
    ll rvn = id->id16[0]; // Assuming id16 is an array with size as first element
    ll id12[rvn];
    memset(id12, -1, sizeof(id12));
    
    ll id20[ren], id1[ren], id10[ren], id15[ren];
    
    ll rei = 0;
    for (ll i = 0; i < 1000; i++) {
        if (rsd[i]) {
            ll f = i;
            ll t = nei[i];
            ll c = rsd[i];
            id20[rei] = f;
            id1[rei] = t;
            id10[rei] = c;
            id15[rei] = id12[f];
            id12[f] = rei;
            ++rei;
        }
    }

    ll sol = 0;
    ll epath[1000];
    while (1) {
        memset(epath, 0, sizeof(epath));
        ll res = _find_aug_path(id12, id20, id1, id10, id15, id->s, id->t, epath);
        if (res == 0) break;
        for (ll i = 0; i < 1000; i++) {
            id10[epath[i]] -= res;
            id10[id15[epath[i]]] += res;
        }
        sol += res;
    }
    return sol;
}

int opp(char a, char b) {
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
        ar[i] = ccinv(a[n - i - 1]);
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
