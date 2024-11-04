#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long a, b, k;
    int aa, bb, lcm_val;
    int adj[360360][10];
    int D[1081080];

    scanf("%lld %lld %lld", &a, &b, &k);

    lcm_val = 1;
    for (int i = 2; i <= k; i++) {
        lcm_val = lcm(lcm_val, i);
    }

    for (int i = 0; i < lcm_val; i++) {
        int count = 0;
        adj[i][count++] = 1;
        for (int j = 2; j <= k; j++) {
            if (i % j != 0) {
                adj[i][count++] = i % j;
            }
        }
    }

    long long tt = (a - b) / lcm_val;

    aa = a % lcm_val;
    bb = b % lcm_val;

    for (int i = 0; i < 3 * lcm_val; i++) {
        D[i] = 1000000000;
    }
    D[0] = 0;

    for (int i = 0; i < 3 * lcm_val; i++) {
        int u = (aa - i) % lcm_val;
        if (u < 0) {
            u += lcm_val;
        }

        int Du = D[i];

        if (Du == 1000000000) {
            continue;
        }

        for (int j = 0; j < 10; j++) {
            int v = adj[u][j];
            D[i + v] = MIN(D[i + v], Du + 1);
        }
    }

    bb = (aa - bb + 3 * lcm_val) % lcm_val;

    tt *= (long long)(D[bb + lcm_val] - D[bb]);

    printf("%d\n", D[bb] + tt);

    return 0;
}
