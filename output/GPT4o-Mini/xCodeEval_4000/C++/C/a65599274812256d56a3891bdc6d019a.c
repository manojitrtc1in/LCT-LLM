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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

LL a, b, k;
int aa, bb, lcm_val;

void bfs() {
    int s = aa;
    memset(D, 0x3f, sizeof(D));
    D[0] = 0;

    for (int i = 0; i < 3 * lcm_val; i++) {
        int u = (s - i) % lcm_val;
        if (u < 0) u += lcm_val;

        int Du = D[i];
        if (Du == INF) continue;

        for (int j = 0; j < adj[u][0]; j++) {
            int next = adj[u][j];
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

    lcm_val = 1;
    for (int i = 2; i <= k; i++) {
        lcm_val = lcm(lcm_val, i);
    }

    for (int i = 0; i < lcm_val; i++) {
        adj[i][0] = 1; // Initialize the first element as the count
        for (int j = 2; j <= k; j++) {
            if (i % j) {
                adj[i][++adj[i][0]] = i % j; // Store the next element
            }
        }
    }

    LL tt = (a - b) / lcm_val;
    aa = a % lcm_val;
    bb = b % lcm_val;

    LL step = INF;
    bfs();

    bb = (aa - bb + 3 * lcm_val) % lcm_val;
    tt *= (LL)(D[bb + lcm_val] - D[bb]);

    printf("%d\n", D[bb] + tt);
    return 0;
}
