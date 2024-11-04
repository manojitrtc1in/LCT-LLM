#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef long long ll;

ll fact[1000005];

ll floor_mod(ll a, ll b) {
    a %= b;
    if (a < 0) a += b;
    return a;
}

typedef struct {
    ll value;
} Ring;

Ring Ring_new(ll value) {
    Ring r;
    r.value = value;
    r.value = floor_mod(r.value, MOD);
    return r;
}

Ring Ring_pow(Ring x, ll p) {
    Ring r = Ring_new(1);
    while (p) {
        if (p & 1) {
            r = Ring_mul(r, x);
        }
        x = Ring_mul(x, x);
        p /= 2;
    }
    return r;
}

Ring Ring_inv(Ring a) {
    return Ring_pow(a, MOD - 2);
}

Ring Ring_mul(Ring a, Ring b) {
    a.value *= b.value;
    a.value = floor_mod(a.value, MOD);
    return a;
}

Ring Ring_add(Ring a, Ring b) {
    a.value += b.value;
    a.value -= (a.value >= MOD) * MOD;
    return a;
}

Ring Ring_sub(Ring a, Ring b) {
    a.value -= b.value;
    a.value += (a.value < 0) ? MOD : 0;
    return a;
}

Ring Ring_div(Ring a, Ring b) {
    a = Ring_mul(a, Ring_inv(b));
    return a;
}

Ring Ring_new_int(int value) {
    return Ring_new((ll)value);
}

Ring Ring_new_ll(ll value) {
    return Ring_new(value);
}

Ring Ring_new_double(double value) {
    return Ring_new((ll)value);
}

Ring Ring_new_string(char* value) {
    return Ring_new((ll)atoll(value));
}

void Ring_print(Ring b) {
    printf("%lld", b.value);
}

ll binom(int n, int k) {
    if (k > n) return 0;
    return Ring_div(fact[n], Ring_mul(fact[n - k], fact[k])).value;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    fact[0] = 1;
    for (int i = 1; i <= n + 100; i++) {
        fact[i] = Ring_mul(fact[i - 1], Ring_new_int(i)).value;
    }
    int* v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        for (int j = 2; j * j <= v[i]; j++) {
            while (v[i] % j == 0 && (v[i] / j) % j == 0) {
                v[i] /= j;
                v[i] /= j;
            }
        }
    }
    int cnt[1000005] = {0};
    for (int i = 0; i < n; i++) {
        cnt[v[i]]++;
    }
    int c[1000005];
    int c_len = 0;
    for (int i = 0; i < 1000005; i++) {
        if (cnt[i] > 0) {
            c[c_len++] = cnt[i];
        }
    }
    Ring dp[1000005];
    dp[0] = Ring_new_int(1);
    for (int i = 0; i < n; i++) {
        Ring ndp[1000005] = {0};
        for (int j = 0; j < 1000005; j++) {
            if (dp[j].value) {
                for (int k = 0; k < c[i]; k++) {
                    int dist = c[i] - k;
                    ndp[j + dist] = Ring_add(ndp[j + dist], Ring_mul(Ring_mul(Ring_new_int(binom(c[i] - 1, k)), Ring_new_int(binom(j + dist, dist))), dp[j]));
                }
            }
        }
        for (int j = 0; j < 1000005; j++) {
            dp[j] = ndp[j];
        }
    }
    int conds = n - c_len;
    Ring final = Ring_new_int(0);
    Ring sign = Ring_new_int(1);
    for (int i = 0; i <= conds; i++) {
        final = Ring_add(final, Ring_mul(sign, dp[n - i]));
        sign = Ring_mul(Ring_new_int(-1), sign);
    }
    for (int i = 0; i < c_len; i++) {
        final = Ring_mul(final, Ring_new_ll(fact[c[i]]));
    }
    Ring_print(final);
    return 0;
}
