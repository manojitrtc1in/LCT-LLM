#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void *wmem;

void walloc1d(int **arr, int x, void **mem) {
    static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    (*mem) = (void *)(((char *)(*mem)) + skip[((unsigned long long)(*mem)) & 15]);
    (*arr) = (int *)(*mem);
    (*mem) = ((*arr) + x);
}

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

struct DijkstraHeap {
    int *val;
    char *visited;
    int *hp, *place, size;
    void malloc(int N) {
        hp = (int *)malloc(N * sizeof(int));
        place = (int *)malloc(N * sizeof(int));
        visited = (char *)malloc(N * sizeof(char));
        val = (int *)malloc(N * sizeof(int));
    }
    void free() {
        free(hp);
        free(place);
        free(visited);
        free(val);
    }
    void walloc(int N, void **mem) {
        walloc1d(&hp, N, mem);
        walloc1d(&place, N, mem);
        walloc1d(&visited, N, mem);
        walloc1d(&val, N, mem);
    }
    void init(int N) {
        size = 0;
        for (int i = 0; i < N; i++) {
            place[i] = -1;
            visited[i] = 0;
        }
    }
    void up(int n) {
        int m;
        while (n) {
            m = (n - 1) / 2;
            if (val[hp[m]] <= val[hp[n]]) {
                break;
            }
            int temp = hp[m];
            hp[m] = hp[n];
            hp[n] = temp;
            temp = place[hp[m]];
            place[hp[m]] = place[hp[n]];
            place[hp[n]] = temp;
            n = m;
        }
    }
    void down(int n) {
        int m;
        for (;;) {
            m = 2 * n + 1;
            if (m >= size) {
                break;
            }
            if (m + 1 < size && val[hp[m]] > val[hp[m + 1]]) {
                m++;
            }
            if (val[hp[m]] >= val[hp[n]]) {
                break;
            }
            int temp = hp[m];
            hp[m] = hp[n];
            hp[n] = temp;
            temp = place[hp[m]];
            place[hp[m]] = place[hp[n]];
            place[hp[n]] = temp;
            n = m;
        }
    }
    void change(int n, int v) {
        if (visited[n] || (place[n] >= 0 && val[n] <= v)) {
            return;
        }
        val[n] = v;
        if (place[n] == -1) {
            place[n] = size;
            hp[size++] = n;
            up(place[n]);
        } else {
            up(place[n]);
        }
    }
    int pop(void) {
        int res = hp[0];
        place[res] = -1;
        size--;
        if (size) {
            hp[0] = hp[size];
            place[hp[0]] = 0;
            down(0);
        }
        visited[res] = 1;
        return res;
    }
};

struct graph {
    int N, **edge, *es;
    void setEdge(int N__, int M, int A[], int B[], void **mem) {
        N = N__;
        walloc1d(&es, N, mem);
        walloc1d(&edge, N, mem);
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            es[A[i]]++;
            es[B[i]]++;
        }
        for (int i = 0; i < N; i++) {
            walloc1d(&edge[i], es[i], mem);
        }
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            edge[A[i]][es[A[i]]++] = B[i];
            edge[B[i]][es[B[i]]++] = A[i];
        }
    }
    void setDirectEdge(int N__, int M, int A[], int B[], void **mem) {
        N = N__;
        walloc1d(&es, N, mem);
        walloc1d(&edge, N, mem);
        walloc1d(&edge[0], M, mem);
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            es[A[i]]++;
        }
        for (int i = 0; i < N; i++) {
            walloc1d(&edge[i], es[i], mem);
        }
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            edge[A[i]][es[A[i]]++] = B[i];
        }
    }
    graph reverse(void **mem) {
        graph g;
        g.N = N;
        walloc1d(&g.es, N, mem);
        walloc1d(&g.edge, N, mem);
        for (int i = 0; i < N; i++) {
            g.es[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < es[i]; j++) {
                g.es[edge[i][j]]++;
            }
        }
        for (int i = 0; i < N; i++) {
            walloc1d(&g.edge[i], g.es[i]);
        }
        for (int i = 0; i < N; i++) {
            g.es[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < es[i]; j++) {
                int k = edge[i][j];
                g.edge[k][g.es[k]++] = i;
            }
        }
        return g;
    }
    // Other methods omitted for brevity...
};

char memarr[96000000];
int N;
int A[1000];
int B[1000];
int C[1000];
struct wgraph {
    int **cost;
    struct graph g;
    int N, **edge, *es;
    void setEdge(int N__, int M, int A[], int B[], int C[], void **mem) {
        N = N__;
        walloc1d(&es, N, mem);
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            es[A[i]]++;
            es[B[i]]++;
        }
        walloc1d(&edge, N, mem);
        for (int i = 0; i < N; i++) {
            walloc1d(&edge[i], es[i], mem);
        }
        walloc1d(&cost, N, mem);
        for (int i = 0; i < N; i++) {
            walloc1d(&cost[i], es[i], mem);
        }
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            edge[A[i]][es[A[i]]] = B[i];
            edge[B[i]][es[B[i]]++] = A[i];
            cost[A[i]][es[A[i]]++] = C[i];
            cost[B[i]][es[B[i]]++] = C[i];
        }
        g.N = N;
        g.es = es;
        g.edge = edge;
    }
    // Other methods omitted for brevity...
};

int arr[1001];
int as;
int r;
int ok[1001];
int dp[1001];

int dfs2(int n, int b) {
    int res = 1;
    for (int i = 0; i < g.es[n]; i++) {
        int k = g.edge[n][i];
        if (k == b) {
            continue;
        }
        res += dfs2(k, n);
    }
    return res;
}

int cnt;

void dfs(int n, int b, int d, int m, int dm) {
    for (int i = 0; i < g.es[n]; i++) {
        if (n == r && ok[i] == dm) {
            continue;
        }
        int k = g.edge[n][i];
        if (k == b) {
            continue;
        }
        cnt++;
        g.cost[n][i] = m * (cnt - d);
        dfs(k, n, cnt, m, dm);
    }
}

int main() {
    wmem = memarr;
    rd(&N);
    for (int Lj4PdHRW = 0; Lj4PdHRW < (N - 1); Lj4PdHRW++) {
        rd(&A[Lj4PdHRW]);
        A[Lj4PdHRW] += (-1);
        rd(&B[Lj4PdHRW]);
        B[Lj4PdHRW] += (-1);
    }
    struct wgraph g;
    g.setEdge(N, N - 1, A, B, C, &wmem);
    for (r = 0; r < N; r++) {
        as = 0;
        for (int i = 0; i < g.es[r]; i++) {
            arr[as++] = dfs2(g.edge[r][i], r);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < as; i++) {
            for (int j = N; j >= arr[i]; j--) {
                if (!dp[j] && dp[j - arr[i]]) {
                    dp[j] = 1;
                    back[j] = i;
                }
            }
        }
        int p;
        for (p = 0; p < (N + 1); p++) {
            if (dp[p] && (p + 1) * (N - p) - 1 >= 2 * N * N / 9) {
                break;
            }
        }
        if (p == N + 1) {
            continue;
        }
        int k = p;
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < g.es[i]; j++) {
            int k = g.edge[i][j];
            int r = g.cost[i][j];
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
    return 0;
}
