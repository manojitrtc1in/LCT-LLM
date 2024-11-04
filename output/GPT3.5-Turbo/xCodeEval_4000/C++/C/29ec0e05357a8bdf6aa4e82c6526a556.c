#include <stdio.h>
#include <string.h>

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_C(i, n) for (int n____=int(n),i=0;i<n____;++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define DWN_C(i, b, a) for (int a____=int(a),i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (int b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (int a____=int(a),i=b;i>=a____;--i)
#define REP_1_N(i, n) for (i=1;i<=int(n);++i)
#define FOR_1_N(i, a, b) for (i=int(a);i<=int(b);++i)
#define DWN_1_N(i, b, a) for (i=int(b);i>=int(a);--i)
#define REP_C_N(i, n) for (n____=int(n),i=0;i<n____;++i)
#define FOR_C_N(i, a, b) for (b____=int(b),i=a;i<b____;++i)
#define DWN_C_N(i, b, a) for (a____=int(a),i=b-1;i>=a____;--i)
#define REP_1_C_N(i, n) for (n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (a____=int(a),i=b;i>=a____;--i)

#define DO(n) while(n--)
#define DO_C(n) int n____ = n; while(n____--)
#define TO(i, a, b) int s_=a<b?1:-1,b_=b+s_;for(int i=a;i!=b_;i+=s_)
#define TO_1(i, a, b) int s_=a<b?1:-1,b_=b;for(int i=a;i!=b_;i+=s_)
#define SQZ(i, j, a, b) for (int i=int(a),j=int(b)-1;i<j;++i,--j)
#define SQZ_1(i, j, a, b) for (int i=int(a),j=int(b);i<=j;++i,--j)
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, X) find(ALL(A), X) 

#define CTN(T, x) T.find(x) != T.end()
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

typedef struct {
    int first;
    int second;
} PII;

typedef struct {
    int first;
    bool second;
} PIB;

typedef struct {
    int adj[16];
    int A[16];
    int P[16];
    int n;
} Graph;

int count_bits(int x) {
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

void dfs(Graph *graph, LL *F, int s, int k, int *pos) {
    memset(F, 0, sizeof(LL) * (1 << graph->n));
    F[0] = 1;
    REP(s, (1 << graph->n)) {
        REP(i, graph->n) {
            if (!(s & (1 << i)) && (pos == NULL || pos[count_bits(s)] == -1 || pos[count_bits(s)] == i) && !(s & graph->adj[i])) {
                F[s | (1 << i)] += F[s];
            }
        }
    }
}

LL solve(Graph *graph, int k) {
    LL F[1 << 16];
    int s = (1 << graph->n);
    int pos[16];
    memset(pos, -1, sizeof(int) * 16);
    REP(i, graph->n) {
        REP(j, graph->n) {
            if (s & (1 << j)) {
                pos[graph->A[i] = j] = i;
                dfs(graph, F, s ^ (1 << j), k, pos);
                if (F[(1 << graph->n) - 1] < k) {
                    k -= F[(1 << graph->n) - 1];
                    pos[j] = -1;
                } else {
                    s ^= (1 << j);
                    printf("%d ", j + 1);
                    break;
                }
            }
        }
    }
    return F[(1 << graph->n) - 1];
}

int main() {
    Graph graph;
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 2000;
    memset(graph.adj, 0, sizeof(int) * 16);
    memset(graph.P, -1, sizeof(int) * 16);
    graph.n = n;
    int m;
    scanf("%d", &m);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph.adj[u - 1] |= (1 << (v - 1));
    }
    if (solve(&graph, k) < k) {
        printf("The times have changed\n");
    }
    return 0;
}
