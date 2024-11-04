#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 998244353
#define INF 10000000000
#define MAXN 1000001

typedef struct {
    double x, y;
} Point;

typedef struct {
    double a, b, c;
} Line;

typedef struct {
    Point *g;
    int size;
} Polygon;

typedef struct {
    int *p;
    int *size;
    int n;
} UnionFind;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

UnionFind* createUnionFind(int n) {
    UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));
    uf->p = (int *)malloc(n * sizeof(int));
    uf->size = (int *)malloc(n * sizeof(int));
    uf->n = n;
    for (int i = 0; i < n; i++) {
        uf->p[i] = i;
        uf->size[i] = 1;
    }
    return uf;
}

int findSet(UnionFind *uf, int v) {
    if (v == uf->p[v]) return v;
    return uf->p[v] = findSet(uf, uf->p[v]);
}

void combine(UnionFind *uf, int a, int b) {
    a = findSet(uf, a);
    b = findSet(uf, b);
    if (a == b) return;
    if (uf->size[a] > uf->size[b]) {
        uf->p[b] = a;
        uf->size[a] += uf->size[b];
    } else {
        uf->p[a] = b;
        uf->size[b] += uf->size[a];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, d;
        scanf("%d %d %d", &n, &k, &d);
        int *a = (int *)malloc(n * sizeof(int));
        int *occ = (int *)calloc(n + 1, sizeof(int));
        int *hm = (int *)malloc(1000001 * sizeof(int));
        memset(hm, -1, 1000001 * sizeof(int));
        int id = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (hm[a[i]] == -1) {
                hm[a[i]] = id++;
            }
            a[i] = hm[a[i]];
        }

        int ans = 0;
        for (int i = 0; i < d; i++) {
            occ[a[i]]++;
            if (occ[a[i]] == 1) ans++;
        }

        int ansl = ans;
        for (int i = d; i < n; i++) {
            int ans1 = ansl;
            occ[a[i]]++;
            if (occ[a[i]] == 1) ans1++;
            occ[a[i - d]]--;
            if (occ[a[i - d]] == 0) ans1--;
            ans = fmin(ans, ans1);
            ansl = ans1;
        }

        printf("%d\n", ans);
        free(a);
        free(occ);
        free(hm);
    }
    return 0;
}
