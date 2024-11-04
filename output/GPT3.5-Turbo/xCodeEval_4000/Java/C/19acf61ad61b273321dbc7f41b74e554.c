#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 1000001

int groups = 0;
int fa[MAXN];
int sz[MAXN];

void init1(int n) {
    groups = n;
    for (int i = 1; i < n; ++i) {
        fa[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        sz[i] = 1;
    }
}

int root(int p) {
    while (p != fa[p]) {
        fa[p] = fa[fa[p]];
        p = fa[p];
    }
    return p;
}

void combine(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i == j) {
        return;
    }
    fa[i] = j;
    if (sz[i] < sz[j]) {
        fa[i] = j;
        sz[j] += sz[i];
    } else {
        fa[j] = i;
        sz[i] += sz[j];
    }
    groups--;
}

char* roundS(double result, int scale) {
    char* fmt = malloc(10 * sizeof(char));
    sprintf(fmt, "%%.%df", scale);
    char* res = malloc(20 * sizeof(char));
    sprintf(res, fmt, result);
    free(fmt);
    return res;
}

int* unique(int a[], int n) {
    int p = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            a[p++] = a[i];
        }
    }
    int* res = malloc(p * sizeof(int));
    for (int i = 0; i < p; ++i) {
        res[i] = a[i];
    }
    return res;
}

int bigger(long a[], int lo, int hi, long key) {
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (a[mid] > key) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int h[MAXN];
int to[MAXN];
int ne[MAXN];
int m = 0;

void addEdge(int u, int v, int w) {
    to[++m] = v;
    ne[m] = h[u];
    h[u] = m;
}

int w[MAXN];

int cc = 0;

void add(int u, int v, int ww) {
    to[++cc] = u;
    w[cc] = ww;
    ne[cc] = h[v];
    h[v] = cc;

    to[++cc] = v;
    w[cc] = ww;
    ne[cc] = h[u];
    h[u] = cc;
}

struct S {
    int l;
    int r;
    int miss;
    int cnt;
    int c;
};

struct S a[MAXN * 4];
int* o;

void init11(int f[], int len) {
    o = f;
    a = malloc(len * 4 * sizeof(struct S));
    build1(1, 0, len - 1);
}

void build1(int num, int l, int r) {
    struct S cur;
    cur.l = l;
    cur.r = r;
    if (l == r) {
        cur.c = o[l];
        a[num] = cur;
        return;
    } else {
        int m = (l + r) >> 1;
        int le = num << 1;
        int ri = le | 1;
        build1(le, l, m);
        build1(ri, m + 1, r);
        a[num] = cur;
        pushup(num, le, ri);
    }
}

int query1(int num, int l, int r) {
    if (a[num].l >= l && a[num].r <= r) {
        return a[num].c;
    } else {
        int m = (a[num].l + a[num].r) >> 1;
        int le = num << 1;
        int ri = le | 1;

        int mi = -1;

        if (r > m) {
            int res = query1(ri, l, r);
            mi = mi > res ? mi : res;
        }

        if (l <= m) {
            int res = query1(le, l, r);
            mi = mi > res ? mi : res;
        }

        return mi;
    }
}

void pushup(int num, int le, int ri) {
    a[num].c = a[le].c > a[ri].c ? a[le].c : a[ri].c;
}

int clr[MAXN];
int** qr;
int qs[MAXN][2];

int rr = 100;
int* cao;

void df(int n, int li[], int sz) {
    if (sz >= rr || sz >= 11) return;
    int v = li[sz - 1];
    if (v == n) {
        cao = malloc(sz * sizeof(int));
        for (int i = 0; i < sz; ++i) {
            cao[i] = li[i];
        }
        rr = sz;
        return;
    }
    int* res = malloc(sz * sizeof(int));
    for (int i = 0; i < sz; ++i) {
        res[i] = li[sz - i - 1];
    }

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            int u = res[i];
            int vv = res[j];
            if (u + vv > v && u + vv <= n) {
                li[sz] = u + vv;
                df(n, li, sz + 1);
            } else if (u + vv > n) {
                break;
            }
        }
    }
    free(res);
}

long mul(long a, long b, long p) {
    long res = 0, base = a;
    while (b > 0) {
        if ((b & 1L) > 0) {
            res = (res + base) % p;
        }
        base = (base + base) % p;
        b >>= 1;
    }
    return res;
}

long mod_pow(long k, long n, long p) {
    long res = 1L;
    long temp = k % p;
    while (n != 0L) {
        if ((n & 1L) == 1L) {
            res = mul(res, temp, p);
        }
        temp = mul(temp, temp, p);
        n = n >> 1L;
    }
    return res % p;
}

long gen(long x) {
    while (1) {
        long f = rand() % x;
        if (f >= 1 && f <= x - 1) {
            return f;
        }
    }
}

bool robin_miller(long x) {
    if (x == 1) return false;
    if (x == 2) return true;
    if (x == 3) return true;
    if ((x & 1) == 0) return false;
    long y = x % 6;
    if (y == 1 || y == 5) {
        long ck = x - 1;
        while ((ck & 1) == 0) ck >>= 1;

        long as[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

        for (int i = 0; i < sizeof(as) / sizeof(as[0]); ++i) {
            long a = as[i];
            long ck1 = ck;
            a = mod_pow(a, ck1, x);
            while (ck1 < x) {
                y = mod_pow(a, 2, x);
                if (y == 1 && a != 1 && a != x - 1)
                    return false;
                a = y;
                ck1 = ck1 << 1;
            }
            if (a != 1)
                return false;
        }
        return true;
    } else {
        return false;
    }
}

long inv(long a, long MOD) {
    return a == 1 ? 1 : (MOD - MOD / a) * inv(MOD % a, MOD) % MOD;
}

long C(long n, long m, long MOD) {
    if (m + m > n) m = n - m;
    long up = 1, down = 1;
    for (long i = 0; i < m; i++) {
        up = up * (n - i) % MOD;
        down = down * (i + 1) % MOD;
    }
    return up * inv(down, MOD) % MOD;
}

long* ex_gcd(long a, long b) {
    if (b == 0) {
        long* res = malloc(3 * sizeof(long));
        res[0] = 1;
        res[1] = 0;
        res[2] = a;
        return res;
    }
    long* r = ex_gcd(b, a % b);
    long* res = malloc(3 * sizeof(long));
    res[0] = r[1];
    res[1] = r[0] - (a / b) * r[1];
    res[2] = r[2];
    free(r);
    return res;
}

void chinese_rm(long m[], long r[]) {
    long* res = ex_gcd(m[0], m[1]);
    long rm = r[1] - r[0];
    if (rm % res[2] == 0) {

    }
}

void go(int i, int c, int cl[]) {
    cl[i] = c;
    for (int j = h[i]; j != -1; j = ne[j]) {
        int v = to[j];
        if (cl[v] == 0) {
            go(v, -c, cl);
        }
    }
}

void solve() {
    int t = ni();
    int dp[MAXN] = {0};
    for (int i = 0; i < t; ++i) {
        int n = ni();
        int k = ni();
        int d = ni();
        int a[n];
        for (int j = 0; j < n; ++j) {
            a[j] = ni();
        }

        int g = 0;
        for (int j = 0; j < d; ++j) {
            if (dp[a[j]]++ == 0) {
                g++;
            }
        }
        int all = g;
        for (int j = d; j < n; ++j) {
            if (--dp[a[j - d]] == 0) {
                g--;
            }
            if (dp[a[j]]++ == 0) {
                g++;
            }
            all = all < g ? all : g;
        }
        printf("%d\n", all);
        for (int j = 0; j < d; ++j) {
            dp[a[n - j - 1]]--;
        }
    }
}

int main() {
    solve();
    return 0;
}
