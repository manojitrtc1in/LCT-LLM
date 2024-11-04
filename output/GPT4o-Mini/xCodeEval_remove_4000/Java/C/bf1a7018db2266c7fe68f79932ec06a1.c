#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define WALL -1
#define EMPTY -2
#define VISITED 1
#define FULL 2
#define START 1
#define END 0

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
    int *id2;
    int **timeRange;
    int t;
    int V;
    int root;
} Tree;

typedef struct {
    int *bit;
    int n;
} BIT;

long dfs(int root, int par, int chosenRoot, int special, int **nbs, int *size, int *visited);
void addEdge(Tree *tree, int p, int q);
void dfsEuler(Tree *tree);
void buildTree(Tree *tree, int node, int lo, int hi);
void pushUp(Tree *tree, int node, int lo, int hi);
void pushDown(Tree *tree, int node, int lo, int hi);
int query(Tree *tree, int node, int lo, int hi, int fr, int to);
void rangeUpdate(Tree *tree, int node, int lo, int hi, int fr, int to, int delta);
long pow(long v, long p);
long inv(long v);
void fill(char *a, int lo, int c, char letter);
int gcd(int x, int y);
int max(int a, int b);
int min(int a, int b);
void swap(char *a, int i, int j);
void reverse(char *a, int i, int j);
int abs(int v);
int common(int v);
int id7(int v);
int distM(int x, int y, int xx, int yy);
long f(int x1, int y1, int x2, int y2);
long overlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void fastReader(int *nt, int *n, int *m, int *s, int *t);

int main() {
    int nt, n, m, s, t;
    fastReader(&nt, &n, &m, &s, &t);
    
    for (int it = 0; it < nt; it++) {
        int *sz = (int *)calloc(n + 1, sizeof(int));
        int **nbs = (int **)malloc((n + 1) * sizeof(int *));
        int **es = (int **)malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++) {
            es[i] = (int *)malloc(2 * sizeof(int));
            scanf("%d %d", &es[i][0], &es[i][1]);
            sz[es[i][0]]++;
            sz[es[i][1]]++;
        }
        for (int i = 1; i <= n; i++) {
            nbs[i] = (int *)malloc(sz[i] * sizeof(int));
            sz[i] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            int p = es[i][0], q = es[i][1];
            nbs[p][sz[p]++] = q;
            nbs[q][sz[q]++] = p;
        }
        
        int *id2 = (int *)calloc(n + 1, sizeof(int));
        int *visited = (int *)calloc(n + 1, sizeof(int));
        long l = dfs(s, 0, s, t, nbs, id2, visited);
        
        for (int i = 1; i <= n; i++) {
            id2[i] = 0;
            visited[i] = 0;
        }
        
        long r = dfs(t, 0, t, s, nbs, id2, visited);
        long tot = (n - 1 - l) * (n - 1 - r;
        printf("%ld\n", tot);
        
        for (int i = 0; i < m; i++) {
            free(es[i]);
        }
        free(es);
        free(sz);
        free(visited);
        free(id2);
        free(nbs);
    }
    
    return 0;
}

long dfs(int root, int par, int chosenRoot, int special, int **nbs, int *size, int *visited) {
    int sz = 1;
    visited[root] = 1;
    if (nbs[root][0] == -1 && par > 0) {
        size[root] = 1;
        return (root == special) ? 1 : 0;
    }
    
    int ans = (root == special) ? 1 : 0;
    for (int i = 0; nbs[root][i] != -1; i++) {
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
    return (ans == 0) ? 0 : sz;
}

void fastReader(int *nt, int *n, int *m, int *s, int *t) {
    scanf("%d", nt);
    scanf("%d %d %d %d", n, m, s, t);
}
