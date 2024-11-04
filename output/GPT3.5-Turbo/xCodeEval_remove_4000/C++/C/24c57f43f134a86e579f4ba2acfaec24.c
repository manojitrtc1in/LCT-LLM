#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAXV 1000001

typedef long long int ll;

typedef struct {
    int least_prime;
    int div_least_prime;
    char lp_multiplicity;
    char mu;
    int phi;
} num;

num nums[MAXV];
int primes[MAXV];
int prime_count = 0;

void sieve() {
    nums[1].least_prime = INT_MAX;
    nums[1].div_least_prime = 1;
    nums[1].lp_multiplicity = 0;
    nums[1].mu = 1;
    nums[1].phi = 1;

    for (int v = 2; v < MAXV; v++) {
        num* n = &nums[v];
        if (n->least_prime == 0) {
            n->least_prime = v;
            n->div_least_prime = 1;
            n->lp_multiplicity = 1;
            n->mu = -1;
            n->phi = v - 1;
            primes[prime_count++] = v;
        }
        for (int i = 0; i < prime_count; i++) {
            int p = primes[i];
            if (p > n->least_prime || v * p >= MAXV) break;
            num* np = &nums[v * p];
            np->least_prime = p;
            np->div_least_prime = v;
            np->lp_multiplicity = n->lp_multiplicity + 1;
            np->mu = 0;
            np->phi = n->phi * p;
        }
    }
}

bool is_prime(int v) {
    return nums[v].least_prime == v;
}

int eliminate_least_prime(int v) {
    num* n = &nums[v];
    for (int m = n->lp_multiplicity; m > 0; m--)
        v = n->div_least_prime;
    return v;
}

void factor(int v, int* factors, int* exponents, int* factor_count) {
    int factor_index = 0;
    while (v > 1) {
        num* n = &nums[v];
        factors[factor_index] = n->least_prime;
        exponents[factor_index] = n->lp_multiplicity;
        factor_index++;
        v = eliminate_least_prime(v);
    }
    *factor_count = factor_index;
}

ll pow_mod(ll base, ll exponent, ll modulus) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

ll ncr(int n, int r, int modulus) {
    if (r < 0 || n < r) return 0;
    ll numerator = 1;
    ll denominator = 1;
    for (int i = 0; i < r; i++) {
        numerator = (numerator * (n - i)) % modulus;
        denominator = (denominator * (i + 1)) % modulus;
    }
    return (numerator * pow_mod(denominator, modulus - 2, modulus)) % modulus;
}

int main() {
    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    int* a = malloc(N * sizeof(int));
    int* q = malloc(Q * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q[i]);
    }

    sieve();

    ll* coeff = malloc(MAXV * sizeof(ll));
    for (int g = 1; g < MAXV; g++) {
        coeff[g] = 0;
        for (int m = g, c = 1; m < MAXV; m += g, c++) {
            coeff[g] += g * nums[c].mu;
        }
    }

    ll ans = 0;
    int* ct = calloc(MAXV, sizeof(int));

    void intro(int v) {
        int factors[100];
        int exponents[100];
        int factor_count;
        factor(v, factors, exponents, &factor_count);
        for (int i = 0; i < factor_count; i++) {
            int d = factors[i];
            ans += coeff[d] * (ncr(ct[d] + 1, K, INT_MAX) - ncr(ct[d], K, INT_MAX));
            ct[d]++;
        }
    }

    for (int i = 0; i < N; i++) {
        intro(a[i]);
    }

    for (int i = 0; i < Q; i++) {
        intro(q[i]);
        printf("%lld\n", ans);
    }

    free(a);
    free(q);
    free(coeff);
    free(ct);

    return 0;
}
