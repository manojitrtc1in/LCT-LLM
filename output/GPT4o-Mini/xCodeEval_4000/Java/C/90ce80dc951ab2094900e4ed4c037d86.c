#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 1000000007

typedef struct {
    long w;
    long val;
    int group;
} Item;

typedef struct {
    int t;
    int rev;
    int cap;
    int f;
} Edge;

typedef struct {
    int l, r;
    long sum;
    long cnt;
    struct Seg *left;
    struct Seg *right;
} Seg;

typedef struct {
    int spf;
    int cnt;
} Wrapper;

typedef struct {
    int index;
    int rank;
    int next;
} Suffix;

void msg(const char *s) {
    printf("%s\n", s);
}

int Int() {
    int x;
    scanf("%d", &x);
    return x;
}

long Long() {
    long x;
    scanf("%ld", &x);
    return x;
}

void addEdge(List<Edge> *graph, int s, int t, int cap) {
    graph[s].add(new Edge(t, graph[t].size(), cap));
    graph[t].add(new Edge(s, graph[s].size() - 1, 0));
}

long C(long fact[], int i, int j) {
    if (j > i) return 0;
    if (j == 0) return 1;
    long a = fact[i];
    long b = ((fact[i - j] % MAX) * (fact[j] % MAX)) % MAX;
    long binverse = modInverse(b, MAX);
    return ((a) * (binverse % MAX)) % MAX;
}

void update(Seg *seg, int index, int v) {
    seg->sum += v;
    seg->cnt++;
    if (seg->l == seg->r && seg->l == index) {
        return;
    }
    int mid = seg->l + (seg->r - seg->l) / 2;
    if (index <= mid) {
        if (seg->left == NULL) seg->left = (Seg *)malloc(sizeof(Seg));
        update(seg->left, index, v);
    } else {
        if (seg->right == NULL) seg->right = (Seg *)malloc(sizeof(Seg));
        update(seg->right, index, v);
    }
}

long *query(Seg *seg, int s, int e) {
    if (seg->l == s && seg->r == e) {
        long *result = (long *)malloc(2 * sizeof(long));
        result[0] = seg->sum;
        result[1] = seg->cnt;
        return result;
    }
    int mid = seg->l + (seg->r - seg->l) / 2;
    if (seg->left == NULL) seg->left = (Seg *)malloc(sizeof(Seg));
    if (seg->right == NULL) seg->right = (Seg *)malloc(sizeof(Seg));
    if (e <= mid) {
        return query(seg->left, s, e);
    } else if (s >= mid + 1) {
        return query(seg->right, s, e);
    } else {
        long *A = query(seg->left, s, mid);
        long *B = query(seg->right, mid + 1, e);
        long *result = (long *)malloc(2 * sizeof(long));
        result[0] = A[0] + B[0];
        result[1] = A[1] + B[1];
        free(A);
        free(B);
        return result;
    }
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        int K = Int();
        long F[6];
        for (int i = 0; i < 6; i++) {
            F[i] = Long();
        }

        int q = Int();
        int W = Int();

        // Call the solution function here
        // solution(K, F, W);
    }
    return 0;
}
