#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long a, b, k;
    scanf("%lld %lld %lld", &a, &b, &k);

    int lcm_val = 1;
    for (int i = 2; i <= k; i++) {
        lcm_val = lcm(lcm_val, i);
    }

    int aa = a % lcm_val;
    int bb = b % lcm_val;

    int adj[lcm_val][k];
    for (int i = 0; i < lcm_val; i++) {
        int count = 0;
        for (int j = 1; j <= k; j++) {
            if (i % j != 0) {
                adj[i][count++] = i % j;
            }
        }
        adj[i][count++] = 1;
    }

    int D[3 * lcm_val];
    for (int i = 0; i < 3 * lcm_val; i++) {
        D[i] = 1e9;
    }
    D[0] = 0;

    int s = aa;
    for (int i = 0; i < 3 * lcm_val; i++) {
        int u = (s - i) % lcm_val;
        if (u < 0) {
            u += lcm_val;
        }
        int Du = D[i];
        if (Du == 1e9) {
            continue;
        }
        for (int j = 0; j < k; j++) {
            int v = (u + adj[u][j]) % lcm_val;
            D[i + adj[u][j]] = MIN(D[i + adj[u][j]], Du + 1);
        }
    }

    bb = (aa - bb + 3 * lcm_val) % lcm_val;

    long long tt = (a - b) / lcm_val;
    tt *= (D[bb + lcm_val] - D[bb]);

    printf("%d\n", D[bb] + tt);

    return 0;
}
