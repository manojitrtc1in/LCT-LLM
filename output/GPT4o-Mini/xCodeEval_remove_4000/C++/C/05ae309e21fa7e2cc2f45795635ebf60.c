#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void *wmem;
int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

void id1(void **arr, int x, void **mem) {
    (*mem) = (void *)(((char *)(*mem)) + skip[((unsigned long long)(*mem)) & 15]);
    (*arr) = (void *)(*mem);
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

void wt_L_int(int x) {
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

template <class S, class T>
S chmin(S *a, T b) {
    if (*a > b) {
        *a = b;
    }
    return *a;
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
        id1((void **)&hp, N, mem);
        id1((void **)&place, N, mem);
        id1((void **)&visited, N, mem);
        id1((void **)&val, N, mem);
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
        id1((void **)&es, N, mem);
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            es[A[i]]++;
            es[B[i]]++;
        }
        id1((void **)&edge, N, mem);
        for (int i = 0; i < N; i++) {
            id1((void **)&edge[i], es[i], mem);
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
        id1((void **)&es, N, mem);
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            es[A[i]]++;
        }
        id1((void **)&edge, N, mem);
        for (int i = 0; i < N; i++) {
            id1((void **)&edge[i], es[i], mem);
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
        id1((void **)&g.es, N, mem);
        id1((void **)&g.edge, N, mem);
        for (int i = 0; i < N; i++) {
            g.es[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < es[i]; j++) {
                g.es[edge[i][j]]++;
            }
        }
        for (int i = 0; i < N; i++) {
            id1((void **)&g.edge[i], g.es[i], mem);
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

    graph reduce(int tn, int ind[], int self_e, int dep_e, void **mem) {
        graph g;
        int M = 0;
        for (int i = 0; i < N; i++) {
            M += es[i];
        }
        pair<int, int> *A = (pair<int, int> *)((int *)((int **) (*mem) + tn) + tn + M);
        M = 0;
        for (int i = 0; i < N; i++) {
            int x = ind[i];
            if (x < 0) {
                continue;
            }
            for (int j = 0; j < es[i]; j++) {
                int y = ind[edge[i][j]];
                if (y < 0) {
                    continue;
                }
                if (self_e == 0 && x == y) {
                    continue;
                }
                A[M++] = make_pair(x, y);
            }
        }
        if (dep_e == 0) {
            sort(A, A + M);
            int k = 0;
            for (int i = 0; i < M; i++) {
                if (k && A[k - 1] == A[i]) {
                    continue;
                }
                A[k++] = A[i];
            }
            M = k;
        }
        g.N = tn;
        g.es = (int *)(*mem);
        g.edge = (int **)(g.es + tn);
        g.edge[0] = (int *)(g.edge + tn);
        for (int i = 0; i < tn; i++) {
            g.es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            g.es[A[i].first]++;
        }
        for (int i = 1; i < tn; i++) {
            g.edge[i] = g.edge[i - 1] + g.es[i - 1];
        }
        *mem = g.edge[tn - 1] + g.es[tn - 1];
        for (int i = 0; i < tn; i++) {
            g.es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            int j = A[i].first;
            int k = A[i].second;
            g.edge[j][g.es[j]++] = k;
        }
        return g;
    }

    void getDist(int root, int res[], void *mem) {
        int i, j, k, *q, s, z;
        id1((void **)&q, N, &mem);
        for (i = 0; i < N; i++) {
            res[i] = -1;
        }
        res[root] = 0;
        s = 0;
        z = 1;
        q[0] = root;
        while (z) {
            i = q[s++];
            z--;
            for (j = 0; j < es[i]; j++) {
                k = edge[i][j];
                if (res[k] >= 0) {
                    continue;
                }
                res[k] = res[i] + 1;
                q[s + z++] = k;
            }
        }
    }

    int sccDFS(int num[], int st, int mx) {
        num[st] = -2;
        for (int i = 0; i < es[st]; i++) {
            int j = edge[st][i];
            if (num[j] == -1) {
                mx = sccDFS(num, j, mx);
            }
        }
        num[st] = mx;
        return mx + 1;
    }

    int scc(int res[], void *mem) {
        graph r;
        int i, j, k, *nrv, *num, ret = 0, *st, st_size;
        r = reverse(&mem);
        id1((void **)&st, N, &mem);
        id1((void **)&num, N, &mem);
        id1((void **)&nrv, N, &mem);
        for (i = 0; i < N; i++) {
            res[i] = num[i] = -1;
        }
        k = 0;
        for (i = 0; i < N; i++) {
            if (num[i] == -1) {
                k = sccDFS(num, i, k);
            }
        }
        for (i = 0; i < N; i++) {
            nrv[num[i]] = i;
        }
        for (k = N - 1; k >= 0; k--) {
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

    void bccDFS(int v, int u, int *res, int *rt, int *rts, int *S, int *Ss, int *inS, int *num, int *tm) {
        num[v] = ++(*tm);
        S[(*Ss)++] = v;
        inS[v] = 1;
        rt[(*rts)++] = v;
        for (int i = 0; i < es[v]; i++) {
            int w = edge[v][i];
            if (!num[w]) {
                bccDFS(w, v, res, rt, rts, S, Ss, inS, num, tm);
            } else if (u != w && inS[w]) {
                while (num[rt[(*rts) - 1]] > num[w]) {
                    (*rts)--;
                }
            }
        }
        if (v == rt[(*rts) - 1]) {
            int k = S[(*Ss) - 1];
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

    int bcc(int res[], void *mem) {
        int *S, Ss = 0, i, *inS, k, *num, *rt, rts = 0, tm = 0;
        pair<int, int> *arr;
        id1((void **)&num, N, &mem);
        id1((void **)&rt, N, &mem);
        id1((void **)&S, N, &mem);
        id1((void **)&inS, N, &mem);
        memset(num, 0, sizeof(int) * N);
        memset(inS, 0, sizeof(int) * N);
        for (i = 0; i < N; i++) {
            if (!num[i]) {
                bccDFS(i, N, res, rt, &rts, S, &Ss, inS, num, &tm);
            }
        }
        arr = (pair<int, int> *)mem;
        for (i = 0; i < N; i++) {
            arr[i].first = res[i];
            arr[i].second = i;
        }
        sort(arr, arr + N);
        k = 0;
        for (i = 0; i < N; i++) {
            if (i && arr[i].first != arr[i - 1].first) {
                k++;
            }
            res[arr[i].second] = k;
        }
        return k + 1;
    }

    int shortestPath(const int s, const int t, int res[], void *mem) {
        int *b, i, j, k, *q, qe = 0, qs = 0;
        id1((void **)&b, N, &mem);
        id1((void **)&q, N, &mem);
        for (i = 0; i < N; i++) {
            b[i] = -1;
        }
        b[s] = -2;
        q[qe++] = s;
        while (qe > qs) {
            i = q[qs++];
            for (j = 0; j < es[i]; j++) {
                k = edge[i][j];
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
        for (int l = 0; l <= k / 2; l++) {
            int temp = res[l];
            res[l] = res[k - l];
            res[k - l] = temp;
        }
        return k;
    }

    int TopologicalSort(int res[], void *mem) {
        int *deg, i, j, k, *q, qe = 0, qs = 0, rs;
        id1((void **)&deg, N, &mem);
        id1((void **)&q, N, &mem);
        rs = 0;
        for (i = 0; i < N; i++) {
            deg[i] = 0;
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < es[i]; j++) {
                deg[edge[i][j]]++;
            }
        }
        for (i = 0; i < N; i++) {
            if (deg[i] == 0) {
                q[qe++] = i;
            }
        }
        while (qs < qe) {
            i = q[qs++];
            res[rs++] = i;
            for (j = 0; j < es[i]; j++) {
                k = edge[i][j];
                deg[k]--;
                if (deg[k] == 0) {
                    q[qe++] = k;
                }
            }
        }
        if (rs == N) {
            return 1;
        }
        return 0;
    }
};

struct wgraph {
    int **cost;
    graph g;
    int N, **edge, *es;

    void setEdge(int N__, int M, int A[], int B[], int C[], void **mem) {
        N = N__;
        id1((void **)&es, N, mem);
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            es[A[i]]++;
            es[B[i]]++;
        }
        id1((void **)&edge, N, mem);
        for (int i = 0; i < N; i++) {
            id1((void **)&edge[i], es[i], mem);
        }
        id1((void **)&cost, N, mem);
        for (int i = 0; i < N; i++) {
            id1((void **)&cost[i], es[i], mem);
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

    void setDirectEdge(int N__, int M, int A[], int B[], int C[], void **mem) {
        N = N__;
        id1((void **)&es, N, mem);
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            es[A[i]]++;
        }
        id1((void **)&edge, N, mem);
        for (int i = 0; i < N; i++) {
            id1((void **)&edge[i], es[i], mem);
        }
        id1((void **)&cost, N, mem);
        for (int i = 0; i < N; i++) {
            id1((void **)&cost[i], es[i], mem);
        }
        for (int i = 0; i < N; i++) {
            es[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            edge[A[i]][es[A[i]]] = B[i];
            cost[A[i]][es[A[i]]++] = C[i];
        }
        g.N = N;
        g.es = es;
        g.edge = edge;
    }

    void getDist(int root, int res[], int unreachable, void *mem) {
        DijkstraHeap hp;
        int i, j;
        hp.walloc(N, &mem);
        hp.init(N);
        hp.change(root, 0);
        while (hp.size) {
            i = hp.pop();
            for (j = 0; j < es[i]; j++) {
                hp.change(edge[i][j], hp.val[i] + cost[i][j]);
            }
        }
        for (i = 0; i < N; i++) {
            res[i] = (hp.visited[i] ? hp.val[i] : unreachable);
        }
    }

    void id4(int root, int res[], int unreachable, void *mem) {
        char *r;
        int i, j, k, *q, s, z;
        id1((void **)&q, N, &mem);
        id1((void **)&r, N, &mem);
        for (i = 0; i < N; i++) {
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
            for (j = 0; j < es[i]; j++) {
                k = edge[i][j];
                if (r[k]) {
                    continue;
                }
                res[k] = res[i] + cost[i][j];
                r[k] = 1;
                q[s + z++] = k;
            }
        }
        for (i = 0; i < N; i++) {
            if (!r[i]) {
                res[i] = unreachable;
            }
        }
    }

    void id2(int root, int res[], int unreachable, int minusInf, int step, void *mem) {
        int *arr;
        int id3, i, *inf, j, k, *q, qe, qs, t;
        id1((void **)&q, N, &mem);
        id1((void **)&inf, N, &mem);
        id1((void **)&arr, N, &mem);
        for (i = 0; i < N; i++) {
            inf[i] = 0;
        }
        for (i = 0; i < N; i++) {
            res[i] = arr[i] = INT_MAX;
        }
        res[root] = arr[root] = 0;
        t = step;
        if (t == -1) {
            t = N;
        }
        for (id3 = 0; id3 < t; id3++) {
            for (i = 0; i < N; i++) {
                if (res[i] != INT_MAX) {
                    for (j = 0; j < es[i]; j++) {
                        chmin(&arr[edge[i][j]], res[i] + cost[i][j]);
                    }
                }
            }
            for (i = 0; i < N; i++) {
                res[i] = arr[i];
            }
        }
        if (step != -1) {
            for (i = 0; i < N; i++) {
                if (res[i] == INT_MAX) {
                    res[i] = unreachable;
                }
            }
            return;
        }
        for (i = 0; i < N; i++) {
            if (res[i] != INT_MAX) {
                for (j = 0; j < es[i]; j++) {
                    k = edge[i][j];
                    if (arr[k] > res[i] + cost[i][j]) {
                        inf[k] = 1;
                    }
                }
            }
        }
        qs = qe = 0;
        for (i = 0; i < N; i++) {
            if (inf[i]) {
                q[qe++] = i;
            }
        }
        while (qs < qe) {
            i = q[qs++];
            for (j = 0; j < es[i]; j++) {
                k = edge[i][j];
                if (inf[k] == 0) {
                    inf[k] = 1;
                    q[qe++] = k;
                }
            }
        }
        for (i = 0; i < N; i++) {
            if (res[i] == INT_MAX) {
                res[i] = unreachable;
            }
        }
        for (i = 0; i < N; i++) {
            if (inf[i] == 1) {
                res[i] = minusInf;
            }
        }
    }

    int MST_Prim_cost(void *mem) {
        DijkstraHeap hp;
        int res = 0;
        int i, j;
        hp.walloc(N, &mem);
        hp.init(N);
        hp.change(0, 0);
        while (hp.size) {
            i = hp.pop();
            res += hp.val[i];
            for (j = 0; j < es[i]; j++) {
                hp.change(edge[i][j], cost[i][j]);
            }
        }
        return res;
    }

    int MST_Prim_cost(int *res, void *mem) {
        DijkstraHeap hp;
        int cnt = 0, i, j;
        *res = 0;
        hp.walloc(N, &mem);
        hp.init(N);
        hp.change(0, 0);
        while (hp.size) {
            i = hp.pop();
            *res += hp.val[i];
            cnt++;
            for (j = 0; j < es[i]; j++) {
                hp.change(edge[i][j], cost[i][j]);
            }
        }
        if (cnt == N) {
            return 1;
        }
        return 0;
    }
};

char memarr[96000000];
int N;
int A[1000];
int B[1000];
int C[1000];
wgraph g;
int arr[1001];
int as;
int r;
int ok[1001];
int dp[1001];

int dfs2(int n, int b) {
    int i, k, res = 1;
    for (i = 0; i < g.es[n]; i++) {
        k = g.edge[n][i];
        if (k == b) {
            continue;
        }
        res += dfs2(k, n);
    }
    return res;
}

int cnt;

void dfs(int n, int b, int d, int m, int dm) {
    int i, k;
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
    wmem = memarr;
    rd(&N);
    for (int id0 = 0; id0 < N - 1; id0++) {
        rd(&A[id0]);
        A[id0] += -1;
        rd(&B[id0]);
        B[id0] += -1;
    }
    g.setEdge(N, N - 1, A, B, &wmem);
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
    return 0;
}
