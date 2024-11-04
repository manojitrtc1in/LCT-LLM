#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 1000

int N;
int A[MAX_N];
int B[MAX_N];
int C[MAX_N];
int arr[MAX_N + 1];
int as;
int r;
int ok[MAX_N + 1];
int dp[MAX_N + 1];
int back[MAX_N + 1];
int cnt;

typedef struct {
    int N;
    int **edge;
    int *es;
    int **cost;
} wgraph;

wgraph g;

void rd(int *x) {
    int k, m = 0;
    *x = 0;
    for (;;) {
        k = getchar();
        if (k == '-') {
            m = 1;
            break;
        }
        if ('0' <= k && k <= '9') {
            *x = k - '0';
            break;
        }
    }
    for (;;) {
        k = getchar();
        if (k < '0' || k > '9') {
            break;
        }
        *x = *x * 10 + k - '0';
    }
    if (m) {
        *x = -(*x);
    }
}

void wt_L(char a) {
    putchar(a);
}

void wt_L(int x) {
    char f[10];
    int m = 0, s = 0;
    if (x < 0) {
        m = 1;
        x = -x;
    }
    while (x) {
        f[s++] = x % 10;
        x /= 10;
    }
    if (!s) {
        f[s++] = 0;
    }
    if (m) {
        putchar('-');
    }
    while (s--) {
        putchar(f[s] + '0');
    }
}

void id1(int ***arr, int x, void ***mem) {
    static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    (**mem) = (void*)(((char*)(**mem)) + skip[((unsigned long long)(**mem)) & 15]);
    (**arr) = (int*)(**mem);
    (**mem) = ((**arr) + x);
}

void id2(int **arr, int x, void **mem) {
    static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    (*mem) = (void*)(((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15]);
    (*arr) = (int*)(*mem);
    (*mem) = ((*arr) + x);
}

void id3(int *arr, int x, void *mem) {
    static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    mem = (void*)(((char*)mem) + skip[((unsigned long long)mem) & 15]);
    arr = (int*)mem;
    mem = (arr + x);
}

void id4(int *arr, int x, void *mem) {
    static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    mem = (void*)(((char*)mem) + skip[((unsigned long long)mem) & 15]);
    arr = (int*)mem;
    mem = (arr + x);
}

void malloc2(int N, void **mem) {
    int i;
    id1(&g.es, N, mem);
    id1(&g.edge, N, mem);
    for (i = 0; i < N; i++) {
        id1(&g.edge[i], g.es[i], mem);
    }
    id1(&g.cost, N, mem);
    for (i = 0; i < N; i++) {
        id1(&g.cost[i], g.es[i], mem);
    }
}

void free2(void *mem) {
    free(g.es);
    free(g.edge);
    free(g.cost);
    free(mem);
}

void walloc(int N, void **mem) {
    id1(&g.es, N, mem);
    id1(&g.edge, N, mem);
    id1(&g.cost, N, mem);
}

void init(int N) {
    int i;
    g.N = N;
    for (i = 0; i < N; i++) {
        g.es[i] = 0;
    }
}

void change(int n, int v) {
    g.cost[n] = v;
}

int pop(void) {
    int res = g.edge[0];
    g.edge = g.edge + 1;
    return res;
}

int dfs2(int n, int b) {
    int i, j, k, res = 1;
    for (i = 0; i < g.es[n]; i++) {
        k = g.edge[n][i];
        if (k == b) {
            continue;
        }
        res += dfs2(k, n);
    }
    return res;
}

void dfs(int n, int b, int d, int m, int dm) {
    int i, j, k;
    for (i = 0; i < g.es[n]; i++) {
        if (n == r && ok[i] == dm) {
            continue;
        }
        k = g.edge[n][i];
        if (k == b) {
            continue;
        }
        cnt++;
        g.cost[n][i] = m * (cnt - d);
        dfs(k, n, cnt, m, dm);
    }
}

int main() {
    int i, j, k, m, p;
    void *wmem = malloc(96000000);
    rd(&N);
    for (i = 0; i < N - 1; i++) {
        rd(&A[i]);
        A[i] += (-1);
        rd(&B[i]);
        B[i] += (-1);
    }
    malloc2(N, &wmem);
    g.N = N;
    for (r = 0; r < N; r++) {
        as = 0;
        for (i = 0; i < g.es[r]; i++) {
            arr[as++] = dfs2(g.edge[r][i], r);
        }
        for (i = 0; i < N + 1; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        for (i = 0; i < as; i++) {
            for (j = N; j >= arr[i]; j--) {
                if (!dp[j] && dp[j - arr[i]]) {
                    dp[j] = 1;
                    back[j] = i;
                }
            }
        }
        for (p = 0; p < N + 1; p++) {
            if (dp[p] && (p + 1) * (N - p) - 1 >= 2 * N * N / 9) {
                break;
            }
        }
        if (p == N + 1) {
            continue;
        }
        k = p;
        while (k) {
            ok[back[k]] = 1;
            k -= arr[back[k]];
        }
        cnt = 0;
        dfs(r, -1, 0, 1, 0);
        cnt = 0;
        dfs(r, -1, 0, p + 1, 1);
        break;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < g.es[i]; j++) {
            k = g.edge[i][j];
            r = g.cost[i][j];
            if (r > 0) {
                wt_L(i + 1);
                wt_L(' ');
                wt_L(k + 1);
                wt_L(' ');
                wt_L(r);
                wt_L('\n');
            }
        }
    }
    free2(wmem);
    free(wmem);
    return 0;
}
