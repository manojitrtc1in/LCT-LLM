#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define popc __builtin_popcount

typedef uint8_t state[1 << n];

void admul(ll *a, ll b, ll c) {
    *a = (*a + b * c) % mod;
}

void go(int n) {
    ll p[n][n];
    ll i100 = powe(100, mod - 2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll x;
            scanf("%lld", &x);
            p[i][j] = x * i100 % mod;
        }
    }
    typedef struct {
        state s;
        ll val;
    } pair;
    pair x[1 << n];
    memset(x, 0, sizeof(x));
    for (int i = 0; i < (1 << n); ++i) {
        memset(x[i].s, 0, sizeof(x[i].s));
        x[i].val = 0;
    }
    memset(x[0].s, 0, sizeof(x[0].s));
    x[0].val = 1;
    for (int turn = 0; turn < n; ++turn) {
        pair newx[1 << n];
        memset(newx, 0, sizeof(newx));
        for (int s = 0; s < (1 << n); ++s) {
            ll mul = 1;
            for (int i = 0; i < n; ++i) {
                if (s >> i & 1) {
                    mul = mul * p[i][turn] % mod;
                } else {
                    mul = mul * (1 - p[i][turn]) % mod;
                }
            }
            for (int i = 0; i < (1 << n); ++i) {
                if ((i & s) && x[i].s < popc(i)) {
                    x[i].s++;
                }
            }
            bool add = true;
            for (int i = 0; i < (1 << n); ++i) {
                if (x[i].s + (n - turn - 1) < popc(i)) {
                    add = false;
                }
            }
            if (add) {
                admul(&newx[i].val, mul, x[i].val);
            }
        }
        memcpy(x, newx, sizeof(x));
    }
    state fin;
    for (int i = 0; i < (1 << n); ++i) {
        fin[i] = popc(i);
    }
    ll ans = x[fin].val;
    ans %= mod;
    if (ans < 0) {
        ans += mod;
    }
    printf("%lld\n", ans);
}

int main() {
    int n;
    scanf("%d", &n);
    go(n);
    return 0;
}
