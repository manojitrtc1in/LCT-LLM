#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define GIGAMOD 1000000007

typedef struct {
    long *array;
    int size;
} FenwickTree;

typedef struct {
    long *euler;
    int *first;
    int *height;
    bool *visited;
    int *segtree;
    int n;
} LCA;

typedef struct {
    int *adj;
    int E;
    int V;
} UGraph;

void initFenwickTree(FenwickTree *ft, int size) {
    ft->array = (long *)calloc(size + 1, sizeof(long));
    ft->size = size;
}

long rsq(FenwickTree *ft, int ind) {
    long sum = 0;
    while (ind > 0) {
        sum += ft->array[ind];
        ind -= ind & (-ind);
    }
    return sum;
}

void update(FenwickTree *ft, int ind, long value) {
    while (ind < ft->size + 1) {
        ft->array[ind] += value;
        ind += ind & (-ind);
    }
}

void initUGraph(UGraph *g, int V) {
    g->adj = (int *)calloc(V, sizeof(int));
    g->E = 0;
    g->V = V;
}

void addEdge(UGraph *g, int from, int to) {
    g->E++;
    // Add edge logic here (e.g., using adjacency list)
}

void initLCA(LCA *lca, UGraph *ug, int root) {
    lca->n = ug->V;
    lca->height = (int *)calloc(lca->n, sizeof(int));
    lca->first = (int *)calloc(lca->n, sizeof(int));
    lca->euler = (long *)malloc(sizeof(long) * lca->n);
    lca->visited = (bool *)calloc(lca->n, sizeof(bool));
    // DFS logic to fill euler, height, and first
}

int query(LCA *lca, int L, int R) {
    // Query logic for LCA
    return -1; // Placeholder
}

int main() {
    int t = 1;
    for (int tc = 0; tc < t; tc++) {
        int n;
        long mod;
        scanf("%d %ld", &n, &mod);

        long *dp = (long *)calloc(n + 1, sizeof(long));
        dp[n] = 1;

        for (int i = n - 1; i > 0; i--) {
            dp[i] += dp[i + 1];
            dp[i] %= mod;

            for (long div = 1; div * i <= n; div++) {
                int lb = (int)(div * i);
                int ub = (int)fmin((div * (i + 1) - 1), n);
                long segSum = dp[lb];
                if (ub + 1 <= n)
                    segSum -= dp[ub + 1];
                dp[i] += segSum;
                dp[i] %= mod;
            }

            dp[i] += dp[i + 1];
            dp[i] %= mod;
        }

        printf("%ld\n", (dp[1] - dp[2] + mod) % mod);
    }

    return 0;
}
