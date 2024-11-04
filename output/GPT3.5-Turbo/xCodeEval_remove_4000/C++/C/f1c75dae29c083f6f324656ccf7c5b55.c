#include <stdio.h>
#include <string.h>

#define N 16
#define S (1 << 16)

typedef long long LL;

LL F[S], k, t;
int adj[N], A[N], P[N], n;

LL dfs() {
    memset(F, 0, sizeof(F));
    F[0] = 1;
    for (int s = 0; s < (1 << n) - 1; s++) {
        if (F[s]) {
            for (int i = 0; i < n; i++) {
                if (!(s & (1 << i)) && (P[i] == -1) && !(s & adj[i])) {
                    F[s | (1 << i)] += F[s];
                }
            }
        }
    }
    return F[(1 << n) - 1];
}

int main() {
    scanf("%d %lld", &n, &k);
    k -= 2000;
    memset(adj, 0, sizeof(adj));
    memset(P, -1, sizeof(P));
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u - 1] |= (1 << (v - 1));
    }

    if (dfs() < k) {
        printf("The times have changed\n");
    } else {
        int s = (1 << n) - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s & (1 << j)) {
                    P[A[i] = j] = i;
                    t = dfs();
                    if (t < k) {
                        k -= t;
                        P[j] = -1;
                    } else {
                        s ^= (1 << j);
                        printf("%d ", j + 1);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
