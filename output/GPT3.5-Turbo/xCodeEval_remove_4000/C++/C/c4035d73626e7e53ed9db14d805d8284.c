#include <stdio.h>
#include <math.h>

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const ld error = 2e-6;
const ld PI = acosl(-1);

inline ll MOD(ll x, ll m) {
    ll y = x % m;
    return (y >= 0) ? y : y + m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000 + 10;

int main() {
    ll n, p;
    scanf("%lld %lld", &n, &p);
    if (p == 0) {
        printf("%d\n", __builtin_popcountll(n));
        return 0;
    }
    if (p > 0) {
        ll i;
        for (i = 1; i <= 35; i++) {
            n -= p;
            if (n < 0) {
                printf("-1\n");
                return 0;
            }
            if (__builtin_popcountll(n) <= i && __builtin_popcountll(n) != 0) {
                if (__builtin_popcountll(n) == 1 && i > log(n) / log(2) + 1) {
                    printf("-1\n");
                    return 0;
                }
                printf("%lld\n", i);
                return 0;
            }
        }
        printf("-1\n");
        return 0;
    }
    if (p < 0) {
        ll i;
        for (i = 1; i <= 35; i++) {
            n += -p;
            if (n < 0) {
                continue;
            }
            if (__builtin_popcountll(n) <= i && __builtin_popcountll(n) != 0) {
                if (__builtin_popcountll(n) == 1 && i > log(n) / log(2) + 1) {
                    printf("-1\n");
                    return 0;
                }
                printf("%lld\n", i);
                return 0;
            }
        }
        printf("-1\n");
        return 0;
    }
    return 0;
}
