#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int ll;

const ll mod = 1e9 + 7;

inline ll MOD(ll x, ll m) {
    ll y = x % m;
    return (y >= 0) ? y : y + m;
}

int main() {
    ll n, p;
    scanf("%lld %lld", &n, &p);
    
    if (p == 0) {
        printf("%d\n", __builtin_popcountll(n));
        exit(0);
    }
    
    if (p > 0) {
        for (ll i = 1; i <= 35; i++) {
            n -= p;
            if (n < 0) {
                printf("-1\n");
                exit(0);
            }
            if (__builtin_popcountll(n) <= i && __builtin_popcountll(n) != 0) {
                if (__builtin_popcountll(n) == 1 && i > log(n) / log(2) + 1) {
                    printf("-1\n");
                    exit(0);
                }
                printf("%lld\n", i);
                exit(0);
            }
        }
        printf("-1\n");
        exit(0);
    }

    if (p < 0) {
        for (ll i = 1; i <= 35; i++) {
            n += -p;
            if (n < 0) {
                continue;
            }
            if (__builtin_popcountll(n) <= i && __builtin_popcountll(n) != 0) {
                if (__builtin_popcountll(n) == 1 && i > log(n) / log(2) + 1) {
                    printf("-1\n");
                    exit(0);
                }
                printf("%lld\n", i);
                exit(0);
            }
        }
        printf("-1\n");
        exit(0);
    }

    return 0;
}
