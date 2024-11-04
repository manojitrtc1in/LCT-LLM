#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long LL;
typedef double DB;

#define MOD 1000000007
#define INF 0x7fffffff
#define PI acos(-1.0)
#define EPS 1e-6
#define OO 1e15

#define REP(i, n) for(int i = 0; i < (n); i++)
#define DO_C(x) for(int ____Case = 0; ____Case < (x); ____Case++)

#define _1(i) (1 << (i))
#define _U(i) (_1(i) - 1)

LL F[1 << 16], k, t;
int adj[16], A[16], P[16], n;

void RST(LL *A) {
    memset(A, 0, sizeof(LL) * (1 << 16));
}

void FLC(int *A, int x) {
    memset(A, x, sizeof(int) * 16);
}

int dfs() {
    RST(F); 
    F[0] = 1; 
    REP(s, _U(n)) if (F[s]) {
        REP(i, n) if (!(s & _1(i)) && !(s & adj[i])) {
            F[s | _1(i)] += F[s];
        }
    }
    return F[_U(n)];
}

void RD(int *x) {
    scanf("%d", x);
}

void OT(int x) {
    printf("%d ", x);
}

int main() {
    RD(&n); 
    RD(&k); 
    k -= 2000;
    DO_C(RD(&adj[RD() - 1] |= _1(RD() - 1))); 
    FLC(P, -1);

    if (dfs() < k) {
        puts("The times have changed");
    } else {
        int s = _U(n); 
        REP(i, n) {
            REP(j, n) if (_1(s, j)) {
                P[A[i] = j] = i; 
                t = dfs(); 
                if (t < k) {
                    k -= t; 
                    P[j] = -1;
                } else {
                    s ^= _1(j);
                    OT(j + 1);
                    break;
                }
            }
        }
    }
    return 0;
}
