#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 1000

int N;
int A[MAX_N];
int B[MAX_N];
int C[MAX_N];

typedef struct {
    int N;
    int **edge;
    int *es;
} Graph;

typedef struct {
    int *val;
    char *visited;
    int *hp;
    int *place;
    int size;
} DijkstraHeap;

typedef struct {
    int N;
    int **cost;
    Graph g;
} WeightedGraph;

char memarr[96000000];
void *wmem = memarr;

void walloc1d(int **arr, int x, void **mem) {
    static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    (*mem) = (void*)(((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15]);
    (*arr) = (int*)(*mem);
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

template<class S, class T> inline S chmin(S *a, T b) {
    if (*a > b) {
        *a = b;
    }
    return *a;
}

void malloc1d(int **arr, int N, void **mem) {
    *arr = (int*)malloc(N * sizeof(int));
    *mem = (void*)(((char*)(*mem)) + N * sizeof(int));
}

void free1d(void *arr) {
    free(arr);
}

void wgraph_setEdge(WeightedGraph *g, int N__, int M, int A[], int B[], int C[], void **mem) {
    int i;
    g->N = N__;
    walloc1d(&g->es, g->N, mem);
    for (i = 0; i < g->N; i++) {
        g->es[i] = 0;
    }
    walloc1d(&g->edge, g->N, mem);
    for (i = 0; i < g->N; i++) {
        walloc1d(&g->edge[i], g->es[i], mem);
    }
    walloc1d(&g->cost, g->N, mem);
    for (i = 0; i < g->N; i++) {
        walloc1d(&g->cost[i], g->es[i], mem);
    }
    for (i = 0; i < M; i++) {
        g->es[A[i]]++;
        g->es[B[i]]++;
    }
    for (i = 0; i < g->N; i++) {
        g->es[i] = 0;
    }
    for (i = 0; i < M; i++) {
        g->edge[A[i]][g->es[A[i]]] = B[i];
        g->cost[A[i]][g->es[A[i]]++] = C[i];
        g->edge[B[i]][g->es[B[i]]] = A[i];
        g->cost[B[i]][g->es[B[i]]++] = C[i];
    }
    g->g.N = g->N;
    g->g.es = g->es;
    g->g.edge = g->edge;
}

void wgraph_setDirectEdge(WeightedGraph *g, int N__, int M, int A[], int B[], int C[], void **mem) {
    int i;
    g->N = N__;
    walloc1d(&g->es, g->N, mem);
    for (i = 0; i < g->N; i++) {
        g->es[i] = 0;
    }
    walloc1d(&g->edge, g->N, mem);
    for (i = 0; i < g->N; i++) {
        walloc1d(&g->edge[i], g->es[i], mem);
    }
    walloc1d(&g->cost, g->N, mem);
    for (i = 0; i < g->N; i++) {
        walloc1d(&g->cost[i], g->es[i], mem);
    }
    for (i = 0; i < M; i++) {
        g->es[A[i]]++;
    }
    for (i = 0; i < g->N; i++) {
        g->es[i] = 0;
    }
    for (i = 0; i < M; i++) {
        g->edge[A[i]][g->es[A[i]]] = B[i];
        g->cost[A[i]][g->es[A[i]]++] = C[i];
    }
    g->g.N = g->N;
    g->g.es = g->es;
    g->g.edge = g->edge;
}

void dijkstraHeap_malloc(DijkstraHeap *hp, int N, void **mem) {
    malloc1d(&hp->hp, N, mem);
    malloc1d(&hp->place, N, mem);
    malloc1d(&hp->visited, N, mem);
    malloc1d(&hp->val, N, mem);
}

void dijkstraHeap_free(DijkstraHeap *hp) {
    free1d(hp->hp);
    free1d(hp->place);
    free1d(hp->visited);
    free1d(hp->val);
}

void dijkstraHeap_walloc(DijkstraHeap *hp, int N, void **mem) {
    walloc1d(&hp->hp, N, mem);
    walloc1d(&hp->place, N, mem);
    walloc1d(&hp->visited, N, mem);
    walloc1d(&hp->val, N, mem);
}

void dijkstraHeap_init(DijkstraHeap *hp, int N) {
    int i;
    hp->size = 0;
    for (i = 0; i < N; i++) {
        hp->place[i] = -1;
    }
    for (i = 0; i < N; i++) {
        hp->visited[i] = 0;
    }
}

void dijkstraHeap_up(DijkstraHeap *hp, int n) {
    int m;
    while (n) {
        m = (n - 1) / 2;
        if (hp->val[hp->hp[m]] <= hp->val[hp->hp[n]]) {
            break;
        }
        int temp = hp->hp[m];
        hp->hp[m] = hp->hp[n];
        hp->hp[n] = temp;
        hp->place[hp->hp[m]] = m;
        hp->place[hp->hp[n]] = n;
        n = m;
    }
}

void dijkstraHeap_down(DijkstraHeap *hp, int n) {
    int m;
    for (;;) {
        m = 2 * n + 1;
        if (m >= hp->size) {
            break;
        }
        if (m + 1 < hp->size && hp->val[hp->hp[m]] > hp->val[hp->hp[m + 1]]) {
            m++;
        }
        if (hp->val[hp->hp[m]] >= hp->val[hp->hp[n]]) {
            break;
        }
        int temp = hp->hp[m];
        hp->hp[m] = hp->hp[n];
        hp->hp[n] = temp;
        hp->place[hp->hp[m]] = m;
        hp->place[hp->hp[n]] = n;
        n = m;
    }
}

void dijkstraHeap_change(DijkstraHeap *hp, int n, int v) {
    if (hp->visited[n] || (hp->place[n] >= 0 && hp->val[n] <= v)) {
        return;
    }
    hp->val[n] = v;
    if (hp->place[n] == -1) {
        hp->place[n] = hp->size;
        hp->hp[hp->size++] = n;
        dijkstraHeap_up(hp, hp->place[n]);
    } else {
        dijkstraHeap_up(hp, hp->place[n]);
    }
}

int dijkstraHeap_pop(DijkstraHeap *hp) {
    int res = hp->hp[0];
    hp->place[res] = -1;
    hp->size--;
    if (hp->size) {
        hp->hp[0] = hp->hp[hp->size];
        hp->place[hp->hp[0]] = 0;
        dijkstraHeap_down(hp, 0);
    }
    hp->visited[res] = 1;
    return res;
}

void graph_setEdge(Graph *g, int N__, int M, int A[], int B[], void **mem) {
    int i;
    g->N = N__;
    walloc1d(&g->es, g->N, mem);
    for (i = 0; i < g->N; i++) {
        g->es[i] = 0;
    }
    walloc1d(&g->edge, g->N, mem);
    for (i = 0; i < g->N; i++) {
        walloc1d(&g->edge[i], g->es[i], mem);
    }
    for (i = 0; i < M; i++) {
        g->es[A[i]]++;
        g->es[B[i]]++;
    }
    for (i = 0; i < g->N; i++) {
        g->es[i] = 0;
    }
    for (i = 0; i < M; i++) {
        g->edge[A[i]][g->es[A[i]]++] = B[i];
        g->edge[B[i]][g->es[B[i]]++] = A[i];
    }
}

Graph graph_reverse(Graph *g, void **mem) {
    Graph rev;
    int i, j, k;
    rev.N = g->N;
    walloc1d(&rev.es, rev.N, mem);
    walloc1d(&rev.edge, rev.N, mem);
    for (i = 0; i < rev.N; i++) {
        rev.es[i] = 0;
    }
    for (i = 0; i < rev.N; i++) {
        for (j = 0; j < g->es[i]; j++) {
            rev.es[g->edge[i][j]]++;
        }
    }
    for (i = 0; i < rev.N; i++) {
        walloc1d(&rev.edge[i], rev.es[i]);
    }
    for (i = 0; i < rev.N; i++) {
        rev.es[i] = 0;
    }
    for (i = 0; i < rev.N; i++) {
        for (j = 0; j < g->es[i]; j++) {
            k = g->edge[i][j];
            rev.edge[k][rev.es[k]++] = i;
        }
    }
    return rev;
}

void graph_reduce(Graph *g, int tn, int ind[], int self_e, int dep_e, void **mem) {
    Graph red;
    int M = 0, i, j, k, x, y;
    int *A;
    for (i = 0; i < g->N; i++) {
        M += g->es[i];
    }
    A = (int*)((int*)((int**)(*mem) + tn) + tn + M);
    M = 0;
    for (i = 0; i < g->N; i++) {
        x = ind[i];
        if (x < 0) {
            continue;
        }
        for (j = 0; j < g->es[i]; j++) {
            y = ind[g->edge[i][j]];
            if (y < 0) {
                continue;
            }
            if (self_e == 0 && x == y) {
                continue;
            }
            A[M++] = x;
            A[M++] = y;
        }
    }
    if (dep_e == 0) {
        for (i = 0; i < M; i += 2) {
            for (j = i + 2; j < M; j += 2) {
                if (A[i] == A[j] && A[i + 1] == A[j + 1]) {
                    A[j] = -1;
                    A[j + 1] = -1;
                }
            }
        }
        k = 0;
        for (i = 0; i < M; i += 2) {
            if (A[i] != -1 && A[i + 1] != -1) {
                A[k++] = A[i];
                A[k++] = A[i + 1];
            }
        }
        M = k;
    }
    g->N = tn;
    g->es = (int*)(*mem);
    g->edge = (int**)(g->es + tn);
    g->edge[0] = (int*)(g->edge + tn);
    for (i = 0; i < g->N; i++) {
        g->es[i] = 0;
    }
    for (i = 0; i < M; i += 2) {
        g->es[A[i]]++;
    }
    for (i = 0; i < g->N; i++) {
        g->es[i] = 0;
    }
    for (i = 0; i < M; i += 2) {
        g->edge[A[i]][g->es[A[i]]++] = A[i + 1];
    }
    *mem = g->edge[tn - 1] + g->es[tn - 1];
}

void graph_getDist(Graph *g, int root, int res[], void *mem) {
    int i, j, k, *q, s, z;
    walloc1d(&q, g->N, &mem);
    for (i = 0; i < g->N; i++) {
        res[i] = -1;
    }
    res[root] = 0;
    s = 0;
    z = 1;
    q[0] = root;
    while (z) {
        i = q[s++];
        z--;
        for (j = 0; j < g->es[i]; j++) {
            k = g->edge[i][j];
            if (res[k] >= 0) {
                continue;
            }
            res[k] = res[i] + 1;
            q[s + z++] = k;
        }
    }
}

int graph_sccDFS(Graph *g, int num[], int st, int mx) {
    int i, j;
    num[st] = -2;
    for (i = 0; i < g->es[st]; i++) {
        j = g->edge[st][i];
        if (num[j] == -1) {
            mx = graph_sccDFS(g, num, j, mx);
        }
    }
    num[st] = mx;
    return mx + 1;
}

int graph_scc(Graph *g, int res[], void *mem) {
    Graph r;
    int i, j, k, *nrv, *num, ret = 0, *st, st_size;
    r = graph_reverse(g, &mem);
    walloc1d(&st, g->N, &mem);
    walloc1d(&num, g->N, &mem);
    walloc1d(&nrv, g->N, &mem);
    for (i = 0; i < g->N; i++) {
        res[i] = num[i] = -1;
    }
    k = 0;
    for (i = 0; i < g->N; i++) {
        if (num[i] == -1) {
            k = graph_sccDFS(g, num, i, k);
        }
    }
    for (i = 0; i < g->N; i++) {
        nrv[num[i]] = i;
    }
    for (k = g->N - 1; k >= 0; k--) {
        i = nrv[k];
        if (res[i] >= 0) {
            continue;
        }
        res[i] = ret;
        st_size = 0;
        st[st_size++] = i;
        while (st_size) {
            i = st[--st_size];
            for (j = 0; j < r.es[i]; j++) {
                if (res[r.edge[i][j]] == -1) {
                    res[r.edge[i][j]] = ret;
                    st[st_size++] = r.edge[i][j];
                }
            }
        }
        ret++;
    }
    return ret;
}

void graph_bccDFS(Graph *g, int v, int u, int *res, int *rt, int *rts, int *S, int *Ss, int *inS, int *num, int *tm) {
    int i, k;
    num[v] = ++(*tm);
    S[(*Ss)++] = v;
    inS[v] = 1;
    rt[(*rts)++] = v;
    for (i = 0; i < g->es[v]; i++) {
        int w = g->edge[v][i];
        if (!num[w]) {
            graph_bccDFS(g, w, v, res, rt, rts, S, Ss, inS, num, tm);
        } else if (u != w && inS[w]) {
            while (num[rt[(*rts) - 1]] > num[w]) {
                (*rts)--;
            }
        }
    }
    if (v == rt[(*rts) - 1]) {
        k = S[(*Ss) - 1];
        for (;;) {
            int w = S[--(*Ss)];
            inS[w] = 0;
            res[w] = k;
            if (v == w) {
                break;
            }
        }
        (*rts)--;
    }
}

int graph_bcc(Graph *g, int res[], void *mem) {
    int *S, Ss = 0, i, *inS, k, *num, *rt, rts = 0, tm = 0;
    int *arr = (int*)mem;
    for (i = 0; i < g->N; i++) {
        arr[i] = res[i];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + g->N] = g->es[i];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + 2 * g->N] = g->edge[i][0];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + 3 * g->N] = g->edge[i][1];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + 4 * g->N] = g->cost[i][0];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + 5 * g->N] = g->cost[i][1];
    }
    for (i = 0; i < g->N; i++) {
        res[i] = -1;
    }
    k = 0;
    for (i = 0; i < g->N; i++) {
        if (num[i] == -1) {
            graph_bccDFS(g, i, g->N, res, rt, rts, S, Ss, inS, num, tm);
        }
    }
    for (i = 0; i < g->N; i++) {
        arr[i] = res[i];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + g->N] = g->es[i];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + 2 * g->N] = g->edge[i][0];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + 3 * g->N] = g->edge[i][1];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + 4 * g->N] = g->cost[i][0];
    }
    for (i = 0; i < g->N; i++) {
        arr[i + 5 * g->N] = g->cost[i][1];
    }
    for (i = 0; i < g->N; i++) {
        res[i] = arr[i];
    }
    return k + 1;
}

int graph_shortestPath(Graph *g, const int s, const int t, int res[], void *mem) {
    int *b, i, j, k, *q, qe = 0, qs = 0;
    walloc1d(&b, g->N, &mem);
    walloc1d(&q, g->N, &mem);
    for (i = 0; i < g->N; i++) {
        b[i] = -1;
    }
    b[s] = -2;
    q[qe++] = s;
    while (qe > qs) {
        i = q[qs++];
        for (j = 0; j < g->es[i]; j++) {
            k = g->edge[i][j];
            if (b[k] != -1) {
                continue;
            }
            b[k] = i;
            q[qe++] = k;
        }
        if (b[t] != -1) {
            break;
        }
    }
    if (b[t] == -1) {
        return -1;
    }
    k = 0;
    res[k] = i = t;
    while (i != s) {
        res[++k] = (i = b[i]);
    }
    for (i = 0; i <= k / 2; i++) {
        int temp = res[i];
        res[i] = res[k - i];
        res[k - i] = temp;
    }
    return k;
}

int graph_TopologicalSort(Graph *g, int res[], void *mem) {
    int *deg, i, j, k, *q, qe, qs, rs;
    walloc1d(&deg, g->N, &mem);
    walloc1d(&q, g->N, &mem);
    rs = 0;
    for (i = 0; i < g->N; i++) {
        deg[i] = 0;
    }
    for (i = 0; i < g->N; i++) {
        for (j = 0; j < g->es[i]; j++) {
            deg[g->edge[i][j]]++;
        }
    }
    for (i = 0; i < g->N; i++) {
        if (deg[i] == 0) {
            q[qe++] = i;
        }
    }
    while (qs < qe) {
        i = q[qs++];
        res[rs++] = i;
        for (j = 0; j < g->es[i]; j++) {
            k = g->edge[i][j];
            deg[k]--;
            if (deg[k] == 0) {
                q[qe++] = k;
            }
        }
    }
    if (rs == g->N) {
        return 1;
    }
    return 0;
}

template<class S> void weightedGraph_getDist(WeightedGraph *g, int root, S res[], S unreachable, void *mem) {
    DijkstraHeap hp;
    int i, j;
    dijkstraHeap_walloc(&hp, g->N, &mem);
    dijkstraHeap_init(&hp, g->N);
    dijkstraHeap_change(&hp, root, 0);
    while (hp.size) {
        i = dijkstraHeap_pop(&hp);
        for (j = 0; j < g->es[i]; j++) {
            dijkstraHeap_change(&hp, g->edge[i][j], hp.val[i] + g->cost[i][j]);
        }
    }
    for (i = 0; i < g->N; i++) {
        res[i] = (hp.visited[i] ? hp.val[i] : unreachable);
    }
}

template<class S> void weightedGraph_getDistForest(WeightedGraph *g, int root, S res[], S unreachable, void *mem) {
    char *r;
    int i, j, k, *q, s, z;
    walloc1d(&q, g->N, &mem);
    walloc1d(&r, g->N, &mem);
    for (i = 0; i < g->N; i++) {
        r[i] = 0;
    }
    res[root] = 0;
    r[root] = 1;
    s = 0;
    z = 1;
    q[0] = root;
    while (z) {
        i = q[s++];
        z--;
        for (j = 0; j < g->es[i]; j++) {
            k = g->edge[i][j];
            if (r[k]) {
                continue;
            }
            res[k] = res[i] + g->cost[i][j];
            r[k] = 1;
            q[s + z++] = k;
        }
    }
    for (i = 0; i < g->N; i++) {
        if (!r[i]) {
            res[i] = unreachable;
        }
    }
}

template<class S> void weightedGraph_BellmanFord(WeightedGraph *g, int root, S res[], S unreachable, S minusInf, int step, void *mem) {
    S *arr;
    int KL2GvlyY, i, *inf, j, k, *q, qe, qs, t;
    walloc1d(&q, g->N, &mem);
    walloc1d(&inf, g->N, &mem);
    walloc1d(&arr, g->N, &mem);
    for (i = 0; i < g->N; i++) {
        inf[i] = 0;
    }
    for (i = 0; i < g->N; i++) {
        res[i] = arr[i] = INT_MAX;
    }
    res[root] = arr[root] = 0;
    t = step;
    if (t == -1) {
        t = g->N;
    }
    for (KL2GvlyY = 0; KL2GvlyY < t; KL2GvlyY++) {
        for (i = 0; i < g->N; i++) {
            if (res[i] != INT_MAX) {
                for (j = 0; j < g->es[i]; j++) {
                    chmin(&arr[g->edge[i][j]], res[i] + g->cost[i][j]);
                }
            }
        }
        for (i = 0; i < g->N; i++) {
            res[i] = arr[i];
        }
    }
    if (step != -1) {
        for (i = 0; i < g->N; i++) {
            if (res[i] == INT_MAX) {
                res[i] = unreachable;
            }
        }
        return;
    }
    for (i = 0; i < g->N; i++) {
        if (res[i] != INT_MAX) {
            for (j = 0; j < g->es[i]; j++) {
                k = g->edge[i][j];
                if (arr[k] > res[i] + g->cost[i][j]) {
                    inf[k] = 1;
                }
            }
        }
    }
    qs = qe = 0;
    for (i = 0; i < g->N; i++) {
        if (inf[i]) {
            q[qe++] = i;
        }
    }
    while (qs < qe) {
        i = q[qs++];
        for (j = 0; j < g->es[i]; j++) {
            k = g->edge[i][j];
            if (inf[k] == 0) {
                inf[k] = 1;
                q[qe++] = k;
            }
        }
    }
    for (i = 0; i < g->N; i++) {
        if (res[i] == INT_MAX) {
            res[i] = unreachable;
        }
    }
    for (i = 0; i < g->N; i++) {
        if (inf[i] == 1) {
            res[i] = minusInf;
        }
    }
}

int weightedGraph_MST_Prim_cost(WeightedGraph *g, void *mem) {
    DijkstraHeap hp;
    int res = 0;
    int i, j;
    dijkstraHeap_walloc(&hp, g->N, &mem);
    dijkstraHeap_init(&hp, g->N);
    dijkstraHeap_change(&hp, 0, 0);
    while (hp.size) {
        i = dijkstraHeap_pop(&hp);
        res += hp.val[i];
        for (j = 0; j < g->es[i]; j++) {
            dijkstraHeap_change(&hp, g->edge[i][j], g->cost[i][j]);
        }
    }
    return res;
}

int weightedGraph_MST_Prim_cost2(WeightedGraph *g, int *res, void *mem) {
    DijkstraHeap hp;
    int cnt = 0;
    int i, j;
    *res = 0;
    dijkstraHeap_walloc(&hp, g->N, &mem);
    dijkstraHeap_init(&hp, g->N);
    dijkstraHeap_change(&hp, 0, 0);
    while (hp.size) {
        i = dijkstraHeap_pop(&hp);
        *res += hp.val[i];
        cnt++;
        for (j = 0; j < g->es[i]; j++) {
            dijkstraHeap_change(&hp, g->edge[i][j], g->cost[i][j]);
        }
    }
    if (cnt == g->N) {
        return 1;
    }
    return 0;
}

int main() {
    int i, j, k, m, p;
    Graph g;
    WeightedGraph wg;
    int arr[1001];
    int as;
    int r;
    int ok[1001];
    int dp[1001];
    int back[1001];
    int cnt;

    wmem = memarr;
    rd(&N);
    for (i = 0; i < N - 1; i++) {
        rd(&A[i]);
        A[i] += (-1);
        rd(&B[i]);
        B[i] += (-1);
    }
    graph_setEdge(&g, N, N - 1, A, B, &wmem);
    for (r = 0; r < N; r++) {
        as = 0;
        for (i = 0; i < g.es[r]; i++) {
            arr[as++] = graph_sccDFS(&g, g.edge[r][i], r, 0);
        }
        for (i = 0; i <= N; i++) {
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
        for (p = 0; p <= N; p++) {
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
        dfs(&g, r, -1, 0, 1);
        cnt = 0;
        dfs(&g, r, -1, p + 1, 1);
        break;
    }
    for (i = 0; i < g.N; i++) {
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
    return 0;
}
