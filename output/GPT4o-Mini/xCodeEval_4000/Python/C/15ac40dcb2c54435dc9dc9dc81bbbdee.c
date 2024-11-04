#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

int* divisors(int M, int* size) {
    int* d = (int*)malloc(sizeof(int) * (M + 1));
    *size = 0;
    for (int i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            d[(*size)++] = i;
            if (i * i != M) {
                d[(*size)++] = M / i;
            }
        }
    }
    return d;
}

int popcount(int x) {
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000007f;
}

int* eratosthenes(int n, int* size) {
    int* res = (int*)malloc(sizeof(int) * (n + 1));
    int* prime = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        res[i] = 0;
    }
    *size = 0;
    for (int i = 2; i <= n; i++) {
        if (!res[i]) {
            prime[(*size)++] = i;
            for (int j = 1; j <= n / i; j++) {
                res[i * j] = 1;
            }
        }
    }
    free(res);
    return prime;
}

int* factorization(int n, int* size, int* prime, int prime_size) {
    int* res = (int*)malloc(sizeof(int) * prime_size);
    *size = 0;
    for (int i = 0; i < prime_size; i++) {
        int p = prime[i];
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            res[(*size)++] = p;
        }
    }
    if (n != 1) {
        res[(*size)++] = n;
    }
    return res;
}

int euler_phi(int n) {
    int res = n;
    for (int x = 2; x <= n; x++) {
        if (x * x > n) break;
        if (n % x == 0) {
            res = res / x * (x - 1);
            while (n % x == 0) {
                n /= x;
            }
        }
    }
    if (n != 1) {
        res = res / n * (n - 1);
    }
    return res;
}

int ind(int b, int n) {
    int res = 0;
    while (n % b == 0) {
        res++;
        n /= b;
    }
    return res;
}

int isPrimeMR(int n) {
    int d = n - 1;
    d = d / (d & -d);
    int L[] = {2, 3, 5, 7, 11, 13, 17};
    for (int i = 0; i < 7; i++) {
        int a = L[i];
        int t = d;
        int y = 1;
        for (int j = 0; j < t; j++) {
            y = (y * a) % n;
        }
        if (y == 1) continue;
        while (y != n - 1) {
            y = (y * y) % n;
            if (y == 1 || t == n - 1) return 0;
            t <<= 1;
        }
    }
    return 1;
}

int findFactorRho(int n) {
    int m = 1 << (int)(log(n) / log(2));
    for (int c = 1; c < 99; c++) {
        int y = 2, r = 1, q = 1, g = 1;
        while (g == 1) {
            int x = y;
            for (int i = 0; i < r; i++) {
                y = (y * y + c) % n;
            }
            int k = 0;
            while (k < r && g == 1) {
                int ys = y;
                for (int i = 0; i < m && i < r - k; i++) {
                    y = (y * y + c) % n;
                    q = (q * abs(x - y)) % n;
                }
                g = gcd(q, n);
                k += m;
            }
            r <<= 1;
        }
        if (g == n) {
            g = 1;
            while (g == 1) {
                ys = (ys * ys + c) % n;
                g = gcd(abs(x - ys), n);
            }
        }
        if (g < n) {
            if (isPrimeMR(g)) return g;
            else if (isPrimeMR(n / g)) return n / g;
            return findFactorRho(g);
        }
    }
    return -1;
}

int* primeFactor(int n, int* size) {
    int i = 2;
    int* ret = (int*)malloc(sizeof(int) * n);
    *size = 0;
    int rhoFlg = 0;
    while (i * i <= n) {
        int k = 0;
        while (n % i == 0) {
            n /= i;
            k++;
        }
        if (k) ret[(*size)++] = i;
        i += 1 + i % 2;
        if (i == 101 && n >= (1 << 20)) {
            while (n > 1) {
                if (isPrimeMR(n)) {
                    ret[(*size)++] = n;
                    n = 1;
                } else {
                    rhoFlg = 1;
                    int j = findFactorRho(n);
                    k = 0;
                    while (n % j == 0) {
                        n /= j;
                        k++;
                    }
                    ret[(*size)++] = j;
                }
            }
        }
    }
    if (n > 1) ret[(*size)++] = n;
    if (rhoFlg) {
        // Sort ret if needed
    }
    return ret;
}

int* divisors(int n, int* size) {
    int* res = (int*)malloc(sizeof(int) * (n + 1));
    *size = 1;
    res[0] = 1;
    int* prime = (int*)malloc(sizeof(int) * n);
    int prime_size;
    prime = primeFactor(n, &prime_size);
    for (int i = 0; i < prime_size; i++) {
        int p = prime[i];
        int new_size = *size;
        for (int j = 0; j < new_size; j++) {
            for (int k = 0; k <= prime[p]; k++) {
                res[(*size)++] = res[j] * pow(p, k);
            }
        }
    }
    free(prime);
    return res;
}

int xorfactorial(int num) {
    if (num == 0) return 0;
    else if (num == 1) return 1;
    else if (num == 2) return 3;
    else if (num == 3) return 0;
    else {
        int x = baseorder(num);
        return (1 << x) * ((num - (1 << x) + 1) % 2) + function(num - (1 << x));
    }
}

int* xorconv(int n, int* X, int* Y) {
    if (n == 0) {
        int* res = (int*)malloc(sizeof(int));
        res[0] = (X[0] * Y[0]) % MOD;
        return res;
    }
    int* x = (int*)malloc(sizeof(int) * (1 << (n - 1)));
    int* y = (int*)malloc(sizeof(int) * (1 << (n - 1)));
    int* z = (int*)malloc(sizeof(int) * (1 << (n - 1)));
    int* w = (int*)malloc(sizeof(int) * (1 << (n - 1)));
    for (int i = 0; i < (1 << (n - 1)); i++) {
        x[i] = X[i] + X[i + (1 << (n - 1))];
        y[i] = Y[i] + Y[i + (1 << (n - 1))];
        z[i] = X[i] - X[i + (1 << (n - 1))];
        w[i] = Y[i] - Y[i + (1 << (n - 1))];
    }
    int* res1 = xorconv(n - 1, x, y);
    int* res2 = xorconv(n - 1, z, w);
    int* former = (int*)malloc(sizeof(int) * (1 << (n - 1)));
    int* latter = (int*)malloc(sizeof(int) * (1 << (n - 1)));
    for (int i = 0; i < (1 << (n - 1)); i++) {
        former[i] = (res1[i] + res2[i]) * inv % MOD;
        latter[i] = (res1[i] - res2[i]) * inv % MOD;
    }
    free(x);
    free(y);
    free(z);
    free(w);
    free(res1);
    free(res2);
    return former; // Return combined result
}

void merge_sort(int* A, int* B, int n, int m, int* res) {
    int pos_A = 0, pos_B = 0;
    while (pos_A < n && pos_B < m) {
        if (A[pos_A] < B[pos_B]) {
            res[pos_A + pos_B] = A[pos_A++];
        } else {
            res[pos_A + pos_B] = B[pos_B++];
        }
    }
    while (pos_A < n) {
        res[pos_A + pos_B] = A[pos_A++];
    }
    while (pos_B < m) {
        res[pos_A + pos_B] = B[pos_B++];
    }
}

typedef struct {
    int* _parent;
    int* _size;
    int group;
} UnionFindVerSize;

UnionFindVerSize* createUnionFindVerSize(int N) {
    UnionFindVerSize* uf = (UnionFindVerSize*)malloc(sizeof(UnionFindVerSize));
    uf->_parent = (int*)malloc(sizeof(int) * N);
    uf->_size = (int*)malloc(sizeof(int) * N);
    uf->group = N;
    for (int i = 0; i < N; i++) {
        uf->_parent[i] = i;
        uf->_size[i] = 1;
    }
    return uf;
}

int find_root(UnionFindVerSize* uf, int x) {
    if (uf->_parent[x] == x) return x;
    uf->_parent[x] = find_root(uf, uf->_parent[x]);
    return uf->_parent[x];
}

void unite(UnionFindVerSize* uf, int x, int y) {
    int gx = find_root(uf, x);
    int gy = find_root(uf, y);
    if (gx == gy) return;

    uf->group--;

    if (uf->_size[gx] < uf->_size[gy]) {
        uf->_parent[gx] = gy;
        uf->_size[gy] += uf->_size[gx];
    } else {
        uf->_parent[gy] = gx;
        uf->_size[gx] += uf->_size[gy];
    }
}

int get_size(UnionFindVerSize* uf, int x) {
    return uf->_size[find_root(uf, x)];
}

int is_same_group(UnionFindVerSize* uf, int x, int y) {
    return find_root(uf, x) == find_root(uf, y);
}

typedef struct {
    int* parent;
    int* size;
    int* val;
    int flag;
    int** edge;
} WeightedUnionFind;

WeightedUnionFind* createWeightedUnionFind(int N) {
    WeightedUnionFind* wuf = (WeightedUnionFind*)malloc(sizeof(WeightedUnionFind));
    wuf->parent = (int*)malloc(sizeof(int) * N);
    wuf->size = (int*)malloc(sizeof(int) * N);
    wuf->val = (int*)malloc(sizeof(int) * N);
    wuf->flag = 1;
    wuf->edge = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        wuf->parent[i] = i;
        wuf->size[i] = 1;
        wuf->val[i] = 0;
        wuf->edge[i] = (int*)malloc(sizeof(int) * N);
    }
    return wuf;
}

void dfs(WeightedUnionFind* wuf, int v, int pv) {
    int new_parent = wuf->parent[pv];
    for (int i = 0; i < N; i++) {
        wuf->parent[v] = new_parent;
        for (int nv = 0; nv < N; nv++) {
            if (nv != pv) {
                wuf->val[nv] = wuf->val[v] + wuf->edge[v][nv];
                dfs(wuf, nv, v);
            }
        }
    }
}

void unite_weighted(WeightedUnionFind* wuf, int x, int y, int w) {
    if (!wuf->flag) return;
    if (wuf->parent[x] == wuf->parent[y]) {
        wuf->flag = (wuf->val[x] - wuf->val[y] == w);
        return;
    }

    if (wuf->size[wuf->parent[x]] > wuf->size[wuf->parent[y]]) {
        wuf->edge[x][y] = -w;
        wuf->edge[y][x] = w;
        wuf->size[x] += wuf->size[y];
        wuf->val[y] = wuf->val[x] - w;
        dfs(wuf, y, x);
    } else {
        wuf->edge[x][y] = -w;
        wuf->edge[y][x] = w;
        wuf->size[y] += wuf->size[x];
        wuf->val[x] = wuf->val[y] + w;
        dfs(wuf, x, y);
    }
}

typedef struct {
    int** G;
    int _E;
    int _V;
} Dijkstra;

Dijkstra* createDijkstra(int V) {
    Dijkstra* dijkstra = (Dijkstra*)malloc(sizeof(Dijkstra));
    dijkstra->G = (int**)malloc(sizeof(int*) * V);
    for (int i = 0; i < V; i++) {
        dijkstra->G[i] = (int*)malloc(sizeof(int) * V);
    }
    dijkstra->_E = 0;
    dijkstra->_V = V;
    return dijkstra;
}

void add_edge(Dijkstra* dijkstra, int _from, int _to, int _cost) {
    dijkstra->G[_from][_to] = _cost;
    dijkstra->_E++;
}

int* shortest_path(Dijkstra* dijkstra, int s) {
    int* d = (int*)malloc(sizeof(int) * dijkstra->_V);
    for (int i = 0; i < dijkstra->_V; i++) {
        d[i] = 1000000000000000; // 10^15
    }
    d[s] = 0;
    // Implement priority queue logic here
    return d;
}

int* Z_algorithm(char* s, int* size) {
    int N = strlen(s);
    int* Z_alg = (int*)malloc(sizeof(int) * N);
    Z_alg[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i + j < N && s[j] == s[i + j]) {
            j++;
        }
        Z_alg[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < N && k + Z_alg[k] < j) {
            Z_alg[i + k] = Z_alg[k];
            k++;
        }
        i += k;
        j -= k;
    }
    *size = N;
    return Z_alg;
}

typedef struct {
    int* BIT;
    int num;
    int mod;
} BIT;

BIT* createBIT(int n, int mod) {
    BIT* bit = (BIT*)malloc(sizeof(BIT));
    bit->BIT = (int*)malloc(sizeof(int) * (n + 1));
    bit->num = n;
    bit->mod = mod;
    return bit;
}

int query(BIT* bit, int idx) {
    int res_sum = 0;
    while (idx > 0) {
        res_sum += bit->BIT[idx];
        if (bit->mod) {
            res_sum %= bit->mod;
        }
        idx -= idx & (-idx);
    }
    return res_sum;
}

void update(BIT* bit, int idx, int x) {
    while (idx <= bit->num) {
        bit->BIT[idx] += x;
        if (bit->mod) {
            bit->BIT[idx] %= bit->mod;
        }
        idx += idx & (-idx);
    }
}

typedef struct {
    int n;
    int debug;
    int* _left;
    int* _right;
    int* exist;
} dancinglink;

dancinglink* createDancingLink(int n, int debug) {
    dancinglink* dl = (dancinglink*)malloc(sizeof(dancinglink));
    dl->n = n;
    dl->debug = debug;
    dl->_left = (int*)malloc(sizeof(int) * n);
    dl->_right = (int*)malloc(sizeof(int) * n);
    dl->exist = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        dl->_left[i] = i - 1;
        dl->_right[i] = i + 1;
        dl->exist[i] = 1;
    }
    return dl;
}

void pop(dancinglink* dl, int k) {
    if (dl->debug) {
        // assert(dl->exist[k]);
    }
    int L = dl->_left[k];
    int R = dl->_right[k];
    if (L != -1) {
        if (R != dl->n) {
            dl->_right[L] = R;
            dl->_left[R] = L;
        } else {
            dl->_right[L] = dl->n;
        }
    } else if (R != dl->n) {
        dl->_left[R] = -1;
    }
    dl->exist[k] = 0;
}

int left(dancinglink* dl, int idx, int k) {
    if (dl->debug) {
        // assert(dl->exist[idx]);
    }
    int res = idx;
    while (k) {
        res = dl->_left[res];
        if (res == -1) break;
        k--;
    }
    return res;
}

int right(dancinglink* dl, int idx, int k) {
    if (dl->debug) {
        // assert(dl->exist[idx]);
    }
    int res = idx;
    while (k) {
        res = dl->_right[res];
        if (res == dl->n) break;
        k--;
    }
    return res;
}

typedef struct {
    int* table;
    int (*merge_func)(int, int);
    int ide_ele;
} SparseTable;

SparseTable* createSparseTable(int* A, int n, int (*merge_func)(int, int), int ide_ele) {
    SparseTable* st = (SparseTable*)malloc(sizeof(SparseTable));
    int N = n;
    int m = (int)log2(N) + 1;
    st->table = (int*)malloc(sizeof(int) * N * m);
    st->merge_func = merge_func;
    st->ide_ele = ide_ele;

    for (int i = 0; i < N; i++) {
        st->table[i * m] = A[i];
    }

    for (int j = 1; j < m; j++) {
        for (int i = 0; i < N - (1 << j) + 1; i++) {
            int f = st->table[i * m + (j - 1)];
            int s = st->table[(i + (1 << (j - 1))) * m + (j - 1)];
            st->table[i * m + j] = st->merge_func(f, s);
        }
    }
    return st;
}

int query(SparseTable* st, int s, int t) {
    int b = t - s + 1;
    int m = (int)log2(b);
    return st->merge_func(st->table[s * m + m], st->table[(t - (1 << m) + 1) * m + m]);
}

typedef struct {
    struct node* root;
} BinaryTrie;

typedef struct node {
    struct node* left;
    struct node* right;
    int max;
} node;

BinaryTrie* createBinaryTrie() {
    BinaryTrie* bt = (BinaryTrie*)malloc(sizeof(BinaryTrie));
    bt->root = (node*)malloc(sizeof(node));
    bt->root->max = -10000000000000; // -10^15
    return bt;
}

void append(BinaryTrie* bt, int key, int val) {
    node* pos = bt->root;
    for (int i = 29; i >= 0; i--) {
        pos->max = fmax(pos->max, val);
        if (key >> i & 1) {
            if (pos->right == NULL) {
                pos->right = (node*)malloc(sizeof(node));
                pos->right->max = val;
                pos = pos->right;
            } else {
                pos = pos->right;
            }
        } else {
            if (pos->left == NULL) {
                pos->left = (node*)malloc(sizeof(node));
                pos->left->max = val;
                pos = pos->left;
            } else {
                pos = pos->left;
            }
        }
    }
    pos->max = fmax(pos->max, val);
}

int search(BinaryTrie* bt, int M, int xor) {
    int res = -10000000000000; // -10^15
    node* pos = bt->root;
    for (int i = 29; i >= 0; i--) {
        if (pos == NULL) break;

        if (M >> i & 1) {
            if (xor >> i & 1) {
                if (pos->right) {
                    res = fmax(res, pos->right->max);
                }
                pos = pos->left;
            } else {
                if (pos->left) {
                    res = fmax(res, pos->left->max);
                }
                pos = pos->right;
            }
        } else {
            if (xor >> i & 1) {
                pos = pos->right;
            } else {
                pos = pos->left;
            }
        }
    }

    if (pos) {
        res = fmax(res, pos->max);
    }
    return res;
}

int solveequation(int** edge, int* ans, int n, int m) {
    int* x = (int*)malloc(sizeof(int) * m);
    int* used = (int*)malloc(sizeof(int) * n);
    for (int v = 0; v < n; v++) {
        if (used[v]) continue;
        int y = dfs(v, edge, ans, used, x);
        if (y != 0) {
            return 0;
        }
    }
    return x;

    int dfs(int v, int** edge, int* ans, int* used, int* x) {
        used[v] = 1;
        int r = ans[v];
        for (int i = 0; i < n; i++) {
            if (used[edge[v][i][0]]) continue;
            int y = dfs(edge[v][i][0], edge, ans, used, x);
            if (edge[v][i][1] == -1) {
                x[edge[v][i][2]] = y;
            } else {
                x[edge[v][i][2]] = -y;
            }
            r += y;
        }
        return r;
    }
}

typedef struct {
    int* tree;
    int size;
    int num;
    int (*segfunc)(int, int);
    int ide_ele;
} SegmentTree;

SegmentTree* createSegmentTree(int* init_val, int n, int (*segfunc)(int, int), int ide_ele) {
    SegmentTree* st = (SegmentTree*)malloc(sizeof(SegmentTree));
    st->segfunc = segfunc;
    st->ide_ele = ide_ele;
    st->num = 1 << (int)(log2(n) + 1);
    st->tree = (int*)malloc(sizeof(int) * 2 * st->num);
    st->size = n;
    for (int i = 0; i < n; i++) {
        st->tree[st->num + i] = init_val[i];
    }
    for (int i = st->num - 1; i > 0; i--) {
        st->tree[i] = st->segfunc(st->tree[2 * i], st->tree[2 * i + 1]);
    }
    return st;
}

void update(SegmentTree* st, int k, int x) {
    k += st->num;
    st->tree[k] = x;
    while (k > 1) {
        st->tree[k >> 1] = st->segfunc(st->tree[k], st->tree[k ^ 1]);
        k >>= 1;
    }
}

int query(SegmentTree* st, int l, int r) {
    if (r == st->size) {
        r = st->num;
    }

    int res = st->ide_ele;
    l += st->num;
    r += st->num;
    while (l < r) {
        if (l & 1) {
            res = st->segfunc(res, st->tree[l]);
            l++;
        }
        if (r & 1) {
            res = st->segfunc(res, st->tree[r - 1]);
        }
        l >>= 1;
        r >>= 1;
    }
    return res;
}

int bisect_l(SegmentTree* st, int l, int r, int x) {
    l += st->num;
    r += st->num;
    int Lmin = -1;
    int Rmin = -1;
    while (l < r) {
        if (l & 1) {
            if (st->tree[l] <= x && Lmin == -1) {
                Lmin = l;
            }
            l++;
        }
        if (r & 1) {
            if (st->tree[r - 1] <= x) {
                Rmin = r - 1;
            }
        }
        l >>= 1;
        r >>= 1;
    }

    if (Lmin != -1) {
        int pos = Lmin;
        while (pos < st->num) {
            if (st->tree[2 * pos] <= x) {
                pos = 2 * pos;
            } else {
                pos = 2 * pos + 1;
            }
        }
        return pos - st->num;
    } else if (Rmin != -1) {
        int pos = Rmin;
        while (pos < st->num) {
            if (st->tree[2 * pos] <= x) {
                pos = 2 * pos;
            } else {
                pos = 2 * pos + 1;
            }
        }
        return pos - st->num;
    } else {
        return -1;
    }
}

int main() {
    int n, mod;
    scanf("%d %d", &n, &mod);

    int M = (int)(sqrt(n)) + 10;

    int* dp = (int*)malloc(sizeof(int) * (n + 1));
    int* imos = (int*)malloc(sizeof(int) * (n + 1));
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        imos[i] = (imos[i] + imos[i - 1]) % mod;
        dp[i] += imos[i];
        dp[i] %= mod;

        imos[i + 1] += dp[i];
        imos[i + 1] %= mod;

        for (int j = 2; j <= n; j++) {
            if (i * j > n) {
                break;
            }
            imos[i * j] += dp[i];
            imos[i * j] %= mod;
            if ((i + 1) * j <= n) {
                imos[(i + 1) * j] -= dp[i];
                imos[(i + 1) * j] %= mod;
            }
        }
    }

    int res = dp[n] + imos[n] + imos[n - 1];
    res %= mod;
    printf("%d\n", res);

    free(dp);
    free(imos);
    return 0;
}
