#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

typedef long long ll;

ll pow_mod(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

typedef struct {
    int size;
    ll *coefficients;
} Polynomial;

Polynomial create_polynomial(int size) {
    Polynomial poly;
    poly.size = size;
    poly.coefficients = (ll *)malloc(size * sizeof(ll));
    return poly;
}

void destroy_polynomial(Polynomial *poly) {
    free(poly->coefficients);
    poly->size = 0;
}

Polynomial multiply_polynomials(const Polynomial *poly1, const Polynomial *poly2) {
    int size = poly1->size + poly2->size - 1;
    Polynomial result = create_polynomial(size);
    for (int i = 0; i < size; i++) {
        result.coefficients[i] = 0;
    }
    for (int i = 0; i < poly1->size; i++) {
        for (int j = 0; j < poly2->size; j++) {
            result.coefficients[i + j] = (result.coefficients[i + j] + poly1->coefficients[i] * poly2->coefficients[j]) % MOD;
        }
    }
    return result;
}

Polynomial power_polynomial(const Polynomial *poly, ll n) {
    if (n == 0) {
        Polynomial result = create_polynomial(1);
        result.coefficients[0] = 1;
        return result;
    }
    if (n == 1) {
        return *poly;
    }
    if (n % 2 == 0) {
        Polynomial half = power_polynomial(poly, n / 2);
        return multiply_polynomials(&half, &half);
    } else {
        Polynomial half = power_polynomial(poly, (n - 1) / 2);
        Polynomial temp = multiply_polynomials(&half, &half);
        return multiply_polynomials(&temp, poly);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *h = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    h[n] = h[0];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] == h[i + 1]) {
            cnt++;
        }
    }
    int d = n - cnt;

    ll res = pow_mod(k, cnt), sum = 0;

    Polynomial f = create_polynomial(2 * d + 1);
    f.coefficients[0] = 1;
    f.coefficients[1] = k - 2;
    f.coefficients[2] = 1;
    f = power_polynomial(&f, d);
    for (int i = d + 1; i <= 2 * d; i++) {
        sum = (sum + f.coefficients[i]) % MOD;
    }

    printf("%lld\n", (res * sum) % MOD);

    free(h);
    destroy_polynomial(&f);

    return 0;
}
