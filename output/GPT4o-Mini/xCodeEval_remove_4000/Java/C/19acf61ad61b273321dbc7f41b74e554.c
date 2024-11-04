#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000001
#define MAXM 100000

int groups = 0;
int fa[MAXM], sz[MAXM];

void init1(int n) {
    groups = n;
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
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
    if (i == j) return;
    fa[i] = j;
    if (sz[i] < sz[j]) {
        sz[j] += sz[i];
    } else {
        sz[i] += sz[j];
    }
    groups--;
}

char* roundS(double result, int scale) {
    char* buffer = (char*)malloc(20);
    snprintf(buffer, 20, "%.*f", scale, result);
    return buffer;
}

int* unique(int a[], int n, int* newSize) {
    int p = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            a[p++] = a[i];
        }
    }
    *newSize = p;
    return realloc(a, p * sizeof(int));
}

int bigger(long a[], int n, long key) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] > key) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int h[MAXM], to[MAXM], ne[MAXM], m = 0;

void addEdge(int u, int v) {
    to[++m] = v;
    ne[m] = h[u];
    h[u] = m;
}

int w[MAXM];
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

typedef struct {
    int l, r, miss, cnt, c;
} S;

S a[MAXM];
int* o;

void init11(int f[], int len) {
    o = f;
    a = (S*)malloc(len * 4 * sizeof(S));
    build1(1, 0, len - 1);
}

void build1(int num, int l, int r) {
    S cur = {l, r, 0, 0, 0};
    if (l == r) {
        cur.c = o[l];
        a[num] = cur;
        return;
    } else {
        int m = (l + r) / 2;
        int le = num * 2;
        int ri = le + 1;
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
        int m = (a[num].l + a[num].r) / 2;
        int le = num * 2;
        int ri = le + 1;

        int mi = -1;

        if (r > m) {
            int res = query1(ri, l, r);
            mi = (mi > res) ? mi : res;
        }

        if (l <= m) {
            int res = query1(le, l, r);
            mi = (mi > res) ? mi : res;
        }

        return mi;
    }
}

void pushup(int num, int le, int ri) {
    a[num].c = (a[le].c > a[ri].c) ? a[le].c : a[ri].c;
}

int clr[MAXM];
int qr[MAXM][MAXM];
int qs[MAXM][MAXM];

int rr = 100;
int* cao;

void df(int n, int* li, int sz) {
    if (sz >= rr || sz >= 11) return;
    int v = li[sz - 1];
    if (v == n) {
        cao = (int*)malloc(sz * sizeof(int));
        memcpy(cao, li, sz * sizeof(int));
        rr = sz;
        return;
    }
    for (int i = sz - 1; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            if (li[i] + li[j] > v && li[i] + li[j] <= n) {
                li[sz++] = li[i] + li[j];
                df(n, li, sz);
                sz--;
            } else if (li[i] + li[j] > n) {
                break;
            }
        }
    }
}

long mul(long a, long b, long p) {
    long res = 0, base = a;
    while (b > 0) {
        if (b & 1L) {
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
        if (n & 1L) {
            res = mul(res, temp, p);
        }
        temp = mul(temp, temp, p);
        n >>= 1;
    }
    return res % p;
}

long gen(long x) {
    long f;
    while (true) {
        f = rand() % x;
        if (f >= 1 && f <= x - 1) {
            return f;
        }
    }
}

bool id1(long x) {
    if (x == 1) return false;
    if (x == 2 || x == 3) return true;
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
                ck1 <<= 1;
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
    return a == 1 ? 1 : (long)(MOD - MOD / a) * inv(MOD % a, MOD) % MOD;
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

long* id3(long a, long b) {
    if (b == 0) {
        long* res = (long*)malloc(3 * sizeof(long));
        res[0] = 1; res[1] = 0; res[2] = a;
        return res;
    }
    long* r = id3(b, a % b);
    long* res = (long*)malloc(3 * sizeof(long));
    res[0] = r[1];
    res[1] = r[0] - (a / b) * r[1];
    res[2] = r[2];
    free(r);
    return res;
}

void id2(long m[], long r[]) {
    long* res = id3(m[0], m[1]);
    long rm = r[1] - r[0];
    if (rm % res[2] == 0) {
        // Do something
    }
    free(res);
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
    int t;
    scanf("%d", &t);
    int dp[MAXN] = {0};
    for (int i = 0; i < t; ++i) {
        int n, k, d;
        scanf("%d %d %d", &n, &k, &d);
        int a[MAXN];
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
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
            all = (all < g) ? all : g;
        }
        printf("%d\n", all);
        for (int j = 0; j < d; ++j) {
            dp[a[n - j - 1]]--;
        }
    }
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    memset(h, -1, sizeof(h));
    solve();
    return 0;
}
