#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MOD 1000000007

int nt;
int dirs8[8][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}, {1,1},{1,-1},{-1,1},{-1,-1}};
int dirs4[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
int WALL = -1;
int EMPTY = -2;
int VISITED = 1;
int FULL = 2;
int START = 1;
int END = 0;
int fac[MAXN];
int ifac[MAXN];
int rfac[MAXN];
int pow2[MAXN];
int mobius[MAXN];
int sieve[MAXN];
int factors[MAXN][MAXN];

void id1(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (int)(1LL * fac[i-1] * i % MOD);
    }
}

void id9(int n) {
    ifac[0] = 1;
    for (int i = 1; i <= n; i++) {
        ifac[i] = (int)(1LL * ifac[i-1] * inv(i) % MOD);
    }
}

void id3(int n) {
    for (int i = 2; i <= n; i++) {
        sieve[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            for (long long j = 1LL * i * i; j <= n; j += i) {
                sieve[j] = i;
            }
        }
    }
}

void id5(int n) {
    for (int i = 2; i <= n; i++) {
        sieve[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            mobius[i] = -1;
            for (long long j = 1LL * i * i; j <= n; j += i) {
                sieve[j] = i;
            }
        }
    }
    for (int i = 6; i <= n; i++) {
        if (sieve[i] != i) {
            int pre = i / sieve[i];
            if (pre % sieve[i] != 0) {
                mobius[i] = -mobius[pre];
            }
        }
    }
    int sz[MAXN];
    long long tot = 0;
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

long long inv(long long v) {
    return pow(v, MOD-2);
}

long long pow(long long v, long long p) {
    long long ans = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            ans = ans * v % MOD;
        }
        v = v * v % MOD;
        p = p / 2;
    }
    return ans;
}

void dfs(int root, int par, int chosenRoot, int special, int** nbs, int* size, int* visited, long long* l) {
    int sz = 1;
    visited[root] = 1;
    if (nbs[root][0] == 1 && par > 0) {
        size[root] = 1;
        if (root == special) {
            *l = 1;
            return;
        }
        *l = 0;
        return;
    }
    int ans = root == special ? 1 : 0;
    for (int i = 0; i < nbs[root][0]; i++) {
        int next = nbs[root][i+1];
        if (next != par && !visited[next]) {
            long long sub;
            dfs(next, root, chosenRoot, special, nbs, size, visited, &sub);
            if (root == chosenRoot) {
                if (sub > 0) {
                    *l = sub;
                    return;
                }
            } else {
                ans += sub;
            }
            sz += size[next];
        }
    }
    size[root] = sz;
    if (ans == 0) {
        *l = 0;
        return;
    }
    *l = sz;
}

void solve() {
    int n, m, s, t;
    int** sz = (int**)malloc((n+1) * sizeof(int*));
    int** nbs = (int**)malloc((n+1) * sizeof(int*));
    int** es = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        es[i] = (int*)malloc(2 * sizeof(int));
    }
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &es[i][0], &es[i][1]);
        sz[es[i][0]][0]++;
        sz[es[i][1]][0]++;
    }
    for (int i = 1; i <= n; i++) {
        nbs[i] = (int*)malloc(sz[i][0] * sizeof(int));
        sz[i][0] = 0;
    }
    for (int i = 0; i < m; i++) {
        int p = es[i][0], q = es[i][1];
        nbs[p][sz[p][0]++] = q;
        nbs[q][sz[q][0]++] = p;
    }
    int* id2 = (int*)malloc((n+1) * sizeof(int));
    int* visited = (int*)malloc((n+1) * sizeof(int));
    long long l, r;
    dfs(s, 0, s, t, nbs, id2, visited, &l);
    for (int i = 1; i <= n; i++) {
        id2[i] = 0;
        visited[i] = 0;
    }
    dfs(t, 0, t, s, nbs, id2, visited, &r);
    long long tot = (n - 1 - l) * (n - 1 - r);
    printf("%lld\n", tot);
}

int main() {
    scanf("%d", &nt);
    for (int it = 0; it < nt; it++) {
        solve();
    }
    return 0;
}
