#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define L 360360
#define N 100009
#define INF INT_MAX

typedef long long LL;
typedef int VI[L];

int D[3 * L];
VI adj[L];

int __gcd(int a, int b) {
    return b ? __gcd(b, a % b) : a;
}

int __lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

LL a, b, k;
int aa, bb, lcm;

inline int f(int s, int t) {
    return D[t];
}

void bfs() {
    int s = aa;
    memset(D, 0x3f, sizeof(D));
    D[0] = 0;

    for (int i = 0; i < 3 * lcm; i++) {
        int u = (s - i) % lcm;
        if (u < 0) u += lcm;

        int Du = D[i];
        if (Du == INF) continue;

        for (int ii = 0; ii < adj[u][0]; ii++) {
            int next = adj[u][ii + 1]; // Skip the first element which is the size
            if (next != 0) {
                if (D[i + next] > Du + 1) {
                    D[i + next] = Du + 1;
                }
            }
        }
    }
}

int main() {
    scanf("%lld %lld %lld", &a, &b, &k);

    lcm = 1;
    for (int i = 2; i <= k; i++) {
        lcm = __lcm(lcm, i);
    }

    for (int i = 0; i < lcm; i++) {
        adj[i][0] = 1; // Initialize size
        adj[i][1] = 1; // First element
        for (int j = 2; j <= k; j++) {
            if (i % j) {
                adj[i][++adj[i][0]] = i % j; // Increment size and add element
            }
        }
    }

    LL tt = (a - b) / lcm;
    aa = a % lcm;
    bb = b % lcm;

    LL step = INF;
    bfs();

    bb = (aa - bb + 3 * lcm) % lcm;
    tt *= (LL)(D[bb + lcm] - D[bb]);

    printf("%d\n", D[bb] + tt);
}
