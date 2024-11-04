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
            n->mu = 0;
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
            np->mu = -n->mu;
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
    int count = 0;
    for (; v > 1; v = eliminate_least_prime(v)) {
        num* n = &nums[v];
        factors[count] = n->least_prime;
        exponents[count] = n->lp_multiplicity;
        count++;
    }
    *factor_count = count;
}

void for_each_divisor_unordered(int v, void (*f)(int), int c) {
    if (v == 1) {
        f(c);
        return;
    }
    int w = eliminate_least_prime(v);
    num* n = &nums[v];
    for (int m = 0; m <= n->lp_multiplicity; m++, c *= n->least_prime)
        for_each_divisor_unordered(w, f, c);
}

void unordered_divisors(int v, int* divisors, int* divisor_count) {
    int count = 0;
    for_each_divisor_unordered(v, ^(int d) {
        divisors[count] = d;
        count++;
    }, 1);
    *divisor_count = count;
}

ll ncr(int n, int r) {
    if (r < 0 || n < r) return 0;
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

ll pow_mod(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll mod_inverse(ll a, ll mod) {
    return pow_mod(a, mod - 2, mod);
}

ll mod_factorial(int n, ll mod) {
    ll res = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % mod;
    }
    return res;
}

ll mod_inverse_factorial(int n, ll mod) {
    ll res = 1;
    for (int i = n; i >= 2; i--) {
        res = (res * mod_inverse(i, mod)) % mod;
    }
    return res;
}

ll mod_ncr(int n, int r, ll mod) {
    ll numerator = mod_factorial(n, mod);
    ll denominator = (mod_inverse_factorial(r, mod) * mod_inverse_factorial(n - r, mod)) % mod;
    return (numerator * denominator) % mod;
}

ll modnum(int v, ll mod) {
    v %= mod;
    if (v < 0) v += mod;
    return v;
}

ll modnum_add(ll a, ll b, ll mod) {
    return modnum(a + b, mod);
}

ll modnum_sub(ll a, ll b, ll mod) {
    return modnum(a - b, mod);
}

ll modnum_mul(ll a, ll b, ll mod) {
    return modnum(a * b, mod);
}

ll modnum_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = modnum_mul(res, base, mod);
        }
        base = modnum_mul(base, base, mod);
        exp /= 2;
    }
    return res;
}

ll modnum_inv(ll a, ll mod) {
    return modnum_pow(a, mod - 2, mod);
}

ll modnum_div(ll a, ll b, ll mod) {
    return modnum_mul(a, modnum_inv(b, mod), mod);
}

ll modnum_ncr(int n, int r, ll mod) {
    if (r < 0 || n < r) return 0;
    ll numerator = mod_factorial(n, mod);
    ll denominator = (mod_inverse_factorial(r, mod) * mod_inverse_factorial(n - r, mod)) % mod;
    return modnum_mul(numerator, denominator, mod);
}

ll modnum_coeff[MAXV];

void calculate_coefficients(ll mod) {
    for (int g = 1; g < MAXV; g++) {
        for (int m = g, c = 1; m < MAXV; m += g, c++) {
            modnum_coeff[m] += g * nums[c].mu;
        }
    }
}

int main() {
    sieve();

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

    ll ans = 0;
    int* ct = calloc(MAXV, sizeof(int));

    calculate_coefficients(1000000007);

    for (int i = 0; i < N; i++) {
        int v = a[i];
        int factors[MAXV];
        int exponents[MAXV];
        int factor_count;
        factor(v, factors, exponents, &factor_count);
        for (int j = 0; j < factor_count; j++) {
            int d = factors[j];
            ans = modnum_add(ans, modnum_mul(modnum_coeff[d], modnum_sub(modnum_pow(ct[d] + 1, K, 1000000007), modnum_pow(ct[d], K, 1000000007), 1000000007), 1000000007), 1000000007);
            ct[d]++;
        }
    }

    for (int i = 0; i < Q; i++) {
        int v = q[i];
        int factors[MAXV];
        int exponents[MAXV];
        int factor_count;
        factor(v, factors, exponents, &factor_count);
        for (int j = 0; j < factor_count; j++) {
            int d = factors[j];
            ans = modnum_add(ans, modnum_mul(modnum_coeff[d], modnum_sub(modnum_pow(ct[d] + 1, K, 1000000007), modnum_pow(ct[d], K, 1000000007), 1000000007), 1000000007), 1000000007);
            ct[d]++;
        }
        printf("%lld\n", ans);
    }

    free(a);
    free(q);
    free(ct);

    return 0;
}
