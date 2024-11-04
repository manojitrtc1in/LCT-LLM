#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

#define MAX_N 16
#define MAX_S (1 << 16)

LL F[MAX_S], k, t;
int adj[MAX_N], A[MAX_N], P[MAX_N], n;

void RD(int *x) {
    scanf("%d", x);
}

void RST(LL *A) {
    memset(A, 0, sizeof(LL) * MAX_S);
}

int _1(int i) {
    return 1 << i;
}

int _U(int i) {
    return _1(i) - 1;
}

LL dfs() {
    RST(F);
    F[0] = 1;
    for (int s = 0; s <= _U(n); s++) {
        if (F[s]) {
            for (int i = 0; i < n; i++) {
                if (!(s & _1(i)) && !(s & adj[i])) {
                    F[s | _1(i)] += F[s];
                }
            }
        }
    }
    return F[_U(n)];
}

int main() {
    RD(&n);
    RD(&k);
    k -= 2000;

    for (int i = 0; i < n; i++) {
        int x, y;
        RD(&x);
        RD(&y);
        adj[x - 1] |= _1(y - 1);
        P[i] = -1;
    }

    if (dfs() < k) {
        puts("The times have changed");
    } else {
        int s = _U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s & _1(j)) {
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
    }
}
