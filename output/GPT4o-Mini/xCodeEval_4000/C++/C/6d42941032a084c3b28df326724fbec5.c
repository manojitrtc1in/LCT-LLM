#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 998244353
#define MAX_N 2000001

typedef long long ll;
typedef struct {
    int X, Y;
} pii;

int inverse(int a, int n) {
    int c = cool_gcd(a, n).X;
    if (c < 0) c += n;
    return c;
}

int prod(int a, int b, int M) {
    return ((ll)(a)) * b % M;
}

int sum(int a, int b, int M) {
    int c = a + b;
    return c >= M ? c - M : c;
}

int raz(int a, int b, int M) {
    int c = a - b;
    return c < 0 ? c + M : c;
}

int cool_gcd(int a, int b) {
    if (b) {
        int c = a / b;
        pii ans1 = cool_gcd(b, a - b * c);
        return (pii){ans1.Y, ans1.X - ans1.Y * c};
    } else {
        return (pii){1, 0};
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], w[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }

    int W1 = 0, W2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]) W1 += w[i];
        else W2 += w[i];
    }

    int probs[m + 1];
    memset(probs, 0, sizeof(probs));
    probs[0] = 1;

    for (int i = 0; i < m; ++i) {
        int new_probs[m + 1];
        memset(new_probs, 0, sizeof(new_probs));
        for (int d1 = 0; d1 <= i; ++d1) {
            int d2 = d1 - i;
            int w1 = W1 + d1;
            int w2 = W2 + d2;
            int w0 = w1 + w2;
            if (probs[d1] && (w2 >= 0)) {
                int inv_w0 = inverse(w0, M);
                if (w2 > 0) {
                    new_probs[d1] = sum(new_probs[d1], prod(probs[d1], prod(w2, inv_w0, M), M), M);
                }
                new_probs[d1 + 1] = sum(new_probs[d1 + 1], prod(probs[d1], prod(w1, inv_w0, M), M), M);
            }
        }
        memcpy(probs, new_probs, sizeof(probs));
    }

    int after_ops_1[m + 1], after_ops_2[m + 1];
    after_ops_1[0] = 1; after_ops_2[0] = 1;
    for (int i = 1; i <= m; ++i) {
        after_ops_1[i] = prod(after_ops_1[i - 1], sum(1, inverse(W1 + i - 1, M), M), M);
    }
    for (int i = 1; i <= m; ++i) {
        after_ops_2[i] = prod(after_ops_2[i - 1], raz(1, inverse(W2 - i + 1, M), M), M);
    }

    int coef1 = 0, coef2 = 0;
    for (int i = 0; i <= m; ++i) {
        coef1 = sum(coef1, prod(after_ops_1[i], probs[i], M), M);
    }
    for (int i = 0; i <= m; ++i) {
        coef2 = sum(coef2, prod(after_ops_2[i], probs[m - i], M), M);
    }

    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            printf("%d\n", prod(w[i], coef1, M));
        } else {
            printf("%d\n", prod(w[i], coef2, M));
        }
    }

    return 0;
}
