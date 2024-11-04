#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX_N 100005

typedef struct {
    int lo, hi;
} Node;

typedef struct {
    int *par;
    int *sz;
    int nGroup;
    int n;
} DSU;

typedef struct {
    int **nbs;
    int *subTreeSize;
    int V;
    int root;
    int t;
} Tree;

typedef struct {
    int *bit;
    int n;
} BIT;

int **nbs;
int *subTreeSize;
int *sz;
int *mobius;
int *sieve;
long long *pow2;

void dfs(int root, int par, int chosenRoot, int special, long long *result);
long long inv(long long v);
long long pow(long long v, long long p);
void build_pow2_function(int n);
void build_sieve_function(int n);
void build_mobius_function(int n);
void add_edge(int p, int q);
void dfs_euler(Tree *tree);
void dfs_tree(Tree *tree, int node);
void range_update(BIT *bit, int fr, int to, int delta);
int range_query_max(BIT *bit, int fr, int to);
int range_query_min(BIT *bit, int fr, int to);
void init_dsu(DSU *dsu, int n);
int find(DSU *dsu, int p);
int add(DSU *dsu, int p, int q);
void init_tree(Tree *tree, int V, int root);
void done_input(Tree *tree);
void free_tree(Tree *tree);
void free_dsu(DSU *dsu);
void free_bit(BIT *bit);

int main() {
    int nt;
    scanf("%d", &nt);
    
    while (nt--) {
        int n, m, s, t;
        scanf("%d %d %d %d", &n, &m, &s, &t);
        
        nbs = (int **)malloc((n + 1) * sizeof(int *));
        sz = (int *)calloc(n + 1, sizeof(int));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            sz[u]++;
            sz[v]++;
        }
        
        for (int i = 1; i <= n; i++) {
            nbs[i] = (int *)malloc(sz[i] * sizeof(int));
            sz[i] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            nbs[u][sz[u]++] = v;
            nbs[v][sz[v]++] = u;
        }
        
        long long l = 0, r = 0;
        dfs(s, 0, s, t, &l);
        dfs(t, 0, t, s, &r);
        
        long long tot = (n - 1 - l) * (n - 1 - r);
        printf("%lld\n", tot);
        
        for (int i = 1; i <= n; i++) {
            free(nbs[i]);
        }
        free(nbs);
        free(sz);
    }
    
    return 0;
}

void dfs(int root, int par, int chosenRoot, int special, long long *result) {
    int sz = 1;
    if (nbs[root][0] == -1 && par > 0) {
        *result += (root == special) ? 1 : 0;
        return;
    }
    
    long long ans = (root == special) ? 1 : 0;
    for (int i = 0; i < sz[root]; i++) {
        int next = nbs[root][i];
        if (next != par) {
            long long sub = dfs(next, root, chosenRoot, special, result);
            if (root == chosenRoot) {
                if (sub > 0) return sub;
            } else {
                ans += sub;
            }
            sz += sub;
        }
    }
    return sz;
}

long long inv(long long v) {
    return pow(v, MOD - 2);
}

long long pow(long long v, long long p) {
    long long ans = 1;
    while (p > 0) {
        if (p % 2 == 1)
            ans = (ans * v) % MOD;
        v = (v * v) % MOD;
        p /= 2;
    }
    return ans;
}

void build_pow2_function(int n) {
    pow2 = (long long *)malloc((n + 1) * sizeof(long long));
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
}

void build_sieve_function(int n) {
    sieve = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 2; i <= n; i++)
        sieve[i] = i;
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            for (long long j = 1LL * i * i; j <= n; j += i)
                sieve[j] = i;
        }
    }
}

void build_mobius_function(int n) {
    mobius = (int *)malloc((n + 1) * sizeof(int));
    sieve = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 2; i <= n; i++)
        sieve[i] = i;
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            mobius[i] = -1;
            for (long long j = 1LL * i * i; j <= n; j += i)
                sieve[j] = i;
        }
    }
    for (int i = 6; i <= n; i++) {
        if (sieve[i] != i) {
            int pre = i / sieve[i];
            if (pre % sieve[i] != 0)
                mobius[i] = -mobius[pre];
        }
    }
}

void init_dsu(DSU *dsu, int n) {
    dsu->n = n;
    dsu->par = (int *)malloc(n * sizeof(int));
    dsu->sz = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dsu->par[i] = i;
        dsu->sz[i] = 1;
    }
    dsu->nGroup = n;
}

int find(DSU *dsu, int p) {
    int r = p;
    while (dsu->par[r] != r) r = dsu->par[r];
    while (r != p) {
        int t = dsu->par[p];
        dsu->par[p] = r;
        p = t;
    }
    return r;
}

int add(DSU *dsu, int p, int q) {
    int rp = find(dsu, p);
    int rq = find(dsu, q);
    if (rq == rp) return 0;
    
    if (dsu->sz[rp] <= dsu->sz[rq]) {
        dsu->sz[rq] += dsu->sz[rp];
        dsu->par[rp] = rq;
    } else {
        dsu->sz[rp] += dsu->sz[rq];
        dsu->par[rq] = rp;
    }
    dsu->nGroup--;
    return 1;
}

void init_tree(Tree *tree, int V, int root) {
    tree->V = V;
    tree->root = root;
    tree->nbs = (int **)malloc(V * sizeof(int *));
    tree->subTreeSize = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        tree->nbs[i] = (int *)malloc(V * sizeof(int));
}

void done_input(Tree *tree) {
    dfs_euler(tree);
}

void free_tree(Tree *tree) {
    for (int i = 0; i < tree->V; i++) {
        free(tree->nbs[i]);
    }
    free(tree->nbs);
    free(tree->subTreeSize);
}

void free_dsu(DSU *dsu) {
    free(dsu->par);
    free(dsu->sz);
}

void free_bit(BIT *bit) {
    free(bit->bit);
}

void add_edge(int p, int q) {
    nbs[p][sz[p]++] = q;
    nbs[q][sz[q]++] = p;
}

void dfs_euler(Tree *tree) {
    tree->t = 1;
    dfs_tree(tree, tree->root);
}

void dfs_tree(Tree *tree, int node) {
    tree->subTreeSize[node] = tree->t;
    for (int i = 0; i < tree->nbs[node][0]; i++) {
        int next = tree->nbs[node][i];
        if (tree->subTreeSize[next] == 0) {
            tree->t++;
            dfs_tree(tree, next);
        }
    }
    tree->subTreeSize[node] = tree->t - tree->subTreeSize[node] + 1;
}

void range_update(BIT *bit, int fr, int to, int delta) {
    for (; fr <= bit->n; fr += (fr & (-fr)))
        bit->bit[fr] += delta;
}

int range_query_max(BIT *bit, int fr, int to) {
    int max = 0;
    for (; to > 0; to -= (to & (-to)))
        max = (max > bit->bit[to]) ? max : bit->bit[to];
    return max;
}

int range_query_min(BIT *bit, int fr, int to) {
    int min = INT_MAX;
    for (; to > 0; to -= (to & (-to)))
        min = (min < bit->bit[to]) ? min : bit->bit[to];
    return min;
}
