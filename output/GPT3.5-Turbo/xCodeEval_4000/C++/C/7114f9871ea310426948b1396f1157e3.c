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
    while (v > 1) {
        num* n = &nums[v];
        for (int m = n->lp_multiplicity; m > 0; m--) {
            v = n->div_least_prime;
        }
    }
    return v;
}

void factor(int v, int* factors, int* factor_count) {
    *factor_count = 0;
    while (v > 1) {
        int least_prime = nums[v].least_prime;
        int lp_multiplicity = nums[v].lp_multiplicity;
        factors[*factor_count] = least_prime;
        factor_count++;
        v = eliminate_least_prime(v);
    }
}

void for_each_divisor_unordered(int v, void (*f)(int), int c) {
    if (v == 1) {
        f(c);
        return;
    }
    int w = eliminate_least_prime(v);
    for (int m = 0; m <= nums[v].lp_multiplicity; m++, c *= nums[v].least_prime) {
        for_each_divisor_unordered(w, f, c);
    }
}

void unordered_divisors(int v, int* divisors, int* divisor_count) {
    *divisor_count = 0;
    for_each_divisor_unordered(v, divisors, divisor_count);
}

ll ncr(int n, int r) {
    if (r < 0 || n < r) return 0;
    ll res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
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

typedef struct {
    ll v;
} modnum;

modnum modnum_init(ll v) {
    modnum num;
    num.v = v % (ll)(1e9 + 7);
    if (num.v < 0) num.v += (ll)(1e9 + 7);
    return num;
}

modnum modnum_add(modnum a, modnum b) {
    return modnum_init((a.v + b.v) % (ll)(1e9 + 7));
}

modnum modnum_sub(modnum a, modnum b) {
    return modnum_init((a.v - b.v + (ll)(1e9 + 7)) % (ll)(1e9 + 7));
}

modnum modnum_mul(modnum a, modnum b) {
    return modnum_init((a.v * b.v) % (ll)(1e9 + 7));
}

modnum modnum_pow(modnum a, ll e) {
    if (e < 0) return modnum_pow(modnum_mul(modnum_init(1), modnum_pow(a, -e)), -1);
    if (e == 0) return modnum_init(1);
    if (e % 2 == 1) return modnum_mul(a, modnum_pow(a, e - 1));
    return modnum_pow(modnum_mul(a, a), e / 2);
}

modnum modnum_inv(modnum a) {
    return modnum_pow(a, (ll)(1e9 + 7) - 2);
}

modnum modnum_div(modnum a, modnum b) {
    return modnum_mul(a, modnum_inv(b));
}

modnum modnum_ncr(int n, int r) {
    if (r < 0 || n < r) return modnum_init(0);
    modnum res = modnum_init(1);
    for (int i = 0; i < r; i++) {
        res = modnum_mul(res, modnum_init(n - i));
        res = modnum_div(res, modnum_init(i + 1));
    }
    return res;
}

modnum modnum_small_inv(int n) {
    return modnum_mul(modnum_ncr(n - 1, 1), modnum_inv(modnum_init(n)));
}

modnum modnum_factorial(int n) {
    modnum res = modnum_init(1);
    for (int i = 2; i <= n; i++) {
        res = modnum_mul(res, modnum_init(i));
    }
    return res;
}

modnum modnum_inverse_factorial(int n) {
    modnum res = modnum_init(1);
    for (int i = n; i >= 2; i--) {
        res = modnum_mul(res, modnum_inv(modnum_init(i)));
    }
    return res;
}

modnum modnum_coeff[MAXV];

void calculate_coeff() {
    for (int g = 1; g < MAXV; g++) {
        for (int m = g, c = 1; m < MAXV; m += g, c++) {
            modnum_mul(modnum_init(g), modnum_init(nums[c].mu));
        }
    }
}

int main() {
    sieve();

    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    int* a = (int*)malloc(N * sizeof(int));
    int* q = (int*)malloc(Q * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q[i]);
    }

    modnum ans = modnum_init(0);
    int* ct = (int*)calloc(MAXV, sizeof(int));

    for (int i = 0; i < N; i++) {
        ct[a[i]]++;
    }

    for (int g = 1; g < MAXV; g++) {
        for (int m = 2 * g; m < MAXV; m += g) {
            ct[g] += ct[m];
        }
        ans = modnum_add(ans, modnum_mul(modnum_coeff[g], modnum_ncr(ct[g], K)));
    }

    void intro(int v) {
        int* divisors = (int*)malloc(MAXV * sizeof(int));
        int divisor_count = 0;
        unordered_divisors(v, divisors, &divisor_count);
        for (int i = 0; i < divisor_count; i++) {
            int d = divisors[i];
            ans = modnum_add(ans, modnum_mul(modnum_coeff[d], modnum_sub(modnum_ncr(ct[d] + 1, K), modnum_ncr(ct[d], K))));
            ct[d]++;
        }
        free(divisors);
    }

    for (int i = 0; i < Q; i++) {
        intro(q[i]);
        printf("%lld\n", ans.v);
    }

    free(a);
    free(q);
    free(ct);

    return 0;
}
