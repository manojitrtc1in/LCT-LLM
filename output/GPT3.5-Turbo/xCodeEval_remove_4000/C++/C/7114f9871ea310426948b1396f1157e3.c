#include <stdio.h>
#include <stdbool.h>

#define MAXV 1000001

typedef long long int ll;

typedef struct {
    int least_prime;
    int div_least_prime;
    char lp_multiplicity;
    char mu;
    int phi;
} num;

typedef struct {
    int f;
    int s;
} pii;

num nums[MAXV];
int primes[MAXV];
int prime_count = 0;

bool is_prime(int v) {
    return nums[v].least_prime == v;
}

int eliminate_least_prime(int v) {
    for (int m = nums[v].lp_multiplicity; m > 0; m--)
        v = nums[v].div_least_prime;
    return v;
}

pii* factor(int v, int* size) {
    static pii res[MAXV];
    int res_size = 0;
    for (; v > 1; v = eliminate_least_prime(v)) {
        res[res_size].f = nums[v].least_prime;
        res[res_size].s = nums[v].lp_multiplicity;
        res_size++;
    }
    *size = res_size;
    return res;
}

void id0(int v, void (*f)(int), int c) {
    if (v == 1) {
        f(c);
        return;
    }
    int w = eliminate_least_prime(v);
    for (int m = 0; m <= nums[v].lp_multiplicity; m++, c *= nums[v].least_prime)
        id0(w, f, c);
}

int* unordered_divisors(int v, int* size) {
    static int res[MAXV];
    int res_size = 0;
    id0(v, ^(int d) { res[res_size] = d; res_size++; }, 1);
    *size = res_size;
    return res;
}

void sieve() {
    for (int v = 2; v < MAXV; v++) {
        num* n = &nums[v];
        if (!n->least_prime) {
            n->least_prime = v;
            n->div_least_prime = 1;
            n->lp_multiplicity = 0;
            n->mu = 1;
            n->phi = 1;
            primes[prime_count] = v;
            prime_count++;
        }
        for (int i = 0; i < prime_count; i++) {
            int p = primes[i];
            if (p > n->least_prime || v * p >= MAXV) break;
            num* np = &nums[v * p];
            np->least_prime = p;
            np->div_least_prime = v;
            np->lp_multiplicity = 1;
            np->mu = -n->mu;
            np->phi = n->phi * (p - 1);
        }
    }
}

typedef struct {
    int v;
} modnum;

modnum modnum_new(int v) {
    modnum res;
    res.v = v;
    return res;
}

modnum modnum_add(modnum a, modnum b, int MOD) {
    modnum res;
    res.v = (a.v + b.v) % MOD;
    if (res.v < 0) res.v += MOD;
    return res;
}

modnum modnum_sub(modnum a, modnum b, int MOD) {
    modnum res;
    res.v = (a.v - b.v) % MOD;
    if (res.v < 0) res.v += MOD;
    return res;
}

modnum modnum_mul(modnum a, modnum b, int MOD) {
    modnum res;
    res.v = ((ll)a.v * b.v) % MOD;
    return res;
}

modnum modnum_pow(modnum a, int e, int MOD) {
    modnum res;
    res.v = 1;
    while (e > 0) {
        if (e & 1) res = modnum_mul(res, a, MOD);
        a = modnum_mul(a, a, MOD);
        e >>= 1;
    }
    return res;
}

modnum modnum_inv(modnum a, int MOD) {
    modnum res;
    res.v = modnum_pow(a, MOD - 2, MOD).v;
    return res;
}

modnum modnum_div(modnum a, modnum b, int MOD) {
    modnum res;
    res.v = ((ll)a.v * modnum_inv(b, MOD).v) % MOD;
    return res;
}

modnum modnum_ncr(int n, int r, int MOD) {
    modnum res;
    res.v = 1;
    for (int i = 0; i < r; i++) {
        res = modnum_mul(res, modnum_new(n - i), MOD);
        res = modnum_div(res, modnum_new(i + 1), MOD);
    }
    return res;
}

modnum modnum_small_inv(int n, int MOD) {
    modnum res;
    res.v = modnum_div(modnum_new(n - 1), modnum_new(n), MOD).v;
    return res;
}

modnum modnum_factorial(int n, int MOD) {
    modnum res;
    res.v = 1;
    for (int i = 2; i <= n; i++) {
        res = modnum_mul(res, modnum_new(i), MOD);
    }
    return res;
}

modnum modnum_inverse_factorial(int n, int MOD) {
    modnum res;
    res.v = 1;
    for (int i = n; i >= 2; i--) {
        res = modnum_mul(res, modnum_new(i), MOD);
    }
    res = modnum_inv(res, MOD);
    return res;
}

modnum modnum_generator(int MOD) {
    modnum res;
    res.v = 2;
    while (true) {
        bool root = true;
        for (int i = 0; i < prime_count; i++) {
            int p = primes[i];
            if (modnum_pow(res, (MOD - 1) / p, MOD).v == 1) {
                root = false;
                break;
            }
        }
        if (root) break;
        res.v++;
    }
    return res;
}

modnum modnum_discrete_log(modnum v, int MOD) {
    static const int M = 1000;
    static int table[MAXV];
    if (table[1] == 0) {
        modnum e;
        e.v = 1;
        for (int i = 0; i < M; i++) {
            table[e.v] = i;
            e = modnum_mul(e, modnum_generator(MOD), MOD);
        }
    }
    modnum f = modnum_pow(modnum_generator(MOD), nums[MOD].phi - M, MOD);
    for (int i = 0; i < M; i++) {
        if (table[v.v] != 0) return modnum_new(table[v.v] + i * M);
        v = modnum_mul(v, f, MOD);
    }
    return modnum_new(-1);
}

modnum modnum_unity_root(int deg, int MOD) {
    modnum res;
    res.v = modnum_pow(modnum_generator(MOD), nums[MOD].phi / deg, MOD).v;
    return res;
}

modnum modnum_unity_root_pow(int deg, int pow, int MOD) {
    static modnum table[2 * MAXV];
    static int table_size = 0;
    while (table_size <= deg) {
        modnum w = modnum_unity_root(table_size, MOD);
        for (int i = table_size / 2, s = table_size; i < s; i++) {
            table[i + s] = table[i];
            table[i + s] = modnum_mul(table[i + s], w, MOD);
        }
        table_size *= 2;
    }
    return table[deg + (pow < 0 ? deg + pow : pow)];
}

modnum coeff[MAXV];

void intro(int v, int K, int* ct, modnum* ans, int MOD) {
    int* divisors;
    int divisors_size;
    divisors = unordered_divisors(v, &divisors_size);
    for (int i = 0; i < divisors_size; i++) {
        int d = divisors[i];
        ans->v = ans->v + coeff[d].v * (modnum_ncr(ct[d] + 1, K, MOD).v - modnum_ncr(ct[d], K, MOD).v);
        ct[d]++;
    }
}

int main() {
    sieve();

    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    int a[N];
    int q[Q];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q[i]);
    }

    int MOD = 1000000007;

    modnum ans;
    ans.v = 0;
    int ct[MAXV];
    for (int i = 0; i < MAXV; i++) {
        ct[i] = 0;
    }

    for (int g = 1; g < MAXV; g++) {
        for (int m = g; m < MAXV; m += g) {
            ct[g] += ct[m];
        }
        ans.v = ans.v + coeff[g].v * modnum_ncr(ct[g], K, MOD).v;
    }

    for (int g = 1; g < MAXV; g++) {
        for (int m = 2 * g; m < MAXV; m += g) {
            ct[g] += ct[m];
        }
    }

    for (int g = 1; g < MAXV; g++) {
        for (int m = g; m < MAXV; m += g) {
            coeff[m].v = coeff[m].v + g * nums[m].mu;
        }
    }

    for (int i = 0; i < Q; i++) {
        intro(q[i], K, ct, &ans, MOD);
        printf("%lld\n", ans.v);
    }

    return 0;
}
