#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 100005
#define MAX_M 1005
#define MOD 998244353

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    int x;
    int y;
    int z;
} Triple;

typedef struct {
    int x;
    int y;
    int z;
    int w;
} Quadruple;

int n, m, fW, hW;
int a[MAX_N], w[MAX_N];
int inv[MAX_M * 2 + 1];
int f[MAX_M + 1][MAX_M + 1];
int h[MAX_M + 1][MAX_M + 1];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int mul(int a, int b) {
    return (int)(((long long)a * b) % MOD);
}

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int powMod(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inverse(int x) {
    return powMod(x, MOD - 2);
}

void solve() {
    scanf("%d %d", &n, &m);
    int count[2] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        count[a[i] % 2]++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        if (a[i] % 2 == 0) {
            hW += w[i];
        } else {
            fW += w[i];
        }
    }

    for (int i = 0; i <= m * 2; i++) {
        inv[i] = inverse(hW + fW + i - m);
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = -1;
            h[i][j] = -1;
        }
    }

    for (int i = 0; i <= m; i++) {
        f[i][0] = 1;
        h[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            printf("%d\n", mul(w[i], f[0][m]));
        } else {
            printf("%d\n", mul(w[i], h[0][m]));
        }
    }
}

int main() {
    solve();
    return 0;
}
