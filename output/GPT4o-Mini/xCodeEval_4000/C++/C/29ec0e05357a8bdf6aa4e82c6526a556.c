#include <stdio.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define _1(i) (1 << (i))
#define _U(i) (_1(i) - 1)
#define RST(A) memset(A, 0, sizeof(A))
#define DO(n) while(n--)
#define INC(a, b) (a += b, (a >= MOD) ? (a -= MOD) : a)
#define DEC(a, b) (a -= b, (a < 0) ? (a += MOD) : a)
#define MOD 1000000007

typedef long long LL;

const int N = 16, S = 1 << 16;

LL F[S], k, t;
int adj[N], A[N], P[N], n;

int count_bits(int x) {
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

LL dfs() {
    RST(F); 
    F[0] = 1; 
    REP(s, _U(n)) if (F[s]) {
        REP(i, n) if (!((s) & _1(i)) && (P[count_bits(s)] == -1 || P[count_bits(s)] == i) && !(s & adj[i])) {
            F[s | _1(i)] += F[s];
        }
    }
    return F[_U(n)];
}

int main() {
    scanf("%d %lld", &n, &k);
    k -= 2000;
    DO_C(RD()) {
        int u = RD() - 1;
        int v = RD() - 1;
        adj[u] |= _1(v);
    }
    RST(P);
    for (int i = 0; i < N; i++) P[i] = -1;

    if (dfs() < k) {
        puts("The times have changed");
    } else {
        int s = _U(n);
        REP(i, n) {
            REP(j, n) if (_1(s) & (1 << j)) {
                P[A[i] = j] = i;
                t = dfs();
                if (t < k) {
                    k -= t;
                    P[j] = -1;
                } else {
                    s ^= _1(j);
                    printf("%d ", j + 1);
                    break;
                }
            }
        }
    }
    return 0;
}
