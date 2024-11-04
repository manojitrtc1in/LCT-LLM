#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;
typedef struct {
    ll X, Y;
} pll;
typedef struct {
    int X, Y;
} pii;
typedef struct {
    int *data;
    int size;
} vi;
typedef struct {
    pii *data;
    int size;
} vpii;

void read_vi(vi *v) {
    for (int i = 0; i < v->size; ++i) {
        scanf("%d", &v->data[i]);
    }
}

void read_pii(pii *p) {
    scanf("%d %d", &p->X, &p->Y);
}

pll mp(ll x, ll y) {
    pll p;
    p.X = x;
    p.Y = y;
    return p;
}

pii mp_int(int x, int y) {
    pii p;
    p.X = x;
    p.Y = y;
    return p;
}

ll sq_len(pll p) {
    return p.X * p.X + p.Y * p.Y;
}

ll sq_dist(pll p, pll q) {
    return sq_len(mp(p.X - q.X, p.Y - q.Y));
}

double len(pll p) {
    return sqrt(sq_len(p));
}

double dist(pll p, pll q) {
    return len(mp(p.X - q.X, p.Y - q.Y));
}

bool id6(pll a, pll b, pll c, pll d) {
    ll x = sq_dist(a, b);
    ll y = sq_dist(b, c);
    ll z = sq_dist(c, d);
    ll t = sq_dist(d, a);
    return (x == y) && (y == z) && (z == t);
}

bool is_rectangle(pll a, pll b, pll c, pll d) {
    pll x = mp(b.X - a.X, b.Y - a.Y);
    pll y = mp(c.X - b.X, c.Y - b.Y);
    pll z = mp(d.X - c.X, d.Y - c.Y);
    pll t = mp(a.X - d.X, a.Y - d.Y);
    return (x.X * y.Y == x.Y * y.X) && (y.X * z.Y == y.Y * z.X) && (z.X * t.Y == z.Y * t.X) && (t.X * x.Y == t.Y * x.X);
}

bool are_parallel(pll a, pll b) {
    return (a.X * b.Y - a.Y * b.X == 0);
}

bool id15(pll a, pll b) {
    return (are_parallel(a, b) && (a.X * b.Y >= 0));
}

bool id20(pll a, pll b, pll c, pll d) {
    return ((a.X - b.X) == (d.X - c.X)) && ((a.Y - b.Y) == (d.Y - c.Y));
}

bool id3(pll a, pll b, pll c, pll d) {
    return id15(a, b) && id15(c, d);
}

int raz(int a, int b, int M) {
    int c = a - b;
    return c < 0 ? c + M : c;
}

int sum(int a, int b, int M) {
    int c = a + b;
    return c >= M ? c - M : c;
}

int id17(int r) {
    return 32 - __builtin_clz(r);
}

pii id1(pii p1, pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1))
        return mp_int(-1, -1);
    pii np1 = mp_int(0, raz(p1.Y, p1.X, n));
    pii np2 = mp_int(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1)
            return mp_int(-1, -1);
        else
            return mp_int(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
    } else {
        if (np2.X <= np1.Y + 1)
            return mp_int(-1, -1);
        else
            return mp_int(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
    }
}

struct sparse {
    int n;
    vpii sp;
    void construct(vpii v) {
        n = v.size;
        int r = id17(n - 1);
        sp.data = (pii *)malloc(r * sizeof(pii));
        for (int i = 0; i < n; ++i)
            sp.data[i] = v.data[i];
        for (int i = 1; i < r; ++i) {
            for (int j = 0; j < n; ++j) {
                pii p1 = sp.data[j];
                pii p2 = sp.data[(j + (1 << (i - 1))) % n];
                sp.data[j] = id1(p1, p2, n);
            }
        }
    }
    pii segment(int l, int r) {
        if ((l == -1) || (r == -1))
            return mp_int(-1, -1);
        int szz = raz(r, l, n);
        if (l == r)
            return sp.data[l];
        int g = id17(szz) - 1;
        return id1(sp.data[g], sp.data[((r + 1 - (1 << g)) % n + n) % n], n);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    vi r;
    r.size = n;
    r.data = (int *)malloc(n * sizeof(int));
    read_vi(&r);
    int zz = id17(n) + 1;
    sparse *v = (sparse *)malloc(zz * sizeof(sparse));
    vpii prs;
    prs.size = n;
    prs.data = (pii *)malloc(n * sizeof(pii));

    for (int i = 0; i < n; ++i) {
        if (r.data[i] >= n - 1)
            prs.data[i] = mp_int(-1, -1);
        else
            prs.data[i] = id1(mp_int(raz(i, r.data[i], n), i), mp_int(i, sum(i, r.data[i], n)), n);
    }

    v[0].construct(prs);

    for (int i = 1; i < zz; ++i) {
        vpii id14;
        id14.size = n;
        id14.data = (pii *)malloc(n * sizeof(pii));
        for (int j = 0; j < n; ++j) {
            pii pairr = v[i - 1].segment(j, j);
            id14.data[j] = v[i - 1].segment(pairr.X, pairr.Y);
        }
        v[i].construct(id14);
    }

    for (int i = 0; i < n; ++i) {
        pii my_pr = mp_int(i, i);
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            pii new_pr = v[j].segment(my_pr.X, my_pr.Y);
            if (new_pr.X != -1) {
                ans += (1 << j);
                my_pr = new_pr;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");
    return 0;
}
