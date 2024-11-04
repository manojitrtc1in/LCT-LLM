#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR_1(i, a, b) for (int i = (a); i <= (b); i++)
#define PB push_back
#define SZ(x) ((int)(x).size())

typedef long long LL;
typedef double DB;
typedef int VI[100009];

const int L = 360360;
const int INF = 0x3f3f3f3f;

int D[3 * L];
VI adj[L];

inline int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int id2(int a, int b) {
    return a * b / gcd(a, b);
}

inline void checkMin(int *a, const int b) {
    if (b < *a) *a = b;
}

inline void bfs(int aa, int lcm) {
    int s = aa;
    memset(D, 0x3f, sizeof(D));
    D[0] = 0;

    REP(i, 3 * lcm) {
        int u = (s - i) % lcm;
        if (u < 0) u += lcm;

        int Du = D[i];
        if (Du == INF) continue;

        REP(ii, SZ(adj[u])) {
            checkMin(&D[i + adj[u][ii]], Du + 1);
        }
    }
}

int main() {
    LL a, b, k;
    scanf("%lld %lld %lld", &a, &b, &k);

    int lcm = 1;
    FOR_1(i, 2, k) {
        lcm = id2(lcm, i);
    }

    REP(i, lcm) {
        adj[i][0] = 1; // Initialize first element
        int size = 1; // Size of the adjacency list
        FOR_1(j, 2, k) {
            if (i % j) {
                adj[i][size++] = i % j;
            }
        }
    }

    LL tt = (a - b) / lcm;
    int aa = a % lcm, bb = b % lcm;

    LL step = INF;
    bfs(aa, lcm);

    bb = (aa - bb + 3 * lcm) % lcm;
    tt *= (LL)(D[bb + lcm] - D[bb]);

    printf("%d\n", D[bb] + tt);
    return 0;
}
