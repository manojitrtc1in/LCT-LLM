#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int test = 0;
int dirs8[8][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}, {1,1},{1,-1},{-1,1},{-1,-1}};
int dirs4[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

int WALL = -1;
int EMPTY = -2;
int VISITED = 1;
int FULL = 2;

int START = 1;
int END = 0;

int* fac;
int* ifac;
int* rfac;

int* pow2;

int* mobius;
int* sieve;
int** factors;

int UNVISITED = -2;

void dfs(int root, int par, int chosenRoot, int special, int** nbs, int* size, int* visited);
long** matIdentity(int n);
long** matPow(long** mat0, long p);
long** matCopy(long** a, int n);
long** matMul(long** a, long** b, int n);
long* matMulVec(long** a, long* b, int n);
int compareNodes(const void* a, const void* b);
void build_pow2_function(int n);
void build_fac_function(int n);
void build_ifac_function(int n);
void build_sieve_function(int n);
void build_mobius_function(int n);
int* build_z_function(char* s);
void fill(char* a, int lo, int c, char letter);
int cntBitOne(char* s);
int compareMarks(const void* a, const void* b);
int coLinear(int* p, int* q, int* r);
int compareInts(const void* a, const void* b);
void reverse(char* a, int i, int j);
void swap(char* a, int i, int j);
int gcd(int x, int y);
long gcdLong(long x, long y);
int max(int a, int b);
long maxLong(long a, long b);
int min(int a, int b);
long minLong(long a, long b);

int main() {
    int nt;
    scanf("%d", &nt);
    for (int it = 0; it < nt; it++) {
        int n, m, s, t;
        scanf("%d %d %d %d", &n, &m, &s, &t);
        int* sz = (int*)malloc((n+1) * sizeof(int));
        int** nbs = (int**)malloc((n+1) * sizeof(int*));
        int** es = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            es[i] = (int*)malloc(2 * sizeof(int));
            scanf("%d %d", &es[i][0], &es[i][1]);
            sz[es[i][0]]++;
            sz[es[i][1]]++;
        }
        for (int i = 1; i <= n; i++) {
            nbs[i] = (int*)malloc(sz[i] * sizeof(int));
            sz[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int p = es[i][0], q = es[i][1];
            nbs[p][sz[p]++] = q;
            nbs[q][sz[q]++] = p;
        }
        int* subTreeSize = (int*)malloc((n+1) * sizeof(int));
        int* visited = (int*)malloc((n+1) * sizeof(int));
        long l = dfs(s, 0, s, t, nbs, subTreeSize, visited);
        for (int i = 1; i <= n; i++) {
            subTreeSize[i] = 0;
            visited[i] = 0;
        }
        long r = dfs(t, 0, t, s, nbs, subTreeSize, visited);
        long tot = (n - 1 - l) * (n - 1 - r);
        printf("%ld\n", tot);
    }
    return 0;
}

void dfs(int root, int par, int chosenRoot, int special, int** nbs, int* size, int* visited) {
    int sz = 1;
    visited[root] = 1;
    if (nbs[root][0] == 1 && par > 0) {
        size[root] = 1;
        if (root == special) return 1;
        return 0;
    }
    int ans = root == special ? 1 : 0;
    for (int i = 0; i < nbs[root][0]; i++) {
        int next = nbs[root][i];
        if (next != par && !visited[next]) {
            long sub = dfs(next, root, chosenRoot, special, nbs, size, visited);
            if (root == chosenRoot) {
                if (sub > 0) return sub;
            } else {
                ans += sub;
            }
            sz += size[next];
        }
    }
    size[root] = sz;
    if (ans == 0) return 0;
    return sz;
}

long** matIdentity(int n) {
    long** a = (long**)malloc(n * sizeof(long*));
    for (int i = 0; i < n; i++) {
        a[i] = (long*)malloc(n * sizeof(long));
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
        a[i][i] = 1;
    }
    return a;
}

long** matPow(long** mat0, long p) {
    int n = sizeof(mat0) / sizeof(mat0[0]);
    long** ans = matIdentity(n);
    long** mat = matCopy(mat0, n);
    while (p > 0) {
        if (p % 2 == 1) {
            ans = matMul(ans, mat, n);
        }
        p /= 2;
        mat = matMul(mat, mat, n);
    }
    return ans;
}

long** matCopy(long** a, int n) {
    long** b = (long**)malloc(n * sizeof(long*));
    for (int i = 0; i < n; i++) {
        b[i] = (long*)malloc(n * sizeof(long));
        for (int j = 0; j < n; j++) {
            b[i][j] = a[i][j];
        }
    }
    return b;
}

long** matMul(long** a, long** b, int n) {
    long** c = (long**)malloc(n * sizeof(long*));
    for (int i = 0; i < n; i++) {
        c[i] = (long*)malloc(n * sizeof(long));
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

long* matMulVec(long** a, long* b, int n) {
    long* c = (long*)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        c[i] = 0;
        for (int j = 0; j < n; j++) {
            c[i] = (c[i] + a[i][j] * b[j]) % MOD;
        }
    }
    return c;
}

int compareNodes(const void* a, const void* b) {
    int lo1 = ((Node*)a)->lo;
    int lo2 = ((Node*)b)->lo;
    if (lo1 != lo2) return lo1 - lo2;
    return ((Node*)a)->hi - ((Node*)b)->hi;
}

void build_pow2_function(int n) {
    pow2 = (int*)malloc((n+1) * sizeof(int));
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) pow2[i] = (int)(1L * pow2[i-1] * 2 % MOD);
}

void build_fac_function(int n) {
    fac = (int*)malloc((n+1) * sizeof(int));
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (int)(1L * fac[i-1] * i % MOD);
}

void build_ifac_function(int n) {
    ifac = (int*)malloc((n+1) * sizeof(int));
    ifac[0] = 1;
    for (int i = 1; i <= n; i++) ifac[i] = (int)(1L * ifac[i-1] * inv(i) % MOD);
}

void build_sieve_function(int n) {
    sieve = (int*)malloc((n+1) * sizeof(int));
    for (int i = 2; i <= n; i++) sieve[i] = i;
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            for (long j = 1L * i * i; j <= n; j += i) sieve[(int)j] = i;
        }
    }
}

void build_mobius_function(int n) {
    mobius = (int*)malloc((n+1) * sizeof(int));
    sieve = (int*)malloc((n+1) * sizeof(int));
    factors = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 2; i <= n; i++) sieve[i] = i;
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            mobius[i] = -1;
            for (long j = 1L * i * i; j <= n; j += i) sieve[(int)j] = i;
        }
    }
    for (int i = 6; i <= n; i++) {
        if (sieve[i] != i) {
            int pre = i / sieve[i];
            if (pre % sieve[i] != 0) mobius[i] = -mobius[pre];
        }
    }
    int* sz = (int*)malloc((n+1) * sizeof(int));
    long tot = 0;
    for (int i = 2; i <= n; i++) {
        if (mobius[i] != 0) {
            for (int j = i * 2; j <= n; j += i) {
                sz[j]++;
                tot++;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        factors[i] = (int*)malloc(sz[i] * sizeof(int));
        sz[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        if (mobius[i] != 0) {
            for (int j = i * 2; j <= n; j += i) {
                factors[j][sz[j]++] = i;
            }
        }
    }
}

int* build_z_function(char* s) {
    int n = sizeof(s) / sizeof(s[0]);
    int* zfun = (int*)malloc(n * sizeof(int));
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            zfun[i] = min(zfun[i-l], r - i + 1);
        }
        while (i + zfun[i] < n && s[i + zfun[i]] == s[zfun[i]]) {
            zfun[i]++;
        }
        if (i + zfun[i] - 1 > r) {
            l = i;
            r = i + zfun[i] - 1;
        }
    }
    if (test) {
        printf("Z-function of %s\n", s);
        for (int i = 0; i < n; i++) printf("%d ", zfun[i]);
        printf("\n");
    }
    return zfun;
}

void fill(char* a, int lo, int c, char letter) {
    for (int i = lo; i < lo + c; i++) a[i] = letter;
}

int cntBitOne(char* s) {
    int c = 0, n = sizeof(s) / sizeof(s[0]);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') c++;
    }
    return c;
}

int compareMarks(const void* a, const void* b) {
    int h1 = ((Mark*)a)->h;
    int h2 = ((Mark*)b)->h;
    if (h1 != h2) return h1 - h2;
    long x1 = ((Mark*)a)->x;
    long x2 = ((Mark*)b)->x;
    if (x1 != x2) return x1 - x2;
    return ((Mark*)a)->type - ((Mark*)b)->type;
}

int coLinear(int* p, int* q, int* r) {
    return 1L * (p[1] - r[1]) * (q[0] - r[0]) == 1L * (q[1] - r[1]) * (p[0] - r[0]);
}

void reverse(char* a, int i, int j) {
    while (i < j) {
        swap(a, i++, j--);
    }
}

void swap(char* a, int i, int j) {
    char t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

long gcdLong(long x, long y) {
    if (y == 0) return x;
    return gcdLong(y, x % y);
}

int max(int a, int b) {
    return a > b ? a : b;
}

long maxLong(long a, long b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

long minLong(long a, long b) {
    return a > b ? b : a;
}
