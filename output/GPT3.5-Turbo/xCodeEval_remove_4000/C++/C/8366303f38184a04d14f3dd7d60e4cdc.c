#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 360360
#define INF 0x3f3f3f3f

typedef struct {
    int fi;
    int se;
} PTT;

PTT PTT_add(const PTT p1, const PTT p2) {
    PTT result;
    result.fi = p1.fi + p2.fi;
    result.se = p1.se + p2.se;
    return result;
}

PTT PTT_sub(const PTT p1, const PTT p2) {
    PTT result;
    result.fi = p1.fi - p2.fi;
    result.se = p1.se - p2.se;
    return result;
}

PTT PTT_mul(const PTT lhs, int k) {
    PTT result;
    result.fi = lhs.fi * k;
    result.se = lhs.se * k;
    return result;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int id2(int a, int b) {
    return a * b / gcd(a, b);
}

int a, b, k;
int aa, bb, lcm;
int adj[MAX_SIZE][MAX_SIZE];

int D[3 * MAX_SIZE];

int f(int s, int t) {
    return D[t];
}

void bfs() {
    int s = aa;
    for (int i = 0; i < 3 * lcm; i++) {
        D[i] = INF;
    }
    D[0] = 0;

    for (int i = 0; i < 3 * lcm; i++) {
        int u = (s - i) % lcm;
        if (u < 0) {
            u += lcm;
        }

        int Du = D[i];

        if (Du == INF) {
            continue;
        }

        for (int j = 0; j < adj[u][0]; j++) {
            int ii = adj[u][j + 1];
            if (D[i + ii] > Du + 1) {
                D[i + ii] = Du + 1;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &a, &b, &k);

    lcm = 1;
    for (int i = 2; i <= k; i++) {
        lcm = id2(lcm, i);
    }

    for (int i = 0; i < lcm; i++) {
        adj[i][0] = 1;
        for (int j = 2; j <= k; j++) {
            if (i % j != 0) {
                adj[i][0]++;
                adj[i][adj[i][0]] = i % j;
            }
        }
    }

    long long tt = (a - b) / lcm;

    aa = a % lcm;
    bb = b % lcm;

    long long step = INF;
    int h;

    bfs();

    bb = (aa - bb + 3 * lcm) % lcm;

    tt *= (long long)(D[bb + lcm] - D[bb]);

    printf("%d\n", D[bb] + tt);

    return 0;
}
