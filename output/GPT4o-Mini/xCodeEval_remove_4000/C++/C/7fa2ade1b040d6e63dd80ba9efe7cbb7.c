#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;

#define MAX_SIZE 1000000

typedef struct {
    ll *data;
    int size;
} Vector;

typedef struct {
    Vector *data;
    int size;
} Vector2D;

typedef struct {
    Vector2D *data;
    int size;
} Vector3D;

typedef struct {
    Vector3D *data;
    int size;
} Vector4D;

typedef struct {
    Vector4D *data;
    int size;
} Vector5D;

typedef struct {
    unsigned int val;
} modint;

modint create_modint(ll val, unsigned int mod) {
    modint m;
    m.val = (val >= 0) ? (val % mod) : (mod - (-val) % mod) % mod;
    return m;
}

modint modint_add(modint a, modint b, unsigned int mod) {
    a.val += b.val;
    if (a.val >= mod) a.val -= mod;
    return a;
}

modint modint_sub(modint a, modint b, unsigned int mod) {
    a.val += mod - b.val;
    if (a.val >= mod) a.val -= mod;
    return a;
}

modint modint_mul(modint a, modint b, unsigned int mod) {
    a.val = (unsigned int)(1LL * a.val * b.val % mod);
    return a;
}

modint modint_inv(modint a, unsigned int mod) {
    int x = a.val, y = mod, u = 1, v = 0, t;
    while (y > 0) {
        t = x / y;
        x -= t * y; 
        int temp = u; u -= t * v; v = temp;
        x ^= y; y ^= x; x ^= y;
    }
    return create_modint(u, mod);
}

modint modint_pow(modint a, ll n, unsigned int mod) {
    modint ret = create_modint(1, mod);
    while (n > 0) {
        if (n & 1) ret = modint_mul(ret, a, mod);
        a = modint_mul(a, a, mod);
        n >>= 1;
    }
    return ret;
}

void read_int(int *x) {
    scanf("%d", x);
}

void read_ll(ll *x) {
    scanf("%lld", x);
}

void read_vector(Vector *v, int size) {
    v->data = (ll *)malloc(size * sizeof(ll));
    v->size = size;
    for (int i = 0; i < size; i++) {
        read_ll(&v->data[i]);
    }
}

void print_vector(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%lld ", v->data[i]);
    }
    printf("\n");
}

void solve() {
    ll N, mod;
    read_ll(&N);
    read_ll(&mod);
    
    modint *dp = (modint *)malloc((N + 1) * sizeof(modint));
    for (int i = 0; i <= N; i++) {
        dp[i] = create_modint(0, mod);
    }
    dp[1] = create_modint(1, mod);
    
    for (ll n = 1; n <= N; n++) {
        dp[n] = modint_add(dp[n], dp[n], mod);
        for (ll z = 2; ; z++) {
            ll l = n * z, r = (n + 1) * z;
            if (l > N) break;
            if (r > N + 1) r = N + 1;
            // Apply dp[n] to the range [l, r)
            // This part would require a segment tree or similar structure
        }
    }
    
    printf("%u\n", dp[N].val);
    free(dp);
}

int main() {
    int T = 1;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
