#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 200001
#define MOD 10007

long mul(long a, long b, long p) {
    long res = 0, base = a;
    while (b > 0) {
        if ((b & 1L) > 0)
            res = (res + base) % p;
        base = (base + base) % p;
        b >>= 1;
    }
    return res;
}

long mod_pow(long k, long n, long p) {
    long res = 1L;
    long temp = k;
    while (n != 0L) {
        if ((n & 1L) == 1L) {
            res = (res * temp) % p;
        }
        temp = (temp * temp) % p;
        n >>= 1;
    }
    return res % p;
}

int ct = 0;
int f[MAX], b[MAX], str[MAX];
int h[MAX], ne[MAX], to[MAX], fa[MAX];
int clr[MAX][3], aa[MAX];
int s1 = 0, s2 = 0;
long t1[MAX];

void go(int rt, int g[][MAX]) {
    str[ct] = rt;
    f[rt] = ct;
    for (int cd = 0; cd < MAX; cd++) {
        if (g[rt][cd] != -1) {
            ct++;
            go(g[rt][cd], g);
        }
    }
    b[rt] = ct;
}

void sort(long a[], int len) {
    for (int i = 1; i < len; ++i) {
        int p = rand() % (i + 1);
        long x = a[p];
        a[p] = a[i];
        a[i] = x;
    }
    qsort(a, len, sizeof(long), (int (*)(const void *, const void *))compare);
}

void dfs(int from, int k) {
    // Implementation needed
}

void add(int u, int v) {
    to[ct] = u;
    ne[ct] = h[v];
    h[v] = ct++;
}

int r = 0;

void dfs1(int c, int ff) {
    clr[c][aa[c]]++;
    for (int j = h[c]; j != -1; j = ne[j]) {
        if (to[j] == ff) continue;
        dfs1(to[j], c);
        clr[c][1] += clr[to[j]][1];
        clr[c][2] += clr[to[j]][2];
        if ((clr[to[j]][1] == s1 && clr[to[j]][2] == 0) || (clr[to[j]][2] == s2 && clr[to[j]][1] == 0)) {
            r++;
        }
    }
}

bool f(int n) {
    int c = 0;
    while (n > 0) {
        c += n % 10;
        n /= 10;
    }
    return (c & 3) == 0;
}

int** next(char* s) {
    int len = strlen(s);
    int** ne = (int**)malloc((len + 1) * sizeof(int*));
    for (int i = 0; i <= len; i++) {
        ne[i] = (int*)malloc(26 * sizeof(int));
        memset(ne[i], -1, 26 * sizeof(int));
    }
    for (int i = len - 1; i >= 0; --i) {
        memcpy(ne[i], ne[i + 1], 26 * sizeof(int));
        ne[i][s[i] - 'a'] = i + 1;
    }
    return ne;
}

void solve() {
    char s[MAX], t[MAX];
    scanf("%s", s);
    scanf("%s", t);
    int len = strlen(s);
    int pref[len], suf[len + 1];
    int p = 0;
    int tlen = strlen(t);
    
    for (int i = 0; i < len; ++i) {
        if (p < tlen && s[i] == t[p]) {
            p++;
        }
        pref[i] = p;
    }
    
    p = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (p < tlen && s[i] == t[tlen - 1 - p]) {
            p++;
        }
        suf[i] = p;
    }
    
    int e = -1, all = 0;
    for (int i = -1; i < len; ++i) {
        int r = tlen - (i < 0 ? 0 : pref[i]);
        while (e + 1 <= len && suf[e + 1] >= r) {
            e++;
        }
        all = (all > e - i - 1) ? all : (e - i - 1);
    }
    printf("%d\n", all);
}

void update(long* t, int i, long v) {
    for (; i < MAX; i += (i & -i)) {
        t[i] += v;
    }
}

long get(long* t, int i) {
    long s = 0;
    for (; i > 0; i -= (i & -i)) {
        s += t[i];
    }
    return s;
}

int id0(long* t, long v) {
    int s = 0, p = 0;
    for (int i = __builtin_ctzll(__builtin_highbit(MAX)); i >= 0; --i) {
        if (p + (1 << i) < MAX && s + t[p + (1 << i)] < v) {
            v -= t[p + (1 << i)];
            p |= 1 << i;
        }
    }
    return p + 1;
}

typedef struct {
    int l;
    int r;
    long le;
    long ri;
    long tot;
    long all;
} S;

S a[MAX * 4];
int* o;

void init(int* f) {
    o = f;
    int len = sizeof(o) / sizeof(o[0]);
    a = (S*)malloc(len * 4 * sizeof(S));
    build(1, 0, len - 1);
}

void build(int num, int l, int r) {
    S cur = {l, r, 0, 0, 0, 0};
    if (l == r) {
        a[num] = cur;
        return;
    } else {
        int m = (l + r) >> 1;
        int le = num << 1;
        int ri = le | 1;
        build(le, l, m);
        build(ri, m + 1, r);
        a[num] = cur;
        pushup(num, le, ri);
    }
}

void update(int num, int l, long v) {
    if (a[num].l == a[num].r) {
        a[num].le = v % MOD;
        a[num].ri = v % MOD;
        a[num].all = v % MOD;
        a[num].tot = v % MOD;
    } else {
        int m = (a[num].l + a[num].r) >> 1;
        int le = num << 1;
        int ri = le | 1;
        pushdown(num, le, ri);
        if (l <= m) {
            update(le, l, v);
        }
        if (l > m) {
            update(ri, l, v);
        }
        pushup(num, le, ri);
    }
}

void pushup(int num, int le, int ri) {
    a[num].all = (a[le].all * a[ri].all) % MOD;
    a[num].le = (a[le].le + a[le].all * a[ri].le) % MOD;
    a[num].ri = (a[ri].ri + a[ri].all * a[le].ri) % MOD;
    a[num].tot = (a[le].tot + a[ri].tot + a[le].ri * a[ri].le) % MOD;
}

void pushdown(int num, int le, int ri) {
    // Implementation needed
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcd_int(int a, int b) {
    return b == 0 ? a : gcd_int(b, a % b);
}

int main() {
    solve();
    return 0;
}
