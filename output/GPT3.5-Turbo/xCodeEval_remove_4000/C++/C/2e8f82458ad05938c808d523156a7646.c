#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int X;
    int Y;
} pii;

typedef struct {
    int n;
    pii** sp;
} sparse;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int abs(int a) {
    return (a < 0) ? -a : a;
}

pii make_pii(int X, int Y) {
    pii* p = (pii*)malloc(sizeof(pii));
    p->X = X;
    p->Y = Y;
    return *p;
}

sparse make_sparse(int n) {
    sparse* s = (sparse*)malloc(sizeof(sparse));
    s->n = n;
    s->sp = (pii**)malloc(n * sizeof(pii*));
    return *s;
}

void construct(sparse* s, pii* v, int n) {
    int r = 32 - __builtin_clz(n - 1);
    s->sp[0] = (pii*)malloc(n * sizeof(pii));
    for (int i = 0; i < n; ++i) {
        s->sp[0][i] = v[i];
    }
    for (int i = 1; i < r; ++i) {
        s->sp[i] = (pii*)malloc(n * sizeof(pii));
        for (int j = 0; j < n; ++j) {
            pii p1 = s->sp[i - 1][j];
            pii p2 = s->sp[i - 1][(j + (1 << (i - 1))) % n];
            s->sp[i][j] = make_pii(id1(p1, p2, n));
        }
    }
}

pii segment(sparse* s, int l, int r) {
    int n = s->n;
    if ((l == -1) || (r == -1)) {
        return make_pii(-1, -1);
    }
    int szz = raz(r, l, n);
    if (l == r) {
        return s->sp[0][l];
    }
    int g = id17(szz) - 1;
    return make_pii(id1(s->sp[g][l], s->sp[g][((r + 1 - (1 << g)) % n + n) % n], n));
}

int id17(int r) {
    return 32 - __builtin_clz(r);
}

int id1(pii p1, pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1)) {
        return -1;
    }
    pii np1 = make_pii(0, raz(p1.Y, p1.X, n));
    pii np2 = make_pii(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) {
            return -1;
        } else {
            return sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n);
        }
    } else {
        if (np2.X <= np1.Y + 1) {
            return -1;
        } else {
            return sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n);
        }
    }
}

int raz(int a, int b, int M) {
    int c = a - b;
    return (c < 0) ? c + M : c;
}

int sum(int a, int b, int M) {
    int c = a + b;
    return (c >= M) ? c - M : c;
}

int id10(pii a, pii b) {
    int p;
    if (p = a.X % b.X) {
        return (p > 0);
    } else {
        return sq_len(a) < sq_len(b);
    }
}

int id9(pii* v, int n) {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i].Y < v[ans].Y) {
            ans = i;
        }
    }
    return ans;
}

int id19(pii** a, int n) {
    if (n) {
        int mt = id9(a, n);
        pii d = a[mt];
        for (int i = 0; i < n; ++i) {
            a[i] -= d;
        }

        int* idx = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i) {
            idx[i] = i;
        }
        sort(idx, idx + n, [&](const int& l, const int& r) {return id10(a[l], a[r]); });

        int* h = (int*)malloc(sizeof(int));
        h[0] = idx[0];
        for (int* it = idx + 1; it != idx + n; ++it) {
            pii* temp = a + *it;
            if (sz(h) >= 2) {
                if (are_parallel(a[h.back()], *temp)) {
                    h.pop_back();
                }
                while ((sz(h) >= 3) && npocs(a[h[sz(h) - 2]], a[h.back()], *temp)) {
                    h.pop_back();
                }
            }
            h.push_back(*it);
        }

        for (int i = 0; i < n; ++i) {
            a[i] += d;
        }
        return h;
    } else {
        return NULL;
    }
}

int id11(pii* a, int n) {
    int ans = 0, n = sz(a);
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[ans]) {
            ans = i;
        }
    }
    return ans;
}

int id20(pii a, pii b, pii c, pii d) {
    return ((a - b) == (d - c));
}

int id8(pii a, pii b, pii c, pii d) {
    pii x = a - b,
        y = b - c,
        z = c - d,
        t = d - a;
    int p = x % y, q = y % z, r = z % t, s = t % x;
    return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
        ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}

int id12(pii a, pii b, pii c, pii d) {
    pii x = a - b, z = d - c;
    return id15(x, z);
}

int id15(pii a, pii b) {
    return (are_parallel(a, b) && (a * b >= 0));
}

int id7(pii a, pii b) {
    return (a * b == 0);
}

int are_parallel(pii a, pii b) {
    return (a % b == 0);
}

int id6(pii a, pii b, pii c, pii d) {
    int x = sq_dist(a, b);
    int y = sq_dist(b, c);
    int z = sq_dist(c, d);
    int t = sq_dist(d, a);
    return ((x == y) && (y == z) && (z == t));
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

pii operator-(pii a, pii b) {
    return make_pii(a.X - b.X, a.Y - b.Y);
}

pii operator+(pii a, pii b) {
    return make_pii(a.X + b.X, a.Y + b.Y);
}

pii operator*(pii p, int q) {
    return make_pii(p.X * q, p.Y * q);
}

int operator*(pii p, pii q) {
    return p.X * q.X + p.Y * q.Y;
}

int operator%(pii p, pii q) {
    return p.X * q.Y - p.Y * q.X;
}

int npocs(pii a, pii b, pii c) {
    return ((a % c) <= 0);
}

int npocs(pii a, pii b, pii c) {
    return npocs(a - b, a - c);
}

int prcs(pii a, pii b, pii c) {
    return ((a % c) > 0);
}

int prcs(pii a, pii b, pii c) {
    return prcs(a - b, a - c);
}

int pocs(pii a, pii b, pii c) {
    return ((a % c) < 0);
}

int pocs(pii a, pii b, pii c) {
    return pocs(a - b, a - c);
}

int id4(pii a, pii b, pii c) {
    return id4(a - b, a - c);
}

int id4(pii a, pii c) {
    return ((a % c) >= 0);
}

int id20(pii a, pii b, pii c, pii d) {
    return ((a - b) == (d - c));
}

int id12(pii a, pii b, pii c, pii d) {
    pii x = a - b, z = d - c;
    return id15(x, z);
}

int id8(pii a, pii b, pii c, pii d) {
    pii x = a - b,
        y = b - c,
        z = c - d,
        t = d - a;
    int p = x % y, q = y % z, r = z % t, s = t % x;
    return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
        ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}

int id21(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p >= 0) && (q <= 0)) ||
        ((p <= 0) && (q >= 0)));
}

int id5(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p > 0) && (q < 0)) ||
        ((p < 0) && (q > 0)));
}

pii id16(pii p) {
    return make_pii(-p.Y, p.X);
}

pii id16(pii p, pii c) {
    return c + id16(p - c);
}

int id3(pii a, pii b, pii c, pii d) {
    return id21(a, b, c, d) && id21(c, d, a, b);
}

int id13(pii a, pii b, pii c, pii d) {
    return id5(a, b, c, d) && id5(c, d, a, b);
}

pii id0(pii normal, pii point) {
    return make_pii(normal, -(normal * point));
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii ints(pii p, int a, pii q, int b) {
    int D = p % q;
    int E = make_pii(-a, p.Y) % make_pii(-b, q.Y);
    int F = make_pii(p.X, -a) % make_pii(q.X, -b);
    return make_pii(E / D, F / D);
}

pii id18(pii x, pii y, pii z) {
    pii p1 = serper(x, y),
        p2 = serper(x, z);
    return ints(p1.X, p1.Y, p2.X, p2.Y);
}

pii serper(pii a, pii b) {
    pii p = b - a;
    return make_pii(p + p, -(p * (a + b)));
}

pii height(pii a, pii b, pii c) {
    return projection(id2(a, c), b);
}

pii projection(pii line, pii point) {
    pii temp = perpendicular(line, point);
    return ints(line, temp.X, temp.Y);
}

pii perpendicular(pii line, pii point) {
    return id0(id16(line), point);
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii id1(pii p1, pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1)) {
        return make_pii(-1, -1);
    }
    pii np1 = make_pii(0, raz(p1.Y, p1.X, n));
    pii np2 = make_pii(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    } else {
        if (np2.X <= np1.Y + 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    }
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int id20(pii a, pii b, pii c, pii d) {
    return ((a - b) == (d - c));
}

int id12(pii a, pii b, pii c, pii d) {
    pii x = a - b, z = d - c;
    return id15(x, z);
}

int id8(pii a, pii b, pii c, pii d) {
    pii x = a - b,
        y = b - c,
        z = c - d,
        t = d - a;
    int p = x % y, q = y % z, r = z % t, s = t % x;
    return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
        ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}

int id21(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p >= 0) && (q <= 0)) ||
        ((p <= 0) && (q >= 0)));
}

int id5(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p > 0) && (q < 0)) ||
        ((p < 0) && (q > 0)));
}

pii id16(pii p) {
    return make_pii(-p.Y, p.X);
}

pii id16(pii p, pii c) {
    return c + id16(p - c);
}

int id3(pii a, pii b, pii c, pii d) {
    return id21(a, b, c, d) && id21(c, d, a, b);
}

int id13(pii a, pii b, pii c, pii d) {
    return id5(a, b, c, d) && id5(c, d, a, b);
}

pii id0(pii normal, pii point) {
    return make_pii(normal, -(normal * point));
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii ints(pii p, int a, pii q, int b) {
    int D = p % q;
    int E = make_pii(-a, p.Y) % make_pii(-b, q.Y);
    int F = make_pii(p.X, -a) % make_pii(q.X, -b);
    return make_pii(E / D, F / D);
}

pii id18(pii x, pii y, pii z) {
    pii p1 = serper(x, y),
        p2 = serper(x, z);
    return ints(p1.X, p1.Y, p2.X, p2.Y);
}

pii serper(pii a, pii b) {
    pii p = b - a;
    return make_pii(p + p, -(p * (a + b)));
}

pii height(pii a, pii b, pii c) {
    return projection(id2(a, c), b);
}

pii projection(pii line, pii point) {
    pii temp = perpendicular(line, point);
    return ints(line, temp.X, temp.Y);
}

pii perpendicular(pii line, pii point) {
    return id0(id16(line), point);
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii id1(pii p1, pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1)) {
        return make_pii(-1, -1);
    }
    pii np1 = make_pii(0, raz(p1.Y, p1.X, n));
    pii np2 = make_pii(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    } else {
        if (np2.X <= np1.Y + 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    }
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int id20(pii a, pii b, pii c, pii d) {
    return ((a - b) == (d - c));
}

int id12(pii a, pii b, pii c, pii d) {
    pii x = a - b, z = d - c;
    return id15(x, z);
}

int id8(pii a, pii b, pii c, pii d) {
    pii x = a - b,
        y = b - c,
        z = c - d,
        t = d - a;
    int p = x % y, q = y % z, r = z % t, s = t % x;
    return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
        ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}

int id21(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p >= 0) && (q <= 0)) ||
        ((p <= 0) && (q >= 0)));
}

int id5(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p > 0) && (q < 0)) ||
        ((p < 0) && (q > 0)));
}

pii id16(pii p) {
    return make_pii(-p.Y, p.X);
}

pii id16(pii p, pii c) {
    return c + id16(p - c);
}

int id3(pii a, pii b, pii c, pii d) {
    return id21(a, b, c, d) && id21(c, d, a, b);
}

int id13(pii a, pii b, pii c, pii d) {
    return id5(a, b, c, d) && id5(c, d, a, b);
}

pii id0(pii normal, pii point) {
    return make_pii(normal, -(normal * point));
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii ints(pii p, int a, pii q, int b) {
    int D = p % q;
    int E = make_pii(-a, p.Y) % make_pii(-b, q.Y);
    int F = make_pii(p.X, -a) % make_pii(q.X, -b);
    return make_pii(E / D, F / D);
}

pii id18(pii x, pii y, pii z) {
    pii p1 = serper(x, y),
        p2 = serper(x, z);
    return ints(p1.X, p1.Y, p2.X, p2.Y);
}

pii serper(pii a, pii b) {
    pii p = b - a;
    return make_pii(p + p, -(p * (a + b)));
}

pii height(pii a, pii b, pii c) {
    return projection(id2(a, c), b);
}

pii projection(pii line, pii point) {
    pii temp = perpendicular(line, point);
    return ints(line, temp.X, temp.Y);
}

pii perpendicular(pii line, pii point) {
    return id0(id16(line), point);
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii id1(pii p1, pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1)) {
        return make_pii(-1, -1);
    }
    pii np1 = make_pii(0, raz(p1.Y, p1.X, n));
    pii np2 = make_pii(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    } else {
        if (np2.X <= np1.Y + 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    }
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int id20(pii a, pii b, pii c, pii d) {
    return ((a - b) == (d - c));
}

int id12(pii a, pii b, pii c, pii d) {
    pii x = a - b, z = d - c;
    return id15(x, z);
}

int id8(pii a, pii b, pii c, pii d) {
    pii x = a - b,
        y = b - c,
        z = c - d,
        t = d - a;
    int p = x % y, q = y % z, r = z % t, s = t % x;
    return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
        ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}

int id21(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p >= 0) && (q <= 0)) ||
        ((p <= 0) && (q >= 0)));
}

int id5(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p > 0) && (q < 0)) ||
        ((p < 0) && (q > 0)));
}

pii id16(pii p) {
    return make_pii(-p.Y, p.X);
}

pii id16(pii p, pii c) {
    return c + id16(p - c);
}

int id3(pii a, pii b, pii c, pii d) {
    return id21(a, b, c, d) && id21(c, d, a, b);
}

int id13(pii a, pii b, pii c, pii d) {
    return id5(a, b, c, d) && id5(c, d, a, b);
}

pii id0(pii normal, pii point) {
    return make_pii(normal, -(normal * point));
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii ints(pii p, int a, pii q, int b) {
    int D = p % q;
    int E = make_pii(-a, p.Y) % make_pii(-b, q.Y);
    int F = make_pii(p.X, -a) % make_pii(q.X, -b);
    return make_pii(E / D, F / D);
}

pii id18(pii x, pii y, pii z) {
    pii p1 = serper(x, y),
        p2 = serper(x, z);
    return ints(p1.X, p1.Y, p2.X, p2.Y);
}

pii serper(pii a, pii b) {
    pii p = b - a;
    return make_pii(p + p, -(p * (a + b)));
}

pii height(pii a, pii b, pii c) {
    return projection(id2(a, c), b);
}

pii projection(pii line, pii point) {
    pii temp = perpendicular(line, point);
    return ints(line, temp.X, temp.Y);
}

pii perpendicular(pii line, pii point) {
    return id0(id16(line), point);
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii id1(pii p1, pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1)) {
        return make_pii(-1, -1);
    }
    pii np1 = make_pii(0, raz(p1.Y, p1.X, n));
    pii np2 = make_pii(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    } else {
        if (np2.X <= np1.Y + 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    }
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int id20(pii a, pii b, pii c, pii d) {
    return ((a - b) == (d - c));
}

int id12(pii a, pii b, pii c, pii d) {
    pii x = a - b, z = d - c;
    return id15(x, z);
}

int id8(pii a, pii b, pii c, pii d) {
    pii x = a - b,
        y = b - c,
        z = c - d,
        t = d - a;
    int p = x % y, q = y % z, r = z % t, s = t % x;
    return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
        ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}

int id21(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p >= 0) && (q <= 0)) ||
        ((p <= 0) && (q >= 0)));
}

int id5(pii a, pii b, pii c, pii d) {
    pii x = b - a;
    int p = x % (c - b), q = x % (d - b);
    return (((p > 0) && (q < 0)) ||
        ((p < 0) && (q > 0)));
}

pii id16(pii p) {
    return make_pii(-p.Y, p.X);
}

pii id16(pii p, pii c) {
    return c + id16(p - c);
}

int id3(pii a, pii b, pii c, pii d) {
    return id21(a, b, c, d) && id21(c, d, a, b);
}

int id13(pii a, pii b, pii c, pii d) {
    return id5(a, b, c, d) && id5(c, d, a, b);
}

pii id0(pii normal, pii point) {
    return make_pii(normal, -(normal * point));
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii ints(pii p, int a, pii q, int b) {
    int D = p % q;
    int E = make_pii(-a, p.Y) % make_pii(-b, q.Y);
    int F = make_pii(p.X, -a) % make_pii(q.X, -b);
    return make_pii(E / D, F / D);
}

pii id18(pii x, pii y, pii z) {
    pii p1 = serper(x, y),
        p2 = serper(x, z);
    return ints(p1.X, p1.Y, p2.X, p2.Y);
}

pii serper(pii a, pii b) {
    pii p = b - a;
    return make_pii(p + p, -(p * (a + b)));
}

pii height(pii a, pii b, pii c) {
    return projection(id2(a, c), b);
}

pii projection(pii line, pii point) {
    pii temp = perpendicular(line, point);
    return ints(line, temp.X, temp.Y);
}

pii perpendicular(pii line, pii point) {
    return id0(id16(line), point);
}

pii id2(pii p, pii q) {
    return make_pii(make_pii(q.Y - p.Y, p.X - q.X), -p % q);
}

pii id1(pii p1, pii p2, int n) {
    if ((p1.X == -1) || (p2.X == -1)) {
        return make_pii(-1, -1);
    }
    pii np1 = make_pii(0, raz(p1.Y, p1.X, n));
    pii np2 = make_pii(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    } else {
        if (np2.X <= np1.Y + 1) {
            return make_pii(-1, -1);
        } else {
            return make_pii(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
        }
    }
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

double len(pii p) {
    return sqrt(sq_len(p));
}

double dist(pii p, pii q) {
    return len(p - q);
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int sq_len(pii p) {
    return p * p;
}

int sq_dist(pii p, pii q) {
    return sq_len(p - q);
}

int dist(pii p, pii q) {
    return len(p - q);
}

