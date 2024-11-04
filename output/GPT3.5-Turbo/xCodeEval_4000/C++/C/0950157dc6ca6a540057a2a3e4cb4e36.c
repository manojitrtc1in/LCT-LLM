#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MOD 10007

typedef struct {
    int x;
} Field;

Field field_multiply(Field a, Field b) {
    Field res;
    res.x = (a.x * b.x) % MOD;
    return res;
}

Field field_add(Field a, Field b) {
    Field res;
    res.x = (a.x + b.x) % MOD;
    return res;
}

Field field_subtract(Field a, Field b) {
    Field res;
    res.x = (a.x - b.x + MOD) % MOD;
    return res;
}

Field field_power(Field a, int n) {
    Field res;
    res.x = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = field_multiply(res, a);
        }
        a = field_multiply(a, a);
        n /= 2;
    }
    return res;
}

typedef struct {
    Field p[202];
} Poly;

Poly poly_multiply(Poly a, Poly b) {
    Poly res;
    memset(res.p, 0, sizeof(res.p));
    for (int i = 0; i < 202; i++) {
        for (int j = 0; j <= i; j++) {
            res.p[i] = field_add(res.p[i], field_multiply(a.p[j], b.p[i - j]));
        }
    }
    return res;
}

Poly poly_shift(Poly a, int shift) {
    Poly res;
    memset(res.p, 0, sizeof(res.p));
    for (int i = shift; i < 202; i++) {
        res.p[i] = a.p[i - shift];
    }
    return res;
}

Poly poly_mod(Poly a, int mod) {
    Poly res;
    memset(res.p, 0, sizeof(res.p));
    for (int i = 0; i < mod; i++) {
        res.p[i] = a.p[i];
    }
    return res;
}

Poly poly_power(Poly a, int n) {
    Poly res;
    memset(res.p, 0, sizeof(res.p));
    res.p[0].x = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = poly_multiply(res, a);
        }
        a = poly_multiply(a, a);
        n /= 2;
    }
    return res;
}

int main() {
    char s[202];
    int n;
    scanf("%s", s);
    scanf("%d", &n);

    Field dp[202][202][2020];
    bool ok[202][202][2020];
    memset(ok, false, sizeof(ok));

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        dp[i][i + 1][0].x = 1;
        ok[i][i + 1][0] = true;
    }

    for (int i = 0; i < len; i++) {
        for (int j = i + 2; j <= len; j++) {
            for (int k = 0; k < 2020; k++) {
                if (ok[i + 1][j][k]) {
                    dp[i][j][k] = field_add(dp[i][j][k], field_multiply(dp[i + 1][j][k - 1], field_power((Field){26}, 1)));
                }
                if (ok[i][j - 1][k]) {
                    dp[i][j][k] = field_add(dp[i][j][k], field_multiply(dp[i][j - 1][k - 1], field_power((Field){26}, 1)));
                }
                if (s[i] == s[j - 1]) {
                    dp[i][j][k] = field_add(dp[i][j][k], dp[i + 1][j - 1][k]);
                } else {
                    dp[i][j][k] = field_add(dp[i][j][k], dp[i + 1][j][k - 1]);
                    dp[i][j][k] = field_add(dp[i][j][k], dp[i][j - 1][k - 1]);
                    dp[i][j][k] = field_add(dp[i][j][k], field_multiply(dp[i][j][k - 2], field_subtract((Field){24}, (Field){0})));
                }
                ok[i][j][k] = true;
            }
        }
    }

    Poly base;
    memset(base.p, 0, sizeof(base.p));
    for (int i = 0; i < 2020; i++) {
        base.p[i] = dp[0][len][i];
    }

    Poly res = poly_power(base, n);
    printf("%d\n", res.p[n].x);

    return 0;
}
